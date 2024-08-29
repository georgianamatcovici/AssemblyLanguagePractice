#include <iostream>
using namespace std;

int fiborec(int n)
{
	_asm
	{mov ebx, dword ptr[ebp + 8];
	cmp ebx, 1;
	jle _if;
	mov ecx, dword ptr[ebp + 8];
	dec ecx;
	push ecx;
	call fiborec;
	mov esi, eax;
	add esp, 4;

	push esi;
	mov ecx, dword ptr[ebp + 8];
	dec ecx;
	dec ecx;
	push ecx;
	call fiborec;
	add esp, 4;
	pop esi;
	add eax, esi;
	jmp sar_if;
_if:
	mov eax, ebx;

sar_if:

}
}

int main()
{
	int n;
	cin >> n;
	cout << fiborec(n);

	return 0;
}



/*int fibo(int n)
{
	if (n <= 1)
	{
		return n;
	}

	return fibo(n - 1) + fibo(n - 2);
}*/