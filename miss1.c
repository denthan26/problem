#include <stdio.h>

#include <string.h>
void characterdel(char arr[10], char del[3], int x, int y);



void characterdel(char arr[10], char del[3], int x, int y)
{
	int i, j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			//if(arr[i] == del[j]);
			if (strcmp(arr[i], del[j]) == 0)
			{
				arr[i] = ' ';
			}
		}
	}
	printf("%s\n", arr);
}
int main()
{
	char arr[10];
	char del[3];
	int c;
	printf("请输入最大长度为9的字符串：>");
	scanf("%s", &arr);
	while ((c = getchar()) != EOF && c != '\n');
	printf("请输入你要删除的字符：>");
	scanf("%s", &del);
	characterdel(arr,del,10,3);
	return 0;
}



//无法输出
