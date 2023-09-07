#include<stdio.h>

int n,rq[100];

void inputdata();
void fcfs();
void scan();
void cscan();
int absdiff(int,int);
void copyarray(int[100],int[100],int);
void sortarray(int[100],int);
void displaydiagram(int[100],int);

void main()
{
int choice;
printf("\nDisk Scheduling\n\n");
inputdata();
printf("1. FCFS\n");
printf("2. SCAN\n");
printf("3. C-SCAN\n");
do{
printf("Enter the choice : ");
scanf("%d",&choice);
switch(choice)
{
  case 1:
    fcfs();
    break;
  case 2:
    scan();
    break;
  case 3:
    cscan();
    break;
}
printf("\n");
}while(choice<=3);
}


void inputdata()
{
printf("Enter the number of requests : ");
scanf("%d",&n);
printf("Enter the requests in order\n");
for(int i=0;i<n;++i)
  scanf("%d",&rq[i]);
printf("Blocks requested for IO...\n\n");
}

void fcfs()
{
  int totalswing = 0,i,sch[100];
  for(i=0;i<n-1;++i)
  {
    totalswing = totalswing + absdiff(rq[i],rq[i+1]);
    sch[i] = rq[i];
  }
  sch[i] = rq[i];
printf("\nOrder of execution\n");
for(i=0;i<n;++i)
  printf("%d->",sch[i]);
printf("\n");
displaydiagram(sch,n);
printf("Total swing required : %d\n",totalswing);
}

void scan()
{
  int totalswing = 0,i,j,sch[100],sch1[100],pos;
  copyarray(sch,rq,n);
  sortarray(sch,n);
  for(i=0;i<n;++i)
    if(sch[i]==rq[0])
      break;
    pos = i;
    j=0;
    for(i=pos;i>=0;--i)
    {
      sch1[j] = sch[i];
      j++;
    }
    sch1[j++] = 0;
    for(i=pos+1;i<n;++i)
    {
      sch1[j] = sch[i];
      j++;
    }
    sch1[j] = 200;
    copyarray(sch,sch1,n+2);
    for(i=0;i<n;++i)

      totalswing = totalswing + absdiff(sch[i],sch[i+1]);

    printf("\nOrder of execution\n");
    for(i=0;i<n+2;++i)
      printf("%d->",sch[i]);
    printf("\n");

  displaydiagram(sch,n+2);
  printf("Total swing required : %d\n",totalswing);

}

void cscan()
{
  int totalswing = 0,i,j,sch[100],sch1[100],pos;
  copyarray(sch,rq,n);
  sortarray(sch,n);
  for(i=0;i<n;++i)
    if(sch[i]==rq[0])
      break;
    pos = i;
    j=0;
    for(i=pos;i<n;++i)
    {
      sch1[j] = sch[i];
      j++;
    }
    sch1[j++] = 200;
    sch1[j++] = 0;
    for(i=0;i<pos;++i)
      sch1[j++] = sch[i];
    copyarray(sch,sch1,n+2);
    for(i=0;i<n+1;++i)
      if(sch[i]!=200||sch[i+1]!=0)
        totalswing = totalswing + absdiff(sch[i],sch[i+1]);
    printf("\nOrder of execution\n");
    for(i=0;i<n+2;++i)
      printf("%d->",sch[i]);
    printf("\n");

  displaydiagram(sch,n+2);
  printf("Total swing required : %d\n",totalswing);

}

int absdiff(int x,int y)
{
  if(x-y>=0)
    return x-y;
  else
    return y-x;
}

void copyarray(int x[100],int y[100],int n)
{
  int i;
  for(i=0;i<n;++i)
  {
    x[i] = y[i];
  }
}

void sortarray(int a[100],int n)
{
  int i,j,temp;
  for(i=0;i<n-1;++i)
  {
    for(j=0;j<n-i-1;++j)
    {
      if(a[j+1]<a[j])
      {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }

    }
  }
}

void displaydiagram(int sch[100],int ns)
{
  int i,j,head[100];
  j=0;
  for(i=0;i<ns;++i)
  {
    if(sch[i]!=0&&sch[i]!=200)
      head[j++] = sch[i];
  }
  head[n] = 0;
  head[n+1] = 200;
  sortarray(head,n+1);
  for(i=0;i<n+2;++i)
  {
    printf(" %3d ",head[i]);
  }
  printf("\n");
  for(i=0;i<ns;++i)
  {
    for(j=0;j<n+2;++j)
    {
      if(head[j]==sch[i])
      {
        printf("  *  ");
        break;
      }
      else
        printf("     ");
    }
    printf("\n");
  }

}
