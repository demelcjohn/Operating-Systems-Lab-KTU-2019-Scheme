#include<stdio.h>

struct memoryalloc{
  int max;
  int alloc;
}mem[100];
int b;
int beg=0;

void inputdata();
void firstfit();
void bestfit();
void worstfit();
void display();

void main()
{int choice ,i;
printf("\nMemory Management\n\n");

inputdata();

printf("1. First Fit Memory Allocation\n");
printf("2. Best Fit Memory Allocation\n");
printf("3. Worst Fit Memory Allocation\n");
printf("4. Exit\n");

do{
  printf("Enter your choice : ");
  scanf("%d",&choice);
  for(i=0;i<b;++i)
    mem[i].alloc = 0;
switch(choice)
{
  case 1:
    firstfit();
    break;
  case 2:
    bestfit();
    break;
  case 3:
    worstfit();
    break;
  default:
    printf("Thank you\n");
}

}while(choice<4);
}

void inputdata()
{
  int i;
  printf("Enter the number of blocks : ");
  scanf("%d",&b);
  printf("Enter size of memory block\n");
  for(i=0;i<b;++i)
  {
    scanf("%d",&mem[i].max);
  }
  display();
  beg = 1;
}

void firstfit()
{
char con = 'n';
int m,i,flag;
do{
  printf("Enter the size of block to be allocated : ");
  scanf("%d",&m);
  flag = 0;
  for(i=0;i<b;++i)
  {
    if(mem[i].max-mem[i].alloc>=m)
    {
      flag = 1;
      mem[i].alloc+=m;
      break;
    }
  }
  if(flag==1)
    printf("Allocated\n");
  else
    printf("Not possible\n");
  display();
  printf("Do you want to continue ?(y/n) : ");
  scanf(" %c",&con);
}while(con=='y');
}

void bestfit()
{
  char con = 'n';
  int m,i,small,smallval,flag;
  do{
    flag = 0;
    printf("Enter the size of block to be allocated : ");
    scanf("%d",&m);
    for(i=0;i<b;++i)
      if(mem[i].max-mem[i].alloc>=m)
      {
        flag = 1;
        smallval = mem[i].max - mem[i].alloc;
        small = i;
        break;
      }
    if(flag==0)
      {
        printf("Not possible\n");
        break;
      }
    for(i=0;i<b;++i)
      if(mem[i].max - mem[i].alloc < smallval && mem[i].max 
- mem[i].alloc >= m)
      {
        smallval = mem[i].max - mem[i].alloc;
        small = i;
      }
    mem[small].alloc +=m;
    display();
    printf("Do you want to continue ?(y/n) : ");
    scanf(" %c",&con);
  }while(con=='y');

}

void worstfit()
{
  char con = 'n';
  int m,i,big,bigval,flag;
  do{
    flag = 0;
    printf("Enter the size of block to be allocated : ");
    scanf("%d",&m);
    for(i=0;i<b;++i)
      if(mem[i].max-mem[i].alloc>=m)
      {
        flag = 1;
        bigval = mem[i].max - mem[i].alloc;
        big = i;
        break;
      }
    if(flag==0)
      {
        printf("Not possible\n");
        break;
      }
    for(i=0;i<b;++i)
      if(mem[i].max - mem[i].alloc > bigval)
      {
        bigval = mem[i].max - mem[i].alloc;
        big = i;
      }
    mem[big].alloc +=m;
    display();
    printf("Do you want to continue ?(y/n) : ");
    scanf(" %c",&con);
  }while(con=='y');

}


void display()
{
  int i;
  printf("\nMemory\n");
  printf("Maximum size -> ");
  for(i=0;i<b;++i)
    printf("%2d -> ",mem[i].max);
  if(beg==1)
  {
    printf("\nAllocated    -> ");
    for(i=0;i<b;++i)
      printf("%2d -> ",mem[i].alloc);
  }
  printf("\n\n");
}
