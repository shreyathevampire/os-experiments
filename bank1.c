#include<stdio.h>

void main()
{
      int avail[20],allocate[20][20],max[20][20],need[20][20];
    //  int allocate[20][20];
      //int max[20][20];
      //int need[20][20];
      int work[20]={0};
      int result[20]={0},flag[20];
      int n,r,i,j,k,l,c=0,found=0;
    //  process p[100];
      printf("enter np of processes\n");
      scanf("%d",&n);
      printf("enter no of resources\n");
      scanf("%d",&r);
      printf("allocation matrix\n");
      for(i=0;i<n;i++)
        for(j=0;j<r;j++)
        {
            scanf("%d",&allocate[i][j]);
        }
      printf("max matrix\n");
      for(i=0;i<n;i++)
        for(j=0;j<r;j++)
        {
            scanf("%d",&max[i][j]);
        }
      printf("available array\n");
      for(i=0;i<r;i++)
      {
        scanf("%d",&avail[i]);
        work[i]=avail[i];
      }

      for(i=0;i<n;i++)
        for(j=0;j<r;j++)
        {
          need[i][j]=max[i][j]-allocate[i][j];
          flag[i]=0;
        }
      for(i=0;i<n;i++)
        {
        for(j=0;j<r;j++)
        {
          printf("%d\t",need[i][j]);
        //  printf("\n");
        }
        printf("\n");
      }

      while(c<n)
      {
          found=0;
          for(i=0;i<n;i++)
          {
        //    printf("i =  %d \t",i);
            if(flag[i]==0)
            {
              for(j=0;j<r;j++)
                if(need[i][j]>work[j])
                  break;

              if(j==r)
              {
                printf("i=%d and j=%d\n",i,j);

      //          printf("caught\n");
//                printf("i=%d and j=%d\n",i,j);
                for(k=0;k<r;k++)
                {
                  printf("loop fault\n");
                  work[k]=work[k]+allocate[i][k];
                }
                result[c]=i;
                printf("%d %d\t",c,i);
                printf("result[%d]=%d  \n",c,result[c]);
                c++;
                flag[i]=1;
                found=1;
              }

            }

          }
    //      printf("%d \t",c);
    //    printf("out of for loop\n");
    //    return;
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
          printf("%d\t ",result[i]);
      }

}
