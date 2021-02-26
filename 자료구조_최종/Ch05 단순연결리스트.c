#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode;

// ����Ʈ�� ����
listNode* L;	//��������

// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList() {
	listNode* p;
	listNode* cur = L;

	while (cur != NULL) {
		p = cur;
		cur = cur->link;
		free(p);
	}

	L = NULL;
}

// ���� ����Ʈ�� ������� ����ϴ� ����
void printList() {
	listNode* cur = L;

	printf("L = (");
	while (cur != NULL) {
		printf("%s", cur->data);
		cur = cur->link;
		if (cur != NULL)
			printf(", ");
	}
	printf(") \n");
}
// ù ��° ���� �����ϴ� ����
void insertFirstNode(char* x) {

	//1 new ��� ����(����ü+�����Ҵ�+������)-> Nullüũ 
	listNode * new = (listNode *)malloc(sizeof(listNode));
	if (new == NULL)
	{
		printf("�����Ҵ� ����");
		exit(1);
	}
	//2 ������ �κ� ������
	strcpy_s(new->data, sizeof(new->data), x);
	//3 ��ũ Null ����
	new->link = NULL;


	if (L != NULL)//4-1 ��尡 �ϳ��̻� �ִ°�� -> ó����ġ�� ����
	{
		new->link = L;
		L = new;
	}
	else//4-2 ��尡 �ϳ��� ���°�� -> ����L�����Ϳ� ��� �ٷο��� 
	{
		L = new;
	}
}
// ������ ���� �����ϴ� ����
void insertLastNode(char* x) {
	//1 new ��� ����(����ü+�����Ҵ�+������)-> Nullüũ 
	listNode * new = (listNode *)malloc(sizeof(listNode));
	if (new == NULL) {
		printf("�����Ҵ� ����!\n");
		exit(1);
	}
	//2 ������ �κ� ������
	strcpy_s(new->data, sizeof(new->data), x);
	//3 ��ũ Null ����
	new->link = NULL;

	if (L != NULL)//4-2 ��尡 �ϳ��̻� �ִ°�� -> ������ ��ġ�� ���� �ڵ� �ۼ� 
	{
		//5 tmp �����͸� ���� �� ��带 ��ȸ(tmp=tmp->link)�ϸ鼭 ��������ġ(link�� NULL) ���� Ȯ��
		listNode * tmp = L;
		while (tmp->link != NULL)
		{
			tmp = tmp->link;
		}
		//�ݺ����� ����ٴ� �ǹ̴� tmp�� ��������带 ����Ű�� �ִ»���!
		tmp->link = new;//6 ��������ġ���� ����带 ����	
	}
	else//4-1 ��尡 �ϳ��� ���°�� -> ����L�����Ϳ� ��� �ٷο��� 
	{
		L = new;
	}
	
	


}
// ����Ʈ���� x ��带 Ž���ϴ� ����
listNode* searchNode(char* x) {
	listNode * tmp=L;		//1 Ž���� ����ü ������(tmp) ����
							//2 ����� �����ּҸ� tmp�����Ϳ� ����

	//��尡 �ϳ��� ���°��
	if (L == NULL)
		return NULL;
	
	//��尡 ������ 
	while (tmp != NULL)	//3 ����带 ��ȸ(tmp=tmp->link)�ϸ鼭 ã�� ���ڿ��� ��ġ�ϴ� 
						//���ڿ� Ȯ��(strcmp(�ּ�1,�ּ�2))
	{
		if (strcmp(tmp->data, x) == 0)//�����Ͱ� ��ġ
		{
			break;
		}
		tmp = tmp->link;
	}
	return tmp;		//1) ������ �����Ͱ��� �ּҰ� tmp�� ��ܼ� break���
					//2) ����� ���������� �̵��Ѱ��(��ġ�ϴ� �����Ͱ� ����)
	

}
// ��带 pre �ڿ� �����ϴ� ����
void insertMiddleNode(listNode* pre, char* x) {
	
	//1 new ��� ����(����ü+�����Ҵ�+������)-> Nullüũ 
	listNode * new = (listNode *)malloc(sizeof(listNode));
	if (new == NULL)
	{
		printf("�޸� ���� ����..�����մϴ�");
		exit(1);
	}
	strcpy_s(new->data, sizeof(new->data), x);//2 ������ �κ� ������
	new->link = NULL;							//3 ��ũ Null ����


	if (pre != NULL) // ���Ž�� �Ϸ���� ,pre�ڿ� new��带 ������
	{
		//4 - 2 pre �� NULL �� �ƴѰ��
		//(pre->link ���� new->link ������ // pre->link�� new����ּҸ� ����)
		new->link = pre->link;
		pre->link = new;
	}
	else // �����Ϸ��� �ϴ� ��尡 �������� �ʴ»���
	{
		printf("�˻���尡 �����ϴ�\n");
		free(new);
	}

}
//�Լ������� �����˻� �Ŀ� �����ϱ�
void insertMiddleNode2(char* search, char* x)
{
	
	listNode * pre = searchNode(search);
	
	listNode * new = (listNode *)malloc(sizeof(listNode));
	if (new == NULL)
		exit(1);
	strcpy_s(new->data, sizeof(new->data), x);
	new->link = NULL;

	if (pre != NULL) //�ڿ� ����
	{
		new->link = pre->link;
		pre->link = new;
	}
	else //pre ��� ������,, ����Ұ�
	{
		printf("��� Ž�� ����!\n");
		free(new);
	}
}
// ����Ʈ���� ��� p�� �����ϴ� ����
void deleteNode(listNode* p) {
	//1 ������ �ش� ������ �������� ��ȸ
	if (p == NULL)
	{
		printf("������ ��尡 �����ϴ�\n");
		return;
	}

	//2 ���� ������� ��ġ Ž�� 
	listNode *pre = L;
	if (pre == NULL) //����� ��尡 �ϳ��� ���°��
	{
		printf("���� ����� ��尡 �����ϴ�\n");
		return ;
	}

	if (pre == p) //������ ��尡 ù����ΰ�� 
	{
		L = p->link;
	}
	else  //������ ��尡 ù��尡 �ƴѰ�� 
	{
		while (pre != NULL)
		{
			if (pre->link == p)
			{
				break;
			}

			pre = pre->link;
		}
		//1) ����� ���� �ٴٸ� ���(pre�ȿ� NULL) -- ��������

		//2) pre->link ==p �������°�� ..����带ã��!!
		pre->link = p->link;
	}
	free(p);



	//3 ���� ��ġ�� ó���ΰ��
	//4 ���� ��ġ�� ó���̾ƴѰ��(�������̰ų� �߰�����ΰ��)
	//4-1 ���� ��ġ�� �������ΰ��(���� ��������� link�� NULL ���� �� ������� free)
	//4-2 ���� ��ġ�� �߰�����ΰ��(���� ��������� link�� ������ ����� link�� ���� �� ������� free)
}

