/*
  2022年9月16日17点27分
  数据结构，连续数组的学习
  目的：想要知道什么是数组
 */

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

struct Arr{
	int cnt;       //用于存储数组的可用个数
	int len;       //用于存储数组的长度
	int*Pbase;     //用来表示数组的地址（代表整个数组）
};

bool isempty (struct Arr* pArr){
	if(0 == pArr->cnt){
		return true;
	}else{
		return false;
	}
}

void show(struct Arr*a){
	if(isempty(a)){
		printf ("该数组为空！\n");
	}else {
		for(int i=0;i<=a->cnt;i++){
			printf ("%d",(a->Pbase)[i]);           //注意要输出整型数组的指
		}
	}
}



void init_Arr(struct Arr* pMove,int length){
	pMove = (struct Arr*)malloc(sizeof(int)*length);
	if(NULL==pMove->Pbase){
		printf ("动态内存分配失败！\n");
		exit(-1);
	}else{
		pMove->len = length;
		pMove->cnt = 0;
	}
}

int main(){
	struct Arr arr;
	init_Arr(&arr,6);
	show(&arr);
}







