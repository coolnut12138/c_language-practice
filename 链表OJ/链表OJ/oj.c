#define _CRT_SECURE_NO_WARNINGS 1

//�Ƴ�����Ԫ��
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL){
		return NULL;
	}
	struct ListNode *prev = head;
	struct ListNode *cur = head->next;
	while (cur != NULL)
	{
		if (cur->val != val)
		{
			prev = cur;
		}
		else
		{
			prev->next = cur->next;
			free(cur);
		}
		cur = prev->next;
	}
	struct ListNode *newHead = head;
	if (head->val == val)
	{
		head = head->next;
		free(newHead);
	}
	return head;
}

//��ת����
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* reverseList(struct ListNode* head) {
	//struct ListNode *newHead = NULL;
	//struct ListNode *node;
	//while(head != NULL)
	//{
	//ͷɾ
	//  node = head;
	// head = head->next;
	//ͷ��
	//  node->next = newHead;
	//  newHead = node;
	//}
	//return newHead;

	if (head == NULL){
		return NULL;
	}
	struct ListNode* p0 = NULL;
	struct ListNode* p1 = head;
	struct ListNode* p2 = head->next;

	while (p1 != NULL){
		p1->next = p0;
		p0 = p1;
		p1 = p2;
		if (p2 != NULL){
			p2 = p2->next;
		}
	}
	return p0;
}

//������м���
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
int GetLength(struct ListNode* head){
	int len = 0;
	struct ListNode *cur = head;
	while (cur != NULL){
		len++;
		cur = cur->next;
	}
	return len;
}
struct ListNode* middleNode(struct ListNode* head) {
	int steps = GetLength(head) / 2;
	struct ListNode* mid = head;
	while (steps--){
		mid = mid->next;
	}
	return mid;
}

//�����е�����k�����
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode *p = pListHead;
		while (p != NULL && k--){
			p = p->next;
		}
		if (p == NULL && k > 0){
			return NULL;
		}
		while (p != NULL){
			pListHead = pListHead->next;
			p = p->next;
		}
		return pListHead;
	}
};

//�ϲ�������������
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *cur1 = l1;
	struct ListNode *cur2 = l2;
	struct ListNode *p = NULL; //��������������
	struct ListNode *ptail = NULL;  //������ָ�����

	if (l1 == NULL){
		return l2;
	}

	if (l2 == NULL){
		return l1;
	}

	while (cur1 != NULL && cur2 != NULL){
		if (cur1->val <= cur2->val){
			//β��cur1��p��
			if (ptail == NULL){
				p = ptail = cur1;
			}
			else{
				ptail->next = cur1;
				ptail = cur1;
			}
			cur1 = cur1->next;
		}
		else{
			if (ptail == NULL){
				p = ptail = cur2;
			}
			else{
				ptail->next = cur2;
				ptail = cur2;
			}
			cur2 = cur2->next;
		}
	}
	if (cur1 == NULL){
		ptail->next = cur2;
	}
	else{
		ptail->next = cur1;
	}
	return p;


}

//����ָ�
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		//�������Ϊ�����֣�С��x���ʹ��ڵ���x��
		ListNode* lt = NULL;
		ListNode* ltTail = NULL;
		ListNode* eg = NULL;
		ListNode* egTail = NULL;

		ListNode* cur = pHead;
		while (cur != NULL){
			if (cur->val < x){
				if (lt == NULL){
					lt = ltTail = cur;
				}
				else{
					//β��
					ltTail->next = cur;
					ltTail = ltTail->next;
				}
			}
			else{
				if (eg == NULL){
					eg = egTail = cur;
				}
				else{
					egTail->next = cur;
					egTail = egTail->next;
				}
			}
			cur = cur->next;
		}

		if (ltTail != NULL){
			ltTail->next = NULL;
		}
		if (egTail != NULL){
			egTail->next = NULL;
		}
		if (lt && eg){
			ltTail->next = eg;
			return lt;
		}
		else if (!lt && !eg){
			return NULL;
		}
		else if (lt == NULL && eg){
			return eg;
		}
		else{
			return lt;
		}
	}
};

//ɾ���������ظ��Ľ��
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL){
			return NULL;
		}
		ListNode* p0 = NULL;
		ListNode* p1 = pHead;
		ListNode* p2 = p1->next;
		while (p2 != NULL){
			if (p2->val != p1->val){
				p0 = p1;
				p1 = p2;
				p2 = p2->next;
			}
			else{
				while (p2 != NULL && p2->val == p1->val){
					p2 = p2->next;
				}
				if (p2 == NULL){
					if (p0 != NULL){
						p0->next = p2;
					}
					else{
						return NULL;
					}
					break;
				}
				if (p0 != NULL){
					p0->next = p2;
				}
				else{
					pHead = p2;
				}
				p1 = p2;
				p2 = p2->next;
			}
		}
		return pHead;
	}
};

