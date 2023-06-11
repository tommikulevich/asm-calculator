// Addem Main Program      (AddMain.cpp) 

#include <iostream>
using namespace std;

extern "C" int addem(int p1, int p2, int p3);	// w = x + y + z
extern "C" int fun(int x, int y, int z);		// w = 20*p3^2 - 100*p2 + p1
extern "C" int fun2(char *strx, int *Slen);		// zamiana w tablicy znakowej strx malych liter na wielkie oraz
												// wyznaczenie Slen - d³ugoœci ³añcycha znaków zapisanych w strx
extern "C" int fun3(int x);						// x = x + 10
extern "C" int min1(int x);						// x = x - 1

int main()
{
	const int BUFSIZE = 200;
	char buffer[BUFSIZE];
	char buffer1[BUFSIZE] = "abcdefghijkabcdefghijkabcdefghijkddd\0";
	int buffer2[BUFSIZE] = { 48, 49, 50, 51, 52, 53, 54, 55, 56, 57 };
	int count;				// loop count
	int p1, p2, p3;
	int i;
	int strlen;
	
	//*****************************************************
	
	int total = addem(10, 15, 25);
	cout << "Total = " << total << endl << min1(5) << endl;

	//*****************************************************

	p1 = 20;  p2 = 15;  p3 = -2;
	int wynik = fun(p1, p2, p3);
	cout << "Wartosc funkcji w = 20*p3^2 - 100*p2 + p1" << endl;
	cout << "dla parametrow : p1 = "  << p1 << ", p2 = " << p2 << ", p3 = " << p3 << endl;
	cout << "wynosi ->   w = " << wynik << endl << endl;

	//*****************************************************

	for (count = 0; count < BUFSIZE; count++)  {
		if (buffer1[count] == '\0')  break;
	}
	cout << "Dlugosc lancucha znakow w tablicy buffer1 = " << count << endl;
	cout << "male litery \"PRZED\"  = " << buffer1 << endl;

	__asm {
		lea esi, buffer1  // Load Effective Address str. 68, 85
		lea edi, buffer
		mov ecx, count
		inc ecx				// zwiekszamy o jeden ecx, gdy¿ bêdzie realizowane
		L0 : mov dl, [esi]	// kopiowanie tablicy buffer1 do buffer
			 mov[edi], dl	// ³¹cznie ze znakiem koñca linii -> '\0'
			 inc esi
			 inc edi
			 loop L0

		;********

			lea esi, buffer1  // g³ówna petla -> pocz¹tek
			lea edi, buffer
			mov ecx, count
			dec ecx			// zmniejszamy d³ugoœæ pêtli o jeden, gdy¿
		LA : mov dl, [esi]	// jesli znak w buffer1 równy 'd' - podmiana
			 cmp dl, 'd'	// dwoch kolejnych znakow w buffer
			 jne LB
			 mov [edi], '*'
			 mov [edi + 1], '#'
		LB : inc esi
			 inc edi
			 Loop LA			// g³ówna pêtla -> koniec
	}	// asm

	cout << "male litery \"PO   \"  = " << buffer << endl << endl;

	//*****************************************************

	fun2(buffer, &strlen);
	cout << "Wielkie litery          = " << buffer << endl;
	cout << "Dlugosc lancucha znakow = " << strlen << endl << endl;

	//*****************************************************

	count = 10 - 1;

	__asm {
			lea esi, buffer2  // Load Effective Address str. 68, 85
			mov ecx, count
		L1 : mov edx, [esi] //inty 32 bitowe
			cmp dl, 50;
			je L2
			inc  esi
			inc  esi
			inc  esi
			inc  esi
			Loop L1
		L2 : mov dword PTR[esi], 1024
			mov dword PTR[esi + 4], 1025
//				L2 : mov [esi], 1024
//				mov [esi + 4], 1025

	}	// asm

	cout << "Liczby = ";
	for (i = 0; i < 10; i++) { cout << buffer2[i] << ", "; }
	cout << endl;



	return 0;
}


