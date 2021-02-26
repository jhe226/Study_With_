//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct treeNode
//{
//	char key;				// ������ �ʵ�
//	struct treeNode* left;	// ���� ���� Ʈ�� ��ũ �ʵ�
//	struct treeNode* right;	// ������ ���� Ʈ�� ��ũ �ʵ�
//} treeNode;
//
//treeNode* root = NULL;
//
//
////Ž�� �Լ�
//
//treeNode* search(char x)
//{
//	
//	// 1 ���۳�� �ּ� *p �� ����
//	treeNode * p = root;
//	if (p == NULL)
//		return NULL;
//
//
//	// 2 p�� NULL�϶����� ��� �ݺ�
//	while (p != NULL)
//	{
//		// 3 p->key�� x �� �� 
//		if (p->key == x) // 3-1 p->key == x		-> ����ּ� return
//		{
//			return p;
//		}
//		else if (p->key > x) // 3-1 p->key > x		-> p->left �� �̵�
//		{
//			p = p->left;
//		}
//		else // 3-1 p->key < x		-> p->right �� �̵� 
//		{
//			p = p->right;
//		}		
//	}
//	//������ Ű�� X
//	//printf("�ش� Ű�� �������� �ʽ��ϴ�\n");
//	return NULL;
//
//
//
//
//}
//
//// ��� ���� �Լ� 
//void insertNode(char x) {
//	// 0 �ߺ�Ű ���� ����
//	if (search(x) != NULL)
//		return;
//	// 1 ��� ����
//	// 2 ������ ���ֱ�
//	// 3 ��ũ NULL �ʱ�ȭ
//	treeNode * new = (treeNode *)malloc(sizeof(treeNode));
//	if (new == NULL)
//		exit(1);
//	new->key = x;
//	new->left = NULL; new->right = NULL;
//
//	
//	if (root == NULL)// 4 ��� X
//	{
//		root = new;
//	}
//	else  // 5 ���   1�̻� ����
//	{
//		treeNode * cur = root;	//������ġ Ž��
//		treeNode * par = NULL;	//������ġ�� �θ��� Ž��
//
//		while (cur != NULL)
//		{
//			if (cur->key > x)
//			{
//				par = cur;
//				cur = cur->left;
//			}
//			else
//			{
//				par = cur;
//				cur = cur->right;
//			}
//		}
//		//par ����ġ Ž��
//		//cur �� NULL
//		if (par->key > x)
//		{
//			par->left = new;
//		}
//		else
//		{
//			par->right = new;
//		}
//	}
//
//}
//
//// ��� ���� �Լ�(�ڽ� X , �ڽ� 1 , �ڽ� 2) 
//void deleteNode(char key)
//{
//
//	//00 ��尡 �ϳ��� ���°��
//	if (root == NULL)
//		return;
//
//	//01 ��ȸ (�������� return , ������ 02���� )
//	if (search(key) == NULL)
//		return;
//
//	//02 ��������ּ�(treeNode * cur)�� �����θ����ּ�(treeNode * par) Ž��
//	treeNode * cur = root;
//	treeNode * par = NULL;
//
//	while (cur->key != key)
//	{
//		if (cur->key > key)
//		{
//			par = cur;
//			cur = cur->left;
//		}
//		else
//		{
//			par = cur;
//			cur = cur->right;
//		}
//	}
//	//cur��ġ Ž���Ϸ� 
//	//par��ġ Ž���Ϸ�(par�� NULL�� ����Ǿ��ִٸ�  �������� root ��尡 �ȴ�)
//
//
//	//03 ��������� �ڽĳ���� ���� Ȯ��
//	
//	if (cur->left == NULL && cur->right == NULL)//03-1��������� �ڽĳ�� X
//	{
//		if (par == NULL) //������尡 rootNode�ΰ�� 
//		{
//			root = NULL;	// root �����Ϳ� NULL(��� ������ ����)
//			free(cur);		// ������� 
//		}
//		else
//		{
//			if (par->left == cur)
//			{
//				par->left = NULL;
//				free(cur);
//			}
//			else
//			{
//				par->right = NULL;
//				free(cur);
//			}
//		}
//		
//	}
//	else if (cur->left == NULL || cur->right == NULL)//03-2��������� �ڽĳ�� 1
//	{
//		if (par == NULL) //������尡 root ����ΰ��
//		{
//			if (cur->left != NULL)
//			{
//				root = cur->left;
//			}
//			else
//			{
//				root = cur->right;
//			}
//		}
//		else //������尡 root��尡 �ƴѰ��
//		{
//			//�ڽ� ����ּҸ� ���� ������
//			treeNode * son = NULL;
//			//Son�� ��ġ�� Ȯ���ؼ� ����
//			if (cur->left != NULL)
//				son = cur->left;
//			else
//				son = cur->right;
//
//			
//			if (par->left == cur)
//			{
//				par->left = son;
//			}
//			else
//			{
//				par->right = son;
//			}
//			
//		}
//		free(cur);
//	}
//	else//03-3��������� �ڽĳ�� 2 
//	{
//			treeNode* succ_par = cur;
//			treeNode* succ = cur->left;
//
//			while (succ->right != NULL)
//			{
//				succ_par = succ;
//				succ = succ->right;
//			}
//			//succ_par->left==succ ==> �� �ݺ��۾��� �ѹ��� �������� ��������
//			//succ_par->left!=succ ==> �� �ݺ��۾��� �����ؼ� �����ʳ���带 Ž���� ����
//			if (succ_par->left == succ)
//			{
//				cur->key = succ->key;
//				cur->left = succ->left;
//			}
//			else
//			{
//				succ_par->right = succ->left;
//				cur->key = succ->key;
//			}
//			free(succ);
//	}
//
//}
//
//// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ����ϴ� ����
//void displayInorder(treeNode* cur) {
//	if (cur) {
//		displayInorder(cur->left);
//		printf("%c_", cur->key);
//		displayInorder(cur->right);
//	}
//}
//
//void menu() {
//	printf("\n*---------------------------*");
//	printf("\n\t1 : Ʈ�� ���");
//	printf("\n\t2 : ���� ����");
//	printf("\n\t3 : ���� ����");
//	printf("\n\t4 : ���� �˻�");
//	printf("\n\t5 : ����");
//	printf("\n*---------------------------*");
//	printf("\n�޴��Է� >> ");
//}
//
//int main() {
//	treeNode* foundedNode = NULL;
//	char choice, key;
//
//	// [�׸� 7-38]�� ���� �ʱ� ���� Ž�� Ʈ���� �����ϰ�
//	// ��� G�� ��Ʈ ��� ������ root�� ����
//	// A - Z  A <B<C<D<E<F..
//	insertNode('G');
//	insertNode('I');
//	insertNode('H');
//	insertNode('C');
//	insertNode('B');
//	insertNode('M');
//	insertNode('N');
//	insertNode('A');
//	insertNode('J');
//	insertNode('E');
//	insertNode('D');
//	insertNode('Q');
//
//	while (1) {
//		menu();
//		fflush(stdout);
//		scanf_s(" %c", &choice, sizeof(choice));
//
//		switch (choice - '0') {
//		case 1:
//			//			printf("\t[���� Ʈ�� ���]  ");
//			displayInorder(root);  printf("\n");
//			break;
//
//		case 2:
//			printf("������ ���ڸ� �Է��ϼ��� : ");
//			fflush(stdout);
//			scanf_s(" %c", &key, sizeof(key));
//			insertNode(key);
//			displayInorder(root);  printf("\n");
//			break;
//
//		case 3:
//			printf("������ ���ڸ� �Է��ϼ��� : ");
//			fflush(stdout);
//			scanf_s(" %c", &key, sizeof(key));
//			deleteNode(key);
//			displayInorder(root);  printf("\n");
//			break;
//
//		case 4:
//			printf("ã�� ���ڸ� �Է��ϼ��� : ");
//			fflush(stdout);
//			scanf_s(" %c", &key, sizeof(key));
//			foundedNode = search(key);
//			if (foundedNode != NULL)
//				printf("\n %c�� ã�ҽ��ϴ�! \n", foundedNode->key);
//			else
//				printf("\n ���ڸ� ã�� ���߽��ϴ�. \n");
//			break;
//
//		case 5:
//			return 0;
//
//		default:
//			printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���! \n");
//			break;
//		}
//	}
//	return 0;
//
//}
