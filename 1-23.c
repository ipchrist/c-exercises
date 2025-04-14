#include <stdio.h>
#include <stdbool.h>

int main(){
	int i, c, prev;
	bool in_block_comment = false;
	bool in_line_comment = false;
	bool in_string = false;
	bool in_char = false;

	for (i = prev = 0; (c = getchar()) != EOF; prev = c){
		if (c == '"' && prev != '\\' && !in_char && !in_line_comment && !in_block_comment){
			in_string = !in_string;
		}

		if (c == '\'' && prev != '\\' && !in_string && !in_line_comment && !in_block_comment){
			in_char = !in_char;
		}

		if (c == '\n'){
			in_line_comment = false;
		}

		if (c == '/' && !in_string && !in_line_comment && !in_block_comment){
			if (prev == '/'){
				in_line_comment = true;
				continue;
			}
			continue;
		}

		if (c == '*' && !in_string && !in_line_comment && !in_block_comment){
			if (prev == '/'){
				in_block_comment = true;
				continue;
			}
		}

		if (prev == '*' && !in_string && !in_line_comment){
			if (c == '/' && !in_string && !in_line_comment){
				in_block_comment = false;
				continue;
			}
		}
		if (!in_line_comment && !in_block_comment){
			putchar(c);
		}
	};
}
