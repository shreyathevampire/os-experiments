#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct pt
{
	int fno;
	int bit;
}pt;

int contobin(int la, int arr[])
{
		int r,i=0,c=0;
		while(la>0)
		{
				r = la%2;
				arr[i++] = r;
				c++;
				la = la/2;
	}
			return c;
}

int contodec(int arr[], int n)
{
		int i=n,sum=0,a=n;
		while(i>=0)
		{
				sum = sum + (arr[i--]*pow(2,a));
					a = a-1;
		}
			return sum;
}

int noofbits(int la)
{
		int r,c=0, i=0;
		while(la>0)
		{
				r= la%2;
				c++;
				la = la/2;
	}
			return c;
}

void main()
{
		int la,pa,f,n,i,pg,c=0,r,z,m,nla,b,d,addr,sum=0,pag,a;
		int no,dec, arr[20], arr1[20];
		int copy[20]={0};

		struct pt pte[20];

		for(i=0;i< 20 ; i++)
				pte[i].bit=-1;
		printf("enter logical address in kB\n");
				scanf("%d",&la);
		la = la * pow(10,3);
	 			c = noofbits(la);
		nla=c;                     //no of bits in logical address
		printf("no of bits in logical address =%d \n", c);
		printf("enter physical address in kB\n");
				scanf("%d",&pa);
				pa = pa * pow(10,3);
				c = noofbits(pa);
				b=c;                          //no of bits in physical address
		printf("no of bits in physical address =%d   \n", c);
		printf("enter size of frame in kB   \n");
				scanf("%d",&f);
				f = f * pow(10,3);
				c = noofbits(f);
				d=c;                             //no of bits in size of frame
		printf("no of bits in f =%d \n", c);
		printf("enter no of page table entry\n");
				scanf("%d",&n);
		printf("enter page table entries\n");
		for(i=0;i<n;i++)
		{
				printf("enter page no and frame no\n");
						scanf("%d",&pg);
						scanf("%d",&pte[pg].fno);
				pte[pg].bit=1;
			}
		for(i=0;i<20;i++)
		{
				if(pte[i].bit==1)
						printf(" frame no [%d]=%d\n",i,pte[i].fno);
			}
  	printf("enter logical address\n");
						scanf("%d",&addr);
			i = contobin(addr, arr);
				m=i;
		printf("%d \n",m);
				i=nla-1;
		while(i>=0)
				printf("%d ",arr[i--]);
		printf("\n");
		m = nla - d;
		for( i= 0; i< m;i++)
				copy[i] = arr[d+i];
		for( i= 0; i< m;i++)
					printf("%d ",copy[i]);
		printf("\n");
			pag = contodec(copy,m-1);
		printf("page no = %d \n", pag);
				i=m-1;
		no = pte[pag].bit;
		if(no == -1)
		{
				printf("frame not avaialable\n");
				return;
	    }
		else
				printf("frame no = %d \n", pte[pag].fno);
		i=0;
		m=pte[pag].fno;
		while(m>0)
		{
					r= m%2;
					copy[i++]= r;
					m = m/2;
	    }
		for(i=(b-d)-1;i>=0 ; i--)
				printf("%d ",copy[i]);
		printf("\n");
		a=0;
		for(i=d ;i<b ;i++)
				arr[i] = copy[a++];

		i=b-1;
		while(i>=0)
					printf("%d ",arr[i--]);
		printf("\n");
		dec = contodec(arr,b-1);
		printf("physical address = %d\n",dec);
		printf("\n");
}





output:
enter logical address in kB
64
no of bits in logical address =16 
enter physical address in kB
1024
no of bits in physical address =20   
enter size of frame in kB   
2
no of bits in f =11 
enter no of page table entry
3
enter page table entries
enter page no and frame no
3 9
enter page no and frame no
2 11
enter page no and frame no
4 2
 frame no [2]=11
 frame no [3]=9
 frame no [4]=2
enter logical address
6050
13 
0 0 0 1 0 1 1 1 1 0 1 0 0 0 1 0 
0 1 0 0 0 
page no = 2 
frame no = 11 
0 0 0 0 0 1 0 1 1 
0 0 0 0 0 1 0 1 1 1 1 1 1 0 1 0 0 0 1 0 
physical address = 24482

