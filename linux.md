free -h 检查内存
df -lh 磁盘空间
git clone www 拉去对应目标到本地
du -sh * 查看项目占用空间
uname -a 查看系统版本
which java 查看安装路径
wget www.** 下载对应网址链接压缩包
tar -zxvf *tar.gz 解压文件
find -name '*.jar*' 找对应名字到包
nohup code . 后台启动程序
jobs 查看任务
ps -ef 查看进程
ps -ef |grep 'java' 筛选java进程
netstat -ntlp 查看占用端口
curl www. 访问网址
tail -n 10 error.log 查看log到最新10行
sz error.log 下载到本地
kill -9 % 指示操作系统强制终止最近挂起的作业
>-9：代表信号编号，这里是 SIGKILL。SIGKILL 是一个特殊的信号，它会立即终止进程，而不给予进程进行任何清理操作的机会。
%：百分号后面不跟任何数字或作业 ID，表示当前 shell 会话中最近挂起的作业。
top 动态查看进程