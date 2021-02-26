//--------------------------
// 1 배열 
//--------------------------

//1) 배열크기 확인

//#include <stdio.h>
//
//int main()
//{
//	char c; int i; short s; float f; long l;
//	char c_array[100];
//	int i_array[100];
//	short s_array[100];
//	float f_array[100];
//	long l_array[100];
//	printf("char c 크기 : %d char c_array크기=%d\n", sizeof(c), sizeof(c_array));
//	printf("int  i 크기 : %d int i_array크기=%d\n", sizeof(i), sizeof(i_array));
//	printf("short s 크기 : %d short s_array크기=%d\n", sizeof(s), sizeof(s_array));
//	printf("float f 크기 : %d float f_array크기=%d\n", sizeof(f), sizeof(f_array));
//	printf("long l 크기 : %d long l_array크기=%d\n", sizeof(l), sizeof(l_array));
//	return 0;
//}

//2) 문자배열 vs 문자열


//#include <stdio.h>
//
//int main()
//{
//	char str1[4] = "abc";	//문자열 o, 문자배열 o
//	char str2[4] = "abcd";	//문자열 x, 문자배열 o
//
//	printf("str1 = %s\n", str1);	//정상출력
//	printf("str2 = %s\n", str2);	//비정상출력(문자열의끝,Null의 위치를 파악하지 못함)
//	
//	return 0;
//}



//--------------------------
// 2 흐름제어문 
//--------------------------

//1) 전체 구구단 수 출력
//2~ 9 단
//중첩 while문을 이용

//#include <stdio.h>
//
//int main()
//{
//	//반복의 탈출조건
//	//1 탈출용변수의 초기값 지정
//	//2 탈출용조건식
//	//3 변수의 증감을 통해 조건식을 거짓으로 만듦
//	int dan = 2;	//탈출용 변수
//	int j = 1;
//	while (dan<10) //참 :  0이 아닌 모든 값  거짓 : 0
//	{
//		j = 1;
//		while (j < 10)
//		{
//			printf("%d x %d = %d\n", dan, j, dan*j);
//			j++;
//		}
//		printf("\n");
//		dan++;
//	}
//	return 0;
//}



// 별찍기

//   *
//  ***
// *****
//*******

//i	k(공백)		j(*)
//0	0 - 2		0 - 0
//1	0 - 1		0 - 2
//2	0 - 0		0 - 4
//3	X			0 - 6
//------------------------------------------ -
//k = 0			j = 0
//k <= 2 - i	j <= 2 * i


//#include <stdio.h>
//
//int main()
//{
//	int i = 0; //줄바꿈용
//	int k = 0; //공백찍기
//	int j = 0; //별찍기
//	
//	while (i < 4)
//	{
//		//공백찍기
//		k = 0; 
//		while (k <= 2 - i)
//		{
//			printf(" ");
//			k++;
//		}
//		//별찍기
//		j = 0;
//		while (j <= 2 * i)
//		{
//			printf("*");
//			j++;
//		}
//		printf("\n");
//		i++;
//	}
//	return 0;
//}



//*******
// *****
//  ***
//   *

//i	j(공백)	k(*)
//0	x	0 - 6
//1	0 - 0	0 - 4
//2	0 - 1	0 - 2
//3	0 - 2	0 - 0
//----------------------------
//j = 0	k = 0
//j < i	k <= 6 - 2 * i
//


//#include <stdio.h>
//int main()
//{
//	int i = 0; //줄바꿈
//	int j = 0; //공백
//	int k = 0; //별찍기
//	while (i < 4)
//	{
//		//공백찍기
//		j = 0;
//		while (j < i)
//		{
//			printf(" ");
//			j++;
//		}
//		//별찍기
//		k = 0;
//		while (k <= 6 - 2 * i)
//		{
//			printf("*");
//			k++;
//		}
//		printf("\n");
//		i++;
//	}
//	return 0;
//}




//정수값 하나를 입력받아 해당 수만큼의 개행작업이 이뤄지면서
//정삼각형 모양의 별을 만들어보세요

