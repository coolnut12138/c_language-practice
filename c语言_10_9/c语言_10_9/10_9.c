#define _CRT_SECURE_NO_WARNINGS 1

////1.1递归求第n个斐波那契数
//#include<stdio.h>
//
//int fib(int n)
//{
//	if(n<=2)
//		return 1;
//	else
//		return fib(n-1)+fib(n-2);
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入你要查找第几个斐波那契数：\n");
//	scanf("%d",&n);
//	printf("第%d个斐波那契数为%d\n",n,fib(n));
//	return 0;
//}
//
////1.2非递归求第n个斐波那契数
//#include<stdio.h>
//
//int fib(int n)
//{
//	int i = 0;
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	for(i=0; i<n-2; i++)
//	{
//		c = a+b;
//		a = b;
//		b = c;
//	}
//	return c;
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入你要查找第几个斐波那契数：\n");
//	scanf("%d",&n);
//	printf("第%d个斐波那契数为%d\n",n,fib(n));
//	return 0;
//}
//
//
////2.编写一个函数实现n^k，使用递归实现 
//#include<stdio.h>
//
//int nk(int n,int k)
//{
//	if(k == 0)
//		return 1;
//	else if(k == 1)
//		return n;
//	else
//		return n*nk(n,k-1);
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	printf("请输入对应的n k：\n");
//	scanf("%d%d",&n,&k);
//	printf("%d^%d = %d",n,k,nk(n,k));
//	return 0;
//}
//
//
////3.写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
//#include<stdio.h>
//
//int DigitSum(int n)
//{
//	if(n>9)
//		return n%10+DigitSum(n/10);
//	else
//		return n;
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入一个非负整数：\n");
//	scanf("%d",&n);
//	printf("%d的数字之和为%d\n",n,DigitSum(n));
//	return 0;
//}
//
//
////4.编写一个函数reverse_string(char * string)（递归实现） 
////实现：将参数字符串中的字符反向排列。 
////要求：不能使用C函数库中的字符串操作函数。
//#include<stdio.h>
//
//char *reverse_string(char *string)
//{     
//	char *p=string;	
//	int n=0;	 
//	while(*p++!='\0')	 
//	{	    
//		n++;	 
//	} 
//	if(n>1)  
//	{    
//		char temp=string[0];	
//		string[0]=string[n-1];	
//		string[n-1]='\0';   
//		reverse_string(string+1);
//		string[n-1]=temp;  	
//		   
//	}  
//	return string;
//}
//int main()
//{
//	char str[1000] = {"abcde"};
//	//printf("请输入一个字符串：\n");
//	//scanf("%s",str);
//	printf("操作后%s\n",reverse_string(str));
//	return 0;
//}
//
//
////5.1递归实现strlen
//#include<stdio.h>
//int my_strlen(char *arr)//递归方式
//{ 
//	if(*arr == '\0')
//	{
//		return 0;  
//	} 
//	else
//	{
//		return 1 + my_strlen(arr + 1);  
//	}
//}
//int main()
//{	
//	char arr[1000];
//	printf("请输入一串字符：\n");
//	scanf("%s",arr);   
//	printf("该串字符的长度为%d\n",my_strlen(arr));
//	return 0;
//} 
//
//
////5.2非递归实现strlen
//#include<stdio.h>
//
//int my_strlen(char *arr)
//{
//	int num = 0;
//	while(*arr)
//	{
//		num++;
//		*arr++;
//	}
//	return num;
//}
//
//int main()
//{
//	char arr[1000];
//	printf("请输入一串字符：\n");
//	scanf("%s",arr);
//	printf("该串字符的长度为%d\n",my_strlen(arr));
//	return 0;
//}
//
//
////6.1递归实现求n的阶乘
//#include<stdio.h>
//
//int fac(int n)
//{
//	if(n == 0)
//		return 1;
//	else
//		return n*fac(n-1);
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入要求阶乘的数：\n");
//	scanf("%d",&n);
//	printf("%d的阶乘为%d\n",n,fac(n));
//	return 0;
//}
//
//
////6.2非递归实现求n的阶乘
//#include<stdio.h>
//
//int fac(int n)
//{
//	int sum = 1;
//	while(n>0)
//	{
//		sum *= n;
//		n--;
//	}
//	return sum;
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入要求阶乘的数：\n");
//	scanf("%d",&n);
//	printf("%d的阶乘为%d\n",n,fac(n));
//	return 0;
//}
//
//
////7.递归方式实现打印一个整数的每一位 
//#include<stdio.h>
//
//void Print(int n)
//{
//	if(n>9)
//	{
//		Print(n/10);
//	}
//	printf("%d ",n%10);
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入一个整数：\n");
//	scanf("%d",&n);
//	Print(n);
//	return 0;
//}