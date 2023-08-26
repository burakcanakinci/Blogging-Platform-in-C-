#pragma once
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
typedef struct node {
	int data;
	node* p_next;
	void InsertNodeHead(node** pp_head, int data);
	void InsertNodeTail(node** pp_head, node** pp_tail, int data);
	void ShowNode(node** pp_head, node** pp_tail);
	void DeleteNode(node** pp_head, node** pp_tail);
}node, * p_node;
void node::InsertNodeHead(node** pp_head, int data)
{
	node* p;
	if (*pp_head) {//!=NULL
		p = *pp_head;
		while (p->p_next != NULL) {
			p = p->p_next;
		}
		p->p_next = (node*)malloc(sizeof(node));
	}
	else {
		p = *pp_head = (p_node)malloc(sizeof(node));
	}
	p->data = data;
	p->p_next = NULL;
}
void node::ShowNode(node** pp_head, node** pp_tail)
{
	node* p_tmp;
	p_tmp = *pp_head;

}
void node::DeleteNode(node** pp_head, node** pp_tail)
{
	node* p_tmp = NULL;
	while (*pp_head != NULL) {
		p_tmp = (*pp_head)->p_next;
		free(*pp_head);
		*pp_head = p_tmp;
	}
	*pp_tail = *pp_head;
}