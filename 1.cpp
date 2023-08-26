#include<stdio.h>
#include<malloc.h>

struct NODE {
	int data;
	NODE* p_next;
};

class node {
private:
	NODE* mp_head;
	NODE* mp_tail;
	static int m_data;//몇 번째 객체인지 알 수 있도록 코드 작성을 해보면(생성자함수에서)
public:
	node();
	~node();
	void insertNode()
	{
		int num;
		while (1) {
			printf("입력을 종료하려면 999를 입력해주세요: ");
			scanf_s("%d", &num);
			if (num != 999) {
				if (mp_head)//if(p_head!=NULL)
				{
					mp_tail->p_next = (NODE*)malloc(sizeof(NODE));
					mp_tail = mp_tail->p_next;
				}
				else {
					mp_tail = mp_head = (NODE*)malloc(sizeof(NODE));
				}
				mp_tail->data = num;
				mp_tail->p_next = NULL;
			}
			else
			{
				break;
			}
		}
	}
	//void DeleteNode() // NODE *this;
	void DeleteNode() // NODE* const this;는 아래에서 멤버변수 수정하는 부분에서 에러를 냄.
	{
		NODE* p;
		while (mp_head){//while(mp_head!=NULL)
			p = mp_head->p_next;
			free(mp_head);
			mp_head = p;
		}
	}
	void ShowNode()
	{
		NODE* p;
		int i = 0;
		while (mp_head) {
			printf("%d번째 노드 %d값\n", i++, mp_head->data);
			mp_head = mp_head->p_next;
		}
		//이것도 가능
		/*printf("이렇게도 출력해도 됩니다\n");
		do {
			printf("%d번째 노드 %d값\n", i++, mp_head->data);
		} while (mp_head = mp_head->p_next);*/
	}
};
int node::m_data = 0;//static멤버변수를 전역변수 영역에 초기화해야 한다
node::node() {
	mp_head = mp_tail = NULL;
	m_data++;
	printf("%d번째 증가입니다\n", m_data);
}
node::~node() {
	NODE* p;//p_save_next;
	while (mp_head) {
		p = mp_head->p_next;
		free(mp_head);
		mp_head = p;
	}
}
class tmp {
private:
	static int m_data;
public:
	tmp() {
		changeOtherclassStatic();
	}
	void changeOtherclassStatic() {
		m_data = 5;
	}
};
void insertNodeHead(NODE** pp_head){
	int num;
	NODE* p;
	while (1) {
		printf("입력을 종료하려면 999를 입력해주세요: ");
		scanf_s("%d", &num);
		if (num != 999) {
			if (*pp_head != NULL) {
				p = *pp_head;
				while (p->p_next != NULL)	p = p->p_next;
				p->p_next = (NODE*)malloc(sizeof(NODE));
				p = p->p_next;
			}
			else {
				p = *pp_head = (NODE*)malloc(sizeof(NODE));
			}
			p->data = num;
			p->p_next = NULL;
		}
		else {
			break;
		}
	}
}
void deleteNodeHead(NODE **pp_head, NODE **pp_tail)
{
	NODE* p;//p_save_next;
	while (*pp_head) {
		p = (*pp_head)->p_next;
		free(*pp_head);
		*pp_head = p;
	}
	*pp_tail = *pp_head;
	
}
void deleteNodeNotHead(NODE** pp_head, NODE** pp_tail)
{
	NODE* p=*pp_head, * p_save_next;
	while (NULL != p) {
		p_save_next = p->p_next;//free로 p노드에 저장된 주소의 메모리를 해제하기 전에 p->p_next에 해당하는 노드를 미리 저장해두어야 합니다
		//이유는 free(p);만 하고 다음노드를 가리키게 하면 안되는 이유를 설명한 김성엽님 교재 18장492쪽 혹은 동영상강좌 혹은 tipsware6회강의
		//에서 확인가능하십니다
		free(p);
		p = p_save_next;
	}
	*pp_head = *pp_tail = NULL;//연결리스트의 시작과 끝이 모두 없음을 명시함
}
void insertNodeTail(NODE** pp_head, NODE** pp_tail, int num)
{
	while (1) {
		printf("입력을 종료하려면 999를 입력해주세요: ");
		scanf_s("%d", &num);
		if (num != 999) {
			if (*pp_head)//if(p_head!=NULL)
			{
				(*pp_tail)->p_next = (NODE*)malloc(sizeof(NODE));
				(*pp_tail) = (*pp_tail)->p_next;
			}
			else {
				(*pp_tail) = (*pp_head) = (NODE*)malloc(sizeof(NODE));
			}
			(*pp_tail)->data = num;
			(*pp_tail)->p_next = NULL;
		}
		else
		{
			break;
		}
	}
}
void ShowNode(NODE** pp_head)
{
	NODE* p;
	int i = 0;
	while (*pp_head) {//while(NULL!=*pp_head)
		printf("%d번째 노드 %d값\n", i++, (*pp_head)->data);
		(*pp_head) = (*pp_head)->p_next;
	}
	//이것도 가능
	/*do {
		printf("%d번째 노드 %d값\n", i++, (*pp_head)->data);
	} while ((*pp_head) = (*pp_head)->p_next);*/
}
int main()
{
	//int num;
	//NODE* p_head, * p_tail;
	//p_head = NULL;
	//p_tail = NULL;
	//while (1) {
	//	printf("입력을 종료하려면 999를 입력해주세요: ");
	//	scanf_s("%d", &num);
	//	if (num != 999) {
	//		if (p_head)//if(p_head!=NULL)
	//		{
	//			p_tail->p_next = (NODE*)malloc(sizeof(NODE));
	//			p_tail = p_tail->p_next;
	//		}
	//		else {
	//			p_tail = p_head = (NODE*)malloc(sizeof(NODE));
	//		}
	//		p_tail->data = num;
	//		p_tail->p_next = NULL;
	//	}
	//	else
	//	{
	//		break;
	//	}
	//}
	//NODE* p;
	//int i = 0;
	//while (p_head) {//while(NULL!=p_head)
	//	printf("%d번째 노드 %d값\n", i++, p_head->data);
	//	p_head = p_head->p_next;
	//}
	//
	/*do {
		printf("%d번째 노드 %d값\n", i++, p_head->data);
	} while (p_head = p_head->p_next);*/


	//while (p_head) {
	//	p = (p_head)->p_next;
	//	free(p_head);
	//	p_head = p;
	//}
	//p_tail = p_head;//while문을 나오면 p_head는 NULL포인터이다


	//class 사용한 코드
	node obj1;
	node obj2;
	node obj3;
	obj1.insertNode();
	obj1.ShowNode();
	obj2.insertNode();
	obj2.ShowNode();
	obj3.insertNode();
	obj3.ShowNode();
}