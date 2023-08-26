#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node {
	int value;
	node* p_next;
}node, *p_node;
void insertNodeHead(node** pp_head, int data)
{
	node* p;
	if (*pp_head == NULL) {
		p = *pp_head = (p_node)malloc(sizeof(node));
	}
	else {
		p = *pp_head;
		while (p->p_next != NULL) {
			p = p->p_next;
		}
		p->p_next = (p_node)malloc(sizeof(node));
		p = p->p_next;
	}
	p->value = data;
	p->p_next = NULL;
}
void insertNodeTail(node** pp_head, node** pp_tail, int data)
{
	if (*pp_head == NULL) {
		*pp_tail = *pp_head = (p_node)malloc(sizeof(node));

	}
	else {
		(*pp_tail)->p_next = (p_node)malloc(sizeof(node));
		(*pp_tail) = (*pp_tail)->p_next;
	}
	(*pp_tail)->value = data;
	(*pp_tail)->p_next = NULL;
}
void ShowNode(node** pp_head)
{
	int i = 0;
	node* p;
	p = *pp_head;
	while (p) {
		printf("%d: %d번째 node\n", p->value, i++);
		p = p->p_next;
	}
}
void DeleteNodeHead(node** pp_head)
{
	p_node p_temp;
	while (*pp_head) {
		p_temp = (*pp_head)->p_next;
		free(*pp_head);
		*pp_head = p_temp;
	}
}
void DeleteNodeTail(node** pp_head, node** pp_tail)
{
	p_node p_temp;
	while (*pp_head) {
		p_temp = (*pp_head)->p_next;
		free(*pp_head);
		*pp_head = p_temp;
	}
	//나왔다는 것은 *pp_head가 NULL이므로
	*pp_tail = *pp_head;
}
int main(int argc, char* argv[])
{
	p_node p_head = NULL;
	p_node p_tail = NULL;
	int num;
	while (1)
	{
		printf("입력해주세요:(999를 입력하면 종료) ");
		scanf_s("%d", &num);
		if (num != 999) {
			//insertNodeHead(&p_head, num);
			insertNodeTail(&p_head, &p_tail, num);
		}
		else {
			break;
		}
	}
	ShowNode(&p_head);
	if(p_tail==NULL)	DeleteNodeHead(&p_head);
	else
	{
		DeleteNodeTail(&p_head, &p_tail);
	}

	return 0;
}