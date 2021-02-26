#include <stdio.h>
#include <string.h>

/** 마지막 길이 반환 함수 ***/
int Endlen(int* arr)
{
	int len = 0, i = 0;
	while (arr[i] != '\0')
		i++;
	return i;
}
/**  데이터 출력 함수 ***/
void Output(int* arr)
{
	int len = Endlen(arr);
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");

}

/**  데이터 삽입 함수 ***/
void Insert(int * arr, int data)
{
	// 꽉찬상태여부 확인(배열의 마지막 전idx(98) 가 0(NULL)인지 확인)
	// ->99 idx까지 데이터를 담게되면 Endlen() 사용할수 가 없다..
	// 저장할 위치idx를 탐색(Endlen()함수를 이용해서 idx를 확인)
	// 해당 idx요소에 전달된 data값을 저장 

	if (arr[98] == 0) //꽉찬상태x
	{
		int idx = Endlen(arr); // 저장위치 인덱스를 idx변수에 저장
		arr[idx] = data;	//삽입할 data를 arr배열의 idx번째에 저장 

	}
	else // 꽉찬 상태 o
	{
		printf("배열에 데이터가 꽉찬 상태입니다. 값삽입 불가능..\n");
	}


}

/**  데이터 조회 함수 ***/
int Search(int * arr, int target)
{
	//순차탐색
	//0 idx부터 차례로검색(Endlen()를통해서 저장된 값의 길이를 확인한 후 반복)
	// idx요소와 target과 비교해서 일치하면 idx리턴
	// 불일치시 -1 리턴 
	int len = Endlen(arr);	// 저장된 값의 길이반환
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == target)
		{
			return i;
		}
	}
	return -1;
}

/**  데이터 중복 조회 함수 ***/
void DSearch(int * arr, int target)
{
	//순차탐색
	//몇회 중복되었는지
	//중복된 idx는 어디어디에 있는지를 화면에 print
	//[출력예]
	//11 11 22 22 33
	//조회값 입력 : 22
	//22는 1,2 idx에 총 2회 중복되어있습니다

	int cnt = 0; // 중복된 회수를 저장할 용도
	for (int i = 0; i < Endlen(arr); i++)
	{
		if (arr[i] == target)
		{
			cnt++;
			printf("%d,", i);
		}
	}
	if (cnt != 0) //cnt!=0 -> target과 일치하는 데이터 1이상
	{
		printf("\b idx에 총 %d번 반복되었습니다\n", cnt);
	}
	else //cnt==0 -> target과 일치하는 데이터 X
	{
		printf("해당 값은 조회되지 않습니다\n");
	}


}
/**  데이터 삭제 함수 ***/
int Remove(int * arr, int target)
{
	// 1 삭제할 데이터를 조회후 데이터가 있다면
	// 2 해당 배열 위치의 요소 뒤에있는 모든 값들을 삭제위치로 한칸씩 이동해서 덮어쓰기형태로 저장
	// 3 삭제할 데이터가 없다면 "해당 데이터는 없습니다\n" 출력 

	int result = Search(arr, target);	//-1 : 조회된데이터 x  or 값에 해당되는 idx를 반환
	int len = Endlen(arr);				//총 저장 데이터 길이
	int i = 0;							//반복에 사용될 변수 
	if (result != -1)	//삭제데이터 o
	{
		for (i = result; i < len; i++)
		{
			arr[i] = arr[i + 1];
		}
	}
	else // 삭제데이터 x
	{
		printf("해당 데이터는 없습니다\n");
	}



}
void DRemove(int* arr, int target)
{

	//동일 값이 있다면 전체 당긴 후(삭제후)
	//또다시 당김작업을 해야함
	//중첩 while문사용


	int result = Search(arr, target);	//-1 : 조회된데이터 x  or 값에 해당되는 idx를 반환
	int len = Endlen(arr);				//총 저장 데이터 길이
	int i = 0;							//반복에 사용될 변수 
	if (result != -1)	//삭제데이터 o
	{
		for(int k=result ;k<len; k++)
		{
			for (i = k; i < len; i++)
			{
				arr[i] = arr[i + 1];
			}
			if (arr[k] == target) // 당겨진 k idx의 요소값이 target 동일한 상황
			{
				k--;	//k 1감소 -> 반복조건식으로 올라가면 1증가되기때문에 해당 자리에서 
						//뒤에있는 요소들을 앞으로 당겨줘야함 
				len = Endlen(arr); //len에 저장된 총길이 다시 수정 -> 삭제된 만큼 반복회수감소
			}

		}

	}
	else // 삭제데이터 x
	{
		printf("해당 데이터는 없습니다\n");
	}


}

void main() {

	//-----------------------------
	// 데이터 삽입
	//-----------------------------
	/*** 데이터 저장 배열 정의***/
	int Array[100] = { 0 };

	/*** 5개의 데이터 저장 ***/
	Insert(Array, 11); 	Insert(Array, 11);
	Insert(Array, 22); 	Insert(Array, 22);
	Insert(Array, 33);  Insert(Array, 22);

	/*** 저장된 데이터  출력 ***/
	Output(Array);

	//-----------------------------
	// 데이터 조회
	//-----------------------------
	int n1;
	/*** 저장된 데이터  조회 ***/
	printf("조회값 입력 : ");
	scanf_s("%d", &n1);
	int result = Search(Array, n1);
	if (result != -1)
	{
		printf("탐색 완료 idx : %d\n", result);
	}
	else
	{
		printf("해당 값은 저장되어있지 않습니다\n");
	}
	
	//-----------------------------
	// 데이터 조회
	//-----------------------------
	/*** 중복 데이터  조회 ***/
	DSearch(Array, n1);
	printf("\n");

	//-----------------------------
	// 데이터 조회
	//-----------------------------
	int rm;
	/*** 데이터  삭제 ***/
	printf("삭제값 입력 : ");
	scanf_s("%d", &rm);
	Remove(Array, rm);
	Output(Array);

	//----------------------------------------------
	// 중복된 데이터 삭제 파트 
	//----------------------------------------------
	printf("삭제값 입력(중복데이터 모두삭제) : ");
	scanf_s("%d", &rm);
	DRemove(Array, rm);
	Output(Array);
}
