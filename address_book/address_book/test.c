#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct PersonInfo //创建个人信息结构体
{
	char name[1024];
	char phone[1024];
}PersonInfo;

//#define SIZE 1000  //最大联系人数量
typedef struct AddrBook  //通讯录
{
	PersonInfo *person_info;  //通讯录人数数组
	int size;//实际联系人数量
	int capacity; //动态数组最大值,最大联系人数量
}AddrBook;

AddrBook g_addr_book;//创建一个通讯录类型的全局变量
void Init()
{
	int i = 0;
	g_addr_book.size = 0;
	//capacity的值
	g_addr_book.capacity = 2;
	//分配动态内存(此处malloc不需要free，因为此处的PersonInfo是全局变量，生命周期是整个程序)
	g_addr_book.person_info = 
		(PersonInfo *)malloc(sizeof(PersonInfo) * g_addr_book.capacity);
}

//扩容
void CheckRealloc()
{
	if (g_addr_book.size < g_addr_book.capacity)
	{
		//不需要扩容
		return;
	}
	g_addr_book.capacity *= 2;
	PersonInfo *temp = (PersonInfo *)malloc(sizeof(PersonInfo) * g_addr_book.capacity);
	for (int i = 0; i < g_addr_book.size; i++)
	{
		temp[i] = g_addr_book.person_info[i];//把之前的person_info的内容放在temp中
	}
	free(g_addr_book.person_info);//释放动态内存分配之前person_info中的内容
	g_addr_book.person_info = temp;//再把temp中的内容放在新分配内存的person_info中
}

