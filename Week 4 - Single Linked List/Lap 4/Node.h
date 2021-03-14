#pragma once
#include<iostream>
using namespace std;

struct NODE {
	int data;
	NODE* pNext;
};

struct LIST {
	NODE* pHead;
	NODE* pTail;
};
void Init(LIST& l);
NODE* createNode(int data);
void Output(LIST l);
NODE* addFirst(LIST& l, int data);
NODE* addTail(LIST& l, int data);
NODE* insertAfterQ(LIST& l, NODE* p, NODE* q);
NODE* InsertBeforeQ(LIST& l, NODE* p, NODE* q);
void deleteAfterQ(LIST& l, NODE* q);
void deleteList(LIST& l);
//bai 2
void deleteHead(LIST& l);
void deleteTail(LIST& l);
int getTail(LIST l);
int getHead(LIST l);
int Get(LIST l, int index);
NODE* Search(LIST l, int key);
int listLen(LIST l);
LIST Noi(LIST l1, LIST l2);
