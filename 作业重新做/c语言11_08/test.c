#define _CRT_SECURE_NO_WARNINGS 1
//C day01

//#include<stdio.h>
//int main()
//{
//	printf("%d\n",sizeof(void *));
//	printf("%d\n",sizeof(char *));
//	return 0;
//}
//��ӡ100~200֮�������
//#include<stdio.h>
//#include<math.h>
//int is_prime(int arr[], int a, int b)
//{
//	int i = 0;
//	int j = 0;
//	int x = 0;
//	int count = 0;
//	//for(i=a; i<=b; i++)  //��һ��
//	for(i=a+1; i<=b; i+=2)  //�ڶ���
//	{
//		//for(j=2; j<=i-1; j++)  //��һ��
//		//for(j=2; j<(i/2); j++)  //�ڶ���
//		for(j=2; j<sqrt(i); j++) //������
//		{
//			if(i % j == 0)
//				break;
//		}
//		//if(i == j) //��һ��
//		//if(j >= (i/2))//��jѭ���ڶ���
//		if(j >= sqrt(i))//��jѭ��������
//		{
//			arr[x] = i;
//			x++;
//			count++;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int i = 0;
//	int a[1024] = {0};
//	int ret = is_prime(a,100,200);
//	for(i=0; i<ret; i++)
//	{
//		printf("%d ",a[i]);
//	}
//	printf("\n");
//	return 0;
//}
//����˷��ھ���
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	for(i=1; i<=9; i++)
//	{
//		for(j=1; j<=i; j++)
//		{
//			printf("%d*%d=%2d ",i,j,i*j);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//�ж�1000��-2000��֮�������
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	for(i=1000; i<=2000; i++)
//	{
//		if((i % 400 == 0)||((i % 4 == 0) && (i % 100 != 0)))
//		{
//			printf("%d ",i);
//		}
//	}
//	return 0;
//}

//C day02

//�����������ͱ�����ֵ��������ֵ���н���
//#include<stdio.h>
//void swap1(int *x,int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//void swap2(int *x,int *y)//��������ʱ����1
//{
//	*x = *x + *y;
//	*y = *x - *y;
//	*x = *x - *y;
//}
//void swap3(int *x,int *y)//��������ʱ����2���
//{
//	*x = *x ^ *y;
//	*y = *x ^ *y;
//	*x = *x ^ *y;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	printf("%d,%d\n",a,b);
//	swap1(&a,&b);
//	printf("%d,%d\n",a,b);
//	swap2(&a,&b);
//	printf("%d,%d\n",a,b);
//	swap3(&a,&b);
//	printf("%d,%d\n",a,b);
//	return 0;
//}

//��10�����������ֵ
//#include<stdio.h>
//int findmax(int arr[],int sz)
//{
//	int i = 0;
//	int max = arr[0];
//	for(i=0; i<sz; i++)
//	{
//		if(arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	return max;
//}
//int main()
//{
//	int arr[10] = {1,2,3,4,5,6,7,8,9,0};
//	int len = sizeof(arr)/sizeof(arr[0]);
//	int ret = findmax(arr,len);
//	printf("���ֵΪ%d\n",ret);
//	return 0;
//}

//�����������Ӵ�С���
//#include<stdio.h>
//void swap(int *x,int *y)
//{
//	*x = *x ^ *y;
//	*y = *x ^ *y;
//	*x = *x ^ *y;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	printf("����������������>");
//	scanf("%d%d%d",&a,&b,&c);
//	if(a < b)
//	{
//		swap(&a,&b);
//	}
//	if(a < c)
//	{
//		swap(&a,&c);
//	}
//	if(b < c)
//	{
//		swap(&b,&c);
//	}
//	printf("%d,%d,%d",a,b,c);
//	return 0;
//}
//////�������������Լ��
//////������������С������
////#include<stdio.h>
////int findgcd(int a,int b)
////{
////	int i,min;
////	min = a<b?a:b;
////	for(i=min; i>=1; i--)
////	{
////		if((a % i == 0) && (b % i == 0))
////			return i;
////	}
////}
////int findlcm(int a,int b)
////{
////	int j,max;
////	max = a>b?a:b;
////	for(j=max;;j++)
////	{
////		if((j % a == 0) && (j % b == 0))
////			return j;
////	}
////}
////int main()
////{
////	int a = 0;
////	int b = 0;
////	int ret1 = 0;
////	int ret2 = 0;
////	printf("����������������:>");
////	scanf("%d%d",&a,&b);
////	ret1 = findgcd(a,b);
////	printf("���Լ��Ϊ%d\n",ret1);
////	ret2 = findlcm(a,b);
////	printf("��С������Ϊ%d\n",ret2);
////	return 0;
////}

