#include <iostream>

using namespace std;


void bubblesort(int v[], int n)
{
	_asm
	{mov edi, dword ptr[ebp + 8];
_repeat:
	mov edx, 1;
	mov ecx, 1;
_for:
	cmp ecx, dword ptr[ebp + 12];
	jge afara_for;
	dec ecx;
	mov eax, dword ptr[edi + ecx * 4];
	inc ecx;
	mov ebx, dword ptr[edi + ecx * 4];
	cmp eax, ebx;
	jg _if;

	jmp sari_if;
_if:
	mov dword ptr[edi + ecx * 4], eax;
	dec ecx;
	mov dword ptr[edi + ecx * 4], ebx;
	inc ecx;
	mov edx, 0;
sari_if:

	inc ecx;
	jmp _for;
afara_for:
	cmp edx, 1;
	je afara_repeat;
	jmp _repeat;
afara_repeat:

}
}

int main()
{
	int v[10] = { 4, 1, 7, 8, 10 };
	bubblesort(v, 5);
	int i;
	for (i = 0; i < 5; i++)
		cout << v[i] << ' ';



	return 0;
}
