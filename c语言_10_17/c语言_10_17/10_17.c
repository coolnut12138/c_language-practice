#define _CRT_SECURE_NO_WARNINGS 1
////1.写一个函数返回参数二进制中 1 的个数 
//#include<stdio.h>
//int count_one_bits(unsigned int value) 
//{
//	int count = 0;
//	while(value)
//	{
//		count++;
//		value = value&(value-1);//递归
//	}
//	return count;
//}
//int main()
//{
//	int ret = 0;
//	ret = count_one_bits(15);
//	printf("%d\n",ret);
//	return 0;
//}
//
////2.获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。
//#include<stdio.h>
//int main()
//{
//	//二进制数在内存中高位在前，低位在后
//	//1的二进制为00000000 00000000 00000000 00000001
//	int i = 0;
//	int j = 0;
//	int num = 0;
//	int arr1[16] = {0};
//	int arr2[16] = {0};
//	printf("请输入一个十进制数\n");
//	scanf("%d",&num);
//	for(i=0,j=0; j<32; i++,j+=2)
//	{
//		arr1[15-i] = (num>>j)&1;
//	}
//	printf("从高位到低位偶数位为：\n");
//	for(i=0; i<16; i++)
//	{
//		printf("%d ",arr1[i]);
//	}
//	for(i=0,j=1; j<32; i++,j+=2)
//	{
//		arr2[15-i] = (num>>j)&1;
//	}
//	printf("\n");
//	printf("从高位到低位奇数位为：\n");
//	for(i=0; i<16; i++)
//	{
//		printf("%d ",arr2[i]);
//	}
//	printf("\n");
//	return 0;
//}
//
//3. 输出一个整数的每一位。
//#include<stdio.h>
//void Print(int n)//递归调用
//{
//	if(n>0)
//	{
//		Print(n/10);
//		printf("%d ",n%10);
//	}
//}
//int main()
//{
//	int num = 0;
//	printf("请输入一个整数：>");
//	scanf("%d",&num);
//	Print(num);
//	return 0;
//}
//
//#include<stdio.h>//非递归
//void Print(int n)
//{
//	int i = 0;
//	int a = 0;
//	int arr[10000] = {0};
//	for(i=0; n>0; i++)
//	{
//		a = n%10;
//		n /=10;
//		arr[9999-i] = a;
//	}
//	for(i=0; i<10000; i++)
//	{
//		if(arr[i] == 0)
//		{
//			continue;
//		}
//		else
//		{
//		printf("%d ",arr[i]);
//		}
//	}
//}
//int main()
//{
//	int num = 0;
//	printf("请输入一个整数:>");
//	scanf("%d",&num);
//	Print(num);
//	return 0;
//}
//
//编程实现： 两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
#include<stdio.h>
int compare(int x,int y)
{
	int i = 0;
	int count = 0;
	int equal = 0;
	for(i=0; i<32; i++)
	{
		((x>>i)&1)!=((y>>i)&1)?count++:equal++;
	}
	return count;
}
int main()
{
	int m = 0;
	int n = 0;
	int ret = 0;
	printf("请输入两个整数：>");
	scanf("%d%d",&m,&n);
	ret = compare(m,n);
	printf("有%d位不一样\n",ret);
	return 0;
}