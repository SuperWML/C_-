/*
  2022年10月20日23点01分
  队
 */

#include <stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct Stack {
	int data;
	struct Stack* next;
} Stack;

Stack* InitStack (){
	Stack* list = (Stack*)malloc(sizeof(Stack));
	list->data = 0;
	list->next = NULL;
	return list;
}

bool IsEmpty (Stack* list){
	if(list->next == NULL){
		return true;
	}else{
		return false;
	}
}

void InputList (Stack* list,int data){
	Stack* Backuplist = list;
	Stack* Node = (Stack*)malloc(sizeof(Stack));
	if(IsEmpty(Backuplist)){
		Node->data = data;
		Node->next = Backuplist->next;
		Backuplist->next = Node;
	}else{
		while(Backuplist->next){
			Backuplist = Backuplist->next;
		}
		Node->data = data;
		Node->next = Backuplist->next;
		Backuplist->next = Node;
	}
	
}

void printList (Stack* list){
	Stack* BackupList = list->next;
	while(BackupList){
		printf ("%d",BackupList->data);
		BackupList = BackupList->next;
	}
}

void deletNode (Stack* list){
	Stack* pre = list;
	Stack* cur = list->next;
	pre->next = cur->next;
	free(cur);
}
int main (){
	Stack* list = InitStack();
	InputList(list,1);
	InputList(list,2);
	InputList(list,3);
	deletNode(list);
	deletNode(list);
	printList(list);
}
