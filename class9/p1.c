#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingest(FILE *fp);

int main(){
	FILE *fptr = fopen("/usr/local/data/dictionary.com", "r");

	if(fptr==NULL){
		printf("Could not open file!\n");
		return 1;
	}

	ingest(fptr);

	return 0;
}

void ingest(FILE *fp){
	char word[256];
	char def[256];
	int count=0;
	while(fgets(word, sizeof(word), fp) && fgets(def, sizeof(def), fp)){
		word[strcspn(word, "\n")] = '\0';
		def[strcspn(def, "\n")] = '\0';

		printf("Word %d is \"%s\", definition is \"%s\" \n", count, word, def);

	count++;
	}
}
