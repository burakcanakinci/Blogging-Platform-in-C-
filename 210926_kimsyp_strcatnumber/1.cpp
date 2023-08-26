
#include"1.h"
#include"node_struct.h"
#include "gycchang_class.h"

int main(int argc, char* argv[])
{
	/*serv_addr.sin_port = htons(atoi(argv[1]))*/
	char* tmp = (char*)malloc(2);
	node* p_head = NULL, * p_tail = NULL;
	void* const p_tmp = tmp;
	fputs("입력하세요 : ", stdout);
	tmp[0] = getchar();
	rewind(stdin);
	*(int*)p_tmp = atoi(tmp);
	p_node p_node_c;
	p_node_c->InsertNodeHead(&p_head, *(int*)p_tmp);
	p_node_c->DeleteNode(&p_head, &p_tail);

	gycchang data_gyc(1);
	//복사생성자
	gycchang tmp_gyc = data_gyc;
	void* p_tmp_gyc = &tmp_gyc;
	printf("복사생성자만 void** pp를 노드를 삽입하고 보여주고 제거하는 것을 해보겠습니다:\n");
	fflush(stdout);
	((p_node)(*((gycchang*)p_tmp_gyc)->pp))->InsertNodeHead(&p_head, *(int*)p_tmp);
	((p_node)(*((gycchang*)p_tmp_gyc)->pp))->ShowNode(&p_head, &p_tail);
	((p_node)(*((gycchang*)p_tmp_gyc)->pp))->DeleteNode(&p_head, &p_tail);

	printf("이제 원본객체를 함수를 출력해보기:\n");
	data_gyc.SetString("honggildong");
	data_gyc.ShowString();

	printf("이제 복사생성자객체를 함수를 출력해보기:\n");
	((gycchang*)p_tmp_gyc)->SetString("copy_honggildong");
	((gycchang*)p_tmp_gyc)->ShowString();
	return 0;
}