#include <iostream>

using namespace std;

void interclasare(int a[], int b[], int c[], int na, int nb, int& nc)
{ // adresa nc
	_asm
	{mov ecx, 0;
	mov edx, 0;
	mov esi, -1;
_while:
	cmp ecx, dword ptr[ebp + 20];
	jge  afara;
	cmp edx, dword ptr[ebp + 24];
	jge afara;
	mov edi, dword ptr[ebp + 8];
	mov eax, dword ptr[edi + 4 * ecx];
	mov edi, dword ptr[ebp + 12];
	mov ebx, dword ptr[edi + 4 * edx];
	cmp eax, ebx;
	jge _else;
	inc esi;
	mov edi, dword ptr[ebp + 16];
	mov dword ptr[edi + 4 * esi], eax;
	inc ecx;
	jmp _cont;
_else:
	inc esi;
	mov edi, dword ptr[ebp + 16];
	mov dword ptr[edi + esi * 4], ebx;
	inc edx;

_cont:
	jmp _while;
afara:

_while1:
	cmp ecx, dword ptr[ebp + 20];
	jge afara1;
	inc esi;
	mov edi, dword ptr[ebp + 8];
	mov eax, dword ptr[edi + ecx * 4];
	mov edi, dword ptr[ebp + 16];
	mov dword ptr[edi + esi * 4], eax;
	inc ecx;
	jmp _while1;
afara1:

_while2:
	cmp edx, dword ptr[ebp + 24];
	jge afara2;
	inc esi;
	mov edi, dword ptr[ebp + 12];
	mov ebx, dword ptr[edi + edx * 4];
	mov edi, dword ptr[ebp + 16];
	mov dword ptr[edi + esi * 4], ebx;
	inc edx;
	jmp _while2;
afara2:

	mov edi, dword ptr[ebp + 28];
	mov dword ptr[edi], esi;
	}
}



int main()
{
	int a[20] = { 3, 7, 9, 10, 12 };
	int b[20] = { 5, 12, 13 };
	int c[20];
	int na, nb, nc;
	na = 5;
	nb = 3;
	nc = 0;
	//interclasare(a, b, c, na, nb, nc);
	_asm
	{lea eax, a;
	lea ebx, b;
	lea ecx, c;
	mov edx, na;
	mov edi, nb;
	lea esi, nc;
	push esi;
	push edi;
	push edx;
	push ecx;
	push ebx;
	push eax;
	call interclasare;
	add esp, 24;
	}
	for (int i = 0; i < nc; i++)
		cout << c[i] << ' ';



	return 0;
}