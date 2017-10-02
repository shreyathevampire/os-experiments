#include<stdio.h>

void safety(int n, int r,int allocate[50][50], int max[50][50], int available[50], int need[50][50], int work[50], int flag[])
{
  int c=0,found=0,i,j,k,l=0;
  int result[50] ={0};
  while(l<n)
  {
      found=0;
      for(i=0;i<n;i++)
      {
        if(flag[i]==0)
        {
          for(j=0;j<r;j++)
            if(need[i][j]>work[j])
              break;
            if(j==r)
            {
                    for(k=0;k<r;k++)
              {
                  work[k]=work[k]+allocate[i][k];
              }
              result[c]=i;
              c++;
              flag[i]=1;
              found=1;
             }
           }
       }
     l++;
  }

  if(found==0)
  {
    printf("system is not in safe state\n");
      for(i=0;i<n;i++)
          printf("%d\t ",flag[i]);
      return;
  }
  else
  {
    printf("safe sequence is : \n");
      for(i=0;i<n;i++)
          printf("%d\t ",result[i]+1);
  }
}




void main()
{
  int allocate[50][50],max[50][50],available[50],need[50][50],work[50],flag[50];
  int i,j,p,r;
  int req[50],pno;
  printf("enter no of processes\n");
  scanf("%d",&p);
  printf("enter no of resources\n");
  scanf("%d",&r);
  printf("enter the allocation matrix\n");
  for(i=0;i<p;i++)
  {
    for(j=0;j<r;j++)
    {
      scanf("%d",&allocate[i][j]);
    }
  }
  printf("maximum matrix\n");
  for(i=0;i<p;i++)
  {
    for(j=0;j<r;j++)
    {
      scanf("%d",&max[i][j]);
    }
  }
  printf("enter available matrix\n");
  for(i=0;i<r;i++)
    scanf("%d",&available[i]);

  printf("need matrix\n");
  for(i=0;i<p;i++)
  {
    for(j=0;j<r;j++)
    {
      need[i][j]= max[i][j] - allocate[i][j];
      flag[i] =0;
    }
  }
  for(i=0;i<p;i++)
  {
    for(j=0;j<r;j++)
    {
      printf("%d  ",need[i][j]);
    }
    printf("\n");
  }
  for(i=0;i<r;i++)
  {
      work[i] = available[i];
  }


  safety(p,r,allocate,max,available,need,work,flag);
  printf("\n");

  printf("enter process no and requesting resources\n");
  scanf("%d",&pno);
  for(i=0; i<r ; i++)
    scanf("%d",&req[i]);
  for(i=0; i<r ;i++)
    printf("%d ",req[i]);
  for(i=0;i<p;i++)
    flag[i] =0;
  for(j=0;j<r;j++)
    if(req[i]>need[pno-1][i])
    {
      printf("request cant be granted\n");
      return;
    }
    printf("\n");
  for(j=0;j<r;j++)
    if(req[j]<= available[j])
  {

    available[j] = available[j] - req[j];
    allocate[pno-1][j] = allocate[pno-1][j] + req[j];
    need[pno-1][j] = need[pno-1][j] - req[j];
}

for(i=0;i<p;i++)
{
  for(j=0;j<r;j++)
  {
    printf("%d ",need[i][j]);
  }
printf("\n");

}
for(j=0;j<r;j++)
  work[j] = available[j];

   safety(p,r,allocate,max,available,need,work,flag);

}
