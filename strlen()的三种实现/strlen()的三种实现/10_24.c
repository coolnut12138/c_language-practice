#define _CRT_SECURE_NO_WARNINGS 1
//�ǵݹ�ʵ��
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
	printf("������һ���ַ���\n");
	gets(str);
	//scanf("%s",str);
	ret = my_strlen1(str);
	printf("�ַ�������Ϊ��%d\n",ret);
	return 0;
}


//�ݹ�ʵ��
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
	printf("������һ���ַ���\n");
	gets(str);
	ret = my_strlen2(str);
	printf("�ַ�������Ϊ:%d\n",ret);
	return 0;
}

//ָ��-ָ��ʵ��
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
	printf("������һ���ַ���\n");
	gets(str);
	ret = my_strlen3(str);
	printf("�ַ����ĳ���Ϊ��%d\n",ret);
	return 0;
}