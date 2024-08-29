#include <iostream>


using namespace std;

int Reverse(int* vector1, int* vector2, int count)
{
	_asm
	{mov edi, dword ptr[ebp + 8];
	mov esi, dword ptr[ebp + 12];
	mov ebx, dword ptr[ebp + 16];
	dec ebx;
	mov eax, 1;
	mov ecx, 0;//contor
// 0 1 2 3 4
// 4 3 2 1 0
_for:
	cmp ecx, ebx;
	jg afara;
	push eax;
	mov eax, dword ptr[edi + 4 * ecx];// v[i]
	sub ebx, ecx;
	mov edx, dword ptr[esi + 4 * ebx]; // v[j]
	add ebx, ecx;
	cmp eax, edx;
	jne _return0;
	pop eax;
	inc ecx;
	jmp _for;
afara:
	jmp cont;
_return0:
	pop eax;
	mov eax, 0;
cont:
    }
}

int main()
{
	int v1[] = {1, 9, 3, 4, 5};
	int v2[] = {5, 4, 3, 2, 1};
	printf("%d", Reverse(v1, v2, 5));

	return 0;
}