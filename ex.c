#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int a, b;
	char op;
	int result;

	printf("���� ���α׷�\n");
	printf("���� ������ ���������� �Է��ϼ���: ");
	scanf("%d %c %d", &a, &op, &b);

	if (op == '+' ) {
		result = a + b;
		printf("���: %d", result);
	}
	else if(op == '-') {
		result = a - b;
		printf("���: %d", result);
	}
	else if(op == '*') {
		result = a * b;
		printf("���: %d", result);
	}
	else if(op == '/') {
		result = a / b;
		printf("���: %d", result);
	}
}

