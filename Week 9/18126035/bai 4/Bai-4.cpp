#include <iostream>
#include <fstream>
#include <string>
using namespace std;

long long int CongNP(int np1,int np2)
{
    int sum[20];
    int i = 0, r = 0;
    while (np1 != 0 || np2 != 0)
    {
        sum[i++] = (int)((np1 % 10 + np2 % 10 + r) % 2);
        r = (int)((np1 % 10 + np2 % 10 + r) / 2);
        np1 = np1 / 10;
        np2 = np2 / 10;
    }
    if (r != 0) {
        sum[i++] = r;
    }
    --i;

    while (i >= 0) {
        return(sum[i--]);
    }
}
int bit(int a, int k) {
    int j = 1;
    if (a & (j << k))
        return(1);
    return(0);
}
long long int Convert2_10(long long int a)
{
    long long int num = a;
    long long int dec_value = 0;

    int base = 1;

    long long int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }
    return dec_value;
}
long int addition(long long int a, long  long int b) {
    return Convert2_10(a)+ Convert2_10(b);
}
long int subtraction(long long int a, long  long int b) {
    return Convert2_10(a) - Convert2_10(b);
}
long int multiply(long long int a, long  long int b) {
    return Convert2_10(a) * Convert2_10(b);
}
bool compare(long long int a, long  long int b) {
    cout << boolalpha;
    if (Convert2_10(a) == Convert2_10(b))
        return true;
    else
        return false;
}
void Convert10_2_Xuat(fstream &xuat_File,int cur, long int dec)
{
    long long int binaryNum[32];


    xuat_File.seekg(cur);
    xuat_File << endl;

    for (int i = 31; i >= 0; i--) {
        int k = dec >> i;
        if (k & 1)
            xuat_File << "1";
        else
            xuat_File << "0";
    }

}
long long int AND(long long int a, long  long int b)
{
    return Convert2_10(a) & Convert2_10(b);
}
long long int OR(long long int a, long  long int b)
{
    return Convert2_10(a) | Convert2_10(b);
}
long long int XOR(long long int a, long  long int b)
{
    return Convert2_10(a) ^ Convert2_10(b);
}
long long int NOT(long long int a)
{
    return ~(a) ;
}