//[출력 예]
//높이 입력 : 4
//     *
//    ***
//   *****
//  *******
//i(줄바꿈) 		j(공백)		k(별찍기)
//0				0 - n - 1		0 - 0
//1				0 - n - 2		0 - 2
//2				0 - n - 3		0 - 4
//3				0 - 0			0 - 6
//4								0 - 8
//
//n				X				0 - 2 * n
// ------------------------------------------
				//j =0			k=0
				//j<=(n-1)-i		k<=2*i

//#include <stdio.h>
//
//int main()
//{
//	int i = 0; //줄바꿈
//	int j = 0; //공백
//	int k = 0; //별찍기
//	int n = 0; //높이 저장
//	printf("삼각형의 높이 : ");
//	scanf_s("%d", &n);
//	while (i < n)
//	{
//		//공백
//		j = 0;
//		while (j <= (n - 1)-i)
//		{
//			printf(" ");
//			j++;
//		}
//
//		//별찍기
//		k = 0;
//		while (k<=2*i)
//		{
//			printf("*");
//			k++;
//		}
//
//		printf("\n");
//		i++;
//	}
//	return 0;
//}


//--------------------------
// 3 포인터 
//--------------------------

//Point: 점, 가리키다
//Pointer : 가리키는 도구
//
//특정 공간의 위치정보(메모리주소)를 담아 메모리공간을 제어(데이터 값저장 / 변경)할수있는 특수변수
//
//변수종류
//
//일반변수 : 데이터값을 저장
//포인터변수 : 메모리주소값을 저장
//
//포인터 연산자
//
//	* : 포인터연산자
//	& : 참조연산자
//
//	int num = 3;		// 3값을 int 공간 num에 대입	
//	int *ptr = &num;	// num의 메모리주소값을 int크기를 가리키는 ptr포인터변수에 초기화
//	*ptr = 10;			// 10값을 ptr포인터가 가리키는 공간에 대입
//	int num2 = *ptr;	// ptr이 가리키는 곳의 값을 num2변수에 초기화
//	printf("*ptr =%d", *ptr); //ptr이 가리키는 곳의 값을 10진정수 서식에 맞게 출력


//1) 포인터 복습
//메모리맵 그리고 오른쪽에 주석으로 해석해봅시다

//#include <stdio.h>
//int main()
//{
//	int num = 10;		//10상수값을 num변수 공간에 초기화
//	int *ptr1 = &num;	//num의 메모리주소값을 int크기정도를 가리키는 ptr1포인터에 초기화
//	int *ptr2 = ptr1;	//ptr1안의 값(주소값)을 ptr2포인터에 초기화
//
//	(*ptr1)++;			//ptr1이 가리키는 곳의 값을 1증가
//	(*ptr2)++;			//ptr2가 가리키는 곳의 값을 1증가 
//	printf("%d\n", num);
//	return 0;
//}


//2) 포인터와 배열
// -> 포인터에 배열의 시작주소를 담아주면 포인터를 배열처럼 사용할 수 있다 

//#include <stdio.h>
//
//int main()
//{
//	int arr[4] = { 10,20,30,40 };
//	int *ptr = &arr[0];
//
//	printf("%d %d\n", *(ptr),     ptr[0]);
//	printf("%d %d\n", *(ptr + 1), ptr[1]);
//	printf("%d %d\n", *(ptr + 2), ptr[2]);
//	printf("%d %d\n", *(ptr + 3), ptr[3]);
//	return 0;
//}


//3) 포인터와 함수

//Call-by-value		: 함수를 실행할때 전달하는 인자가 데이터값인 경우
//Call-by-address	: 함수를 실행할때 전달하는 인자가 메모리주소값인 경우
//Call-by-Reference(C++) :함수를 실행할때 전달하는 인자가 참조값인 경우

//#include <stdio.h>
//void Swap(int x, int y)
//{
//	int tmp = x;
//	x = y;
//	y = tmp;
//}
//int main() 
//{
//	int a = 10, b = 20;
//	printf("Swap 전 a = %d , b = %d\n", a, b);
//	Swap(a, b);	//Call-by-Value
//	printf("Swap 후 a = %d , b = %d\n", a, b);
//
//	return 0;
//}



// Call-by-Address

//#include <stdio.h>
//void Swap(int *x, int *y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//}
//int main()
//{
//	int a = 10, b = 20;
//	printf("Swap 전 a = %d , b = %d\n", a, b);
//	Swap(&a, &b);	//Call-by-Address
//	printf("Swap 후 a = %d , b = %d\n", a, b);
//
//	return 0;
//}


