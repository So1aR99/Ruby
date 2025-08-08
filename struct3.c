//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//struct vision {
//	double left;
//	double right;
//};
//
//struct vision exchange(struct vision arobot);
//
//void main()
//{
//	struct vision robot;
//	printf("시력 입력: ");
//	scanf("%lf %lf", &robot.left, &robot.right);
//	robot = exchange(robot);
//	printf("바뀐 시력: %.1lf %.1lf\n", robot.left, robot.right);
//}
//
//struct vision exchange(struct vision arobot)
//{
//	double temp;
//	temp = arobot.left;
//	arobot.left = arobot.right;
//	arobot.right = temp;
//
//	return arobot;
//}