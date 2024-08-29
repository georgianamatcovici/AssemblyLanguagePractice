#include <iostream>

using namespace std;

int getmaxcons(char s[])
{
	_asm
	{ // adresa sir
	mov edi, dword ptr[ebp + 8];
	mov ecx, 0; // i
	mov eax, 0; //cnt
_for:
	cmp byte ptr[edi+ecx], 0;
	je afara;
	movsx ebx, byte ptr[edi + ecx]; // s[i]
	mov edx, ecx; 
	inc edx; // j=i+1
_while:
	movsx esi, byte ptr[edi + edx]; // s[j]
	cmp esi, 0;
	je afara_while;
	cmp ebx, esi;
	jne afara_while;
	inc edx;
	jmp _while;
afara_while:
	mov esi, edx;
	sub esi, ecx;
	cmp esi, eax;
	jg _if;
	jmp sari_if;
_if:
	mov eax, esi;
sari_if:

	mov ecx, edx;
	jmp _for;
afara:

	}
}

int main()
{
char str[] = "aaaiuuuugu";

cout << getmaxcons(str);
	return 0;
}