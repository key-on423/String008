#include <stdio.h>
#include <string.h>


//9.��дһ�����������ַ����е��������䷴���ַ������档��һ�������ĳ����в��Ըú�����ʹ��һ��ѭ���������ṩ����ֵ
//char* s_gets(char* st, int n);
//int main()
//{
//	char arr1[80];
//	printf("������һ���ַ������ҽ���ӡ���ĵ���:\n");
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


//10.��дһ����������һ���ַ�����Ϊ��������ɾ���ַ����еĿո���һ�������в��Ըú�����ʹ��ѭ����ȡ�����У�ֱ���û�����һ�п���
//�ó���Ӧ��ʹ�øú��������ȡÿ��������ַ���������ʾ�����Ľ��
//#define max 50
//char* s_gets(char* st, int n);
//char* trim(char* st);
//int main()
//{
//	char arr1[max];
//	char* p = NULL;
//	printf("������һ���ַ���:\n");
//	s_gets(arr1, max);
//	while (*arr1 != '\0')
//	{
//		p = trim(arr1);
//		printf("�ı����ַ���Ϊ��\n");
//		puts(arr1);
//		printf("Ҫ��������һ���ַ�����(�հ������˳�)\n");
//		s_gets(arr1, max);
//	}
//	printf("����\n");
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
//	char* head = st;//�ֱ�ʹ��st��head����ָ���ʾԭ�ַ�����ɾ������ַ���
//
//	int count = 0;//ͳ�ƿո���
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
//	//while (count--)  ���п���
//		*head++ = '\0';//ɾ���ո����ĩβ��ӿ��ַ��������ʣ���ַ�;
//	return st;
//}



//11.��дһ�����򣬶���10���ַ������߶���#ʱֹͣ���ó���Ϊ�û��ṩһ����5��ѡ��Ĳ˵�����ӡԴ�ַ����б���ASCII�е�˳���ӡ�ַ����������ȵ���˳��
//��ӡ�ַ��������ַ����е�1�����ʵĳ��ȴ�ӡ�ַ������˳����˵�����ѭ����ʾ�������û�ѡ���˳�ѡ�
#include <ctype.h>
#define max 50
#define NUMBER 5
void menu();
char* s_gets(char* st, int n);
char getch(char ch);
int get_word_length(char* input);
void sort_order(int n, int order[][2]);
//���¶��ǰ��յ������򣬼���С�����
void aaa(char st[][max], int n);
void bbb(char st[][max], int n);
void ccc(char st[][max], int n);
void ddd(char st[][max], int n);
int main(int  argc,char *argv[])
{
	char arr1[10][max];
	printf("�����������ַ���(10������):\n");
	int i = 0;
	while (i < 10 && s_gets(arr1[i], max) != NULL && arr1[i][0] != '\0')
	{
		printf("��������һ���ַ������߿����������:\n");
		i++;
		
	}
	printf("iΪ%d������\n",i);
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
		printf("�㻹��ִ�������Ĳ���?\n");
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
	printf("a.��ӡԴ�ַ����б�                  	b.��ASCII�е�˳���ӡ�ַ���\n");
	printf("c.�����ȵ���˳���ӡ�ַ���              d.���ַ����е�1�����ʵĳ��ȴ�ӡ�ַ���\n");
	printf("g.�˳�\n");
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
	printf("��ASCII��ֵ˳���ӡΪ:\n");
	for (i = 0;i < n;i++)
	{
		//ASCII������Ҫ��ȡ����ĸ����Ϊ����������order����ڶ�����
		order[i][0] = i;
		order[i][1] = st[i][0];
	}
	sort_order(n, order);//������һ����ַ���Կ����ڱ༭�ĺ����иı�
	for (i = 0;i < n;i++)
	{
		printf("ASCII %d. %s\n", i, st[order[i][0]]);//��������order�������� st���arr1  ʵ������ֵΪorder[i][0]
		
	}
}
void ccc(char st[][max], int n)
{
	printf("���ַ�������˳���ӡΪ:\n");
	int i = 0;
	int order[10][2];
	for (i = 0;i < n;i++)
	{
		//�ַ�������������Ҫ��ȡ�ַ������ȣ���Ϊ����������order����ڶ�����
		order[i][0] = i;
		order[i][1] = strlen(st[i]);
	}
	sort_order(n, order);//������һ����ַ���Կ����ڱ༭�ĺ����иı�
	for (int i = 0;i < n;i++)
	{
		printf("�ַ�����������: %d. %s\n", i + 1, st[order[i][0]]);

	}

}
void ddd(char st[][max], int n)
{
	printf("���ַ����е�1�����ʵĳ���˳���ӡ�ַ���Ϊ��\n");
	int i = 0;
	int order[10][2];
	for (i = 0;i < n;i++)
	{
		//����һ������������Ҫ��ȡ�׵��ʳ��ȣ���Ϊ����������order����ڶ�����
		order[i][0] = i;
		order[i][1] = get_word_length(st[i]);//��ȡ�ַ�����һ�����ʵĳ���
	}
	sort_order(n, order);//������һ����ַ���Կ����ڱ༭�ĺ����иı�
	for (int i = 0;i < n;i++)
	{
		printf("�ַ�����������: %d. %s\n", i + 1, st[order[i][0]]);

	}
}

void sort_order(int n, int order[][2])//������һ����ַ���Կ����ڱ༭�ĺ����иı�
{
	//����������Ķ�ά����
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
	//�����Ĺ����Ǽ���ÿһ���ַ����е�һ�����ʵĳ���
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