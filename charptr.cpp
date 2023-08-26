#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAX_LEN 240

void printnotchangePtr(const char *ap_str)//ap_str = 매개변수에 포인터변수명보냄
{
	printf("%s\n", ap_str);
}
char* printchangeArr(char(*ap_str)[MAX_LEN])
{
	char* temp;//구조체 포인터변수이든 일반변수를 가리키는 포인터 변수이든
	//임시로 생성하는 경우에는 (예시: swapbyreference 함수 혹은 연결리스트 노드삽입함수
	char strawberry[MAX_LEN] = "strawberry";//strcpy_s나 strncpy_s쓸 때는
	//반드시 같은 크기로 (MAX_LEN으로) 배열크기 선언
	temp = strcpy(*ap_str, strawberry);
	return *ap_str;
}
void printnotchangeArr(const char(*ap_str)[MAX_LEN])
{
	//1차원 char형 배열을 매개변수에 보내는 경우 ap_str = &arr1D
	printf("%s\n", *ap_str);
}

int main(void)
{
	//문자열상수로 초기화된 포인터변수와 char형 배열 변수
	//const char* ptr_notchange_str = "banana";
	//printnotchangePtr(ptr_notchange_str);
	//char arr_str[MAX_LEN] = "banana";//배열크기를 MAX_LEN으로 써주지 않으면 안됨
	//printf("%s\n",printchangeArr(&arr_str));
	//char arr_notchange_str[MAX_LEN] = "banana";
	//printnotchangeArr(&arr_notchange_str);

	char arr3D[2][3][5] = { {"hihi", "hehe", "haha"},{"abcd", "efgh"} };
	char(*ptr)[3][5] = arr3D;
	for (unsigned int i = 0; i < 2; i++) {
		for (unsigned int j = 0; j < 3; j++)
			printf("%s\n", *(*(ptr + i) + j) + 0);//printf("%s\n", *(ptr + i) + j);도 동일결과
		printf("\n");
	}
	/*char arr3D[][3][5] = { {"abcd", "efgh", "ijkl"}, {"mnop","qrst", "uvwx"} };
	char arr2D[3][5] = { "abcd", "efgh", "ijkl" };
	char(*ptr)[3][5] = &arr2D;
	for (unsigned int i = 0; i < 3; i++) {
			printf("%s\n", *(*(ptr + 0) + i) + 0);
	}
	ptr = arr3D;
	for (unsigned int i = 0; i < 2; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			printf("%s\n", *(*(ptr+i)+j)+0);
		}
	}*/

	return 0;
}