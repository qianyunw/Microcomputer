// os_memory1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string> 
using namespace std;
//ctrl+F5:�������˵���

int main()
{
	cout << "����b" << endl;
	int b;
	cin >> b;
	int M0, M1, M2, M3, M4, M5;
	while (b != 99) {
		M5 = b / 32;
		M4 = b % 32 / 16;
		M3 = b % 16 / 8;
		M2 = b % 8 / 4;
		M1 = b % 4 / 2;
		M0 = b % 2 / 1;
		cout << M5 <<" " << M4 << " " << M3 << " " << M2 << " " << M1 << " " << M0 << endl;
		cout <<"M0*1 + M1*2 + M2*4 + M3*8 + M4*16 + M5*32 = "<< M0 * 1 + M1 * 2 + M2 * 4 + M3 * 8 + M4 * 16 + M5 * 32 <<endl;
		cout << "����b" << endl;
		cin >> b;
	}
}

