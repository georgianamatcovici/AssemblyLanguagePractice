#include <iostream>

using namespace std;

void sumabs(int *x, int n, int& s)
{
	_asm
	{mov edi, dword ptr[ebp + 8];
	mov ebx, dword ptr[ebp + 12];
	mov ecx, 0;
	fldz; //0
_for:
	cmp ecx, ebx;
	jge afara;
	fld dword ptr[edi + ecx*4];// v[i] 0...
	//fabs;
	//fabs;
    //faddp st(1), st(0); //
	//fxch st(1);
	//fstp st(0);
	//fadd st(0), st(1);
	//fstp st(0);
	inc ecx;
	jmp _for;
afara:
	mov esi, dword ptr[ebp + 16];
	fstp dword ptr [esi];
	}


}


int main()
{
	int v[6] = { -1, 2, -3, -4, 5, -6};
	int sum;
	sum = 0;
	sumabs(v, 6, sum);
	cout << sum;


	return 0;
}