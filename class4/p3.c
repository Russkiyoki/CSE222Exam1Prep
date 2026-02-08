#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song{
	char name[32]; 
	int length;
	char rating; // A-F
	};

void print(struct song);

int main(){
	struct song song1;
	strcpy(song1.name, "Mr. Brightside");
	song1.length = 223;
	song1.rating = 'B';

	struct song song2;
	strcpy(song2.name, "Cherry waves");
	song2.length = 318;
	song2.rating = 'B';

	print(song1);
	print(song2);

	return 0;
}

void print(struct song s){
	printf(" %s %d %c \n", s.name, s.length, s.rating);
}

