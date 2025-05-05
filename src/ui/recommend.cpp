#include "recommend.h"

recommend::recommend(QWidget *parent) :
    QDialog(parent)
{
    //setWindowFlags(Qt::FramelessWindowHint);
    setParent(parent);
    init();
}

recommend::~recommend()
{
}

void recommend::init() {
    //loadVideos();
    m_filepath="../web/videos/";
    m_path_csv = "../web/csv/";


    m_historyVideos=readCSV(m_path_csv+"watch_record.csv");
    m_allVideos=readCSV(m_path_csv+"recommend_list.csv");

    m_rcmdVideos={};
}

void recommend::m_getRCMDrefreshed(){
    m_rcmdVideos.clear();
    QSet<int> numbers;
    while (numbers.size() < 6) {
        numbers.insert(QRandomGenerator::global()->bounded(m_allVideos.size()));
    }
    for(int n : numbers){
        m_rcmdVideos+=m_allVideos[n];
    }
    m_get_predictRanks(m_historyVideos,m_rcmdVideos);
}

void recommend::m_getSearchResult(){
    m_rcmdVideos=readCSV(m_path_csv+"search_result.csv");
}

QList<VideoData> recommend::readCSV(const QString& filePath) {
    QList<VideoData> dataList;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file:" << filePath;
        return dataList;
    }

    QTextStream in(&file);
    QString header = in.readLine(); // 跳过表头
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() >= 15) {
            VideoData data;
            data.id = fields[0].toInt();
            data.filename = fields[1];
            data.tags = fields[2].split(" ");
            data.emotion = fields[3].toInt();
            data.keywords = fields[4].split(" ",Qt::SkipEmptyParts);
            data.typeContent = fields[5];
            data.typeForm = fields[6];
            data.duration = fields[7].toInt();
            data.isDownloaded = fields[8].toInt();
            data.uri = fields[9];
            data.source = fields[10].split(" ");
            data.isWatched = fields[11].toInt();
            int temp=fields[12].toInt();
            if(temp>0)data.isLiked = true;
            else if(temp<0)data.isUnliked = true;
            data.rank = fields[13].toInt();
            data.dateTime = QDateTime::fromString(fields[14], "yyyy/M/d h:m");

            dataList.append(data);

            QString video_path=m_filepath+data.filename+".mp4";
            if (QFile::exists(video_path)) {
                data.isDownloaded=1;
            }

        }
    }
    file.close();

    return dataList;
}

void recommend::m_get_predictRanks(const QList<VideoData>& historyVideos, QList<VideoData>& allVideos) {

    // 统计 HV 数据
    RCMD_Stats stats = m_computeStatistics(historyVideos);
    m_debugStats(stats);


    // 为每个 AV 预测 rank
    for (auto& video : allVideos) {
        auto res= m_computePredictedRank(video, stats);
        video.rank =  res.first;
        video.source = res.second;
    }
}


// 统计 HV 的 Type 和 Keywords 数据
RCMD_Stats recommend::m_computeStatistics(const QList<VideoData>& historyVideos) {
    RCMD_Stats stats;

    for (const auto& video : historyVideos) {
        // 统计 typeContent
        if (!stats.typeContentStats.contains(video.typeContent)) {
            stats.typeContentStats[video.typeContent] = {0.0, 0};
        }
        auto& tcStats = stats.typeContentStats[video.typeContent];
        tcStats.first = (tcStats.first * tcStats.second + video.rank) / (tcStats.second + 1);
        tcStats.second++;

        // 统计 typeForm
        if (!stats.typeFormStats.contains(video.typeForm)) {
            stats.typeFormStats[video.typeForm] = {0.0, 0};
        }
        auto& tfStats = stats.typeFormStats[video.typeForm];
        tfStats.first = (tfStats.first * tfStats.second + video.rank) / (tfStats.second + 1);
        tfStats.second++;

        // 统计 keywords
        for (const auto& keyword : video.keywords) {
            if (!stats.keywordStats.contains(keyword)) {
                stats.keywordStats[keyword] = {0.0, 0};
            }
            auto& kwStats = stats.keywordStats[keyword];
            kwStats.first = (kwStats.first * kwStats.second + video.rank) / (kwStats.second + 1);
            kwStats.second++;
        }
    }

    return stats;
}


