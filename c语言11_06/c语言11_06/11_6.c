#define _CRT_SECURE_NO_WARNINGS 1
//1.ģ��ʵ��strcpy(�ַ�������)
#include<stdio.h>
#include<assert.h>
char * my_strcpy(char *dest,const char *str)
{
	char *p = dest;
	assert(dest);
	assert(str);
	while(*dest++ = *str++)
	{
		;
	}
	return p;
}
int main()
{
	char *arr = "hello world";
	char a[1024] = {0};
	my_strcpy(a,arr);
	puts(a);
	return 0;
}
//2.ģ��ʵ��strcat(�ַ���ƴ��)
#include<stdio.h>
#include<assert.h>
char * my_strcat(char *dest,const char *src)
{
	char *p = dest;
	assert(src);
	while(*dest)//������while(*dest++),��Ϊstrcat�Ĺ����ǰ�src��ָ�ַ�����ӵ�dest��β��(����dest��β
               //����'\0')�����'\0',while(*dest++)��ѭ�������󻹻�ִ��һ��++����ָ��'\0'����һ��λ��
	{
		dest++;
	}
	while(*dest++ = *src++)
	{
		;
	}
	return p;
}
int main()
{
	char *str = "man";
	char arr[1024] = "hello ";
	my_strcat(arr,str);
	puts(arr);
	return 0;
}
//3.ģ��ʵ��strstr(�ַ�����ѯ,һ���ַ����Ƿ�����һ���ַ������Ӵ�)
#include<stdio.h>
#include<assert.h>
char * my_strstr(char *dest, const char *src)
{
	const char *s1 = dest;//����
	const char *s2 = src;//�Ӵ�
	const char *cur = dest;//��¼������ַ
	assert(dest);
	assert(src);
	if(*src == '\0')
		return dest;
	while(*cur)
	{
		s1 = cur;
		s2 = src;
		while(*s1 == *s2 && *s1 != '\0' && *s2 != '\0')//ע��һ��Ҫ�ж��Ƿ�'\0'���������ѭ��
		{
			s1++;
			s2++;
		}
		if(*s2 == '\0')
		{
			return (char *)cur;
		}
		if(*s1 == '\0')
		{
			return NULL;
		}
		cur++;
	}
	return NULL;
}
int main()
{
	char *arr1 = "i am a student";
	char *arr2 = "student";
	char *ret = my_strstr(arr1,arr2);
	puts(ret);
	return 0;
}
//4.ģ��ʵ��strchr(����һ���ַ����ַ����״γ��ֵ�λ��)
#include<stdio.h>
#include<assert.h>
char * my_strchr(const char *dest,int n)
{
	assert(dest);
	while(*dest)
	{
		if(*dest == n)
		{
			return (char*)dest;
		}
		dest++;
	}
	return NULL;
}
int main()
{
	char *str = "asdfghjk,l";
	char *ptr = my_strchr(str,'h');
	printf("%c����ַ���%s�����ַ�\n",'h',ptr);
	return 0;
}
//5.ģ��ʵ��strcmp(�Ƚ��ַ���)
#include<stdio.h>
#include<assert.h>
int my_strcmp(const char *str1,const char *str2)
{
	assert(str1);
	assert(str2);
	while(*str1 && *str2)
	{
		if(*str1 > *str2)
			return 1;
		else if(*str1 < *str2)
			return -1;
		else 
		{
			str1++;
			str2++;
		}
	}
	return 0;
}
int main()
{
	char *arr1 = "good";
	char *arr2 = "bad";
	int ret = my_strcmp(arr1,arr2);
	if(ret > 0)
	{
		printf("�ַ���1�����ַ���2\n");
	}
	else if(ret < 0)
	{
		printf("�ַ���1С���ַ���2\n");
	}
	else
	{
		printf("���ַ������\n");
	}
	return 0;
}
//6.ģ��ʵ��memcpy(��Դָ���λ��(��ʼλ��)��count�ֽڵ�ֱֵ�Ӹ��Ƶ�Ŀ��ָ����ڴ��)
#include<stdio.h>
#include<assert.h>
void *my_memcpy(void *dest,const void *src,size_t count)
{
	char *p = dest;//��Ŀ���Դת�����ͣ�����void*��֪����С
	char *p1 = dest;
	const char *p2 = src;
	assert(dest);
	assert(src);
	while(count--)
	{
		*p1++ = *p2++;
	}
	return p;
}
int main()
{
	char arr1[1024] = {0};
	char *arr2 = "hello world";
	my_memcpy(arr1,arr2,7);
	puts(arr1);
	return 0;
}
//7.ģ��ʵ��memmove(��Դָ���λ�ÿ���count���ֽڵ�ֵ����Ŀ����ָ���λ��)
//memmove���ڴ�src����count���ֽڵ�dest�����Ŀ�������Դ�������ص��Ļ���
//memmove�ܹ���֤Դ���ڱ�����֮ǰ���ص�������ֽڿ�����Ŀ�������С�
//�����ƺ�src���ݻᱻ���ġ����ǵ�Ŀ��������Դ����û���ص����memcpy����������ͬ��
#include<stdio.h>
#include<assert.h>
void * my_memmove(void *dest,const void *src, size_t count)
{
	char *ret = dest;
	char *p1 = dest;
	const char *p2 = src;
	assert(src);
	assert(dest);
	if(dest < src)
	{
		while(count--)
		{
			*p1++ = *p2++;
		}
	}
	else
	{
		while(count--)
		{
			*(p1+count) = *(p2+count);
		}
	}
	return ret;
}
int main()
{
	char str1[1024] = "abcde";
	char *str2 = "fghijk";
	my_memmove(str1+4,str2,5);
	puts(str1);
	return 0;
}