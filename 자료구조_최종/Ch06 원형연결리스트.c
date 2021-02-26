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
//	Node* tail;		// ���� ��ġ ������
//	int NodeCnt;	// ������ ���� Ȯ��
//}List;
//
////�ʱ�ȭ�Լ�
//void ListInit(List* plist)
//{
//	plist->tail = NULL;	// ���������� �ʱ�ȭ
//	plist->NodeCnt = 0;	// ������ ���� �ʱ�ȭ
//}
//
////����Ʈ ����Ʈ �Լ� 
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
////�������� ����
//void LInsert(List* plist, int data)
//{
//	//1 ������
//	//2 ������ ���ֱ�
//	//3 ��ũ�� �ʱ�ȭ
//	Node * new = (Node *)malloc(sizeof(Node));
//	if (new == NULL)
//	{
//		printf("�����Ҵ� ����!\n");
//		exit(1);
//	}
//	new->data = data;
//	new->next = NULL;
//
//	if (plist->tail == NULL)//4-1 ��尡 �ϳ��� ������
//	{
//		plist->tail = new;
//		plist->tail->next = new;
//		
//	}
//	else //4-2 ��尡 �ϳ��̻� ������
//	{
//		new->next=plist->tail->next;
//		plist->tail->next = new;
//		plist->tail = new;
//	}
//	plist->NodeCnt++;
//}
//
////ó���� ����
//void LInsertFront(List* plist, int data)
//{
//	//1 ������(NULLüũ) + �����Ͱ��ֱ� + ��ũNULL�ʱ�ȭ
//	Node * new = (Node *)malloc(sizeof(Node));
//	if (new == NULL)
//	{
//		printf("�����Ҵ� ����!\n");
//		exit(1);
//	}
//	new->data = data;
//	new->next = NULL;
//
//	if (plist->tail == NULL)//2-1 ��尡 X
//	{
//		plist->tail = new;
//		plist->tail->next = new;
//	}
//	else//2-2 ��尡 O
//	{
//		new->next = plist->tail->next;
//		plist->tail->next = new;	
//	}
//	plist->NodeCnt++;
//}
//
//
////��ȸ �Լ�
//Node* SearchNode(List* plist, int target)
//{
//	//1 ���� ��尡 X -> return NULL;
//	//2 ���� ��尡 O -> 3 �۾� ����
//	//3-1 Nodecnt������ŭ �ݺ� , ��ġ ������ ������ ��� �ּ� Return 
//	//3-1 Nodecnt������ŭ �ݺ� , ��ġ ������ ������ NULL Return
//
//	//1 ���� ��尡 X -> return NULL;
//	if (plist->tail == NULL)
//		return NULL;
//
//	//2 ���� ��尡 O -> 3 �۾� ����
//	Node * cur = plist->tail->next;	//ù�����ġ�� �˻� ���������� ����
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
////���� �Լ�
//void LRemove(List* plist, int target)
//{
//	// 1 ��ȸ
//	// 2 ��������� ����� �˻�
//	// 3-1 ������尡 ������ΰ��
//	// 3-2 ������尡 ����尡 �ƴѰ��
//
//	Node* del = SearchNode(plist, target);
//	if (del == NULL)
//	{
//		printf("������� X\n");
//		return ;
//	}
//
//
//	Node * pre = plist->tail->next;	//�����ã�� ���� ������ 
//	//�������ġ ã��
//	//��� ������ŭ �ݺ��ϸ鼭 pre�� next���� del����ġ�ϸ� break	
//	for (int i = 0; i < plist->NodeCnt; i++)
//	{
//		if (pre->next == del)
//			break;
//		pre = pre->next;
//	}
//
//	pre->next = del->next; //��������� ������ġ�� ������� next�� ���� 
//	plist->NodeCnt--;		// ��尳�� 1 ���� 
//
//	if (plist->tail == del) //������尡 ������ΰ�� 
//	{
//		plist->tail = pre; //tail�� ��ġ�� ���� ������ ���� 
//	}
//
//	free(del); //������� �����Ҵ� ���� 
//
//}
//
//int main(void)
//{
//	//-----------------------------------
//	// ���� ���� ����Ʈ�� ���� �� �ʱ�ȭ 
//	//-----------------------------------
//	List list;
//	int data, i, nodeNum;
//	ListInit(&list);
//	int num;
//
//	//-----------------------------------
//	// ����忡 ���� /////// 
//	//-----------------------------------
//	printf("\n--------(1) �� ��忡 ���� ---------\n");
//	LInsert(&list, 3);
//	LInsert(&list, 4);
//	LInsert(&list, 5);
//	PrintList(&list);
//	
//	//-----------------------------------
//	// ù��忡 ���� /////// 
//	//-----------------------------------
//	printf("\n--------(2) ù ��忡 ���� ---------\n");
//	LInsertFront(&list, 2);
//	LInsertFront(&list, 1);
//	PrintList(&list);
//
//	//-----------------------------------
//	//����� ������ ��ȸ///////
//	//-----------------------------------
//	printf("\n--------(3) ������ ��ȸ ---------\n");
//	printf("�� �Է�[��ȸ] : ");
//	scanf_s("%d", &num);
//	Node* cur = SearchNode(&list, num);
//	if (cur == NULL)
//		printf("�Է��� ���� ��ġ�ϴ� �����ʹ� �����ϴ�\n");
//	else
//		printf("�Է��� �� %d �� �����մϴ�\n", cur->data);
//
//	//-----------------------------------
//	//����
//	//-----------------------------------
//	printf("\n--------(4) ������ ���� ---------\n");
//	printf("�� �Է�[����] :");
//	scanf_s("%d", &num);
//	LRemove(&list, num);
//	PrintList(&list);
//
//	return 0;
//}