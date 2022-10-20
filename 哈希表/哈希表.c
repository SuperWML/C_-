/*
  2022年10月12日22点12分
  哈希表
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define NUM 5

typedef struct HashList {
	int num;             //当前哈希表里有多少个指
	char* data;           //每个节点放的东西
} HashList;

//哈希表初始化的函数
HashList* initList (){
	HashList* list = (HashList*)malloc(sizeof(HashList));
	list->num = 0;
	list->data = (char*)malloc(sizeof(HashList));              //data是char类型的指针，所有的指针都需要开辟空间
	//给哈希表里面的data赋初值
	for (int i = 0;i<NUM;i++){
		list->data[i] = 0;
	}
	return list;
}

//设计哈希函数
int hash (int data){
	return data % NUM;
}

//在哈希表里面放值
void put (HashList* list,char data){
	int index = hash(data);
	if(list->data[index] != 0){
		int count = 1;                           //线性哈希运算的计数器
		while(list->data[index] != 0){
			index = hash(hash(data)+count);
			count++;
		}
		list->data[index] = data;
	}else {
		list->data[index] = data;
	}
}

int main (){
	HashList* list = initList();
	put(list,'A');
	put(list,'F');
	printf("%c\n",list->data[0]);
}
