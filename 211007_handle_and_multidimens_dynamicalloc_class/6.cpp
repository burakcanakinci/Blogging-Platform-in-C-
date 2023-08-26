#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef int HANDLE;
#define MAX_COUNT 1024
struct HandleData {
	HANDLE h;
	char* p_string;
};
class HandleManager{
private:
	HandleData** pp_data;
	unsigned int m_len, m_max_len;

	unsigned int m_gen_value;
	HandleData* mp_data;
	unsigned int m_max_count;

	/*실험용-c언어: 1차원 동적할당, 재할당이용*/
	char* mp_string;
	unsigned int m_str_len, m_str_max_len=1;

	/*[Q&A,Quiz]-cpp언어: 2차원 동적할당이용*/
	char** pp_string;
	unsigned int m_str_two_len, m_str_max_two_len = 1;

public:
	HandleManager(unsigned int a_max_count =50){
		m_gen_value = 1;
		m_max_count = a_max_count;
		pp_data = (HandleData**)malloc(sizeof(HandleData) * m_max_count);

		InitString();

	}
	~HandleManager() {
		HandleData* p = mp_data;
		for (int i = 0; i < m_max_count; i++) {
			if (p->h) {
				delete[] p->p_string;
			}
			p++;
		}
		delete[] mp_data;

		DeleteString();
	}
	HANDLE InsertData(const char* ap_string) {
		m_len = strlen(ap_string) + 1;
		mp_data = new HandleData[m_max_count];
		memcpy(mp_data, 0, sizeof(HandleData)* m_max_count);
		HandleData* p = mp_data;
		unsigned int i;
		for (i= 0; i < m_max_count; i++) {
			if (p->h == 0)	break;
			else
			{
				p++;
			}
		}
		if (i<m_max_count) {
			strcpy_s(p->p_string, strlen(ap_string)+1, ap_string);
			cout << p->p_string << ": 문자열 추가" << endl;
			p->h = m_gen_value++;
			return p->h;
		}
		return 0xFFFFFFFF;
	}
	void printData(HANDLE h_str)
	{
		HandleData* p = mp_data;
		for (unsigned int i = 0; i < m_max_count; i++) {
			if (p->h) {
				cout << p->p_string << ": 삭제" << endl;
				delete[] p->p_string;
			}
			p++;
		}
		cout << "일치하는 메모리 주소를 찾지 못했습니다" << endl;
	}
	void DeleteData(HANDLE h_str) {

	}
	/*실험용: c언어 -1차원 동적할당,재할당이용*/
	void InitString()
	{
		mp_string = (char*)malloc(2);
		strcpy_s(mp_string, 2, "a");
	}
	void SetString(const char* ap_string)
	{
		m_str_len = strlen(ap_string)+1;
		if (m_str_max_len < m_str_len) {
			m_str_max_len = m_str_len;
			free(mp_string);
			mp_string = (char*)malloc(m_str_max_len);
		}
		memcpy(mp_string, ap_string, m_str_max_len);
	}
	char* method1(const char* ap) {
		char arr[MAX_COUNT];
		for (int i = 0; i < strlen(ap) + 1; i++)
			arr[i] = *(ap + i);
		//혹은
		//memcpy(arr, ap, strlen(ap)+1);
		char(*ptr)[MAX_COUNT];
		ptr = &arr;
		return *ptr;
	}
	void InsertString(const char* ins, int index)
	{
		char ori[29] = { 0, };//9+19+1(널문자용) = 29
		char* p = (char*)malloc(29);
		p=method1(mp_string);
		strcpy_s(ori, strlen(p) + 1, p);
		cout << ori << ": ori" << endl;
		char temp_left[10] = { 0, };//9글자+1(널문자삽입용)
		char temp_right[20] = { 0, };//19글자+1(널문자삽입용)
		int total_size = m_str_max_len;
		char* message = (char*)malloc(10);
		for (int i = 0; i < index; i++) {
			temp_left[i] = ori[i];
			if (i == index - 1)	temp_left[i] = 0;
		}
		for (int i = index; i < m_str_max_len; i++) {
			temp_right[i - index] = ori[i];
			if (i == m_str_max_len - 1)	temp_right[i] = 0;
		}
		strcpy_s(message, 10, temp_left);
		total_size += strlen(ins);
		message = (char*)realloc(message, total_size);
		strcat_s(message, total_size, ins);
		total_size += strlen(temp_right);
		strcat_s(message, total_size, temp_right);
		cout << message << ": message" << endl;

	}
	void DeleteString()
	{
		free(mp_string);
	}
	/*실험용: 1차원동적할당 cpp용*/
	/*1차원 동적할당 cpp용을 new와 delete연산자를 써서 구현*/
	void SetString_cpp(const char* ap_string)
	{
		SetString(ap_string);//1차원 동적할당 c언어용과 동일
	}
	void InsertString_cpp(const char* ins, int index)
	{
		char ori[29] = { 0, };
		char temp_left[10] = { 0, };
		char temp_right[20] = { 0, };
		char* p = new char[29];
		p = method1(mp_string);
		//배열포인터인 p를 배열로 복사
		strcpy_s(ori, strlen(p) + 1, p);
		cout << ori << ": ori" << endl;
		int toal_size = m_str_max_len;
		char* message = new char[10];
		for (int i = 0; i < index; i++) {
			temp_left[i] = ori[i];
			if (i == index - 1)	temp_left[i] = 0;
		}
		strcpy_s(message, 10, temp_left);
		int total_size = strlen(temp_left)+1;
		total_size += strlen(ins);
		strcat_s(message, total_size, ins);
		total_size += strlen(temp_right);
		strcat_s(message, total_size, temp_right);
		cout << message << ": message" << endl;

	}
	/*[Q&A,Quiz] 2차원동적메모리할당-cpp용*/
	void SetString_two_cpp(unsigned int a_str_max_two_count = 50)
	{
		m_str_max_two_len = a_str_max_two_count;
		pp_string = new char* [m_str_max_two_len];//포인터배열 할당
		for (unsigned int i = 0; i < m_str_max_two_len; i++) {
			*(pp_string + i) = new char[MAX_COUNT];
		}
	}
	void DeleteString_two_cpp()
	{
		for (unsigned int i = 0; i < m_str_max_two_len; i++)
			delete[] * (pp_string + i);
		delete[] pp_string;
	}
};

