//#define _CRT_SECURE_NO_WARNINGS // if use 'strcpy' or 'scanf'
#include<stdio.h>
#include<string.h>
#include<stdlib.h>//atoi
#define MAX_LEN 11
class Student {
protected:
	int m_grade;
	char m_name[11];
	void* studentNum;//학번을 정수 문자열로 자료형 선언함
public:
	Student(int, const char*, char*, char);
	~Student() {}
	void Study() {
		exam();
	}
	void exam();
};

class Researcher : public Student{

public:
	Researcher(int grade, const char* name, const char* studentNum, char flag) : Student(grade, name, (char*)studentNum, flag) {}
	void research() {}
	
	//overriding
	void exam();
};

Student::Student(int grade, const char* name, char* studentNum, char flag)// Student * const this
{
	m_grade = grade;
	//혹은 this->m_grade = grade;

	strcpy_s(this->m_name, sizeof(char) * MAX_LEN, name);
	//혹은 strcpy_s(m_name, sizeof(char)*MAX_LEN, name);

	//학번을 정수 문자열로 자료형 선언함
	void* tmp_stdNum = studentNum;
	if (flag == 0)	*(char*)tmp_stdNum = atoi((const char*)studentNum);
	else if (flag == 1) {//short형 정수형 문자열
		char* tmp_shortPtr = (char*)studentNum;//1바이트로 시작 주소 가리킨 뒤에
		//높은 주소에서 1바이트씩 주소연산해서 값 읽어오기
		for (int i = 0; i < 2; i++)	*(((char*)tmp_stdNum)+i) = *(tmp_shortPtr+i);//for문 한 번 돌 때마다 1바이트씩 양쪽이 모두 증가해야 하므로
	}
	this->studentNum = studentNum;
}


//클래스 외부에 정의하는 방법: 3회 두번째 강좌 00:47:35
void Student::exam() {//Student const *this 생략됨
	printf("Student class : exam\n");
}

void Researcher::exam() {
	printf("Researcher class : exam\n");
}

int main(void)
{
	int grade = 95;
	const char name[12] = "홍길동";
	const char* ptr = name;//포인터 매개변수를(배열포인터 말고) 사용하는 생성자 함수에 보내므로 배열을 보내면 안되고 포인터 변수를 보내야 하므로
					 //해당 부분 내용 정리한 포스팅: https://blog.naver.com/raspmldlgycchang8753/222468500445
	
	Researcher cDer(grade, ptr, "2020123456", char(2));
	cDer.exam();

	//업캐스팅
	//구조체 포인터 처럼 혹은 일반변수의 포인터변수처럼 가리키는 주소가 포인터 변수
	Student *cBase = (Student*)&cDer;//학번을 정수 문자열로 자료형 선언함
	//flag는 학번에 해당하는 멤버변수가 어떤 길이의 정수형 자료형의 범위에 속할지 모르니까 void포인터형에 값을
	//저장할 때 자료형을 알려줘야하므로 flag로 알려준다(0: char형, 1: short형, 2: int형)

	cBase->exam();//자식클래스메서드오버라이딩 
	return 0;
}