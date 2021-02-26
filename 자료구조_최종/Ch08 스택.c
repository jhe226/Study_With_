//#include <stdio.h>
//#include <stdlib.h>
//
//#define TRUE	1
//#define FALSE	0
//
////������ ����ü ��� ����
//typedef struct node
//{
//	int data;
//	struct Node* next;
//}Node;
//
//// TopPointer 
//Node * Top;
//
//// ��ũ �ʱ�ȭ �Լ�
//void StackInit()
//{
//	Top = NULL;
//}
//
//// ��ũ Null Ȯ�� �Լ�
//int SIsEmpty()
//{
//	if (Top == NULL)
//		return TRUE;
//	else
//		return FALSE;
//}
//
//// ������(Top) ������ Ȯ�� �Լ�
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
//// PUSH �Լ� 
//void SPush(int data)
//{
//	// 1 ������
//	// 2 ���ֱ�
//	// 3 ��ũ NULL
//	Node * new = (Node *)malloc(sizeof(Node));
//	if (new == NULL)
//	{
//		printf("OverFlow\n");
//		exit(1);
//	}
//	new->data = data;
//	new->next = NULL;
//	
//	// 4 ��尡 �ϳ��� ������
//	// 5 ��尡 �ϳ��̻� ������
//	// 5-1 new�� next�� top ����
//	// 5-2 top �� new ����
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
//// POP �Լ� 
//void SPop()
//{
//
//	// 1 ��� �ϳ��� ������
//	if (Top == NULL)
//	{
//		printf("UnderFlow!\n");
//		return;
//	}
//
//	// 2 ��� ������
//	// 2-1 Top ��ġ�� del�� ����
//	// 2-2 Top �� ���� ��ġ�� �̵�
//	// 2-3 del �� free() �� ����
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
//	// Stack�� ���� �� �ʱ�ȭ ///////
//	//--------------------------------------------------
//	StackInit();
//
//	//--------------------------------------------------
//	// ������ �ֱ� ///////
//	//--------------------------------------------------
//	printf("---------------(1) PUSH() ----------------\n");
//	SPush(1);  SPush(2);
//	SPush(3);  SPush(4);
//	SPush(5);
//	PrintStack();
//	//--------------------------------------------------
//	// ������ ������ Ȯ�� ///////
//	//--------------------------------------------------
//	printf("---------------(2) PEEK() ----------------\n");
//	printf("������ ������ : %d\n", SPeek());
//	//--------------------------------------------------
//	// ������ ������ ///////
//	//--------------------------------------------------
//	printf("---------------(3) PEEK() ----------------\n");
//	printf("1ȸ POP()! :"); SPop();
//	PrintStack();
//	printf("2ȸ POP()! :"); SPop();
//	PrintStack();
//	printf("3ȸ POP()! :"); SPop();
//	PrintStack();
//	printf("4ȸ POP()! :"); SPop();
//	PrintStack();
//	printf("5ȸ POP()! :"); SPop();
//	PrintStack();
//	printf("6ȸ POP()! :"); SPop();
//	PrintStack();
//	return 0;
//}