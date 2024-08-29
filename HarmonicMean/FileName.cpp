#include <iostream>

using namespace std;

/*float harmean(int* x, int nr)
{
	_asm
	{mov edi, dword ptr[ebp + 8];
	fldz; //0
	mov ecx, 0;
_for:
	cmp ecx, dword ptr[ebp + 12];
	jge afara;
	fild dword ptr[edi + 4 * ecx]; // v[i] 0
	fld1; // 1 v[i] 0
	fdiv st(0), st(1); // 1/v[i] v[i] 0
	fxch st(1); // v[i] 1/v[i] 0
	fstp st(0); // 1/v[i] 0
	faddp st(1), st(0); // 1/v[i]+0+...
	inc ecx;
	jmp _for;
afara:
	fild dword ptr[ebp + 12]; // n suma
	fdiv st(0), st(1); // n/suma   suma
	fxch st(1); // suma n/suma
	fstp st(0); // n/suma

    }
}
*/

float harmean(int* x, int nr)
{
	float rez;
	_asm
	{mov edi, dword ptr[ebp + 8];
	mov ecx, 0;
	cvtsi2ss xmm0, ecx; // xmm0 0
_for:
	cmp ecx, dword ptr[ebp + 12];
	jge afara;
	mov ebx, dword ptr[edi + 4 * ecx];
	cvtsi2ss xmm1, ebx; // v[i];
	mov ebx, 1;
	cvtsi2ss xmm2, ebx; // 1
	divss xmm2, xmm1; // 1/v[i]
	addss xmm0, xmm2; // 1/v[i]+0+...
	inc ecx;
	jmp _for;
afara:
	mov ebx, dword ptr[ebp + 12];
	cvtsi2ss xmm3, ebx; // n;
	divss xmm3, xmm0;
	movss rez, xmm3;
	fld rez;
	}
	

}
int main()
{
	int v[] = { 1, 2, 3, 4, 5 };
	cout << harmean(v, 5);

	return 0;
}