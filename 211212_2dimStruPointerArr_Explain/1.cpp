#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef unsigned int HANDLE;
typedef struct HandleData {
	HANDLE h;
	char* p_string;
}HandleData;
class HandleUsers {
private:
	char** pp;
	unsigned int m_gen_value;
	unsigned int m_max_user_cnt, m_max_count;
	HandleData** mp_users;
public:
	HandleUsers(unsigned int a_max_user_cnt = 8, unsigned int a_max_count = 8) {
		m_max_user_cnt = a_max_user_cnt;
		m_max_count = a_max_count;
		mp_users = new HandleData * [m_max_user_cnt];
		for (unsigned int j = 0; j < m_max_user_cnt; j++)
			*(mp_users + j) = new HandleData[m_max_count];
		for (unsigned int j = 0; j < m_max_user_cnt; j++)
			memset(*(mp_users + j), 0, sizeof(HandleData) * m_max_count);
		m_gen_value = 1;
	}
	~HandleUsers() {
		HandleData* p_handle = mp_users[0];
		for (unsigned int j = 0; j < m_max_user_cnt; j++) {
			p_handle = &mp_users[j][0];
			/*포인터 변수는 주소연산을 포인터 변수의 자료형으로 하고*/
			/*HandleData*가 자료형이라 구조체변수크기만큼 증가*/
			/*#포인터변수주소연산*/
			for (unsigned int i = 0; i < m_max_count; i++) {
				if (p_handle != NULL) {
					delete[] p_handle->p_string;
					p_handle++;
				}
			}
			delete[] mp_users[j];
		}
		delete mp_users;
	}
	HANDLE SetString(const char* ap_string)
	{
		int len = strlen(ap_string) + 1;
		HandleData* p_handle = mp_users[0];
		//HandleData* p_handle = &mp_users[0][0];과 동일
		//포인터배열의 구조는 배열의 구조와 동일하므로
		//mp_users[0]은 mp_users[0]배열의 첫번째원소의 주소를 가리키는 변수
		for (unsigned int j = 0; j < m_max_user_cnt; j++) {
			p_handle = &mp_users[j][0];
			for (unsigned int i = 0; i < m_max_count; i++) {
				while (p_handle->h) {
					p_handle++;
				}
				p_handle->p_string = new char[len];
				memcpy(p_handle->p_string, ap_string, len);
				p_handle->h = m_gen_value++;
				printf("SetString함수에서 저장합니다: %s,핸들값: %u\n", p_handle->p_string, p_handle->h);
				return p_handle->h;
			}
			/*j를 증가시킨뒤(return안되면바깥for문 실행해서 
			p_handle = &mp_users[j++][0];을 이 위치에서 수행한 것과 동일
			이렇게 j를 증가시킨뒤에 안쪽 for문 다시 반복*/
			for (unsigned int i = 0; i < m_max_count; i++) {
				while (p_handle->h) {
					p_handle++;
				}
				p_handle->p_string = new char[len];
				memcpy(p_handle->p_string, ap_string, len);
				p_handle->h = m_gen_value++;
				printf("SetString함수에서 저장합니다: %s,핸들값: %u\n", p_handle->p_string, p_handle->h);
				return p_handle->h;
			}
			/*여기도 return이 있으므로 j를 증가시키고(return안되면
			바깥for문 실행해서 p_handle = &mp_users[j++][0];을 
			이 위치에서 수행한 것과 동일
			이렇게 j를 증가시킨뒤에 안쪽 for문 다시반복*/
			printf("아직 증가할 사용자가 남았습니다\n");
			for (unsigned int i = 0; i < m_max_count; i++) {
				while (p_handle->h) {
					p_handle++;
				}
				p_handle->p_string = new char[len];
				memcpy(p_handle->p_string, ap_string, len);
				p_handle->h = m_gen_value++;
				printf("SetString함수에서 저장합니다: %s,핸들값: %u\n", p_handle->p_string, p_handle->h);
				return p_handle->h;
			}
			/*방금return이가능했다면 아래의 사용자수 넘은 처리해주면되서 더이상코드안씀*/
			
		}
		printf("사용자 수가 넘었습니다. 함수를 종료합니다\n");
		return 0xFFFFFFFF;
	}
	void ShowString(HANDLE h_str)
	{

	}
};
int main(void)
{
	HandleUsers users_lists(2,1);
	const char* ap_string = "안녕하세요~";
	/*다양한 문자열 입력 예시와 realloc과 malloc을 입력받은 문자열 매개변수로 들어온 것의 길이가 더길면
	realloc하는 것에 대한 예시를 보여드리고자 아래에서 구분선 내의 내용을 작성했습니다*/
	/*구분선 밖의 내용만으로도 충분히 실행가능합니다*/
	/*-----------------------------------------------------*/
	char* ap_string_1 = NULL;
	char* message = NULL;
	const int MAX_LEN = 100;
	int len;
	char aArr_string_1[MAX_LEN] = { 0, };
	puts("입력해주세요~:");
	if (scanf_s("%s", aArr_string_1, MAX_LEN) == 0) {
		fprintf(stderr, "Please input string");
		exit(EXIT_FAILURE);
	}
	int totalsize = 0;
	len = strlen(aArr_string_1) + 1;

	if (ap_string_1 != NULL) {
		totalsize += len;/*여기서는 의미가 안 보이지만 realloc의 의미를 명확히 하고자 변수 한개 더 선언했습니다*/
		ap_string_1 = (char*)realloc(ap_string_1, totalsize);
		memcpy(ap_string_1, aArr_string_1, totalsize);
	}
	else {
		ap_string_1 = (char*)malloc(MAX_LEN);
		memcpy(ap_string_1, aArr_string_1, len);
		printf("%s : 동적메모리할당\n", ap_string_1);
	}
	/*-----------------------------------------------------*/
	HANDLE h_user1_str1 = users_lists.SetString(ap_string);
	char aArr_string[MAX_LEN] = "반갑습니다~";
	ap_string = aArr_string;
	HANDLE h_user2_str1 = users_lists.SetString(ap_string);
	strcpy_s(aArr_string, 16, "또뵙겠습니다아~");
	ap_string = aArr_string;
	HANDLE h_error = users_lists.SetString(ap_string);
	if(ap_string_1)	free(ap_string_1);
	/*const char포인터형의 변수는 동적메모리할당하지 않아도 됩니다!이유는 모르지만 이때까지 경험상 그래왔기 때문입니다*/
	return 0;
}