#include<stdio.h>
#include<stdlib.h>
struct fcfs
{
    int at,bt,order,Rtime,rt,wt,tat,term;
};
int allterminate(int n,struct fcfs arr[])
{
    for(int i=0;i<n;i++)
    {
        if(!arr[i].term)
        {
            return 0;
        }
    }
    return 1;
}
int nextprocess(int n,struct fcfs arr[],int ct)
{
    int min=100,x=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i].at<=ct && !arr[i].term)
        {
            if(arr[i].order<min)
            {
                min=arr[i].order;
                x = i;
            }
            
        }
    }
    return x;
}
int main()
{
    int n,i,ct=0,x;
    printf("Enter no. of processes : ");
    scanf("%d",&n);
    struct fcfs arr[n];
    for(i=0;i<n;i++)
    {
        printf("For P%d\n",i);
        printf("Enter arrival time : ");
        scanf("%d",&arr[i].at);
        printf("Enter burst time : ");
        scanf("%d",&arr[i].bt);
        printf("Enter order : ");
        scanf("%d",&arr[i].order);
        arr[i].term=0;
        arr[i].Rtime=arr[i].bt;
        arr[i].wt = 0;
    }
    while(!allterminate(n,arr))
    {
        x=nextprocess(n,arr,ct);
        if(x==-1)
        {
            printf("t=%d idle\n",ct++);
            continue;
        }
        if (arr[x].Rtime==arr[x].bt)
        {
            arr[x].rt=ct-arr[x].at;
        }
        arr[x].Rtime--;
        if(arr[x].Rtime==0)
        {
            arr[x].tat=ct+1-arr[x].at;
            arr[x].term=1;
        }
        for(i=0;i<n;i++)
        {
            if(i==x)
            {
                continue;
            }
            else
            {
                if(arr[i].at<=ct && !arr[i].term)
                {
                    arr[i].wt++;
                }
            }
        }
        printf("t=%d P%d\n",ct,x);
        ct++;
    }
    for(i=0;i<n;i++)
    {
        printf("For P%d\n",i);
        printf("Response time : %d\t",arr[i].rt);
        printf("Waiting time : %d\t",arr[i].rt);
        printf("Turnaround time : %d\t",arr[i].rt);
    }
    
return 0;
}