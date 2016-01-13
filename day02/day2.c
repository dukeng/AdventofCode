/*
 * day2.c
 *
 *  Created on: Dec 7, 2015
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
	int area1;
	int area2;
	int area3;
	printf("Start\n");
	double min=0;
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

		area1=2*a*b;
		area2=2*b*c;
		area3=2*c*a;
		//printf("%d %d %d \n",area1,area2,area3);
		subtotal=area1+area2+area3;

		min=area1;
		if(area2<=min){
			min=area2;
			if(area3<=min){
				min=area3;
			}
		}
		else if (area2>=min){
			if(area3<=min){
				min=area3;
			}
		}// cri
		min=min/2.0;
		subtotal= subtotal+min;
		printf("%d+%d+%d+%lf=%lf\n", area1,area2,area3, min, subtotal);
		total=total+subtotal;

	}// end of big while loop
	printf("answer is: %f", total);

	printf("\nEnd");
	fclose(ifp);
	return 1;
}
