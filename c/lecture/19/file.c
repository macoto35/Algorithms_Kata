#include <stdio.h>
#include <stdlib.h> // parent of exit();

/*
- FILE *fp; // file control pointer

- fp = fopen("<file_name>", "<mode>"); // open file
- fclose(fp); // close file

- fputc('a', fp); // write character one by one into file
- fgetc(fp); // read character one by one from file

- fprintf(fp, "test %d\n", age); // write file
- fscanf(fp, "%d", &number); // read file
*/
void main()
{
	FILE* fp;

	// write mode
	fp = fopen("test.txt", "w"); // r: read, w: write, a: append

	if (fp == NULL) { // if system can't file a file then return NULL
		printf("Cannot open a file!\n");
		exit(1);
	}

	int age = 24;
	fprintf(fp, "%d is my age ", age);

	char str[] = "and my name is abc!";
	fputs(str, fp);

	fclose(fp);



	// read mode
	fp = fopen("test.txt", "r");

	if (fp == NULL) {
		printf("Cannot open a file!\n");
		exit(1);
	}

	int num;
	char ch;
	fscanf(fp, "%d %c", &num, &ch);
	printf("-----%d %c-----\n", num, ch);

	/*
	if file contains mulit-lines string:
	      abcd\n
	      defg\n
	      EOF
	\n means end of line
        EOF means end of file 
	*/
	while((ch = fgetc(fp)) != EOF)
		putchar(ch);

	fclose(fp);
}
