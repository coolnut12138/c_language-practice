#define _CRT_SECURE_NO_WARNINGS 1
//1.一个数组中只有两个数字是出现一次， 
//其他所有数字都出现了两次。 
//找出这两个数字，编程实现。 
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
//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水， 
//给20元，可以多少汽水。 
//编程实现。
//#include<stdio.h>
//int drink_sodawater(int total)
//{
//	int bottle = total;//初始总瓶数
//	int remainder = 0;//余数
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
//	printf("请输入钱数：>");
//	scanf("%d",&money);
//	printf("能喝%d瓶\n",drink_sodawater(money));
//	return 0;
//}
//3.模拟实现strcpy
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
//4.模拟实现strcat（附加一个字符串）
//#include<stdio.h>
//#include<assert.h>
//char *my_strcat(char *dest,const char *str)
//{
//	char *p = dest;
//	assert(dest);
//	assert(str);
//	//跳到最后一个字符
//	while(*dest != '\0')
//	{
//		dest++;
//	}
//	//拷贝
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