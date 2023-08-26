#include<string.h>
#include<iostream>

typedef unsigned int HANDLE;

struct HandleData {
	HANDLE h;
	char* p_string;
};
class HandleManager
{
protected:
	char* mp_string;
	int m_max_len, m_len;
	
	HandleData* mp_data;//포인터배열
	unsigned int m_max_count;
public:
	HandleManager()
	{
		Init();
	}
	~HandleManager()
	{
		if (mp_string != NULL)	delete[] mp_string;
	}
	void Init()
	{
		mp_string = (char*)malloc(1);
		strcpy_s(mp_string, 1, "a");
	}
	void SetString(const char* ap_string)
	{
		if (mp_string != NULL)	delete[] mp_string;

		int length = strlen(ap_string) + 1;
		mp_string = new char[length]
	}
};
int main(void)
{
	unsigned int i;

}