//4) 포인터와 문자열

//#include <stdio.h>
//
//int main()
//{
//	char arr[20] ="hello World";	//배열공간을 따로 만들어서 문자열 상수값을 저장
//	char * ptr1 = "hello World";
//	char * ptr2 = "hello World";
//	
//	printf("arr배열의 주소 : %x\n", arr);//배열의 이름은 배열의 시작주소를 담고있는 포인터상수이다
//	printf("hello World의 주소 :%x\n", "hello World");
//	printf("ptr1안의 주소 : %x\n", ptr1);//"hello World"라는 문자열 상수를 가리킴(ptr1==ptr2)
//	printf("ptr2안의 주소 : %x\n", ptr2);//"hello World"라는 문자열 상수를 가리킴(ptr1==ptr2)
//
//	return 0;
//}
//



//--------------------------
// 4 동적할당
//--------------------------

//코드영역		: 컴파일된 데이터 저장
//데이터영역		: 공유메모리영역(전역변수,static변수)		  프로그램시작시 생성 -> 프로그램종료시 소멸
//스택영역		: 중괄호({}) 내에서 선언되지는 변수(지역변수) 중괄호에서 생성 -> 중괄호벗어나면 소멸
//힙영역			: 동적할당 영역	 malloc함수 공간생성 -> free 공간소멸


//동적할당: 필요한 만큼 공간을 할당 받아 저장하기 위한 문법
//동적할당은 Heap 영역에 형성이 된다
//동적할당함수 : malloc(★), realloc, calloc
//동적할당해제 함수 : free;

//1) 동적할당기본

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() 
//{
//	// 동적할당 기본
//
//	//int *pi;
//	//pi = (int *)malloc(sizeof(int));
//	//if (pi == NULL)
//	//{
//	//	printf("동적할당 실패!");
//	//	exit(1);
//	//}
//	//*pi = 10;
//	//printf("pi = %d\n", *pi);
//
//	//free(pi);
//
//	// 동적할당 배열
//
//	int *arr;
//	arr = (int *)malloc(sizeof(int) * 7);
//	if (arr == NULL)
//	{
//		printf("동적할당 실패!");
//		exit(1);
//	}
//	//동적할당 배열에 값넣기
//	for (int i = 0; i < 7; i++)
//	{
//		arr[i] = i + 10;	//포인터에 배열의 시작주소를 담으면
//							//포인터를 배열처럼 사용할수 있다!!
//	}
//	//동적할당 배열의 값출력
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//문제

// int 형배열 10칸 배열을 동적할당해서
// 각각의 요소에 키보드로 입력한 정수값을 저장하세요
// 그리고 각저장된 수의 합과 최소값/최대값을 구해보세요
//
//[출력 예]
//0 idx에 정수값 : 10
//1 idx에 정수값 : 5
//2 idx에 정수값 : 4
//3 idx에 정수값 : 22
//4 idx에 정수값 : 77
//5 idx에 정수값 : 123
//6 idx에 정수값 : 45
//7 idx에 정수값 : 23
//8 idx에 정수값 : 89
//9 idx에 정수값 : 122
//
//총합 : ? 최대값 : ? 최소값 : ? 


// 답

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//
//	int sum = 0;	//총합 누적용
//	int max = 0;	//최대값 
//	int min = 0;	//최소값
//	int *arr = (int *)malloc(sizeof(int) * 10);	//동적할당
//	if (arr == NULL)
//	{
//		printf("동적할당 실패!");
//		exit(1);
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d Idx 요소에 값 입력 : ",i);
//		scanf_s("%d", &arr[i]);
//		sum = sum + arr[i];
//	}
//	//최소값/최대값
//	max = arr[0];
//	min = arr[0];
//	for (int i = 1; i < 10; i++)
//	{
//		if (max < arr[i])	//각 요소와 max값 비교후 큰값 저장
//			max = arr[i];	
//		if (min > arr[i])	//각 요소와 min값 비교후 작은값 저장
//			min = arr[i];
//	}
//	//저장된 값 출력
//	printf("총합 : %d 최소값 : %d 최대값 : %d\n", sum, min, max);
//
//	return 0;
//}


//2) 동적할당 공간확인 (_msize())