long long int Phai(long long int a,int b)
{
    return a >> b;
}
long long int Trai(long long int a, int b)
{
    return a << b;
}
int main()
{
    fstream doc_File;
    fstream xuat_File;
    doc_File.open("Input.txt",ios::in);
    xuat_File.open("Output.txt", ios::out);
    int mode[20];
    long long int np1,np2,np3,np4,np5,np6,np7,np8,np9,np10;
    char phep_Tinh, phep_Tinh_2,phep_Tinh_3, phep_Tinh_4;
    doc_File >> mode[0];
    doc_File >> mode[1];
    doc_File >> np1;
    
    doc_File >> mode[2];
    doc_File >> mode[3];    
    doc_File >> np2;
    //------------------chuyển 2->10---------------
    if (mode[0] == 2 && mode[1] == 10)
    {
        xuat_File<<Convert2_10(np1);
    }


    int cur = xuat_File.tellg();
    //----------------chuyển 10->2-----------------
    if (mode[2] == 10 && mode[3] == 2)
    {

        Convert10_2_Xuat(xuat_File,cur,np2);
        
    }

    
    
    doc_File >> mode[4];
    doc_File >> np3;
    doc_File >> phep_Tinh;
    doc_File >> np4;
    int cur_2=xuat_File.tellg();
    //------------phép cộng----------------
    if (mode[4] == 2)
    {
        if (phep_Tinh == '+')
        {
            Convert10_2_Xuat(xuat_File,cur_2,addition(np3, np4));
        }
    }
    doc_File >> mode[5];
    doc_File >> np5;
    doc_File >> phep_Tinh_2;
    doc_File >> np6;
    int cur_3 = xuat_File.tellg();
    //------------phép trừ----------------
    if (mode[5] == 2)
    {
        if (phep_Tinh_2 == '-')
        {
            Convert10_2_Xuat(xuat_File, cur_3, subtraction(np5, np6));
        }
    }

    doc_File >> mode[6];
    doc_File >> np7;
    doc_File >> phep_Tinh_3;
    doc_File >> np8;
    int cur_4 = xuat_File.tellg();
    //------------phép nhân----------------
    if (mode[6] == 2)
    {
        if (phep_Tinh_3 == '*')
        {
            Convert10_2_Xuat(xuat_File, cur_4, multiply(np7, np8));
        }
    }


    doc_File >> mode[7];
    doc_File >> np9;
    doc_File >> phep_Tinh_4;
    doc_File >> np10;
    int cur_5 = xuat_File.tellg();
    //------------phép so sánh----------------
    if (mode[7] == 2)
    {
        if (phep_Tinh_4 == '=')
        {
            xuat_File.seekg(cur_5);
            xuat_File << endl;
            xuat_File << boolalpha;
            xuat_File <<compare(np9, np10);
        }
    }

    //----------các phép logic:---------
    ///-------phép AND---
    long long int np11, np12,np13,np14,np15,np16,np17,np18, np19;

    char phep_Tinh_5, phep_Tinh_6,phep_Tinh_7,phep_Tinh_8;
  

    //AND
    doc_File >> mode[8];
    doc_File >> np11;
    doc_File >> phep_Tinh_5;
    doc_File >> np12;
    int cur_6 = xuat_File.tellg();
    if (mode[8] == 2 && phep_Tinh_5=='&')
    {
        xuat_File.seekg(cur_6);
        xuat_File << endl;
        Convert10_2_Xuat(xuat_File, cur_6, AND(np11, np12));
    }
    //OR
    doc_File >> mode[9];
    doc_File >> np13;
    doc_File >> phep_Tinh_6;
    doc_File >> np14;
    int cur_7 = xuat_File.tellg();
    if (mode[9] == 2 && phep_Tinh_6 == '|')
    {
        xuat_File.seekg(cur_7);
        xuat_File << endl;
        Convert10_2_Xuat(xuat_File, cur_7, OR(np13, np14));
    }
    //XOR
    doc_File >> mode[10];
    doc_File >> np15;
    doc_File >> phep_Tinh_7;
    doc_File >> np16;
    int cur_8 = xuat_File.tellg();
    if (mode[10] == 2 && phep_Tinh_7 == '^')
    {
        xuat_File.seekg(cur_8);
        xuat_File << endl;
        Convert10_2_Xuat(xuat_File, cur_8, XOR(np15, np16));
    }
    //NOT
    doc_File >> mode[11];
    doc_File >> phep_Tinh_8;
    doc_File >> np17;
    
    //cout << np17;
    int cur_9 = xuat_File.tellg();
    if (mode[11] == 10 && phep_Tinh_8 == '~')
    {
        xuat_File.seekg(cur_9);
        xuat_File << endl;
        xuat_File<<NOT(np17);
    }
    //>>
    char phep_Tinh_9[2];
    //phep_Tinh_9 = new char[2];
    int don_Vi;
    doc_File >> mode[12];
    doc_File >> np18;
    doc_File >> phep_Tinh_9[0];
    doc_File>>phep_Tinh_9[1];
    doc_File >> don_Vi;
    int cur_10 = xuat_File.tellg();
    if (mode[12] == 10 && phep_Tinh_9[0] == '>' && phep_Tinh_9[1]=='>')
    {
        xuat_File.seekg(cur_10);
        xuat_File << endl;
        xuat_File << Phai(np18,don_Vi);
    }
    // <<
    char phep_Tinh_10[2];
    //phep_Tinh_9 = new char[2];
    int don_Vi_2;
    doc_File >> mode[13];
    doc_File >> np19;
    doc_File >> phep_Tinh_10[0];
    doc_File >> phep_Tinh_10[1];
    doc_File >> don_Vi_2;
    int cur_11 = xuat_File.tellg();
    if (mode[13] == 10 && phep_Tinh_10[0] == '<' && phep_Tinh_10[1] == '<')
    {
        xuat_File.seekg(cur_11);
        xuat_File << endl;
        xuat_File << Trai(np19, don_Vi_2);
    }

   // cout << AND(np11, np12);
    


}


