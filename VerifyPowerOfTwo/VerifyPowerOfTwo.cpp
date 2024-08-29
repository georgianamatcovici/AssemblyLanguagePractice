#include <iostream>

using namespace std;

int putere_2(int n)
{
	_asm
	{mov ebx, dword ptr[ebp + 8];
	mov ecx, ebx;
	dec ecx;
	test ebx, ecx;
	jz _return1;
	mov eax, 0;
	jmp _return0;
_return1:
	mov eax, 1;
_return0:

    }
}

int main()
{
	int n;
	cin >> n;
	cout << putere_2(n);


	return 0;
}