//����Ļ��Ľṹ
/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
	ListNode* reverseList(ListNode* head){
		ListNode *newHead = NULL;
		ListNode *node;

		while (head != NULL){
			//��֮ǰ��������ͷɾ
			node = head;
			head = head->next;
			//����������ͷ��
			node->next = newHead;
			newHead = node;
		}
		return newHead;
	}
	int GetLength(struct ListNode *head){
		int len = 0;
		ListNode *cur = head;
		while (cur != NULL){
			len++;
			cur = cur->next;
		}
		return len;
	}
	ListNode* middleNode(ListNode* head){
		int steps = GetLength(head) / 2;
		ListNode *middle = head;
		while (steps--){
			middle = middle->next;
		}
		return middle;
	}
	bool chkPalindrome(ListNode* A) {
		ListNode *middle = middleNode(A);
		ListNode *reversed = reverseList(A);

		ListNode *c1 = A;
		ListNode *c2 = reversed;
		while (c1 != NULL && c2 != NULL){
			if (c1->val != c2->val){
				return false;
			}
			c1 = c1->next;
			c2 = c2->next;
		}
		return true;
	}
};

//�ཻ����
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
typedef struct ListNode ListNode;

int GetLength(ListNode *head){
	int len = 0;
	ListNode *cur = head;
	while (cur != NULL){
		cur = cur->next;
		len++;
	}
	return len;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int len1 = GetLength(headA);
	int len2 = GetLength(headB);
	ListNode *longer, *shorter;
	int diff;
	if (len1 >= len2){
		longer = headA;
		shorter = headB;
		diff = len1 - len2;
	}
	else{
		longer = headB;
		shorter = headA;
		diff = len2 - len1;
	}

	//���ó�����diff��
	for (int i = 0; i < diff; i++){
		longer = longer->next;
	}
	while (longer != shorter){
		//�Ƚϵ��ǽ���ַ
		longer = longer->next;
		shorter = shorter->next;
	}

	return longer;
}

//��������
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
bool hasCycle(struct ListNode *head) {
	struct ListNode *fast = head;
	struct ListNode *slow = head;
	//�����������������һ��
	//�����������������һ�����У���Զ��������
	do
	{
		if (fast == NULL){
			break;
		}
		fast = fast->next;
		if (fast == NULL){
			break;
		}
		fast = fast->next;
		slow = slow->next;
	} while (fast != slow);

	if (fast == NULL){
		return false;
	}
	else{
		return true;
	}
}

//��������II
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *hasCycle(struct ListNode *head) {
	struct ListNode *fast = head;
	struct ListNode *slow = head;
	do
	{
		if (fast == NULL){
			break;
		}
		fast = fast->next;
		if (fast == NULL){
			break;
		}
		fast = fast->next;
		slow = slow->next;
	} while (fast != slow);

	return fast;
}

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode *meet = hasCycle(head);
	if (meet == NULL){
		return NULL;
	}

	struct ListNode *p1 = head;
	struct ListNode *p2 = meet;
	while (p1 != p2){
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}

//���ƴ����ָ�������
/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     struct RandomListNode *next;
*     struct RandomListNode *random;
* };
*/
struct RandomListNode * CreateNode(int label)
{
	struct RandomListNode *p = (struct RandomListNode *)
		malloc(sizeof(struct RandomListNode));
	p->label = label;
	p->next = p->random = NULL;
	return p;
}

struct RandomListNode *copyRandomList(struct RandomListNode *head)
{
	if (head == NULL){
		return NULL;
	}
	// 1. ����ԭ�������µĽ������ϵĽ����
	struct RandomListNode *oldNode = head;
	while (oldNode != NULL) {
		struct RandomListNode *newNode = CreateNode(oldNode->label);
		newNode->next = oldNode->next;
		oldNode->next = newNode;

		oldNode = oldNode->next->next;
	}

	// ���� random ָ��
	oldNode = head;
	while (oldNode != NULL) {
		struct RandomListNode *newNode = oldNode->next;
		if (oldNode->random != NULL) {
			newNode->random = oldNode->random->next;
		}

		oldNode = oldNode->next->next;
	}

	// ��һ����������������
	oldNode = head;
	struct RandomListNode *newHead = head->next;
	while (oldNode != NULL) {
		struct RandomListNode *newNode = oldNode->next;
		oldNode->next = newNode->next;
		if (oldNode->next != NULL) {
			newNode->next = oldNode->next->next;
		}
		else {
			newNode->next = NULL;	// ����ԭ������ NULL
		}

		oldNode = oldNode->next;
	}

	return newHead;
}