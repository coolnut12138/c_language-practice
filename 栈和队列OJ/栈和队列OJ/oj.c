#define _CRT_SECURE_NO_WARNINGS 1

//��Ч������
//������������
typedef char SDataType;

//��̬˳���ʵ��ջ
//˳����С
#define MaxSize 1000000

typedef struct {
	SDataType array[MaxSize];
	int top; //���Ǳ�ʾ����Ĵ�С
}	Stack;

//��ʼ��
void StackInit(Stack *stack)
{
	stack->top = 0;
}

//����
void StackDestroy(Stack *stack)
{
	stack->top = 0;
}

void StackPush(Stack *stack, SDataType val)
{
	assert(stack != NULL);
	//�ж�ջ�������Ƿ�����
	assert(stack->top < MaxSize);
	stack->array[stack->top] = val;
	stack->top++;
}

void StackPop(Stack *stack)
{
	assert(stack != NULL);
	assert(stack->top > 0);

	stack->top--;
}

SDataType StackTop(Stack *stack)
{
	assert(stack != NULL);
	assert(stack->top > 0);

	return stack->array[stack->top - 1];
}

int StackEmpty(const Stack *stack)
{
	return stack->top == 0 ? 1 : 0;
}

int StackSize(const Stack *stack)
{
	return stack->top;
}
bool isValid(char* s) {
	char *p = s;
	Stack stack;
	StackInit(&stack);
	while (*p != '\0'){
		switch (*p) {
		case '{':
		case '[':
		case '(':
			StackPush(&stack, *p);
			break;
		case '}':
		case ']':
		case ')':{
					 //�����Ŷ���������
					 if (StackEmpty(&stack)){
						 return false;
					 }
					 char left = StackTop(&stack);
					 StackPop(&stack);
					 //�������Ų�ƥ��
					 if (!((left == '(' && *p == ')')
						 || (left == '[' && *p == ']')
						 || (left == '{' && *p == '}'))){
						 return false;
					 }
		}
			break;
		}
		p++;
	}
	if (!StackEmpty(&stack)){
		//�����Ŷ���������
		return false;
	}
	return true;
}

//�ö���ʵ��ջ
typedef int QDataType;

//����������н��
typedef struct QNode{
	QDataType val;
	struct QNode *next;
}	QNode;

