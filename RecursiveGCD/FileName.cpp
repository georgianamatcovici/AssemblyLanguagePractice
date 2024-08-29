#include <iostream>

using namespace std;

int cmmdc(int a, int b)
{
	//if (a % b != 0)
	//	return cmmdc(b, a % b);
	//else return b;
	_asm
	{mov edi, dword ptr[ebp + 8];
	mov esi, dword ptr[ebp + 12];
	mov eax, edi;
	mov edx, 0;
	div esi;
	cmp edx, 0;
	je _else;
	push edx;
	push esi;
	call cmmdc;
	add esp, 8;
	jmp cont;
_else:
	mov eax, esi;
cont:

	}

}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << cmmdc(a, b);

	return 0;
}