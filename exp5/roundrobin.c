#include<stdio.h>

struct times
{
       int pno,at,bt,wt,tt,rnt;
};


void sortart(struct times a[],int n)
{
       int i,j;
       struct times temp;
       for(i=0;i<n;i++)
       {
              for(j=i+1;j<n;j++)
              {
                     if(a[i].at > a[j].at)
                     {
                           temp = a[i];
                           a[i] = a[j];
                           a[j] = temp;
                     }
              }
       }
       return;
}

void main()
{
int i,j,n,time,remain,flag=0,ts;
struct times p[100];
float avgwt=0,avgtt=0;
printf("Round Robin Scheduling\n");
printf("Enter number of processes : ");
scanf("%d",&n);
remain=n;
for(i=0;i<n;i++)
{
      printf("Enter arrival time and Burst time for process %d : ",i+1);
      scanf("%d",&p[i].at);
      scanf("%d",&p[i].bt);
      p[i].pno = i;
      p[i].rnt = p[i].bt;
}
sortart(p,n);
printf("Enter time quatum : ");
scanf("%d",&ts);
printf("Gantt Chart\n");
printf("0");
for(time=0,i=0;remain!=0;)
{
      if(p[i].rnt<=ts && p[i].rnt>0)
      {
             time = time + p[i].rnt;
             printf("| P%d|%d",p[i].pno+1,time);
             p[i].rnt=0;
             flag=1;
      }
      else if(p[i].rnt > 0)
      {
             p[i].rnt = p[i].rnt - ts;
             time = time + ts;
             printf("| p%d |%d",p[i].pno+1,time);
      }
      if(p[i].rnt==0 && flag==1)
      {
             remain--;
             p[i].tt = time-p[i].at;
             p[i].wt = time-p[i].at-p[i].bt;
             avgwt = avgwt + time-p[i].at-p[i].bt;
             avgtt = avgtt + time-p[i].at;
             flag=0;
      }
      if(i==n-1)
             i=0;
      else if(p[i+1].at <= time)
             i++;
      else
             i=0;
}
avgwt = avgwt/n;
avgtt = avgtt/n;
printf("\nAverage Waiting Time : %.2f\n",avgwt);
printf("Average Turnaround Time : %.2f\n",avgtt);
}






