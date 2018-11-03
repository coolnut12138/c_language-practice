#define _CRT_SECURE_NO_WARNINGS 1
//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
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
	printf("请输入要旋转几个字符：>");
	scanf("%d",&n);
	left_rotate(str,n,len);
	printf("%s\n",str);
	return 0;
}

//判断一个字符串是否为另外一个字符串旋转之后的字符串。
#include <stdio.h>
#include <string.h> 
int judge(char str1[],char str2[])
{    
	int i = 0;    
	int j = 0;    
	int len = strlen(str1);  
	//依次循环将每一位向左旋转，然后将两个字符串进行比较
	for (j = 1; j <= len; j++)    
	{        
		{            
			int tem = str1[0];  //将字符串首字符赋给tem          
			for (i = 0; i < len - 1; i++)    //左旋        
			{                
				str1[i] = str1[i + 1];            
			}            
			str1[len - 1] = tem;  // 将首字符赋给最后一位    
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