//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//
//	int * ptr1 = (int *)malloc(123);
//	int len1 = sizeof(ptr1);	//포인터변수의 크기를 잽니다
//	int len2 = _msize(ptr1);	//동적할당된 공간의 크기를 잽니다
//	printf("sizeof함수를 이용한 size확인 : %d\n", len1);
//	printf("_msize함수를 이용한 size확인 : %d\n", len2);
//
//	return 0;
//}


//3) 배열의 이름 
// 배열의 이름은 배열의 시작주소를 담고있는 포인터 상수이다

//#include <stdio.h>
//int main()
//{
//
//	int arr[3] = { 11,22,33 };
//
//	printf("첫번째 요소 값 : %d\n", *arr);		//배열의 시작위치의 값 %d로 출력
//	printf("첫번째 요소 값 : %d\n", *(arr+1));	//배열의 시작위치에서 int * 1 크기 정도 떨어진 곳의 값 %d로 출력
//	printf("첫번째 요소 값 : %d\n", *(arr+2));	//배열의 시작위치에서 int * 2 크기 정도 떨어진 곳의 값 %d로 출력
//
//	int num2 = 10;
//	arr = &num2; //arr은 포인터 상수 , 다른주소를 담을 수가 없다!!
//	
//	return 0;
//}



//--------------------------
// 문자열 처리 함수 
//--------------------------

//예제 1

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char str1[20];
//	char *ptr = "Hello World!";
//
//	//-----------------
//	//문자열 복사(strcpy_s(대상공간주소,대상공간크기,원본공간주소)
//	//-----------------
//	strcpy_s(str1, sizeof(str1), ptr);
//	printf("%s\n", str1);
//	//-----------------
//	//문자열 길이(strlen(문자열이저장된공간주소))
//	//-----------------
//	printf("str1 배열의 총 길이 : %d\n", sizeof(str1));
//	printf("str1 안의 문자열의 길이 : %d\n", strlen(str1));
//	//-----------------
//	//공백문자를 포함하는 값 입력받기 fgets(저장할공간주소 , 저장공간크기, stdin or FileStream)
//	//-----------------
//	char str2[20];
//	char str3[20];
//	printf("문자열입력(scanf_s) : ");
//	scanf_s("%s", str2, sizeof(str2)); //키보드로 문자열을 입력받아 str2의 크기에 맞게 저장하겠다 
//	rewind(stdin);	//버퍼 공간 초기화
//	printf("문자열입력(fgets) : ");
//	fgets(str3, sizeof(str3), stdin);	//stdin(표준입력스트림,키보드)로부터 문자열을받아 str3에 저장하겠다 
//	
//	//확인
//	printf("str2 : %s , str3 : %s\n", str2, str3);
//
//	//-----------------
//	//fgets로 값받을때 \n제거하기
//	//-----------------
//	// \n문자를 포함해서 값을 저장 -> \n 제거하는 작업 수반되어야한다
//
//	//\n 문자 입력 확인
//	printf("%s", str3);	//"%s"에 \n을 포함하지 않았는데 str3의 끝에 \n이 저장되어있기때문에 자동개행됩니다
//	for (int i = 0; i < 20; i++)
//		printf("%d ", str3[i]);
//	printf("\n");
//	//-----------------
//	//개행문자 제거하기 
//	//-----------------
//	int len = strlen(str3) - 1; // \n이 저장된 위치의 idx
//	str3[len] = '\0';
//	for (int i = 0; i < 20; i++)
//		printf("%d ", str3[i]);
//	printf("\n");
//	//-----------------
//	//문자열 비교  strcmp(저장주소1 , 저장주소2)
//	//-----------------
//	if (strcmp(str1, str3) == 0) //두문자열 같으면 0반환 / 다르면 0아닌값 반환 
//	{
//		printf("두 문자열이 같습니다");
//	}
//	else
//	{
//		printf("두 문자열이 다릅니다");
//	}
//	return 0;
//}


