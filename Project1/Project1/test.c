#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 100; i <= 200;i++)
//	{
//
//		for (j = 2; j < i; j++)
//		{
//			if (i%j == 0)
//			{
//				break;
//			}
//		}
//		if (i == j)
//		{
//			printf("%5d", i);
//		}
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %d   ", i, j, i*j);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int year = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//			printf("%5d", year);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int a = 3;
//	int b = 1;
//	int c = 0;
//	c = a;
//	a = b;
//	b = c;
//	printf("a=%d,b=%d\n", a, b);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int a = 3;
//	int b = 1;
//	a = a^b;
//	b = a^b;
//	a = a^b;
//	printf("a=%d,b=%d\n", a, b);
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 7, 6, 4, 8, 9 };
//	int i = 0;
//	int max = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (arr[i]>max)
//			max = arr[i];
//	}
//	printf("%d\n", max);
//	system("pause");
//	return 0;
//}
//int main()
//
//{
//
//	int i = 0;
//
//	int arr[3] = { 0 };
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%d ", arr[i]);
//	}
//	for (i = 0; i < 3; i++)
//
//	{
//		if (arr[i] < arr[i + 1])
//
//		{
//
//			arr[i + 1] =arr[i];
//
//			arr[i] = arr[i+1];
//
//		}
//
//	}
//
//	printf("%d\n", arr);
//
//	system("pause");
//
//	return 0;
//
//}
//int main()

//{

//	int x;

//	int y;

//	int c = 0;

//	scanf("%d %d", &x, &y);

//	while (x%y != 0)

//	{

//		c = x%y;

//		x = y;

//		y = c;

//	}

//	printf("%d\n",y);

//	system("pause");

//	return 0;

//}