#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
	char key;				// 데이터 필드
	struct treeNode* left;	// 왼쪽 서브 트리 링크 필드
	struct treeNode* right;	// 오른쪽 서브 트리 링크 필드
} treeNode;

treeNode* root = NULL;


//탐색 함수

treeNode* search(char x)
{
	
	// 1 시작노드 주소 *p 로 받음
	treeNode * p = root;
	if (p == NULL)
		return NULL;


	// 2 p가 NULL일때까지 계속 반복
	while (p != NULL)
	{
		// 3 p->key와 x 를 비교 
		if (p->key == x) // 3-1 p->key == x		-> 노드주소 return
		{
			return p;
		}
		else if (p->key > x) // 3-1 p->key > x		-> p->left 로 이동
		{
			p = p->left;
		}
		else // 3-1 p->key < x		-> p->right 로 이동 
		{
			p = p->right;
		}		
	}
	//동일한 키가 X
	//printf("해당 키가 존재하지 않습니다\n");
	return NULL;




}

// 노드 삽입 함수 
void insertNode(char x) {
	// 0 중복키 존재 여부
	if (search(x) != NULL)
		return;
	// 1 노드 생성
	// 2 데이터 값넣기
	// 3 링크 NULL 초기화
	treeNode * new = (treeNode *)malloc(sizeof(treeNode));
	if (new == NULL)
		exit(1);
	new->key = x;
	new->left = NULL; new->right = NULL;

	
	if (root == NULL)// 4 노드 X
	{
		root = new;
	}
	else  // 5 노드   1이상 존재
	{
		treeNode * cur = root;	//삽입위치 탐색
		treeNode * par = NULL;	//삽입위치의 부모노드 탐색

		while (cur != NULL)
		{
			if (cur->key > x)
			{
				par = cur;
				cur = cur->left;
			}
			else
			{
				par = cur;
				cur = cur->right;
			}
		}
		//par 의위치 탐색
		//cur 는 NULL
		if (par->key > x)
		{
			par->left = new;
		}
		else
		{
			par->right = new;
		}
	}

}

// 노드 삭제 함수(자식 X , 자식 1 , 자식 2) 
void deleteNode(char key)
{

}

// 이진 탐색 트리를 중위 순회하면서 출력하는 연산
void displayInorder(treeNode* cur) {
	if (cur) {
		displayInorder(cur->left);
		printf("%c_", cur->key);
		displayInorder(cur->right);
	}
}

void menu() {
	printf("\n*---------------------------*");
	printf("\n\t1 : 트리 출력");
	printf("\n\t2 : 문자 삽입");
	printf("\n\t3 : 문자 삭제");
	printf("\n\t4 : 문자 검색");
	printf("\n\t5 : 종료");
	printf("\n*---------------------------*");
	printf("\n메뉴입력 >> ");
}

int main() {
	treeNode* foundedNode = NULL;
	char choice, key;

	// [그림 7-38]과 같은 초기 이진 탐색 트리를 구성하고
	// 노드 G를 루트 노드 포인터 root로 지정
	// A - Z  A <B<C<D<E<F..
	insertNode('G');
	insertNode('I');
	insertNode('H');
	insertNode('C');
	insertNode('B');
	insertNode('M');
	insertNode('N');
	insertNode('A');
	insertNode('J');
	insertNode('E');
	insertNode('D');
	insertNode('Q');

	while (1) {
		menu();
		fflush(stdout);
		scanf_s(" %c", &choice, sizeof(choice));

		switch (choice - '0') {
		case 1:
			//			printf("\t[이진 트리 출력]  ");
			displayInorder(root);  printf("\n");
			break;

		case 2:
			printf("삽입할 문자를 입력하세요 : ");
			fflush(stdout);
			scanf_s(" %c", &key, sizeof(key));
			insertNode(key);
			displayInorder(root);  printf("\n");
			break;

		case 3:
			printf("삭제할 문자를 입력하세요 : ");
			fflush(stdout);
			scanf_s(" %c", &key, sizeof(key));
			deleteNode(key);
			displayInorder(root);  printf("\n");
			break;

		case 4:
			printf("찾을 문자를 입력하세요 : ");
			fflush(stdout);
			scanf_s(" %c", &key, sizeof(key));
			foundedNode = search(key);
			if (foundedNode != NULL)
				printf("\n %c를 찾았습니다! \n", foundedNode->key);
			else
				printf("\n 문자를 찾지 못했습니다. \n");
			break;

		case 5:
			return 0;

		default:
			printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n");
			break;
		}
	}
	return 0;

}
