//-----------------------------
// ����Լ�
//-----------------------------
//�����θ� �ݺ������� ȣ���ϴ� ������ �ڵ带 �����ϴ� �Լ�


//1) ����Լ� �⺻

//#include <stdio.h>
//void Recursive(int num)
//{
//	if (num > 0)
//	{
//		printf("Recursive call!!: %d\n", num);
//		Recursive(num - 1);		//�ڽ��� ȣ�� 
//	}
//}
//int main()
//{
//	Recursive(3);
//	return 0;
//}

//2) ����Լ��⺻

//#include <stdio.h>
//void Recursive(int num)
//{
//	if (num > 0)
//	{
//		Recursive(num - 1);		//�ڽ��� ȣ�� 
//		printf("Recursive call!!: %d\n", num);
//		
//	}
//}
//int main()
//{
//	Recursive(3);
//	return 0;
//}

//3) ����Լ� �⺻

//#include <stdio.h>
//void Recursive(int num)
//{
//	if (num > 0)
//	{
//		printf("Recursive call!!: %d\n", num); //3 -> 2 -> 1
//		Recursive(num - 1);		//�ڽ��� ȣ�� 
//		printf("Recursive call!!: %d\n", num); //1 -> 2 -> 3
//
//	}
//}
//int main()
//{
//	Recursive(3);
//	return 0;
//}


//4) ����Լ��� �̿��ؼ� 1���� 10������ �� ���ϱ�

//#include <stdio.h>
//
//int recursive(int num)
//{
//	int sum = 0;
//	if (num > 0)
//	{
//		sum = recursive(num - 1) + num; //����Լ� ȣ�� ���� 
//		printf("num %d�� ���� sum�� �� : %d\n", num, sum);
//		return sum;
//	}
//	return 0;
//}
//int main()
//{
//	int total = recursive(10);
//	printf("�հ� : %d\n", total);
//	return 0;
//}


//5) 1���� 10������ ������ 3�� ������� �� ���(�� %3 == 0 ) 

//#include <stdio.h>
//
//int recursive(int num)
//{
//	int sum = 0;
//	//���޹��� ���ڰ� 3�� ����� �ɶ����� num �� ����
//	while (num % 3 != 0)	//3�� ����� �ɶ�����
//	{	
//		num--;	//num�� 1 ����
//	}
//	//while�� �������ö� 9,6,3,0
//
//	if (num > 0)
//	{
//		sum = recursive(num - 1) + num; //����Լ� ȣ�� ���� 
//		printf("num %d�� ���� sum�� �� : %d\n", num, sum);
//		return sum;
//	}
//	return 0;
//}
//int main()
//{
//	int total = recursive(10);
//	printf("�հ� : %d\n", total);
//	return 0;
//}

//6) ����Լ��� �����

//*
//**
//***
//****

//#include <stdio.h>
//void star(int n)
//{
//	if(n>0)
//	{
//		star(n - 1); // 3 -> 2 -> 1 -> 0
//		for (int i = 0; i < n; i++)
//			printf("*");
//		printf("\n");
//	}
//}
//int main()
//{
//	star(50);
//	return 0;
//}


//7) ����Լ��� �����

//****
//***
//**
//*

//#include <stdio.h>
//void star(int n)
//{
//	if(n>0)
//	{
//		for (int i = 0; i < n; i++)
//			printf("*");
//		printf("\n");
//
//		star(n - 1);
//
//	}
//}
//int main()
//{
//	star(4);
//	return 0;
//}



//����

//   *
//  ***
// *****
//*******

//--------------
//i		j		k
//0		0-2		0-0
//1		0-1		0-2
//2		0-0		0-4
//3		X		0-6


