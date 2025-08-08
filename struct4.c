//#include <stdio.h>
//
//typedef struct score
//{
//	int kor;
//	int eng;
//	int math;
//}Score;
//
//int main()
//{
//	Score s = { 95, 80, 85 };
//	Score* ps = &s;						// 구조체 포인터 선언
//
//	printf("국어: %d\n", s.kor);		// 구조체 변수로 접근
//	printf("영어: %d\n", ps->eng);		// 구조체 포인터로 멤버 접근
//	printf("수학: %d\n", ps->math);
//
//	return 0;
//}