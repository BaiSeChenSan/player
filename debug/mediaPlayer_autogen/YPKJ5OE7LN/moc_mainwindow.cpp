/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/ui/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[97];
    char stringdata0[1604];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 26), // "m_downloadfinished_history"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 18), // "on_openBtn_clicked"
QT_MOC_LITERAL(4, 58, 16), // "updateVoiceLabel"
QT_MOC_LITERAL(5, 75, 5), // "value"
QT_MOC_LITERAL(6, 81, 27), // "on_voiceSlider_valueChanged"
QT_MOC_LITERAL(7, 109, 19), // "on_playIcon_clicked"
QT_MOC_LITERAL(8, 129, 19), // "on_lastIcon_clicked"
QT_MOC_LITERAL(9, 149, 19), // "on_nextIcon_clicked"
QT_MOC_LITERAL(10, 169, 19), // "on_stopIcon_clicked"
QT_MOC_LITERAL(11, 189, 20), // "on_voiceIcon_clicked"
QT_MOC_LITERAL(12, 210, 20), // "on_allButton_clicked"
QT_MOC_LITERAL(13, 231, 30), // "on_comboBox_currentTextChanged"
QT_MOC_LITERAL(14, 262, 4), // "arg1"
QT_MOC_LITERAL(15, 267, 21), // "on_listButton_clicked"
QT_MOC_LITERAL(16, 289, 12), // "upDateSlider"
QT_MOC_LITERAL(17, 302, 8), // "position"
QT_MOC_LITERAL(18, 311, 11), // "GetDuration"
QT_MOC_LITERAL(19, 323, 8), // "duration"
QT_MOC_LITERAL(20, 332, 9), // "MoveVideo"
QT_MOC_LITERAL(21, 342, 9), // "videoData"
QT_MOC_LITERAL(22, 352, 20), // "onPlayerStateChanged"
QT_MOC_LITERAL(23, 373, 18), // "on_setting_clicked"
QT_MOC_LITERAL(24, 392, 12), // "stopPlayback"
QT_MOC_LITERAL(25, 405, 21), // "on_slider_sliderMoved"
QT_MOC_LITERAL(26, 427, 22), // "on_slider_valueChanged"
QT_MOC_LITERAL(27, 450, 17), // "initRecommendList"
QT_MOC_LITERAL(28, 468, 17), // "QList<VideoData>&"
QT_MOC_LITERAL(29, 486, 4), // "temp"
QT_MOC_LITERAL(30, 491, 4), // "type"
QT_MOC_LITERAL(31, 496, 14), // "on_min_clicked"
QT_MOC_LITERAL(32, 511, 14), // "on_max_clicked"
QT_MOC_LITERAL(33, 526, 16), // "on_close_clicked"
QT_MOC_LITERAL(34, 543, 22), // "on_dayAndNight_clicked"
QT_MOC_LITERAL(35, 566, 15), // "mousePressEvent"
QT_MOC_LITERAL(36, 582, 12), // "QMouseEvent*"
QT_MOC_LITERAL(37, 595, 5), // "event"
QT_MOC_LITERAL(38, 601, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(39, 616, 17), // "mouseReleaseEvent"
QT_MOC_LITERAL(40, 634, 17), // "updateCursorShape"
QT_MOC_LITERAL(41, 652, 3), // "pos"
QT_MOC_LITERAL(42, 656, 16), // "adjustWindowSize"
QT_MOC_LITERAL(43, 673, 14), // "globalMousePos"
QT_MOC_LITERAL(44, 688, 13), // "keyPressEvent"
QT_MOC_LITERAL(45, 702, 10), // "QKeyEvent*"
QT_MOC_LITERAL(46, 713, 12), // "MActionsSlot"
QT_MOC_LITERAL(47, 726, 25), // "on_selectedButton_clicked"
QT_MOC_LITERAL(48, 752, 27), // "on_openFolderButton_clicked"
QT_MOC_LITERAL(49, 780, 17), // "onMenuAboutToShow"
QT_MOC_LITERAL(50, 798, 17), // "onMenuAboutToHide"
QT_MOC_LITERAL(51, 816, 16), // "closeMenuClicked"
QT_MOC_LITERAL(52, 833, 18), // "clearRecordclicked"
QT_MOC_LITERAL(53, 852, 19), // "setClearModeClicked"
QT_MOC_LITERAL(54, 872, 19), // "systemDialogclicked"
QT_MOC_LITERAL(55, 892, 18), // "aboutDialogclicked"
QT_MOC_LITERAL(56, 911, 24), // "on_historyButton_clicked"
QT_MOC_LITERAL(57, 936, 28), // "on_personalityButton_clicked"
QT_MOC_LITERAL(58, 965, 19), // "on_aiButton_clicked"
QT_MOC_LITERAL(59, 985, 14), // "listChoosePlay"
QT_MOC_LITERAL(60, 1000, 8), // "QString&"
QT_MOC_LITERAL(61, 1009, 8), // "fileName"
QT_MOC_LITERAL(62, 1018, 21), // "personalityChoosePlay"
QT_MOC_LITERAL(63, 1040, 6), // "aiPlay"
QT_MOC_LITERAL(64, 1047, 13), // "receiveSignal"
QT_MOC_LITERAL(65, 1061, 3), // "str"
QT_MOC_LITERAL(66, 1065, 5), // "index"
QT_MOC_LITERAL(67, 1071, 12), // "speedChanged"
QT_MOC_LITERAL(68, 1084, 5), // "speed"
QT_MOC_LITERAL(69, 1090, 11), // "sizeChanged"
QT_MOC_LITERAL(70, 1102, 10), // "widthRatio"
QT_MOC_LITERAL(71, 1113, 11), // "heightRatio"
QT_MOC_LITERAL(72, 1125, 10), // "rotateView"
QT_MOC_LITERAL(73, 1136, 6), // "choice"
QT_MOC_LITERAL(74, 1143, 21), // "updateVideoWidgetSize"
QT_MOC_LITERAL(75, 1165, 13), // "on_ai_clicked"
QT_MOC_LITERAL(76, 1179, 27), // "on_deleteListButton_clicked"
QT_MOC_LITERAL(77, 1207, 19), // "called_orNot_addSrt"
QT_MOC_LITERAL(78, 1227, 13), // "called_setSrt"
QT_MOC_LITERAL(79, 1241, 13), // "appendMessage"
QT_MOC_LITERAL(80, 1255, 7), // "message"
QT_MOC_LITERAL(81, 1263, 14), // "AiLogo_clicked"
QT_MOC_LITERAL(82, 1278, 16), // "onFilterSelected"
QT_MOC_LITERAL(83, 1295, 8), // "QAction*"
QT_MOC_LITERAL(84, 1304, 6), // "action"
QT_MOC_LITERAL(85, 1311, 19), // "onSearchTextChanged"
QT_MOC_LITERAL(86, 1331, 25), // "on_analyse_button_clicked"
QT_MOC_LITERAL(87, 1357, 22), // "on_type_button_clicked"
QT_MOC_LITERAL(88, 1380, 22), // "on_playListBtn_clicked"
QT_MOC_LITERAL(89, 1403, 16), // "onSchemeSelected"
QT_MOC_LITERAL(90, 1420, 20), // "on_deleteAll_clicked"
QT_MOC_LITERAL(91, 1441, 24), // "on_refreshButton_clicked"
QT_MOC_LITERAL(92, 1466, 25), // "onPersonSearchTextChanged"
QT_MOC_LITERAL(93, 1492, 25), // "on_ui_keywordLike_clicked"
QT_MOC_LITERAL(94, 1518, 29), // "on_ui_keywordSearch_2_clicked"
QT_MOC_LITERAL(95, 1548, 27), // "on_ui_keywordLike_2_clicked"
QT_MOC_LITERAL(96, 1576, 27) // "on_ui_keywordSearch_clicked"

    },
    "MainWindow\0m_downloadfinished_history\0"
    "\0on_openBtn_clicked\0updateVoiceLabel\0"
    "value\0on_voiceSlider_valueChanged\0"
    "on_playIcon_clicked\0on_lastIcon_clicked\0"
    "on_nextIcon_clicked\0on_stopIcon_clicked\0"
    "on_voiceIcon_clicked\0on_allButton_clicked\0"
    "on_comboBox_currentTextChanged\0arg1\0"
    "on_listButton_clicked\0upDateSlider\0"
    "position\0GetDuration\0duration\0MoveVideo\0"
    "videoData\0onPlayerStateChanged\0"
    "on_setting_clicked\0stopPlayback\0"
    "on_slider_sliderMoved\0on_slider_valueChanged\0"
    "initRecommendList\0QList<VideoData>&\0"
    "temp\0type\0on_min_clicked\0on_max_clicked\0"
    "on_close_clicked\0on_dayAndNight_clicked\0"
    "mousePressEvent\0QMouseEvent*\0event\0"
    "mouseMoveEvent\0mouseReleaseEvent\0"
    "updateCursorShape\0pos\0adjustWindowSize\0"
    "globalMousePos\0keyPressEvent\0QKeyEvent*\0"
    "MActionsSlot\0on_selectedButton_clicked\0"
    "on_openFolderButton_clicked\0"
    "onMenuAboutToShow\0onMenuAboutToHide\0"
    "closeMenuClicked\0clearRecordclicked\0"
    "setClearModeClicked\0systemDialogclicked\0"
    "aboutDialogclicked\0on_historyButton_clicked\0"
    "on_personalityButton_clicked\0"
    "on_aiButton_clicked\0listChoosePlay\0"
    "QString&\0fileName\0personalityChoosePlay\0"
    "aiPlay\0receiveSignal\0str\0index\0"
    "speedChanged\0speed\0sizeChanged\0"
    "widthRatio\0heightRatio\0rotateView\0"
    "choice\0updateVideoWidgetSize\0on_ai_clicked\0"
    "on_deleteListButton_clicked\0"
    "called_orNot_addSrt\0called_setSrt\0"
    "appendMessage\0message\0AiLogo_clicked\0"
    "onFilterSelected\0QAction*\0action\0"
    "onSearchTextChanged\0on_analyse_button_clicked\0"
    "on_type_button_clicked\0on_playListBtn_clicked\0"
    "onSchemeSelected\0on_deleteAll_clicked\0"
    "on_refreshButton_clicked\0"
    "onPersonSearchTextChanged\0"
    "on_ui_keywordLike_clicked\0"
    "on_ui_keywordSearch_2_clicked\0"
    "on_ui_keywordLike_2_clicked\0"
    "on_ui_keywordSearch_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      72,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  374,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  377,    2, 0x08 /* Private */,
       4,    1,  378,    2, 0x08 /* Private */,
       6,    1,  381,    2, 0x08 /* Private */,
       7,    0,  384,    2, 0x08 /* Private */,
       8,    0,  385,    2, 0x08 /* Private */,
       9,    0,  386,    2, 0x08 /* Private */,
      10,    0,  387,    2, 0x08 /* Private */,
      11,    0,  388,    2, 0x08 /* Private */,
      12,    0,  389,    2, 0x08 /* Private */,
      13,    1,  390,    2, 0x08 /* Private */,
      15,    0,  393,    2, 0x08 /* Private */,
      16,    1,  394,    2, 0x08 /* Private */,
      18,    1,  397,    2, 0x08 /* Private */,
      20,    1,  400,    2, 0x08 /* Private */,
      22,    0,  403,    2, 0x08 /* Private */,
      23,    0,  404,    2, 0x08 /* Private */,
      24,    0,  405,    2, 0x08 /* Private */,
      25,    1,  406,    2, 0x08 /* Private */,
      26,    1,  409,    2, 0x08 /* Private */,
      27,    2,  412,    2, 0x08 /* Private */,
      27,    1,  417,    2, 0x28 /* Private | MethodCloned */,
      31,    0,  420,    2, 0x08 /* Private */,
      32,    0,  421,    2, 0x08 /* Private */,
      33,    0,  422,    2, 0x08 /* Private */,
      34,    0,  423,    2, 0x08 /* Private */,
      35,    1,  424,    2, 0x08 /* Private */,
      38,    1,  427,    2, 0x08 /* Private */,
      39,    1,  430,    2, 0x08 /* Private */,
      40,    1,  433,    2, 0x08 /* Private */,
      42,    1,  436,    2, 0x08 /* Private */,
      44,    1,  439,    2, 0x08 /* Private */,
      46,    0,  442,    2, 0x08 /* Private */,
      47,    0,  443,    2, 0x08 /* Private */,
      48,    0,  444,    2, 0x08 /* Private */,
      49,    0,  445,    2, 0x08 /* Private */,
      50,    0,  446,    2, 0x08 /* Private */,
      51,    0,  447,    2, 0x08 /* Private */,
      52,    0,  448,    2, 0x08 /* Private */,
      53,    0,  449,    2, 0x08 /* Private */,
      54,    0,  450,    2, 0x08 /* Private */,
      55,    0,  451,    2, 0x08 /* Private */,
      56,    0,  452,    2, 0x08 /* Private */,
      57,    0,  453,    2, 0x08 /* Private */,
      58,    0,  454,    2, 0x08 /* Private */,
      59,    1,  455,    2, 0x08 /* Private */,
      62,    1,  458,    2, 0x08 /* Private */,
      63,    1,  461,    2, 0x08 /* Private */,
      64,    2,  464,    2, 0x08 /* Private */,
      67,    1,  469,    2, 0x08 /* Private */,
      69,    2,  472,    2, 0x08 /* Private */,
      72,    1,  477,    2, 0x08 /* Private */,
      74,    0,  480,    2, 0x08 /* Private */,
      75,    0,  481,    2, 0x08 /* Private */,
      76,    0,  482,    2, 0x08 /* Private */,
      77,    1,  483,    2, 0x08 /* Private */,
      78,    0,  486,    2, 0x08 /* Private */,
      79,    2,  487,    2, 0x08 /* Private */,
      81,    0,  492,    2, 0x08 /* Private */,
      82,    1,  493,    2, 0x08 /* Private */,
      85,    0,  496,    2, 0x08 /* Private */,
      86,    0,  497,    2, 0x08 /* Private */,
      87,    0,  498,    2, 0x08 /* Private */,
      88,    0,  499,    2, 0x08 /* Private */,
      89,    1,  500,    2, 0x08 /* Private */,
      90,    0,  503,    2, 0x08 /* Private */,
      91,    0,  504,    2, 0x08 /* Private */,
      92,    0,  505,    2, 0x08 /* Private */,
      93,    0,  506,    2, 0x08 /* Private */,
      94,    0,  507,    2, 0x08 /* Private */,
      95,    0,  508,    2, 0x08 /* Private */,
      96,    0,  509,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   17,
    QMetaType::Void, QMetaType::LongLong,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 28, QMetaType::Int,   29,   30,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 36,   37,
    QMetaType::Void, 0x80000000 | 36,   37,
    QMetaType::Void, 0x80000000 | 36,   37,
    QMetaType::Void, QMetaType::QPoint,   41,
    QMetaType::Void, QMetaType::QPoint,   43,
    QMetaType::Void, 0x80000000 | 45,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 60,   61,
    QMetaType::Void, 0x80000000 | 60,   61,
    QMetaType::Void, 0x80000000 | 60,   61,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   65,   66,
    QMetaType::Void, QMetaType::Double,   68,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   70,   71,
    QMetaType::Void, QMetaType::Int,   73,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   80,   30,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 83,   84,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 83,   84,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->m_downloadfinished_history((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_openBtn_clicked(); break;
        case 2: _t->updateVoiceLabel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_voiceSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_playIcon_clicked(); break;
        case 5: _t->on_lastIcon_clicked(); break;
        case 6: _t->on_nextIcon_clicked(); break;
        case 7: _t->on_stopIcon_clicked(); break;
        case 8: _t->on_voiceIcon_clicked(); break;
        case 9: _t->on_allButton_clicked(); break;
        case 10: _t->on_comboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_listButton_clicked(); break;
        case 12: _t->upDateSlider((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 13: _t->GetDuration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 14: _t->MoveVideo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->onPlayerStateChanged(); break;
        case 16: _t->on_setting_clicked(); break;
        case 17: _t->stopPlayback(); break;
        case 18: _t->on_slider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->initRecommendList((*reinterpret_cast< QList<VideoData>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 21: _t->initRecommendList((*reinterpret_cast< QList<VideoData>(*)>(_a[1]))); break;
        case 22: _t->on_min_clicked(); break;
        case 23: _t->on_max_clicked(); break;
        case 24: _t->on_close_clicked(); break;
        case 25: _t->on_dayAndNight_clicked(); break;
        case 26: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 27: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 28: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 29: _t->updateCursorShape((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 30: _t->adjustWindowSize((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 31: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 32: _t->MActionsSlot(); break;
        case 33: _t->on_selectedButton_clicked(); break;
        case 34: _t->on_openFolderButton_clicked(); break;
        case 35: _t->onMenuAboutToShow(); break;
        case 36: _t->onMenuAboutToHide(); break;
        case 37: _t->closeMenuClicked(); break;
        case 38: _t->clearRecordclicked(); break;
        case 39: _t->setClearModeClicked(); break;
        case 40: _t->systemDialogclicked(); break;
        case 41: _t->aboutDialogclicked(); break;
        case 42: _t->on_historyButton_clicked(); break;
        case 43: _t->on_personalityButton_clicked(); break;
        case 44: _t->on_aiButton_clicked(); break;
        case 45: _t->listChoosePlay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 46: _t->personalityChoosePlay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 47: _t->aiPlay((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 48: _t->receiveSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 49: _t->speedChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 50: _t->sizeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 51: _t->rotateView((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 52: _t->updateVideoWidgetSize(); break;
        case 53: _t->on_ai_clicked(); break;
        case 54: _t->on_deleteListButton_clicked(); break;
        case 55: { bool _r = _t->called_orNot_addSrt((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 56: _t->called_setSrt(); break;
        case 57: _t->appendMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 58: _t->AiLogo_clicked(); break;
        case 59: _t->onFilterSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 60: _t->onSearchTextChanged(); break;
        case 61: _t->on_analyse_button_clicked(); break;
        case 62: _t->on_type_button_clicked(); break;
        case 63: _t->on_playListBtn_clicked(); break;
        case 64: _t->onSchemeSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 65: _t->on_deleteAll_clicked(); break;
        case 66: _t->on_refreshButton_clicked(); break;
        case 67: _t->onPersonSearchTextChanged(); break;
        case 68: _t->on_ui_keywordLike_clicked(); break;
        case 69: _t->on_ui_keywordSearch_2_clicked(); break;
        case 70: _t->on_ui_keywordLike_2_clicked(); break;
        case 71: _t->on_ui_keywordSearch_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 59:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        case 64:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAction* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::m_downloadfinished_history)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 72)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 72;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 72)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 72;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::m_downloadfinished_history(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
