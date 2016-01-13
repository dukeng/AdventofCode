/*
 * day1.c
 *
 *  Created on: Dec 7, 2015
 *      Author: User
 */
#include <stdlib.h>
#include <stdio.h>


int main(){
	FILE* ifp;
	ifp= fopen("day1.txt","r");
	if (ifp == NULL) {
		printf("Cannot open input file %s\n", "day1.txt");
		exit(EXIT_FAILURE);
	}
	char juan;
	int k=0;
	int count=0;
	while(!feof(ifp)){
		juan= fgetc(ifp);
		count++;
		if(juan== '('){k++;};
		if(juan== ')'){
			k--;
			if(k<0){
				break;
			}
		}
	}
	printf("Part 1 answer: %d\n",k);
	printf("Part 2 answer: %d", count);
	fclose(ifp);
	return 1;
}
