#pragma once
#define __CRT_SECURE_NO_WARNINGS

#define MAX_LEN 32
#include<stdio.h>
#include <string>
#include<string.h>
enum class CLASSIFICATION { FRESHMAN, SOPHOMORE, JUNIOR, SENIOR };


class Person {
public:
	CLASSIFICATION m_grade;
	int m_len;
	int m_max_len;
	char *mp_str;
	char mArray_str[MAX_LEN];
	std::string mstring_str;
public:
	Person(const char(*ap_str)[MAX_LEN]) {
		//m_len = strlen(ap_str) + 1;에러
		m_len = strlen(*ap_str) + 1;
		Init();

		if (m_max_len < m_len) {
			mp_str = (char*)malloc(m_len);
			*mp_str = 0;
		}
		strcpy_s(mArray_str, m_len, *ap_str);
	}
	Person() {
		//문자열받기
		//배열포인터를 매개변수로 사용하였기에 포인터로 ap_str을 받는다면 똑같은 형태인 char (*ap_str)[MAX_LEN]으로 선언이 되어야 하고
		//배열을 사용하는 것이 배열포인터를 매개변수로 사용하는 근본적인 이유고 따라서 aArray_str이라는 변수에 받아서 이것에 주소연산자를 붙인
		//&aArray_str을 배열포인터에 넘겨주는 것이 1차원배열 뿐 아니라 다차원 배열에서 적용되는 배열을 함수에 매개변수로 넘길 때의 규칙이고
		//물론 1차원배열은 배열포인터가 아닌 char *ptr이라는 단순한 포인터 변수로 매개변수를 사용하여도 되지만
		//다차원 배열을 반드시(char형에 한해서입니다) 배열포인터로 함수의 매개변수로 받아야 합니다
		char aArray_str[MAX_LEN];
		puts(aArray_str);
		rewind(stdin);
		SetString1(&aArray_str);
		mp_str = aArray_str;
	}
	void SetString1(char(*ap_str)[MAX_LEN]) {
		//m_len = strlen(ap_str) + 1;
		m_len = strlen(*ap_str) + 1;
		mp_str = (char*)malloc(m_len);
		strcpy_s(mp_str, m_len, *ap_str);
	}
	void SetString2(const std::string& ap_str) {
		mstring_str = ap_str;
	}
	void Init() {
		mp_str = 0;
		m_max_len = 1;
		mp_str = (char*)malloc(1);
		*mp_str = 0;
	}
	void ShowString()
	{
		printf("%s\n", mp_str);
	}
	void Destroy() {
		free(mp_str);
		Init();
	}
	~Person() {
		free(mp_str);
	}
};

