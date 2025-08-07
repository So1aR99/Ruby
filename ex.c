#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int a, b;
	char op;
	int result;

	printf("계산기 프로그램\n");
	printf("정수 연산자 정수순으로 입력하세요: ");
	scanf("%d %c %d", &a, &op, &b);

	if (op == '+' ) {
		result = a + b;
		printf("결과: %d", result);
	}
	else if(op == '-') {
		result = a - b;
		printf("결과: %d", result);
	}
	else if(op == '*') {
		result = a * b;
		printf("결과: %d", result);
	}
	else if(op == '/') {
		result = a / b;
		printf("결과: %d", result);
	}
}

