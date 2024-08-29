#include <iostream>


using namespace std;

float adunare(float v[], int size)
{
	_asm
	{mov edi, dword ptr[ebp + 8];
	mov ecx, 0;
	fldz; //0
_while:
	cmp ecx, dword ptr[ebp + 12];
	jge afara;
	fld dword ptr[edi + 4 * ecx];
	faddp st(1), st(0);

	inc ecx;
	jmp _while;
afara:

	fild dword ptr[ebp + 12];
	fdivp st(1), st(0);
}
}


int main()
{
	float vector[] = { 3.5, 1.45, 10.2, 90.45, 100.3, 7.8, 9.89, 89.67, 100.59 };
	int size = sizeof(vector) / sizeof(vector[0]);

	cout << adunare(vector, size);

	return 0;
}