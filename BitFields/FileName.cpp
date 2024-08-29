#include <iostream>


using namespace std;

int main()
{
	unsigned int var;
	struct bitfields
	{
		unsigned int a : 20;
		unsigned int b : 6;
		unsigned int c : 22;
}s;
	s.a = 7;
	s.b = 5;
	_asm 
	{mov eax, dword ptr s;
	//and eax, 2047;
	shr eax, 20;
	and eax, 63;
	mov var, eax;
	}
	cout << var;
	return 0;
}