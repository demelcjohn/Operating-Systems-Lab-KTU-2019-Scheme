#include<stdio.h>

struct process{
int pid,at,aat,bt,wt,tt,rt;
}p[20];
int n,t;

void srtf();
void inputdata();
void sortat(struct process[],int);
void copyarray(struct process[],struct process[],int);
void startsort(struct process[],int);
void sortcond(struct process[],int,int);

void main()
{
printf("Preemptive SJF (SRTF) CPU Scheduling\n");
printf("Insert values\n");
inputdata();
srtf();
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
}
}

void srtf()
{
int finish=0,ti=0,entd_prcs,i,j;
float avgwt=0,avgtt=0;
struct process p1[20];
copyarray(p,p1,n);
printf("Gantt Chart\n|0|");
while(finish<n)
{
  sortat(p1,n);
  for(entd_prcs=0;entd_prcs<n;entd_prcs++)
  {
    if(p1[entd_prcs].aat>ti)
      break;
  }
  if(entd_prcs==0)
  {
    ti=p1[0].aat;
    printf(" Idle |%d|",ti);
    continue;
  }
  sortcond(p1,0,entd_prcs-1);
  if(p1[0].rt+ti>p1[entd_prcs].aat)
  {
    p1[0].rt = p1[0].rt -(p1[entd_prcs].aat - ti);
    ti = p1[entd_prcs].aat;
    p1[0].aat = ti;
    printf(" P%d |%d|",p1[0].pid,ti);
  }
  else if(p1[0].rt+ti<=p1[entd_prcs].aat)
  {
    ti = ti + p1[0].rt;
    p1[0].rt = 0;
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

void sortcond(struct process p2[20],int l,int h)
{
int i,j;
struct process temp;
for(i=l;i<=h-1;++i)
  for(j=l;j<=h-i+l-1;++j)
    if(p2[j].rt>p2[j+1].rt)
    {
      temp = p2[j];
      p2[j] = p2[j+1];
      p2[j+1] = temp;
    }
}
