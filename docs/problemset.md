Q:QT版本统一  
A:uos默认版本5.11.3
<br/>
Q:rsync配置
A:git bash运行  
echo "alias zstd='/d/tool/zstd/zstd.exe'" >> ~/.bashrc  
echo "alias rsync='/d/tool/rsync/usr/bin/rsync.exe'" >> ~/.bashrc  
source ~/.bashrc  
将两个libxx文件夹下的usr/bin/中的dll复制到C:\Program Files\Git\usr\bin  
注意修改实际路径以及盘符使用小写  
运行zstd -h\rsync -h判断是否正常使用  
运行rsync -av /mediaPlayer 用户名@虚拟机ip:/home/用户名/Downloads/  
将其发送到虚拟机  
可用rsync -av --dry-run /mediaPlayer 用户名@虚拟机ip:/home/用户名/Downloads/
进行测试连接  
<br/>
Q:ip地址确认  
A:windows下,ipconfig,去掉带有vmware的,剩下的唯一一个IPv4  
uos下,ifconfig,inet后的就是.
注意,虚拟机需要设置为桥接模式  
<br/>
Q:main分支更新后,如何更新自己的分支
A:
rebase方法:  
不推荐使用,但是可以让当前分支的commit记录与main一致.  
假设该分支命名为a,使用`git checkout a`切换到该分支,
使用`git fetch origin`获取最新的main,
然后,使用`git rebase origin/main`将分支a更新到main的相同状态,
如果有冲突,解决后使用`git rebase --continue`继续更新,
最后,使用`git push origin a --force`推送到github
<br/>
merge方法:该方法会保留自己的分支中独有的提交记录,rebase方法不会  

git checkout main  
git pull origin main  
git checkout a  
git merge main  
git add <冲突解决后的文件>  
git commit  
git push origin a  
  

Q:ffmpeg版本  
A:由于原有ffmpeg版本难以找到,使用最新版本7.1  

- 原有版本卸载 

    sudo apt remove ffmpeg  
    sudo apt autoremove
- 7.1版本安装

    mkdir ffmpeg  
    cd ffmpeg  
    wget https://ffmpeg.org/releases/ffmpeg-7.1.tar.gz  
    tar -zxvf ffmpeg-7.1.tar.gz  
    sudo apt update  
    sudo apt install build-essential yasm pkg-config libx264-dev libvpx-dev libmp3lame-dev libopus-dev libfdk-aac-dev libx265-dev  
    cd ffmpeg-7.1  
    注意修改以下命令中的user为自己的用户名,不确定可以使用pwd查看  
    ./configure --prefix=/home/user/ffmpeg-build --enable-shared --disable-static --enable-gpl --enable-nonfree --enable-libx264 --enable-libvpx --enable-libfdk-aac --enable-libx265  
    make -j$(nproc)  
    sudo make install  
    export PATH=/home/user/ffmpeg-build/bin:$PATH  
    export LD_LIBRARY_PATH=/home/user/ffmpeg-build/lib:$LD_LIBRARY_PATH  
    echo 'export PATH=/home/user/ffmpeg-build/bin:$PATH' >> ~/.bashrc  
    echo 'export LD_LIBRARY_PATH=/home/user/ffmpeg-build/lib:$LD_LIBRARY_PATH' >> ~/.bashrc  
    source ~/.bashrc  
    使用ffmpeg -version查看版本信息,显示为7.1即可  
    windows下直接解压添加环境变量.  
    注意,如果版本不是7.1,可能是环境变量的其他地方有ffmpeg,使用where ffmpeg查看路径,调整环境变量顺序即可
    
<br/>
    

