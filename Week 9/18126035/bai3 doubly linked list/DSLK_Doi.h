#pragma once
#include<iostream>
#include<stdio.h>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev; 
};

struct List {
	Node* head;
	Node* tail;
};
void Init(List& l);
bool isEmpty(List l);
Node* creatNode(int x);
Node* addHead(List& l, int x);
void Xuat(List l);
Node* addTail(List& l, int x);
int Size(List l);
void addSomeWhere(List& l, int x, int k);
void delHead(List& l);
void delTail(List& l);
void deleteSomeWhere(List& l, int k);
void deleteList(List& l);
int getHead(List l);
int getTail(List l);
int Get(List l, int index);
Node* Search(List l, int key);
List Noi(List l1, List l2);