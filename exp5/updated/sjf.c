#include<stdio.h>

struct process{
int pid,at,bt,wt,tt;
}p[20];
int n;

void inputdata();
void sjf();
void sortat(struct process[],int);
void copyarray(struct process[],struct process[],int);
void sortcond(struct process[],int,int);

void main()
{
printf("SJF CPU Scheduling Algorithm\n");
printf("Insert values\n");
inputdata();
sjf();
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

void sjf()
{
float avgwt=0,avgtt=0;
struct process p1[20],p2[20];
int ti,i,j;
copyarray(p,p2,n);
sortat(p2,n);
ti = 0;
for(i=0;i<n;++i)
{
  for(j=i;j<n;++j)
  {
    if(ti<p2[j].at)
      break;
  }
  if(i==j)
  {
    ti = p2[i].at;
    i--;
    continue;
  }
  sortcond(p2,i,j-1);
  printf("sort - i=%d,j=%d",i,j);
  for(int k=0;k<=i;++k)
    printf("p%d->",p2[k].pid);
  printf("\n");
  p1[i] = p2[i];
  ti = ti + p1[i].bt;
}
for(int k=0;k<n;++k)
  printf("p%d->",p1[k].pid);
printf("\n");
ti = 0;
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

void sortcond(struct process p2[20],int l,int h)
{
int i,j;
struct process temp;
for(i=l;i<=h-1;++i)
  for(j=l;j<=h-i+l-1;++j)
    if(p2[j].bt>p2[j+1].bt)
    {
      temp = p2[j];
      p2[j] = p2[j+1];
      p2[j+1] = temp;
    }
}
