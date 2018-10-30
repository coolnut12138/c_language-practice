#define _CRT_SECURE_NO_WARNINGS 1
//调整数组使奇数全部都位于偶数前面。
#include<stdio.h>
void adjust(int arr[],const int len)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	//冒泡排序
	for(i=0; i<len-1; i++)
	{
		for(j=0; j<len-1-i; j++)
		{
			if(arr[j]%2 != 0)
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}
int main()
{
	int arr[9] = {1,2,3,4,5,6,7,8,9};
	int sz = 0;
	int i = 0;
	sz = sizeof(arr)/sizeof(arr[0]);
	adjust(arr,sz);
	for(i=0; i<sz; i++)
	{
		printf("%d",arr[i]);
	}
	return 0;
}
//杨氏矩阵
//有一个二维数组. 
//数组的每行从左到右是递增的，每列从上到下是递增的. 
//在这样的数组中查找一个数字是否存在。 
//时间复杂度小于O(N);
//数组： 
//1 2 3 
//2 3 4 
//3 4 5 
//
//1 3 4 
//2 4 5 
//4 5 6 
//
//1 2 3 
//4 5 6 
//7 8 9 
#include<stdio.h>
#define ROW 3
#define COL 3
int find(int arr[ROW][COL],int n,int row,int col)
{
	int x = 0;
	int y = col-1;
	while(x < row && y >= 0)
	{
		if(n < arr[x][y])
		{
			y--;
		}
		else if(n > arr[x][y])
		{
			x++;
		}
		else if(n == arr[x][y])
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[ROW][COL] = {1,2,3,4,5,6,7,8,9};
	int num = 0;
	printf("请输入要查找的数字\n");
	scanf("%d",&num);
	find(arr,num,ROW,COL);
	if(find(arr,num,ROW,COL))
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}
	return 0;
}