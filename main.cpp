#include <iostream>
#include <pcap.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string>

using namespace std;

int main(){
  string dev_name;
  string net_addr;
  string mask;
  int ret;
  char errbuf[PCAP_ERRBUF_SIZE];

  bpf_u_int32 netp; /* ip          */
  bpf_u_int32 maskp;/* subnet mask */
  struct in_addr addr;

  dev_name = pcap_lookupdev(errbuf);

  if (dev_name.empty()){
    cout << errbuf << endl;
    exit(1);
  }

  cout << "DEV: " << dev_name << endl;

  ret = pcap_lookupnet(dev_name.c_str(), &netp, &maskp, errbuf);

  if (ret == -1){
    cout << errbuf << endl;
    exit(1);
  }

  addr.s_addr = netp;
  net_addr = inet_ntoa(addr);
  if (net_addr.empty()){
    perror("inet_ntoa");
    exit(1);
  }
  cout << "NET: " << net_addr << endl;

  addr.s_addr = maskp;
  mask = inet_ntoa(addr);
  if (mask.empty()){
    perror("inet_ntoa");
    exit(1);
  }
  cout << "MASK: " << mask << endl;
  
  return 0;
}