/*
  2022年10月13日21点39分
  哈希表
 */

#include <stdio.h>
#include <malloc.h>

#define NUM 5

typedef struct HashList {
	int num;         //当前哈希表中有多少个元素
	char * data;     //数据的指针
}HashList;

HashList* initList (){
	HashList* list = (HashList*)malloc(sizeof(HashList));
	list->num = 0;                 //哈希表中当前元素的个数，初始化为0
	list->data = (char*)malloc(sizeof(char)*NUM);      //为data指针分配空间
	//为data赋初始值
	for(int i=0;i<NUM;i++){
		list->data[i] = 0;
	}
	return list;
}

int hash (int data){
	return data%NUM;
}

//往哈希表里放值
void Hasput (HashList* list,char data){
	int index = hash(data);                //算出哈希值
	if(list->data[index] != 0){
		int count = 1;
		while(list->data[index] != 0){
			index = hash(hash(index)+count);
			count++;
		}
	}
	list->data[index] = data;
}

int main (){
	HashList* list = initList();
	Hasput(list,'A');
	Hasput(list,'B');
	printf("%c",list->data[1]);
}
