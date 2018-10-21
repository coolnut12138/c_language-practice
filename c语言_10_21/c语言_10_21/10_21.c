#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int count_one_bits(unsigned int value)
//{
//	int i = 0;
//	int count = 0;
//	for(i=1; i!=0; i<<=1)
//	{
//		if((value&1) == 1)
//		{
//			count++;
//		}
//		value >>= 1;
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d",&n);
//	ret = count_one_bits(n);
//	printf("%d",ret);
//	return 0;
//}

//
//#include<stdio.h>
//int count_one_bits(unsigned int value)
//{
//	int i = 1;
//	int count = 0;
//	for(i=0; i<32; i++)
//	{
//		if(((value>>i)&1) == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}


////用n&(n-1)的方法
//#include<stdio.h>
//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	while(value)
//	{
//		value = value&(value-1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d",&n);
//	ret = count_one_bits(n);
//	printf("%d",ret);
//	return 0;
//}


//#include<stdio.h>
//void print(int n)
//{
//	int i = 0;
//	//偶数位
//	for(i=31; i>0; i-=2)
//	{
//		printf("%d",(n>>i)&1);
//	}
//	printf("\n");
//	//奇数位
//	for(i=30; i>=0; i-=2)
//	{
//		printf("%d",(n>>i)&1);
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d",&n);
//	print(n);
//	return 0;
//}


//#include<stdio.h>
//void print(int n)
//{
//	int i = 0;
//	for(i = 31; i>0; i -= 2)
//	{
//		printf("%d ",(n>>i) & 1);
//	}
//	for(i = 30; i>=0; i -= 2)
//	{
//		printf("%d ",(n>>i) & 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	print(n);
//	return 0;
//}

//#include<stdio.h>
//void print(int n)
//{
//	if(n>9)
//	{
//		print(n/10);	
//	}
//	printf("%d ",n%10);
//}
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);
//	print(n);
//	return 0;
//}

#define N 10
#include<stdio.h>
int main()
{
	int a[N][N];
	int i = 0;
	int j = 0;
	for(i=0; i<N; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}
	for(i=2; i<N; i++)
	{
		for(j=1; j<i; j++)
		{
			a[i][j] = a[i-1][j]+a[i-1][j-1];
		}
	}
	for(i=0; i<N; i++)
	{
		for(j=0; j<4*(N-i)/2; j++)
		{
			printf(" ");
		}
		for(j=0; j<=i; j++)
		{
			printf("%4d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}