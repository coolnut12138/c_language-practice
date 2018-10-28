#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
unsigned int reverse_bit(unsigned int n)
{
	int sum = 0;
	int i = 0;
	for(i=0; i<32; i++)
	{
		sum += ((n>>i) & 1) * pow(2, 31-i);
	}
	return sum;
}
int main()
{
	unsigned int n = 25;
	printf("%u\n",reverse_bit(n));
	return 0;
}

//unsigned int reverse_bit(unsigned int n)
//{
//	unsigned int ret = 0;
//	int i = 0;
//	for(i=0; i<32; i++)
//	{
//		ret <<= 1;
//		ret |= (n >> i) & 1;
//	}
//	return ret;
//}
//int main()
//{
//	unsigned int n = 25;
//	printf("%u\n",reverse_bit(n));
//	return 0;
//}

//��ʹ��(a+b)/2�ķ�ʽ������������ƽ��ֵ
//��һ�֣�һ��������һλ�൱��һ��������2  ��a+b��>>1
//�ڶ��֣� a+(b-a)>>1 = a + b/2 - a/2 = (a+b)/2        b+(a-b)>>1
//int average(int a,int b)
//{
//	return (a + b) >> 1;
//}
//int average2(int a,int b)
//{
//	return a+((b-a) >> 1);
//}
//int average3(int a,int b)
//{
//	return (a & b) + ((a ^ b) >> 1);
//}
//int main()
//{
//	printf("%d\n",average(500,1000));
//	printf("%d\n",average2(500,1000));
//	printf("%d\n",average3(500,1000));
//}

//int my_strlen(char *str)
//{
//	int count = 0;
//	while(*str++)
//	{
//		count++;
//	}
//	return count;
//}
//
//void reverse_str(char *start, char *end)
//{
//	while(start < end)
//	{
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//}
//void reverse(char *str)
//{
//	char *start = str;
//	char *end = str + my_strlen(str) - 1;
//	//�Ӵ�����ʼָ��
//	char *cur_start = str;
//	//������תһ��
//	reverse_str(start,end);
//	while(*cur_start)
//	{
//		//�ֲ����
//		char *start = cur_start;
//		while((*cur_start != '\0') && (*cur_start) != ' ')
//		{
//			cur_start++;
//		}
//		reverse_str(start,cur_start-1);
//		if(*cur_start != '\0')
//		{
//			cur_start++;
//		}
//	}
//}
//
//int main()
//{
//	char str[] = "student a am i";
//	puts(str);
//	reverse(str);
//	puts(str);
//	return 0;
//}