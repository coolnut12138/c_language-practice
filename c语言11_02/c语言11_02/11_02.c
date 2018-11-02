#define _CRT_SECURE_NO_WARNINGS 1
//��������λ�������ǰ�벿��
//#include<stdio.h>
//void adjust(int arr[],int len)
//{
//	int left = 0;
//	int right = len - 1;
//	while(left < right)
//	{
//		//����߿�ʼ�ҵ�һ��ż��
//		while((left < right) && (arr[left] % 2 != 0))
//		{
//			left++;
//		}
//		//���ұ߿�ʼ�ҵ�һ������
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

//�����Ͼ����в�������
//1.�����Ͻǿ�ʼ�ң����Ҫ�ҵ�ֵ���ڵ�ǰֵ�������ң����������ң�����ȷ��
//2.�����½ǿ�ʼ�ң����Ҫ�ҵ�ֵ���ڵ�ǰֵ�������ң����������ң�����ȷ��
//---->���ʱ�临�Ӷ�O(row + col) < O(N)
#include<stdio.h>
void find(int a[3][3],int row,int col,int k,int *px,int *py)
{
	//�����Ͻǿ�ʼ��
	int i = 0;
	int j = col - 1;
	while((i < row) && (j >= 0))
	{
		//����ҵ�k��ֵ������k����ʾ��λ��
		if(a[i][j] == k)
		{
			*px = i;
			*py = j;
			return;
		}
		//�����ǰֵС��k��������
		else if(a[i][j] < k)
		{
			i++;
		}
		//�����ǰֵ����k��������
		else
		{
			j--;
		}
	}
	//û���ҵ�������Чֵ
	*px = -1;
	*py = -1;
}
void find2(int a[3][3],int row,int col,int k,int *px,int *py)
{
	//�����½���
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
//�����Ͻǿ�ʼ�ң��ݹ鷽��
int search(/*������Ϣ*/int a[3][3],int row,int col,/*���ҵ����Լ�����*/int k,int x,int y,
		   /*��ŵ�λ��*/int *px,int *py)
{
	//����
	if((x >= row) || (y<0))
	{
		//�������ֵΪ0����ʾû���ҵ�
		return 0;
	}
	if(a[x][y] == k)
	{
		*px = x;
		*py = y;
		//�������ֵΪ1����ʾ�ҵ���
		return 1;
	}
	else if(a[x][y] > k)
	{
		//�����ǰֵ����k�������ߣ��Ҹ�С��ֵ
		return search(a,row,col,k,x,y-1,px,py);
	}
	else
	{
		//�����ǰֵС��k�������ߣ��Ҹ����ֵ
		return search(a,row,col,k,x+1,y,px,py);
	}
}
//�����½ǿ�ʼ�ң��ݹ鷽��
int search2(/*������Ϣ*/int a[3][3],int row,int col,/*���ҵ���*/int k,/*��ʼ����*/int x,int y,
		   /*��ŵ�λ��*/int *px,int *py)
{
	//����
	if((x < 0) || (y >= col))
	{
		//�������ֵΪ0����ʾû���ҵ�
		return 0;
	}
	if(a[x][y] == k)
	{
		*px = x;
		*py = y;
		//�������ֵΪ1����ʾ�ҵ���
		return 1;
	}
	else if(a[x][y] > k)
	{
		//�����ǰֵ����k�������ߣ��Ҹ�С��ֵ
		return search2(a,row,col,k,x-1,y,px,py);
	}
	else
	{
		//�����ǰֵС��k�������ߣ��Ҹ����ֵ
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