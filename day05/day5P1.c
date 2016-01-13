/*
 ============================================================================
 Name        : day5P1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool teststring3(char c[]){
	int k;
	int count=0;
	for(k=0;k<17;k++){
		if(c[k]==c[k+1]){
			return true;
		}
	}
	return false;
}
bool teststring2(char c[]){
	int k;
	int count=0;
	for(k=0;k<17;k++){
		if(c[k]=='a' || c[k]=='e' || c[k]=='i' || c[k]=='o' || c[k]=='u'){
			count++;
		}
	}
	if(count>=3){
		return true;
	}
	else{
		return false;
	}
}
bool teststring(char c[]){
	int k;
	int count=0;
	for(k=0;k<17;k++){
		if(c[k]=='a'&& c[k+1]=='b'){count++;}
		if(c[k]=='c'&& c[k+1]=='d'){count++;}
		if(c[k]=='p'&& c[k+1]=='q'){count++;}
		if(c[k]=='x'&& c[k+1]=='y'){count++;}

	}
	if(count>0){
		return false;
	}
	else{
		return true;
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
			if(teststring(c) ){
				if(teststring2(c)){
					if(teststring3(c)){
						printf("Nice string is: ->%s<-\n",c);
						nice++;
					}
				}

			}
			count++;

		}
	}
	printf("nice:%d\n",nice);
	printf("total:%d\n",count);
	return EXIT_SUCCESS;
}
