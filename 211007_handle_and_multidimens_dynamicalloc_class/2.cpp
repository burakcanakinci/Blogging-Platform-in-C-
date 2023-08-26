#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
using namespace std;

typedef struct node {
	int value;
	node* p_next;
	node* p_prev;
}node, * p_node;
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
void showNode(node** pp_head)
{
	node* p = *pp_head;
	while (p!= NULL)
	{
		cout << p->value << endl;
		p = p->p_next;
	}
}
void deleteNode(node** pp_head, node** pp_tail)
{
	node* p = *pp_head;
	while (p != NULL) {
		p = (*pp_head)->p_next;
		free(*pp_head);
		*pp_head = p;
	}
	*pp_tail = *pp_head;
}
int main(void)
{
	node* p_head = NULL;
	node *p_tail = NULL;
	int num;
	while (1) {
		printf("데이터를 입력해주세요 : ");
		scanf_s("%d", &num);
		if (num == 999)	break;
		insertNodeHead(&p_head, num);
	}
	showNode(&p_head);

	deleteNode(&p_head, &p_tail);

}