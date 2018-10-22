#define _CRT_SECURE_NO_WARNINGS 1
//用*打印菱形
//      *
//     ***
//    *****
//   *******
//  *********
// ***********
//*************
// ***********
//  *********
//   *******
//    *****
//     ***
//      *
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int n = 0;
//	printf("请输入一个整数:\n");
//	scanf("%d",&n);
//	for(i=0; i<n; i++)//打印上三角
//	{
//		//打印一行
//		for(j=0; j<n-1-i; j++)
//		{
//			printf(" ");
//		}
//		for(j=0; j<2*i+1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for(i=0; i<n-1; i++)//打印下三角
//	{
//		//打印一行
//		for(j=0; j<=i; j++)
//		{
//			printf(" ");
//		}
//		for(j=0; j<2*(n-1-i)-1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//打印杨辉三角
//     1
//    1 1
//   1 2 1
//  1 3 3 1
// 1 4 6 4 1
//1
//11
//121
//1331
//14641
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	int arr[100][100] = {0};
	int n = 0;
	printf("请输入要几行杨辉三角：\n");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
	}
	for(i=2; i<n; i++)
	{
		for(j=1; j<i; j++)
		{
			arr[i][j] = arr[i-1][j]+arr[i-1][j-1];				
		}
		
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<=4*(n-i)/2; j++)
		{
			printf(" ");
		}
		for(j=0; j<=i; j++)
		{
			printf("%4d",arr[i][j]);
		}
		printf("\n");
	}
}