//
// Created by varus on 2023/4/30.
//
#include <netinet/in.h>
#include "iostream"
#include "cstdlib"
#define BUFFER_LEN (64)

int main(int argc, char** argv){
    int listenfd, connfd;
    struct sockaddr_in servaddr = {};
    char  buff[BUFFER_LEN];

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        std::cerr<<"create socket err:"<<strerror(errno)<<std::endl;
        exit(1);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8875);

    if (bind(listenfd,(sockaddr*)&servaddr, sizeof (servaddr)) == -1){
        std::cerr<<"bind socket err:"<<strerror(errno)<<std::endl;
        exit(1);
    }

    if (listen(listenfd, 10) == -1) {
        std::cerr<<"listen err:"<<strerror(errno)<<std::endl;
        exit(1);
    }

    std::cout<<"waiting for client connect..."<<std::endl;

    while(true) {
        if ((connfd = accept(listenfd, (struct sockaddr*)nullptr, nullptr)) == -1){
            std::cerr<<"accept error"<<strerror(errno)<<std::endl;
            continue;
        }
        std::cout<<"connection established"<<std::endl;
        time_t now;
        time(&now);
        memset(buff, '\0', BUFFER_LEN);
        snprintf(buff,BUFFER_LEN, "now time:%d\n", int(now));
        send(connfd,buff, BUFFER_LEN, 0);
    }
    return  0;
}