//����
typedef struct Queue{
	int size; //����Ԫ�ظ���
	QNode *front;//ָ����е�һ��Ԫ�أ��������Ϊ�գ������NULL
	QNode *rear;//ָ��������һ��Ԫ�أ��������Ϊ�գ������NULL
}	Queue;
//��ʼ��
void QueueInit(Queue *queue)
{
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

//����
void QueueDestroy(Queue *queue)
{
	//���������Ԫ�أ������ͷ�
	QNode *next;
	for (QNode *cur = queue->front; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

//����
void QueuePush(Queue *queue, QDataType val)
{
	//�ȴ������
	QNode *node = (QNode *)malloc(sizeof(QNode));
	assert(node != NULL);
	node->val = val;
	node->next = NULL;
	queue->size++;
	//���ж϶����Ƿ�Ϊ��
	if (queue->rear == NULL)
	{
		queue->front = queue->rear = node;
	}
	else
	{
		queue->rear->next = node;
		queue->rear = node;
	}
}

//ɾ��
void QueuePop(Queue *queue)
{
	assert(queue->rear != NULL);//ȷ�����в�Ϊ��
	queue->size--;
	QNode *old_front = queue->front;
	queue->front = queue->front->next;
	free(old_front);
	//���ɾ����п��˵Ļ�����Ҫ����rear��ָ��NULL
	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}
}

//���ض��׽���ֵ
QDataType QueueFront(const Queue *queue)
{
	assert(queue->size > 0);

	return queue->front->val;
}

//�ж϶����Ƿ�Ϊ�գ�Ϊ�շ���1�����շ���0
int QueueEmpty(const Queue *queue)
{
	return queue->size == 0 ? 1 : 0;
}
typedef struct {
	int max_size;
	Queue queue;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
	//���ص��ǿռ䣬����Ҫmalloc���ռ�
	MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
	assert(stack);
	stack->max_size = maxSize;
	QueueInit(&(stack->queue));
	return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	//obj->queue.size����Ч���ݸ���
	//obj->max_size��������ݸ���
	assert(obj->queue.size < obj->max_size);
	QueuePush(&(obj->queue), x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	assert(obj->queue.size > 0);
	//��size������������Ȼsize��һֱ��
	int size = obj->queue.size;
	for (int i = 0; i < size - 1; i++){
		int x = QueueFront(&(obj->queue));
		QueuePop(&(obj->queue));
		QueuePush(&(obj->queue), x);
	}

	int x = QueueFront(&(obj->queue));
	QueuePop(&(obj->queue));
	return x;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	assert(obj->queue.size > 0);
	//��size������������Ȼsize��һֱ��
	int size = obj->queue.size;
	for (int i = 0; i < size - 1; i++){
		int x = QueueFront(&(obj->queue));
		QueuePop(&(obj->queue));
		QueuePush(&(obj->queue), x);
	}

	int x = QueueFront(&(obj->queue));
	QueuePop(&(obj->queue));
	QueuePush(&(obj->queue), x);

	return x;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&(obj->queue));
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&(obj->queue));
}

/**
* Your MyStack struct will be instantiated and called as such:
* struct MyStack* obj = myStackCreate(maxSize);
* myStackPush(obj, x);
* int param_2 = myStackPop(obj);
* int param_3 = myStackTop(obj);
* bool param_4 = myStackEmpty(obj);
* myStackFree(obj);
*/

//��ջʵ�ֶ���C
//������������
typedef int SDataType;

//��̬˳���ʵ��ջ
//˳����С
#define MaxSize 100

typedef struct {
	SDataType array[MaxSize];
	int top; //���Ǳ�ʾ����Ĵ�С
}	Stack;
//��ʼ��
void StackInit(Stack *stack)
{
	stack->top = 0;
}

//����
void StackDestroy(Stack *stack)
{
	stack->top = 0;
}

void StackPush(Stack *stack, SDataType val)
{
	assert(stack != NULL);
	//�ж�ջ�������Ƿ�����
	assert(stack->top < MaxSize);
	stack->array[stack->top] = val;
	stack->top++;
}

void StackPop(Stack *stack)
{
	assert(stack != NULL);
	assert(stack->top > 0);

	stack->top--;
}

SDataType StackTop(Stack *stack)
{
	assert(stack != NULL);
	assert(stack->top > 0);

	return stack->array[stack->top - 1];
}

int StackEmpty(const Stack *stack)
{
	return stack->top == 0 ? 1 : 0;
}

int StackSize(const Stack *stack)
{
	return stack->top;
}

typedef struct {
	Stack stackA;
	Stack stackB;
	int max_size;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
	//���ص��ǿռ䣬����Ҫmalloc���ռ�
	MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
	assert(queue);
	queue->max_size = maxSize;
	StackInit(&(queue->stackA));
	StackInit(&(queue->stackB));
	return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	assert(obj->stackA.top < obj->max_size);
	StackPush(&(obj->stackA), x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	//�ж�ջB�Ƿ�Ϊ�գ�Ϊ�վ�Ų����
	if (StackEmpty(&(obj->stackB))){
		int size = StackSize(&(obj->stackA));
		for (int i = 0; i < size; i++){
			int x = StackTop(&(obj->stackA));
			StackPop(&(obj->stackA));
			StackPush(&(obj->stackB), x);
		}
	}

	int x = StackTop(&(obj->stackB));
	StackPop(&(obj->stackB));
	return x;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&(obj->stackB))){
		int size = StackSize(&(obj->stackA));
		for (int i = 0; i < size; i++){
			int x = StackTop(&(obj->stackA));
			StackPop(&(obj->stackA));
			StackPush(&(obj->stackB), x);
		}
	}

	int x = StackTop(&(obj->stackB));
	return x;
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&(obj->stackA)) && StackEmpty(&(obj->stackB));
}

