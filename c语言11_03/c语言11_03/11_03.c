#define _CRT_SECURE_NO_WARNINGS 1
//1.һ��������ֻ�����������ǳ���һ�Σ� 
//�����������ֶ����������Ρ� 
//�ҳ����������֣����ʵ�֡� 
#include<stdio.h>
void find(int arr[],int len,int *m,int *n)
{
	int s = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	for(i=0; i<len; i++)
	{
		s ^=arr[i];
	}
	for(k=1;;k = k << 1)
	{
		if(((k & s) != 0))
		{
			break;
		}
	}
	for(j=0; j<len; j++)
	{
		if((arr[j] & k) != 0)
		{
			*m ^= arr[j];
		}
	}
	*n = s^*m;
}
int main()
{
	int arr[10] = {1,1,2,3,3,4,4,5,7,7};
	int len = sizeof(arr)/sizeof(arr[0]);
	int m = 0;
	int n = 0;
	find(arr,len,&m,&n);
	printf("%d,%d",m,n);
	return 0;
}
//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ�� 
//��20Ԫ�����Զ�����ˮ�� 
//���ʵ�֡�
//#include<stdio.h>
//int drink_sodawater(int total)
//{
//	int bottle = total;//��ʼ��ƿ��
//	int remainder = 0;//����
//	while(bottle > 1)
//	{
//		total += bottle / 2;
//		remainder = bottle % 2;
//		bottle = bottle/2 + remainder;
//	}
//	return total;
//}
//int main()
//{
//	int money;
//	printf("������Ǯ����>");
//	scanf("%d",&money);
//	printf("�ܺ�%dƿ\n",drink_sodawater(money));
//	return 0;
//}
//3.ģ��ʵ��strcpy
//#include<stdio.h>
//#include<assert.h>
//char *my_strcpy(char *dest,const char *str)
//{
//	char *p = dest;
//	assert(dest);
//	assert(str);
//	while(*dest++ = *str++)
//	{
//		;
//	}
//	return p;
//}
//int main()
//{
//	char *arr1 = "abcdefg";
//	char arr2[10] = {0};
//	my_strcpy(arr2,arr1);
//	printf("%s\n",arr2);
//	return 0;
//}
//4.ģ��ʵ��strcat������һ���ַ�����
//#include<stdio.h>
//#include<assert.h>
//char *my_strcat(char *dest,const char *str)
//{
//	char *p = dest;
//	assert(dest);
//	assert(str);
//	//�������һ���ַ�
//	while(*dest != '\0')
//	{
//		dest++;
//	}
//	//����
//	while(*dest++ = *str++)
//	{
//		;
//	}
//	return p;
//}
//int main()
//{
//	char arr1[30] = "i am a";
//	char arr2[30] = " student";
//	my_strcat(arr1,arr2);
//	puts(arr1);
//	return 0;
//}