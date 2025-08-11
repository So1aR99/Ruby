// ��Ʈ�Ͻ� ȸ������ ���α׷�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int num;
	char name[20];
	double weight;
	double height;
}Fitness;

void total_number(int count) {
	printf("  - ��ü ��� ȸ�� �� : %d��\n", count);
}

double average_weight(Fitness** pary, int count)			// ��� ü��
{
	double sum = 0;
	double average = 0;
	for (int i = 0; i < count; i++) {						// count��ŭ pary���� sum�� �����ؼ� ���� ���� count�� ���� ��հ��� ���� �� �� ���� ��ȯ
		sum += pary[i]->weight;
	}
	average = sum / count;
	return average;
}

double arerage_height(Fitness** pary, int count)			// ��� Ű
{
	double sum = 0;
	double average = 0;
	for (int i = 0; i < count; i++) {						// count��ŭ pary���� sum�� �����ؼ� ���� ���� count�� ���� ��հ��� ���� �� �� ���� ��ȯ
		sum += pary[i]->height;
	}
	average = sum / count;
	return average;
}

int max_weight(Fitness** pary, int count)					// �ְ� ü���� ȸ�� index
{
	int max = 0;
	for (int i = 1; i < count; i++) {
		if (pary[i]->weight > pary[max]->weight) {			// �� ���� ���� ū ���� ����
			max = i;
		}
	}
	return max;
}
void print_info(Fitness** pary, int index)					// ȸ�� ���� ���
{
	printf("  - ȸ�� ��ȣ: %d\n", pary[index]->num);
	printf("  - �̸�: %s\n", pary[index]->name);
	printf("  - ������(kg): %.2lf (kg)\n", pary[index]->weight);
	printf("  - Ű(cm):  %.2lf  (cm)\n", pary[index]->height);
}
void free_ary(Fitness** pary, int count)					// ���� �Ҵ� ����
{
	for (int i = 0; i < count; i++) {
		free(pary[i]);
	}
	free(pary);
}

int main()
{
	int count;
	printf("����� ȸ�� ���� �Է��ϼ���: ");
	scanf("%d", &count);

	Fitness** pary = (Fitness**)malloc(sizeof(Fitness**) * count);		// ���� �Ҵ�
	for (int i = 0; i < count; i++) {
		pary[i] = (Fitness*)malloc(sizeof(Fitness));

		printf("\n%d��° ȸ�� ���� �Է�\n", i+1);
		printf("  - ȸ�� ��ȣ: ");
		scanf("%d", &pary[i]->num);

		printf("  - �̸�: ");
		scanf("%s", &pary[i]->name);

		printf("  - ������(kg): ");
		scanf("%lf", &pary[i]->weight);

		printf("  - Ű(cm): ");
		scanf("%lf", &pary[i]->height);
	}
	printf("\nȸ�� ����\n");
	total_number(count);

	double avg1 = average_weight(pary, count);
	printf("  - ��� ������(kg): %.2lf (kg)\n", avg1);

	double avg2 = arerage_height(pary, count);
	printf("  - ��� Ű(cm): %.2lf (cm)\n", avg2);

	int max = max_weight(pary, count);
	printf("\n�����԰� ���� ���� ������ ȸ�� ����\n");
	print_info(pary, max);

	void free_ary(pary, count);

	return 0;
}