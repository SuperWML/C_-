/*
  2022年10月13日22点07分
  哈希表自己的练习2
 */

#include<stdio.h>
#include<malloc.h>
#define NUM 5

typedef struct HashList{
	int num;
	char* data;
} HashList;

HashList* initHashList (){
	HashList* list = (HashList*)malloc(sizeof(HashList));
	list->num = 0;
	list->data = (char*)malloc(sizeof(char)*NUM);
	for(int i=0;i<NUM;i++){
		list->data[i] = 0;
	}
	return list;
}

int hash (int data){
	return data%NUM;
}

void putHashList (HashList* list,char data){
	int index = hash(data);
	if(list->data[index] != 0){
		int count = 1;
		while(list->data[index] != 0){
			index = hash(hash(index)+count);
			count++;
		}
		list->data[index] = data;
	}else{
		list->data[index] = data;
	}
}

int main (){
	HashList* list = initHashList();
	putHashList(list,'A');
	putHashList(list,'B');
	printf("%c",list->data[1]);
}
