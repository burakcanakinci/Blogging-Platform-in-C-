#include<stdio.h>

//코드 출처: Do it!C언어 입문 20-2장 함수포인터 예제
int Sum(int a, int b)
{
	return a + b;
}
int Sub(int a, int b)
{
	return a - b;
}
int Mul(int a, int b)
{
	return a * b;
}
int Div(int a, int b)
{
	return a / b;
}
//int (*p[4])(int, int) = { &Sum, &Sub, &Mul,&Div };
//위와 동일한 표현을 간결하게 쓸 때
typedef int (*FT_TYPE)(int, int);
FT_TYPE funcPtrArr[4] = { &Sum, &Sub, &Mul,&Div };

int main(void)
{
	int result[4];
	for (int i = 0; i < 4; i++)	result[i] = funcPtrArr[i](6, 3);


	int (*p[4])(int, int)= { &Sum, &Sub, &Mul,&Div };

	FT_TYPE *temp = &p[0];//자신과 같은 차원의 변수를 포인터변수는 가리켜야 합니다.// p가능
	//(즉, p는 2차원이므로 p[0]은 못 가리킵니다)
	for (int i = 0; i < 4; i++) {
		result[i] = (*temp)(6, 3);
		temp++;//포인터변수는 포인터변수의 자료형 == 자신이 가리키는 변수의 자료형 크기만큼 
		//주소연산에서 증가합니다.
	}

	for (int i = 0; i < 4; i++)	printf("%d ",result[i]);

	return 0;
}