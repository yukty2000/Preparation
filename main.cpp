#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int *arr=(int *)malloc(n*sizeof(int));
	scanf("%d",&arr[0]);
	int max,min;
	if(n==1)
	{
		printf("Yes\n");
		return 0;
	}
	max=min=arr[0];
	for(i=1;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i]>max)
			max=arr[i];
		else if(arr[i]<min)
			min=arr[i];
	}
	if(max!=arr[n-1])
	{
		printf("No\n");
		return 0;
	}
	int count=0;
	if(arr[0]<=arr[1])
	{
		count++;
	}
	else if((arr[0]-arr[1])==1)
	{
		count ++;
		arr[0]--;
	}
	else
	{
		printf("No\n");
		return 0;
	}
	for(i=1;i<n-1;i++)
	{
		if(arr[i]>=arr[i-1])
		{
			if(arr[i+1]>=arr[i])
			{
				count++;
			}
			else if((arr[i]-arr[i+1])==1)
			{
				arr[i]--;
				count ++;
			}
			else
			{
				printf("No\n");
				return 0;
			}
		}
		else
		{
			printf("No\n");
			return 0;
		}
	}
	count ++;
	if(count==n)
	{
		printf("Yes\n");
	}
	else
		printf("No\n");
}
