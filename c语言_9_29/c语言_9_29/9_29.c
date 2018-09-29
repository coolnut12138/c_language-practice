#define _CRT_SECURE_NO_WARNINGS 1
////乘法口诀函数
//#include<stdio.h>
//int mul(int x)
//	{
//		int i = 0;
//		int j = 0;
//		for(i=1; i<=x; i++)
//		{
//			for(j=1; j<=i; j++)
//			{
//				printf("%2d*%2d=%2d ",i,j,i*j);
//			}
//			printf("\n");
//		}
//		return 0;
//	}
//	
//int main()
//	{
//		int n = 0;
//		printf("请输入数字：\n");
//		scanf("%d",&n);
//		mul(n);
//		return 0;
//	}



////交换两个数的函数
//#include<stdio.h>
//void swap(int *x,int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入要交换的两个数\n");
//	scanf("%d %d",&a,&b);
//	printf("交换前a=%d b=%d\n",a,b);
//	swap(&a,&b);
//	printf("交换后a=%d b=%d\n",a,b);
//	return 0;
//}



////判断闰年函数
//#include<stdio.h>
//int is_leapyear(int x)
//{
//	if(((x%4==0)&&(x%100!=0))||(x%400==0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//
//int main()
//{
//	int year = 0;
//	int a = 0;
//	printf("请输入年份：\n");
//	scanf("%d",&year);
//	is_leapyear(year);
//	a = is_leapyear(year);
//	if(1 == a)
//	{
//		printf("%d是闰年\n",year);
//	}
//	else
//	{
//		printf("%d不是闰年\n",year);
//	}
//	return 0;
//}



////创建一个数组， 
////实现函数init（）初始化数组、 
////实现empty（）清空数组、 
////实现reverse（）函数完成数组元素的逆置。 
////要求：自己设计函数的参数，返回值。
//#include<stdio.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
//	printf("^^^^^^^^^^1.初始化数组  ^^^^^^^^^\n");
//	printf("^^^^^^^^^^2.清空数组    ^^^^^^^^^\n");
//	printf("^^^^^^^^^^3.逆置数组元素^^^^^^^^^\n");
//	printf("^^^^^^^^^^0.退出        ^^^^^^^^^\n");
//	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
//}
//
//
//int init(int arr[],int len)
//{
//	int i = 0;
//	for(i=0; i<len; i++)
//	{
//		arr[i] = i;
//	}
//	return 0;
//}
//
//int empty(int arr[],int len)
//{
//	int i = 0;
//	for(i=0; i<len; i++)
//	{
//		arr[i] = 0;
//	}
//	return 0;
//}
//
//
//int reverse(int arr[],int len)
//{
//	int i = 0;
//	for(i=0; i<=len/2-1; i++)
//	{
//		int temp = arr[i];
//		arr[i] = arr[len-i-1];
//		arr[len-i-1] = temp;
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[10];
//	int i = 0;
//	int input = 0;
//	int j = 0;
//	int length = sizeof(arr)/sizeof(arr[0]);
//	menu();
//	do
//	{
//		printf("选择你要进行的操作:\n");
//		scanf("%d",&input);
//		switch(input)
//		{
//		case 1:
//			{
//				init(arr,length);
//				printf("初始化后的结果如下：\n");
//			for(j=0; j<10; j++)
//			{
//				printf("%d",arr[j]);
//			}
//			printf("\n");
//			break;
//			}
//		case 2:
//			{
//				empty(arr,length);
//				printf("已清空，清空后的结果如下：\n");
//			for(j=0; j<10; j++)
//			{
//				printf("%d",arr[j]);
//			}
//			printf("\n");
//				break;
//			}
//		case 3:
//			{
//				reverse(arr,length);
//				printf("已逆置，逆置后的结果如下：\n");
//			for(j=0; j<10; j++)
//			{
//				printf("%d",arr[j]);
//			}
//			printf("\n");
//				break;
//			}
//		case 0:
//			{
//				printf("已退出\n");
//				break;
//			}
//		default:
//			{
//				printf("选择错误，请重新选择\n");
//				break;
//			}
//		}
//	}while(input);
//	return 0;
//}





////判断素数的函数
//#include<stdio.h>
//int is_prime(int x)
//{
//	int i = 0;
//	for(i=2; i<x; i++)
//	{
//		if(0 == x%i)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//
//
//int main()
//{
//	int num = 0;
//	int a = 0;
//	printf("请输入一个数字：\n");
//	scanf("%d",&num);
//	is_prime(num);
//	a = is_prime(num);
//	if(1 == a)
//	{
//		printf("%d是素数\n",num);
//	}
//	else
//	{
//		printf("%d不是素数\n",num);
//	}
//	return 0;
//}



