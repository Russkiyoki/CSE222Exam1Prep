#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingest(FILE *fp);
int hash(char *c);

// Function to function properly
int main(){
	FILE *fptr = fopen("/usr/local/data/dictionary.com", "r");

	if(fptr==NULL){
		printf("Could not open file!\n");
		return 1;
	}

	ingest(fptr);
	fclose(fptr);
	return 0;
}

// Function to process a file into words and defs on different lines
void ingest(FILE *fp){
	char word[256];
	char def[256];
	int count=0;
	int tally[10] = {0};

	while(fgets(word, sizeof(word), fp) && fgets(def, sizeof(def), fp)){
		word[strcspn(word, "\n")] = '\0';
		def[strcspn(def, "\n")] = '\0';
		int h = hash(word);
		tally[h]++;
		//printf("Word %d is \"%s\", definition is \"%s\" \n", count, word, def);

	count++;
	}

	for(int i =0; i<10; i++){
		printf("Hash %d: %d words\n", i, tally[i]);
	}
}
// Function to hash stuff up
int hash(char *c){
	int sum = 0;
	for(int i=0; i<strlen(c); i++){
		sum += c[i];
	}
	return sum % 10;
}
