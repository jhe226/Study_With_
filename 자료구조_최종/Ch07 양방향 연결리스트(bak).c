#include <stdio.h>
#include <stdlib.h>

//����ü ���

typedef struct _node
{
	int data;
	struct _node* next;		// ���� ��带 ����Ű�� ����ü ������
	struct _node* prev;     // ���� ��带 ����Ű�� ����ü ������	
} Node;

//������ ���

typedef struct _dbLinkedList
{
	Node* head;				// ó�� ��带 ����Ű�� ����ü ������
	Node* tail;				// ������ ��带 ����Ű�� ����ü ������
	int numOfData;			// ���� �������� ���� ī��Ʈ ����
} DBLinkedList;
typedef DBLinkedList List;

//�ʱ�ȭ �Լ�
void ListInit(List* plist)
{
	plist->head = NULL;
	plist->tail = NULL;
	plist->numOfData = 0;
}

//����Ʈ ��� �Լ� 
void PrintList(List* plist)
{
	Node* cur = plist->head;
	printf("����� ����Ʈ : ");
	for (int i = 0; i < plist->numOfData; i++)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


//ó���� ���� �Լ�
void LInsertFirst(List* plist, int data)
{
	// 1 ����� ����
	// 2 ������ ��
	// 3 ��ũ NULL
	Node * new = (Node *)malloc(sizeof(Node));
	if (new == NULL)
		exit(1);
	new->data = data;
	new->prev = NULL; new->next = NULL;

	// 4 ��� �ϳ��� ������
	// 5 ��� �ϳ��̻� ���� ��
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
//�������� ���� �Լ�
void LInsertLast(List* plist, int data)
{

	// 1 ����� ����
	// 2 ������ ��
	// 3 ��ũ NULL
	Node * new = (Node *)malloc(sizeof(Node));
	if (new == NULL)
		exit(1);
	new->data = data;
	new->prev = NULL; new->next = NULL;

	// 4 ��� �ϳ��� ������
	// 5 ��� �ϳ��̻� ���� ��	

	if (plist->numOfData == 0)
	{
		plist->head = new;
		plist->tail = new;	
	}
	else
	{
		plist->tail->next = new;	//���������next�� new��� ����
		new->prev = plist->tail;	//new��� prev�� ����� ����
		plist->tail = new;
	}
	plist->numOfData++;
}


// ó������ ��ȸ �Լ� 

int FindFirst(List* plist, int data)
{


	// 0 plist->head�� �̿��ؼ� ���ʷ� ����Ž�� 
	// 1 ��� ������ return NULL
	// 2 ��� ������ 
	// 2-1 NumofData ������ŭ �ݺ��Ͽ� ��ġ�� ������ ã���� return ��� �ּ�
	// 2-1 NumofData ������ŭ �ݺ��Ͽ� ��ġ�� ������ ��ã���� return NULL
	

	//1 ��尡 ������
	if (plist->numOfData == 0)
		return NULL;

	//2 ��尡 ������
	Node * cur = plist->head; //ó����ġ ��� 
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

// ���������� ��ȸ �Լ� 

int FindLast(List* plist, int data)
{

	// 0 plist->tail�� �̿��ؼ� ���ʷ� ����Ž��(������)
	// 1 ��� ������ return NULL
	// 2 ��� ������ 
	// 2-1 NumofData ������ŭ �ݺ��Ͽ� ��ġ�� ������ ã���� return ��� �ּ�
	// 2-1 NumofData ������ŭ �ݺ��Ͽ� ��ġ�� ������ ��ã���� return NULL

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
// �߰� ��� ���� �Լ� 

void LInsertMiddle(List* plist, Node* pre, int data)
{
	// 1 ������
	// 2 �����ͺ� ��
	// 3 ��ũ�� NULL �ʱ�ȭ 
	Node * new = (Node *)malloc(sizeof(Node));
	if (new == NULL)
		exit(1);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;

	// 4 pre �� ������ ����ΰ��
	// 5 pre �� ������ ��尡 �ƴѰ�� 
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
//�����Լ�
void LRemove(List* plist, int data)
{
	//1 ��ȸ(FindFirst(plist,data))
	//1-1 ������  return 
	//1-2 ��ȸ������ �ִٸ� 2 �� �̵�
	//2 ���� ��ġ Ȯ��
	//2-1 �Ǿ�
	//2-2 �߰�
	//2-3 ������
	//3 ������ ��� 1 ����

	if (plist->numOfData == 0)
	{
		printf("���������\n");
		return;
	}
	Node * del = FindFirst(plist, data);
	if (del == NULL)
	{
		printf("������� Ž������\n");
		return;
	}

	//��尡 ���� O , ������� O
	if (plist->head == del)	//ó��
	{
		plist->head = del->next;
		plist->head->prev = NULL;
	}
	else if (plist->tail == del) //������
	{
		plist->tail = del->prev;
		plist->tail->next = NULL;

	}
	else //�߰� 
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
	// ����� ���� ����Ʈ�� ���� �� �ʱ�ȭ  ///////
	//----------------------------------------------
	List list;
	int data;
	ListInit(&list);
	//----------------------------------------------
	// 1 ó����ġ�� ���� 
	//----------------------------------------------
	printf("\n--------------- ó�� ��ġ�� ���� ---------------\n");
	LInsertFirst(&list, 4);  LInsertFirst(&list, 3);
	LInsertFirst(&list, 2);  LInsertFirst(&list, 1);
	PrintList(&list);

	//----------------------------------------------
	// 2 ������ ��ġ�� ���� 
	//----------------------------------------------
	printf("\n--------------- ������ ��ġ�� ���� ---------------\n");
	LInsertLast(&list, 5);  LInsertLast(&list, 6);
	LInsertLast(&list, 7);  LInsertLast(&list, 8);
	PrintList(&list);

	//----------------------------------------------
// 3-1 ��� ������ ��ȸ(������) 
//----------------------------------------------
	printf("---------------������ ��ȸ (������)---------------\n");
	int num;
	printf("ã�� �� �Է�(��������ȸ) : ");
	scanf_s("%d", &num);
	Node* search = FindFirst(&list, num);
	if (search)
	{
		printf("%d�� ã�ҽ��ϴ�\n", search->data);
	}
	else
	{
		printf("�����Ͱ� �����ϴ�\n");
	}
	//----------------------------------------------
	// 3-2 ��� ������ ��ȸ(������) 
	//----------------------------------------------
	printf("---------------������ ��ȸ (������)---------------\n");
	printf("ã�� �� �Է�(��������ȸ) : ");
	scanf_s("%d", &num);
	search = FindLast(&list, num);
	if (search)
	{
		printf("%d�� ã�ҽ��ϴ�\n", search->data);
	}
	else
	{
		printf("�����Ͱ� �����ϴ�\n");
	}

	//----------------------------------------------
	//4 �߰���� ����
	//----------------------------------------------
	printf("---------------�߰� ��� ����---------------\n");
	printf("ã�� ��� ��:");
	scanf_s("%d", &num);
	search = FindFirst(&list, num);
	if (search == NULL)
	{
		printf("�ش� ���� ��忡 �������� �ʽ��ϴ�\n");
	}
	else
	{
		printf("������ �� �Է� :");
		scanf_s("%d", &num);
		LInsertMiddle(&list, search, num);
	}
	printf("");
	PrintList(&list);

	//----------------------------------------------
	// 5 ��� ���� ////
	//----------------------------------------------
	printf("---------------������ ����---------------\n");
	printf("������ �� �Է� : ");
	scanf_s("%d", &num);
	LRemove(&list, num);
	PrintList(&list);


	return 0;
}