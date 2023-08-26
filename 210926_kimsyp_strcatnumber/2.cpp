#include"../Project01/1.h"
#include"../Project01/gycchang_class.h"
#include"../Project01/node_struct.h"
int main(int argc, char* argv[])
//strcmpprinciple을 구현한 것을 메인에서 실행
{
	const char* p1 = "hello";
	const char* p2 = "hi";
	printf("%d %d(결과같은지 확인)\n", strcmpprinciple_2(&p1, &p2), strcmp(p1, p2));

	printf("%d %d(결과같은지 확인)\n", strcmpprinciple("a", "A"), strcmp("a", "A"));
	return 0;
}