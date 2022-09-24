/*
  2022年9月24日09点09分
  双链表
  要完成的功能：初始化，头插，尾插，删除，遍历
 */

#include<stdio.h>
#include <malloc.h>

struct Node {
	struct Node * pre;
	int data;
	struct Node* next;
};

//初始化双链表
struct Node* InitNode () {
	struct Node* list = (struct Node*)malloc(sizeof(struct Node));
	list->pre = NULL;
	list->data = 0;
	list->next = NULL;
	return list;
};

//头插法
void headInsert (struct Node* headlist, int data) {
	struct Node* list = (struct Node*)malloc(sizeof(struct Node));
	list->data = data;
	if (headlist->data == 0) {
		list->next = headlist->next;
		list->pre = headlist;
		headlist->next = list;
	} else {
		headlist->next = list;
		list->next = headlist->next;
		list->pre = headlist;
		headlist->next->pre = list;
	}
}

//遍历链表
void printList(struct Node* headList) {
	struct Node* list = headList->next;
	while (list) {
		printf ("%d", list->data);
		list = list->next;
	}
}

//尾插法
void tailinsert (struct Node* headlist, int data) {
	struct Node* list = (struct Node*)malloc(sizeof(struct Node));
	struct Node* BackupList = headlist;
	list->data = data;
	while (BackupList->next) {
		BackupList = BackupList->next;
	}
	list->next = BackupList->next;
	BackupList->next = list;
	list->pre = BackupList;
}

//删除节点
void deleteNode (struct Node* headList,int data){
	struct Node* pre = headList;
	struct Node* current = headList->next;
	while(current){
		if(current->data == data){
			current->next->pre = pre;
			pre->next = current->next;
			free(current);
			break;
		}
		pre = current;
		current = current->next;
	}
}

int main () {
	struct Node* list = InitNode();
	headInsert(list, 1);
	headInsert(list, 2);
	tailinsert(list, 3);
	tailinsert(list, 4);
	tailinsert(list, 5);
	deleteNode(list,3);
	deleteNode(list,2);
	printList(list);
}
