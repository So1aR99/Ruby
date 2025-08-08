//#include <stdio.h>
//
//struct address
//{
//	char name[20];
//	int age;
//	char tel[20];
//	char addr[80];
//};
//
//void print_list(struct address* plist, int size)
//{
//	//for (int i = 0; i < size; i++) {
//	//	printf("%s %d %s %s\n", plist[i]->name, plist[i]->age, plist[i]->tel, plist[i]->addr);
//	//}
//
//	for (int i = 0; i < size; i++) {
//		printf("이름: %s\n", (plist+i)->name);
//		printf("나이: %d\n", (plist+i)->age);
//		printf("전화번호: %s\n", (plist+i)->tel);
//		printf("주소: % s\n\n", (plist+i)->addr);
//	}
//}
//
//int main()
//{
//	struct address list[3] = {
//		{ "홍길동", 100, "010 - 1234 - 5678", "대전 동구"},
//		{ "강감찬", 150, "010 - 0000 - 1234", "서울 강남구" },
//		{ "이순신", 200, "010 - 3415 - 2352", "서울 서초구" } };
//
//	/*for (int i = 0; i < 3; i++) {
//		printf("%s %d %s %s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
//	}*/
//	print_list(list, 3);
//
//	return 0;
//}