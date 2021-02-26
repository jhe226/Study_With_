//#include <stdio.h>
//#include <stdlib.h>
//
//
//typedef struct _node
//{
//	int data;
//	struct _node* next;
//}Node;
//
//typedef struct CList
//{
//	Node* tail;		// 꼬리 위치 포인터
//	int NodeCnt;	// 데이터 개수 확인
//}List;
//
////초기화함수
//void ListInit(List* plist)
//{
//	plist->tail = NULL;	// 꼬리포인터 초기화
//	plist->NodeCnt = 0;	// 데이터 개수 초기화
//}
//
////리스트 프린트 함수 
//void PrintList(List* plist)
//{
//	Node* head = plist->tail->next;
//	if (plist->NodeCnt != 0)
//	{
//		for (int i = 0; i < plist->NodeCnt; i++)
//		{
//			printf("%d ", head->data);
//			head = head->next;
//		}
//		printf("\n");
//	}
//}
////마지막에 삽입
//void LInsert(List* plist, int data)
//{
//	//1 노드생성
//	//2 데이터 값넣기
//	//3 링크부 초기화
//	Node * new = (Node *)malloc(sizeof(Node));
//	if (new == NULL)
//	{
//		printf("동적할당 실패!\n");
//		exit(1);
//	}
//	new->data = data;
//	new->next = NULL;
//
//	if (plist->tail == NULL)//4-1 노드가 하나도 없을때
//	{
//		plist->tail = new;
//		plist->tail->next = new;
//		
//	}
//	else //4-2 노드가 하나이상 있을때
//	{
//		new->next=plist->tail->next;
//		plist->tail->next = new;
//		plist->tail = new;
//	}
//	plist->NodeCnt++;
//}
//
////처음에 삽입
//void LInsertFront(List* plist, int data)
//{
//	//1 노드생성(NULL체크) + 데이터값넣기 + 링크NULL초기화
//	Node * new = (Node *)malloc(sizeof(Node));
//	if (new == NULL)
//	{
//		printf("동적할당 실패!\n");
//		exit(1);
//	}
//	new->data = data;
//	new->next = NULL;
//
//	if (plist->tail == NULL)//2-1 노드가 X
//	{
//		plist->tail = new;
//		plist->tail->next = new;
//	}
//	else//2-2 노드가 O
//	{
//		new->next = plist->tail->next;
//		plist->tail->next = new;	
//	}
//	plist->NodeCnt++;
//}
//
//
////조회 함수
//Node* SearchNode(List* plist, int target)
//{
//	//1 존재 노드가 X -> return NULL;
//	//2 존재 노드가 O -> 3 작업 수행
//	//3-1 Nodecnt개수만큼 반복 , 일치 데이터 있을시 노드 주소 Return 
//	//3-1 Nodecnt개수만큼 반복 , 일치 데이터 없을시 NULL Return
//
//	//1 존재 노드가 X -> return NULL;
//	if (plist->tail == NULL)
//		return NULL;
//
//	//2 존재 노드가 O -> 3 작업 수행
//	Node * cur = plist->tail->next;	//첫노드위치를 검색 시작점으로 지정
//	for (int i = 0; i < plist->NodeCnt; i++)
//	{
//		if (cur->data == target)
//		{
//			return cur;
//		}
//		cur = cur->next;
//	}
//	return NULL;
//}
//
////삭제 함수
//void LRemove(List* plist, int target)
//{
//	// 1 조회
//	// 2 삭제노드의 전노드 검색
//	// 3-1 삭제노드가 끝노드인경우
//	// 3-2 삭제노드가 끝노드가 아닌경우
//
//	Node* del = SearchNode(plist, target);
//	if (del == NULL)
//	{
//		printf("삭제노드 X\n");
//		return ;
//	}
//
//
//	Node * pre = plist->tail->next;	//전노드찾기 위한 포인터 
//	//전노드위치 찾기
//	//노드 개수만큼 반복하면서 pre의 next값이 del과일치하면 break	
//	for (int i = 0; i < plist->NodeCnt; i++)
//	{
//		if (pre->next == del)
//			break;
//		pre = pre->next;
//	}
//
//	pre->next = del->next; //삭제노드의 다음위치를 전노드의 next에 연결 
//	plist->NodeCnt--;		// 노드개수 1 감소 
//
//	if (plist->tail == del) //삭제노드가 끝노드인경우 
//	{
//		plist->tail = pre; //tail의 위치를 삭제 전노드로 설정 
//	}
//
//	free(del); //삭제노드 동적할당 해제 
//
//}
//
//int main(void)
//{
//	//-----------------------------------
//	// 원형 연결 리스트의 생성 및 초기화 
//	//-----------------------------------
//	List list;
//	int data, i, nodeNum;
//	ListInit(&list);
//	int num;
//
//	//-----------------------------------
//	// 끝노드에 연결 /////// 
//	//-----------------------------------
//	printf("\n--------(1) 끝 노드에 연결 ---------\n");
//	LInsert(&list, 3);
//	LInsert(&list, 4);
//	LInsert(&list, 5);
//	PrintList(&list);
//	
//	//-----------------------------------
//	// 첫노드에 연결 /////// 
//	//-----------------------------------
//	printf("\n--------(2) 첫 노드에 연결 ---------\n");
//	LInsertFront(&list, 2);
//	LInsertFront(&list, 1);
//	PrintList(&list);
//
//	//-----------------------------------
//	//저장된 데이터 조회///////
//	//-----------------------------------
//	printf("\n--------(3) 데이터 조회 ---------\n");
//	printf("값 입력[조회] : ");
//	scanf_s("%d", &num);
//	Node* cur = SearchNode(&list, num);
//	if (cur == NULL)
//		printf("입력한 값과 일치하는 데이터는 없습니다\n");
//	else
//		printf("입력한 값 %d 가 존재합니다\n", cur->data);
//
//	//-----------------------------------
//	//삭제
//	//-----------------------------------
//	printf("\n--------(4) 데이터 삭제 ---------\n");
//	printf("값 입력[삭제] :");
//	scanf_s("%d", &num);
//	LRemove(&list, num);
//	PrintList(&list);
//
//	return 0;
//}