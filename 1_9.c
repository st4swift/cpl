#include <stdio.h>

#define MAXLEN  10000  //每行最大长度

//外部变量
int max;
char line[MAXLEN]; 	// current line
char longest[MAXLEN];  //max line

int getlin(void);
void copy(void);

int main(){
	int len;

	extern int max;
	extern char longest[];

	max = 0;
	while((len = getlin()) > 0){
		if (len > max) {
			max = len;
			copy();
		}
	}
	if (max > 0) printf("%s", longest);

	return 0;
}

int getlin(void){
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}

	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

void copy(void){
	extern char line[], longest[];

	int i = 0;
	while ((longest[i] = line[i]) != '\0') {
		++i;
	}
}

