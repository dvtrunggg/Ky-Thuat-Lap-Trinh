#pragma once
#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h>
using namespace std;

//câu 2: dslk
typedef struct NODE
{
    int data;
    NODE* pNext;
};
typedef struct LIST
{
    NODE* pTail;
    NODE* pHead;
};


void InputArray(int* a, int n);
void GenerateArray(int* a, const int& n, const int min, const int max);
void PrintArray(int* a, int n);
void Swap(int& a, int& b);
void  InterchangeSort_Pointer(int* a, int n);
void Init(LIST& l);
NODE* createNode(int data);
void Output(LIST l);
void InterchangeSort_LinkedList(LIST l, int* a, int n);
void addTail(LIST& l, int data);
int listLen(LIST l);