int main() {
	listNode* p;
	L = NULL;               //���� ����Ʈ ����

	// ---------------------------------------------
	// ������ ����(ù���)
	// ---------------------------------------------

	printf("----------(1) ù��忡 ���� [��][��] ----------\n");
	insertFirstNode("��");
	insertFirstNode("��");
	printList();

	// ---------------------------------------------
	// ������ ����(�����)
	// ---------------------------------------------
	printf("\n----------(2) ������ ��忡 ���� [��][��][��] ----------\n");
	insertLastNode("��");
	insertLastNode("��");
	insertLastNode("��");
	printList();

	// ---------------------------------------------
	// ������ Ž��
	// ---------------------------------------------
	printf("\n----------(4) ����Ʈ���� [��] ��� Ž���ϱ�!----------\n");
	p = searchNode("��");
	if (p == NULL)
		printf("ã�� �����Ͱ� �����ϴ�.\n");
	else
		printf("[%s]�� ã�ҽ��ϴ�.\n", p->data);

	printf("\n----------(3) ����Ʈ���� [��] ��� Ž���ϱ�! ----------\n");
	p = searchNode("��");
	if (p == NULL)
		printf("ã�� �����Ͱ� �����ϴ�.\n");
	else
		printf("[%s]�� ã�ҽ��ϴ�.\n", p->data);

	// ---------------------------------------------
	// ������ ���� (�߰� ���)
	// ---------------------------------------------
	printf("\n----------(5) ����Ʈ�� [��] �ڿ� [��] ��� �����ϱ�!----------\n");
	insertMiddleNode(p, "��");
	printList();

	// ---------------------------------------------
	// ������ ����2 (�߰� ���) - ã���� �����Է�
	// ---------------------------------------------
	printf("\n----------(6) ����Ʈ���� �˻��� ��� �ڿ� ����� �����ϱ�!----------\n");
	char search[4];
	char x[4];
	printf("�Է�(�˻�����,�߰�����) :");
	scanf_s("%s", search, sizeof(search));
	scanf_s("%s", x, sizeof(x));
	insertMiddleNode2(search,x);
	printList();

	// ---------------------------------------------
	// ������ ����
	// ---------------------------------------------
	printf("\n----------(7) ����Ʈ���� [��]��� �����ϱ�!----------\n");
	p = searchNode("��");		// ������ ��� ��ġ p�� ã��
	deleteNode(p);				// ������ p ��� ����
	printList();

	printf("\n----------(8) ����Ʈ���� [��]��� �����ϱ�!----------\n");
	p = searchNode("��");
	deleteNode(p);
	printList();

	printf("\n----------(9) ����Ʈ���� [��]��� �����ϱ�!----------\n");
	p = searchNode("��");
	deleteNode(p);
	printList();







	freeLinkedList();               //����Ʈ �޸� ����
	return 0;
}