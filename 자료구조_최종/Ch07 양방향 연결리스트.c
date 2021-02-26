#include <stdio.h>
#include <stdlib.h>

//구조체 노드

typedef struct _node
{
	int data;
	struct _node* next;		// 다음 노드를 가리키는 구조체 포인터
	struct _node* prev;     // 이전 노드를 가리키는 구조체 포인터	
} Node;

//포인터 노드

typedef struct _dbLinkedList
{
	Node* head;				// 처음 노드를 가리키는 구조체 포인터
	Node* tail;				// 마지막 노드를 가리키는 구조체 포인터
	int numOfData;			// 현재 데이터의 개수 카운트 변수
} DBLinkedList;
typedef DBLinkedList List;

//초기화 함수
void ListInit(List* plist)
{
	plist->head = NULL;
	plist->tail = NULL;
	plist->numOfData = 0;
}

//리스트 출력 함수 
void PrintList(List* plist)
{
	Node* cur = plist->head;
	printf("저장된 리스트 : ");
	for (int i = 0; i < plist->numOfData; i++)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


//처음에 삽입 함수
void LInsertFirst(List* plist, int data)
{
	// 1 새노드 생성
	// 2 데이터 값
	// 3 링크 NULL
	Node * new = (Node *)malloc(sizeof(Node));
	if (new == NULL)
		exit(1);
	new->data = data;
	new->prev = NULL; new->next = NULL;

	// 4 노드 하나도 없을때
	// 5 노드 하나이상 있을 때
	if (plist->numOfData == 0)
	{
		plist->head = new;
		plist->tail = new;	
	}
	else
	{
		new->next = plist->head;
		plist->head->prev = new;
		plist->head = new;
	}
	plist->numOfData++;


}
//마지막에 삽입 함수
void LInsertLast(List* plist, int data)
{

	// 1 새노드 생성
	// 2 데이터 값
	// 3 링크 NULL
	Node * new = (Node *)malloc(sizeof(Node));
	if (new == NULL)
		exit(1);
	new->data = data;
	new->prev = NULL; new->next = NULL;

	// 4 노드 하나도 없을때
	// 5 노드 하나이상 있을 때	

	if (plist->numOfData == 0)
	{
		plist->head = new;
		plist->tail = new;	
	}
	else
	{
		plist->tail->next = new;	//마지막노드next에 new노드 연결
		new->prev = plist->tail;	//new노드 prev에 전노드 연결
		plist->tail = new;
	}
	plist->numOfData++;
}


// 처음부터 조회 함수 

int FindFirst(List* plist, int data)
{


	// 0 plist->head를 이용해서 차례로 순차탐색 
	// 1 노드 없을때 return NULL
	// 2 노드 있을때 
	// 2-1 NumofData 개수만큼 반복하여 일치된 데이터 찾으면 return 노드 주소
	// 2-1 NumofData 개수만큼 반복하여 일치된 데이터 못찾으면 return NULL
	

	//1 노드가 없을때
	if (plist->numOfData == 0)
		return NULL;

	//2 노드가 있을때
	Node * cur = plist->head; //처음위치 노드 
	for (int i = 0; i < plist->numOfData; i++)
	{
		if (cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// 끝에서부터 조회 함수 

int FindLast(List* plist, int data)
{

	// 0 plist->tail를 이용해서 차례로 순차탐색(역방향)
	// 1 노드 없을때 return NULL
	// 2 노드 있을때 
	// 2-1 NumofData 개수만큼 반복하여 일치된 데이터 찾으면 return 노드 주소
	// 2-1 NumofData 개수만큼 반복하여 일치된 데이터 못찾으면 return NULL

	if (plist->numOfData == 0)
		return NULL;

	Node * cur = plist->tail;
	for (int i = 0; i < plist->numOfData; i++)
	{
		if (cur->data == data)
			return cur;
		cur = cur->prev;
	}
	return NULL;

}
// 중간 노드 삽입 함수 

void LInsertMiddle(List* plist, Node* pre, int data)
{
	// 1 노드생성
	// 2 데이터부 값
	// 3 링크부 NULL 초기화 
	Node * new = (Node *)malloc(sizeof(Node));
	if (new == NULL)
		exit(1);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;

	// 4 pre 가 마지막 노드인경우
	// 5 pre 가 마지막 노드가 아닌경우 
	if (pre != plist->tail)
	{
		new->prev = pre;
		new->next = pre->next;
		pre->next->prev = new;
		pre->next = new;
	}
	else
	{
		pre->next = new;
		new->prev = pre;
		plist->tail = new;
		
	}
	plist->numOfData++;

}
//삭제함수
void LRemove(List* plist, int data)
{
	//1 조회(FindFirst(plist,data))
	//1-1 없으면  return 
	//1-2 조회데이터 있다면 2 로 이동
	//2 삭제 위치 확인
	//2-1 맨앞
	//2-2 중간
	//2-3 마지막
	//3 데이터 노드 1 감소

	if (plist->numOfData == 0)
	{
		printf("연결노드없음\n");
		return;
	}
	Node * del = FindFirst(plist, data);
	if (del == NULL)
	{
		printf("삭제노드 탐색실패\n");
		return;
	}

	//노드가 존재 O , 삭제노드 O
	if (plist->head == del)	//처음
	{
		plist->head = del->next;
		plist->head->prev = NULL;
	}
	else if (plist->tail == del) //마지막
	{
		plist->tail = del->prev;
		plist->tail->next = NULL;

	}
	else //중간 
	{
		del->prev->next = del->next;
		del->next->prev = del->prev;
	}
	plist->numOfData--;
	free(del);

}

int main(void)
{

	//----------------------------------------------
	// 양방향 연결 리스트의 생성 및 초기화  ///////
	//----------------------------------------------
	List list;
	int data;
	ListInit(&list);
	//----------------------------------------------
	// 1 처음위치에 연결 
	//----------------------------------------------
	printf("\n--------------- 처음 위치에 연결 ---------------\n");
	LInsertFirst(&list, 4);  LInsertFirst(&list, 3);
	LInsertFirst(&list, 2);  LInsertFirst(&list, 1);
	PrintList(&list);

	//----------------------------------------------
	// 2 마지막 위치에 연결 
	//----------------------------------------------
	printf("\n--------------- 마지막 위치에 연결 ---------------\n");
	LInsertLast(&list, 5);  LInsertLast(&list, 6);
	LInsertLast(&list, 7);  LInsertLast(&list, 8);
	PrintList(&list);

	//----------------------------------------------
// 3-1 노드 데이터 조회(정방향) 
//----------------------------------------------
	printf("---------------데이터 조회 (정방향)---------------\n");
	int num;
	printf("찾을 값 입력(정방향조회) : ");
	scanf_s("%d", &num);
	Node* search = FindFirst(&list, num);
	if (search)
	{
		printf("%d를 찾았습니다\n", search->data);
	}
	else
	{
		printf("데이터가 없습니다\n");
	}
	//----------------------------------------------
	// 3-2 노드 데이터 조회(역방향) 
	//----------------------------------------------
	printf("---------------데이터 조회 (역방향)---------------\n");
	printf("찾을 값 입력(역방향조회) : ");
	scanf_s("%d", &num);
	search = FindLast(&list, num);
	if (search)
	{
		printf("%d를 찾았습니다\n", search->data);
	}
	else
	{
		printf("데이터가 없습니다\n");
	}

	//----------------------------------------------
	//4 중간노드 삽입
	//----------------------------------------------
	printf("---------------중간 노드 삽입---------------\n");
	printf("찾을 노드 값:");
	scanf_s("%d", &num);
	search = FindFirst(&list, num);
	if (search == NULL)
	{
		printf("해당 값이 노드에 존재하지 않습니다\n");
	}
	else
	{
		printf("삽입할 값 입력 :");
		scanf_s("%d", &num);
		LInsertMiddle(&list, search, num);
	}
	printf("");
	PrintList(&list);

	//----------------------------------------------
	// 5 노드 삭제 ////
	//----------------------------------------------
	printf("---------------데이터 삭제---------------\n");
	printf("삭제할 값 입력 : ");
	scanf_s("%d", &num);
	LRemove(&list, num);
	PrintList(&list);


	return 0;
}