//--------------------------
// 입력되는 데이터의 크기만큼 공간 할당 
//--------------------------

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int main()
//{
//	char buff[1024] = { 0 };	// 입력된 문자열 임시 보관 배열
//	int len = 0;				// \n을 제거하기 위한 용도 idx 저장
//	char * name;				// 이름이 저장될 동적공간 바인딩용 포인터변수
//	char * addr;				// 주소가 저장될 동적공간 바인딩용 포인터변수
//
//	printf("이름 : ");
//	fgets(buff, sizeof(buff), stdin);	//키보드로부터 입력된 문자열을 buff크기만큼 buff배열에 저장
//
//	// \n 제거
//	len = strlen(buff) - 1;				//buff안의 \n 의 위치idx 를 len 저장
//	buff[len] = '\0';					//len idx(\n의 위치)에 \0 를 저장
//
//	//입력된 이름크기만큼 동적할당 
//	name = (char *)malloc(sizeof(char)*(len + 1));	// len + 1 의 1은 \0가 저장될 공간을 추가하는 작업
//													// char를 배열요소 크기로 해서 len+1 길이의 배열을동적할당
//													// 시작주소를 name포인터변수에 저장
//	//동적할당 성공 여부 체크
//	if (name == NULL)
//	{
//		printf("동적할당 실패");
//		exit(1);
//	}
//
//	//문자열 복사
//	strcpy_s(name, _msize(name), buff);
//
//	printf("이름 : %s\n", name);
//	printf("이름이 저장된 공간의 크기 : %d\n", _msize(name));
//
//	//주소 입력받기
//	printf("주소입력 : ");
//	fgets(buff, sizeof(buff), stdin);
//	
//	//개행 제거 작업
//	len = strlen(buff) - 1; // \n의 idx가 len에 저장
//	buff[len] = '\0';		// \n -> \0 교체
//
//	//저장된 문자열의 크기만큼 동적할당
//	addr = (char *)malloc(sizeof(char)*(len + 1));
//	if (addr == NULL)
//	{
//		printf("동적할당실패!!");
//		exit(1);
//	}
//
//	strcpy_s(addr, _msize(addr), buff);
//	printf("저장된 주소 : %s\n", addr);
//	printf("저장된 주소의 크기 : %d\n", _msize(addr));
//
//	return 0;
//}



//--------------------------
// 구조체 기본 
//--------------------------


//1) 구조체 기본 예제

//#include <stdio.h>
//
//typedef struct person {
//	char name[30];
//	int age;
//	float weight;
//	double height;
//}Person;
//int main()
//{
//	//구조체 기본
//	struct person Lee = { "이지성",35,67.5,177.5 };
//	printf("%s %d %f %lf\n", Lee.name, Lee.age, Lee.weight, Lee.height);
//
//	//typedef 사용
//	Person Kim = { "김상중",40,77.7, 177.5 };
//	printf("%s %d %f %lf\n", Kim.name, Kim.age, Kim.weight, Kim.height);
//
//	//구조체 배열
//	Person empolyee[3] = {
//		{"홍길동",50,56.6,188.8},
//		{"남길동",60,60.6,188.8},
//		{"서길동",70,65.6,180.2}
//	};
//	for(int i=0;i<3;i++)
//		printf("%s %d %f %lf\n", empolyee[i].name, empolyee[i].age, empolyee[i].weight, empolyee[i].height);
//	
//	//구조체 포인터 
//	Person *ptr = &Kim;		//포인터로 구조체 변수에 접근
//	
//	printf("%s\n", ptr->name);	//kim의 name멤버에 접근
//	printf("%d\n", ptr->age);		//kim의 age멤버에 접근
//	printf("%f\n", ptr->weight);	//kim의 weight멤버에 접근
//	printf("%lf\n",ptr->height);	//kim의 height멤버에 접근
//
//	return 0;
//}

//2) 구조체 사용시 주의 할 점

//#include <stdio.h>
//typedef struct person
//{
//	char name[30];
//	int age;
//}Person;
//
//int main()
//{
//	Person Lee = { "이지성",29};		//구조체변수 생성과 동시에 초기화 
//
//	Person Kim;			//구조체변수를 정의(공간형성)..초기값은 미지정
//
//	Kim.age = 50;
//	//Kim.name = "김길중";	//[문제] 이부분에서 컴파일 에러가 뜨는이유는??? 배열의 이름은 포인터 상수다
//							// 상수안의 값은 다른값으로 변경 불가
//							// strcpy_s()로 문자열 복사를 통해서 값 저장한다
//	strcpy_s(Kim.name, sizeof(Kim.name), "김길중");
//
//	return 0;
//}


