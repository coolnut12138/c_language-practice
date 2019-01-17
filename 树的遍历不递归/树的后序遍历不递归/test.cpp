#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
typedef struct Node {
	char val;
	struct Node *left;
	struct Node *right;
}	Node;


typedef struct {
	Node *root;		// �����õ����ĸ����
	int	used;		// �������������õ��� val ����
}	Result;

Result CreateTree(char preorder[], int size) {
	if (size == 0) {
		Result result = { NULL, 0 };

		return result;
	}

	char rootValue = preorder[0];
	if (rootValue == '#') {
		Result result = { NULL, 1 };

		return result;
	}

	// ���������
	Node *root = (Node *)malloc(sizeof(Node));
	root->val = rootValue;

	// ����������
	Result left_result = CreateTree(preorder + 1, size - 1);
	/*
	left_result.root;	// �����õ��������ĸ����
	left_result.used;	// �����������������õ��� val �ĸ���
	*/
	// ����������
	Result right_result = CreateTree(preorder + 1 + left_result.used, size - 1 - left_result.used);
	root->left = left_result.root;
	root->right = right_result.root;

	Result result = { root, 1 + left_result.used + right_result.used
	};
	return result;
}

//�������������ʵ�֣�
void LevelOrderTraversal(Node *root){
	if (root == NULL){
		return;
	}
	
	//�������У������д������������Node *
	//�����ռ�
	std::queue<Node *> q;
	q.push(root);

	while (!q.empty()) {
		Node *node = q.front();//ȡ���׽��
		q.pop();				//�������׽��
		printf("%c ", node->val);

		if (node->left != NULL) {
			q.push(node->left);
		}

		if (node->right != NULL) {
			q.push(node->right);
		}
	}
}

// ǰ������ǵݹ�
void PreorderTraversalNoR(Node *root){
	std::stack<Node *>	s;
	Node *cur = root;
	Node *top = NULL;

	while (cur != NULL || !s.empty()){
		while (cur != NULL){
			printf("%c ", cur->val);
			s.push(cur);
			cur = cur->left;
		}

		//�ߵ���һ��������������
		//����ջ����ʣ���������
		top = s.top(); s.pop();
		cur = top->right;
	}
}

// ��������ǵݹ�
void InorderTraversalNoR(Node *root){
	std::stack<Node *>	s;
	Node *cur = root;
	Node *top = NULL;

	while (cur != NULL || !s.empty()){
		while (cur != NULL){
			s.push(cur);
			cur = cur->left;
		}

		//�ߵ���һ��������������
		//����ջ����ʣ���������
		top = s.top(); s.pop();
		printf("%c ", top->val);
		cur = top->right;
	}
}

// ��������ǵݹ�
void PostorderTraversalNoR(Node *root) {
	std::stack<Node *>	s;	// ջ
	std::stack<Node *>	b;
	Node *cur = root;
	Node *top = NULL;
	Node *top2 = NULL;
	char arr[1024];
	int i = 0;

	while (cur != NULL || !s.empty()) {
		while (cur != NULL) {
			s.push(cur);
			b.push(cur);
			top2 = b.top(); b.pop();
			arr[i] = top2->val;
			cur = cur->right;
			i++;
			arr[i] = '\0';
		}
		top = s.top();	s.pop();
		cur = top->left;	
	}
	for (int j = strlen(arr) - 1; j >= 0; j--){
		printf("%c ", arr[j]);
	}
}

int main() {
	char preorder[1000] = "abc##de#g##f###";
	int size = strlen(preorder);

	Result result = CreateTree(preorder, size);

	printf("��������� ");
	LevelOrderTraversal(result.root);
	printf("\n");

	printf("ǰ�����: ");
	PreorderTraversalNoR(result.root);
	printf("\n");

	printf("�������: ");
	InorderTraversalNoR(result.root);
	printf("\n");

	printf("�������: ");
	PostorderTraversalNoR(result.root);
	printf("\n");
 
	system("pause");
	return 0;
}