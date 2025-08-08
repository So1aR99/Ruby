#include <stdio.h>

#define VER 7 
#define BIT16

int main()
{
	int max;
#if VER >= 6		// #if ~ #endif 한쌍임
	printf("버전은 %d입니다.\n", VER);
#endif				// 조건부 컴파일

#ifdef BIT16		// BIT16발견하면 실행
	max = 32767;
#else
	max = 2147473647;
#endif // BIT16
	printf("int형 변수 최대값: %d\n", max);

	return 0;
}