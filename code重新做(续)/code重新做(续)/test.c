#define _CRT_SECURE_NO_WARNINGS 1
//C day05
//1.猜数字小游戏
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//int menu()
//{
//	int input = 0;
//	printf("1.play\n");
//	printf("0.exit\n");
//	scanf("%d",&input);
//	return input;
//}
//void game()
//{
//	int inp = 0;
//	int num = rand() % 100 + 1;
//	printf("请输入一个数字\n");
//	while (1)
//	{
//		scanf("%d",&inp);
//		if (inp < num)
//		{
//			printf("猜小了\n");
//		}
//		else if (inp > num)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("猜对了\n");
//			return;
//		}
//	}
//}
//enum
//{
//	EXIT,
//	PLAY
//};
//int main()
//{
//	int choice = 0;
//	srand((unsigned)time(NULL));
//	do
//	{
//		choice = menu();
//		switch (choice)
//		{
//		case PLAY:
//			game();
//			break;
//		case EXIT:
//			printf("已退出！\n");
//			system("pause");
//			return 0;
//			break;
//		}
//	} while (choice);
//	system("pause");
//	return 0;
//}

//2.写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回-1.（折半查找）
//#include<stdio.h>
//#include<stdlib.h>
//int Find(int arr[],int n,int len)
//{
//	int left = 0;
//	int right = len - 1;
//	int mid = 0;
//	while (left <= right)
//	{
//		mid = (left + right) / 2;
//		if (n < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else if (n > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//int main()
//{
//	int num = 0;
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("请输入要查找的数字：\n");
//	scanf("%d",&num);
//	printf("%d\n", Find(arr, num, sz));
//	system("pause");
//	return 0;
//}

//3.编写代码模拟三次密码输入的场景。 
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，可以重新输入，
//多输入三次。三次均错，则提示退出程序。
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	char password[1024] = { 0 };
//	char mima[1024] = "123456";
//	int i = 3;
//	printf("请输入密码(只有三次机会)：\n");
//	while (i > 0)
//	{
//		scanf("%s",password);
//		if (0 == strcmp(password,mima))  //字符串比较大小用库函数strcmp
//		{
//			printf("登陆成功！\n");
//			break;
//		}
//		else if (password != mima && i > 1)
//		{
//			printf("密码错误！请重新输入！还有%d次机会\n",i-1);
//		}
//		else
//		{
//			printf("密码错误！次数用尽！程序退出！\n");
//		}
//		i--;
//	}
//	system("pause");
//	return 0;
//}

//4.编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。 
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char arr = 0;
//	while (1)
//	{
//		arr = getchar();
//		if (arr >= 'a' && arr <= 'z')
//		{
//			arr -= 32;
//		}
//		else if (arr >= 'A' && arr <= 'Z')
//		{
//			arr += 32;
//		}
//		else if (arr >= '0' && arr <= '9')
//		{
//			arr = ' ';
//		}
//		putchar(arr);
//	}
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int i = 0;
//	char arr[10240] = { 0 };
//	gets(arr);
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++)
//	{
//		if (arr[i] >= 'a' && arr[i] <= 'z')
//		{
//			arr[i] -= 32;
//		}
//		else if (arr[i] >= 'A' && arr[i] <= 'Z')
//		{
//			arr[i] += 32;
//		}
//		else if (arr[i] >= '0' && arr[i] <= '9')
//		{
//			arr[i] = ' ';
//		}
//	}
//	puts(arr);
//	system("pause");
//	return 0;
//}

//C day07
//1. 实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
//#include<stdio.h>
//#include<stdlib.h>
//void multi_table(int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= n; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d * %d = %2d ",i,j,i*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int num = 0;
//	printf("请输入你要打印乘法口诀表的行数：\n");
//	scanf("%d",&num);
//	multi_table(num);
//	system("pause");
//	return 0;
//}

//2. 使用函数实现两个数的交换。
//#include<stdio.h>
//#include<stdlib.h>
//void swap1(int *a, int *b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void swap2(int *a, int *b)
//{
//	*a = *a + *b;
//	*b = *a - *b;
//	*a = *a - *b;
//}
//void swap3(int *a, int *b)
//{
//	*a = *a ^ *b;
//	*b = *a ^ *b;
//	*a = *a ^ *b;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	printf("%d %d\n", a, b);
//	swap1(&a,&b);//创建第三个变量
//	printf("%d %d\n", a, b);
//	swap2(&a,&b);//使用加减法（容易溢出）
//	printf("%d %d\n", a, b);
//	swap3(&a,&b);//使用异或
//	printf("%d %d\n",a,b);
//	system("pause");
//	return 0;
//}

//3. 实现一个函数判断year是不是润年。
//#include<stdio.h>
//#include<stdlib.h>
//int is_leapyear(int year)
//{
//	if (((0 == year % 4) && (0 != year % 100)) || (0 == year % 400))
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int year = 0;
//	printf("请输入一个年份：\n");
//	scanf("%d",&year);
//	if (1 == is_leapyear(year))
//	{
//		printf("%d是闰年\n",year);
//	}
//	else
//	{
//		printf("%d不是闰年\n", year);
//	}
//	system("pause");
//	return 0;
//}

//4. 创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
//#include<stdio.h>
//#include<stdlib.h>
//int menu()
//{
//	int input = 0;
//	printf("1.初始化数组\n");
//	printf("2.清空数组\n");
//	printf("3.逆置数组\n");
//	printf("0.退出\n");
//	scanf("%d",&input);
//	return input;
//}
//void Init(int a[], int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		a[i] = i;
//	}
//}
//void Empty(int a[], int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		a[i] = 0;
//	}
//}
//void Reverse(int a[], int len)
//{
//	int left = 0;
//	int right = len - 1;
//	while (left < right)
//	{
//		a[left] = a[left] ^ a[right];
//		a[right] = a[left] ^ a[right];
//		a[left] = a[left] ^ a[right];
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	int arr[10] = {0};
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	while (1)
//	{
//		int choice = menu();
//		switch (choice)
//		{
//		case 1:
//			Init(arr,sz);
//			for (i = 0; i < sz; i++)
//			{
//				printf("%d ",arr[i]);
//			}
//			printf("\n");
//			break;
//		case 2:
//			Empty(arr, sz);
//			for (i = 0; i < sz; i++)
//			{
//				printf("%d ", arr[i]);
//			}
//			printf("\n");
//			break;
//		case 3:
//			Reverse(arr, sz);
//			for (i = 0; i < sz; i++)
//			{
//				printf("%d ", arr[i]);
//			}
//			printf("\n");
//			break;
//		case 0:
//			system("pause");
//			return 0;
//			break;
//		}
//	}
//	system("pause");
//	return 0;
//}

//5.实现一个函数，判断一个数是不是素数。
#include<stdio.h>
#include<stdlib.h>
int is_prime(int num)
{
	int i = 0;
	for (i = 2; i < num; i++)
	{
		if (0 == num % i)
			return 0;
	}
	if (i == num)
		return 1;
}
int main()
{
	int num = 0;
	printf("请输入一个正整数：\n");
	scanf("%d",&num);
	if (1 == is_prime(num))
	{
		printf("%d是素数\n",num);
	}
	else
	{
		printf("%d不是素数\n",num);
	}
	system("pause");
	return 0;
}