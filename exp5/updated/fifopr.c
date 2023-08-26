#include <stdio.h>

int np,nf,pages[50],frames[20][50];
int pgflt,fptr=1;

void inputdata();
int checkPage(int,int);
void copyframe(int);
void insertPage(int,int);
void display();

void main()
{
int i;
printf("FIFO Page Replacement Algorithm\n");
inputdata();
frames[0][0] = pages[0];
pgflt = 1;
for(i=1;i<np;++i)
{
  if(checkPage(pages[i],i-1))
  {
    copyframe(i);
  }
  else
  {
    pgflt++;
    insertPage(pages[i],i);
  }
}
display();
printf("Page faults : %d\n",pgflt);
}

void inputdata()
{
int i,j;
printf("Enter the number of pages : ");
scanf("%d",&np);
printf("Enter the number of frames : ");
scanf("%d",&nf);
printf("Enter the pages\n");
for(i=0;i<np;++i)
{
  scanf("%d",&pages[i]);
  for(j=0;j<nf;++j)
  {
    frames[j][i] = -1;
  }
}
}

int checkPage(int pg,int pno)
{
  int i;
  for(i=0;i<nf;++i)
  {
    if(pg==frames[i][pno])
      return 1;
  }
  return 0;
}

void copyframe(int pno)
{
  int i;
  for(i=0;i<nf;++i)
  {
    frames[i][pno] = frames[i][pno-1];
  }
}

void insertPage(int pg,int pno)
{
  copyframe(pno);
  frames[fptr][pno] = pg;
  fptr = (fptr+1)%nf;
}

void display()
{
  int i,j;
  printf("Pages-Frames\n");
  for(i=0;i<np;++i)
  {
    printf("%2d  ",pages[i]);
  }
  printf("\n\n");
  for(i=0;i<nf;++i)
  {
    for(j=0;j<np;++j)
    {
      if(frames[i][j]!=-1)
        printf("%2d  ",frames[i][j]);
      else
        printf("    ");
    }
    printf("\n");
  }

}
