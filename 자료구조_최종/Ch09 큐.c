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
//	//1 새노드
//	//2 데이터 값
//	//3 링크 초기화
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
//	//5 노드 하나도 없을때
//	//6 노드 하나이상 있을때
//	//6-1 rear의 next에 new 대입
//	//6-2 rear의 위치를 new 로 지정 
//
//}
//
//void Deq(Queue* pq)
//{
//	//1 노드가 없는경우
//	//2 노드가 있는경우
//	//2-1 front 의 노드 주소를 del에 담는다
//	//2-2 front 를 next위치로 이동시킨다
//	//2-3 del를 free()한다
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
//	// Queue의 생성 및 초기화 ///////
//	//-----------------------------------------
//	Queue q;
//	Init(&q);
//
//	//-----------------------------------------
//	// 데이터 넣기 ///////
//	//-----------------------------------------
//	Enq(&q, 1);  Enq(&q, 2);
//	Enq(&q, 3);  Enq(&q, 4);
//	Enq(&q, 5);
//	PrintQ(&q);
//
//	//-----------------------------------------
//	// 데이터 꺼내기 ///////
//	//-----------------------------------------
//	printf("Deq() 1회 : "); Deq(&q); PrintQ(&q);
//	printf("Deq() 2회 : "); Deq(&q); PrintQ(&q);
//	printf("Deq() 3회 : "); Deq(&q); PrintQ(&q);
//	printf("Deq() 4회 : "); Deq(&q); PrintQ(&q);
//	printf("Deq() 5회 : "); Deq(&q); PrintQ(&q);
//	return 0;
//}