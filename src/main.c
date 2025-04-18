#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_help()
{
	printf("Error Encountered!\n");
	printf("Options:\n");
	printf("	-h, --help : Show this help message\n");
	printf("	-v, --version : Show program version\n");
}

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
		printf("Program version is 1.0.0.0\n");
		return 0;
	}

	
	return 0;
}
