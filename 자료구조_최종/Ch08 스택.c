//#include <stdio.h>
//#include <stdlib.h>
//
//#define TRUE	1
//#define FALSE	0
//
////데이터 구조체 노드 설정
//typedef struct node
//{
//	int data;
//	struct Node* next;
//}Node;
//
//// TopPointer 
//Node * Top;
//
//// 링크 초기화 함수
//void StackInit()
//{
//	Top = NULL;
//}
//
//// 링크 Null 확인 함수
//int SIsEmpty()
//{
//	if (Top == NULL)
//		return TRUE;
//	else
//		return FALSE;
//}
//
//// 마지막(Top) 데이터 확인 함수
//int SPeek()
//{
//	if (SIsEmpty(Top)) {
//		printf("Stack Memory Error!");
//		exit(-1);
//	}
//	return Top->data;
//}
//void PrintStack()
//{
//	Node* cur = Top;
//	while (cur != NULL)
//	{
//		printf("%d ", cur->data);
//		cur = cur->next;
//	}
//	printf("\n");
//
//}
//// PUSH 함수 
//void SPush(int data)
//{
//	// 1 노드생성
//	// 2 값넣기
//	// 3 링크 NULL
//	Node * new = (Node *)malloc(sizeof(Node));
//	if (new == NULL)
//	{
//		printf("OverFlow\n");
//		exit(1);
//	}
//	new->data = data;
//	new->next = NULL;
//	
//	// 4 노드가 하나도 없을때
//	// 5 노드가 하나이상 있을때
//	// 5-1 new의 next에 top 대입
//	// 5-2 top 에 new 대입
//	if (Top == NULL)
//	{
//		Top = new;
//	}
//	else
//	{
//		new->next = Top;
//		Top = new;
//	}
// 
//
//}
//
//// POP 함수 
//void SPop()
//{
//
//	// 1 노드 하나도 없을때
//	if (Top == NULL)
//	{
//		printf("UnderFlow!\n");
//		return;
//	}
//
//	// 2 노드 있을때
//	// 2-1 Top 위치를 del에 저장
//	// 2-2 Top 은 다음 위치로 이동
//	// 2-3 del 을 free() 로 제거
//
//	Node * del = Top;
//	Top = Top->next;
//	free(del);
//
//
//}
//
//
//
//int main(void)
//{
//	//--------------------------------------------------
//	// Stack의 생성 및 초기화 ///////
//	//--------------------------------------------------
//	StackInit();
//
//	//--------------------------------------------------
//	// 데이터 넣기 ///////
//	//--------------------------------------------------
//	printf("---------------(1) PUSH() ----------------\n");
//	SPush(1);  SPush(2);
//	SPush(3);  SPush(4);
//	SPush(5);
//	PrintStack();
//	//--------------------------------------------------
//	// 마지막 데이터 확인 ///////
//	//--------------------------------------------------
//	printf("---------------(2) PEEK() ----------------\n");
//	printf("마지막 데이터 : %d\n", SPeek());
//	//--------------------------------------------------
//	// 데이터 꺼내기 ///////
//	//--------------------------------------------------
//	printf("---------------(3) PEEK() ----------------\n");
//	printf("1회 POP()! :"); SPop();
//	PrintStack();
//	printf("2회 POP()! :"); SPop();
//	PrintStack();
//	printf("3회 POP()! :"); SPop();
//	PrintStack();
//	printf("4회 POP()! :"); SPop();
//	PrintStack();
//	printf("5회 POP()! :"); SPop();
//	PrintStack();
//	printf("6회 POP()! :"); SPop();
//	PrintStack();
//	return 0;
//}