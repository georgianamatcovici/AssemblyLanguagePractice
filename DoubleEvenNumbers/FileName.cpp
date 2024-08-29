#include <iostream>

using namespace std;
///We double even numbers in v[]
void dublare_pare(int v[], int& n)
{
	_asm
	{mov edi, dword ptr[ebp + 8];
	mov ecx, 0;// i
_for1:
	mov esi, dword ptr[ebp + 12];//adresa n
	mov esi, dword ptr[esi]; //n
	cmp ecx, esi;
	jge afara1;
	mov ebx, dword ptr[edi + ecx * 4]; // v[i];
	test ebx, 1; // par, ultimul bit 0
	jz _este_par;
	inc ecx;
	jmp sari_par;
_este_par:
	mov esi, dword ptr[ebp + 12];
	mov eax, dword ptr[esi]; // n
	inc eax; //n+1
	mov dword ptr[esi], eax; // n=n+1
	dec eax; //n
_for2:
	cmp eax, ecx;
	jle afara2;
	dec eax;
	mov ebx, dword ptr[edi + eax * 4]; // v[j-1]
	inc eax;
	mov dword ptr[edi + eax * 4], ebx; // v[j]=v[j-1]
	dec eax;
	jmp _for2;
afara2:

	mov ebx, dword ptr[edi + ecx * 4]; // v[i]
	inc ecx;
	mov dword ptr[edi + 4 * ecx], ebx;
	inc ecx;
sari_par:

	//inc ecx;
	jmp _for1;
afara1:

	}
}

int main()
{
	int v[20] = { 2, 5, 2, 7, 12, 34, 24, 15, 14 };
	int n = 9;
	dublare_pare(v, n);
	int i;
	for (i = 0; i < n; i++)
		cout << v[i] << ' ';

	return 0;
}
