#define _CRT_SECURE_NO_WARNINGS 1
//1.ģ��ʵ��strncpy(����ǰn���ַ�)
//#include<stdio.h>
//#include<assert.h>
//char * my_strncpy(char *dest,const char *src,size_t num)
//{
//	char *p = dest;
//	int i = 0;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while(num--)
//	{
//		*(dest + i) = *(src + i);
//		i++;
//	}
//	return p;
//}
//int main()
//{
//	char a1[1024] = {0};
//	char a2[1024] = "asdfgh";
//	my_strncpy(a1,a2,3);
//	puts(a1);
//	return 0;
//}
//2.ģ��ʵ��strncat(ƴ��ǰn���ַ�)
//#include<stdio.h>
//#include<assert.h>
//char * my_strncat(char *dest,const char *src,size_t num)
//{
//	char *ret = dest;
//	int i = 0;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while(*dest != '\0')
//	{
//		dest++;
//	}
//	while(num--)
//	{
//		*(dest + i) = *(src + i);
//		i++;
//	}
//	return ret;
//}
//int main()
//{
//	char a1[1024] = "today is";
//	char a2[1024] = " a good day or not";
//	my_strncat(a1,a2,11);
//	puts(a1);
//	return 0;
//}
//3.ģ��ʵ��strncmp(ǰn���ַ��Ƚ�)
#include<stdio.h>
#include<assert.h>
int my_strncmp(const char *dest,const char *src,size_t num)
{
	int i = 0;
	assert(dest != NULL);
	assert(src != NULL);
	while(num--)   //a1>a2����1��a1<a2����-1�����ڷ���0
	{
		if(*(dest + i) == *(src + i))
		{
			i++;
		}
		else if(*(dest + i) > *(src + i))
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	return 0;
}
int main()
{
	char a1[1024] = "zabcd";
	char a2[1024] = "fabc";
	printf("%d\n",my_strncmp(a1,a2,2));
	return 0;
}