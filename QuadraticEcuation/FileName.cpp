#include <iostream>

using namespace std;

struct Functie
{
	double rad1;
	double rad2;
	float a;
	float b;
	float c;
};

void calc_radacina(Functie* f)
{
	int valoare2 = 2;
	int valoare4 = 4;

	_asm
	{
		xor eax, eax;
		xor ebx, ebx;
		xor ecx, ecx;
		xor edx, edx;
		xor edi, edi; // functia
		xor esi, esi;

		mov edi, [ebp + 8];

		//[edi] - rad1;
		//[edi + 8] - rad2;
		//[edi + 16] - a;
		//[edi + 20] - b;
		//[edi + 24] - c;

		fld dword ptr[edi + 20];
		fmul st(0), st(0); // st(0) = b^2;
		fld dword ptr[edi + 16];
		fmul dword ptr[edi + 24];
		fimul valoare4; // st(0) = 4ac, st(1) = b^2
		fsubp st(1), st(0); // st(0) = b^2 - 4ac = delta

		fsqrt; // st(0) = rad(delta)

		fld dword ptr[edi + 20];
		fsubr st(0), st(1); // st(0) = -b + rad(delta), st(1) = rad(delta);
		fld dword ptr[edi + 16];
		fimul valoare2; // st(0) = 2a, st(1) = -b + rad(delta), st(2) = rad(delta);
		fdivp st(1), st(0); // st(0) = rad1, st(1) = rad(delta)
		fstp qword ptr[edi];

		fld dword ptr[edi + 20];
		fchs; // st(0) = -b
		fsub st(0), st(1); // st(0) = -b - rad(delta), st(1) = rad(delta);
		fld dword ptr[edi + 16];
		fimul valoare2; // st(0) = 2a, st(1) = -b + rad(delta), st(2) = rad(delta);
		fdivp st(1), st(0); // st(0) = rad1, st(1) = rad(delta)
		fstp qword ptr[edi + 8];
	}

}




int main()
{
	Functie f;
	f.a = 1;
	f.b = 4;
	f.c = 2;

	Functie* p = &f;

	calc_radacina(p);

	cout << f.rad1 << " " << f.rad2;

	return 0;
}