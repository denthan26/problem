//一个数如果恰好等于它的因子之和，这个数就称为"完数"。例如6 = 1＋2＋3.编程找出1000以内的所有完数。
#include <stdio.h>
int AndSeveral(int i);
int PerfectNum(int i);


int PerfectNum(int i)
{
	int a, n, b;
	int pn[1000] = { 0 };
	int k = 0;
	for (a = 2; a < i; a++)
	{
		if (i % a == 0)
		{
			pn[k] = a;//6 = 1 + 2 + 3  pn0=2;pn1=3
			k++;//n个元素n<k
		}
		b = 0;
		for (n = 0; n < k; n++)
		{
			b += pn[n];//2

		}
		if (a == i)
			return 1;
		return b + 1;

	}
}
int AndSeveral(int i)
{
	int a = 0;
	for (a = 2; a < i; a++)
	{
		if (i % a == 0)
		{
			return i;
			break;
		}

	}
	return 1;
}
int main()
{
	int i, ret, k, a, b, c;
	int and [1000] = { 0 };
	k = 0;
	for (i = 2; i <= 1000; i++)
	{
		//找出所有合数
		ret = AndSeveral(i);
		if (ret != 1)//=1表示一个合数也没有
		{
			and [k] = ret;
			//printf("%d\n", and[k]);
			if (i < 1000)
				k++;
		}
		//循环将and[]每一个元素依次传到函数中
		for (a = 0; a <= k; a++)
		{
			b = and[a];
			c = PerfectNum(b);
			if (c == and[a])
			{
				printf("%d ", and[a]);
			}
		}
		//PerfectNum();//传一个合数，将它所有的因子都找出来相加，将和数返回
		//将返回的和数与传上去的合数对比，相同打印，不同跳过
		//循环k次
	}
	return 0;
}






//错误方式，未返回值
//未进行调试2021/2/6