void myQueueFree(MyQueue* obj) {
	free(obj);
}

/**
* Your MyQueue struct will be instantiated and called as such:
* struct MyQueue* obj = myQueueCreate(maxSize);
* myQueuePush(obj, x);
* int param_2 = myQueuePop(obj);
* int param_3 = myQueuePeek(obj);
* bool param_4 = myQueueEmpty(obj);
* myQueueFree(obj);
*/

//��ջʵ�ֶ���C++
class MyQueue {
private:
	stack<int> stack_a;
	stack<int> stack_b;

public:
	/** Initialize your data structure here. */
	MyQueue() {
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		stack_a.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (stack_b.empty()){
			int size = stack_a.size();
			for (int i = 0; i < size; i++){
				int x = stack_a.top();
				stack_a.pop();
				stack_b.push(x);
			}
		}
		int x = stack_b.top();
		stack_b.pop();
		return x;
	}

	/** Get the front element. */
	int peek() {
		if (stack_b.empty()){
			int size = stack_a.size();
			for (int i = 0; i < size; i++){
				int x = stack_a.top();
				stack_a.pop();
				stack_b.push(x);
			}
		}
		int x = stack_b.top();
		return x;
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return stack_a.empty() && stack_b.empty();
	}
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue obj = new MyQueue();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.peek();
* bool param_4 = obj.empty();
*/

//��Сջ
class MinStack {
public:
	stack<int> stack_a;
	stack<int> stack_b;
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		stack_a.push(x);
		if (stack_b.empty()){
			stack_b.push(x);
		}
		else{
			//���bջ����ֵ����x����Ҫ��xѹ��ջb
			if (stack_b.top() >= x){
				stack_b.push(x);
			}
		}
	}

	void pop() {
		//�ж�ջa��ջbջ��Ԫ���Ƿ���ȣ�
		//���ab����ջ
		//�����ֻ��a��a�б�������������ݣ�b �б����������minֵ��
		int m = stack_a.top();
		if (m == stack_b.top()){
			stack_a.pop();
			stack_b.pop();
		}
		else{
			stack_a.pop();
		}
	}

	int top() {
		return stack_a.top();
	}

	int getMin() {
		return stack_b.top();
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/

//���ѭ������
//���� size �� capacity ���ж���/�յ����
typedef struct {
	int *array;
	int capacity;
	int size;
	int front; //����Ԫ�����ڵ��±�
	int rear; //��һ�����ÿռ���±�
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue *obj = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
	assert(obj);
	obj->array = (int *)malloc(sizeof(int)* k);
	obj->capacity = k;
	obj->size = 0;
	obj->front = 0;
	obj->rear = 0;
	return obj;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (obj->size == obj->capacity){
		return false;
	}

	obj->array[obj->rear] = value;
	obj->size++;
	obj->rear = (obj->rear + 1) % obj->capacity;
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (obj->size == 0){
		return false;
	}

	obj->size--;
	obj->front = (obj->front + 1) % obj->capacity;
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->size == 0){
		return -1;
	}

	return obj->array[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->size == 0){
		return -1;
	}
	//ע�ⲻ��ֱ��дrear + capacity - 1��Ҫģ���������
	return obj->array[(obj->rear + obj->capacity - 1) % obj->capacity];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->size == 0;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return obj->size == obj->capacity;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->array);
	free(obj);
}

/**
* Your MyCircularQueue struct will be instantiated and called as such:
* struct MyCircularQueue* obj = myCircularQueueCreate(k);
* bool param_1 = myCircularQueueEnQueue(obj, value);
* bool param_2 = myCircularQueueDeQueue(obj);
* int param_3 = myCircularQueueFront(obj);
* int param_4 = myCircularQueueRear(obj);
* bool param_5 = myCircularQueueIsEmpty(obj);
* bool param_6 = myCircularQueueIsFull(obj);
* myCircularQueueFree(obj);
*/