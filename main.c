#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

int main() {
	struct DIR *direct = opendir(".");
	long size = 0;
	
	if (direct < 0) {
		printf("Error Opening Assignment Directory: %s\n", strerror(errno));
		return 0;
	}
	struct dirent *file;
	printf("-----Examining Current Assignment Directory-----\n");
	while ((file = readdir(direct)) != NULL) {
		int dirCheck = file->d_type;
		if (dirCheck == 4) {
			printf("[dir]");
		}
		else {
			printf("[---]");
		}
		struct stat fileStats;
		if (stat(file->d_name, &fileStats) < 0) {
			printf("Error w/ stat: %s\n", strerror(errno));
			return 0;
		}
		size += fileStats.st_size;
		printf(" : %s\n", file->d_name);
	}
	printf("TOTAL SIZE: %ld bytes\n", size);
	printf("*** NOTE: [dir] = directory, [---] = other\n");
}