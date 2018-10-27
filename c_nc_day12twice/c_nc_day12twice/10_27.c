#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//unsigned int reverse_bit(unsigned int value)
//{
//	unsigned int num = 0;
//	int i = 0;
//	for(i=0; i<32; i++)
//	{
//		num = num << 1;//把num左移放在前面是为了将按位或的结果少移一次，因为第1位移到第32位只需要移位31次
//		num |= (value >> i) & 1;
//	}
//	return num;
//}
//int main()
//{
//	int ret = 0;
//	int n = 0;
//	printf("请输入一个整数：\n");
//	scanf("%d",&n);
//	ret = reverse_bit(n); 
//	printf("反转后的值为：%u\n",ret);//记得输出无符号数时一定要用%u
//	return 0;
//}

//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。 
//请找出这个数字。（使用位运算） 
//#include<stdio.h>
//int main()
//{
//	int arr[] = {1,3,1,4,4,3,6,7,7};
//	int i = 0;
//	int len = sizeof(arr)/sizeof(arr[0]);
//	for(i=1; i<len; i++)
//	{
//		arr[0] = arr[0]^arr[i];//自己异或自己还是自己
//	}
//	printf("%d\n",arr[0]);
//	return 0;
//}

//有一个字符数组的内容为:"student a am i", 
//请你将数组的内容改为"i am a student". 
//要求： 
//不能使用库函数。 
//只能开辟有限个空间（空间个数和字符串的长度无关）。
//#include<stdio.h>
//#include<assert.h>
//int my_strlen(const char *arr)
//{
//	const char *p = arr;
//	assert(arr != NULL);
//	assert(p != NULL);
//	while(*arr != '\0')
//	{
//		arr++;
//	}
//	return arr-p;
//}
//void overthrow(char *left,char *right)
//{
//	assert(left != NULL);
//	assert(right != NULL);
//	while(left<right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void all_overthrow(char *str)
//{
//	int len = 0;
//	assert(str != NULL);
//	len = my_strlen(str);
//	overthrow(str,str+len-1);
//	while(*str != '\0')
//	{
//		char *p = str;
//		while((*str != ' ') && (*str != '\0'))
//		{
//			str++;
//		}
//		overthrow(p,str-1);
//		if(*str != '\0')
//		{
//			str++;
//		}
//	}
//}
//int main()
//{
//	char str[999] = {0};
//	printf("请输入一串字符:>");
//	gets(str);
//	all_overthrow(str);
//	puts(str);
//	return 0;
//}

////计算二进制位中1的个数
//#include<stdio.h>
//int count_one_bits(unsigned int value)
//{
//	int sum = 0;
//	while(value)
//	{
//		value = value & (value-1);
//		sum++;
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	printf("请输入一个整数：>");
//	scanf("%d",&n);
//	ret = count_one_bits(n);
//	printf("有%d位1\n",ret);
//	return 0;
//}

#include<stdio.h>
int count_one_bits(unsigned int value)
{
	int count = 0;
	while(value)
	{
		if((value&1) == 1)//模1取最低位数字
		{
			count++;
		}
		value >>=1;
	}
	return count;
}
int main()
{
	int n = 0;
	int ret = 0;
	printf("请输入一个整数：>");
	scanf("%d",&n);
	ret = count_one_bits(n);
	printf("有%d位1\n",ret);
	return 0;
}