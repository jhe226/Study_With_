
//#include <stdio.h>
//
////���
//typedef struct ListNode {
//	char data[4];
//	struct ListNode* link;
//} listNode;
//
//int main()
//{
//	// 1 ����� ����(���+������+�����Ҵ�)
//	listNode * new = (listNode *)malloc(sizeof(listNode));
//	if (new == NULL)
//	{
//		printf("�����Ҵ� ����!");
//		exit(1);
//	}
//	// 2 �������ʵ忡 �� ����
//	strcpy_s(new->data, sizeof(new->data), "��");
//	// 3 ��ũ�� NULL �ʱ�ȭ
//	new->link = NULL;
//
//	printf("�����Ͱ� : %s\n", new->data);
//	printf("��ũ�� : %d\n", new->link);
//	return 0;
//}