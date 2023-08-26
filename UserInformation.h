#pragma once
typedef struct UserInformation UI;
typedef struct UserInformation* P_UI;
typedef char AGE;
typedef char NAME_TYPE[12];

struct UserInformation {
	char name[12];
	int age;
};
struct UserInformationAdd {
	char name[12];
	int age;
	short money;//학생이니 6만원만 있다고 가정하고 하겠습니다
};
void ArrangeMemberByAGE(UI* p_u,int count)
{//먼저 구조체 원소를 임의로 아무거나 가리키게 가능하므로 첫 번째 원소를 가리키게 하고 다음 원소는 주소연산으로 접근한다
	for (int pass = 0; pass < count; pass++) {
		for (int i = count - 1; count > pass; count--) {//마지막 인덱스부터 줄여가면서 i인덱스에 대입
			if (p_u->age < (p_u--)->age) {
				int tmp = p_u->age;
				p_u->age = (p_u--)->age;
				(p_u--)->age = tmp;
			}
			p_u++;
		}
	}
}
void ShowUIAdd(struct UserInformationAdd*);
void SetMoney(UI* p_u, AGE age, int index) {
	//p_u에는 첫 번째 원소의 주소를 넘겨주어 다른 구조체의 멤버변수에 접근한다
	//연산자우선순위: ->연산자 > &연산자 > +(가감연산자)
	//&(p_u + index)->age : age변수의 주소(포인터변수임을 주의해서 보자, 왜냐면 다음줄 설명에서 포인터 주소연산을 사용하기 때문이다)
	//포인터변수의 주소연산에 의해서 +1을 하면 앞의 age변수에 해당하는 포인터변수이므로 +1을 포인터 변수에 해주면 4바이트만큼 증가한다
	//따라서 &(p_u + index)->age+1 는 UserInformationAdd의 money변수를 가리킬 수 있게 될 첫 번째 조건은 갖추었고, 두번째 조건으로는 캐스팅을 통해
	//이 부분을 잘 모르시겠는 분께서는 void*형(13-5장,6장을) 참고해주세요~
	//short*형 캐스팅을 해주고, 가장 먼저 만족되어야 했던 조건인 UserInformationAdd의 객체를 가리키도록 하는것, 그리고 포인터 변수p_u는 UserInformation의 
	//객체이므로 p_u로 바로 money변수에 접근하는 것은 불가능하다, 하지만 주소연산은 포인터변수가 가리키는 자료형의 범위를 벗어나도 괜찮다는 특성과
	//주소연산의 특성을 활용하였다
	struct UserInformationAdd data;
	data.age = age;
	strcpy_s(data.name, 12, "마리오");
	p_u = (P_UI)&data;
	*(short*)(&(p_u + index)->age + 1) = 30000;
	ShowUIAdd(&data);
}

void ShowUIAdd(struct UserInformationAdd* p_data) {
	printf("UserInformationAdd 구조체 변수입니다 :%d, %s, %hd", p_data->age, p_data->name, p_data->money);
}

P_UI FindByAGE(UI* p_u, AGE age, int count) {

	for (int i = 0; i < count; i++) {
		if ((p_u + i)->age == age) {
			return p_u;
		}
	}
	return NULL;
}