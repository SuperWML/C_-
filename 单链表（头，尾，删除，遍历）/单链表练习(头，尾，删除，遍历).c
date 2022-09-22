/*
  2022年9月22日15点54分
  自己写的单链表
  具体功能：单链表的创建，头插法，尾插法，删除
 */

#include <stdio.h>
#include <malloc.h>

struct Node {
	int data;
	struct Node* next;
};

//单链表的创建
struct Node* initList (){
	struct Node* list = (struct Node*)malloc(sizeof(struct Node));
	list->next = NULL;
	list->data = 0;
	return list;
};

//单链表的输出
void printList (struct Node* headlist){
	struct Node* list = headlist->next;
	while(list){
		printf ("%d",list->data);
		list = list->next;
	}
	printf ("\n");
}

//头插法
void headinsert (struct Node* headlist,int data){
	struct Node* list = (struct Node*)malloc(sizeof(struct Node));
	list->next = headlist->next;
	list->data = data;
	headlist->next = list;
	(headlist->data)++;
}

//尾插法
void tailinsert (struct Node* headlist,int data){
	struct Node* backupList = headlist;
	struct Node* list = (struct Node*)malloc(sizeof(struct Node));
	while(backupList->next){
		backupList = backupList->next;
	}
	backupList->next = list;
	list->data = data;
	list->next = NULL;
	(headlist->data)++;
}

//删除节点
void deleteNode (struct Node* headList,int data){
	struct Node* pre = headList;
	struct Node* current = headList->next;
	while(current){
		if(current->data == data){
			pre->next = current->next;
			free(current);
			break;
		}
		pre = current;                    //先前的节点后移一个
		current = current->next;          ////当前的节点后移一个
	}
	(headList->data)--;
}

int main (){
	struct Node* list = initList();
	tailinsert(list,4);
	tailinsert(list,5);
	headinsert(list,1);
	headinsert(list,1);
	deleteNode(list,5);
	printList(list);
	printf("%d",list->data);
	
}
