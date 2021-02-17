////一个数如果恰好等于它的因子之和，这个数就称为"完数"。例如6 = 1＋2＋3.编程找出1000以内的所有完数。
#include <stdio.h>
int AndSeveral(int i);
void PerfectNum(int i);


void PerfectNum(int i)
{
	int x, n, y;
	int pn[1000] = { 0 };
	int k = 0;
	for (x = 2; x < i; x++)//6
	{
		if (i % x == 0)//6%2==0
		{
			//i = i / x;//3
			pn[k] = x;//6 = 1 + 2 + 3  pn0=2;pn1=3
			k++;//n个元素n<k
		}
	}
	n = 0;
	for (y = 0; y < k; y++)
	{
		//printf("%d ", pn[y]);
		n =  n + pn[y];
	}
	n = n + 1;
	if (n == i)
		printf("%d\n", i);
	//printf("\n");
	//y = 0;
	//for (n = 0; n < k; n++)
	//{
	//	y = pn[n] + y;//2

	//}
	//if (x == i)
	//	return 1;
	//return y + 1;
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
		/*a = and [0];
		b = and [1];
		c = and [2];
		printf("%d", a);
		printf("%d", b);
		printf("%d", c);*/
		
	}
	//循环将and[]每一个元素依次传到函数中
	for (a = 0; a < k; a++)
	{
		b = and [a];
		PerfectNum(b);
		//printf("%d\n", b);
		/*c = PerfectNum(b);
		if (c == b)
		{
			printf("%d\n", b);
		}*/
	}
		//PerfectNum();//传一个合数，将它所有的因子都找出来相加，将和数返回
		//将返回的和数与传上去的合数对比，相同打印，不同跳过
		//循环k次
	return 0;
}
