#include <stdio.h>

struct student {
	int middle;
	int final;
};

void main()
{
	struct student s;
	struct student* p;

	p = &s;

	printf("middle exam score? ");
	scanf("%d", &p->middle);
	printf("final exam score? ");
	scanf("%d", &p->final);

	printf("sum: %d\n", p->middle + p->final);


	printf("&s? %p\n", &s);
	printf("&s.middle? %p\n", &s.middle);
	printf("&s.final? %p\n", &s.final);
	
	printf("&p? %p\n", &p);
	printf("p? %p\n", p);
	printf("p->middle / &p->middle? %d / %p\n", p->middle, &p->middle);
	printf("p->final / &p->final? %d / %p\n", p->final, &p->final);
}
