#include<stdio.h>

int pg[20],fr[10][20],curfr[20],n,np;
int pgflt=0,sz=0;
int pt=0;
int used[10][2];
int rused[10];


void inputdata();
int checkframe(int,int);
void fcfs(int,int);
void lru(int,int);
void lfu(int,int);
void display();
void copyframe(int);


void main()
{
int choice,i,j;
printf("\nPage Replacement Algorithms\n\n");
inputdata();
printf("1.FCFS\n");
printf("2.LRU\n");
printf("3.LFU\n");
do{
pgflt=0;
sz=0;
pt=0;
printf("\nEnter the choice : ");
scanf("%d",&choice);
switch(choice)
{
  case 1:
  printf("FIFO Page Replacement Algorithm\n");
  fcfs(pg[0],0);
  sz = pgflt = 1;
  for(i=1;i<np;++i)
  {
    if(checkframe(i-1,pg[i]))
    {
      copyframe(i);
    }
    else
    {
      pgflt++;
      fcfs(pg[i],i);
      if(sz<n)
        sz++;
    }
  }

  display();
  printf("Page fault = %d\n\n",pgflt);

    break;
  case 2:
  printf("LRU Page Replacement Algorithm\n");
  lru(pg[0],0);
  sz = pgflt = 1;
  for(i=1;i<np;++i)
  {
    if(checkframe(i-1,pg[i]))
    {
      copyframe(i);
    }
    else
    {
      pgflt++;
      lru(pg[i],i);
      if(sz<n)
        sz++;
    }
  }

  display();
  printf("Page fault = %d\n\n",pgflt);

    break;
  case 3:
  printf("LFU Page Replacement Algorithm\n");
  lfu(pg[0],0);
  sz = pgflt = 1;
  for(i=1;i<np;++i)
  {
    if(checkframe(i-1,pg[i]))
    {
      copyframe(i);
    }
    else
    {
      pgflt++;
      lfu(pg[i],i);
      if(sz<n)
        sz++;
    }
  }

  display();
  printf("Page fault = %d\n\n",pgflt);

    break;
}

}while(choice<=3);
}

void inputdata()
{
int i,j;
printf("Enter the number of frames : ");
scanf("%d",&n);
printf("Enter the number of pages : ");
scanf("%d",&np);
printf("Enter the pages\n");
for(i=0;i<np;++i)
  scanf("%d",&pg[i]);
for(i=0;i<n;++i)
  for(j=0;j<np;++j)
    fr[i][j] = -1;
}

int checkframe(int fn,int pg)
{
  int i;
  for(i=0;i<sz;++i)
  {
    if(fr[i][fn]==pg)
    {
      return 1;
    }
  }
  return 0;
}


void fcfs(int x,int fn)
{
  int i;
  if(sz<n)
  {
    curfr[pt] = x;
    pt = (pt+1)%n;
    for(i=0;i<sz+1;++i)
    {
      fr[i][fn] = curfr[i];
    }
    if(sz+1==n)
      pt = 0;
  }
  else{
    for(i=0;i<n;++i)
      fr[i][fn] = fr[i][fn-1];
    fr[pt][fn] = x;
    pt = (pt+1)%n;
  }

}


void lru(int x,int fn)
{
  int i,j,k,flag;
  if(sz<n)
  {
    curfr[pt] = x;
    pt = (pt+1)%n;
    for(i=0;i<sz+1;++i)
    {
      fr[i][fn] = curfr[i];
    }
    if(sz+1==n)
      pt = 0;
  }
  else{
    k=0;
    rused[k] = pg[fn-1];
    k++;
    for(i=fn-1;i>=0;--i)
    {
      flag=1;
      for(j=0;j<k;++j)
      {
        if(rused[j]==pg[i])
        {
          flag = 0;
        }
      }
      if(flag==1)
      {
        rused[k++] = pg[i];
      }
      if(k==n)
        break;
    }
    for(i=0;i<n;++i)
      fr[i][fn] = fr[i][fn-1];
    for(i=0;i<n;++i)
    {
      if(rused[n-1]==fr[i][fn])
        fr[i][fn] = x;
    }
  }

}

void lfu(int x,int fn)
{
  int i,j,k,count,temp,flag1,flag2;
  if(sz<n)
  {
    curfr[pt] = x;
    pt = (pt+1)%n;
    for(i=0;i<sz+1;++i)
    {
      fr[i][fn] = curfr[i];
    }
    if(sz+1==n)
      pt = 0;
  }
  else
  {
    k=0;
    for(i=fn-1;i>=0;--i)
    {
      flag1 = 0;
      flag2 = 0;
      for(j=0;j<fn-1-i;++j)
        if(used[j][0]==pg[i])
        {
          flag1 = 1;
          break;
        }
      for(j=0;j<n;++j)
        if(pg[i]==fr[j][fn-1])
        {
          flag2 = 1;
          break;
        }
      if(flag1==0&&flag2!=0)
      {
        used[k][0] = pg[i];
        used[k][1] = 0;
        k++;
      }
      if(k==n)
        break;
    }

  for(i=fn-1;i>=0;--i)
  {
    for(j=0;j<n;++j)
    {
      if(used[j][0]==pg[i])
      {
        used[j][1]++;
      }
    }
  }
  for(i=0;i<n-1;++i)
    for(j=0;j<n-i-1;++j)
    {
      if(used[j][1]<used[j+1][1])
      {
        temp = used[j][0];
        used[j][0] = used[j+1][0];
        used[j+1][0] = temp;
        temp = used[j][1];
        used[j][1] = used[j+1][1];
        used[j+1][1] = temp;
      }
    }
  for(i=0;i<n;++i)
    fr[i][fn] = fr[i][fn-1];
  for(i=0;i<n;++i)
  {
    if(used[n-1][0]==fr[i][fn])
      fr[i][fn] = x;
  }

  }
}

void display()
{
  int i,j;
  printf("\nPages\n\n");
  for(j=0;j<np;++j)
    printf("%d  ",pg[j]);
  printf("\n\n");
  printf("Page Frames\n\n");
  for(i=0;i<n;++i)
  {
    for(j=0;j<np;++j)
    {
      if(fr[i][j]!=-1)
        printf("%d  ",fr[i][j]);
      else
        printf("   ");
    }
    printf("\n");
  }
}

void copyframe(int fn)
{
  for(int i=0;i<sz;++i)
    fr[i][fn] = fr[i][fn-1];
}
