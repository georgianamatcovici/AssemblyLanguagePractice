#include <iostream>

using namespace std;
int var;

void suma(char* s1, char* s2, char* rez)
{
	_asm
	{mov ecx, 0;
for1:
	mov edi, dword ptr[ebp + 8];
	cmp byte ptr[edi + ecx], 0;
	je afara1;

	inc ecx;
	jmp for1;
afara1:
	mov edi, dword ptr[ebp + 16];
	mov al, 0;
	mov byte ptr[edi + ecx], al;
	dec ecx;
	mov dl, 0;// carry

_for2:
	cmp ecx, 0;
	jl afara2;
	mov edi, dword ptr[ebp + 8];
	mov esi, dword ptr[ebp + 12];
	mov al, byte ptr[edi + ecx];
	mov bl, byte ptr[esi + ecx];
	push ecx;
	mov cl, '0';
	sub al, cl;
	sub bl, cl;
	pop ecx;
	add bl, al;
	cmp dl, 1;
	je carry;
	jmp sari_carry;
carry:
	add bl, 1;
sari_carry:

	cmp bl, 10;
	jg dep;
	jmp cont;
dep:
	push edx;
	mov dl, bl;
	sub dl, 10;
	mov bl, dl;
	pop edx;
	mov dl, 1;
	//mov var, ebx;
cont:
	push ecx;
	mov cl, '0';
	add bl, cl;
	pop ecx;
	mov edi, dword ptr[ebp + 16];
	mov byte ptr[edi + ecx], bl;
	dec ecx;
	jmp _for2;
afara2:

	}
}

int main()
{
	char t1[] = "5732", t2[] = "1944", r[10];
	suma(t1, t2, r);
	cout << r << endl;
	//var = 0;
	/*_asm
	{mov ax, 17;
	mov cl, 10;
	div cl;
	mov var, ah;
	}*/
	//cout << var;
	return 0;
}