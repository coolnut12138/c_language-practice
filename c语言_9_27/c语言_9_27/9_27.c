#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int binary_search(int arr[], int key, int left, int right)
//
//{
//
//	while(left<=right)
//
//	{
//
//		int mid = left+(right-left)/2;
//
//		if(arr[mid]>key)
//
//		{
//
//			right = mid-1;
//
//		}
//
//		else if(arr[mid]<key)
//
//		{
//
//			left = mid+1;
//
//		}
//
//		else
//
//		{
//
//			return mid;
//
//		}
//
//	}
//
//	return -1;
//
//}
//int main()
//
//{
//
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//
//	int key = 12;
//
//	int left = 0;
//
//	int right = sizeof(arr)/sizeof(arr[0])-1;
//
//
//
//	int ret= binary_search(arr, key, left, right);
//
//	if(ret == -1)
//
//		printf("找不到\n");
//
//	else
//
//		printf("找到了:%d\n", ret);
//
//	return 0;
//
//}









//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int left = 0;
//	int right = sizeof(arr)/sizeof(arr[0])-1;
//	int key = 0;
//	int mid = 0;
//	printf("请输入要查找的数：");
//	scanf("%d",&key);
//	while(left<=right)
//	{	
//		mid = (left+right)/2;
//		if(key<arr[mid])
//		{
//			right = mid-1;
//		}
//		else if(key>arr[mid])
//		{
//			left = mid+1;
//		}
//		else
//		{
//			break;
//		}
//	}
//	if(left<=right)
//	{
//		printf("你所查找的数字的下标为%d\n",mid);
//	}
//	else
//	{
//		printf("-1\n");
//	}
//}




//#include<stdio.h>
//int search(int arr[],int left,int right,int n)
//{
//	int mid = 0;
//	while(left<=right)
//	{
//		mid = (left + right)/2;
//		if(n < arr[mid])
//		{
//			right = mid-1;
//		}
//		else if(n > arr[mid])
//		{
//			left = mid+1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//		return -1;
//}
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,8,9,10};
//	int n = 0;
//	int left = 0;
//	int right = sizeof(arr)/sizeof(arr[0])-1;
//	int mid = 0;
//	printf("请输入要查找的数字");
//		scanf("%d",&n);
//	int a = search(arr,left,right,n);
//	if(a == -1)
//		return -1;
//	else
//		return mid;
//}

#include<string.h>
int main()
{
	char password[20] = {0};
	int i = 0;
	printf("请输入密码（只有三次机会）\n");
	for(i=3; i>0; i--)
	{
		scanf("%s",password);
		if(0 == strcmp(password,"123456"))
		{
			printf("登陆成功\n");
			break;
		}
		else 
		{
			printf("密码错误，你还有%d次机会\n",i-1);
		}

	}
	return 0;
}



//int main()
//{
//	printf("请输入一个字符\n");
//	while(1)
//	{
//	int i = 0;	
//	i = getchar();
//	if(i>='a' && i<='z')
//	{
//		putchar(i-32);
//	}
//	else if(i>='A' && i<='Z')
//	{
//		putchar(i+32);
//	}
//	else if(i>='0' && i<='9')
//	{
//		;
//	}
//	printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	printf("请输入一个字符\n");
//	while(1)
//	{
//	char i = 0;
//	scanf("%c",&i);
//	if(i>='a' && i<='z')
//	{
//		i-=32;
//		printf("%c\n",i);
//	}
//	else if(i>='A' && i<='Z')
//	{
//		i+=32;
//		printf("%c\n",i);
//	}
//	else if(i>='0' && i<='9')
//	{
//		printf("\n");
//	}
//	}
//	return 0;
//}