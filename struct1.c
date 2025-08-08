//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
////struct student {
////	int num;
////	int num2;
////	char ch;
////	char ch;			// 메모리 절약을 위해 같은 자료형끼리 묶음
////	double grade;		// 남는 메모리공간 (패딩바이트)
////};
//
//struct profile {
//	char name[20];
//	int age;
//	double height;
//	double weight;
//	char* info;
//};
//
//void main()
//{
//	struct profile p;
//	p.age = 27;
//	p.height = 173.53;
//	p.weight = 65.93;
//	//p.name = "노태성";
//	strcpy(p.name, "노태성");
//	p.info = (char*)malloc(80);
//	printf("자기소개: ");
//	//scanf("%s", p.info);
//
//	gets(p.info);		// 띄어쓰기 포함 출력
//
//	printf("이름: %s\n", p.name);
//	printf("나이: %d\n", p.age);
//	printf("몸무게: %.2lf\n", p.weight);
//	printf("키: %.2lf\n", p.height);
//	printf("소개: %s\n", p.info);
//}