//��ʽ�ֽ�
#include <stdio.h>
void restore(int i,int arr[],int k)
{
	
	int j = 0;
	for (j = 2; j < i; j++)
	{
		if (i % j == 0)//j=5ʱ����ʱi=5��
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
	int i = 90;//Ҫ��ʽ�ֽ��ֵ 90=2*3*3*5
	int sz = 0;//����arr�еĸ���
	int k = 0;
	int m = 0;
	//����һ�����飬�����������
	int arr[] = { 0 };
	restore(i,arr,k);//����Ӱ�ӷֽ�ĺ���,�����ӷֽ��������������
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