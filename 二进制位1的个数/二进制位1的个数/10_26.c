#define _CRT_SECURE_NO_WARNINGS 1
//��һ����������λ1�ĸ���
//#include<stdio.h>
//int count_one_bits(unsigned int value) 
//{
//	int count = 0;
//	while(value)
//	{
//		value = value & (value-1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	printf("%d\n",count_one_bits(11));
//	return 0;
//}

//#include<stdio.h>
//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	while(value)
//	{
//		if((value & 1)==1)
//		{
//			count++;
//		}
//		value = value>>1;
//	}
//	return count;
//}
//int main()
//{
//	printf("%d\n",count_one_bits(15));
//	return 0;
//}

//��ȡһ�������������������е�ż��λ������λ���ֱ�������������С� 
#include<stdio.h>
int main()
{
	int n = 0;
	int i = 0;
	int j = 0;
	int arr1[16] = {0};//����λ
	int arr2[16] = {0};//ż��λ
	printf("������һ��������\n");
	scanf("%d",&n);
	for(i=0,j=0; i<32; i+=2,j++)//ע��Ҫдj+=2����дj+2
	{
		arr1[15-j] = (n >> i) & 1;//����λ
	}
	for(i=1,j=0; i<32; i+=2,j++)
	{
		arr2[15-j] = (n >> i) & 1;//ż��λ
	}
	printf("����λ�Ӹߵ���Ϊ��\n");
	for(i=0; i<16; i++)
	{
		printf("%d",arr1[i]);
	}
	printf("\n");
	printf("ż��λ�Ӹߵ���Ϊ��\n");
	for(i=0; i<16; i++)
	{
		printf("%d",arr2[i]);
	}
	return 0;
}