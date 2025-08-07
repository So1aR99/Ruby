//#include <stdio.h>
//#include <string.h>
//
//int main() {
//	const char* orign = "Hello World";
//	
//	char *copy = strdup(orign);
//	if (copy == NULL) {		// 메모리를 할당 못받으면 예외처리
//		perror("failed");
//		return 1;
//	}
//	printf("orign: %s\n", orign);
//	printf("copy: %s\n", copy);
//
//  free(copy);
//	return 0;
//}