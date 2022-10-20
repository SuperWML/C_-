/*
  2022年10月14日15点32分
  哈希表
 */
#include <stdio.h>
#include<malloc.h>
#define NUM 5

typedef struct HashList {
	int num;                   //用来存放哈希表中元素的个数
	char* data;
}HashList;

HashList* InitHashList (){
	HashList* list = (HashList*)malloc(sizeof(HashList));
	list->data = (char*)malloc(sizeof(char)* NUM);
	list->num = 0;
	for(int i=0;i<NUM;i++){
		list->data[i] = 0;
	}
	return list;
}

int hash(int data){
	return data%NUM;
}

void putHash (HashList* list,char data){
	int index = hash(data);
	if(list->data[index] != 0){
		int count = 1;
		while(list->data[index] != 0){
			index = hash(hash(index)+count);
			count++;
		}
		list->data[index] = data;
	}else {
		list->data [index] = data;
	}
}

int main (){
	HashList* list = InitHashList();
	putHash(list,'A');
	putHash(list,'B');
	printf("%c",list->data[1]);
}
