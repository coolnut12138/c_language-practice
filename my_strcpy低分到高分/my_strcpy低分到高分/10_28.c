#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�ͷ�д��
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

//6��
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

//8��
#include<assert.h>
//void my_strcpy(char *dest, char *str)
//{
//	assert(str != NULL);//����
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

//9��
//void my_strcpy(char *dest, const char *str)//����const�������øı�ı���
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

//10��
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