#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct CNode{
	int val;
	struct CNode *random;
	struct CNode *next;
}	CNode;

//1.��������
void CopyNodeAfterNewNode(CNode *head){
	CNode *cur = head;
	while (cur != NULL){
		//����newNode������ÿһ�����
		CNode *newNode = (CNode *)malloc(sizeof(CNode));
		newNode->val = cur->val;
		newNode->random = NULL;		//random���ÿ�
		//Ȼ��newNode����cur �� cur->next��
		newNode->next = cur->next;
		cur->next = newNode;
		//�ƶ�cur��λ�õ���һ���Ͻ��
		cur = cur->next->next;
	}
}
//2.����random���
void CopyRandomNode(CNode *head){
	CNode *cur = head;
	while (cur != NULL){
		//�½������Ͻ�����һ����㣬��newNode����ʾ�½��
		CNode *newNode = cur->next;
		//����random���֮ǰҪ�ж��Ƿ�ΪNULL
		if (cur->random != NULL){
			newNode->random = cur->random->next;
		}
		else{
			newNode->random = NULL;
		}
		//���curΪ��һ���Ͻ��
		cur = cur->next->next;
	}
}
//3.�������
CNode* SplitList(CNode *head){
	CNode *cur = head;
	CNode *newHead = head->next;
	while (cur != NULL){
		//����������½����Ͻ��ֿ�
		CNode *newNode = cur->next;
		cur->next = newNode->next;
		//�ж�cur->next�Ƿ�Ϊ�գ��ܷ������
		if (cur->next != NULL){
			newNode->next = cur->next->next;
		}
		else{
			newNode->next = NULL;
		}
		cur = cur->next;
	}
	return newHead;
}

CNode* Copy(CNode *head){
	if (head == NULL){
		return NULL;
	}
	CopyNodeAfterNewNode(head);
	CopyRandomNode(head);
	CNode * newHead = SplitList(head);
	return newHead;
}

CNode *createNode(int val){
	CNode *node = (CNode *)malloc(sizeof(CNode));
	node->val = val;
	node->random = NULL;
	node->next = NULL;
	return node;
}

int main()
{
	CNode *n1 = createNode(1);
	CNode *n2 = createNode(2);
	CNode *n3 = createNode(3);
	CNode *n4 = createNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	n1->random = n3;
	n2->random = n1;
	n3->random = n3;

	CNode *newHead = Copy(n1);
	
	printf("�ɹ�\n");
	system("pause");
	return 0;
}