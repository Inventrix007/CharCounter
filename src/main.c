#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct flags{
	int outputFlag;
	int wordFlag;
	char* outputFileName;
	char* inputFile;
	int charFlag;
};
FILE* output;

void print_help()
{
	fprintf(output,"Error Encountered!\n");
	fprintf(output,"Options:\n");
	fprintf(output,"	-h, --help : Show this help message\n");
	fprintf(output,"	-v, --version : Show program version\n");
	fprintf(output,"    -f, --file : Specify file name\n");
	fprintf(output,"    -o, --output : Specify the output file\n");
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
	struct flags flag;
	output = stdout;
	for(int i = 1; i < argc; i++){
		if(strcmp(argv[i],"-h") == 0 || strcmp(argv[i],"--help") == 0){
			print_help();
		}		
	    else if(strcmp(argv[i],"-v")== 0 || strcmp(argv[i], "--version")== 0){
			fprintf(output,"Program version is 1.0.0.1\n");
		}
		else if(strcmp(argv[i], "-f")== 0 || strcmp(argv[i], "--file")==0){
			i++;
			fprintf(output,"The file name is %s\n", argv[i]);
			flag.charFlag =1;
			flag.inputFile = argv[i];
		}
		else if(strcmp(argv[i], "-o")==0 || strcmp(argv[i], "--file")==0){
			i++;
			flag.outputFlag = 1;
			flag.outputFileName = argv[i];
		}
		else{
			print_help();
		}
	}

	if(flag.outputFlag){
		output = fopen(flag.outputFileName, "w");
		fprintf(output,"output file is : %s", flag.outputFileName);
	}
	if(flag.charFlag){
		charCount(flag.inputFile);
	}
	
	fprintf(output, "hello from main.c");
	fclose(output);
	return 0;
}

FILE* openFile(char* fileName)
{
	fprintf(output,"Inside openFile function\n");
	if(access(fileName, F_OK) != 0){
		fprintf(output,"file does not exist");
		return 0;
	}
	FILE *file = fopen(fileName, "r");
	if(file == NULL){
		fprintf(output,"Error: could not open file%s\n",fileName);
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
	fprintf(output,"Inside CharCount Function %s\n", fileName);
	FILE* file = openFile(fileName);

	//count characters in file
	int counter = 0;
	char ch;
	while( (ch = fgetc(file)) != EOF)
	{
		counter++;
	}
	fprintf(output,"File %s contains %d characters.\n",fileName, counter);
	
	fclose(file);
	fprintf(output,"file closed successfully\n");
}


