#include <iostream>

using namespace std;

struct Circle {
	short int x, y;
	int radius;
};
//0 1 2 3 4 5 6 7
//x x y y r r r r

int var;
float area(Circle *x, int nr)
{
	_asm
	{mov edi, dword ptr[ebp + 8];
	fldz; // 0
	mov ecx, 0; //cnt;
_for:
	cmp ecx, dword ptr[ebp + 12];
	jge afara;
	mov eax, dword ptr[edi + ecx * 8 + 4];
	fild dword ptr[edi + ecx * 8 + 4]; // raza 0
    fmul st(0), st(0); // raza^2 0
	fldpi; // pi raza^2 0;
	fmulp st(1), st(0) // pi*r^2 0
	fcomi st(0), st(1);
	ja _if;
	fstp st(0);
	jmp cont;
_if:
	fxch st(1); // 0 pi*r^2
	fstp st(0); // pi*r^2;
cont:
	inc ecx;
	jmp _for;
afara:


    }
}

int main()
{
	Circle c[] = { {1, 4, 7}, {2, 3, 12}, {4, 2, 8} };
	cout << area(c, 3);
	//cout << var;
	return 0;
}