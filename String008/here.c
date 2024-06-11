#include <stdio.h>
#include <string.h>


//9.编写一个函数，把字符串中的内容用其反序字符串代替。在一个完整的程序中测试该函数，使用一个循环给函数提供输入值
//char* s_gets(char* st, int n);
//int main()
//{
//	char arr1[80];
//	printf("请输入一个字符串，我将打印他的倒序:\n");
//	s_gets(arr1, 80);
//	int i = strlen(arr1)-1;
//	while (i >= 0)
//	{
//		printf("%c", arr1[i]);
//		i--;
//	}
//	return 0;
//}
//char* s_gets(char* st, int n)
//{
//	char* ret_val;
//	ret_val = fgets(st, n, stdin);
//	if (ret_val)
//	{
//		while (*st != '\n' && *st != '\0')
//			st++;
//		if (*st == '\n')
//			*st = '\0';
//		else
//			while (getchar() != '\n')
//				continue;
//	}
//	return ret_val;
//}


//10.编写一个函数接受一个字符串作为参数，并删除字符串中的空格。在一个程序中测试该函数，使用循环读取输入行，直到用户输入一行空行
//该程序应该使用该函数输入读取每个输入的字符串，并显示处理后的结果
//#define max 50
//char* s_gets(char* st, int n);
//char* trim(char* st);
//int main()
//{
//	char arr1[max];
//	char* p = NULL;
//	printf("请输入一串字符串:\n");
//	s_gets(arr1, max);
//	while (*arr1 != '\0')
//	{
//		p = trim(arr1);
//		printf("改变后的字符串为：\n");
//		puts(arr1);
//		printf("要输入另外一个字符串吗？(空白输入退出)\n");
//		s_gets(arr1, max);
//	}
//	printf("结束\n");
//	return 0;
//}
//char* s_gets(char* st, int n)
//{
//	char* ret_val;
//	ret_val = fgets(st, n, stdin);
//	if (ret_val)
//	{
//		while (*st != '\n' && *st != '\0')
//			st++;
//		if (*st == '\n')
//			*st = '\0';
//		else
//			while (getchar() != '\n')
//				continue;
//	}
//	return ret_val;
//}
//char* trim(char* st)
//{
//	char* head = st;//分别使用st和head两个指针表示原字符串和删除后的字符串
//
//	int count = 0;//统计空格数
//	while (*st != '\0')
//	{
//		if (*st != ' ')
//		{
//			*head++ = *st++;//important!
//		}
//		else
//		{
//			st++;
//			count++;
//		}
//     }
//	//while (count--)  可有可无
//		*head++ = '\0';//删除空格后，在末尾添加空字符，并清除剩余字符;
//	return st;
//}



