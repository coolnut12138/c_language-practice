#define _CRT_SECURE_NO_WARNINGS 1
////1.дһ���������ز����������� 1 �ĸ��� 
//#include<stdio.h>
//int count_one_bits(unsigned int value) 
//{
//	int count = 0;
//	while(value)
//	{
//		count++;
//		value = value&(value-1);//�ݹ�
//	}
//	return count;
//}
//int main()
//{
//	int ret = 0;
//	ret = count_one_bits(15);
//	printf("%d\n",ret);
//	return 0;
//}
//
////2.��ȡһ�������������������е�ż��λ������λ���ֱ�������������С�
//#include<stdio.h>
//int main()
//{
//	//�����������ڴ��и�λ��ǰ����λ�ں�
//	//1�Ķ�����Ϊ00000000 00000000 00000000 00000001
//	int i = 0;
//	int j = 0;
//	int num = 0;
//	int arr1[16] = {0};
//	int arr2[16] = {0};
//	printf("������һ��ʮ������\n");
//	scanf("%d",&num);
//	for(i=0,j=0; j<32; i++,j+=2)
//	{
//		arr1[15-i] = (num>>j)&1;
//	}
//	printf("�Ӹ�λ����λż��λΪ��\n");
//	for(i=0; i<16; i++)
//	{
//		printf("%d ",arr1[i]);
//	}
//	for(i=0,j=1; j<32; i++,j+=2)
//	{
//		arr2[15-i] = (num>>j)&1;
//	}
//	printf("\n");
//	printf("�Ӹ�λ����λ����λΪ��\n");
//	for(i=0; i<16; i++)
//	{
//		printf("%d ",arr2[i]);
//	}
//	printf("\n");
//	return 0;
//}
//
//3. ���һ��������ÿһλ��
//#include<stdio.h>
//void Print(int n)//�ݹ����
//{
//	if(n>0)
//	{
//		Print(n/10);
//		printf("%d ",n%10);
//	}
//}
//int main()
//{
//	int num = 0;
//	printf("������һ��������>");
//	scanf("%d",&num);
//	Print(num);
//	return 0;
//}
//
//#include<stdio.h>//�ǵݹ�
//void Print(int n)
//{
//	int i = 0;
//	int a = 0;
//	int arr[10000] = {0};
//	for(i=0; n>0; i++)
//	{
//		a = n%10;
//		n /=10;
//		arr[9999-i] = a;
//	}
//	for(i=0; i<10000; i++)
//	{
//		if(arr[i] == 0)
//		{
//			continue;
//		}
//		else
//		{
//		printf("%d ",arr[i]);
//		}
//	}
//}
//int main()
//{
//	int num = 0;
//	printf("������һ������:>");
//	scanf("%d",&num);
//	Print(num);
//	return 0;
//}
//
//���ʵ�֣� ����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
#include<stdio.h>
int compare(int x,int y)
{
	int i = 0;
	int count = 0;
	int equal = 0;
	for(i=0; i<32; i++)
	{
		((x>>i)&1)!=((y>>i)&1)?count++:equal++;
	}
	return count;
}
int main()
{
	int m = 0;
	int n = 0;
	int ret = 0;
	printf("����������������>");
	scanf("%d%d",&m,&n);
	ret = compare(m,n);
	printf("��%dλ��һ��\n",ret);
	return 0;
}