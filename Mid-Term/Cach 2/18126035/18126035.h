//Dinh Viet Trung - 18126035 - de 1
//doc file tu file data.txt 
//file data chua matran 



#pragma once
#include<iostream>
#include<fstream>
#include<string>
#define Min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;


void readFile(ifstream& fileName, int** a, int row, int column);
void Print(int** a, int row, int column);
int countRows(ifstream& fileName);
int countIntegers(ifstream& fileName);
bool isMagicSquare(int** a, int row, int column);
void test(int** a, int column, int row);




