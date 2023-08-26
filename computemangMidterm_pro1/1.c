#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef unsigned int HANDLE;
typedef struct HandleData {
	HANDLE h;
	char* p_string;
}HandleData;
HANDLE SetString(HandleData** mp_users, unsigned int m_max_user_cnt, unsigned int m_max_count, unsigned int m_gen_value, const char* ap_string);
void printString(HandleData** mp_users, unsigned int m_max_user_cnt, unsigned int m_max_count, HANDLE h_str);
int main(int argc, char* argv[])
{
	unsigned int m_max_user_cnt, m_max_count;
	unsigned m_gen_value;
	printf("최대 몇 명의 user를, 최대 몇 개의 문자열을 각 user에?:");
	scanf("%d %d", &m_max_user_cnt, &m_max_count);
	//cpp
	//HandleManager str_user_lists(max_user_cnt, max_count);
	//c
	//메모리동적할당및 필요한 변수 초기화 및 2차원구조체포인터배열초기화 및 SetString함수
	//메모리동적할당및 필요한 변수 초기화 및 2차원구조체포인터배열초기화
	m_gen_value = 1;
	HandleData** mp_users = (HandleData**)malloc(sizeof(HandleData*) * m_max_user_cnt);
	for (unsigned int j = 0; j < m_max_user_cnt; j++) {
		mp_users[j] = (HandleData*)malloc(sizeof(HandleData)*m_max_count);
	}
	for (unsigned int j = 0; j < m_max_user_cnt; j++) {
		memset(mp_users[j], 0, sizeof(HandleData) * m_max_count);
	}
	//SetString함수
	const char* ap_string = "안녕하세요";
	//HANDLE SetString(HandleData**mp_users,unsigned int m_max_user_cnt, unsigned int m_max_count,unsigned int m_gen_value, const char* ap_string)매개변수에 보내줘야 할 것들
	HANDLE h_user1_str1 = SetString(mp_users, m_max_user_cnt, m_max_count,m_gen_value, ap_string);
	//void printString(HandleData * *mp_users, unsigned int m_max_user_cnt, unsigned int m_max_count, HANDLE h_str);매개변수로 보내줘야 할 것들
	printString(mp_users, m_max_user_cnt,m_max_count, h_user1_str1);

	//메모리해제
	HandleData* p_handle = mp_users[0];
	for (unsigned int j = 0; j < m_max_user_cnt; j++) {
		p_handle = &mp_users[j][0];
		for (unsigned int i = 0; i < m_max_count; i++) {
			if (p_handle->h) {
				free(p_handle->p_string);
				p_handle++;//sizeof(HandleData)만큼 증가
			}
		}
		free(mp_users[j]);
	}
	free(mp_users);
	
	return 0;
}
HANDLE SetString(HandleData**mp_users,unsigned int m_max_user_cnt, unsigned int m_max_count,unsigned int m_gen_value, const char* ap_string)
{
	int len = strlen(ap_string) + 1;
	HandleData* p_handle = &mp_users[0][0];
	unsigned int j = 0;
	for (; j < m_max_user_cnt; j++) {
		p_handle = &mp_users[j][0];
		//비어있는거찾기
		unsigned int i = 0;
		for (i = 0; i < m_max_count; i++) {
			if (p_handle->h)	break;
			else {
				p_handle++;

			}
		}
		if (i < m_max_count) {
			p_handle->p_string = (char*)malloc(sizeof(char)*len);
			memcpy(p_handle->p_string, ap_string, len);
			printf("%d 번째 user의 %d번째 말입니다\n", j, i);
			p_handle->h = m_gen_value++;
			return p_handle->h;
		}
		else if (j < m_max_user_cnt) {
			p_handle = &mp_users[j++][0];
			//혹은 p_handle = mp_users[j++];
			for (i = 0; i < m_max_count; i++) {
				if (p_handle->h == 0)	break;
				else {
					p_handle++;

				}
			}
			if (i < m_max_count) {
				p_handle->p_string =(char*)malloc(sizeof(char)*len);
				memcpy(p_handle->p_string, ap_string, len);
				printf("%d 번째 user의 %d번째 말입니다\n", j, i);
				p_handle->h = m_gen_value++;
				return p_handle->h;
			}
			else {
				printf("아직증가할사용자가 남아있습니다\n");
				p_handle = &mp_users[j++][0];
				for (i = 0; i < m_max_count; i++) {
					if (p_handle->h)	break;
					else {
						p_handle++;

					}
				}
				if (i < m_max_count) {
					p_handle->p_string=(char*)malloc(sizeof(char)*len);
					memcpy(p_handle->p_string, ap_string, len);
					printf("%d 번째 user의 %d번째 말입니다\n", j, i);
					p_handle->h = m_gen_value++;
					return p_handle->h;
				}
			}
		}
		else {
			printf("지정해주신 사용자수가 넘었습니다\n");
			return 0xFFFFFFFF;
		}
	}
}
void printString(HandleData** mp_users, unsigned int m_max_user_cnt, unsigned int m_max_count, HANDLE h_str)
{
	HandleData* p_handle = &mp_users[0][0];
	for (unsigned int j = 0; j < m_max_user_cnt; j++) {
		p_handle = &mp_users[j][0];
		for (unsigned int i = 0; i < m_max_count; i++) {
			if (p_handle->h == h_str) {
				printf("%s : 요청하신 문자열입니다\n", p_handle->p_string);
				return;
			}
			else if (i < m_max_count) {
				p_handle++;

			}
		}
	}
	printf("요청하신 메모리주소가 없습니다\n");
}
