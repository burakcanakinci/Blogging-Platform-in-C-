#include<iostream>
#include<string.h>//memset strlen strcpy_s
#include<stdlib.h>
#include<malloc.h>
using namespace std;
#define MAX_LEN 240
class HandleManager {
private:
	char** mp_str;
	unsigned int m_max_len=MAX_LEN, m_max_count;
public:
	HandleManager(unsigned int a_max_count = 5) {
		m_max_count = a_max_count;
		mp_str = new char* [m_max_count];
		for (unsigned int i = 0; i < m_max_count; i++) {
			*(mp_str + i) = new char[m_max_len];
		}
		for (unsigned int i = 0; i < m_max_count; i++)
			memset(mp_str[i], 0, sizeof(char));//첫바이트 0(널문자)
	}
	~HandleManager();
	unsigned int SetString(const char* ap_string);

};

HandleManager::~HandleManager() {
	for (unsigned int i = 0; i < m_max_count; i++) {
		delete mp_str[i];
		cout << "mp_str[" << i << "] 동적메모리해제 및 객체소멸완료" << endl;
	}
	delete[] mp_str;

}
unsigned int HandleManager::SetString(const char* ap_string)
{
	int len = strlen(ap_string) + 1;
	char* p;
	p = new char[len];
	strcpy_s(p, len, ap_string);
	cout << p << " : p " << endl;

	unsigned int i;
	char* p_char = mp_str[0];
	for (i = 0; i < m_max_count; i++) {
		if (mp_str[i]) {
			break;
		}
		else
			continue;
	}
	if (i < m_max_count) {
		memcpy(mp_str[i], p, len);
		return 1;
	}
	return 0xFFFFFFFF;
}
int main(void)
{
	HandleManager str_list_users;
	unsigned int list1 = str_list_users.SetString("안녕하세요");
	unsigned int list2 = str_list_users.SetString("저는 누구누구입니다1");
	unsigned int list3 = str_list_users.SetString("저는 누구누구입니다2");
	unsigned int list4 = str_list_users.SetString("저는 누구누구입니다3");
	unsigned int list5 = str_list_users.SetString("저는 누구누구입니다4");
	unsigned int error = str_list_users.SetString("저는 누구누구입니다5");

	cout << list1 << list2 << list3 << list4 << list5 << endl;
	return 0;
}