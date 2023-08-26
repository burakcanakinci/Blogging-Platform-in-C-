#include<stdio.h>
#include<string.h>

#define MAX_COUNT 2;
typedef char NAME_TYPE[14];

void SetName(NAME_TYPE* p, int count) {//시작주소와 총 학생수, char (*p)[14]와 동일
	const char* ptr = "홍길동";
	const char arr[14] = "김연아";
	strcpy_s(*(p + 0), strlen(ptr) + 1, ptr);
	strcpy_s(*(p + 1), 14, arr);

	for (int i = 0; i < count; i++) {
		printf("%s\n", *(p + i) + 0);
	}
}//p가 배열 포인터(char (*p)[14])
//2차원 배열 arr
int main()
{
	NAME_TYPE Name_2DArray[2];//char Name_2DArray[2][14];
	NAME_TYPE* p;//char (*p)[14];
	p = Name_2DArray;

	const char* ptr = "홍길동";
	const char arr[14] = "김연아";
	strcpy_s(*(p + 0),strlen(ptr)+1, ptr);
	strcpy_s(*(p + 1), 14, arr);

	SetName((p+0), 2);//SetName의 p변수에 보내는 배열의 MAX_LEN이 14여야해 왜냐면 매개변수 p가 그림처럼 *(p+0)+0을 가리켜야 해
	//char (*p)[14] = Name_2DArray;//p가 Name_2DArray의 첫 번째 1차원 배열의 시작주소에 주소연산자 붙인 메모리주소임
	return 0;
}