#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//����һ�������ݹ�ʵ�ָ�����λ�ĺ�
//int Digitsum(int n)
//{
//	if (n > 9)
//	{
//		return n % 10 + Digitsum(n / 10);
//	}
//	return n;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d\n", Digitsum(n));
//	system("pause");
//	return 0;
//}
//�ַ�����ת
//reverse_string(char *str)
//{
//	if (*str)
//	{
//		char *start = str;
//		char* end = str + strlen(str) - 1;
//		char temp = *start;
//		*start = *end;
//		*end = '\0';
//		reverse_string(start + 1);
//		*end =temp;
//	}
//}
//int main()
//{
//	char str[100] = { 0 };
//	scanf("%s", str);
//	reverse_string(str);
//	printf("%s\n", str);
//	system("pause");
//	return 0;
//}
//�ݹ�ͷǵݹ�ʵ��strlen
//�ݹ�ʵ��strlen
//my_strlen(char*str)
//{
//	if (*str)
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	return 0;
//}
//int main()
//{
//	char str[100] = { 0 };
//	scanf("%s", str);
//	printf("%d\n", my_strlen(str));
//	system("pause");
//	return 0;
//}
//�ݹ�ͷǵݹ���n�Ľ׳�
//�ǵݹ飺ѭ������1~n����
//�ݹ飺�����0��1������1����������n*f(n-1)��
//�ݹ�ʵ�ִ�ӡ������ÿһλ
//print(int n)
//{
//	if (n >= 10)
//	{
//		print(n / 10);
//	}
//	printf("%d    ", n % 10);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print(n);
//	system("pause");
//	return 0;
//}
//д��һ���������ز�����������1�ĸ�����n>>&1==1(count++):���ư�λ��1��ʮһ����������һ������count��whileѭ�����Ӹ�Ч��
//while(n)
//{
//	n = n&(n - 1);//��ʾ�ӵ�λ����λ��һ�γ���1��λ��Ϊ0��
//	count++;
//}
