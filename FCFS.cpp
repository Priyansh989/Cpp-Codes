#include<iostream>
using namespace::std;


void findwaitingtime(int arr[] , int bt[] , int n , int wt[] )
{
    wt[0] = 0;
    for(int i =1 ; i<n ; i++)
    {
        wt[i]=bt[i-1] + wt[i-1];
    }
}

void findturnaroundtime(int arr[] , int bt[] , int n , int wt[] , int tat[])
{
    for(int i =1 ; i<n ; i++)
    {
        tat[i] = bt[i] + wt[i];
    } 
    
}

void findavgtime(int arr[] , int bt[] , int n)
{
    int wt[n];
    int tat[n];
    int total_wt = 0 ;
    int total_tat = 0;
    findwaitingtime(arr,bt,n,wt);
    findturnaroundtime(arr,bt,n,wt,tat);
     for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << "   " << i+1 << "\t\t" << bt[i] <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter the number of processes you want: ";
    cin>>n;
    int arr[n];
    int bt[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the value of process "<<i+1<<": ";
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the value of the burst time "<<i+1<<": ";
        cin>>bt[i];
    }
     for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    findavgtime(arr,bt,n);
    return 0;
}