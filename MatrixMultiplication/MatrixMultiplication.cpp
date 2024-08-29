#include <iostream>


using namespace std;

void inmultire(int m1[3][3], int m2[3][3], int m3[3][3])
{
	_asm
	{
		mov ebx, 0; //i
	for1:
		cmp ebx, 3;
		jge afara1;
		mov ecx, 0; // j
	for2:
		cmp ecx, 3;
		jge afara2;
		mov edi, 0; //k
	for3:
		cmp edi, 3;
		jge afara3;
		push ecx;
		mov eax, 3;
		mul ebx;
		add eax, edi; // nrcol*i+k
		mov esi, dword ptr[ebp + 8]; // m1
		mov esi, dword ptr[esi + eax * 4]; // m1[i][k]
		pop ecx; // j
		mov eax, 3;
		mul edi;
		add eax, ecx; // nrcol*k+j
		push ebx;
		mov ebx, dword ptr[ebp + 12]; // m2
		mov ebx, dword ptr[ebx + eax * 4]; //m2[k][j]
		mov eax, esi;
		mul ebx;
		// eax m1[i][k]*m2[k][j]
		pop ebx;
		push edi;
		mov edi, eax;
		mov eax, 3;
		mul ebx;
		add eax, ecx; // nrcol*i+j
		mov edx, dword ptr[ebp + 16]; // m3
		mov dword ptr[edx + eax * 4], edi;

		pop edi;
		inc edi;
		jmp for3;
	afara3:

		inc ecx;
		jmp for2;
	afara2:
		inc ebx;
		jmp for1;
	afara1:

	}
}

int main()
{
	int m1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int m2[3][3] = { {7, 8, 9}, {4, 5, 6}, {1, 2, 3} };
	int m3[3][3];
	inmultire(m1, m2, m3);
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			cout << m3[i][j] << ' ';
		cout << endl;
	}


	return 0;
}
