#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

#define MAX_PET_COUNT 40
#define PET_TABLE_COUNT 2
class Pet{
public:
	virtual Pet* CreatePet() {
		return NULL;
	}
	virtual const char* GetPetName() {
		return NULL;
	}
	virtual void Feed(){}
	virtual void Bark(){}
};

class Dog : public Pet{
public:
	//virtual 키워드는 부모 클래스에는 반드시 적어줘야 하고, 자식클래스는 적지 않아도 됩니다
	// 예를 들어 A<-B<-C여도 A만 적어주고 B와 C는 안 적어줘도 됩니다
	// 그래도 증조할아버지, 할아버지, 부모 이렇게 상속 구조가 계속 계층적으로 될 것이 예상된다면
	// 모든 virtual키워드 적은 함수는 자식클래스까지 모두 다 적어줘야(B,C까지 모두) C클래스를 작성하는 개발자가
	// B만 보고 알 수 있기 때문에 적어주는 것이 권장됩니다
	virtual Pet* CreatePet() {
		return new Dog;
	}
	virtual const char* GetPetName() {
		return "강아지";
	}
	void Feed() {
		printf("강아지우유라면 어떤 맛이라도!ㅎㅎ 고구마랑 계란을 제일 좋아해요\n");
	}
	void Bark() {
		printf("월월!^^\n");
	}
};

class Cat : public Pet{
public:
	virtual Pet* CreatePet() {
		return new Cat;
	}
	virtual const char* GetPetName() {
		return "고양이";
	}
	void Feed() {
		printf("야옹이들은 생선이나 연어들어간 스틱간식을 좋아해요^^\n");
	}
	void Bark() {
		printf("냐옹~\n");
	}
};

int main()
{
	int select;//메뉴 중에 선택할 번호 저장
	int type;//강아지와 야옹이 중 관리 동물 타입 선택 번호 저장
	Pet* p_pet_list[MAX_PET_COUNT];
	Pet* p_pet_table[PET_TABLE_COUNT] = {new Dog, new Cat};
	int pet_count=0;
	while (1) {
		printf("\n[ 메뉴 ]\n");
		printf("1. 신규 등록 2. 밥 먹이기 3. 건강상태체크(Bark) 4. 종료 : ");
		scanf_s("%d", &select);
		if (select == 1) {
			for (int i = 0; i < PET_TABLE_COUNT; i++) {
				printf("%d. %s ", i, p_pet_table[i]->GetPetName());
			}
			printf(": ");
			scanf_s("%d", &type);
			p_pet_list[pet_count] = p_pet_table[type]->CreatePet();
			pet_count++;
		}
		else if (select == 2) {
			for (int i = 0; i < pet_count; i++) {
				p_pet_list[i]->Feed();
			}

		}
		else if (select == 3) {
			for (int i = 0; i < pet_count; i++) {
				p_pet_list[i]->Bark();
			}

		}
		else if (select == 4)	break;

	}
	for (int i = 0; i < pet_count; i++) {
		delete* (p_pet_list + i); //delete p_pet_list[i];
	}
	return 0;
}