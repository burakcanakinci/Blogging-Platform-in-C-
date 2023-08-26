//구조체포인터변수로 구조체변수클래스멤버변수나 멤버메서드접근하는 방법
#include<stdio.h>
#define MAX_PET 2
class Pet {
public:
	virtual void Sound(){}
	virtual void Eat(){}
	virtual Pet* CreatePet() { return NULL; }
	virtual char* GetName() { return NULL; }
};

//*(p+0~4) 와 *(ptr+0~4)로 매개변수에서 보내서 구조체 각 원소의 시작주소,
//1차원 char*형 변수의 값을 보내주기
class Dog :public Pet {
public:
	void Sound() { printf("멍멍~\n"); }
	void Eat() { printf("뼈다귀\n"); }
	//마치 throws Exception을 할 때 catch블럭에서 throw new MyException("Hwang");을 하면
	//업캐스팅이 일어나서 가능하다
	Pet* CreatePet() { return new Dog; }
	char* GetName() { return (char*)"Dog"; }
};
class Cat :public Pet{
public:
	void Sound() { printf("야옹~\n"); }
	void Eat() { printf("생선\n"); }
	Pet* CreatePet() { return new Cat; }
	char* GetName() { return (char*)"Cat"; }
};
//각 클래스의 클래스 포인터 배열
//ap_dog_count[0]~ap_dog_count[추가]
Pet* gp_pet_table[MAX_PET] = { new Dog, new Cat };

void AddPet(Pet* ap_list[],int* ap_pet_count)
{
	int select;
	//강아지 숫자를 증가시키고 강아지 포인터 배열에 강아지 객체를 동적할당으로 추가
	//포인터배열에서 빈 원소로 이동해서 그런데 이거는 이미 할당을 완료한 뒤에 그 제한이 걸려있고
	//p_handle->h을 이용했었어
	//하지만 여기서는 단순히 포인터배열의 동적할당을 이용할거야
	//뒤에 추가해서 하는 것이 가능하네
	for (int i = 0; i < MAX_PET; i++) {
		printf("%s -> %d\n", gp_pet_table[i]->GetName(), i);
	}
	scanf_s("%d", &select);
	ap_list[*ap_pet_count] = gp_pet_table[select]->CreatePet();//함수반환값이용(동적바인딩에 따른 서브클래스 메서드실행)
	(*ap_pet_count)++;
}
void PetSound(Pet* ap_list[], int pet_count)
{
	for (int i = 0; i < pet_count; i++) {
		ap_list[i]->Sound();
	}
}
void PetEat(Pet* ap_list[], int pet_count)
{
	//포인터배열의 원소는 클래스포인터변수이므로
	//구조체와 동일하게 접근한다
	for (int i = 0; i < pet_count; i++) {
		ap_list[i]->Eat();//동적바인딩으로 슈퍼클래스의 메서드로 갔다가 서브클래스의 메서드를 실행한다
	}
}
int main(void)
{
	Pet* p_list[20];//포인터배열 20개원소(최대원소개수)
	int pet_count = 0,select=0;
	while (select != 4) {
		printf("[Menu] ");
		printf("1. AddPet 2. PetSound 3. PetEat 4. Exit :");
		scanf_s("%d", &select);
		//부모클래스로 작성된 virtual키워드를 쓴 메서드를 동적바인딩을 통해
		//서브클래스의 메서드를 실행함으로써(단 이때, 업캐스팅이기 때문에 부모 객체로
		//먼저 실행후에, 서브클래스의 메서드로 간다)
		if (select == 1)	AddPet(p_list, &pet_count);
		else if (select == 2)	PetSound(p_list, pet_count);
		else if(select==3)	PetEat(p_list, pet_count);
	}
	//함수를 통해서 동적할당을 한(매개변수로 보낼 때 NULL로 보냈더라도)
	//동적메모리해제하는 코드가 반드시 필요하다(연결리스트 NODE **pp_head생각)
	//포인터배열이므로 각 변수를 해제하는 코드가 필요한데 
	//하나의 원소에 할당된 것이 배열이 아니라 하나의 클래스 객체니까 
	//delete으로 해야하고 delete[]으로 하면 안된다
	for (int i = 0; i < pet_count; i++) {
		//1을 증가시키기 때문에 1을 뺀 인덱스까지 포인터변수가 저장되어있다
		delete p_list[i];
	}
	//하나의 구조체포인터변수를 동적할당했으니까 이거 동적할당하고
	//이게 끝이네
	//new를 통해서 생성한 건 모두 해제해야지
	for (int i = 0; i <MAX_PET; i++) {
		delete gp_pet_table[i];
	}
	return 0;
}