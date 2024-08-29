#include <iostream>

/// Counts the number of co prime pairs in a linked list 
using namespace std;

struct nod {
    int info;
    nod* urm;
};

// 0 1 2 3 4 5 6 7
// i i i i a a a a

int cmmdc(int a, int b)
{
    _asm
    {mov ebx, dword ptr[ebp + 8]; //a
    mov ecx, dword ptr[ebp + 12]; //b
    mov edx, 0;
    mov eax, ebx;
    div ecx;
    cmp edx, 0;
    je _if;
    push edx;
    push ecx;
    call cmmdc;
    add esp, 8;
    jmp cont;
_if:
    mov eax, ecx;
cont:

}
}

int numarare(nod* p)
{
    _asm
    {mov edi, dword ptr[ebp + 8]; // adresa primului elem
   
    mov eax, 0;
_while1:
    cmp edi, 0;
    je afara1;
    mov esi, dword ptr[edi + 4]; // edi->urm
_while2:
    cmp esi, 0;
    je afara2;
    mov ebx, dword ptr[edi];
    mov ecx, dword ptr[esi];
    push edi;
    push esi;
    push eax;

    push ecx;
    push ebx;
    call cmmdc;
    add esp, 8;
    mov ebx, eax; // cmmdc

    pop eax;
    pop esi;
    pop edi;

    cmp ebx, 1;
    je _if1;
    jmp continuare;
_if1:
    inc eax;
    continuare:

    mov esi, dword ptr[esi + 4];
    jmp _while2;
    afara2:

    mov edi, dword ptr[edi + 4];
    //mov edi, ecx;
    jmp _while1;
afara1:

    }
    
}

int main()
{
    nod* q, * prim;
    q = new nod;
    q->info = 4;
    q->urm = NULL;
    prim = q;

    q = new nod;
    q->info = 7;
    q->urm = NULL;
    prim->urm = q;
    q = new nod;
    q->info = 8;
    q->urm = NULL;
    prim->urm->urm = q;
    q = new nod;
    q->info = 2;
    q->urm = NULL;
    prim->urm->urm->urm = q;
    q = new nod;
    q->info = 9;
    q->urm = NULL;
    prim->urm->urm->urm->urm = q;
    q = new nod;
    q->info = 2;
    q->urm = NULL;
    prim->urm->urm->urm->urm->urm = q;
    q = new nod;
    q->info = 8;
    q->urm = NULL;
    prim->urm->urm->urm->urm->urm->urm = q;
    cout << numarare(prim);
	return 0;
}