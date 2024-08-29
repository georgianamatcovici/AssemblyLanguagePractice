#include <iostream>


using namespace std;

void eliminare(int v[], int &n, int k)
{
	_asm
	{mov edi, dword ptr [ebp + 8];
	mov ebx, dword ptr [ebp + 12];
	mov ebx, dword ptr[ebx]; //n
	mov ecx, dword ptr [ebp + 16];
	dec ebx;// n-1
	mov eax, dword ptr[ebp + 12];
	mov dword ptr[eax], ebx;
_while:
	cmp ecx, ebx;
	jge afara;
	inc ecx;
	mov esi, dword ptr[edi + ecx * 4];
	dec ecx;
	mov dword ptr[edi + ecx * 4], esi;
	inc ecx;
	jmp _while;
afara:

	}
}

void inserare(int v[], int& n, int k, int val)
{
	_asm
	{ mov edi, dword ptr[ebp + 8];
	mov ebx, dword ptr[ebp + 12];
	mov ebx, dword ptr[ebx];
	mov ecx, dword ptr[ebp + 16];
	mov esi, dword ptr[ebp + 20];
	inc ebx; // n+1
	mov eax, dword ptr[ebp + 12];
	mov dword ptr[eax], ebx;
	dec ebx; // n
_while:
	cmp ebx, ecx;
	jle afara;
	dec ebx;
	mov eax, dword ptr[edi + 4 * ebx];
	inc ebx;
	mov dword ptr[edi + 4 * ebx], eax;
	dec ebx;
	jmp _while;

afara:
	mov dword ptr[edi + ecx * 4], esi;


	}
}



int main()
{
	int n;
	int v[7] = { 1, 2, 3, 4, 5, 6 };
	n = 6;
	inserare(v, n, 3, 89);
	int i;
	cout << n << endl;
	for (i = 0; i < n; i++)
		cout << v[i]<<' ';

	return 0;
}