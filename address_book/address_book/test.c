#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct PersonInfo //����������Ϣ�ṹ��
{
	char name[1024];
	char phone[1024];
}PersonInfo;

//#define SIZE 1000  //�����ϵ������
typedef struct AddrBook  //ͨѶ¼
{
	PersonInfo *person_info;  //ͨѶ¼��������
	int size;//ʵ����ϵ������
	int capacity; //��̬�������ֵ,�����ϵ������
}AddrBook;

AddrBook g_addr_book;//����һ��ͨѶ¼���͵�ȫ�ֱ���
void Init()
{
	int i = 0;
	g_addr_book.size = 0;
	//capacity��ֵ
	g_addr_book.capacity = 2;
	//���䶯̬�ڴ�(�˴�malloc����Ҫfree����Ϊ�˴���PersonInfo��ȫ�ֱ�����������������������)
	g_addr_book.person_info = 
		(PersonInfo *)malloc(sizeof(PersonInfo) * g_addr_book.capacity);
}

//����
void CheckRealloc()
{
	if (g_addr_book.size < g_addr_book.capacity)
	{
		//����Ҫ����
		return;
	}
	g_addr_book.capacity *= 2;
	PersonInfo *temp = (PersonInfo *)malloc(sizeof(PersonInfo) * g_addr_book.capacity);
	for (int i = 0; i < g_addr_book.size; i++)
	{
		temp[i] = g_addr_book.person_info[i];//��֮ǰ��person_info�����ݷ���temp��
	}
	free(g_addr_book.person_info);//�ͷŶ�̬�ڴ����֮ǰperson_info�е�����
	g_addr_book.person_info = temp;//�ٰ�temp�е����ݷ����·����ڴ��person_info��
}

void AddPersonInfo()
{
	//�ж��Ƿ�����
	CheckRealloc();
	printf("��������ϵ����Ϣ\n");
	printf("�������û���:\n");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].name);
	printf("�������û��绰����:\n");
	scanf("%s", g_addr_book.person_info[g_addr_book.size].phone);
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
			g_addr_book.person_info[g_addr_book.size - 1].phone);
	}
	g_addr_book.size--;
	count++;
	printf("ɾ���ɹ�,��ɾ����%d����Ϣ\n",count);
	return;
}
void FindPersonInfo()
{
	printf("������ϵ��:\n");
	printf("�������û���:\n");
	char name[1024] = {0};
	int count = 0;
	scanf("%s",name);
	for (int i = 0; i < g_addr_book.size; i++)
	{
		if (0 == strcmp(name, g_addr_book.person_info[i].name))
		{
			printf("�ҵ�һ����¼���绰����Ϊ��%s\n",
				g_addr_book.person_info[i].phone);
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
	printf("�޸���ϵ����Ϣ\n");
	printf("������Ҫ�޸��˵ı��:\n");
	int num = 0;
	scanf("%d",&num);
	while (num < 0 || num >= g_addr_book.size)
	{
		printf("�����ų�����Χ������������:\n");
		scanf("%d",&num);
	}
	printf("�������µ��û���:\n");
	scanf("%s",g_addr_book.person_info[num].name);
	printf("���������û��ĵ绰����:\n");
	scanf("%s",g_addr_book.person_info[num].phone);
	printf("�޸ĳɹ�\n");
}
void DisplayPersonInfo()
{
	printf("��ӡ������ϵ����Ϣ\n");
	for (int i = 0; i < g_addr_book.size; i++)
	{
		printf("[%d][%s] %s\n",i,g_addr_book.person_info[i].name,
			g_addr_book.person_info[i].phone);
	}
	printf("��ӡ���,����ӡ��%d����Ϣ\n",g_addr_book.size);
}
void ClearPersonInfo()
{
	printf("��������û���Ϣ��\n");
	printf("���Ƿ�ȷ��Ҫɾ��������Ϣ�� y/n\n");
	char input[1024] = { 0 };
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
	printf("����ϵ�˽�������\n");
	for (int i = 0; i < g_addr_book.size - 1; i++)//ð������
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
	printf("�������!\n");
	DisplayPersonInfo();
	return;
}
//�����˳�ǰ����
void SavePersonInfo()
{
	printf("��ʼ���棡\n");
	FILE *fp = fopen("../test.txt","w");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�����ʧ�ܣ�\n");
		return;
	}
	for (int i = 0; i < g_addr_book.size; i++)
	{
		fwrite(&g_addr_book.person_info[i],sizeof(PersonInfo),1,fp);
	}
	fclose(fp);
	printf("����ɹ���������%d����Ϣ\n",g_addr_book.size);
}
//����ʼǰ����
void LoadPersonInfo()
{
	printf("��ʼ���أ�\n");
	FILE *fp = fopen("../test.txt","r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ�����ʧ�ܣ�\n");
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
	printf("���سɹ���������%d����Ϣ\n",g_addr_book.size);
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
	LoadPersonInfo();//��ʼ�����Ҫ����
	while (1)
	{
		choice = menu();
		switch (choice)
		{
		case EXIT:
			SavePersonInfo();
			printf("���˳�\n");
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
