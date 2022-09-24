/*
  2022年9月24日10点55分
  双循环链表
  目的：初始化，头插法，尾插法，删除
 */

#include <stdio.h>
#include <malloc.h>

struct Node {
	int data;
	struct Node* pre;
	struct Node* next;
};

struct Node* InitList () {
	struct Node* list = (struct Node*)malloc(sizeof(struct Node));
	list->data = 0;
	list->next = list;
	list->pre = list;
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
		headlist->next->pre = list;
		headlist->next = list;
		list->pre = headlist;
		list->next = headlist->next;
	}
	headlist->data++;
}

//尾插法
void tailInsert (struct Node* headlist, int data) {
	struct Node* list = (struct Node*)malloc(sizeof(struct Node));
	struct Node * BackupList = headlist;
	while (BackupList->next != headlist) {
		BackupList = BackupList->next;
	}
	list->data = data;
	list->next = headlist;
	list->pre = BackupList;
	BackupList->next = list;
	headlist->pre = list;
}

//删除
void deleteNode (struct Node* headlist, int data) {
	struct Node* pre = headlist;
	struct Node* current = headlist->next;
	struct Node* BackupList = headlist;
	while (BackupList->next != headlist) {
		if (current->data == data) {
			current->next->pre = pre;
			pre->next = current->next;
			free(current);
			break;
		}
		pre = current;
		current = current->next;
	}
}

//遍历数组
void printList(struct Node* list) {
	struct Node* BackupList = list->next;
	while (BackupList != list) {
		printf ("%d->", BackupList->data);
		BackupList = BackupList->next;
	}
	printf ("%d",list->data);
}



int main () {
	struct Node* list = InitList();
	headInsert(list, 1);
	headInsert(list, 2);
	tailInsert(list, 12);
	headInsert(list, 3);
	headInsert(list, 4);
	headInsert(list, 5);
	tailInsert(list, 6);
	tailInsert(list, 7);
	tailInsert(list, 8);
	deleteNode(list, 4);
	printList(list);
}
