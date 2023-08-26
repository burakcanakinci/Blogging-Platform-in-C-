#include<malloc.h>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef unsigned int HANDLE;
#define MAX_COUNT 5
#define BUF_SIZE 1024
enum NUM {
	ROCK,
	SCISSORS,
	PAPER
};
typedef struct HandleTournaData* p_Data;
typedef struct HandleTournaData {
	HANDLE h;
	char* p_string;

	int num_result;
	enum NUM enum_result;
	void* p;
}Data;
class HandleTournaManager {
private:
	unsigned int m_len;
	unsigned int m_max_count;
	p_Data mp_data;//포인터배열
	char* const apointer_string[MAX_COUNT];
public:
	HandleTournaManager();
	~HandleTournaManager();
	void Init();
	HANDLE SetString(const char * ap_string);
};
HandleTournaManager::HandleTournaManager() {
	//사용자가 들어오는 만큼 계속 생성(<m_max_count인덱스)
	Init();
}
void HandleTournaManager::Init() {
	m_max_count = MAX_COUNT;
	//포인터배열에서 마지막 노드를 찾기위해(mp_data[마지막노드]->h==0)
	//
}
HANDLE HandleTournaManager::SetString(const char* ap_string)
{
	m_len = strlen(ap_string) + 1;
	HandleTournaData* p = mp_data;//구조체 포인터배열 첫번째 원소와 
	//마치 연결리스트 삽입처럼 헤드포인터이용해서 마지막 노드 찾는 것을 위해
	//p라는 변수를 도입
	//위의 내용은 아래와 동일
	/*
	* HandleTournaData * p;
	* p = mp_data;
	*/
	unsigned int i;
	for (i = 0; i < m_max_count; i++) {
		if (p->h == 0)	break;
		else p++;
	}
	if (i < m_max_count) {
		p->
	}

	return 0xFFFFFFFF;
}
int GetMyString(char buffer[], int limit)//사용자로부터 횟수제한해서 문자열입력받기
{
	int i;
	for (i = 0; i < limit; i++) {
		buffer[i] = getchar();
		if (buffer[i] == '\n') {
			buffer[i] = 0;
			return 1;
		}
	}
	buffer[i] = 0;
	rewind(stdin);
	return 0;
}
int main(int argc, char* argv[])
{
	HandleTournaManager obj1;
	HandleTournaManager obj2;
	HandleTournaManager obj3;
	int state;
	char input[BUF_SIZE];
	while (1) {
		fputs("For exit (q or Q) : ", stdout);
		fgets(input, BUF_SIZE, stdin);
		if (strcmp(input, "q\n") || strcmp(input, "Q\n"))
			break;
		rewind(stdin);
		state = GetMyString(input, 1023);

		if (state == -1)	printf("your input is : %s\n", input);
		else
		{
			printf("your input was interrupted : %s => 문자열길이를 조금만 줄여주세용!\n", input);
		}
	}
	return 0;
}