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
//	printf("�÷� �Է�: ");
//	scanf("%lf %lf", &robot.left, &robot.right);
//	robot = exchange(robot);
//	printf("�ٲ� �÷�: %.1lf %.1lf\n", robot.left, robot.right);
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