#include <stdio.h>
#define MAXLINE 1000

char line[MAXLINE];
char longest[MAXLINE];
int max;

int get_line(void);
void copy(void);

int main(){
	//tried to make my own version and ended up copying the whole code from the book
	//i am a miserable person lmao
	int len;
	extern int max;

	max = 0;
	while ((len = get_line()) > 0){
		if (len > max){
			max = len;
			copy();
		}
	}
	
	if (max > 0){
		printf("%s", longest);
	}

	return 0;
}

int get_line(void){
	// gets line, checks for spaces and null terminator and EOF
	// if it finds space, it skips the first for loop, then it is
	// assigned to line[i] and added a null terminator
	// so it grab lines and return their length (including null terminator)
	
	extern char line[];
	int i, c;
	
	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
		line[i] = c;
	}

	if (c == '\n'){
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	
	return i;
}

void copy(void){
	//it copies line to longest
	extern char line[];
	extern char longest[];

	int i;
	i = 0;
	while ((longest[i] = line[i]) != '\0'){
	++i;
	}
}