// 计算单个 AV 的预测 rank
QPair<int,QStringList> recommend::m_computePredictedRank(const VideoData& video, const RCMD_Stats& stats) {
    QStringList keyw={};

    // 计算 Type 评分
    double typeScore_1=0;
    double typeScore_2=0;

    int count=0;
    for (auto it = stats.typeContentStats.begin(); it != stats.typeContentStats.end(); ++it)
        {count += it.value().first*it.value().second;}
    // typeContent 评分
    if (stats.typeContentStats.contains(video.typeContent)) {
        typeScore_1 = (stats.typeContentStats[video.typeContent].first*stats.typeContentStats[video.typeContent].second)/count;
    }
    if(typeScore_1>0.15){typeScore_1=0.15;}


    count=0;
    for (auto it = stats.typeFormStats.begin(); it != stats.typeFormStats.end(); ++it)
        {count += it.value().first*it.value().second;}
    // typeForm 评分
    if (stats.typeFormStats.contains(video.typeForm)) {
        typeScore_2 = (stats.typeFormStats[video.typeForm].first*stats.typeFormStats[video.typeForm].second)/count;
    }
    if(typeScore_2>0.15){typeScore_2=0.15;}


    // 计算 Keywords 评分
    double keywordScore = 0.0;
    double totalWeight = 0.0;
    if (!video.keywords.isEmpty()) {
        for (const auto& keyword : video.keywords) {
            if (stats.keywordStats.contains(keyword)) {
                auto kwStats = stats.keywordStats[keyword];
                double weight = kwStats.second;
                keywordScore += kwStats.first * weight;
                totalWeight += 4 * weight; //以出现关键词平均达到4分为满分

                if(stats.keywordStats[keyword].first>=1&&stats.keywordStats[keyword].second>=1) keyw+=keyword;
            }
        }
    }

    // 平均 Keywords 评分
    if (totalWeight > 0) {
        keywordScore /= totalWeight;
        if(keywordScore>0.7){
            keywordScore=0.7;
        }
    } else {
        keywordScore = 0.0; // 默认评分
    }


    // 综合评分
    qDebug()<<"scores:"<<typeScore_1*5<< typeScore_2*5<< keywordScore*5 <<'\n'<<"keywords:"<<keyw;
    double finalScore = (typeScore_1 + typeScore_2 + keywordScore)*5;

    return QPair<int,QStringList>(int(finalScore),keyw);
}

// 调试输出 Stats 内容
void recommend::m_debugStats(const RCMD_Stats& stats) const {
    qDebug() << "TypeContent Stats:";
    for (auto it = stats.typeContentStats.constBegin(); it != stats.typeContentStats.constEnd(); ++it) {
        qDebug() << QString("%1: avgRank=%2, count=%3")
                    .arg(it.key())
                    .arg(it.value().first, 0, 'f', 1) // 保留 1 位小数
                    .arg(it.value().second);
    }

    qDebug() << "TypeForm Stats:";
    for (auto it = stats.typeFormStats.constBegin(); it != stats.typeFormStats.constEnd(); ++it) {
        qDebug() << QString("%1: avgRank=%2, count=%3")
                    .arg(it.key())
                    .arg(it.value().first, 0, 'f', 1)
                    .arg(it.value().second);
    }

    qDebug() << "Keyword Stats:";
    for (auto it = stats.keywordStats.constBegin(); it != stats.keywordStats.constEnd(); ++it) {
        qDebug() << QString("%1: avgRank=%2, count=%3")
                    .arg(it.key())
                    .arg(it.value().first, 0, 'f', 1)
                    .arg(it.value().second);
    }
}
