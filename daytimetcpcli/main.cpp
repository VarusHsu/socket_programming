// I page 6
#include "../unpv13e/lib/unp.h"
#include "iostream"
int main(int argc, char** argv){
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;
    if (argc != 2) {
        std::cout<<"usage: ./a.out <IPaddress>"<<std::endl;
        exit(1);
    }
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0))<0){
        std::cerr<<"socket err"<<std::endl;
    }
    bzero(&servaddr, sizeof (servaddr));
    servaddr.sin_family =  AF_INET;
    servaddr.sin_port =htons(8875);
    if (inet_pton(AF_INET, "0.0.0.0", &servaddr.sin_addr)<=0){
        std::cout<<"inet_pton error for "<<argv[1]<<std::endl;
        exit(1);
    }

    if (connect(sockfd,(SA*)&servaddr, sizeof (servaddr))<=0){
        std::cerr<<"connect_err "<<strerror(errno)<<std::endl;
        exit(1);
    }

    while((n = read(sockfd, recvline,MAXLINE))> 0){
        recvline[n] = 0;
        if (fputs(recvline, stdout) ==EOF)
            std::cerr<<"fputs err"<<std::endl;
    }

    if (n<0)
        std::cerr<<"read err"<<std::endl;
    exit(0);
}