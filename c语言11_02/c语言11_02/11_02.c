#define _CRT_SECURE_NO_WARNINGS 1
//调整奇数位于数组的前半部分
//#include<stdio.h>
//void adjust(int arr[],int len)
//{
//	int left = 0;
//	int right = len - 1;
//	while(left < right)
//	{
//		//从左边开始找第一个偶数
//		while((left < right) && (arr[left] % 2 != 0))
//		{
//			left++;
//		}
//		//从右边开始找第一个奇数
//		while((left < right) && (arr[right] % 2) == 0)
//		{
//			right--;
//		}
//		if(left < right)
//		{
//			int temp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = temp;
//		}
//	}
//}
//int main()
//{
//	int i = 0;
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int len = sizeof(arr)/sizeof(arr[0]);
//	adjust(arr,len);
//	for(i=0; i<len; i++)
//	{
//		printf("%d",arr[i]);
//	}
//	return 0;
//}

//从杨氏矩阵中查找数字
//1.从右上角开始找，如果要找的值大于当前值，向下找，否则，向左找，方向确定
//2.从左下角开始找，如果要找的值大于当前值，向右找，否则，向上找，方向确定
//---->最大时间复杂度O(row + col) < O(N)
#include<stdio.h>
void find(int a[3][3],int row,int col,int k,int *px,int *py)
{
	//从右上角开始找
	int i = 0;
	int j = col - 1;
	while((i < row) && (j >= 0))
	{
		//如果找到k的值，保存k所表示的位置
		if(a[i][j] == k)
		{
			*px = i;
			*py = j;
			return;
		}
		//如果当前值小于k，向下走
		else if(a[i][j] < k)
		{
			i++;
		}
		//如果当前值大于k，向左走
		else
		{
			j--;
		}
	}
	//没有找到，赋无效值
	*px = -1;
	*py = -1;
}
void find2(int a[3][3],int row,int col,int k,int *px,int *py)
{
	//从左下角找
	int i = row - 1;
	int j = 0;
	while((i >= 0) && (j <= col-1))
	{
		if(a[i][j] == k)
		{
			*px = i;
			*py = j;
			return;
		}
		else if(a[i][j] < k)
		{
			j++;
		}
		else
		{
			i--;
		}
	}
	*px = -1;
	*py = -1;
}
//从右上角开始找，递归方法
int search(/*数组信息*/int a[3][3],int row,int col,/*查找的数以及坐标*/int k,int x,int y,
		   /*存放的位置*/int *px,int *py)
{
	//出口
	if((x >= row) || (y<0))
	{
		//如果返回值为0，表示没有找到
		return 0;
	}
	if(a[x][y] == k)
	{
		*px = x;
		*py = y;
		//如果返回值为1，表示找到；
		return 1;
	}
	else if(a[x][y] > k)
	{
		//如果当前值大于k，向左走，找更小的值
		return search(a,row,col,k,x,y-1,px,py);
	}
	else
	{
		//如果当前值小于k，向下走，找更大的值
		return search(a,row,col,k,x+1,y,px,py);
	}
}
//从坐下角开始找，递归方法
int search2(/*数组信息*/int a[3][3],int row,int col,/*查找的数*/int k,/*起始坐标*/int x,int y,
		   /*存放的位置*/int *px,int *py)
{
	//出口
	if((x < 0) || (y >= col))
	{
		//如果返回值为0，表示没有找到
		return 0;
	}
	if(a[x][y] == k)
	{
		*px = x;
		*py = y;
		//如果返回值为1，表示找到；
		return 1;
	}
	else if(a[x][y] > k)
	{
		//如果当前值大于k，向上走，找更小的值
		return search2(a,row,col,k,x-1,y,px,py);
	}
	else
	{
		//如果当前值小于k，向右走，找更大的值
		return search2(a,row,col,k,x,y+1,px,py);
	}
}
int main()
{
	int a[3][3] = {1,2,3,4,5,6,7,8,9};
	int px = 0;
	int py = 0;
	int px1 = 0;
	int py1 = 0;
	int px2 = 0;
	int py2 = 0;
	int px3 = 0;
	int py3 = 0;
	find(a,3,3,9,&px,&py);
	printf("%d,%d\n",px,py);
	find2(a,3,3,9,&px1,&py1);
	printf("%d,%d\n",px1,py1);
	search(a,3,3,9,0,2,&px2,&py2);
	printf("%d,%d\n",px2,py2);
	search2(a,3,3,9,2,0,&px3,&py3);
	printf("%d,%d",px3,py3);
	return 0;
}