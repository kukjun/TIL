//
// Created by kukjun0712 on 2020-05-19.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LENGTH 128
#define MAX_PATH 256

int main() {

    char line[256], *pathPtr[MAX_PATH];
    char *command;

//	char ch;
//	int n;

//	char buffer[MAX_LENGTH];
//	int i=0;
//	FILE *fp=fopen(".myshell", "rt");

    char seps[] = " \n";
//	char *token;
/*

	if(fp == NULL) {
		printf("failed");
		return -1;
	}

	while(1) {
		ch=fgetc(fp);

		if(ch==EOF)
			break;

		buffer[i] = ch;
		i++;
	}

	fclose(fp);

	token = strtok(buffer, seps);

	while(token!=NULL) {
		printf("토큰: %s\n", token);
		token = strtok(NULL, seps);
	}
*/
    //while(1) {


    printf("@ ");
    fgets(line, 256, stdin);
    command = strtok(line, seps);
    printf("command = %s  ", command);


    //	break;
    //}

    return 0;
}