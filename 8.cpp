#include<stdio.h>
#include<string.h>
#include "UserInformation.h"


int main()
{
	const int count = 5;
	UI u[count] = { {"홍", 23} ,{"희", 22} ,{"길", 21} ,{"김", 20} ,{"설", 25}};
	ArrangeMemberByAGE(&u[0], count);
	//구조체변수도 일반변수도 동일하다
	//따라서 구조체 배열도 기본 자료형의 배열과 완전히 동일하다
	SetMoney(u, 19, 0);
	
	return 0;
}