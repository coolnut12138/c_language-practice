#define _CRT_SECURE_NO_WARNINGS 1
////�˷��ھ�����
//#include<stdio.h>
//int mul(int x)
//	{
//		int i = 0;
//		int j = 0;
//		for(i=1; i<=x; i++)
//		{
//			for(j=1; j<=i; j++)
//			{
//				printf("%2d*%2d=%2d ",i,j,i*j);
//			}
//			printf("\n");
//		}
//		return 0;
//	}
//	
//int main()
//	{
//		int n = 0;
//		printf("���������֣�\n");
//		scanf("%d",&n);
//		mul(n);
//		return 0;
//	}



////�����������ĺ���
//#include<stdio.h>
//void swap(int *x,int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("������Ҫ������������\n");
//	scanf("%d %d",&a,&b);
//	printf("����ǰa=%d b=%d\n",a,b);
//	swap(&a,&b);
//	printf("������a=%d b=%d\n",a,b);
//	return 0;
//}



////�ж����꺯��
//#include<stdio.h>
//int is_leapyear(int x)
//{
//	if(((x%4==0)&&(x%100!=0))||(x%400==0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//
//int main()
//{
//	int year = 0;
//	int a = 0;
//	printf("��������ݣ�\n");
//	scanf("%d",&year);
//	is_leapyear(year);
//	a = is_leapyear(year);
//	if(1 == a)
//	{
//		printf("%d������\n",year);
//	}
//	else
//	{
//		printf("%d��������\n",year);
//	}
//	return 0;
//}



////����һ�����飬 
////ʵ�ֺ���init������ʼ�����顢 
////ʵ��empty����������顢 
////ʵ��reverse���������������Ԫ�ص����á� 
////Ҫ���Լ���ƺ����Ĳ���������ֵ��
//#include<stdio.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
//	printf("^^^^^^^^^^1.��ʼ������  ^^^^^^^^^\n");
//	printf("^^^^^^^^^^2.�������    ^^^^^^^^^\n");
//	printf("^^^^^^^^^^3.��������Ԫ��^^^^^^^^^\n");
//	printf("^^^^^^^^^^0.�˳�        ^^^^^^^^^\n");
//	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
//}
//
//
//int init(int arr[],int len)
//{
//	int i = 0;
//	for(i=0; i<len; i++)
//	{
//		arr[i] = i;
//	}
//	return 0;
//}
//
//int empty(int arr[],int len)
//{
//	int i = 0;
//	for(i=0; i<len; i++)
//	{
//		arr[i] = 0;
//	}
//	return 0;
//}
//
//
//int reverse(int arr[],int len)
//{
//	int i = 0;
//	for(i=0; i<=len/2-1; i++)
//	{
//		int temp = arr[i];
//		arr[i] = arr[len-i-1];
//		arr[len-i-1] = temp;
//	}
//	return 0;
//}
//
//int main()
//{
//	int arr[10];
//	int i = 0;
//	int input = 0;
//	int j = 0;
//	int length = sizeof(arr)/sizeof(arr[0]);
//	menu();
//	do
//	{
//		printf("ѡ����Ҫ���еĲ���:\n");
//		scanf("%d",&input);
//		switch(input)
//		{
//		case 1:
//			{
//				init(arr,length);
//				printf("��ʼ����Ľ�����£�\n");
//			for(j=0; j<10; j++)
//			{
//				printf("%d",arr[j]);
//			}
//			printf("\n");
//			break;
//			}
//		case 2:
//			{
//				empty(arr,length);
//				printf("����գ���պ�Ľ�����£�\n");
//			for(j=0; j<10; j++)
//			{
//				printf("%d",arr[j]);
//			}
//			printf("\n");
//				break;
//			}
//		case 3:
//			{
//				reverse(arr,length);
//				printf("�����ã����ú�Ľ�����£�\n");
//			for(j=0; j<10; j++)
//			{
//				printf("%d",arr[j]);
//			}
//			printf("\n");
//				break;
//			}
//		case 0:
//			{
//				printf("���˳�\n");
//				break;
//			}
//		default:
//			{
//				printf("ѡ�����������ѡ��\n");
//				break;
//			}
//		}
//	}while(input);
//	return 0;
//}





////�ж������ĺ���
//#include<stdio.h>
//int is_prime(int x)
//{
//	int i = 0;
//	for(i=2; i<x; i++)
//	{
//		if(0 == x%i)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//
//
//int main()
//{
//	int num = 0;
//	int a = 0;
//	printf("������һ�����֣�\n");
//	scanf("%d",&num);
//	is_prime(num);
//	a = is_prime(num);
//	if(1 == a)
//	{
//		printf("%d������\n",num);
//	}
//	else
//	{
//		printf("%d��������\n",num);
//	}
//	return 0;
//}



