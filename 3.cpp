#include<stdio.h>
#define MAX_LEN 32
void printnotchangeArr(const char(*ap_str)[MAX_LEN])
{
	printf("%s: printnotchangeArr\n", *ap_str);
}
void printnotchangePtr(const char(* ptr1D)[MAX_LEN])
{
	printf("%s: printnotchangePtr\n", *ptr1D);
}
void printnotchangePtr_(const char *ptr)
{
	printf("%s: printnotchangePtr\n", ptr);
}
int main()
{
	int data = 5;
	int data2 = 5;
	int* const ptr = &data;
	*ptr = 5;//성공
	ptr = &data2;//에러
	const int* ptr2 = &data2;
	*ptr2 = 5;//에러
	ptr2 = &data;//성공


	char arr1D[MAX_LEN] = "banana";
	const char(*ptr1D)[MAX_LEN] = &arr1D;
	printnotchangePtr(ptr1D);

	char arr1D_[MAX_LEN] = "banana";
	char arr1D__[] = "banana";
	printnotchangePtr_(arr1D_);
	printnotchangePtr_(arr1D__);
	return 0;
}