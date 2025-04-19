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

typedef struct WordNode{
	char* word;
	int count;
	struct WordNode* next;
} WordNode;

FILE* output;
#define Table_Size 1000
WordNode* hashTable[Table_Size];

int hash(char* word){
	unsigned long hash = 5381;
	int c;
	while(( c= (unsigned char)*word++)){
		hash = ((hash << 5) + hash) + c;
	}
	return hash%Table_Size;
}

void insert_word(char* word){
	// printf("inside insert word function %s:\n", word);
	int index = hash(word);
	WordNode *node = hashTable[index];

	while(node != NULL){
		if(strcmp( node->word, word) == 0){
			node->count++;
			return;
		}
		node = node->next;
	}
	//insert word
	WordNode* newnode = malloc(sizeof(WordNode)); 
	newnode->count = 1;
	newnode->word = strdup(word);
	newnode->next = NULL;
	hashTable[index]= newnode;
	// printf("hash value: %s : %d\n", hashTable[index]->word, index);
}

void printUniqueWord(){
	int counter =0;
	// char* str = malloc(sizeof(char)*1000);
	fprintf(output,"The list of unique words is: \n");
	for(int i = 0; i < Table_Size; i++){
		if(hashTable[i] == NULL){
			continue;
		}	
		WordNode *node = hashTable[i];
		while(node!= NULL){
			if(node->count == 1){
				printf("%s\n", node->word);
				// fprintf(output, "%s : %s\n",str, hashTable[i]->word);
				counter++;
			}
			node = node->next;
		}
	}
	fprintf(output,"The number of unique words is: %d\n",counter);
}

void print_help(int error)
{
	if(error){
		fprintf(output,"Error Encountered!\n");	
	}
	fprintf(output,"Options:\n");
	fprintf(output,"	-h, --help : Show this help message\n");
	fprintf(output,"	-v, --version : Show program version\n");
	fprintf(output,"    -f, --file : Specify file name\n");
	fprintf(output,"    -o, --output : Specify the output file\n");
}

FILE* openFile(char* fileName);
int fileHandler(struct flags flag);

int main(int argc, char *argv[]){
	// printf("Main Starts\n");
	printf("%s\n",argv[0]);
	if(argc<2){
		print_help(1);
		return 0;
	}
	struct flags flag;
	output = stdout;
	for(int i = 1; i < argc; i++){
		if(strcmp(argv[i],"-h") == 0 || strcmp(argv[i],"--help") == 0){
			print_help(0);
		}		
	    else if(strcmp(argv[i],"-v")== 0 || strcmp(argv[i], "--version")== 0){
			fprintf(output,"Program version is 1.0.0.1\n");
		}
		else if(strcmp(argv[i], "-f")== 0 || strcmp(argv[i], "--file")==0){
			i++;
			flag.inputFile = argv[i];
		}
		else if(strcmp(argv[i], "-o")==0 || strcmp(argv[i], "--file")==0){
			i++;
			flag.outputFlag = 1;
			flag.outputFileName = argv[i];
		}
		else if(strcmp(argv[i], "-c") ==0){
			flag.charFlag = 1;
		}
		else if(strcmp(argv[i], "-w") ==0){
			flag.wordFlag = 1;
		}
		else{
			print_help(0);
		}
	}

	if(flag.outputFlag){
		output = fopen(flag.outputFileName, "w");
		fprintf(output,"output file is : %s", flag.outputFileName);
	}

	fileHandler(flag);
	//fprintf(output, "hello from main.c");
	fclose(output);
	return 0;
}

int fileHandler(struct flags flag){
	// fprintf(output,"Inside file handler Function %s\n", flag.inputFile);
	FILE* file = openFile(flag.inputFile);

	//count characters in file
	int counter = 0;
	int wordCounter =0;
	char ch;
	char* str = malloc(sizeof(char)*100);
	int i =0;
	while( (ch = fgetc(file)) != EOF)
	{
		if(flag.charFlag){
			counter++;	
		}
		if(flag.wordFlag){
			if(((unsigned char)ch == ' ') || ((unsigned char) ch == '\n')){
				wordCounter++;
				str[i]='\0';
				i = 0;				
				insert_word(str);
				continue;
			}
			str[i] = ch;
			i++;
		}
		// if(counter < 8){
			// printf("ascii char of %c is %d and signed is %d\n", ch, (unsigned char) ch, ch);
		// }
		
	}
	fprintf(output,"File %s contains %d characters.\n",flag.inputFile, counter);
	fprintf(output,"File %s contains %d words.\n",flag.inputFile, wordCounter);
	fclose(file);
	printUniqueWord();
	free(str);
}

//void wordCount(char* fileName){
//	FILE* inputFile = openFile(fileName);
//	char ch;
//	while()		
//}

FILE* openFile(char* fileName)
{
	// fprintf(output,"Inside openFile function\n");
	if(access(fileName, F_OK) != 0){
		fprintf(output,"file does not exist");
		return 0;
	}
	FILE *file = fopen(fileName, "r");
	if(file == NULL){
		fprintf(output,"Error: could not open file%s\n",fileName);
	}
	// Print file content to terminal
	fprintf(output, "The text in file %s:\n", fileName);
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


