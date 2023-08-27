#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define N 100

int Available[N];
int Max[N][N];
int Allocation[N][N];
int Need[N][N];
int Work[N];
int np,nr;
int Finish[N];
int Finished[N],top = -1,pre_top;

void inputdata();
void push(int);
void requestResource();
void display();

void main()
{
int i,j,flag,complete = TRUE;
printf("Banker's Algorithm\n");
inputdata();
requestResource();
for(i=0;i<nr;++i)
{
  Work[i] = Available[i];
}

pre_top = 0;
while(top!=np-1)
{
  if(top==pre_top)
  {
    complete = FALSE;
    break;
  }
  pre_top = top;
  for(i=0;i<np;++i)
  {
    if(Finish[i]==FALSE)
    {
      flag = FALSE;
      for(j=0;j<nr;++j)
      {
        if(Need[i][j]>Work[j]){
          //printf("<<%d--%d>>\n",Need[i][j],Work[j]);
          flag = TRUE;
          break;
        }
      }
      if(flag==FALSE)
      {
        Finish[i] = TRUE;
        push(i);
        for(j=0;j<nr;++j)
        {
          Work[j] = Work[j] + Allocation[i][j];
        }
      }
    }
  }
}
if(complete == TRUE)
{
  printf("System is in safe state\n");
  printf("Order of processes : ");
  for(i=0;i<np;++i)
    printf(" %d -> ",Finished[i]);
  printf("\n");
}
else
  printf("System is not safe\n");

printf("\n");
}

void inputdata()
{
int i,j;
printf("Enter the number of processes : ");
scanf("%d",&np);
printf("Enter the number of resources : ");
scanf("%d",&nr);
printf("Enter the availables resources : ");
for(i=0;i<nr;++i)
{
  scanf("%d",&Available[i]);
}
printf("Enter the maximum resources  \n");
for(i=0;i<np;++i)
{
  printf("Process %d : ",i);
  for(j=0;j<nr;++j)
    scanf("%d",&Max[i][j]);
}

printf("Enter the allocated resources  \n");
for(i=0;i<np;++i)
{
  printf("Process %d : ",i);
  for(j=0;j<nr;++j)
  {
    scanf("%d",&Allocation[i][j]);
    Need[i][j] = Max[i][j] - Allocation[i][j];
    }
}

for(i=0;i<np;++i)
  Finish[i] = FALSE;

display();

}
 void push(int n)
 {
   Finished[++top] = n;
 }

void requestResource()
{
  char ch;
  int n=-1,i,j,flag;
  int req[100][100];
  printf("Do you want to request resource ?(y/n) : ");
  scanf(" %c",&ch);
  if(ch!='y')
    return;
    do{
      printf("Enter the process number : ");
      scanf("%d",&req[++n][0]);
      if(req[n][0]>=np)
      {
        printf("Not possible\n");
        continue;
      }
      printf("Enter the resources : ");
      for(i=1;i<=nr;++i)
        scanf("%d",&req[n][i]);
      printf("Do you want to continue ?(y/n) : ");
      scanf(" %c",&ch);
    }while(ch=='y');
    if(n==-1)
      return;
    else
      n++;
    for(i=0;i<n;++i)
    {
      flag = 0;
      for(j=0;j<nr&&flag==0;++j)
        if(Available[j]<req[i][j+1]||Need[req[i][0]][j]
<req[i][j+1])
        {
          flag =1;
          break;
        }
      if(flag==1)
        continue;
      for(j=0;j<nr;++j)
      {
        Available[j] = Available[j] - req[i][j+1];
        Allocation[req[i][0]][j] = Allocation[req[i][0]][j]
 + req[i][j+1];
        Need[req[i][0]][j] = Need[req[i][0]][j] - req[i][j+1];
      }
    }
    //display();
}

void display()
{
  int i,j;
  printf("Available resouces : ");
  for(i=0;i<nr;++i)
    printf(" %d",Available[i]);
  printf("\nMax, Allocated, Need \n");
  for(i=0;i<np;++i)
  {
    printf("Process %d : ",i);
    for(j=0;j<nr;++j)
      printf("%2d ",Max[i][j]);
    printf("  |  ");
    for(j=0;j<nr;++j)
      printf("%2d ",Allocation[i][j]);
    printf("  |  ");
    for(j=0;j<nr;++j)
      printf("%2d ",Need[i][j]);
    printf("\n");
    }

}
