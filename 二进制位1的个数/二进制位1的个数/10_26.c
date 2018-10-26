#define _CRT_SECURE_NO_WARNINGS 1
//求一个数二进制位1的个数
//#include<stdio.h>
//int count_one_bits(unsigned int value) 
//{
//	int count = 0;
//	while(value)
//	{
//		value = value & (value-1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	printf("%d\n",count_one_bits(11));
//	return 0;
//}

//#include<stdio.h>
//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	while(value)
//	{
//		if((value & 1)==1)
//		{
//			count++;
//		}
//		value = value>>1;
//	}
//	return count;
//}
//int main()
//{
//	printf("%d\n",count_one_bits(15));
//	return 0;
//}

//获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。 
#include<stdio.h>
int main()
{
	int n = 0;
	int i = 0;
	int j = 0;
	int arr1[16] = {0};//奇数位
	int arr2[16] = {0};//偶数位
	printf("请输入一个整数：\n");
	scanf("%d",&n);
	for(i=0,j=0; i<32; i+=2,j++)//注意要写j+=2不能写j+2
	{
		arr1[15-j] = (n >> i) & 1;//奇数位
	}
	for(i=1,j=0; i<32; i+=2,j++)
	{
		arr2[15-j] = (n >> i) & 1;//偶数位
	}
	printf("奇数位从高到低为：\n");
	for(i=0; i<16; i++)
	{
		printf("%d",arr1[i]);
	}
	printf("\n");
	printf("偶数位从高到低为：\n");
	for(i=0; i<16; i++)
	{
		printf("%d",arr2[i]);
	}
	return 0;
}