/*
  2022年9月28日00点12分
  队列
  特点：先进先出
  要实现的功能：初始化，增加节点，删除节点（先进先出），遍历
 */

#include<stdio.h>
#include <malloc.h>
#include<stdbool.h>

typedef struct team {
	int data;
	struct team* next;
} team;

team* InitTeam (){
	team* headteam = (team*)malloc(sizeof(team));
	headteam->data = 0;
	headteam->next = NULL;
	return headteam;
}

bool IsEmpty (team* HeadTeam){
	if(HeadTeam->data == 0 || HeadTeam->next == NULL){
		return true;
	}else{
		return false;
	}
}

void InsertTeam (team* HeadTeam,int data){
	team* Node = (team*)malloc(sizeof(team));
	team* backUp = HeadTeam;
	if(IsEmpty(HeadTeam)){
		Node->data = data;
		Node->next = HeadTeam->next;
		HeadTeam->next = Node;
		HeadTeam->data++;
	}else{
		while(backUp->next){
			backUp = backUp->next;
		}
		Node->data = data;
		Node->next = backUp->next;
		backUp->next = Node;
		HeadTeam->data++;
	}
}

void printTeam (team* HeadTeam){
	team* backUp = HeadTeam->next;
	while(backUp){
		printf ("%d",backUp->data);
		backUp = backUp->next;
	}
}

void deleteTeam (team* HeadTeam){
	int i;
	team* pre = HeadTeam;
	team* current = HeadTeam->next;
	if(IsEmpty(HeadTeam)){
		printf ("this is a empty team");
	}else{
/*		i = current->data;*/
		pre->next = current->next;
		free(current);
		HeadTeam->data--;
/*		return i;*/
	}
}

int main (){
	team* NewTeam = InitTeam();
	InsertTeam(NewTeam,1);
	InsertTeam(NewTeam,2);
	InsertTeam(NewTeam,3);
	deleteTeam(NewTeam);

	printTeam(NewTeam);
}
