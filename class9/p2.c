#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingest(FILE *fp);
int hash(char *c);

int main(){
	FILE *fptr = fopen("/usr/local/data/dictionary.com", "r");

	if(fptr==NULL){
		printf("Could not open file!\n");
		return 1;
	}

	ingest(fptr);
	printf("%d\n", hash("A"));
	printf("%d\n", hash("a"));
	printf("%d\n", hash("B"));
	printf("%d\n", hash("X"));
	printf("%d\n", hash("z"));
	return 0;
}

void ingest(FILE *fp){
	char word[256];
	char def[256];
	int count=0;
	while(fgets(word, sizeof(word), fp) && fgets(def, sizeof(def), fp)){
		word[strcspn(word, "\n")] = '\0';
		def[strcspn(def, "\n")] = '\0';

		//printf("Word %d is \"%s\", definition is \"%s\" \n", count, word, def);

	count++;
	}
}

int hash(char *c){
	int sum = 0;
	for(int i=0; i<strlen(c); i++){
		sum += c[i];
	}
	return sum % 10;
}
