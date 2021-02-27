#include <stdio.h>
void collect(int* p);
void collect(int* p)
{
	int temp1, temp2, temp3;
	int arr[3];//用来存放收集的数
	temp1 = *p;
	temp2 = *(p + 1);
	temp3 = *(p + 2);
	if (temp1 == temp2 && temp2 == temp3)
		;
	else if (temp1 == temp2 || temp1 == temp3 || temp2 == temp3)
	{
		if (temp1 == temp2)//如果1、2数相等，比较3数与1数
		{
			if (temp1 < temp3)
				;//输出1<2<3
			else//1>3  1=2>3 将1与3对调
			{
				int temp = 0;
				temp = *p;
				*p = *(p + 2);
				*(p + 2) = temp;
			}//1<2=3
		}
		else if (temp1 == temp3)
		{
			if (temp2 < temp3)//2<1=3  1与2对调
			{
				int temp = 0;
				temp = *p;//5     255
				*p = *(p + 1);//2
				*(p + 1) = temp;//5
			}
			else//1=3<2   将2与3对调
			{
				int temp = 0;
				temp = *(p + 1);
				*(p + 1) = *(p + 2);
				*(p + 2) = temp;
			}
		}
		else//2=3
		{
			if (temp1 < temp3)
				;//1<2=3  
			else//2=3<1   将1与3对调
			{
				int temp = 0;
				temp = *p;
				*p = *(p + 2);
				*(p + 2) = temp;
			}
		}

	}
	else
	{
		if (temp1 > temp2 && temp1 > temp3)
		{
			if (temp2 > temp3)//3<2<1  1 3调换
			{
				int temp = 0;
				temp = *p;
				*p = *(p + 2);
				*(p + 2) = temp;
			}
			else//2<3<1       
			{
				*p = temp2;
				*(p + 1) = temp3;
				*(p + 2) = temp1;
			}
		}
		else if (temp2 > temp1 && temp2 > temp3)
		{
			if (temp1 > temp3)//3<1<2
			{
				*p = temp3;
				*(p + 1) = temp1;
				*(p + 2) = temp2;
			}
			else//1<3<2   2  3对调
			{
				int temp = 0;
				temp = *(p + 1);
				*(p + 1) = *(p + 2);
				*(p + 2) = temp;
			}
		}
		else//3最大
		{
			if (temp1 > temp2)//2<1<3
			{
				*p = temp2;
				*(p + 1) = temp1;
			}
			else//1<2<3
				;
		}
	}
}
int main()
{
	int arr[13] = { 1,3,5,7,9,10,25,26,30,35 };
	int i, j, min, max, count;
	int letin[3];

	for (i = 0; i < 10; i++)
	{
		printf("%4d", arr[i]);
	}
	printf("请输入你要添得3个数：>");
	//scanf("%d", &number);//8
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &letin[i]);
	}
	collect(letin);//将插入的数进行排序
	min = letin[0];
	max = letin[2];
	//输入的最小值>原数列的最大值
	//输入的最大值<原数列的最小值
	//直接输出
	if (min > 35 || min == 35)
	{
		arr[10] = letin[0];
		arr[11] = letin[1];
		arr[12] = letin[2];
	}
	else if (max < 1)//先定义一个新数组接收，在将arr重置
	{
		int newarr[13];
		for (i = 0; i < 3; i++)
		{
			newarr[i] = letin[i];
		}
		for (j = 3; j < 13; j++)
		{
			newarr[j] = arr[j - 3];
		}
		for (i = 0; i < 13; i++)
		{
			arr[i] = newarr[i];
		}
	}
	else//分两种情况：第一种letin3个数在arr中两个数之间；第二种无序
	{
		int newletin[3], m, n;
		int newarr[13];
		i = 0;
		while ( i < 10)
		{

			if (arr[i]<min && arr[i + 1]>max)//arr[i]<min<max<arr[i+1]
			{//1 3 5 7 9 10 25       11 12 13(9)  ,26,30,35
				int newarr[13], k, m, n;
				for (j = 0; j <= i; j++)
				{
					newarr[j] = arr[j];
				}
				for (j = i + 1; j <= i + 3; j++)
				{//7     6  7                    7-7 7-6 7-5
					newarr[j] = letin[j - i - 1];//7  0
				}
				for (j = i + 4; j < 13; j++)
				{//      10          7
					newarr[j] = arr[j - 3];//26
				}
				for (n = 0; n < 13; n++)
				{
					arr[n] = newarr[n];

				}
				//break;
			}
			i++;
		}
		count = 0;
		for (j = 0; j < 3; j++)//无序
		{
			for (i = 0; i < 10; i++)
			{//1,3,5,7,9,10,25,26,30,35       4 8 11
				if (arr[i] > letin[j])
				{
					newletin[j] = i;//2  4  6
					break;
				}
			}         //  0,1,2,3,4,5,6, 7, 8, 9,10,11,12  
		}//               1,3,4,5,7,8,9,10,11,25,26,30,35       
		for (m = 0; m < newletin[0]; m++)//[0,2)
		{
			newarr[m] = arr[m];//0 1->1 3                                                         1  3
		}
		newarr[newletin[0]] = letin[0];//  2  ///////////////////////////////////////////////           4
		for (m = newletin[0]+1; m <= newletin[1]; m++)//[3,4)
		{/////////[3,4]     2,3
			newarr[m] = arr[m-1];//1,3,5,7,9,10,25,26,30,35
		}                        //0,1,2,3,4, 5, 6, 7, 8, 9
		newarr[newletin[1]+1] = letin[1];//5   8
		for (m = newletin[1]+2; m <= newletin[2]+1; m++)//[5,6)
		{///////m=6  m=7
			newarr[m] = arr[m-2];
		}
		newarr[newletin[2]+2] = letin[2];//8
		for (m = newletin[2]+3; m < 13; m++)//[7,13)
		{///m=9 m<13
			newarr[m] = arr[m-3];
		}
		//newarr存有全部元素
		for (i = 0; i < 13; i++)
			arr[i] = newarr[i];
	}
	for (i = 0; i < 13; i++)
		printf("%d ", arr[i]);
	return 0;


}
