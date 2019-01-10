#include <stdio.h>
#include <conio.h>

struct person {
	char name[20];
	int age;
	char birthday[11];
	char gender;
};

void main()
{
	struct person a;

	printf("name: ");
	gets(a.name);

	printf("age: ");
	scanf("%d", &a.age);
	getchar();

	printf("birthday: ");
	gets(a.birthday);

	printf("gender: ");
	scanf("%c", &a.gender);

	printf("\nname: %s, age: %d, birthday: %s, gender: %c\n", a.name, a.age, a.birthday, a.gender);
}
