/*
  栈
  自己的练习
  实现的功能：栈的初始化，增加，删除，判断是否为空
 */

#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

Node* InitNode (){
	Node* stack = (Node*)malloc(sizeof(Node))
}
