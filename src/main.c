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
	printf("    -f, --file : Specify file name\n");
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
	for(int i = 1; i < argc; i++){
		if(strcmp(argv[i],"-h") == 0 || strcmp(argv[i],"--help") == 0){
			print_help();
		}		
	    else if(strcmp(argv[i],"-v")== 0 || strcmp(argv[i], "--version")== 0){
			printf("Program version is 1.0.0.1\n");
		}
		else if(strcmp(argv[i], "-f")== 0 || strcmp(argv[i], "--file")==0){
			i++;
			printf("The file name is %s\n", argv[i]);
			charCount(argv[i]);
		}
		else{
			print_help();
		}
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
	printf("file closed successfully\n");
}


