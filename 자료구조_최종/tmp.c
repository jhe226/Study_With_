
//#include <stdio.h>
//
////노드
//typedef struct ListNode {
//	char data[4];
//	struct ListNode* link;
//} listNode;
//
//int main()
//{
//	// 1 새노드 생성(노드+포인터+동적할당)
//	listNode * new = (listNode *)malloc(sizeof(listNode));
//	if (new == NULL)
//	{
//		printf("동적할당 실패!");
//		exit(1);
//	}
//	// 2 데이터필드에 값 삽입
//	strcpy_s(new->data, sizeof(new->data), "월");
//	// 3 링크에 NULL 초기화
//	new->link = NULL;
//
//	printf("데이터값 : %s\n", new->data);
//	printf("링크값 : %d\n", new->link);
//	return 0;
//}