//一个数如果恰好等于它的因子之和，这个数就称为"完数"。例如6 = 1＋2＋3.编程找出1000以内的所有完数。
#include <stdio.h>
int AndSeveral(int i);


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
	int i, ret, k;
	int and [1000] = { 0 };
	k = 0;
	for (i = 2; i <= 1000; i++)
	{
		//找出所有合数
		ret = AndSeveral(i);
		if (ret != 1)//=1表示一个合数也没有
		{
			and[k] = ret;
			//printf("%d\n", and[k]);
			k++;
		}
		PerfectNum();//传一个合数，将它所有的因子都找出来相加，将和数返回
		//将返回的和数与传上去的合数对比，相同打印，不同跳过
		//循环k-1次
	}
	return 0;
}
