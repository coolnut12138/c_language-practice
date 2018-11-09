#define _CRT_SECURE_NO_WARNINGS 1
//实现一个函数，可以左旋字符串中的k个字符
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//#include<stdio.h>
//#include<string.h>
//void left_rotate(char *str,int k)
//{
//	int len = strlen(str);
//	char temp = 0;
//	char *cur = str;
//	k %= len;
//	while(k--)
//	{
//		//左旋一次
//		temp = *str;
//		cur = str;//每次循环都要重新赋值
//		while(*(cur + 1) != '\0')
//		{
//			//每个字符向前挪动一个位置
//			*cur = *(cur + 1);
//			cur++;
//		}
//		//把第一个位置的内容放到最后一个位置
//		*cur = temp;
//	}
//}
//int main()
//{
//	char str[5] = "abcd";
//	left_rotate(str,2);
//	printf("%s\n",str);
//	return 0;
//}
//三次逆转法实现左旋
//void 
//{
//	while()
//	{
//		char temp = *start;
//		*start = *end;
//		*end = temp;
//		start++;
//		end--;
//	}
//}
//一个数组中只有两个数字是出现一次，其他所有数字出现了两次
//异或：单独出现的两个数异或的结果 a^b^c = a^c^b = c^b^a
//       单独出现的两个数
//position ----->异或结果中第一个出现1的位置
//在positio位，两个数肯定有一个为0，一个为1
//以position位的值，把数组分成两部分，一部分：position位值为0，另一部分其值为1
//每一部分都有一个只出现一次的数字，其他的都是成对出现的
//每一部分再做一次异或运算，运算的结果即为单独出现的数字
//#include<stdio.h>
//int main()
//{
//	int a[] = {1,2,3,4,8,9,3,2,1,4};
//	int ret = 0;
//	int i = 0;
//	int pos = 0;
//	int x = 0;
//	int y = 0;
//	int len = sizeof(a)/sizeof(a[0]);
//	//整体异或
//	for(i=0; i<len; i++)
//	{
//		ret ^=a[i];
//	}
//	//寻找ret第一个位置出现1的位置
//	for(i=0; i<32; i++)
//	{
//		if(((ret >> i) & 1) == 1)
//		{
//			pos = i;
//			break;
//		}
//	}
//	//把数组分成两部分
//	for(i=0; i<len; i++)
//	{
//		//如果pos位值为1
//		if(((a[i] >> pos) & 1) == 1)
//		{
//			x ^= a[i];
//		}
//		else
//		{
//			y ^= a[i];
//		}
//	}
//	printf("%d %d",x,y);
//}
//喝汽水，一瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少瓶
//#include<stdio.h>
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	printf("请输入钱数");
//	scanf("%d", &money);
//	total = money;
//	empty = money;
//	while(empty > 1)
//	{
//		total += empty/2;
//		empty = empty/2 + empty % 2;
//	}
//	printf("%d",total);
//}
//模拟strcpy
//#include<stdio.h>
//#include<assert.h>
//char *my_strcpy(char *dest,const char *src)
//{
//	char *p = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while(*dest++ = *src++)
//	{
//		;
//	}
//	return p;
//}
//int main()
//{
//	char s1[1024] = {0};
//	char *s2 = "123486zxc";
//	my_strcpy(s1,s2);
//	puts(s1);
//	return 0;
//}
//模拟实现strcat
#include<stdio.h>
#include<assert.h>
char *my_strcat(char *dest,const char *src)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while(*dest != '\0')
	{
		dest++;
	}
	while(*dest++ = *src++);
	return ret;
}
int main()
{
	char a1[1024] = "asd";
	char *a2 = "z123456798cx";
	my_strcat(a1,a2);
	puts(a1);
	return 0;
}