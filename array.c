///* 3명의 4과목 점수를 입력받아 총점과 평균을 구하시오. */
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//void main()
//{
//	int score[3][4];
//	double avg;
//	int total;
//
//	for (int i = 0; i < 3; i++) {
//		printf("%d번째  학생의 4과목 입력: ", i+1);
//		for (int j = 0; j < 4; j++) {
//			scanf("%d", &score[i][j]);
//		}
//	}
//	for (int i = 0; i < 3; i++) {
//		total = 0;
//		printf("%d번째  학생의 4과목 점수: ", i+1);
//		for (int j = 0; j < 4; j++) {
//			printf("%d ", score[i][j]);
//			total += score[i][j];
//		}
//		avg = total / 4.0;
//		printf("\n총점: %d, 평균 %.2f\n", total, avg);
//	}
//}