```shell
# build
cd ../unpv13e
./configure
cd ../daytimetcpcli
cmake .
make
```
```shell
# run
./a.out <YourServerAddress>
# You can use my server by execute:
# ./a.out 81.70.196.215
# Or deploy your server.
```

描述：对应《UNIX网络编程 卷一》第6页中的socket客户端小程序