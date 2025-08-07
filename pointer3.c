//#include <stdio.h>
//
//void main() {
//	char* str;
//	str = "hello";				// 한문자만 수정 불가능, 
//								// 포인터 str은 스택영역에 저장, 데이터영역에 저장
//	char st[10] = "hello";		// 수정가능, 스택영역에 저장
//	for (; *str; str++) {		// 널 문자 있을때까지 출력
//		printf("%s\n", str);
//	}
//}