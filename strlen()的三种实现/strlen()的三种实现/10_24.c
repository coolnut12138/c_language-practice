#define _CRT_SECURE_NO_WARNINGS 1
//非递归实现
#include<stdio.h>
#include<assert.h>
int my_strlen1(const char *p)
{
	int count = 0;
	assert(p != NULL);
	while(*p != '\0')
	{
		count++;
		p++;
	}
	return count;
}
int main()
{
	char str[999] = {0};
	int ret = 0;
	printf("请输入一串字符：\n");
	gets(str);
	//scanf("%s",str);
	ret = my_strlen1(str);
	printf("字符串长度为：%d\n",ret);
	return 0;
}


//递归实现
#include<stdio.h>
#include<assert.h>
int my_strlen2(const char *p)
{
	assert(p != NULL);
	if(*p == '\0')
	{
		return 0;
	}
	else
	{
		return 1+my_strlen2(p+1);
	}
}
int main()
{
	char str[999] = {0};
	int ret = 0;
	printf("请输入一串字符：\n");
	gets(str);
	ret = my_strlen2(str);
	printf("字符串长度为:%d\n",ret);
	return 0;
}

//指针-指针实现
#include<stdio.h>
#include<assert.h>
int my_strlen3(const char *p)
{
	const char *s = p;
	assert(p != NULL);
	assert(s != NULL);
	while(*p != '\0')
	{
		p++;
	}
	return p-s;
}
int main()
{
	char str[999] = {0};
	int ret = 0;
	printf("请输入一串字符：\n");
	gets(str);
	ret = my_strlen3(str);
	printf("字符串的长度为：%d\n",ret);
	return 0;
}