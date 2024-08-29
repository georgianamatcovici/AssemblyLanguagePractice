#include <iostream>

using namespace std;
//Counts the number of 1 bits
int bitcount(int n)
{//0 1 0 1 1
// 
	_asm
	{mov ebx, dword ptr[ebp + 8];
	mov ecx, 0; //cnt
_while:
	test ebx, 1;
	jz sar_if;
	inc ecx;
	sar_if:
	shr ebx, 1;
	jz afara;
	jmp _while;
afara:
	mov eax, ecx;
    }
	
}

int main()
{
	int n;
	cin >> n;
	cout << bitcount(n);


	return 0;
}