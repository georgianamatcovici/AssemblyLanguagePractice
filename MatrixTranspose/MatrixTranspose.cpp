#include <iostream>

using namespace std;


int a[3][3], b[3][3];
int main()
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			cin >> a[i][j];

	_asm
	{lea edi, a;
	lea esi, b;
	mov ecx, 0;

	
_for1:
	cmp ecx, 3;
	jge final1;
	mov ebx, 0;
_for2:
	cmp ebx, 3;
	jge final2;

	
	mov eax, ebx;
	mov edx, 3;
	mul edx;
	add eax, ecx;
	mov edx, dword ptr[edi + eax * 4];
	push edx;
	mov eax, ecx;
	mov edx, 3;
	mul edx;
	add eax, ebx;
	pop edx;
	mov dword ptr[esi + eax * 4], edx;


	inc ebx;
	jmp _for2;
final2:

	inc ecx;
	jmp _for1;
final1:

	}



	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			cout << b[i][j] << ' ';
		cout << endl;
	}


	return 0;
}