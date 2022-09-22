/*
  自己写的链表
  所实现的功能：创建一个链表，头插法，尾插法，删除
 */

#include <stdio.h>
#include <malloc.h>

struct Node {
	int data;
	struct Node* next;
};

//链表的初始化（创建链表）
struct Node* initList () {
	struct Node* headlist = (struct Node*)malloc(sizeof(struct Node));
	headlist->data = 0;               //创建的头链表所指向的数据是用来记录链表的个数的
	headlist->next = NULL;
	return headlist;
}

//头插法
void headinsert (struct Node* list, int data) {
	struct Node* headinsertNode = (struct Node*)malloc(sizeof(struct Node));
	headinsertNode->next = list->next;
	headinsertNode->data = data;
	list->next = headinsertNode;
	(list->data)++;
}

//尾插法
void tailinster (struct Node* list,int data){
	struct Node* backupList = list;
	struct Node* tailinsertNode = (struct Node*)malloc(sizeof(struct Node));
	while(list->next){
		list = list->next;
	}
	list->next = tailinsertNode;
	tailinsertNode->data = data;
	tailinsertNode->next = NULL;
	(backupList->data)++;
}

//删除节点
void delete (struct Node* list,int data){
	struct Node* pre = list;
	struct Node* current = list->next;
	while(current){
		if(current->data = data){            //(错在这里，=是赋值，==才是判断)
			pre->next = current->next;
			free(current);
			break;
		}
		pre = current;                     //先前的节点后移一个
		current = current->next;           //当前的节点后移一个
	}
	list->data--;
}

//遍历节点
void printLit (struct Node*headlist){
	struct Node* list = headlist->next;      //头节点的下一个节点，也就是说节点的初始
	while(list){
		printf ("%d",list->data);
		list = list->next;
	}
	printf ("\n");
}

int main (){
	struct Node* list = initList();
	headinsert(list,1);
	headinsert(list,2);
	headinsert(list,3);
	tailinster(list,4);
	tailinster(list,5);
	tailinster(list,6);
	printLit(list);
	delete(list,5);
	printLit(list);
}
