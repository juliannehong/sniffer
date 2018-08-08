#include <iostream>
#include <string>
#include <pcap.h>
#include <sys/socket.h>

using namespace std;

void print_interface(){
    string dev_name;
    string net_addr;
    string mask;
    int ret;
    char errbuf[PCAP_ERRBUF_SIZE];

    bpf_u_int32 netp;
    bpf_u_int32 maskp;
    struct in_addr addr;
}

int main(){
    

}