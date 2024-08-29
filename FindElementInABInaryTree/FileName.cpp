#include <iostream>


using namespace std;

struct Tree
{
	int value;
	Tree* left, * right;
};

int find(int v, Tree* root)
{
	_asm
	{mov ebx, dword ptr[ebp + 8];
	mov edi, dword ptr[ebp + 12];
	cmp edi, '\0';
	je not_found;
	cmp dword ptr[edi], ebx;
	je _found;
	mov ecx, dword ptr[edi + 4];
	mov edx, dword ptr[edi + 8];
	push ecx;
	push ebx;
	call find;
	add esp, 8;
	cmp eax, 1;
	je _found;
	push edx;
	push ebx;
	call find;
	add esp, 8;
	cmp eax, 1;
	je _found;
not_found:
	mov eax, 0;
	jmp _final;
_found:
	mov eax, 1;

_final:

	}
}

int main()
{
	Tree* r;
	r = new Tree;
	r->value = 7;
	r->left = new Tree;
	r->left->value = 4;
	r->left->left = new Tree;
	r->left->left->value = 3;
	r->left->left->left = r->left->left->right = NULL;
	r->left->right = NULL;
	r->right = new Tree;
	r->right->value = 2;
	r->right->left = r->right->right = NULL;
	cout << find(5, r);



	return 0;
}