//C day03

//������A�е����ݺ�����B�е����ݽ��н�����������һ����
//#include<stdio.h>
//void swap_arr(int *a,int *b,int len1)
//{
//	int i = 0;
//	int temp = 0;
//	for(i=0; i<len1; i++)
//	{
//		temp = a[i];
//		a[i] = b[i];
//		b[i] = temp;
//	}
//}
//int main()
//{
//	int a[5] = {1,2,3,4,5};
//	int b[5] = {6,7,8,9,0};
//	int i = 0;
//	int len1 = sizeof(a)/sizeof(a[0]);;
//	swap_arr(a,b,len1);
//	for(i=0; i<len1; i++)
//	{
//		printf("%d",a[i]);
//	}
//	printf("\n");
//	for(i=0; i<len1; i++)
//	{
//		printf("%d",b[i]);
//	}
//	return 0;
//}

//////����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ
////#include<stdio.h>
////int main()
////{
////	double i = 0.0;
////	double sum = 0.0;
////	int n = 1;
////	for(i=1; i<=100; i++)
////	{
////		sum += n/i;  //��������Ҫ��ͬ
////		n *= -1;
////	}
////	printf("%lf",sum); //�����ʽҲҪһ��
////	return 0;
////}

// ��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9�� 
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for(i=1; i<=100; i++)
//	{
//		if((9 == (i % 10)) || (9 == ((i / 10) % 10)))
//		{
//			count++;
//		}
//	}
//	printf("%d\n",count);
//	return 0;
//}

//C day04

////����Ļ����*�������
////      * 
////     *** 
////    ***** 
////   ******* 
////  ********* 
//// *********** 
////************* 
//// *********** 
////  ********* 
////   ******* 
////    ***** 
////     *** 
////      * 
////#include<stdio.h>
////int main()
////{
////	int i = 0;
////	int j = 0;
////	int n = 0;
////	printf("������һ�����ִ�ӡ����");
////	scanf("%d",&n);
////	for(i=0; i<n/2+1; i++)//��ӡ������(7��)
////	{
////		for(j=0; j<n/2-i; j++)//��ӡÿһ�еĿո�
////		{
////			printf(" ");
////		}
////		for(j=0; j<i*2+1; j++)//��ӡÿһ�е�*
////		{
////			printf("*");
////		}
////		printf("\n");
////	}
////	for(i=0; i<n/2; i++)//��ӡ������(6��)
////	{
////		for(j=0; j<i+1; j++)//��ӡÿһ�еĿո�
////		{
////			printf(" ");
////		}
////		for(j=0; j<n-2-i*2; j++)//��ӡÿһ�е�*
////		{
////			printf("*");
////		}
////		printf("\n");
////	}
////	return 0;
////}
////#include<stdio.h> 
////int main()
////{
////	int i = 0;
////	int j = 0;
////	int n = 13;//����iΪ������jΪÿһ�е�������nΪ������
////	for(i=1; i<=n/2+1; i++)//��ӡ������
////	{
////		for(j=1; j<=n/2+i; j++)
////			if(j>=n/2-i+2)
////			{
////				printf("*");
////			}
////			else
////			{
////				printf(" ");
////			}
////			printf("\n");
////	}
////	for(i=n/2; i>=1; i--)//��ӡ������
////	{
////		for(j=1; j<=n/2+i; j++)
////			if(j>=n/2-i+2)
////			{
////				printf("*");
////			}
////			else
////			{
////				printf(" ");
////			}
////			printf("\n");
////	}
////	return 0;
////}

//���0��999֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ�������
//�磻153��1��5��3?����153��һ����ˮ�ɻ�������
//#include<stdio.h>
//int main()
//{
//	int i = 0;
//	int sum = 0;
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	for(i=100; i<=999; i++)
//	{
//		a = i%10;
//		b = (i/10)%10;
//		c = i/100;
//		if(a*a*a + b*b*b + c*c*c == i)
//		{
//			printf("%d\n",i);
//		}
//	}
//	return 0;
//}

//////��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣����磺2+22+222+2222+22222 
////#include<stdio.h>
////int main()
////{
////	int num = 0;
////	int sum = 0;
////	int sum1 = 0;
////	int i = 0;
////	printf("������һ������\n");
////	scanf("%d",&num);
////	for(i=0; i<5; i++)
////	{
////		sum1 = sum1*10 + num;
////		sum += sum1;
////	}
////	printf("%d\n",sum);
////	return 0;
////}