#define _CRT_SECURE_NO_WARNINGS 1
//ʵ��һ�����������������ַ����е�k���ַ�
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
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
//		//����һ��
//		temp = *str;
//		cur = str;//ÿ��ѭ����Ҫ���¸�ֵ
//		while(*(cur + 1) != '\0')
//		{
//			//ÿ���ַ���ǰŲ��һ��λ��
//			*cur = *(cur + 1);
//			cur++;
//		}
//		//�ѵ�һ��λ�õ����ݷŵ����һ��λ��
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
//������ת��ʵ������
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
//һ��������ֻ�����������ǳ���һ�Σ������������ֳ���������
//��򣺵������ֵ����������Ľ�� a^b^c = a^c^b = c^b^a
//       �������ֵ�������
//position ----->������е�һ������1��λ��
//��positioλ���������϶���һ��Ϊ0��һ��Ϊ1
//��positionλ��ֵ��������ֳ������֣�һ���֣�positionλֵΪ0����һ������ֵΪ1
//ÿһ���ֶ���һ��ֻ����һ�ε����֣������Ķ��ǳɶԳ��ֵ�
//ÿһ��������һ��������㣬����Ľ����Ϊ�������ֵ�����
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
//	//�������
//	for(i=0; i<len; i++)
//	{
//		ret ^=a[i];
//	}
//	//Ѱ��ret��һ��λ�ó���1��λ��
//	for(i=0; i<32; i++)
//	{
//		if(((ret >> i) & 1) == 1)
//		{
//			pos = i;
//			break;
//		}
//	}
//	//������ֳ�������
//	for(i=0; i<len; i++)
//	{
//		//���posλֵΪ1
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
//����ˮ��һƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ���ƿ
//#include<stdio.h>
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	printf("������Ǯ��");
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
//ģ��strcpy
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
//ģ��ʵ��strcat
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