#include <stdio.h>

/*
structure is object
*/
struct soldier {
	int height;
	int weight;
	char grade[10];
	char weapon[20];
	char speciality[30];
};

void main()
{
	struct soldier a, b;

	a.height = 165;
	a.weight = 55;
	strcpy(a.grade, "A\0");
	strcpy(a.weapon, "Knife\0");
	strcpy(a.speciality, "None\0");

	printf("please enter b's height: ");
	scanf("%d", &b.height);
	
	printf("please enter b's weight: ");
	scanf("%d", &b.weight);
	getchar();
	
	printf("please enter b's grade: ");
	gets(b.grade);
	
	printf("please enter b's weapon: ");
	gets(b.weapon);

	printf("please enter b's speciality: ");
	gets(b.speciality);

	printf("\n----------------------------------------\n");
	printf("summary of a:\n");
	printf("height: %d, weight: %d, grade: %s, weapon: %s, speciality: %s\n", a.height, a.weight, a.grade, a.weapon, a.speciality);
	printf("summary of b:\n");
	printf("height: %d, weight: %d, grade: %s, weapon: %s, speciality: %s\n", b.height, b.weight, b.grade, b.weapon, b.speciality);
}
