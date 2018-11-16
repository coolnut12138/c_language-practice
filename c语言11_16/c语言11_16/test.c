#define _CRT_SECURE_NO_WARNINGS 1
//1.逆转整数：Reverse Integer 
//Example1: x = 123, return 321
//Example2: x = -123, return -321
//处理溢出：  比如整数最大值2147483647逆转之后的整数值不存在
//要求所有值逆转之后再判断是否溢出
#include<stdio.h>
int reverse_int(int n)
{
	int max = 0x7fffffff;//int类型正数最大值
	int min = -max - 1; //int类型负数最小值
	long long res = 0;//防止逆转之后的整数溢出
	while(n != 0)
	{
		res = res * 10 + n % 10;
		n /= 10;
	}
	if(res > max || res < min)
	{
		return 0;
	}
	return res;
}
int main()
{
	int num = 0;
	int ret = 0;
	scanf("%d",&num);
	ret = reverse_int(num);
	printf("%d",ret);
	return 0;
}

//2.判断是否是回文字符串
//#include<stdio.h>
//#include<string.h>
//void judge(char *str)
//{
//	char *left = str;
//	char *right = str+strlen(str)-1;
//	while(left < right)
//	{
//		if(*left == *right)
//		{
//			left++;
//			right--;
//		}
//		else
//		{
//			break;
//		}
//	}
//	if(left == right)
//	{
//		printf("是回文字符串\n");
//	}
//	else
//	{
//		printf("不是回文字符串\n");
//	}
//}
//int main()
//{
//	int len = 0;
//	char arr[1024] = {0};
//	printf("输入一串字符\n");
//	scanf("%s",arr);
//	judge(arr);
//	return 0;
//}

//3.判断是否是回文数
//#include<stdio.h>
//#include<limits.h>
//void judge(int n)
//{
//	int a = 0;
//	int b = 0;
//	a = n;
//	while(a > 0)
//	{
//		b = b * 10 + a % 10;
//		a /= 10;
//	}
//	if(b == n)
//	{
//		printf("是回文数\n");
//	}
//	else
//	{
//		printf("不是回文数\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	int s = 0;
//	int y = 0;
//	printf("请输入一个正整数\n");
//	scanf("%d",&n);
//	judge(n);
//	return 0;
//}
//#include<stdio.h>
//int is_pal(int n)
//{
//	int div = 1;
//	//是div与n在同一个数量级
//	while((n / div) >= 10)
//	{
//		div *= 10;
//	}
//	//判断数字是否为回文数
//	while(n > 9)
//	{
//		//判断当前最高位和最低位是否相同
//		if(n / div != n % 10)
//		{
//			return 0;
//		}
//		//掐头：去掉最高位
//		n %= div;
//		//去尾：去掉最低位
//		n /= 10;
//		div /= 100;
//	}
//	return 1;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	printf("%d\n",is_pal(n));
//	return 0;
//}

//4.从0到n之间取出n个数，找出漏掉的那个数，这n个数乱序
//不使用额外数组
//异或：  取出的n个数 与 0~n共2n+1个元素，有n个成对出现，有一个出现了一次
//#include<stdio.h>
//int find(int a[],int n)
//{
//	// 0~n这个范围的数看出了一个数组
//	//a[]看成另外数组，包含了n个元素
//	//找出2n+1个元素中单独出现的数字
//	int i = 0;
//	int res = 0;
//	for(i = 0; i <= n; i++)
//	{
//		res ^= i;
//	}
//	for(i = 0; i < n; i++)
//	{
//		res ^= a[i];
//	}
//	return res;
//}
//int main()
//{
//	int a[] = {0,1,2,3,4,5,6,7,9};
//	printf("%d\n",find(a,sizeof(a)/sizeof(a[0])));
//	return 0;
//}
//5.给出一个整数，判断它是否是2的幂
//(判断二进制中只有一个1)
//可以移位运算，2的幂则二进制表示只有一位是1，其他位为0；
//1 0001
//2 0010
//4 0100
//8 1000
//#include<stdio.h>
//int is_pow(int n)
//{
//	int count = 0;
//	int i = 0;
//	for(i = 0; i < 32; i++)
//	{
//		if(((n >> i) & 1) == 1)
//		{
//			count++;
//		}
//	}
//	return count == 1;
//}
//int is_pow2(int n)
//{
//	int count = 0;
//	int i = 0;
//	for(i=0; i<32; i++)
//	{
//		if(((n >> i) & 1) == 1)
//		{
//			if(count)//减少冗余
//			{
//				return 0;
//			}
//			else
//			{
//				count++;
//			}
//		}
//	}
//	return count;
//}
//int main()
//{
//	int num = 0;
//	scanf("%d",&num);
//	printf("%d\n",is_pow(num));
//	printf("%d\n",is_pow2(num));
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int num = 0;
//	int s = 0;
//	printf("请输入一个整数\n");
//	scanf("%d",&num);
//	if(num > 0)
//	{
//		while(num > 2)
//		{
//			s = num / 2;
//			num /= 2;
//		}
//		if(s%2 == 0)
//		{
//			printf("是\n");
//		}
//		else
//		{
//			printf("不是\n");
//		}
//	}
//	else
//	{
//		printf("不是\n");
//	}
//	return 0;
//}