#define SIZE 10
#include<stdio.h>

struct data{
int pno;
int at,bt,wt,tt;
};
struct data p[SIZE];
struct data p1[SIZE];

void findWaitingTime(int n);
void findTurnaroundTime(int n);
void swap(struct data*,struct data*);

void main()
{
int n;
float avg_wt,avg_tt;
printf("FCFS Scheduling\n");
printf("Enter the number of processes : ");
scanf("%d",&n);
for(int i=0;i<n;++i)
{
  printf("Enter arrival time and burst time of process %d : ",i+1);
  p[i].pno = i+1;
  scanf("%d",&p[i].at);
  scanf("%d",&p[i].bt);
}

findWaitingTime(n);
findTurnaroundTime(n);
printf("Pno  Arrival time  Burst time  Waiting time  Turnaround time 
\n");
for(int i=0;i<n;++i)
{
  printf("%3d  %11d  %9d  %12d  %14d\n",p[i].pno,p[i].at,p[i].bt,
p[i].wt,p[i].tt);
}
avg_wt=0;
avg_tt=0;
for(int i=0;i<n;++i)
{
  avg_wt = avg_wt + p[i].wt;
  avg_tt = avg_tt + p[i].tt;
}
avg_wt = avg_wt/n;
avg_tt = avg_tt/n;
printf("Average waiting time : %f\n",avg_wt);
printf("Average turnaround time : %f\n",avg_tt);
printf("Gantt Chart\n|");
int i,t,no=0;
if(0!=p1[0].at)
	printf("0|  |");
for(i=0,t=0;i<n;++t)
{
	if(i>0&&p1[i].at==t)
		if(p1[i-1].at+p1[i-1].bt+p1[i-1].wt<p1[i].at)
			printf("%d|  |",p1[i-1].at+p1[i-1].bt+
p1[i-1].wt);
	if(p1[i].at+p1[i].wt==t){
		printf("%d| p%d |",t,p1[i].pno);
		++i;
		}
			
}
printf("%d|\n",p1[n-1].at+p1[n-1].bt+p1[n-1].wt);
}

void findWaitingTime(int n)
{
int i,j,k,m;
float t;


for(i=0;i<n;++i)
  p1[i] = p[i];
  
for(i=0;i<n;++i)
  for(j=0;j<n-i-1;++j)
    if(p1[j+1].at<p1[j].at)
      swap(&p1[j+1],&p1[j]);

p1[0].wt=0;

for(i=1;i<n;++i)
{
    t=p1[i-1].at+p1[i-1].bt+p1[i-1].wt;
  if(p1[i].at<=t)
    p1[i].wt = t-p1[i].at;
  else
    p1[i].wt = 0;
    
}

for(i=0;i<n;++i)
  for(j=0;j<n;++j)
    if(p1[j].pno==p[i].pno)
      p[i].wt=p1[j].wt;
}


void findTurnaroundTime(int n)
{
  int i;
  for(i=0;i<n;++i)
    p[i].tt = p[i].bt+p[i].wt;
}

void swap(struct data *a,struct data *b)
{
  struct data temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
