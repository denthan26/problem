//因式分解
#include <stdio.h>
void restore(int i,int arr[],int k)
{
	
	int j = 0;
	for (j = 2; j < i; j++)
	{
		if (i % j == 0)//j=5时，此时i=5，
		{
			arr[k] = j;
			k++;
			i = i / j;
			restore(i, arr, k);
		}
		
	}
}

int main()
{
	int i = 90;//要因式分解的值 90=2*3*3*5
	int sz = 0;//计算arr中的个数
	int k = 0;
	int m = 0;
	//创建一个数组，用来存放因子
	int arr[] = { 0 };
	restore(i,arr,k);//进行影视分解的函数,把因子分解出来放在数组中
	sz = sizeof(arr) / sizeof(arr[0]);
	//printf("%d\n", sz);
	for (m = 0; m < sz; m++)
	{                        //0 1 2 3 
		printf("%d", arr[m]);//2*3*3*5
		if (m < sz - 1)
			printf("*");
	}
	return 0;
}