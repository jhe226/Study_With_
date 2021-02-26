//-----------------------------
// 재귀함수
//-----------------------------
//스스로를 반복적으로 호출하는 형태의 코드를 포함하는 함수


//1) 재귀함수 기본

//#include <stdio.h>
//void Recursive(int num)
//{
//	if (num > 0)
//	{
//		printf("Recursive call!!: %d\n", num);
//		Recursive(num - 1);		//자신을 호출 
//	}
//}
//int main()
//{
//	Recursive(3);
//	return 0;
//}

//2) 재귀함수기본

//#include <stdio.h>
//void Recursive(int num)
//{
//	if (num > 0)
//	{
//		Recursive(num - 1);		//자신을 호출 
//		printf("Recursive call!!: %d\n", num);
//		
//	}
//}
//int main()
//{
//	Recursive(3);
//	return 0;
//}

//3) 재귀함수 기본

//#include <stdio.h>
//void Recursive(int num)
//{
//	if (num > 0)
//	{
//		printf("Recursive call!!: %d\n", num); //3 -> 2 -> 1
//		Recursive(num - 1);		//자신을 호출 
//		printf("Recursive call!!: %d\n", num); //1 -> 2 -> 3
//
//	}
//}
//int main()
//{
//	Recursive(3);
//	return 0;
//}


//4) 재귀함수를 이용해서 1부터 10까지의 합 구하기

//#include <stdio.h>
//
//int recursive(int num)
//{
//	int sum = 0;
//	if (num > 0)
//	{
//		sum = recursive(num - 1) + num; //재귀함수 호출 시점 
//		printf("num %d를 더한 sum의 값 : %d\n", num, sum);
//		return sum;
//	}
//	return 0;
//}
//int main()
//{
//	int total = recursive(10);
//	printf("합계 : %d\n", total);
//	return 0;
//}


//5) 1부터 10까지의 수중의 3의 배수의합 만 출력(수 %3 == 0 ) 

//#include <stdio.h>
//
//int recursive(int num)
//{
//	int sum = 0;
//	//전달받은 인자가 3의 배수가 될때까지 num 값 감소
//	while (num % 3 != 0)	//3의 배수가 될때까지
//	{	
//		num--;	//num을 1 감소
//	}
//	//while을 빠져나올때 9,6,3,0
//
//	if (num > 0)
//	{
//		sum = recursive(num - 1) + num; //재귀함수 호출 시점 
//		printf("num %d를 더한 sum의 값 : %d\n", num, sum);
//		return sum;
//	}
//	return 0;
//}
//int main()
//{
//	int total = recursive(10);
//	printf("합계 : %d\n", total);
//	return 0;
//}

//6) 재귀함수로 별찍기

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


//7) 재귀함수로 별찍기

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



//문제

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
//		//처리되는 부분
//		star(n - 1);
//		//공백찍기 반복
//		for (int i = 0; i <= 3 - n ; i++)
//		{
//			printf(" ");	//공백(n==1) :3 ,
//							//공백(n==2) :2 ,
//							//공백(n==3) :1 ,
//							//공백(n==4) :x 
//		}
//		//별찍기 반복
//		for (int i = 0; i <= (n - 1) * 2; i++)
//		{
//			printf("*");	//별찍기(n==1) : 1
//							//별찍기(n==2) : 3
//							//별찍기(n==3) : 5
//							//별찍기(n==4) : 7
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	star(4);
//	return 0;
//}



//문제

//*******
// *****
//  ***
//   *



//8) 피보나치 수열
// 0 1 2 3 5 8 13 21 ...

//#include <stdio.h>
//int Fibo(int n)
//{
//	if (n == 1)						//만약 n이 1이라면
//		return 0;					//0 을 리턴
//	if (n == 2)						//만약 n이 2이라면
//		return 1;					//1 을 리턴
//	if (n > 2)							//만약 n>2이라면
//		return Fibo(n - 2) + Fibo(n - 1);	//Fibo(n-2) + Fibo(n-1)을 리턴
//}
//int main()
//{
//	for (int i = 1; i < 15; i++)
//		printf("%d ", Fibo(i)); //Fibo(1) , Fibo(2), Fibo(3), .....Fibo(14)..
//	return 0;
//}


//9) 이진탐색 알고리즘을 재귀함수형태로 구현하기

////http://naver.me/FHYF8Tet
////1234
//
//#include <stdio.h>
//
//int BSearch(int *ar,int First ,int Last, int target)
//{
//	int mid = 0;
//	if (First <= Last)				//!!!!- 재귀함수의 탈출조건 if문으로 변경
//	{
//		mid = (First + Last) / 2;		//<--코드입력 (hint : Mid Index 저장)
//		if (ar[mid] == target)				//배열의 mid번째 요소값이 target과 일치한다면
//			return mid;					// mid를 리턴
//		if (ar[mid] > target)			//배열의 mid번째 요소값이 target보다 크다면 
//			return BSearch(ar, First, mid - 1, target);		//!!!! - 재귀함수호출! Last에 mid-1한 값을 인자로 전달				
//		if (ar[mid] < target)			//배열의 mid번째 요소값이 target보다 작다면 
//			return BSearch(ar, mid + 1, Last, target);		//!!!! - 재귀함수호출! First 에 mid + 1 한값을 인자로 전달
//	}
//	return -1;							//반복문을 벗어난 리턴은 First>Last 보다 커진경우
//										//target이 배열에 없으므로 -1을 리턴 
//}
//int main(void)
//{
//	int arr[] = { 1, 3, 5, 7, 9 };
//	int idx;
//
//	idx = BSearch(arr,0, (sizeof(arr) / sizeof(int))-1, 7);
//	if (idx == -1)
//		printf("탐색 실패 \n");
//	else
//		printf("타겟 저장 인덱스: %d \n", idx);
//
//	idx = BSearch(arr,0, (sizeof(arr) / sizeof(int))-1, 4);
//	if (idx == -1)
//		printf("탐색 실패 \n");
//	else
//		printf("타겟 저장 인덱스: %d \n", idx);
//
//	return 0;
//}


//10) 하노이 타워 

//#include <stdio.h>
//
//void Hanoi(int num, char from, char by, char to)//원반개수,현재기둥,경유기둥,옮길기둥
//{
//	if (num > 0)
//	{
//		Hanoi(num - 1, from, to, by);				 //Hanoi 재귀호출 num-1 를 A->B 이동
//		printf("%c에 있는 %d번째 원반을 %c로 옮김\n",from, num, to); //printf 마지막 원반을 C로 이동
//		Hanoi(num - 1, by, from, to);				 //Hanoi 재귀호출 num-1 를 B->C 이동
//	}
//
//}
//
//int main(void)
//{
//	// 막대A의 원반 3개를 막대B를 경유하여 막대C로 옮기기
//	Hanoi(2, 'A', 'B', 'C');
//	return 0;
//}