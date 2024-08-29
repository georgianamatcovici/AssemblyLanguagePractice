#include <iostream>

using namespace std;

int strAdd(char* sir, unsigned int sirMaxLength, char* toAdd)
{
	_asm
	{mov edi, dword ptr[ebp + 8]; //adresa sir1
	mov esi, dword ptr[ebp + 16]; // adresa sir2
	mov ebx, 0; //cnt1;
_while1:
	movsx ecx, byte ptr[edi + ebx];
	cmp ecx, 0;
	je afara1;
	inc ebx;
	jmp _while1;
afara1:
	// lun s1
		
	mov ecx, 0;
_while2:
	movsx eax, byte ptr[esi + ecx];
	cmp eax, 0;
	je afara2;
	inc ecx;
	jmp _while2;
afara2:
 //lun s2
	mov eax, ebx;
	add eax, ecx;
	cmp eax, dword ptr[ebp + 12];
	jge _return0;
	mov edx, 0;
_while3:
	cmp edx, ecx;
	jg afara3;
	mov al, byte ptr[esi + edx];
	mov byte ptr[edi + ebx], al;
	inc ebx;
	inc edx;
	jmp _while3;
afara3:



	mov eax, 1;
	jmp _sfarsit;
	_return0:
	mov eax, 0;
_sfarsit:

	}
}

int main()
{
	char s1[250];
	char s2[250];
	cin.getline(s1, 250);
	cin.getline(s2, 250);
	strAdd(s1, 250, s2);
	cout << s1 << endl;



	return 0;
}