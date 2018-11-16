#define _CRT_SECURE_NO_WARNINGS 1
//1.��ת������Reverse Integer 
//Example1: x = 123, return 321
//Example2: x = -123, return -321
//���������  �����������ֵ2147483647��ת֮�������ֵ������
//Ҫ������ֵ��ת֮�����ж��Ƿ����
#include<stdio.h>
int reverse_int(int n)
{
	int max = 0x7fffffff;//int�����������ֵ
	int min = -max - 1; //int���͸�����Сֵ
	long long res = 0;//��ֹ��ת֮����������
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

//2.�ж��Ƿ��ǻ����ַ���
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
//		printf("�ǻ����ַ���\n");
//	}
//	else
//	{
//		printf("���ǻ����ַ���\n");
//	}
//}
//int main()
//{
//	int len = 0;
//	char arr[1024] = {0};
//	printf("����һ���ַ�\n");
//	scanf("%s",arr);
//	judge(arr);
//	return 0;
//}

//3.�ж��Ƿ��ǻ�����
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
//		printf("�ǻ�����\n");
//	}
//	else
//	{
//		printf("���ǻ�����\n");
//	}
//}
//int main()
//{
//	int n = 0;
//	int s = 0;
//	int y = 0;
//	printf("������һ��������\n");
//	scanf("%d",&n);
//	judge(n);
//	return 0;
//}
//#include<stdio.h>
//int is_pal(int n)
//{
//	int div = 1;
//	//��div��n��ͬһ��������
//	while((n / div) >= 10)
//	{
//		div *= 10;
//	}
//	//�ж������Ƿ�Ϊ������
//	while(n > 9)
//	{
//		//�жϵ�ǰ���λ�����λ�Ƿ���ͬ
//		if(n / div != n % 10)
//		{
//			return 0;
//		}
//		//��ͷ��ȥ�����λ
//		n %= div;
//		//ȥβ��ȥ�����λ
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

//4.��0��n֮��ȡ��n�������ҳ�©�����Ǹ�������n��������
//��ʹ�ö�������
//���  ȡ����n���� �� 0~n��2n+1��Ԫ�أ���n���ɶԳ��֣���һ��������һ��
//#include<stdio.h>
//int find(int a[],int n)
//{
//	// 0~n�����Χ����������һ������
//	//a[]�����������飬������n��Ԫ��
//	//�ҳ�2n+1��Ԫ���е������ֵ�����
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
//5.����һ���������ж����Ƿ���2����
//(�ж϶�������ֻ��һ��1)
//������λ���㣬2����������Ʊ�ʾֻ��һλ��1������λΪ0��
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
//			if(count)//��������
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
//	printf("������һ������\n");
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
//			printf("��\n");
//		}
//		else
//		{
//			printf("����\n");
//		}
//	}
//	else
//	{
//		printf("����\n");
//	}
//	return 0;
//}