/*
 * day5p2.c
 *
 *  Created on: Dec 11, 2015
 *      Author: User
 */
/*
 ============================================================================
 Name        : day5P1.c
 Author      : Duke Nguyen
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool teststring2(char c[]){
	int k;
	int count=0;
	for(k=0;k<15;k++){
		if(c[k]==c[k+2]){
			count++;
		}
	}
	if(count>0){
		return true;
	}
	else{
		return false;
	}
}
bool teststring(char c[]){
	int k;
	int count=0;
	int h;
	char a;
	char b;
	for(k=0;k<17;k++){
		a=c[k];
		b=c[k+1];
		for(h=k+2;h<17;h++){
			if(c[h]==a && c[h+1]==b){
				count++;
			}
		}
	}
	if(count>0){
		return true;
	}
	else{
		return false;
	}
}

int main(void) {
	FILE* ifp;
	ifp=fopen("input.txt","r");
	char c[18];
	int nice=0;
	int count=0;
	int k;
	while(fgets(c,18,ifp)!=NULL){
		if(c!=NULL){
			if(teststring(c)){
				if(teststring2(c)){
						printf("Nice string is: ->%s<-\n",c);
						nice++;
				}

			}
			count++;

		}
	}
	printf("nice:%d\n",nice);
	printf("total:%d\n",count);
	return EXIT_SUCCESS;
}


