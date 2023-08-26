#include<stdio.h>

struct process{
int pid,at,bt,wt,tt;
}p[20];
int n;

void inputdata();
void fcfs();
void sortat(struct process[],int);
void copyarray(struct process[],struct process[],int);

void main()
{
printf("FCFS CPU Scheduling Algorithm\n");
printf("Insert values\n");
inputdata();
fcfs();
}

void inputdata()
{
int i;
printf("Enter the number of processes : ");
scanf("%d",&n);
for(i=0;i<n;++i)
{
  printf("Enter arrival time and burst time of process P%d : ",i);
  scanf("%d",&p[i].at);
  scanf("%d",&p[i].bt);
  p[i].pid = i;
}
}

void fcfs()
{
float avgwt=0,avgtt=0;
struct process p1[20];
int ti=0,i,j;
copyarray(p,p1,n);
sortat(p1,n);
printf("Gantt Chart\n|0|");
for(i=0;i<n;++i)
{
if(ti<p1[i].at)
{
  printf(" Idle |%d|",p1[i].at);
  ti = p1[i].at;
}
printf(" P%d |%d|",p1[i].pid,ti+p1[i].bt);
ti = ti + p1[i].bt;
p1[i].wt = ti - p1[i].at -p1[i].bt;
p1[i].tt = ti - p1[i].at;
}
printf("\n");
for(i=0;i<n;++i)
  for(j=0;j<n;++j)
    if(p1[j].pid==p[i].pid)
      p[i] = p1[j];
  for(i=0;i<n;++i)
  {
    avgwt = avgwt + p[i].wt;
    avgtt = avgtt + p[i].tt;
  }
  avgwt = (float)(avgwt/n);
  avgtt = (float)(avgtt/n);
  printf("Average waiting time : %f\n",avgwt);
  printf("Average turnaround time : %f\n",avgtt);


}

void sortat(struct process p1[20],int size)
{
  int i,j;
  struct process temp;
  for(i=0;i<size;++i)
    for(j=0;j<size-i-1;++j)
      if(p1[j].at>p1[j+1].at)
      {
        temp = p1[j];
        p1[j] = p1[j+1];
        p1[j+1] = temp;
      }
}

void copyarray(struct process p1[20],struct process p2[20],int size)
{
  for(int i=0;i<size;++i)
  {
    p2[i] = p1[i];
  }
}
