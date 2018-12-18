#define _CRT_SECURE_NO_WARNINGS 1

//有效的括号
//定义数据类型
typedef char SDataType;

//静态顺序表实现栈
//顺序表大小
#define MaxSize 1000000

typedef struct {
	SDataType array[MaxSize];
	int top; //就是表示数组的大小
}	Stack;

//初始化
void StackInit(Stack *stack)
{
	stack->top = 0;
}

//销毁
void StackDestroy(Stack *stack)
{
	stack->top = 0;
}

void StackPush(Stack *stack, SDataType val)
{
	assert(stack != NULL);
	//判断栈内数据是否满了
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
					 //右括号多于左括号
					 if (StackEmpty(&stack)){
						 return false;
					 }
					 char left = StackTop(&stack);
					 StackPop(&stack);
					 //左右括号不匹配
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
		//左括号多于右括号
		return false;
	}
	return true;
}

//用队列实现栈
typedef int QDataType;

//定义链表队列结点
typedef struct QNode{
	QDataType val;
	struct QNode *next;
}	QNode;

//队列
typedef struct Queue{
	int size; //队列元素个数
	QNode *front;//指向队列第一个元素，如果队列为空，则等于NULL
	QNode *rear;//指向队列最后一个元素，如果队列为空，则等于NULL
}	Queue;
//初始化
void QueueInit(Queue *queue)
{
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

//销毁
void QueueDestroy(Queue *queue)
{
	//队内如果有元素，就先释放
	QNode *next;
	for (QNode *cur = queue->front; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

//插入
void QueuePush(Queue *queue, QDataType val)
{
	//先创建结点
	QNode *node = (QNode *)malloc(sizeof(QNode));
	assert(node != NULL);
	node->val = val;
	node->next = NULL;
	queue->size++;
	//再判断队列是否为空
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

//删除
void QueuePop(Queue *queue)
{
	assert(queue->rear != NULL);//确保队列不为空
	queue->size--;
	QNode *old_front = queue->front;
	queue->front = queue->front->next;
	free(old_front);
	//如果删完队列空了的话，就要设置rear的指向NULL
	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}
}

//返回队首结点的值
QDataType QueueFront(const Queue *queue)
{
	assert(queue->size > 0);

	return queue->front->val;
}

//判断队列是否为空，为空返回1，不空返回0
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
	//返回的是空间，所以要malloc出空间
	MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
	assert(stack);
	stack->max_size = maxSize;
	QueueInit(&(stack->queue));
	return stack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	//obj->queue.size是有效数据个数
	//obj->max_size是最大数据个数
	assert(obj->queue.size < obj->max_size);
	QueuePush(&(obj->queue), x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	assert(obj->queue.size > 0);
	//把size保存起来，不然size在一直变
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
	//把size保存起来，不然size在一直变
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

//用栈实现队列C
//定义数据类型
typedef int SDataType;

//静态顺序表实现栈
//顺序表大小
#define MaxSize 100

typedef struct {
	SDataType array[MaxSize];
	int top; //就是表示数组的大小
}	Stack;
//初始化
void StackInit(Stack *stack)
{
	stack->top = 0;
}

//销毁
void StackDestroy(Stack *stack)
{
	stack->top = 0;
}

void StackPush(Stack *stack, SDataType val)
{
	assert(stack != NULL);
	//判断栈内数据是否满了
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
	//返回的是空间，所以要malloc出空间
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
	//判断栈B是否为空，为空就挪数据
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

//用栈实现队列C++
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

//最小栈
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
			//如果b栈顶的值大于x，就要把x压入栈b
			if (stack_b.top() >= x){
				stack_b.push(x);
			}
		}
	}

	void pop() {
		//判断栈a和栈b栈顶元素是否相等，
		//相等ab都出栈
		//不相等只出a（a中保存的是所有数据，b 中保存的是所有min值）
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

//设计循环队列
//利用 size 和 capacity 来判断满/空的情况
typedef struct {
	int *array;
	int capacity;
	int size;
	int front; //队首元素所在的下标
	int rear; //下一个可用空间的下标
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
	//注意不能直接写rear + capacity - 1，要模上最大容量
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