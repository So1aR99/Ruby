/*
	���ڴ� ' ', ���ڿ��� " "�� ���´�.
	���ڴ� char, ���ڿ��� char �迭�� �����Ѵ�.
	�迭���� �迭�� �����ּҸ� ��Ÿ����.
	���ڿ��� ���ڿ�ũ�� +1�� �迭ũ�⸦ ������.
*/
#include <stdio.h>

void main()
{
	char ch = 'a';			// ����
	printf("ch: %c, ch: %d\n", ch, ch);

	char str[6] = "apple";		// �迭(�迭�̸��� �����ּ�, for)
	printf("str: %s\n", str);

	printf("str[0]: %c\n", str[0]);
	printf("str[4]: %c\n", str[4]);
	printf("str[5]: %s\n", str[5]);			// �ι��� ���

	char str1[] = "banana";
	char str2[] = str + str1;		// ���ڿ����� ���� �� ���� �Լ��̿�
	int a = 10, b = 20;
	int c = a + b;
}