#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* FILE_NAME;
bool checkFile(){
	FILE *file;
	if(file = fopen(FILE_NAME,"r")){
		printf("[LOG] FILE EXISTS\n");
		return true;
	} 
	printf("[ERROR] FILE %s DOESN'T EXIST\n", FILE_NAME);

	return false;
}

int compileFile(){
	char cmd[256]; char out[256];
	size_t len = strlen(FILE_NAME);
	strncpy(out, FILE_NAME, len-2);
	out[len -2] = '\0';
	snprintf(cmd, sizeof(cmd), "gcc %s -o %s", FILE_NAME, out);
	int comp_re = system(cmd);
	if(comp_re != 0){
		return comp_re;
	}
	snprintf(out, sizeof(out), "./%s", out);
	printf("%s", out);
	system(out);
}

int main(int argc, char* argv[]){
	// CHECK THE ARGUMENTS AND HANDLE THEM
	if(argc > 2){
		printf("USAGE: (kiara|k) [filename]\n");
		return 2;
	}

	if(argc == 1){
		printf("HELP MENU\n");
		return 0;
	}

	// CHECK IF THE FILE_NAME HAS .c or else append it
	size_t len = strlen(argv[1]);
	if(strcmp(argv[1] +len-2, ".c") == 0){
		FILE_NAME = argv[1];
	} else{
		FILE_NAME = malloc(len+3);
		strcpy(FILE_NAME, argv[1]);
		strcat(FILE_NAME,".c");
	}
	if(checkFile()){
		printf("[LOG] COMPILING FILE\n");

	}
	compileFile();
	return 0;
}
