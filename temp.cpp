
#include <iostream>
#include <pcap.h>  /* GIMME a libpcap plz! */
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

using namespace std;

#if 1
int main(int argc, char **argv)
{
//   char *dev; /* name of the device to use */ 
//   char *net; /* dot notation of the network address */
//   char *mask;/* dot notation of the network mask    */
//   int ret;   /* return code */
    string dev;ssss
    string net;
    string mask;
    int ret;
  char errbuf[PCAP_ERRBUF_SIZE];
  bpf_u_int32 netp; /* ip          */
  bpf_u_int32 maskp;/* subnet mask */
  struct in_addr addr;

  /* ask pcap to find a valid device for use to sniff on */
  dev = pcap_lookupdev(errbuf);

  /* error checking */
  if(dev.empty())
  {
   //printf("%s\n",errbuf);
   cout << errbuf << endl;
   exit(1);
  }

  /* print out device name */
  //printf("DEV: %s\n",dev);
    cout << "dev : " << dev << endl;
  /* ask pcap for the network address and mask of the device */
  ret = pcap_lookupnet(dev.c_str(),&netp,&maskp,errbuf);

  if(ret == -1)
  {
   printf("%s\n",errbuf);
   exit(1);
  }

  /* get the network address in a human readable form */
  addr.s_addr = netp;
  net = inet_ntoa(addr);

  if(net.empty())/* thanks Scott :-P */
  {
    perror("inet_ntoa");
    exit(1);
  }

  //printf("NET: %s\n",net);
  cout << "net: " << net << endl;

  /* do the same as above for the device's mask */
  addr.s_addr = maskp;
  mask = inet_ntoa(addr);
  
  if(mask.empty())
  {
    perror("inet_ntoa");
    exit(1);
  }
  
 // printf("MASK: %s\n",mask);
    cout << "mask: " << mask << endl;
  return 0;
}

#endif 
