/*
 ============================================================================
 Name        : day3p2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * day3p1.c
 *
 *  Created on: Dec 10, 2015
 *      Author: User
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct ListNode{
	int row;
	int col;
	struct ListNode* next;
} ListNode;
typedef struct{
	ListNode*head;
	int size;
} LinkedList;

void Addhouse(LinkedList* list,int rowadd, int coladd){
	ListNode* newNode;
	newNode=(ListNode*)malloc(sizeof(ListNode));
	/*if(list->head==NULL){
		newNode->row=rowadd;
		newNode->col=coladd;
		newNode->next=NULL;
		list->head=newNode;
		list->size++;
	}*/
		newNode->row=rowadd;
		newNode->col=coladd;
		newNode->next=list->head;
		list->head=newNode;
		list->size++;
}
void Comparehouse(LinkedList* list, int rowadd, int coladd){
	ListNode* currentNode= list->head;
	int count=0;
	while(currentNode!=NULL){
		if(coladd==currentNode->col && rowadd==currentNode->row){
			count++;
		}
		currentNode=currentNode->next;
	}
	if(count==0){
		Addhouse(list,rowadd,coladd);
	}
}
void PrintList(LinkedList* list){
	printf("Size = %d. Contents:", list->size);
	ListNode* currentNode= list->head;
	while(currentNode!= NULL){
		printf("\n%d, %d", currentNode->row,currentNode->col);
		currentNode = currentNode-> next;
	}
	printf("\n");
}
void answer(LinkedList* list){
	printf("Number of houses: %d",list->size);
}
void firstnode(LinkedList* list){
	ListNode* newNode;
	newNode=(ListNode*)malloc(sizeof(ListNode));
	newNode->row=0;
	newNode->col=0;
	newNode->next=list->head;
	list->head=newNode;
	list->size++;
}
int main(){
	FILE* ifp;
	int col=0;
	int row=0;
	int col1=0;
	int row1=0;
	ifp=fopen("input.txt","r");
	char c;
	LinkedList count;
	count.size = 0;
	count.head = NULL;
	firstnode(&count);
	int k=0;
	while(!feof(ifp)){
		c=fgetc(ifp);
		if(k%2==0){
			if(c=='>'){
				row=row+1;
				Comparehouse(&count,row,col);
			}
			else if(c=='<'){
				row=row-1;
				Comparehouse(&count,row,col);
			}
			else if(c=='v'){
				col=col-1;
				Comparehouse(&count,row,col);
			}
			else if(c=='^'){
				col=col+1;
				Comparehouse(&count,row,col);
			}
		}
		else if(k%2==1){
			if(c=='>'){
				row1=row1+1;
				Comparehouse(&count,row1,col1);
			}
			else if(c=='<'){
				row1=row1-1;
				Comparehouse(&count,row1,col1);
			}
			else if(c=='v'){
				col1=col1-1;
				Comparehouse(&count,row1,col1);
			}
			else if(c=='^'){
				col1=col1+1;
				Comparehouse(&count,row1,col1);
			}
		}
		k++;
	}

	PrintList(&count);
	answer(&count);
	return 1;
}
