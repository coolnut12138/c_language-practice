#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct PersonInfo //����������Ϣ�ṹ��
{
	char name[1024];
	char sex[1024];
	char age[1024];
	char phone[1024];
	char address[1024];
}PersonInfo;

#define SIZE 1000  //�����ϵ������
typedef struct AddrBook  //ͨѶ¼
{
	PersonInfo person_info[1024];  //ͨѶ¼��������
	int size;//ʵ����ϵ������
}AddrBook;

AddrBook g_addr_book;//����һ��ͨѶ¼���͵�ȫ�ֱ���
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
		printf("ͨѶ¼���������ʧ�ܣ�\n");
		return;
	}
	printf("��������ϵ����Ϣ\n");
	printf("��������ϵ����:\n");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].name);
	printf("��������ϵ���Ա�:\n");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].sex);
	printf("��������ϵ������:\n");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].age);
	printf("��������ϵ�˵绰����:\n");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].phone);
	printf("��������ϵ�˵�ַ:\n");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].address);
	g_addr_book.size++;
	printf("��ӳɹ�\n");
	return;
}
void DelPersonInfo()
{
	int num = 0;
	int count = 0;
	printf("ɾ����ϵ����Ϣ\n");
	printf("������Ҫɾ���˵ı��\n");
	scanf("%d",&num);
	while (num < 0 || num >= g_addr_book.size)
	{
		printf("����ı�ų�����Χ������������\n");
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
	printf("ɾ���ɹ�,��ɾ����%d����Ϣ\n",count);
	return;
}
void FindPersonInfo()
{
	char name[1024] = {0};
	int count = 0;
	int i = 0;
	printf("������ϵ��:\n");
	printf("�������û���:\n");
	scanf("%s",name);
	for (i = 0; i < g_addr_book.size; i++)
	{
		if (0 == strcmp(name, g_addr_book.person_info[i].name))
		{
			printf("�ҵ�һ����¼���Ա�Ϊ��%s,����Ϊ��%s,�绰����Ϊ��%s,��ͥסַΪ��%s\n",
				g_addr_book.person_info[i].sex,g_addr_book.person_info[i].age,
				g_addr_book.person_info[i].phone,g_addr_book.person_info[i].address);
			count++;
		}
	}
	if (0 == count)
	{
		printf("δ�ҵ������Ϣ\n");
	}
	else
	{
		printf("���ҳɹ��������ҵ�%d����¼\n",count);
	}
}
void ModifyPersonInfo()
{
	int num = 0;
	printf("�޸���ϵ����Ϣ\n");
	printf("������Ҫ�޸��˵ı��:\n");
	scanf("%d",&num);
	while (num < 0 || num >= g_addr_book.size)
	{
		printf("�����ų�����Χ������������:\n");
		scanf("%d",&num);
	}
	printf("�������µ���ϵ������:\n");
	scanf("%s",g_addr_book.person_info[num].name);
	printf("�������µ���ϵ���Ա�:\n");
	scanf("%s", g_addr_book.person_info[num].sex);
	printf("�������µ���ϵ������:\n");
	scanf("%s", g_addr_book.person_info[num].age);
	printf("����������ϵ�˵ĵ绰����:\n");
	scanf("%s",g_addr_book.person_info[num].phone);
	printf("�������µ���ϵ�˼�ͥסַ:\n");
	scanf("%s", g_addr_book.person_info[num].address);
	printf("�޸ĳɹ�\n");
}
void DisplayPersonInfo()
{
	int i = 0;
	printf("��ӡ������ϵ����Ϣ\n");
	for (i = 0; i < g_addr_book.size; i++)
	{
		printf("��ţ�[%d] ������[%s] �Ա�%s ���䣺%s  �绰���룺%s ��ͥסַ��%s\n",
			i,g_addr_book.person_info[i].name,
			g_addr_book.person_info[i].sex, g_addr_book.person_info[i].age,
			g_addr_book.person_info[i].phone,g_addr_book.person_info[i].address);
	}
	printf("��ӡ���,����ӡ��%d����Ϣ\n",g_addr_book.size);
}
void ClearPersonInfo()
{
	char input[1024] = { 0 };
	printf("��������û���Ϣ��\n");
	printf("���Ƿ�ȷ��Ҫɾ��������Ϣ�� y��ȷ������������ȡ��\n");
	scanf("%s",input);
	if (0 != strcmp(input, "y")) //ע�⵱���벻��y����nʱ�����
	{
		printf("��ȡ��ɾ��������\n");
		return;
	}
	else
	{
		g_addr_book.size = 0;
		printf("�����ɣ�\n");
	}
}
void SortPersonInfo()
{
	int i = 0;
	int j = 0;
	printf("����ϵ�˽�������\n");
	for (i = 0; i < g_addr_book.size - 1; i++)//ð������
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
	printf("�������!\n");
	DisplayPersonInfo();
	return;
}

int menu()
{
	int input = 0;
	printf("&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf("1.�����ϵ����Ϣ\n");
	printf("2.ɾ��ָ����ϵ����Ϣ\n");
	printf("3.����ָ����ϵ����Ϣ\n");
	printf("4.�޸�ָ����ϵ����Ϣ\n");
	printf("5.��ʾ������ϵ����Ϣ\n");
	printf("6.���������ϵ��\n");
	printf("7.����������������ϵ��\n");
	printf("8.����\n");
	printf("0.�˳�\n");
	printf("&&&&&&&&&&&&&&&&&&&&&&&&\n");
	scanf("%d", &input);
	while (input < 0 || input > 8)
	{
		printf("������������������:\n");
		scanf("%d", &input);
	}
	return input;
}

enum
{
	EXIT,	   //�˳�
	ADD,	   //���
	DEL,	   //ɾ��
	FIND,	   //����
	MODIFY,    //�޸�
	DISPLAY,   //��ʾ
	CLEAR,     //���
	SORT,	   //����
	CLEAN,	   //����
};

int main()
{
	int choice = 0;
	Init();//��ʼ��ͨѶ¼����
	while (1)
	{
		choice = menu();
		switch (choice)
		{
		case EXIT:
			printf("���˳�\n");
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
