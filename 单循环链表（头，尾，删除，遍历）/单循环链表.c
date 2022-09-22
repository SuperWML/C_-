/*
  单循环链表
  所实现的功能：创建，头插，尾插，删除
 */

#include <stdio.h>
#include <malloc.h>

struct Node {
	int data;
	struct Node* next;
};

//初始化单链表循环节点
struct Node* initList() {
	struct Node* List = (struct Node*)malloc(sizeof(struct Node));
	List->data = 0;
	List->next = List;
	return List;
};

//头插法
void headinsert (struct Node* headlist,int data){
	struct Node* list = (struct Node*)malloc(sizeof(struct Node));
	list->next = headlist->next;
	list->data = data;
	headlist->next = list;
}

//尾插法
void tailinsert (struct Node* headlist,int data){
	struct Node* list = (struct Node*)malloc(sizeof(struct Node));
	struct Node* backupNode = headlist;
	while(backupNode->next != headlist){
		backupNode = backupNode->next;
	}
	list->data = data;
	list->next = headlist;
	backupNode->next = list;
}

//遍历单循环链表
void printList (struct Node* headlist){
	struct Node* backupList = headlist->next;
	while(backupList != headlist){
		printf ("%d",backupList->data);
		backupList = backupList->next;
	}
}

void deleteList (struct Node* headlist,int data){
	struct Node* pre = headlist;
	struct Node* current = headlist->next;
	struct Node* pMove = headlist;
	while(pMove->next != headlist){
		if(current->data == data){
			pre->next = current->next;
			free(current);
			break;
		}
		pre = current;
		current = current->next;
	}
}

int main (){
	struct Node* list = initList();
	headinsert(list,1);
	headinsert(list,2);
	headinsert(list,3);
	tailinsert(list,4);
	tailinsert(list,5);
	tailinsert(list,6);
	deleteList(list,4);
	printList(list);
}
