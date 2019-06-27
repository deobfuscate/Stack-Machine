#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(int argc, char *argv[]) {
	printf("Stack Machine. Valid commands are: \"push <n>\" and \"pop\"\n");
	if (argc == 1) {
		printf("Missing parameter n\n");
		return 1;
	}
	if (argc > 2) {
		printf("Too many parameters\n");
		return 1;
	}
	STACK *mystack = MakeStack(10);
	int n = atoi(argv[1]);
	char buff[256];
	const char s[2] = " ";
	char *token;

	for (int i = 0; i < n; i++) {
		printf("> ");
		fgets(buff, 256, stdin);
		token = strtok(buff, s);
		int flag = 0;
		while (token != NULL) {
			if (flag == 1) {
				char* next = strtok(NULL, s);
				if (next != NULL && next[0] != '\n') break;
				int valToPush = atoi(token);
				Push(mystack, valToPush);
				break;
			}
			if (strcmp(token, "pop\n") == 0) {
				printf("%d\n", Pop(mystack));
				break;
			}
			if (strcmp(token, "push") == 0) {
				flag = 1;
			}
			token = strtok(NULL, s);
		}
	}
}