void AddPersonInfo()
{
	//判断是否扩容
	CheckRealloc();
	printf("请输入联系人信息\n");
	printf("请输入用户名:\n");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].name);
	printf("请输入用户电话号码:\n");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].phone);
	g_addr_book.size++;
	printf("添加成功\n");
	return;
}
void DelPersonInfo()
{
	int num = 0;
	int count = 0;
	printf("删除联系人信息\n");
	printf("请输入要删除人的编号\n");
	scanf("%d",&num);
	while (num < 0 || num >= g_addr_book.size)
	{
		printf("输入的编号超出范围，请重新输入\n");
		scanf("%d", &num);
	}
	if (num != g_addr_book.size - 1)
	{
		strcpy(g_addr_book.person_info[num].name,
			g_addr_book.person_info[g_addr_book.size - 1].name);
		strcpy(g_addr_book.person_info[num].phone,
			g_addr_book.person_info[g_addr_book.size - 1].phone);
	}
	g_addr_book.size--;
	count++;
	printf("删除成功,共删除了%d条信息\n",count);
	return;
}
void FindPersonInfo()
{
	printf("查找联系人:\n");
	printf("请输入用户名:\n");
	char name[1024] = {0};
	int count = 0;
	scanf("%s",name);
	for (int i = 0; i < g_addr_book.size; i++)
	{
		if (0 == strcmp(name, g_addr_book.person_info[i].name))
		{
			printf("找到一条记录，电话号码为：%s\n",
				g_addr_book.person_info[i].phone);
			count++;
		}
	}
	if (0 == count)
	{
		printf("未找到相关信息\n");
	}
	else
	{
		printf("查找成功，共查找到%d条记录\n",count);
	}
}
void ModifyPersonInfo()
{
	printf("修改联系人信息\n");
	printf("请输入要修改人的编号:\n");
	int num = 0;
	scanf("%d",&num);
	while (num < 0 || num >= g_addr_book.size)
	{
		printf("输入编号超出范围，请重新输入:\n");
		scanf("%d",&num);
	}
	printf("请输入新的用户名:\n");
	scanf("%s",g_addr_book.person_info[num].name);
	printf("请输入新用户的电话号码:\n");
	scanf("%s",g_addr_book.person_info[num].phone);
	printf("修改成功\n");
}
void DisplayPersonInfo()
{
	printf("打印所有联系人信息\n");
	for (int i = 0; i < g_addr_book.size; i++)
	{
		printf("[%d][%s] %s\n",i,g_addr_book.person_info[i].name,
			g_addr_book.person_info[i].phone);
	}
	printf("打印完成,共打印了%d条信息\n",g_addr_book.size);
}
void ClearPersonInfo()
{
	printf("清除所有用户信息！\n");
	printf("你是否确定要删除所有信息？ y/n\n");
	char input[1024] = { 0 };
	scanf("%s",input);
	if (0 != strcmp(input, "y")) //注意当输入不是y或者n时的情况
	{
		printf("已取消删除操作！\n");
		return;
	}
	else
	{
		g_addr_book.size = 0;
		printf("清除完成！\n");
	}
}
void SortPersonInfo()
{
	printf("将联系人进行排序\n");
	for (int i = 0; i < g_addr_book.size - 1; i++)//冒泡排序
	{
		for (int j = 0; j < g_addr_book.size - i - 1; j++)
		{
			if (strcmp(g_addr_book.person_info[j].name,
				g_addr_book.person_info[j + 1].name) > 0)
			{
				PersonInfo temp = g_addr_book.person_info[j];
				g_addr_book.person_info[j] =
					g_addr_book.person_info[j + 1];
				g_addr_book.person_info[j + 1] = temp;
			}
		}
	}
	printf("排序完成!\n");
	DisplayPersonInfo();
	return;
}
//程序退出前保存
void SavePersonInfo()
{
	printf("开始保存！\n");
	FILE *fp = fopen("../test.txt","w");
	if (fp == NULL)
	{
		printf("文件打开失败！保存失败！\n");
		return;
	}
	for (int i = 0; i < g_addr_book.size; i++)
	{
		fwrite(&g_addr_book.person_info[i],sizeof(PersonInfo),1,fp);
	}
	fclose(fp);
	printf("保存成功！保存了%d条信息\n",g_addr_book.size);
}
//程序开始前加载
void LoadPersonInfo()
{
	printf("开始加载！\n");
	FILE *fp = fopen("../test.txt","r");
	if (fp == NULL)
	{
		printf("文件打开失败！加载失败！\n");
		return;
	}
	PersonInfo temp = { 0 };
	while (fread(&temp, sizeof(temp), 1, fp))
	{
		CheckRealloc();
		g_addr_book.person_info[g_addr_book.size] = temp;
		g_addr_book.size++;
	}
	fclose(fp);
	printf("加载成功！加载了%d条信息\n",g_addr_book.size);
}
int menu()
{
	int input = 0;
	printf("&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf("1.添加联系人信息\n");
	printf("2.删除指定联系人信息\n");
	printf("3.查找指定联系人信息\n");
	printf("4.修改指定联系人信息\n");
	printf("5.显示所有联系人信息\n");
	printf("6.清空所有联系人\n");
	printf("7.以名字排序所有联系人\n");
	printf("8.清屏\n");
	printf("0.退出\n");
	printf("&&&&&&&&&&&&&&&&&&&&&&&&\n");
	scanf("%d", &input);
	while (input < 0 || input > 8)
	{
		printf("输入有误，请重新输入:\n");
		scanf("%d", &input);
	}
	return input;
}

enum
{
	EXIT,	   //退出
	ADD,	   //添加
	DEL,	   //删除
	FIND,	   //查找
	MODIFY,    //修改
	DISPLAY,   //显示
	CLEAR,     //清空
	SORT,	   //排序
	CLEAN,	   //清屏
};

int main()
{
	int choice = 0;
	Init();//初始化通讯录变量
	LoadPersonInfo();//初始化完就要加载
	while (1)
	{
		choice = menu();
		switch (choice)
		{
		case EXIT:
			SavePersonInfo();
			printf("已退出\n");
			system("pause");
			return 0;
			break;
		case ADD:
			AddPersonInfo();
			SavePersonInfo();
			break;
		case DEL:
			DelPersonInfo();
			SavePersonInfo();
			break;
		case FIND:
			FindPersonInfo();
			break;
		case MODIFY:
			ModifyPersonInfo();
			SavePersonInfo();
			break;
		case DISPLAY:
			DisplayPersonInfo();
			break;
		case CLEAR:
			ClearPersonInfo();
			SavePersonInfo();
			break;
		case SORT:
			SortPersonInfo();
			SavePersonInfo();
			break;
		case CLEAN:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}
