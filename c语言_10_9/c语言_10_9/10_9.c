#define _CRT_SECURE_NO_WARNINGS 1

////1.1�ݹ����n��쳲�������
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
//	printf("��������Ҫ���ҵڼ���쳲���������\n");
//	scanf("%d",&n);
//	printf("��%d��쳲�������Ϊ%d\n",n,fib(n));
//	return 0;
//}
//
////1.2�ǵݹ����n��쳲�������
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
//	printf("��������Ҫ���ҵڼ���쳲���������\n");
//	scanf("%d",&n);
//	printf("��%d��쳲�������Ϊ%d\n",n,fib(n));
//	return 0;
//}
//
//
////2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ�� 
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
//	printf("�������Ӧ��n k��\n");
//	scanf("%d%d",&n,&k);
//	printf("%d^%d = %d",n,k,nk(n,k));
//	return 0;
//}
//
//
////3.дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
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
//	printf("������һ���Ǹ�������\n");
//	scanf("%d",&n);
//	printf("%d������֮��Ϊ%d\n",n,DigitSum(n));
//	return 0;
//}
//
//
////4.��дһ������reverse_string(char * string)���ݹ�ʵ�֣� 
////ʵ�֣��������ַ����е��ַ��������С� 
////Ҫ�󣺲���ʹ��C�������е��ַ�������������
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
//	//printf("������һ���ַ�����\n");
//	//scanf("%s",str);
//	printf("������%s\n",reverse_string(str));
//	return 0;
//}
//
//
////5.1�ݹ�ʵ��strlen
//#include<stdio.h>
//int my_strlen(char *arr)//�ݹ鷽ʽ
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
//	printf("������һ���ַ���\n");
//	scanf("%s",arr);   
//	printf("�ô��ַ��ĳ���Ϊ%d\n",my_strlen(arr));
//	return 0;
//} 
//
//
////5.2�ǵݹ�ʵ��strlen
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
//	printf("������һ���ַ���\n");
//	scanf("%s",arr);
//	printf("�ô��ַ��ĳ���Ϊ%d\n",my_strlen(arr));
//	return 0;
//}
//
//
////6.1�ݹ�ʵ����n�Ľ׳�
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
//	printf("������Ҫ��׳˵�����\n");
//	scanf("%d",&n);
//	printf("%d�Ľ׳�Ϊ%d\n",n,fac(n));
//	return 0;
//}
//
//
////6.2�ǵݹ�ʵ����n�Ľ׳�
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
//	printf("������Ҫ��׳˵�����\n");
//	scanf("%d",&n);
//	printf("%d�Ľ׳�Ϊ%d\n",n,fac(n));
//	return 0;
//}
//
//
////7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ 
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
//	printf("������һ��������\n");
//	scanf("%d",&n);
//	Print(n);
//	return 0;
//}