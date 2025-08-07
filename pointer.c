//#include <stdio.h>
//
//void main() {
//	int a = 10;			// 변수 선언
//	int* pa;			// 포인터 선언
//	pa = &a;			// 변수a의 주소값을 포인터변수에 대입
//
//	printf("&a: %p,	 pa: %p\n", &a, pa);
//	printf("a: %d,	*pa: %d\n", a, *pa);
//
//	*pa = 20;
//	printf("a: %d,	*pa: %d\n", a, *pa);
//	printf("pa + 1: %p\n", pa + 1);
//	char c = 'a';
//	pa = &c;
//	printf("pa: %p,  pa + 1: %p\n", pa, pa + 1);
//}