//3) 자기참조 구조체

//#include <stdio.h>
//
//typedef struct person {
//	char name[30];			//이름저장용 배열 
//	struct person *next;	//자기참조 포인터
//}Person;
//
//int main()
//{
//
//	//구조체간 연결 
//	Person Jung = { "정우균",NULL };
//	Person Lee = { "이지성",&Jung };
//	Person Kim = { "김상중", &Lee };
//	Person * L = &Kim;
//
//	//L포인터로 각 구조체 안의 멤버중 이름에 접근
//	printf("%s\n", L->name);		//김상중
//	printf("%s\n", L->next->name);  //이지성
//	printf("%s\n", L->next->next->name); //정우균
//
//	//반복문을 통해 연결된 구조체에 접근(★★★)
//	Person * cur = L;
//	while (cur != NULL)
//	{
//		printf("%s\n", cur->name);	//cur포인터가 가리키는 곳의 name 출력 
//		cur = cur->next;			//다음구조체노드로 이동 코드
//	}
//
//
//	return 0;
//}





//--------------------------
// 동적할당 + 포인터 + 구조체 
//--------------------------

//#include <stdio.h>
//
//typedef struct person {
//	char name[20];	// 구조체 멤버 공간에 name저장
//	char *addr;		// 상수pool에 저장된 문자열의 주소를 담는 포인터
//	struct person *next;
//}Person;
//int main()
//{
//	Person * node = (Person *)malloc(sizeof(Person));
//	if (node == NULL)
//	{
//		printf("동적실패!");
//		exit(1);
//	}
//
//	//node->name = "정우균"; X		//node->name은 배열이름, 배열이름은 포이터 상수이므로 다른주소를
//									//담을수없다!!
//	strcpy_s(node->name, sizeof(node->name), "정우균");
//	node->addr = "대구광역시 달서구 갈밭남로~";	//o addr은 node구조체의 멤버포인터'변수!!'이다
//												//값의 변경가능하므로 문자열상수의 주소를담을수있다!
//	node->next = NULL;
//
//	node->next=(Person *)malloc(sizeof(Person));
//
//	strcpy(node->next->name, sizeof(node->next->name), "김상중");
//	node->next->addr = "서울특별시 ~~";
//	node->next->next = NULL;
//
//	return 0;
//}

//--------------------------
//// 문제
//--------------------------
// 도서 정보 구조체를 참조하여  각 데이터를 담는 구조체를 동적할당하여 생성한 뒤
// 각 동적할당된 구조체변수를 먼저 생성된 순으로 연결해봅니다
// 그리고 연결된 구조체 변수를 반복문을 통해서 차례대로 출력해봅니다

//#include <stdio.h>
//
//typedef struct bookinfo {
//	int bookCode;
//	char bookName[30];
//	struct bookinfo * next;
//}BookInfo;
//
//int main()
//{
//	BookInfo * L;  // 제일 첫노드(bookInfo구조체변수)의 주소를 담는 포인터 변수
//
//	//첫노드에 동적할당한 구조체 변수의 시작주소를 저장
//	L = (BookInfo *)malloc(sizeof(BookInfo));
//	if (L == NULL)
//	{
//		printf("동적할당 실패!");
//		exit(1);
//	}
//	//첫노드에 각각 bookCode = 1010 , bookName배열에  "윤성우의열혈C" 를 저장
//	L->bookCode = 1010;
//	strcpy_s(L->bookName, sizeof(L->bookName), "윤성우의열혈C");
//	//첫노드의 next포인터에 NULL값 초기화
//	L->next = NULL;
//
//	//두번째노드 동적할당 하면서 그주소를 첫노드의 next에 저장
//	L->next = (BookInfo *)malloc(sizeof(BookInfo));
//	if (L->next == NULL)
//	{
//		printf("동적할당 실패!");
//		exit(1);
//	}
//	//두번째노드의 bookCode = 2020 , bookName배열에 "이것이리눅스다"를 저장
//	L->next->bookCode = 2020;
//	strcpy_s(L->next->bookName, sizeof(L->next->bookName), "이것이리눅스다");
//
//	//두번재노드의 next포인터에는 NULL값 저장 
//	L->next->next = NULL;
//
//	return 0;
//}
























































































































