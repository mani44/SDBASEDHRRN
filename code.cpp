#include <iostream>

using namespace std;

struct process {
char name;
int at, bt, pt, ct,wt, tt; 
int completed;
float ntt;
} p[10];
int n;
// Sorting Processes by arrival Time 
void sortByarrival()
{
    struct process temp; 
    int i, j;
    // Selection Sort applied 
    for (i = 0; i< n - 1; i++) {
        for (j = i + 1; j < n; j++) {
        // Check for lesser arrival time 
            if (p[i].at > p[j].at) {
                // Swap earlier process to front 
                temp =p[i];
                p[i] = p[j];
                p[j]=temp;
            }
        }
    }
}
int main()
{
    int i, j, t, sum_bt = 0; char c;
    float avgwt = 0,
    avgtt = 0; n = 6;// predefined arrival times 
    int arriv[] = { 0, 0, 0, 0, 0, 0 };
    // predefined burst times
    int burst[] = { 3, 9, 6, 14, 10, 7 };
    // predefined sd priority
    int prior[] = { 1, 4, 2, 6, 5, 3 };
    // Initializing the structure variables 
    for (i = 0, c = 'a'; i< n; i++, c++) {
    p[i].name = c; 
    p[i].at=arriv[i];
    p[i].bt =burst[i];
    p[i].pt =prior[i];
    // Variable for Completion status
    // Pending = 0
    // Completed = 1
    p[i].completed =0;
    // Variable for sum of all Burst Times 
    sum_bt +=p[i].bt;
    }
    // Sorting the structure by arrival times 
    sortByarrival();
    cout << "Name " << " arrival Time " << " Burst Time " << " Waiting Time " << " Turnaround Time " << " Normalized TT" ; 
    for (t = p[0].at; t < sum_bt;) 
    {  // Set higher limit to response ratio 
        float hrr = 9999;
        // Response Ratio Variable 
        float temp;
        // Variable to store next processs selected 
        int loc;
        for (i = 0; i < n; i++) {
        // Checking if process has arrived and is Incomplete 
            if (p[i].at <= t && p[i].completed != 1) {
                // Calculating Response Ratio
                temp = (p[i].bt + (t - p[i].at)) / p[i].bt; 
                temp = 0.5*temp + 0.5*(p[i].pt);
                // Checking for Lowest Response Ratio 
                if (hrr > temp)
                {
                    // Storing Response Ratio 
                    hrr = temp;
                    // Storing Location 
                    loc = i;
                }
            }
        }
        // Updating time value 
        t+= p[loc].bt;
        // Calculation of waiting time 
        p[loc].wt = t - p[loc].at - p[loc].bt;
        // Calculation of Turn around Time 
        p[loc].tt = t - p[loc].at;
        // Sum Turn around Time for average 
        avgtt += p[loc].tt;
        // Calculation of Normalized Turn around Time 
        p[loc].ntt = ((float)p[loc].tt / p[loc].bt);
        // Updating Completion Status 
        p[loc].completed = 1;
        // Sum Waiting Time for average
        avgwt += p[loc].wt;
        cout<< "\n" << p[loc].name <<"\t" << p[loc].at; cout << "\t\t" << p[loc].bt <<"\t\t"<< p[loc].wt; 
        cout<<"\t\t"<<p[loc].tt<<"\t\t"<<p[loc].ntt;
    }
cout << "\naverage waiting time: " << avgwt / n << endl; 
cout <<"average Turn around time:"<< avgtt / n;
}
