#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct CNode{
	int val;
	struct CNode *random;
	struct CNode *next;
}	CNode;

//1.复制链表
void CopyNodeAfterNewNode(CNode *head){
	CNode *cur = head;
	while (cur != NULL){
		//创建newNode来复制每一个结点
		CNode *newNode = (CNode *)malloc(sizeof(CNode));
		newNode->val = cur->val;
		newNode->random = NULL;		//random先置空
		//然后将newNode插入cur 和 cur->next中
		newNode->next = cur->next;
		cur->next = newNode;
		//移动cur的位置到下一个老结点
		cur = cur->next->next;
	}
}
//2.复制random结点
void CopyRandomNode(CNode *head){
	CNode *cur = head;
	while (cur != NULL){
		//新结点就是老结点的下一个结点，用newNode来表示新结点
		CNode *newNode = cur->next;
		//复制random结点之前要判断是否为NULL
		if (cur->random != NULL){
			newNode->random = cur->random->next;
		}
		else{
			newNode->random = NULL;
		}
		//变更cur为下一个老结点
		cur = cur->next->next;
	}
}
//3.拆分链表
CNode* SplitList(CNode *head){
	CNode *cur = head;
	CNode *newHead = head->next;
	while (cur != NULL){
		//拆分链表，将新结点和老结点分开
		CNode *newNode = cur->next;
		cur->next = newNode->next;
		//判断cur->next是否为空，能否解引用
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
	
	printf("成功\n");
	system("pause");
	return 0;
}