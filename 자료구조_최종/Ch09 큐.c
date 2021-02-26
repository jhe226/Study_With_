//#include <stdio.h>
//
//typedef struct _node
//{
//	int data;
//	struct _node* next;
//}Node;
//
//typedef struct _lQueue
//{
//	Node* front;
//	Node* rear;
//} Queue;
//
//void Init(Queue* pq)
//{
//	pq->front = NULL;
//	pq->rear = NULL;
//}
//
//int Empty(Queue* pq)
//{
//	if (pq->front == NULL)
//		return 1;
//	else
//		return 0;
//}
//int QPeek(Queue* pq)
//{
//	if (Empty(pq))
//	{
//		printf("Queue Memory Error!");
//		exit(-1);
//	}
//
//	return pq->front->data;
//}
//void PrintQ(Queue* pq)
//{
//	Node* cur = pq->front;
//
//	while (cur != NULL)
//	{
//		printf("%d ", cur->data);
//		cur = cur->next;
//	}
//	printf("\n");
//
//
//}
//
//void Enq(Queue* pq, int data)
//{
//	//1 �����
//	//2 ������ ��
//	//3 ��ũ �ʱ�ȭ
//
//	Node * new = (Node *)malloc(sizeof(Node));
//	if (new == NULL)
//		exit(1);
//	new->data = data;
//	new->next = NULL;
//
//	if (pq->front == NULL)
//	{
//		pq->front = new;
//		pq->rear = new;
//	}
//	else 
//	{
//		pq->rear->next = new;
//		pq->rear = new;
//	}
//	//5 ��� �ϳ��� ������
//	//6 ��� �ϳ��̻� ������
//	//6-1 rear�� next�� new ����
//	//6-2 rear�� ��ġ�� new �� ���� 
//
//}
//
//void Deq(Queue* pq)
//{
//	//1 ��尡 ���°��
//	//2 ��尡 �ִ°��
//	//2-1 front �� ��� �ּҸ� del�� ��´�
//	//2-2 front �� next��ġ�� �̵���Ų��
//	//2-3 del�� free()�Ѵ�
//	if (pq->front == NULL)
//		return;
//
//	Node * del = pq->front;
//	pq->front = pq->front->next;
//	free(del);
//
//}
//int main(void)
//{
//	//-----------------------------------------
//	// Queue�� ���� �� �ʱ�ȭ ///////
//	//-----------------------------------------
//	Queue q;
//	Init(&q);
//
//	//-----------------------------------------
//	// ������ �ֱ� ///////
//	//-----------------------------------------
//	Enq(&q, 1);  Enq(&q, 2);
//	Enq(&q, 3);  Enq(&q, 4);
//	Enq(&q, 5);
//	PrintQ(&q);
//
//	//-----------------------------------------
//	// ������ ������ ///////
//	//-----------------------------------------
//	printf("Deq() 1ȸ : "); Deq(&q); PrintQ(&q);
//	printf("Deq() 2ȸ : "); Deq(&q); PrintQ(&q);
//	printf("Deq() 3ȸ : "); Deq(&q); PrintQ(&q);
//	printf("Deq() 4ȸ : "); Deq(&q); PrintQ(&q);
//	printf("Deq() 5ȸ : "); Deq(&q); PrintQ(&q);
//	return 0;
//}