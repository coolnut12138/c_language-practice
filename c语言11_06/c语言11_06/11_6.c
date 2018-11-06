#define _CRT_SECURE_NO_WARNINGS 1
//1.模拟实现strcpy(字符串拷贝)
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
//2.模拟实现strcat(字符串拼接)
#include<stdio.h>
#include<assert.h>
char * my_strcat(char *dest,const char *src)
{
	char *p = dest;
	assert(src);
	while(*dest)//不能用while(*dest++),因为strcat的功能是把src所指字符串添加到dest结尾处(覆盖dest结尾
               //处的'\0')并添加'\0',while(*dest++)在循环结束后还会执行一次++，会指向'\0'的下一个位置
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
//3.模拟实现strstr(字符串查询,一个字符串是否是另一个字符串的子串)
#include<stdio.h>
#include<assert.h>
char * my_strstr(char *dest, const char *src)
{
	const char *s1 = dest;//父串
	const char *s2 = src;//子串
	const char *cur = dest;//记录父串地址
	assert(dest);
	assert(src);
	if(*src == '\0')
		return dest;
	while(*cur)
	{
		s1 = cur;
		s2 = src;
		while(*s1 == *s2 && *s1 != '\0' && *s2 != '\0')//注意一定要判断是否到'\0'，否则会死循环
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
//4.模拟实现strchr(查找一个字符在字符串首次出现的位置)
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
	printf("%c这个字符在%s的首字符\n",'h',ptr);
	return 0;
}
//5.模拟实现strcmp(比较字符串)
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
		printf("字符串1大于字符串2\n");
	}
	else if(ret < 0)
	{
		printf("字符串1小于字符串2\n");
	}
	else
	{
		printf("两字符串相等\n");
	}
	return 0;
}
//6.模拟实现memcpy(从源指向的位置(起始位置)将count字节的值直接复制到目标指向的内存块)
#include<stdio.h>
#include<assert.h>
void *my_memcpy(void *dest,const void *src,size_t count)
{
	char *p = dest;//给目标和源转换类型，否则void*不知道大小
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
//7.模拟实现memmove(从源指向的位置拷贝count个字节的值放在目标所指向的位置)
//memmove用于从src拷贝count个字节到dest，如果目标区域和源区域有重叠的话，
//memmove能够保证源串在被覆盖之前将重叠区域的字节拷贝到目标区域中。
//但复制后src内容会被更改。但是当目标区域与源区域没有重叠则和memcpy函数功能相同。
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