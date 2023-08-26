#include <stdio.h>
#include<string.h>
#define MAX_LEN 12
typedef struct UserInformation UI;
typedef struct UserInformation* P_UI;
struct UserInformation {
	char name[12];
	int age;
};

int main()
{
	UI u[2];
	P_UI p_u[2] = {&u[0], &u[1]};
	//첫번째 요소는 구조체포인터변수이용해서 초기화
	p_u[0]->age = 23;
	const char* ap_str = "홍길동";
	//아래 두 개 모두 가능
	strcpy_s(p_u[0]->name, strlen(ap_str) + 1, "홍길동");
	strcpy_s(p_u[0]->name, strlen(ap_str) + 1, ap_str);
	
	p_u[1]->age = 24;
	const char name[12] = "김연아";
	const char(*ap_str1)[MAX_LEN] = &name;
	strcpy_s(p_u[1]->name, MAX_LEN, *ap_str1);
	
	for(int i=0;i<2;i++)	printf("%d, %s\n", p_u[i]->age, p_u[i]->name);
	
	//다른초기화방법제시
	//반드시 멤버변수 순서대로 초기화해주기
	UI u2[2] = { {"펭수",23}, {"뽀로로", 22} };

	//포인터변수가 가리킬 수 있는 크기를 벗어나더라도(지금은 구조체 변수 1개를 가리키는 구조체 포인터 변수로 한다)
	//주소연산을 이용해서 다음 구조체 변수를 가리킬 수 있도록 한다(이때 구조체멤버정렬이 있어서 각 정렬 바이트 수에 맞추어
	//그 정렬 바이트 수의 배수에 해당하는 주소에서 시작해서 그 정렬 바이트 수의 배수에 해당하는 주소에서 끝나게 되어있기 때문에
	//구조체 변수의 배열의 다음의 원소를 구조체 포인터 변수(하나의 구조체 변수만 가리킬 수 있도록 자료형이 정해져 있음)로 가리킬 수 있다
	P_UI p_u3 = &u2[0];
	//주소연산으로 for문에서 두 원소를 모두 출력한다
	for (int i = 0; i < 2;i++) {
		printf("%d, %s\n", p_u3->age, p_u3->name);
		p_u3++;
	}

	return 0;
}