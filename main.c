#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

int main (int argc, char *argv[]) {
	char toOpen[1000] = ".";
	if (argc == 1) {
		fgets(toOpen, sizeof(toOpen), stdin);
		toOpen[strlen(toOpen) - 1] = '\0';
	}
	else {
		strcpy(toOpen, argv[1]);
	}
	struct DIR *direct = opendir(toOpen);
	long size = 0;
	if (direct < 0) {
		printf("Error Opening Directory: %s\n", strerror(errno));
		return 0;
	}
	struct dirent *file;
	printf("----- Examining Directory: [%s] -----\n", toOpen);
	while ((file = readdir(direct)) != NULL) {
		int dirCheck = file->d_type;
		if (dirCheck == 4) {
			printf("[DIR] ");
		}
		else {
			printf("[---] ");
		}
		struct stat fileStats;
		stat(file->d_name, &fileStats);
		size += fileStats.st_size;
		printf(": %s\n", file->d_name);
	}
	printf("TOTAL DIRECTORY SIZE: %ld bytes\n", size);
	printf("* KEY: [DIR] = directory, [---] = other\n");
}