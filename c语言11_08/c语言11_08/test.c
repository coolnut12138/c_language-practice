#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
//{
//	printf("%d\n",sizeof(void *));
//	printf("%d\n",sizeof(char *));
//	return 0;
//}
//打印100~200之间的素数
//#include<stdio.h>
//#include<math.h>
//int is_prime(int arr[], int a, int b)
//{
//	int i = 0;
//	int j = 0;
//	int x = 0;
//	int count = 0;
//	//for(i=a; i<=b; i++)  //第一种
//	for(i=a+1; i<=b; i+=2)  //第二种
//	{
//		//for(j=2; j<=i-1; j++)  //第一种
//		//for(j=2; j<(i/2); j++)  //第二种
//		for(j=2; j<sqrt(i); j++) //第三种
//		{
//			if(i % j == 0)
//				break;
//		}
//		//if(i == j) //第一种
//		//if(j >= (i/2))//对j循环第二种
//		if(j >= sqrt(i))//对j循环第三种
//		{
//			arr[x] = i;
//			x++;
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int i = 0;
//	int a[1024] = {0};
//	int ret = is_prime(a,100,200);
//	for(i=0; i<ret; i++)
//	{
//		printf("%d ",a[i]);
//	}
//	printf("\n");
//	return 0;
//}
//输出乘法口诀表
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for(i=1; i<=9; i++)
//	{
//		for(j=1; j<=i; j++)
//		{
//			printf("%d*%d=%2d ",i,j,i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//判断1000年-2000年之间的闰年
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for(i=1000; i<=2000; i++)
//	{
//		if((i % 400 == 0)||((i % 4 == 0) && (i % 100 != 0)))
//		{
//			printf("%d ",i);
//		}
//	}
//	return 0;
//}
//给定两个整型变量的值，将两个值进行交换
//#include<stdio.h>
//void swap1(int *x,int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//void swap2(int *x,int *y)//不创建临时变量1
//{
//	*x = *x + *y;
//	*y = *x - *y;
//	*x = *x - *y;
//}
//void swap3(int *x,int *y)//不创建临时变量2异或
//{
//	*x = *x ^ *y;
//	*y = *x ^ *y;
//	*x = *x ^ *y;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	printf("%d,%d\n",a,b);
//	swap1(&a,&b);
//	printf("%d,%d\n",a,b);
//	swap2(&a,&b);
//	printf("%d,%d\n",a,b);
//	swap3(&a,&b);
//	printf("%d,%d\n",a,b);
//	return 0;
//}
//求10个整数中最大值
//#include<stdio.h>
//int findmax(int arr[],int sz)
//{
//	int i = 0;
//	int max = arr[0];
//	for(i=0; i<sz; i++)
//	{
//		if(arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	return max;
//}
//int main()
//{
//	int arr[10] = {1,2,3,4,5,6,7,8,9,0};
//	int len = sizeof(arr)/sizeof(arr[0]);
//	int ret = findmax(arr,len);
//	printf("最大值为%d\n",ret);
//	return 0;
//}
//将三个数按从大到小输出
//#include<stdio.h>
//void swap(int *x,int *y)
//{
//	*x = *x ^ *y;
//	*y = *x ^ *y;
//	*x = *x ^ *y;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	printf("请输入三个整数：>");
//	scanf("%d%d%d",&a,&b,&c);
//	if(a < b)
//	{
//		swap(&a,&b);
//	}
//	if(a < c)
//	{
//		swap(&a,&c);
//	}
//	if(b < c)
//	{
//		swap(&b,&c);
//	}
//	printf("%d,%d,%d",a,b,c);
//	return 0;
//}
//求两个数的最大公约数
//求两个数的最小公倍数
#include<stdio.h>
int findgcd(int a,int b)
{
	int i,min;
	min = a<b?a:b;
	for(i=min; i>=1; i--)
	{
		if((a % i == 0) && (b % i == 0))
			return i;
	}
}
int findlcm(int a,int b)
{
	int j,max;
	max = a>b?a:b;
	for(j=max;;j++)
	{
		if((j % a == 0) && (j % b == 0))
			return j;
	}
}
int main()
{
	int a = 0;
	int b = 0;
	int ret1 = 0;
	int ret2 = 0;
	printf("请输入两个正整数:>");
	scanf("%d%d",&a,&b);
	ret1 = findgcd(a,b);
	printf("最大公约数为%d\n",ret1);
	ret2 = findlcm(a,b);
	printf("最小公倍数为%d\n",ret2);
	return 0;
}