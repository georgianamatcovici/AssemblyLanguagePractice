#include <iostream>

using namespace std;

int nrcuv(char s[])
{
	_asm
	{mov eax, 0;
	mov edi, dword ptr[ebp + 8];
	mov ecx, 0;
_while:
	cmp byte ptr[edi+ecx], 0;
	je afara;
	movsx ebx, dword ptr[edi + ecx];
	cmp ebx, ' ';
	jne _if;
	inc ecx;
	jmp sari_if;
_if:
	inc eax;
	mov edx, ecx;
	inc edx;
_while2:
	cmp byte ptr[edi + edx], ' ';
	je afara2;
	cmp byte ptr[edi + edx], 0;
	je afara2;

	inc edx;
	jmp _while2;
afara2:
	mov ecx, edx;

sari_if:

	jmp _while;
afara:

	}
}

int main()
{
	char s[] = "Ana are mere multe";
	cout << nrcuv(s);


	return 0;
}