## 程序如何运行

### 服务器端
- Redis: 本地- D:\local_app\Redis-x64-5.0.14.1下，打开终端 - .\redis-server.exe .\redis.windows.conf

- 对应的配置：

```conf
bind 127.0.0.1

protected-mode yes

port 6379

tcp-backlog 511

tcp-keepalive 300

```
- Mysql对应的配置my.ini:

```ini
[mysqld]
bind-address = 127.0.0.1
# 设置3308端口
port=3308
# 设置mysql的安装目录 ---这里输入你安装的文件路径----
basedir=D:\cppsoft\mysql
# 设置mysql数据库的数据的存放目录
datadir=D:\mysql\data
# 允许最大连接数
max_connections=200
# 允许连接失败的次数。
max_connect_errors=10
# 服务端使用的字符集默认为utf8
character-set-server=utf8
# 创建新表时将使用的默认存储引擎
default-storage-engine=INNODB
# 默认使用“mysql_native_password”插件认证
#mysql_native_password
default_authentication_plugin=mysql_native_password
[mysql]
# 设置mysql客户端默认字符集
default-character-set=utf8
[client]
# 设置mysql客户端连接服务端时默认使用的端口
port=3308
default-character-set=utf8
```
`服务端有5个服务器端口`：ChatServer ChatServer2 GateServer StatusServer VarifyServer




