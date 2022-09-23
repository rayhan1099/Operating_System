#include <bits/stdc++.h>
using namespace std;

void WaitingTime(int processes[], int n, int bt[], int wt[])
{
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void TurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}
void avgTime(int processes[], int n, int bt[])
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    WaitingTime(processes, n, bt, wt);

    TurnAroundTime(processes, n, bt, wt, tat);

    cout << "Processes  "
         << " Burst time  "
         << " Waiting time  "
         << " Turn around time" << endl;

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i + 1 << "\t\t" << bt[i] << "\t  " << wt[i] << "\t\t  " << tat[i] << endl;
    }

    cout << "Average waiting time = " << (float)total_wt / (float)n << endl;
    cout << "Average turn around time = " << (float)total_tat / (float)n << endl;
}

int main()
{
    int n, i;
    cout << "Enter Number Of Process:";
    cin >> n;
    int processes[n];
    cout << "Enter Arivaltime:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> processes[i];
    }
    int burst_time[n];
    cout << "Enter Burst Time:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> burst_time[i];
    }
    avgTime(processes, n, burst_time);
    return 0;
}