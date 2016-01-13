/*
 * day2P2.c
 *
 *  Created on: Dec 9, 2015
 *      Author: User
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void count(char line[10],int* index1, int*index2){
	int k=0;
	while(line[k]!='\0'){
		if(k<3){
			if(line[k]=='x'){
				*index1=k;
			}
		}
		if(k>=3){
			if(line[k]=='x'){
				*index2=k;
			}
		}

		k++;
	}
}

int cmparea(int a,int b,int c){
	int min=a;
	if(b<min){
		min=b;
		if(c<min){
			min=b;
		}

	}
	else if (b>min){
		if(c<min){
			min=c;
		}
	}
	return min;
}

int main(){
	FILE* ifp;
	ifp=fopen("input.txt","r");
	int a,b,c;
	b=0;c=0;
	char line[10];
	int k=0;
	int index1,index2;
	double total=0;
	double subtotal;
	int volume;
	int small1;
	int small2;
	printf("Start\n");
	double max=0;
	while(fgets(line,10,ifp)!=NULL){
		count(line,&index1,&index2);
		if (index1==1){
			a=line[0]-'0';
			if(index2==3){
				b=(line[2]-'0');
				k=4;
				c=0;
				while(k<strlen(line)-1){
					c= c*10+(line[k]-'0');
					k++;
				}
			}
			if(index2==4){
				b=(line[3]-'0')+(line[2]-'0')*10;
				k=5;
				c=0;
				while(k<strlen(line)-1){
					c= c*10+(line[k]-'0');
					k++;
				}

			}
		}
		else{
			a=(line[1]-'0')+(line[0]-'0')*10;
			if(index2==4){
				b=(line[3]-'0');
				k=5;
				c=0;
				while(k<strlen(line)-1){
					c= c*10+(line[k]-'0');
					k++;
				}

			}
			if(index2==5){
				b=(line[4]-'0')+(line[3]-'0')*10;
				k=6;
				c=0;
				while(k<strlen(line)-1){
					c= c*10+(line[k]-'0');
					k++;
				}
			}

		}
		volume=a*b*c;
		if(a>=b){
			if(a>=c){
				small1=2*c;
				small2=2*b;
			}
			else{
				small1=2*a;
				small2=2*b;
			}
		}
		else{
			if(b>=c){
				small1=2*a;
				small2=2*c;
			}
			else{
				small1=2*a;
				small2=2*b;

			}
		}


		subtotal=volume+small1+small2;
		printf("%dx%dx%d\n", a,b,c);
		printf("%d+%d+%d=%lf\n", volume,small1,small2, subtotal);
		total=total+subtotal;

	}// end of big while loop
	printf("answer is: %f", total);

	printf("\nEnd");
	fclose(ifp);
	return 1;
}
