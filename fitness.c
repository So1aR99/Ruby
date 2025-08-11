// 휘트니스 회원관리 프로그램
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
	printf("  - 전체 등록 회원 수 : %d명\n", count);
}

double average_weight(Fitness** pary, int count)			// 평균 체중
{
	double sum = 0;
	double average = 0;
	for (int i = 0; i < count; i++) {						// count만큼 pary값을 sum에 누적해서 더한 값을 count로 나눠 평균값을 구한 후 그 값을 반환
		sum += pary[i]->weight;
	}
	average = sum / count;
	return average;
}

double arerage_height(Fitness** pary, int count)			// 평균 키
{
	double sum = 0;
	double average = 0;
	for (int i = 0; i < count; i++) {						// count만큼 pary값을 sum에 누적해서 더한 값을 count로 나눠 평균값을 구한 후 그 값을 반환
		sum += pary[i]->height;
	}
	average = sum / count;
	return average;
}

int max_weight(Fitness** pary, int count)					// 최고 체중의 회원 index
{
	int max = 0;
	for (int i = 1; i < count; i++) {
		if (pary[i]->weight > pary[max]->weight) {			// 두 값을 비교해 큰 값을 리턴
			max = i;
		}
	}
	return max;
}
void print_info(Fitness** pary, int index)					// 회원 정보 출력
{
	printf("  - 회원 번호: %d\n", pary[index]->num);
	printf("  - 이름: %s\n", pary[index]->name);
	printf("  - 몸무게(kg): %.2lf (kg)\n", pary[index]->weight);
	printf("  - 키(cm):  %.2lf  (cm)\n", pary[index]->height);
}
void free_ary(Fitness** pary, int count)					// 동적 할당 해제
{
	for (int i = 0; i < count; i++) {
		free(pary[i]);
	}
	free(pary);
}

int main()
{
	int count;
	printf("등록할 회원 수를 입력하세요: ");
	scanf("%d", &count);

	Fitness** pary = (Fitness**)malloc(sizeof(Fitness**) * count);		// 동적 할당
	for (int i = 0; i < count; i++) {
		pary[i] = (Fitness*)malloc(sizeof(Fitness));

		printf("\n%d번째 회원 정보 입력\n", i+1);
		printf("  - 회원 번호: ");
		scanf("%d", &pary[i]->num);

		printf("  - 이름: ");
		scanf("%s", &pary[i]->name);

		printf("  - 몸무게(kg): ");
		scanf("%lf", &pary[i]->weight);

		printf("  - 키(cm): ");
		scanf("%lf", &pary[i]->height);
	}
	printf("\n회원 정보\n");
	total_number(count);

	double avg1 = average_weight(pary, count);
	printf("  - 평균 몸무게(kg): %.2lf (kg)\n", avg1);

	double avg2 = arerage_height(pary, count);
	printf("  - 평균 키(cm): %.2lf (cm)\n", avg2);

	int max = max_weight(pary, count);
	printf("\n몸무게가 가장 많이 나가는 회원 정보\n");
	print_info(pary, max);

	void free_ary(pary, count);

	return 0;
}