#include<stdio.h>

struct process{
int pid,at,aat,bt,wt,tt,rt,start;
}p[20];
int n,t;

void roundrobin();
void inputdata();
void sortat(struct process[],int);
void copyarray(struct process[],struct process[],int);
void startsort(struct process[],int);

void main()
{
printf("Round Robin CPU Scheduling\n");
printf("Insert values\n");
inputdata();
printf("Enter the time quantum t :");
scanf("%d",&t);
roundrobin();
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
  p[i].rt = p[i].bt;
  p[i].aat = p[i].at;
  p[i].start = 0;
}
}

void roundrobin()
{
int finish=0,tq=t,ti=0,entd_prcs,i,j;
float avgwt=0,avgtt=0;
struct process p1[20];
copyarray(p,p1,n);
printf("Gantt Chart\n|0|");
while(finish<n)
{
  if(tq==0)
    tq=t;
  startsort(p1,n);
  sortat(p1,n);
  for(entd_prcs=0;entd_prcs<n;entd_prcs++)
  {
    if(p1[entd_prcs].aat>ti)
      break;
  }
  p1[0].start = 1;
  if(entd_prcs==0)
  {
    ti=p1[0].aat;
    printf(" Idle |%d|",ti);
  }
  else if(tq<p1[0].rt)
  {
    ti = ti + tq;
    p1[0].aat = ti;
    p1[0].rt = p1[0].rt - tq;
    tq = 0;
    printf(" P%d |%d|",p1[0].pid,ti);
  }
  else
  {
    ti = ti + p1[0].rt;
    tq = p1[0].rt = 0;
    finish++;
    p1[0].aat = 999;
    p1[0].wt = ti - p1[0].at -p1[0].bt;
    p1[0].tt = ti - p1[0].at;
    printf(" P%d |%d|",p1[0].pid,ti);
  }
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
      if(p1[j].aat>p1[j+1].aat)
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

void startsort(struct process p1[20],int size)
{
  int i,j;
  struct process temp;
  for(i=0;i<size;++i)
    for(j=0;j<size-i-1;++j)
      if(p1[j].start>p1[j+1].start)
      {
        temp = p1[j];
        p1[j] = p1[j+1];
        p1[j+1] = temp;
      }
}
