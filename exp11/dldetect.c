#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define N 100

int Available[N];
int Allocation[N][N];
int Request[N][N];
int Work[N];
int np,nr;
int Finish[N];

int Finished[N],top = -1,pre_top;


void inputdata();
void display();

void push(int);

void main()
{
int i,j,flag,complete = TRUE;
printf("Deadlock Detection Algorithm\n");

inputdata();
for(i=0;i<nr;++i)
  Work[i] = Available[i];

for(i=0;i<np;++i)
{
  flag = TRUE;
  for(j=0;j<nr;++j)
  {
    if(Allocation[i][j]!=0)
    {

      flag = FALSE;
      break;
    }
  }

  if(flag==TRUE)
  {
    Finish[i] = TRUE;
    push(i);

  }
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
        if(Request[i][j]>Work[j]){
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
  printf("There is no Deadlock\n");
  printf("Order of processes : ");
  for(i=0;i<np;++i)
    printf(" %d -> ",Finished[i]);
  printf("\n");
}
else
  printf("System is in Deadlock State\n");

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

printf("Enter the allocated resources  \n");
for(i=0;i<np;++i)
{
  printf("Process %d : ",i);
  for(j=0;j<nr;++j)
  {
    scanf("%d",&Allocation[i][j]);
    }
}



printf("Enter the requested resources  \n");
for(i=0;i<np;++i)
{
  printf("Process %d : ",i);
  for(j=0;j<nr;++j)
    scanf("%d",&Request[i][j]);
}


for(i=0;i<np;++i)
  Finish[i] = FALSE;

display();

}

void push(int n)
{
  Finished[++top] = n;
}

void display()
{
  int i,j;
  printf("Available resouces : ");
  for(i=0;i<nr;++i)
    printf(" %d",Available[i]);
  printf("\nAllocated   Request\n");
  for(i=0;i<np;++i)
  {
    printf("Process %d : ",i);
    for(j=0;j<nr;++j)
      printf("%2d ",Allocation[i][j]);
    printf("  |  ");
    for(j=0;j<nr;++j)
      printf("%2d ",Request[i][j]);
    printf("\n");
    }

}
