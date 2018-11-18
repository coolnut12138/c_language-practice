#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct PersonInfo //创建个人信息结构体
{
	char name[1024];
	char sex[1024];
	char age[1024];
	char phone[1024];
	char address[1024];
}PersonInfo;

#define SIZE 1000  //最大联系人数量
typedef struct AddrBook  //通讯录
{
	PersonInfo person_info[1024];  //通讯录人数数组
	int size;//实际联系人数量
}AddrBook;

AddrBook g_addr_book;//创建一个通讯录类型的全局变量
void Init()
{
	int i = 0;
	g_addr_book.size = 0;
	for(i = 0; i < SIZE; i++)
	{
		strcpy(g_addr_book.person_info[i].name,"");
		strcpy(g_addr_book.person_info[i].sex,"");
		strcpy(g_addr_book.person_info[i].age,"");
		strcpy(g_addr_book.person_info[i].phone,"");
		strcpy(g_addr_book.person_info[i].address,"");
	}
}

void AddPersonInfo()
{
	if(g_addr_book.size >= SIZE)
	{
		printf("通讯录已满，添加失败！\n");
		return;
	}
	printf("请输入联系人信息\n");
	printf("请输入联系人名:\n");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].name);
	printf("请输入联系人性别:\n");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].sex);
	printf("请输入联系人年龄:\n");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].age);
	printf("请输入联系人电话号码:\n");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].phone);
	printf("请输入联系人地址:\n");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].address);
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
			g_addr_book.person_info[g_addr_book.size - 1].sex);
		strcpy(g_addr_book.person_info[num].sex,
			g_addr_book.person_info[g_addr_book.size - 1].age);
		strcpy(g_addr_book.person_info[num].age,
			g_addr_book.person_info[g_addr_book.size - 1].phone);
		strcpy(g_addr_book.person_info[num].address,
			g_addr_book.person_info[g_addr_book.size - 1].address);
	}
	g_addr_book.size--;
	count++;
	printf("删除成功,共删除了%d条信息\n",count);
	return;
}
void FindPersonInfo()
{
	char name[1024] = {0};
	int count = 0;
	int i = 0;
	printf("查找联系人:\n");
	printf("请输入用户名:\n");
	scanf("%s",name);
	for (i = 0; i < g_addr_book.size; i++)
	{
		if (0 == strcmp(name, g_addr_book.person_info[i].name))
		{
			printf("找到一条记录，性别为：%s,年龄为：%s,电话号码为：%s,家庭住址为：%s\n",
				g_addr_book.person_info[i].sex,g_addr_book.person_info[i].age,
				g_addr_book.person_info[i].phone,g_addr_book.person_info[i].address);
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
	int num = 0;
	printf("修改联系人信息\n");
	printf("请输入要修改人的编号:\n");
	scanf("%d",&num);
	while (num < 0 || num >= g_addr_book.size)
	{
		printf("输入编号超出范围，请重新输入:\n");
		scanf("%d",&num);
	}
	printf("请输入新的联系人姓名:\n");
	scanf("%s",g_addr_book.person_info[num].name);
	printf("请输入新的联系人性别:\n");
	scanf("%s", g_addr_book.person_info[num].sex);
	printf("请输入新的联系人年龄:\n");
	scanf("%s", g_addr_book.person_info[num].age);
	printf("请输入新联系人的电话号码:\n");
	scanf("%s",g_addr_book.person_info[num].phone);
	printf("请输入新的联系人家庭住址:\n");
	scanf("%s", g_addr_book.person_info[num].address);
	printf("修改成功\n");
}
void DisplayPersonInfo()
{
	int i = 0;
	printf("打印所有联系人信息\n");
	for (i = 0; i < g_addr_book.size; i++)
	{
		printf("编号：[%d] 姓名：[%s] 性别：%s 年龄：%s  电话号码：%s 家庭住址：%s\n",
			i,g_addr_book.person_info[i].name,
			g_addr_book.person_info[i].sex, g_addr_book.person_info[i].age,
			g_addr_book.person_info[i].phone,g_addr_book.person_info[i].address);
	}
	printf("打印完成,共打印了%d条信息\n",g_addr_book.size);
}
void ClearPersonInfo()
{
	char input[1024] = { 0 };
	printf("清除所有用户信息！\n");
	printf("你是否确定要删除所有信息？ y：确定，按其他键取消\n");
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
	int i = 0;
	int j = 0;
	printf("将联系人进行排序\n");
	for (i = 0; i < g_addr_book.size - 1; i++)//冒泡排序
	{
		for (j = 0; j < g_addr_book.size - i - 1; j++)
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
	while (1)
	{
		choice = menu();
		switch (choice)
		{
		case EXIT:
			printf("已退出\n");
			return 0;
			break;
		case ADD:
			AddPersonInfo();
			break;
		case DEL:
			DelPersonInfo();
			break;
		case FIND:
			FindPersonInfo();
			break;
		case MODIFY:
			ModifyPersonInfo();
			break;
		case DISPLAY:
			DisplayPersonInfo();
			break;
		case CLEAR:
			ClearPersonInfo();
			break;
		case SORT:
			SortPersonInfo();
			break;
		case CLEAN:
			system("cls");
			break;
		}
	}
	return 0;
}
