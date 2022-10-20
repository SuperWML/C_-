/*
  2022年9月26日13点52分
  栈
  要实现的功能：栈的初始化，出栈，入栈，判断栈是否为空
 */

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

//初始化栈
Node* Initstack () {
	Node* stack = (Node*)malloc(sizeof(Node));
	stack->next = NULL;
	stack->data = 0;
	return stack;
}

//判断栈是否为空
bool IsEmpty (Node* stack) {
	if (stack ->next == NULL || stack->data == 0) {
		return true;
	} else {
		return false;
	}
}

//弹出
int pop(Node* stack) {
	if (IsEmpty(stack)) {
		return -1;
	} else {
		return stack->next->data;
	}
}

//出栈
int popstack(Node*stack) {
	Node* pre = stack;
	Node* current = stack->next;

	if (IsEmpty(stack)) {
		return -1;
	} else {
		pre->next = current->next;
		int data = current->data;                  //记录删除节点的数值
		free(current);
		return data;
	}
}

//压栈(其实就是头插法)
void push(Node* Headstack, int data) {
	Node* stack = (Node*)malloc(sizeof(Node));
	stack->data = data;
	stack->next = Headstack->next;
	Headstack->next = stack;
	Headstack->data++;
}

//遍历栈
void printstack (Node* Headstack) {
	Node* stack = Headstack->next;
	if (Headstack->data != 0) {
		while (stack) {
			printf ("%d", stack->data);
			stack = stack->next;
		}
	} else {
		printf ("这是一个空栈！");
	}
}

int main () {
	Node* stack = Initstack();
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	int i = popstack(stack);
	printf("%d\n",i);        //用于输出删除的头栈数字
	printstack(stack);
}
