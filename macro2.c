#include <stdio.h>

#define VER 7 
#define BIT16

int main()
{
	int max;
#if VER >= 6		// #if ~ #endif �ѽ���
	printf("������ %d�Դϴ�.\n", VER);
#endif				// ���Ǻ� ������

#ifdef BIT16		// BIT16�߰��ϸ� ����
	max = 32767;
#else
	max = 2147473647;
#endif // BIT16
	printf("int�� ���� �ִ밪: %d\n", max);

	return 0;
}