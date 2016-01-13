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
	int col=1;
	int row=0;
	ifp=fopen("input.txt","r");
	char c;
	LinkedList count;
	count.size = 0;
	count.head = NULL;
	firstnode(&count);
	while(!feof(ifp)){
		c=fgetc(ifp);
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

	PrintList(&count);
	answer(&count);
	return 1;
}
