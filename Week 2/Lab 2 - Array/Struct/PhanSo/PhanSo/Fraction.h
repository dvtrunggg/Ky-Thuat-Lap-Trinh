#pragma once
#include <stdio.h>
#include <iostream>
#include<conio.h>
using namespace std;
struct PhanSo
{
	float num;
	float deno;
};
typedef struct PhanSo PHANSO;


void Input(PHANSO&);
void Output(PHANSO);

float UCLN(float, float);
PHANSO RutGonPhanSo(PHANSO);
PHANSO Summation(PHANSO, PHANSO);
PHANSO Subtraction(PHANSO, PHANSO);
PHANSO Multiplication(PHANSO, PHANSO);
PHANSO Division(PHANSO, PHANSO);
bool isToiGian(PHANSO);
void QuiDong2PhanSo(PHANSO&, PHANSO&);
bool isPositive(PHANSO);
bool isNegative(PHANSO);
int SoSanh2PhanSo(PHANSO, PHANSO);
PHANSO operator +(PHANSO, PHANSO);
PHANSO operator -(PHANSO, PHANSO);
PHANSO operator *(PHANSO, PHANSO);
PHANSO operator /(PHANSO, PHANSO);

