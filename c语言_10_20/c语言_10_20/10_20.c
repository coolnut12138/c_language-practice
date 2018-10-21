#define _CRT_SECURE_NO_WARNINGS 1
////5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果 
////A选手说：B第二，我第三； 
////B选手说：我第二，E第四； 
////C选手说：我第一，D第二； 
////D选手说：C最后，我第三； 
////E选手说：我第四，A第一； 
////比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for(a=1; a<=5; a++)
//	{
//		for(b=1; b<=5; b++)
//		{
//			for(c=1; c<=5; c++)
//			{
//				for(d=1; d<=5; d++)
//				{
//					for(e=1; e<=5; e++)
//					{
//						if((b==2 && a!=3) || (a==3 && b!=2))
//						{
//							if((b==2 && e!=4) || (e==4 && b!=2))
//							{
//								if((c==1 && d!=2) || (d==2 && c!=1))
//								{
//									if((c==5 && d!=3) || (d==3 && c!=5))
//									{
//										if((e==4 && a!=1) || (a==1 && e!=4))
//										{
//											if(120 == a*b*c*d*e)
//											{
//											printf("a = %d,b = %d,c = %d,d = %d,e = %d\n",a,b,c,d,e);
//											}
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}
//
////日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个 
////嫌疑犯的一个。以下为4个嫌疑犯的供词。 
////A说：不是我。 
////B说：是C。 
////C说：是D。 
////D说：C在胡说 
////已知3个人说了真话，1个人说的是假话。 
////现在请根据这些信息，写一个程序来确定到底谁是凶手。 
//#include<stdio.h>
//int main()
//{
//	char killer = 0;
//	for(killer='a'; killer<='d'; killer++)
//	{
//		if((killer!='a') + (killer=='c') + (killer=='d') + (killer!='d') == 3)
//			printf("凶手是%c\n",killer);
//	}
//	return 0;
//}
//
////打印杨辉三角
//#include<stdio.h>
//#define N 10
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int a[N][N] = {0};
//	for(i=0; i<N; i++)//给每一行的第一列和最后一列赋1
//	{
//		a[i][0] = 1;
//		a[i][i] = 1;
//	}
//	for(i=2; i<N; i++)//第三行开始第i行第j列是第i-1行第j列和第i-1行第j列的和
//	{
//		for(j=1; j<i; j++)
//		{
//			a[i][j] = a[i-1][j] + a[i-1][j-1];
//		}
//	}
//	for(i=0; i<N; i++)//输出
//	{
//		for(j=0; j<4*(N-i)/2; j++)//恰当的空格
//		{
//			printf(" ");
//		}
//		for(j=0; j<=i; j++)//输出每一行，第i行有i个元素
//		{
//			printf("%4d",a[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//#include <stdio.h>
//#include<stdlib.h>
//int c(int x, int y);
//int main()
//{	
//	int i, j,n=13;	
//	printf("N= ");	
//	while (n>12)	
//	{		
//		scanf("%d", &n);	
//	}	
//	for (i = 0; i <= n;i++)   //控制输出n行	
//	{		
//		for (j = 0; j < 12 - i;j++)		
//		{			
//			printf("  ");  //控制输出第i行前面的空格		
//		}		
//		for (j = 1; j < i + 2;j++)		
//		{			
//			printf("%5d", c(i, j));  //输出第i行第j个值		
//		}		
//		printf("\n");	
//	}	
//	system("pause");	
//	return 0;
//}
//int c(int x,int y)    //求杨辉三角形中第x行第y列的值
//{	
//	int z;	
//if ((y==1)||(y==x+1))	
//{		return 1;   //若为x行的第一或第x+1列，则输出1	
//}	z = c(x - 1, y - 1) + c(x - 1, y);	
//return z;   //否则，其值为前一行的第y-1列与第y列值之和
//}




//#include<stdio.h> 
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int n = 13;//定义i为行数，j为每一行的项数，n为总行数
//	for(i=1; i<=n/2+1; i++)//打印上三角
//	{
//		for(j=1; j<=n/2+i; j++)
//			if(j>=n/2-i+2)
//			{
//				printf("%d",i);
//			}
//			else
//			{
//				printf(" ");
//			}
//			printf("\n");
//	}
	//for(i=n/2; i>=1; i--)//打印下三角
	//{
	//	for(j=1; j<=n/2+i; j++)
	//		if(j>=n/2-i+2)
	//		{
	//			printf("*");
	//		}
	//		else
	//		{
	//			printf(" ");
	//		}
	//		printf("\n");
	//}
//	return 0;
//}
