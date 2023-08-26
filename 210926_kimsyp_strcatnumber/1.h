#pragma once
int strcmpprinciple(const char* p1, const char* p2)
{
	int len = strlen(p1);
	//계속 우선순위 동일했는데 길이가 더짧으면 비교는 끝내고 나머지 문자열이 이긴 것이므로 변수필요
	if (strlen(p2) < len)	len = strlen(p2);
	int i = 0;
	do {
		if (p1[i] < p2[i])//ascii 코드 비교
		{//'A'(65) < 'c'(98+'c'-'a') 
			if (65 <= p1[i] <= 90) {
				return -1;
			}
			//'a' < 'c', 'A' < 'C'인 경우
			else {
				return 1;
			}
		}
		else if (p1[i] > p2[i]) {
			if (65 <= p2[i] <= 90) {//'c' > 'A'
				return 1;
			}
			else {
				//'C' >'A', 'c' > 'a'
				return -1;
			}
		}
		else
			continue;
	} while (i < len && ++i);
	return 0;
}
int strcmpprinciple_2(const char** p1, const char** p2)
{
	int len = strlen(*p1);
	if (strlen(*p2) < len)	len = strlen(*p2);
	int i = 0;
	do {
		if (*((p1[0]) + i) < *((p2[0]) + i))//ascii 코드 비교
		//p1[0]
		{//'A'(65) < 'c'(98+'c'-'a') 
			if (65 <= *(*p1 + i) <= 90)
				return -1;
			else
			{
				return 1;
			}
		}
		else if (*((p1[0]) + i) > *((p2[0]) + i))
		{
			if (65 <= *(*p2 + i) <= 90)
				return 1;
			else
				return -1;
		}
		else
			continue;
	} while (i < len && ++i);
	return 0;
}