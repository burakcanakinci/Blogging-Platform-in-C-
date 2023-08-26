#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#define MAX_BOOK_KIND 1//책 분야 최대 개수(자동화기능시 수정할 부분1)
#define MAX_ONE_CATEGORY 260//사용자에게 입력을 받는 동적할당 코드구현시 없앨 부분1
#define MAX_BOOK_SIZE 1000//사용자에게 입력을 받는 동적할당 코드구현시 없앨 부분2
typedef unsigned int HANDLE;
void error_handling(const char* msg);
typedef struct reg {
	char author[20];//작가
	char company[20];//출판사
}reg;
typedef struct bookInfo {//연결리스트의 원소
	char year[20];//출판년도
	char name[40];//책이름
	reg owner;//작가,출판사
	HANDLE h;//검색,삭제를 위한 핸들값
	bookInfo* p_next;
}bookInfo;
//한 카테고리가 BOOK_TYPE이라는 1차원구조체포인터 자료형에 해당
class Book {
private:
	bookInfo bookInfomation;
public:
	virtual char* GetName() { return NULL; }
	virtual Book* CreateBook() { return NULL; }
	HANDLE SetString(unsigned int ap_book_cout);
};

typedef Book BOOK_TYPE[MAX_ONE_CATEGORY];
class Inmune :public Book {
public:
	char* GetName() { return (char*)"인문"; }
	Book* CreateBook() { return new Inmune; }
};
Book* gp_book_table[MAX_BOOK_KIND] = { new Inmune };//자동화기능시 수정할 부분2
//책 분야 모두 저장하고 모든 분야를 보여주고 사용자가 그 중에서 선택하게 하기 위함

//클래스는 상속을 통한 최소의 메모리 사용을 위해서 구현했고
//linked List기반 데이터 관리는 top라는 1차원구조체포인터변수에서 관리합니다
bookInfo* top;//bookInfo* top = NULL;//연결리스트가 할당되어있지 않으면 NULL저장된상태
//책정보를 저장하는 함수 : 추후 핸들값을 받아서 원하는 위치에 넣기 위해서 핸들값을 책마다 반환
HANDLE Book::SetString(unsigned int ap_book_count) {
	//bookInfo구조체 변수 생성
	bookInfo* new_book = new bookInfo;//구조체변수 1개를 저장할 구조체포인터변수메모리할당
	//bookInfo구조체 변수 초기화
	//linked List기반 데이터 구현 : 데이터 저장
	printf("책 이름: ");
	rewind(stdin);
	scanf("%s", new_book->name);
	printf("출판년도: ");
	rewind(stdin);
	scanf("%s", new_book->year);
	printf("저자 : ");
	rewind(stdin);
	scanf("%s", (new_book->owner).author);
	printf("출판사: ");
	rewind(stdin);
	scanf("%s", (new_book->owner).company);
	//linked List기반 데이터 구현 : 이전노드인 헤드포인터 가리킴
	new_book->p_next = top;
	top = new_book;
	new_book->h = ap_book_count+1;//핸들값은 1부터 시작인데 ap_book_count는 0부터 시작이라서
	printf("%d: 새로운 노드의 핸들값\n", new_book->h);
	return new_book->h;//핸들값은 1부터 시작이라 반환값이 1이상 자연수만 가능
}
HANDLE AddBook(Book* ap_book_list[], unsigned int ap_book_count)
//사용자가 넣은 책들만 담겨있는 배열과 이 배열의 현재 원소 개수로, 빈위치 찾아서 추가
{
	int select;//책 분야 중 어느 분야 선택할지를 받는 변수
	if (ap_book_count < MAX_ONE_CATEGORY) {
		for (int i = 0; i < MAX_BOOK_KIND; i++)
			printf(" %d. %s  ", i, gp_book_table[i]->GetName());
		scanf("%d", &select);
		//비어있는 위치에 넣는다
		ap_book_list[ap_book_count] = gp_book_table[select]->CreateBook();//클래스객체를 매번 생성
		//추가할 책 정보 입력
		ap_book_list[ap_book_count] = new Book;
		(ap_book_list[ap_book_count])->SetString(ap_book_count);

		return ap_book_list[ap_book_count]->SetString(ap_book_count);//해당 분야에 새로운 책을 등록하는 함수
		
	}
	else {
		printf("한 분야의 최대 인원을 초과하여 입력을 하실 수 없습니다.\n");
		printf("최대 %d권까지 한 분야에 가능하도록 지정하셨습니다\n\n", MAX_ONE_CATEGORY);
	}
	return 0;//AddBook실패
}
int is_empty() {
	return top == NULL;
}
void PrintStack()//해당 분야의 모든 책을 출력하는 함수
{
	if (!is_empty()) {
		bookInfo* p = top;
		while (p) {
			printf("%8s %8s %8s %8s\n", p->year, p->name, (p->owner).author, (p->owner).company);
			p = p->p_next;
		}
		printf("\n\n");
	}
}
//ap_book_list에 넣은 책들을 배열을 따로 잡아서 넣어주고
//핸들값을 여기서 바로 등록해서
//찾을 때는 여기서 찾기
//따라서 지금까지 구현된 것은 구조체포인터배열을 이용하지 않고 1차원구조체포인터배열로 검색,삭제

void DeleteNode(unsigned int a_book_count) {//p_next해제(구조체요소)
	//중간보고1에서 동적메모리해제를 쓰지도 않은 메모리에 대해서도, 미리 할당하고 시작했기에
	//했어야 했는 한계를 극복한 부분: a_book_count라는 사용자의 입력이 있을 때만 ap_book_list배열의
	//원소를 동적으로 할당을 했던 코드를 구현함으로써 극복
	/*for (int i = 0; i < a_book_count; i++) {
		bookInfo* p = top->p_next;
		free(top);
		top = p;
	}*/
	//혹은 is_empty반환값으로 비어있다면 반환하도록 구현
	while (1) {
		bookInfo* top_save_next;
		if (is_empty())
			error_handling("stack is empty!");
		int result = top->h;
		printf("%d :핸들값 해제합니다\n", result);
		top_save_next = top->p_next;
		free(top);
		top = top_save_next;
	}
}




void main()
{
	int select = 0;;
	unsigned int book_count = 0;

	Book* p_book_list[MAX_BOOK_SIZE];//일단은 사용자에게 최대 개수 입력안받고 정해서 구현
	while (1) {
		printf("도서관리시스템입니다. 어떤 작업을 하시겠습니까?\n");
		printf(" [ Menu ] ");
		printf(" 1. AddBook  2. FindBook  3. DeleteBook  4. Exit :");
		rewind(stdin);
		scanf_s("%d", &select);
		if (select == 4)	break;
		if (select == 1) {
			//AddBook에서 입력받은 최대 배열크기를 초과하지 않을때만 book_count증가
			int handle = AddBook(p_book_list, book_count);//핸들값을 SetString에서 반환
			if(handle){//handle!=0
				book_count++;
			}
		}
	}
	DeleteNode(book_count);//bookInfo연결리스트노드해제

	for (int i = 0; i < MAX_BOOK_KIND; i++)
		delete gp_book_table[i];//책 종류를 담아놓은 포인터배열 동적메모리 해제
	for (int i = 0; i < book_count; i++)
		delete p_book_list[i];//사용자가 입력한 책들만 담아놓은 포인터배열 동적메모리 해제
}
void error_handling(const char* msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(0);
}