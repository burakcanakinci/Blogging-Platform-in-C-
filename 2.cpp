#include<malloc.h>
#include "Person.h"
/*//Person 클래스 재정의했다고 에러가 떠서 주석처리함
class Person {
public:
	CLASSIFICATION m_grade;
	int m_len;
	int m_max_len;
	char* mp_str;
	char mArray_str[MAX_LEN];
public:
	Person();
	Person(const char(*ap_str)[MAX_LEN]);
	~Person();
	void SetString1(char(*ap_str)[MAX_LEN]);
	void SetString2(const std::string& ap_str);
	void Init();
	void Destroy();
	void ShowString();
};*/

class Student:public Person {
private:
	int m_age;
public:
	Student():Person(){}
	Student(CLASSIFICATION grade, const char(*ap_str)[MAX_LEN]) :Person(ap_str)
	//에러: Person(*ap_str) 이유: 매개변수에 2차원포인터를 넘겨주어야 하므로(1차원배열의 &연산자, 즉, 1차원포인터의 &연산자 붙인 것)
	{
		//Person(ap_str);
		m_grade = grade;
		switch (grade) {
		case CLASSIFICATION::FRESHMAN:
			this->m_age = 20;
			break;
		case CLASSIFICATION::SOPHOMORE:
			m_age = 21;
			break;
		case CLASSIFICATION::JUNIOR:
			m_age = 22;
			break;
		case CLASSIFICATION::SENIOR:
			m_age = 23;
			break;
		default:
			break;
		};
	}
};

int main()
{
	//포인터를 사용하지 않고 인자없는 생성자함수이용해서 객체 생성한 부분
	Student std1;

	//복사생성자 부분
	//------
	const char name_in[MAX_LEN] = "홍길동";
	const char(*ptr_in)[MAX_LEN] = &name_in;
	enum CLASSIFICATION grade_in;
	grade_in = CLASSIFICATION::SOPHOMORE;
	
	Student std_tmp(grade_in,ptr_in);
	
	Student std_cp = std_tmp;
	delete[] std_tmp.mArray_str;

	printf("std_cp의 mArray_str멤버변수인\t %s는 메모리가 복사되었고 그 메모리에 값이 복사되었기 때문에 접근이 가능한 이유입니다\n", std_cp.mArray_str);
	//---

	//성공적으로 메모리가 할당되어 값이 제대로 적혔는지 확인해보는 부분
	std_tmp.ShowString();
	
	return 0;
}