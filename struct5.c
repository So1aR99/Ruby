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
//		printf("�̸�: %s\n", (plist+i)->name);
//		printf("����: %d\n", (plist+i)->age);
//		printf("��ȭ��ȣ: %s\n", (plist+i)->tel);
//		printf("�ּ�: % s\n\n", (plist+i)->addr);
//	}
//}
//
//int main()
//{
//	struct address list[3] = {
//		{ "ȫ�浿", 100, "010 - 1234 - 5678", "���� ����"},
//		{ "������", 150, "010 - 0000 - 1234", "���� ������" },
//		{ "�̼���", 200, "010 - 3415 - 2352", "���� ���ʱ�" } };
//
//	/*for (int i = 0; i < 3; i++) {
//		printf("%s %d %s %s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
//	}*/
//	print_list(list, 3);
//
//	return 0;
//}