int GetMyString(char buffer[], int limit)
{
	int i;
	if (buffer != NULL)	rewind(stdin);
	for (i = 0; i < limit; i++) {
		buffer[i] = getchar();
		if (buffer[i] == '\n') {
			buffer[i] = 0;
			cout << buffer << " is your input" << endl;
			break;
		}
	}
	if (i < limit)	return 1;
	//양수표현범위에서 1을 더하면 비트연산으로 1을 더하는 것이므로
	//비트가 다음 최상위비트가 1이 되고 나머지는 모두 0으로 되므로
	//그리고 이는 양수, 음수전환과 동일한 효과를 가져오기에
	//음수 최솟값은 최상위 부호비트 1제외하고 모두 0이고
	//거기서 비트값이 1씩 증가할 수록(이 원리는 양수와 동일하게 1씩 증가)
	//값이 더해지면서 음수 최댓값(점점 커지는 쪽, 즉, -1로 가는 쪽)이 된다
	buffer[i] = 0;
	cout << buffer << ": your buffer is out of range" << endl;
	rewind(stdin);
	return 0x7FFFFFFF+1;//최상위 1비트 부호비트
	//최상위 비트는 0으로 부호비트이고 따라서 0111로 2^3-1=7
	//= 2^24*(2^7-1)+2^16*(2^8-1)+2^8*(2^8-1)+ 2^8-1
	//= 0x7FFFFFFF
	//= 2,147,483,647(long int 최댓값)
	//= 2^24*(2^8-1)+2^16*(2^8-1)+2^8*(2^8-1)+ 2^8-1
	// =0xFFFFFFFF
	//= 4,294,967,295(unsigned long int 최댓값)
}
int main(void)
{
	HandleManager str_list;
	str_list.InsertData("안녕하세요~");
	char buffer[2];
	int status = GetMyString(buffer, 1);
	cout << status << endl;
	return 0;
}