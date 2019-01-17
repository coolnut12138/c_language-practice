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
	Node *root;		// 创建好的树的根结点
	int	used;		// 创建树过程中用掉的 val 个数
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

	// 创建根结点
	Node *root = (Node *)malloc(sizeof(Node));
	root->val = rootValue;

	// 创建左子树
	Result left_result = CreateTree(preorder + 1, size - 1);
	/*
	left_result.root;	// 创建好的左子树的根结点
	left_result.used;	// 创建左子树过程中用掉的 val 的个数
	*/
	// 创建右子树
	Result right_result = CreateTree(preorder + 1 + left_result.used, size - 1 - left_result.used);
	root->left = left_result.root;
	root->right = right_result.root;

	Result result = { root, 1 + left_result.used + right_result.used
	};
	return result;
}

//层序遍历（队列实现）
void LevelOrderTraversal(Node *root){
	if (root == NULL){
		return;
	}
	
	//来个队列，队列中存的数据类型是Node *
	//命名空间
	std::queue<Node *> q;
	q.push(root);

	while (!q.empty()) {
		Node *node = q.front();//取队首结点
		q.pop();				//弹出队首结点
		printf("%c ", node->val);

		if (node->left != NULL) {
			q.push(node->left);
		}

		if (node->right != NULL) {
			q.push(node->right);
		}
	}
}

// 前序遍历非递归
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

		//走到这一定是向左遇到空
		//利用栈处理剩余的右子树
		top = s.top(); s.pop();
		cur = top->right;
	}
}

// 中序遍历非递归
void InorderTraversalNoR(Node *root){
	std::stack<Node *>	s;
	Node *cur = root;
	Node *top = NULL;

	while (cur != NULL || !s.empty()){
		while (cur != NULL){
			s.push(cur);
			cur = cur->left;
		}

		//走到这一定是向左遇到空
		//利用栈处理剩余的右子树
		top = s.top(); s.pop();
		printf("%c ", top->val);
		cur = top->right;
	}
}

// 后序遍历非递归
void PostorderTraversalNoR(Node *root) {
	std::stack<Node *>	s;	// 栈
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

	printf("层序遍历： ");
	LevelOrderTraversal(result.root);
	printf("\n");

	printf("前序遍历: ");
	PreorderTraversalNoR(result.root);
	printf("\n");

	printf("中序遍历: ");
	InorderTraversalNoR(result.root);
	printf("\n");

	printf("后序遍历: ");
	PostorderTraversalNoR(result.root);
	printf("\n");
 
	system("pause");
	return 0;
}