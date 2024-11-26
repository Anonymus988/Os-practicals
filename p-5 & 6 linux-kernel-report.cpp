#include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>

int main()
{
    cout << "\n The kernel version is : \n";
    cout << flush;
    system("cat /proc/sys/kernel/osrelease");

    cout << "\n The CPU space : \n";
    cout << flush;
    system("cat /proc/cpuinfo | awk 'NR==3,NR==4{print}'");

    cout << "\n Amount of cpu time since system was last booted is: ";
    cout << flush;
    system("cat /proc/uptime");

    cout << "\n The configured memory is : \n";
    cout << flush;
    system("cat /proc/meminfo | awk 'NR == 1{print $2}'");

    cout << "\n Amount of free memory: \n";
    cout << flush;
    system("cat /proc/meminfo | awk 'NR == 2{print $2}'");

    cout << "\n Amount of used memory is : \n";
    cout << flush;
    system("cat /proc/meminfo | awk '{if (NR==1) a=$2; if(NR==2) b=$2 } END {print a-b}'");

    cout << endl;
    return 0;
}