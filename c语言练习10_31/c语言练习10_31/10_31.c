#define _CRT_SECURE_NO_WARNINGS 1
//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<assert.h>
void left_rotate(char str[],int n,int sz)
{
	int i = 0;
	assert(str);
	n %= sz;
	while(n--)
	{
		char tmp = str[0];
		for(i=0; i<sz-1; i++)
		{
			str[i] = str[i+1];
		}
		str[sz-1] = tmp;
	}
}
int main()
{
	int n = 0;
	char str[] = "ABCD";
	int len = strlen(str);
	printf("������Ҫ��ת�����ַ���>");
	scanf("%d",&n);
	left_rotate(str,n,len);
	printf("%s\n",str);
	return 0;
}

//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
#include <stdio.h>
#include <string.h> 
int judge(char str1[],char str2[])
{    
	int i = 0;    
	int j = 0;    
	int len = strlen(str1);  
	//����ѭ����ÿһλ������ת��Ȼ�������ַ������бȽ�
	for (j = 1; j <= len; j++)    
	{        
		{            
			int tem = str1[0];  //���ַ������ַ�����tem          
			for (i = 0; i < len - 1; i++)    //����        
			{                
				str1[i] = str1[i + 1];            
			}            
			str1[len - 1] = tem;  // �����ַ��������һλ    
		}        
		if (0 == strcmp(str1, str2))        
		{            
			return 1;       
		}    
	}    
	return 0;
}
int main()
{    
	char s1[10] = "AABCD";    
	char s2[10] = "BCDAA";    
	printf("s1 = %s\n", s1);    
	printf("s2 = %s\n", s2);    
	printf("%d\n", judge(s1, s2));        
	return 0;
}
