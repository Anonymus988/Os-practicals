#include <iostream>
#include <stdio.h>
using namespace std;
class fcfs
{
public:
    int
        burst_tm,
        arv_tm, wait_tm;
    char pid;
};
int main()
{
    int n, sum = 0, carry;
    cout << "Enter the no. of processes:\n";
    cin >> n;
    fcfs temp;
    fcfs *f = new fcfs[n];
    for (int i = 0; i < n; i++)
    {

        cout << "Enter the process id:\n";
        cin >> f[i].pid;
        cout << "Enter the burst timing :\n ";
        cin >> f[i].burst_tm;
        cout
            << "Enter the arrival timing:\n";
        cin >> f[i].arv_tm;
        // system("cls");
    }
    int k = 0, flag = 1;
    while (k != 0)
    {
        if (f[k].arv_tm == 0)
        {
            flag = 0;
            break;
        }
        k++;
    }
    if (!flag)
    {
        cout << "enter all values of arival time as no arrival time is 0\n ";
        return 1;
    }
    for (k = 0; k < n; k++)
    {
        temp = f[k];
        for (int
                 i = k + 1;
             i < n; i++)
        {
            if (temp.arv_tm > f[i].arv_tm)
            {
                temp = f[i];
                f[i] = f[k];
                f[k] = temp;
            }
        }
    }
    cout << "Entered info is as follows:\n";
    int avg_wait_tm = 0, avg_around_tm = 0;
    for (k = 0; k < n; k++)
    {
        f[k].wait_tm = sum - f[k].arv_tm;
        if (f[k].wait_tm < 0)
            f[k].wait_tm = 0;
        sum += f[k].burst_tm;
        avg_wait_tm += f[k].wait_tm;
        avg_around_tm += f[k].wait_tm + f[k].burst_tm;
    }
    avg_around_tm /= n;
    avg_wait_tm /= n;
    for (k = 0; k < n; k++)
    {
        cout << "pid: " << f[k].pid << endl
             << "Burst time:" << f[k].burst_tm << endl
             << " arrival time : " << f[k].arv_tm << endl
             << " Waiting time : " << f[k].wait_tm << endl;
    }
    cout << "average turn aroun time :\n " << avg_around_tm << endl
         << " average waiting time :\n " << avg_wait_tm << endl;
    return 0;
}