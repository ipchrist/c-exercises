#include <stdio.h>

#define 	IN 	1
#define 	OUT	0

int main(){
	int i;
	int c;
	int state;
	int count;

	count = 0;
	state = OUT;
	while((c = getchar()) != EOF){
		if (c == '\n' || c == ' ' || c == '\t'){
			// if last word just finished and a new one has started
			if(state == IN){
				printf("\t");
				for (i = 0; i < count; ++i)
					printf("#");
			}
			count = 0;
			state = OUT;
			printf("\n");
		}

		//this happens at the beginning of each word
		else if (state == OUT){
			state = IN;
		}

		// if is inside a word, print char and count + 1
		if (state == IN){
			putchar(c);
			++count;
		}
	}
}

