#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;




void read_AndWriteInteger(ifstream& fileIn, ofstream& fileOut, int* a, int& n);

int countRows(ifstream& fileIn);
int countColumns(ifstream& fileIn);
void readMatrix(ifstream& fileIn, int** a, int row, int column, ofstream& fileOut);


void cau1(ifstream& fileIn, ofstream& fileOut, int *a, int& n);
void cau2Va3(ifstream& fileIn, ofstream& fileOut, int**& a, int rows, int columns);
//cau 4-5: trong file Fraction.h
