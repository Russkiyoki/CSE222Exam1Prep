#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 10000

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
	int tally[HASHSIZE] = {0};

	while(fgets(word, sizeof(word), fp) && fgets(def, sizeof(def), fp)){
		word[strcspn(word, "\n")] = '\0';
		def[strcspn(def, "\n")] = '\0';
		int h = hash(word);
		tally[h]++;
		//printf("Word %d is \"%s\", definition is \"%s\" \n", count, word, def);

	count++;
	}

	int big, bigIndex = 0;
	int small = tally[0];
	int smallIndex = 0;

	for(int i =0; i<HASHSIZE; i++){
		// tally[i] returns word count per hash index
		if(tally[i] > big){
			bigIndex = i;
			big = tally[i];
		}
		if(tally[i] < small){
			smallIndex = i;
			small = tally[i];
		}
		printf("Hash %d: %d words\n", i, tally[i]);
	}
		printf("Smallest hash index: %d\n", smallIndex);
		printf("Biggest hash index: %d\n", bigIndex);
}
// Function to hash stuff up
int hash(char *c){
	int sum = 0;
	for(int i=0; i<strlen(c); i++){
		sum += c[i];
	}
	return sum % HASHSIZE;
}
