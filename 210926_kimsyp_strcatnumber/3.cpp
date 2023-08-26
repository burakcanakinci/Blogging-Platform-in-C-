#include"../Project01/1.h"
#include"../Project01/gycchang_class.h"
#include"../Project01/node_struct.h"
int main(int argc, char* argv[])
//리틀엔디언 빅엔디언 전송방식 및 저장 방식 확인
{
	int data = 0x12345678;

	void* p = &data;

	//p의 시작주소는 0x78이므로 2바이트 0x78 0x56 이 수정됨

	*(short*)p = 0x4689;//
	printf("%#X, ", data);

	*(char*)p = 0x46;
	char* p_char = (char*)p;
	*p_char++ = 0x89;
	printf("%#X, ", data); // 리틀엔디언이 빅엔디언으로부터 전송된 데이터를 받을 때는 빅엔디언은 낮은주소부터 전송하고
	//빅엔디언은 낮은주소에 상위바이트값이 저장되어있어 0x4689인 경우라면 낮은주소에 0x46이 저장되어있고 
	//리틀엔디언은 빅엔디언으로부터 전송된 데이터를 온 순서대로 받아서 0x46 낮은주소 0x89 높은주소지만
	//지금의 경우는 리틀엔디언에서 전송하는 경우라 높은 주소부터 전송을 해서 0x46부터 전송하고 입력받는 리틀엔디언은 위에서도 봐왔듯이
	//0x46(상위 바이트)를 높은 주소에 저장합니다
	printf("\n");

	printf("%d %d(결과같은지 확인)\n", strcmpprinciple("a", "A"), strcmp("a", "A"));
	return 0;
}