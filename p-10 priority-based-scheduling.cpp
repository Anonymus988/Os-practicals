#include <iostream>
using namespace std;
struct Process
{
    int pid, arrival_time, burst_time, priority, waiting_time, turnaround_time;
};
void calculateTimes(Process proc[], int n)
{
    int completed = 0, time = 0;
    while (completed < n)
    {
        int idx = -1;
        int min_priority = 9999;

        // Find the process with the highest priority that has arrived
        for (int i = 0; i < n; i++)
        {
            if (proc[i].arrival_time <= time && proc[i].burst_time > 0)
            {
                if (proc[i].priority < min_priority)
                {
                    min_priority = proc[i].priority;
                    idx = i;
                }
            }
        }
        // Execute the selected process
        if (idx != -1)
        {
            time += proc[idx].burst_time;
            proc[idx].waiting_time = time - proc[idx].arrival_time - proc[idx].burst_time;
            proc[idx].turnaround_time = time - proc[idx].arrival_time;
            proc[idx].burst_time = 0;
            completed++;
        }
        else
        {
            time++;
        }
    }
}
void printResults(Process proc[], int n)
{
    cout << "PID\tWT\tTAT\n";
    for (int i = 0; i < n; i++)
    {
        cout << proc[i].pid << "\t" << proc[i].waiting_time << "\t" << proc[i].turnaround_time << endl;
    }
}
int main()
{
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    Process proc[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time, burst time, and priority for process" << i + 1 << ": ";
        cin >> proc[i].arrival_time >> proc[i].burst_time >> proc[i].priority;
        proc[i].pid = i + 1;
    }
    calculateTimes(proc, n);
    printResults(proc, n);
    return 0;
}