#include <stdio.h>
#include <string.h>

/** ������ ���� ��ȯ �Լ� ***/
int Endlen(int* arr)
{
	int len = 0, i = 0;
	while (arr[i] != '\0')
		i++;
	return i;
}
/**  ������ ��� �Լ� ***/
void Output(int* arr)
{
	int len = Endlen(arr);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

}

/**  ������ ���� �Լ� ***/
void Insert(int * arr, int data)
{
	// �������¿��� Ȯ��(�迭�� ������ ��idx(98) �� 0(NULL)���� Ȯ��)
	// ->99 idx���� �����͸� ��ԵǸ� Endlen() ����Ҽ� �� ����..
	// ������ ��ġidx�� Ž��(Endlen()�Լ��� �̿��ؼ� idx�� Ȯ��)
	// �ش� idx��ҿ� ���޵� data���� ���� 

	if (arr[98] == 0) //��������x
	{
		int idx = Endlen(arr); // ������ġ �ε����� idx������ ����
		arr[idx] = data;	//������ data�� arr�迭�� idx��°�� ���� 

	}
	else // ���� ���� o
	{
		printf("�迭�� �����Ͱ� ���� �����Դϴ�. ������ �Ұ���..\n");
	}


}

/**  ������ ��ȸ �Լ� ***/
int Search(int * arr, int target)
{
	//����Ž��
	//0 idx���� ���ʷΰ˻�(Endlen()�����ؼ� ����� ���� ���̸� Ȯ���� �� �ݺ�)
	// idx��ҿ� target�� ���ؼ� ��ġ�ϸ� idx����
	// ����ġ�� -1 ���� 
	int len = Endlen(arr);	// ����� ���� ���̹�ȯ
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == target)
		{
			return i;
		}
	}
	return -1;
}

/**  ������ �ߺ� ��ȸ �Լ� ***/
void DSearch(int * arr, int target)
{
	//����Ž��
	//��ȸ �ߺ��Ǿ�����
	//�ߺ��� idx�� ����� �ִ����� ȭ�鿡 print
	//[��¿�]
	//11 11 22 22 33
	//��ȸ�� �Է� : 22
	//22�� 1,2 idx�� �� 2ȸ �ߺ��Ǿ��ֽ��ϴ�

	int cnt = 0; // �ߺ��� ȸ���� ������ �뵵
	for (int i = 0; i < Endlen(arr); i++)
	{
		if (arr[i] == target)
		{
			cnt++;
			printf("%d,", i);
		}
	}
	if (cnt != 0) //cnt!=0 -> target�� ��ġ�ϴ� ������ 1�̻�
	{
		printf("\b idx�� �� %d�� �ݺ��Ǿ����ϴ�\n", cnt);
	}
	else //cnt==0 -> target�� ��ġ�ϴ� ������ X
	{
		printf("�ش� ���� ��ȸ���� �ʽ��ϴ�\n");
	}


}
/**  ������ ���� �Լ� ***/
int Remove(int * arr, int target)
{
	// 1 ������ �����͸� ��ȸ�� �����Ͱ� �ִٸ�
	// 2 �ش� �迭 ��ġ�� ��� �ڿ��ִ� ��� ������ ������ġ�� ��ĭ�� �̵��ؼ� ��������·� ����
	// 3 ������ �����Ͱ� ���ٸ� "�ش� �����ʹ� �����ϴ�\n" ��� 

	int result = Search(arr, target);	//-1 : ��ȸ�ȵ����� x  or ���� �ش�Ǵ� idx�� ��ȯ
	int len = Endlen(arr);				//�� ���� ������ ����
	int i = 0;							//�ݺ��� ���� ���� 
	if (result != -1)	//���������� o
	{
		for (i = result; i < len; i++)
		{
			arr[i] = arr[i + 1];
		}
	}
	else // ���������� x
	{
		printf("�ش� �����ʹ� �����ϴ�\n");
	}



}
void DRemove(int* arr, int target)
{

	//���� ���� �ִٸ� ��ü ��� ��(������)
	//�Ǵٽ� ����۾��� �ؾ���
	//��ø while�����


	int result = Search(arr, target);	//-1 : ��ȸ�ȵ����� x  or ���� �ش�Ǵ� idx�� ��ȯ
	int len = Endlen(arr);				//�� ���� ������ ����
	int i = 0;							//�ݺ��� ���� ���� 
	if (result != -1)	//���������� o
	{
		for(int k=result ;k<len; k++)
		{
			for (i = k; i < len; i++)
			{
				arr[i] = arr[i + 1];
			}
			if (arr[k] == target) // ����� k idx�� ��Ұ��� target ������ ��Ȳ
			{
				k--;	//k 1���� -> �ݺ����ǽ����� �ö󰡸� 1�����Ǳ⶧���� �ش� �ڸ����� 
						//�ڿ��ִ� ��ҵ��� ������ �������� 
				len = Endlen(arr); //len�� ����� �ѱ��� �ٽ� ���� -> ������ ��ŭ �ݺ�ȸ������
			}

		}

	}
	else // ���������� x
	{
		printf("�ش� �����ʹ� �����ϴ�\n");
	}


}

void main() {

	//-----------------------------
	// ������ ����
	//-----------------------------
	/*** ������ ���� �迭 ����***/
	int Array[100] = { 0 };

	/*** 5���� ������ ���� ***/
	Insert(Array, 11); 	Insert(Array, 11);
	Insert(Array, 22); 	Insert(Array, 22);
	Insert(Array, 33);  Insert(Array, 22);

	/*** ����� ������  ��� ***/
	Output(Array);

	//-----------------------------
	// ������ ��ȸ
	//-----------------------------
	int n1;
	/*** ����� ������  ��ȸ ***/
	printf("��ȸ�� �Է� : ");
	scanf_s("%d", &n1);
	int result = Search(Array, n1);
	if (result != -1)
	{
		printf("Ž�� �Ϸ� idx : %d\n", result);
	}
	else
	{
		printf("�ش� ���� ����Ǿ����� �ʽ��ϴ�\n");
	}
	
	//-----------------------------
	// ������ ��ȸ
	//-----------------------------
	/*** �ߺ� ������  ��ȸ ***/
	DSearch(Array, n1);
	printf("\n");

	//-----------------------------
	// ������ ��ȸ
	//-----------------------------
	int rm;
	/*** ������  ���� ***/
	printf("������ �Է� : ");
	scanf_s("%d", &rm);
	Remove(Array, rm);
	Output(Array);

	//----------------------------------------------
	// �ߺ��� ������ ���� ��Ʈ 
	//----------------------------------------------
	printf("������ �Է�(�ߺ������� ��λ���) : ");
	scanf_s("%d", &rm);
	DRemove(Array, rm);
	Output(Array);
}
