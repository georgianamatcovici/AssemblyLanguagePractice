#include <iostream>


using namespace std;

void paritate(int v[], int & n)
{
	_asm
	{mov edi, dword ptr[ebp + 8];
	mov esi, dword ptr[ebp+12]
	mov ecx, 1;
_for1:
	cmp ecx, dword ptr[esi];
	jge afara1;
	dec ecx;
	mov eax, dword ptr[edi + ecx * 4];
	inc ecx;
	mov ebx, dword ptr[edi + ecx * 4];
	mov edx, 0;
	push ebx;
	mov ebx, 2;
	div ebx;
	pop ebx;
	push edi; // push
	mov edi, edx;
	mov edx, 0;
	mov eax, ebx;
	push ecx;
	mov ecx, 2;
	div ecx;
	pop ecx;
	mov eax, edi;
	pop edi;
	cmp eax, edx;
	jne _else;
	mov edx, dword ptr[esi]; //n
	inc edx; //n+1
	mov dword ptr[esi], edx;
	dec edx; //n

_for2:
	cmp edx, ecx;
	jle afara2;
	dec edx;
	mov edi, dword ptr[ebp + 8];
	mov eax, dword ptr[edi + edx * 4];
	inc edx;
	mov dword ptr[edi + edx * 4], eax;
	dec edx;
	jmp _for2;
afara2:
	dec ecx;
	
	mov edi, dword ptr[ebp + 8];
	mov eax, dword ptr[edi + 4 * ecx];
	inc ecx;
	mov ebx, dword ptr[edi + 4 * ecx];
	add eax, ebx;
	mov ebx, 2;
	mov edx, 0;
	div ebx;
	mov dword ptr[edi + 4 * ecx], eax;
	


	inc ecx;
	inc ecx;
	jmp cont;
_else:
	inc ecx;
cont:
	jmp _for1;
	
afara1:


	}
}

int main()
{
	int v[20] = { 1, 41, 3, 3, 4, 8 };
	int n = 6;
	paritate(v, n);
	int i;
	cout << n << endl;
	for (i = 0; i < n; i++)
		cout << v[i] << ' ';


	return 0;
}