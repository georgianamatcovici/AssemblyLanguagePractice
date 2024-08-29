#include <iostream>

using namespace std;

struct Complex
{
	short re;
	int im;
};

// (a+bi)*(c+di)=ac+adi+bci-bd
// = ac-bd +(ad+bc)i
// modul sqrt((ac-bd)^2+(ad+bc)^2)
//0 1 2 3 4 5 6 7 
//r r - - i i i i
float modulprod(Complex* c1, Complex* c2)
{
	_asm
	{mov edi, dword ptr[ebp + 8]; //adresa struct c1
	mov esi, dword ptr[ebp + 12]; // adresa struct c2
	fild word ptr[edi]; // re1 
	fild word ptr[esi]; // re2 re1 
	fmulp st(1), st(0); // re1*re2 
	fild dword ptr[edi + 4]; // im1 re1*re2 
	fild dword ptr[esi + 4]; // im2 im1 re1*re2 
	fmulp st(1), st(0); // im1*im2 re1*re2 
	fsubp st(1), st(0); // ac-bd 0
	fmul st(0), st(0); // ac-bd patrat 
	fild word ptr[edi]; // re1 ac-bd^2
	fild dword ptr[esi + 4]; // im2 re1 ...
	fmulp st(1), st(0); // re1*im2 ...
	fild dword ptr[edi + 4]; // im1 re1*im2 ..
	fild word ptr[esi]; // re2 im1 ...
	fmulp st(1), st(0); // re2*im1 re1*im2 ac-bd^2
	faddp st(1), st(0); // 
	fmul st(0), st(0); // 
	faddp st(1), st(0); // 
	fsqrt;

	}
}

int main()
{
	Complex c1, c2;
	c1.re = 2;
	c1.im = 3;
	c2.re = 7;
	c2.im = 5;
	cout << modulprod(&c1, &c2);


	return 0;
}