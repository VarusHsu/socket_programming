# include "../unpv13e/lib/unp.h"
# include "iostream"
int main(){
    std::cout<<CPU_VENDOR_OS<<std::endl;
    int a = 1;
    char *p = (char*)&a;
    *p==0?
    std::cout<<"(network byte ordered)big-endian"<<std::endl:
    std::cout<<"little-endian"<<std::endl;
    return 0;
}