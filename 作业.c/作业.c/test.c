#define _CRT_SECURE_NO_WARNINGS
//1.��ӡ����
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (j = 2; j < i; j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (j == i)
//		{
//			printf("%d\n", i);
//		}
//	}
//	system("pause");
//	return 0;
//}
//2.��ӡ�˷��ھ���
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d       ", i, j, i*j);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//3.��ӡ1000--2000�������
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//		{
//			printf("%d\n", year);
//		}
//	}
//	system("pause");
//	return 0;
//}
//1.�����������α�����ֵ
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	scanf("%d%d", &x, &y);
//	ret = x;
//	x = y;
//	y = ret;
//	printf("x=%d  y=%d\n",x, y);
//	system("pause");
//	return 0;
//}
//2.��������ʱ������������������ֵ
//int main()
//{
//	int x = 0;
//	int y = 0;
//	scanf("%d %d", &x, &y);
//	x = x^y;
//	y = x^y;
//	x = x^y;
//	printf("x=%d  y=%d\n", x, y);
//	system("pause");
//	return 0;
//}
//3.��10��������������
//int main()
//{
//	int i= 0;
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int ret = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i]>ret)
//		{
//			ret = arr[i];
//		}
//	}
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//4.���������Ӵ�С���
//int main()
//{
//	int i = 0;
//	int arr[4] = { 0 };
//	scanf("%d %d %d", arr);
//	for (i = 0; i < 3; i++)
//	{
//		if (arr[i] < arr[i + 1])
//		{
//			arr[i + 1] =arr[i];
//			arr[i] = arr[i+1];
//		}
//	}
//	printf("%d\n", arr);
//	system("pause");
//	return 0;
//}
//