//다차원배열 매개변수 c언어
#include<string.h>
#include<stdio.h>
void GetMyString(char(*p)[3]);
int main(void)
{
	char arr[2][3] = { {'h', 'i', 0},"ku"};
	GetMyString(arr);
}
void GetMyString(char(*p)[3])
{
	char arr_copy[3];
	strcpy_s(arr_copy, 3, *(p+0));
	fputs(arr_copy, stdout);
	fputc('\n', stdout);
	fflush(stdout);
	strcpy_s(arr_copy, 3, *(p+1));
	/*이렇게 널문자제외하고 문자열길이만큼만 복사한뒤
	널문자를 printf할때는 꼭 해주어야 하므로 printf하기전에 
	널문자를 넣어주는 방식으로 하면 에러가 나는데 이유를 모르겠습니다
	*/
	/*
	strcpy_s(arr_copy, 2, *(p+1));
	int len= strlen(*(p+1));
	arr_copy[len] = 0;
	*/
	fputs(arr_copy, stdout);
	fflush(stdout);
}