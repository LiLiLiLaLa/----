#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_back = NULL;
	pq->_front = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	QueueNode* del = NULL;
	while (cur){
		del = cur->_next;
		free(cur);
		cur = del;
	}
	//QueueNode* del = pq->_front;
	//QueueNode* cur = NULL;
	//while (del){
	//	cur = del->_next;
	//	free(del);
	//	del = cur;
	//}
}

QueueNode* BuyQueueNode(DataType x)
{
	QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newNode == NULL)
	{
		perror("BuyQueueNode::malloc");
		return NULL;
	}
	newNode->_data = x;
	newNode->_next = NULL;
	return newNode;
}

void QueuePush(Queue* pq, DataType x)
{
	QueueNode* newNode = NULL;
	assert(pq);
	newNode = BuyQueueNode(x);
	if (pq->_front == NULL)
	{
		pq->_front = newNode;
		pq->_back = newNode;
	}
	else
	{
		pq->_back->_next = newNode;
		pq->_back = pq->_back->_next;
	}
}

void QueuePop(Queue* pq)
{
	QueueNode* cur = NULL;
	assert(pq);
	if (pq->_front == NULL)
		return;
	cur = pq->_front->_next;
	free(pq->_front);
	pq->_front = cur;
}

DataType QueueFront(const Queue* pq)
{
	assert(pq);
	assert(pq->_front);
	return pq->_front->_data;
}

//¿Õ0
//·Ç¿Õ1
int QueueEmpty(const Queue* pq)
{
	return pq->_front == NULL ? 0 : 1;
}

int QueueSize(const Queue* pq)
{
	int count = 0;
	QueueNode* cur = pq->_front;
	assert(pq);
	while (cur)
	{
		count++;
		cur = cur->_next;
	}
	return count;
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 33);
	QueuePush(&q, 44);
	//QueuePop(&q);
	printf("FrontData is %d\n", QueueFront(&q));
	printf("CountData is %d\n", QueueSize(&q));
	QueueDestory(&q);
}