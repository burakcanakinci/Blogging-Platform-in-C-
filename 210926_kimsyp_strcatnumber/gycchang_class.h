#pragma once
#include "node_struct.h"
class gycchang {
public:
	int m_len;
	int m_max_len;
	char* mp_str;
	void* p_node_c;
	node* p_tail;
	node* p_head;
	void* const p = NULL;
	void** pp = NULL;
public:
	gycchang(int type);
	~gycchang();
	void Init(int type);
	void SetString(const char* ap_str);
	void ShowString();
	void Destroy();
};
typedef gycchang gyc;
typedef gycchang* p_gyc;

gycchang::gycchang(int type)
{
	Init(1);
}
void gycchang::Init(int type)
{
	if (type) {
		m_len = m_max_len = 0;
		mp_str = (char*)malloc(1);
		*mp_str = 0;
		p_tail = NULL;
		p_head = NULL;

		((p_node)p_node_c)->InsertNodeHead(&p_head, 3);
		((p_node)p_node_c)->ShowNode(&p_head, &p_tail);
		((p_node)p_node_c)->DeleteNode(&p_head, &p_tail);
		((p_node)p)->InsertNodeHead(&p_head, 3);
		((p_node)p)->ShowNode(&p_head, &p_tail);
		((p_node)p)->DeleteNode(&p_head, &p_tail);
		((p_gyc)(*pp))->m_len = ((p_gyc)(*pp))->m_max_len = 0;
		((p_gyc)(*pp))->mp_str = (char*)malloc(2);
		//아래꺼는 있어도 되고 없어도 되고
		strcpy_s(((p_gyc)(*pp))->mp_str,2,"a");
		//((p_gyc)(*pp))->p_node_c = ((p_node)p);
		((p_gyc)(*pp))->p_node_c = NULL;
		//*(int*)(&((gycchang*)p)->m_len) = 5;생각하기항상
	}

}
//만약 같은 경우엔 continue하고 다른 경우엔 문자열길이(total_size를 더해서) 비교해서 더 긴 경우에만
//클래스의 멤버변수를 동적메모리해제하고 재할당
void gycchang::SetString(const char* ap_str)
{
	m_len = strlen(ap_str);
	if (m_max_len < m_len)	m_max_len = m_len;
	free(mp_str);
	mp_str = (char*)malloc(m_max_len);
	strcpy_s(mp_str, m_max_len, ap_str);
}
void gycchang::ShowString()
{
	fputs(mp_str, stdout);
	rewind(stdin);
}
void gycchang::Destroy()
{
	free(mp_str);
	Init(1);
}
gycchang::~gycchang()
{
	free(mp_str);
}