//11.编写一个程序，读入10个字符串或者读到#时停止。该程序为用户提供一个有5个选项的菜单：打印源字符串列表，以ASCII中的顺序打印字符串，按长度递增顺序
//打印字符串，按字符串中第1个单词的长度打印字符串，退出。菜单可以循环显示，除非用户选择退出选项。
#include <ctype.h>
#define max 50
#define NUMBER 5
void menu();
char* s_gets(char* st, int n);
char getch(char ch);
int get_word_length(char* input);
void sort_order(int n, int order[][2]);
//以下都是按照递增排序，即从小到大↓
void aaa(char st[][max], int n);
void bbb(char st[][max], int n);
void ccc(char st[][max], int n);
void ddd(char st[][max], int n);
int main(int  argc,char *argv[])
{
	char arr1[10][max];
	printf("请依次输入字符串(10个以内):\n");
	int i = 0;
	while (i < 10 && s_gets(arr1[i], max) != NULL && arr1[i][0] != '\0')
	{
		printf("请输入下一个字符串或者空行输入结束:\n");
		i++;
		
	}
	printf("i为%d接下来\n",i);
	menu();
	char ch;
	ch = getch(&ch);
	while (ch != 'g')
	{
		if (ch == 'a')
			aaa(arr1,i);
		if (ch == 'b')
			bbb(arr1,i);
		if (ch == 'c')
			ccc(arr1,i);
		if (ch == 'd')
			ddd(arr1,i);
		printf("你还想执行怎样的操作?\n");
		menu();
		ch = getch(&ch);
	}
	return 0;
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	ret_val = fgets(st, max, stdin);
	if (ret_val)
	{
		while (*st != '\n' && *st != '\0')
			st++;
		if (*st == '\n')
			*st = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
void menu()
{
	printf("a.打印源字符串列表                  	b.以ASCII中的顺序打印字符串\n");
	printf("c.按长度递增顺序打印字符串              d.按字符串中第1个单词的长度打印字符串\n");
	printf("g.退出\n");
}
void aaa(char st[][max], int n)
{
	int x = 0;
	while (x < n)
	{
		printf("%d %s\n",x+1,st[x]);
		x++;
	}
}
void bbb(char st[][max], int n)
{

	int i = 0;
	int order[5][2];
	printf("以ASCII码值顺序打印为:\n");
	for (i = 0;i < n;i++)
	{
		//ASCII排序需要提取首字母，作为特征保存至order数组第二列中
		order[i][0] = i;
		order[i][1] = st[i][0];
	}
	sort_order(n, order);//传的是一个地址所以可以在编辑的函数中改变
	for (i = 0;i < n;i++)
	{
		printf("ASCII %d. %s\n", i, st[order[i][0]]);//并不是用order打出结果用 st打出arr1  实际有用值为order[i][0]
		
	}
}
void ccc(char st[][max], int n)
{
	printf("按字符串长度顺序打印为:\n");
	int i = 0;
	int order[10][2];
	for (i = 0;i < n;i++)
	{
		//字符串长度排序需要提取字符串长度，作为特征保存至order数组第二列中
		order[i][0] = i;
		order[i][1] = strlen(st[i]);
	}
	sort_order(n, order);//传的是一个地址所以可以在编辑的函数中改变
	for (int i = 0;i < n;i++)
	{
		printf("字符串长度排序: %d. %s\n", i + 1, st[order[i][0]]);

	}

}
void ddd(char st[][max], int n)
{
	printf("按字符串中第1个单词的长度顺序打印字符串为：\n");
	int i = 0;
	int order[10][2];
	for (i = 0;i < n;i++)
	{
		//按第一个单词排序需要提取首单词长度，作为特征保存至order数组第二列中
		order[i][0] = i;
		order[i][1] = get_word_length(st[i]);//获取字符串第一个单词的长度
	}
	sort_order(n, order);//传的是一个地址所以可以在编辑的函数中改变
	for (int i = 0;i < n;i++)
	{
		printf("字符串长度排序: %d. %s\n", i + 1, st[order[i][0]]);

	}
}

void sort_order(int n, int order[][2])//传的是一个地址所以可以在编辑的函数中改变
{
	//函数对输入的二维数组
	int temp[2];
	for (int i = 0;i <n-1;i++)
	{
		for (int j = 0;j < n-1 - i;j++)
		{
			if (order[j][1] > order[j + 1][1])
			{
				temp[0] = order[i][0];
				temp[1] = order[i][1];
				order[j][0] = order[j + 1][0];
				order[j][1] = order[j + 1][1];
				order[j + 1][0] = temp[0];
				order[j + 1][1] = temp[1];
			}
		}
	}
}

int get_word_length(char* input)
{
	//函数的功能是计算每一个字符串中第一个单词的长度
	char* in = input;
	int length = 0;
	while (isalpha(*in) == 0)
		in++;
	while (isalpha(*in) != 0)
	{
		in++;
		length++;
	}
	return length;
}
char getch(char ch)
{
	ch = getchar();
	while (getchar() != '\n')
		continue;
	return ch;
}