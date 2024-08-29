#include <iostream>


using namespace std;

float harmean(int* x, int nr)
{
	float var;
	_asm
	{mov edi, dword ptr[ebp + 8];
	mov ecx, 0;
	cvtsi2ss xmm2, ecx;
_for:
	cmp ecx, dword ptr[ebp + 12];
	jge afara;
	mov ebx, dword ptr[edi + ecx * 4];
	cvtsi2ss xmm0, ebx; // x[i]
	mov eax, 1;
	cvtsi2ss xmm1, eax;
	divss xmm1, xmm0; // xmm1 1/x[i]
	addss xmm2, xmm1; 
	inc ecx;
	jmp _for;
afara:
	mov ebx, dword ptr[ebp + 12];
	cvtsi2ss xmm0, ebx; // n
	divss xmm0, xmm2;
	movss var, xmm0;
	fld var;
}
}


	
int main() {
		
	int v[] = { 1,2,3,4,5 }; cout << harmean(v, 5); // se va afisa valoarea 2.18978
		
	return 0; }

