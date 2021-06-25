#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NAME_MAX 256

char *strupr(char *s) {
	char *p=s;
	while(*p) {
		*p=toupper(*p);
		p++;
	}
	return s;
}

int main(void) {

	char *casts[]={
		"Harry Potter",
		"Ron Weasley",
		"Hermione Granger",
		"Severus Snape",
		"Albus Dumbledore",
		"Rubeus Hagrid",
		"Tom Riddle",
		NULL
	};

	char name[NAME_MAX];
	char uprname[NAME_MAX];
	char uprcast[NAME_MAX];
	char *p;
	int found;

	for(;;) {

		printf("Search for casts of movie 'Harry Potter': ");
		fgets(name,NAME_MAX-1,stdin);
		p=strchr(name,'\n'); if(p) *p='\0';

		if(!name[0]) break;

		strcpy(uprname,name);
		strupr(uprname);

		found=0;
		for(int i=0;casts[i];i++) {

			strcpy(uprcast,casts[i]);
			strupr(uprcast);

			if(!strcmp(uprcast,uprname)) {
				printf("yes we've %s!\n",casts[i]);
				found=1;
				break;
			} else if(strstr(uprcast,uprname)) {
				printf("did you mean %s!\n",casts[i]);
				found=1;
				break;
			}
		}

		if(!found) {
			printf("sorry we'vent have %s.\n",name);
		}
	}

	printf("Thank you please come again.\n");

	return 0;
}