//#include <stdio.h>
//void star(int n)
//{
//	if(n>0)
//	{
//		//ó���Ǵ� �κ�
//		star(n - 1);
//		//������� �ݺ�
//		for (int i = 0; i <= 3 - n ; i++)
//		{
//			printf(" ");	//����(n==1) :3 ,
//							//����(n==2) :2 ,
//							//����(n==3) :1 ,
//							//����(n==4) :x 
//		}
//		//����� �ݺ�
//		for (int i = 0; i <= (n - 1) * 2; i++)
//		{
//			printf("*");	//�����(n==1) : 1
//							//�����(n==2) : 3
//							//�����(n==3) : 5
//							//�����(n==4) : 7
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	star(4);
//	return 0;
//}



//����

//*******
// *****
//  ***
//   *



//8) �Ǻ���ġ ����
// 0 1 2 3 5 8 13 21 ...

//#include <stdio.h>
//int Fibo(int n)
//{
//	if (n == 1)						//���� n�� 1�̶��
//		return 0;					//0 �� ����
//	if (n == 2)						//���� n�� 2�̶��
//		return 1;					//1 �� ����
//	if (n > 2)							//���� n>2�̶��
//		return Fibo(n - 2) + Fibo(n - 1);	//Fibo(n-2) + Fibo(n-1)�� ����
//}
//int main()
//{
//	for (int i = 1; i < 15; i++)
//		printf("%d ", Fibo(i)); //Fibo(1) , Fibo(2), Fibo(3), .....Fibo(14)..
//	return 0;
//}


//9) ����Ž�� �˰����� ����Լ����·� �����ϱ�

////http://naver.me/FHYF8Tet
////1234
//
//#include <stdio.h>
//
//int BSearch(int *ar,int First ,int Last, int target)
//{
//	int mid = 0;
//	if (First <= Last)				//!!!!- ����Լ��� Ż������ if������ ����
//	{
//		mid = (First + Last) / 2;		//<--�ڵ��Է� (hint : Mid Index ����)
//		if (ar[mid] == target)				//�迭�� mid��° ��Ұ��� target�� ��ġ�Ѵٸ�
//			return mid;					// mid�� ����
//		if (ar[mid] > target)			//�迭�� mid��° ��Ұ��� target���� ũ�ٸ� 
//			return BSearch(ar, First, mid - 1, target);		//!!!! - ����Լ�ȣ��! Last�� mid-1�� ���� ���ڷ� ����				
//		if (ar[mid] < target)			//�迭�� mid��° ��Ұ��� target���� �۴ٸ� 
//			return BSearch(ar, mid + 1, Last, target);		//!!!! - ����Լ�ȣ��! First �� mid + 1 �Ѱ��� ���ڷ� ����
//	}
//	return -1;							//�ݺ����� ��� ������ First>Last ���� Ŀ�����
//										//target�� �迭�� �����Ƿ� -1�� ���� 
//}
//int main(void)
//{
//	int arr[] = { 1, 3, 5, 7, 9 };
//	int idx;
//
//	idx = BSearch(arr,0, (sizeof(arr) / sizeof(int))-1, 7);
//	if (idx == -1)
//		printf("Ž�� ���� \n");
//	else
//		printf("Ÿ�� ���� �ε���: %d \n", idx);
//
//	idx = BSearch(arr,0, (sizeof(arr) / sizeof(int))-1, 4);
//	if (idx == -1)
//		printf("Ž�� ���� \n");
//	else
//		printf("Ÿ�� ���� �ε���: %d \n", idx);
//
//	return 0;
//}


//10) �ϳ��� Ÿ�� 

//#include <stdio.h>
//
//void Hanoi(int num, char from, char by, char to)//���ݰ���,������,�������,�ű���
//{
//	if (num > 0)
//	{
//		Hanoi(num - 1, from, to, by);				 //Hanoi ���ȣ�� num-1 �� A->B �̵�
//		printf("%c�� �ִ� %d��° ������ %c�� �ű�\n",from, num, to); //printf ������ ������ C�� �̵�
//		Hanoi(num - 1, by, from, to);				 //Hanoi ���ȣ�� num-1 �� B->C �̵�
//	}
//
//}
//
//int main(void)
//{
//	// ����A�� ���� 3���� ����B�� �����Ͽ� ����C�� �ű��
//	Hanoi(2, 'A', 'B', 'C');
//	return 0;
//}