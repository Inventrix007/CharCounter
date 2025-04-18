#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void print_help()
{
	printf("Error Encountered!\n");
	printf("Options:\n");
	printf("	-h, --help : Show this help message\n");
	printf("	-v, --version : Show program version\n");
}
FILE* openFile(char* fileName);
void charCount(char* fileName);

int main(int argc, char *argv[]){
	printf("Main Starts\n");
	printf("%s\n",argv[0]);
	if(argc<2){
		print_help();
		return 0;
	}

	if(strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"--help") == 0){
		print_help();
		return 0;
	}
	if(strcmp(argv[1],"-v")== 0 || strcmp(argv[1], "--version")== 0){
		printf("Program version is 1.0.0.1\n");
	}
	if(strcmp(argv[1], "-f")== 0 || strcmp(argv[1], "--file")==0){
		printf("The file name is %s\n", argv[2]);
		charCount(argv[2]);
	}

	
	return 0;
}

FILE* openFile(char* fileName)
{
	printf("Inside openFile function\n");
	if(access(fileName, F_OK) != 0){
		printf("file does not exist");
		return 0;
	}
	FILE *file = fopen(fileName, "r");
	if(file == NULL){
		printf("Error: could not open file%s\n",fileName);
	}
	// Print file content to terminal
	char ch;
	while ((ch = fgetc(file)) !=EOF){
		putchar(ch);
	}
	// rewind the file pointer so that returned file is ready to be reused
	rewind(file);

	return file;
}

void charCount(char* fileName)
{
	printf("Inside CharCount Function %s\n", fileName);
	FILE* file = openFile(fileName);

	//count characters in file
	int counter = 0;
	char ch;
	while( (ch = fgetc(file)) != EOF)
	{
		counter++;
	}
	printf("File %s contains %d characters.\n",fileName, counter);
	
	fclose(file);
}


