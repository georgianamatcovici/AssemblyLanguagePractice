#include <iostream>


using namespace std;

int factorial(int n)
{//if(n==0) return 1;
// else return n*fact(n-1)
	_asm
	{mov ebx, dword ptr[ebp + 8]; //n
	cmp ebx, 0;
	je _if;
	mov ecx, ebx;
	dec ecx;
	push ecx;
	call factorial;
	add esp, 4;
	mul ebx;

	jmp sari_if;
_if:
	mov eax, 1;
sari_if:

	}
}


int main()
{
	int n;
	cin >> n;
	cout << factorial(n);

	return 0;
}