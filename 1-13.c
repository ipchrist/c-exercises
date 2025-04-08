#include <stdio.h>

int main(){
	int i, count, c, j, y;
	int wlen[10];
	count = 0;

	for (i = 0; i <= 9; ++i){
		wlen[i] = 0;
	}

	while ((c = getchar()) != EOF){
		if (c == '\n' || c == ' ' || c == '\t'){
			if (count > 0){
				++wlen[count];
			}
	
		count = 0;

		} else {
			++count;
		}
	}

	for (i = 1; i <= 9; ++i){
		printf("%02d | ", i);
		for (y = 1; y <= wlen[i]; ++y){
			printf("#");
		}
		printf("\n");
	}
}
