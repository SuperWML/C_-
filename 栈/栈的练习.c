/*
  2022年10月15日23点29分
  栈
 */

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct stack {
	int data;
	struct stack* next;
} stack;

stack* InitStack () {
	stack* list = (stack*)malloc(sizeof(stack));
	list->data = 0;
	list->next = NULL;
	return list;
}

void putStack (stack* list, int data) {
	stack* BackupList = list;
	stack* Node = (stack*)malloc(sizeof(stack));
	Node->data = data;
	Node->next = list->next;
	BackupList->next = Node;
}

void printStack (stack* list) {
	stack* BackupList = list->next;
	while (BackupList) {
		printf ("%d", BackupList->data);
		BackupList = BackupList->next;
	}
}

bool Isempty (stack* list) {
	stack* BackupStack = list->next;
	if (BackupStack == NULL) {
		return true;
	} else {
		return false;
	}
}

void popStack (stack* list) {
	if (Isempty(list)) {
		printf ("这是一个空栈");
	} else {
		stack* pre = list;
		stack* cur = list->next;
		pre->next = cur->next;
		free(cur);
	}
}

int main () {
	stack* list = InitStack();
	putStack(list, 1);
	putStack(list, 2);
	popStack(list);
	printStack(list);
}
