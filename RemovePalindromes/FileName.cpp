#include <iostream>

using namespace std;

int palindrom(int n)
{
    _asm
    {mov ebx, dword ptr[ebp + 8]; //n
    mov edi, 0; //m
    mov esi, ebx; //n
_while:
    cmp ebx, 0;
    je afara;
    mov eax, ebx;

    push ebx;
    mov ebx, 10;
    mov edx, 0;
    div ebx;
    mov ecx, eax; // n/10
    pop ebx;

    push edx;
    // edx n%10
    mov eax, edi;
    push ebx;
    mov ebx, 10;
    mul ebx; // eax edi*10
    pop ebx;
    pop edx; // edx n%10;
    mov edi, eax;
    add edi, edx; // edi=edi*10+n%10;

    mov ebx, ecx;
    jmp _while;
afara:
    cmp esi, edi;
    je _if;
    mov eax, 0;
    jmp continua;
_if:
    mov eax, 1;
continua:

    }
}

void removePalindrom(int v[], int& n)
{
    _asm
    {mov edi, dword ptr[ebp + 8]; //adresa vector
    mov ecx, 0; // contor
_for1:
    mov esi, dword ptr[ebp + 12];
    cmp ecx, dword ptr[esi];
    jge afara1;
    mov ebx, dword ptr[edi + ecx * 4];
    push edi;
    push ecx;

    push ebx; // apel
    mov eax, 0;
    call palindrom;
    add esp, 4;
    pop ecx;
    pop edi;
    cmp eax, 1;
    je _if;
    jmp sari_if;
_if:
    mov edx, ecx; // i
    mov esi, dword ptr[ebp + 12]; // adresa lui n
    mov ebx, dword ptr[esi]; // n;
    dec ebx; // n-1
    mov dword ptr[esi], ebx; // n=n-1;
    // 0 1 2 3 
    // a a a a 
_for2:
    cmp edx, ebx;
    jge afara2;
    push ecx;
    inc edx;
    mov ecx, dword ptr[edi + edx * 4]; // v[j+1]
    dec edx;
    mov dword ptr[edi + edx * 4], ecx; // v[j]=v[j+1]
    pop ecx;
    inc edx;
    jmp _for2;
afara2:


    jmp continua;
sari_if:

    inc ecx;
    continua:
    jmp _for1;
afara1:

    }
}

int main()
{  int v[] = { 4876, 11, 878, 987, 11};
    int n = 5;

   removePalindrom(v, n);
    printf("Numarul de elemente este: %d \n", n);
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
  // cout << palindrom(987);


	return 0;
}