#define _CRT_SECURE_NO_WARNINGS 1
//C day05
//1.������С��Ϸ
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
//	printf("������һ������\n");
//	while (1)
//	{
//		scanf("%d",&inp);
//		if (inp < num)
//		{
//			printf("��С��\n");
//		}
//		else if (inp > num)
//		{
//			printf("�´���\n");
//		}
//		else
//		{
//			printf("�¶���\n");
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
//			printf("���˳���\n");
//			system("pause");
//			return 0;
//			break;
//		}
//	} while (choice);
//	system("pause");
//	return 0;
//}

//2.д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ�������-1.���۰���ң�
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
//	printf("������Ҫ���ҵ����֣�\n");
//	scanf("%d",&num);
//	printf("%d\n", Find(arr, num, sz));
//	system("pause");
//	return 0;
//}

//3.��д����ģ��������������ĳ����� 
//����������������룬������ȷ����ʾ����¼�ɹ���, ������󣬿����������룬
//���������Ρ����ξ�������ʾ�˳�����
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int main()
//{
//	char password[1024] = { 0 };
//	char mima[1024] = "123456";
//	int i = 3;
//	printf("����������(ֻ�����λ���)��\n");
//	while (i > 0)
//	{
//		scanf("%s",password);
//		if (0 == strcmp(password,mima))  //�ַ����Ƚϴ�С�ÿ⺯��strcmp
//		{
//			printf("��½�ɹ���\n");
//			break;
//		}
//		else if (password != mima && i > 1)
//		{
//			printf("����������������룡����%d�λ���\n",i-1);
//		}
//		else
//		{
//			printf("������󣡴����þ��������˳���\n");
//		}
//		i--;
//	}
//	system("pause");
//	return 0;
//}

//4.��дһ�����򣬿���һֱ���ռ����ַ��������Сд�ַ��������Ӧ�Ĵ�д�ַ���
//������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ�����������ֲ������ 
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
//1. ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
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
//	printf("��������Ҫ��ӡ�˷��ھ����������\n");
//	scanf("%d",&num);
//	multi_table(num);
//	system("pause");
//	return 0;
//}

//2. ʹ�ú���ʵ���������Ľ�����
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
//	swap1(&a,&b);//��������������
//	printf("%d %d\n", a, b);
//	swap2(&a,&b);//ʹ�üӼ��������������
//	printf("%d %d\n", a, b);
//	swap3(&a,&b);//ʹ�����
//	printf("%d %d\n",a,b);
//	system("pause");
//	return 0;
//}

//3. ʵ��һ�������ж�year�ǲ������ꡣ
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
//	printf("������һ����ݣ�\n");
//	scanf("%d",&year);
//	if (1 == is_leapyear(year))
//	{
//		printf("%d������\n",year);
//	}
//	else
//	{
//		printf("%d��������\n", year);
//	}
//	system("pause");
//	return 0;
//}

//4. ����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��
//#include<stdio.h>
//#include<stdlib.h>
//int menu()
//{
//	int input = 0;
//	printf("1.��ʼ������\n");
//	printf("2.�������\n");
//	printf("3.��������\n");
//	printf("0.�˳�\n");
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

//5.ʵ��һ���������ж�һ�����ǲ���������
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
	printf("������һ����������\n");
	scanf("%d",&num);
	if (1 == is_prime(num))
	{
		printf("%d������\n",num);
	}
	else
	{
		printf("%d��������\n",num);
	}
	system("pause");
	return 0;
}