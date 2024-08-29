#include <iostream>


using namespace std;
int var1, var2;

bool strchr1(char s[], char l)
{
	_asm
	{mov eax, 0;
	mov edi, dword ptr[ebp + 8];
	movsx ebx, byte ptr[ebp + 12];
	mov ecx, 0;
_for:
	cmp byte ptr[edi + ecx], '\0';
	je afara;
	movsx esi, byte ptr[edi + ecx];
	cmp esi, ebx;
	je _return1;
	inc ecx;
	jmp _for;

afara:

	jmp cont;
_return1:
	mov eax, 1;
cont:


    }
}

void inserare(char s[])
{
	char voc[] = "aeiou";
	_asm
	{mov edi, dword ptr[ebp + 8];
	mov ecx, 0; //contor
parcurgere:
	cmp byte ptr[edi + ecx], 0;
	je final_parcurgere;
	movsx ebx, byte ptr[edi + ecx];
	lea esi, voc;
	push edi; //retin
	push ecx; //retin

	push ebx; // l pt apel
	push esi; // voc pt apel
	call strchr1;
	add esp, 8;

	pop ecx;
	pop edi;

	cmp eax, 0;
	jne _else;
	inc ecx;

	jmp continua;
_else:
	push ecx; // retin
_while:
	cmp byte ptr[edi + ecx], 0;
	je afara;
	inc ecx;
	jmp _while;
afara:
	inc ecx;
	mov edx, ecx; // 
	pop ecx;
	mov var1, edx;
	mov var2, ecx;
for_mutare:
	cmp edx, ecx;
	jle sf_for_mutare;
	dec edx;
	mov edi, dword ptr[ebp + 8];
	mov al, byte ptr[edi + edx];
	inc edx;
	mov byte ptr[edi + edx], al;
	dec edx;
	jmp for_mutare;

sf_for_mutare:

mov edi, dword ptr[ebp + 8];
mov byte ptr[edi + ecx+1], '*';
inc ecx;
inc ecx;


continua:
	jmp parcurgere;



final_parcurgere:


	}
}


int main()
{
	char s[255];
	cin.getline(s, 250);
	inserare(s);
	cout << s;
	//cout << var1 << ' ' << var2 << endl;

	return 0;
}