#include<stdio.h>
int main()
{
	int a[5],i;
	int *q = a;
	for (i=0;i<5;i++)
	{
		//scanf("%d",&q[i]);
		//scanf("%d",&a[i]);
		//scanf("%d",q+i);
		scanf("%d",a+i);
	}
	
	for (i=0;i<5;i++)
	{
		//printf(" %d ",*a+i);
		//printf(" %d ",*q+i);
		//printf(" %d ",a[i]);
		printf(" %d ",q[i]);
		//printf(" %d ",a+i); //memory locations
	}
}
