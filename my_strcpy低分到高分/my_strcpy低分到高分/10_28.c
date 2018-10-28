#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//低分写法
//void my_strcpy(char *dest, char *str)
//{
//	while(*str != '\0')
//	{
//		*dest = *str;
//		dest++;
//		str++;
//	}
//	*dest = *str;
//}
//int main()
//{
//	char *p = "hello world";
//	char arr[30] = {0};
//	my_strcpy(arr,p);
//	puts(arr);
//	return 0;
//}

//6分
//void my_strcpy(char *dest, char *str)
//{
//	while(*dest++ = *str++)
//	{
//		;
//	}
//}
//int main()
//{
//	char *p = "hello world";
//	char arr[30] = {0};
//	my_strcpy(arr,p);
//	puts(arr);
//	return 0;
//}

//8分
#include<assert.h>
//void my_strcpy(char *dest, char *str)
//{
//	assert(str != NULL);//断言
//	assert(dest != NULL);
//	//if(str == NULL)
//	//	return;
//	while(*dest++ = *str++)
//	{
//		;
//	}
//}
//int main()
//{
//	char *p = "hello world";
//	char arr[30] = {0};
//	my_strcpy(arr,p);
//	puts(arr);
//	return 0;
//}

//9分
//void my_strcpy(char *dest, const char *str)//加上const保护不用改变的变量
//{
//	assert(str != NULL);
//	assert(dest != NULL);
//	while(*dest++ = *str++)
//	{
//		;
//	}
//}
//int main()
//{
//	char *p = "hello world";
//	char arr[30] = {0};
//	my_strcpy(arr,p);
//	puts(arr);
//	return 0;
//}

//10分
//char *my_strcpy(char *dest, const char *str)
//{
//	char *ret = dest;
//	assert(str != NULL);
//	assert(dest != NULL);
//	while(*dest++ = *str++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char *p = "hello world";
//	char arr[30] = {0};
//	my_strcpy(arr,p);
//	puts(arr);
//	return 0;
//}