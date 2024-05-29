//=========================================================
//	IntスタックTwin
//==========================================================
#include "IntStackTwin.h"

#include <stdio.h>
#include <stdlib.h>  // calloc(),free()

IntStackResult Initialize(IntStackTwin* s, int max)
{
	s->stk = (int*)calloc(max, sizeof(int));
	if (s->stk == nullptr) {
		s->max = 0;
		s->ptrA = 0;
		s->ptrB = 0;
		return INITIALIZE_FAIL;
	}
	s->max = max;
	s->ptrA = 0;
	s->ptrB = max;
	return SUCCESS;
}
IntStackResult PushA(IntStackTwin* s, int x)
{
	if (s->ptrA >= s->ptrB) {
		return PUSH_NO_SPACE;
	}
	s->stk[s->ptrA++] = x;
	return SUCCESS;
}
IntStackResult PushB(IntStackTwin* s, int x)
{
	if (s->ptrA >= s->ptrB) {
		return PUSH_NO_SPACE;
	}
	s->stk[--s->ptrB] = x;
	return SUCCESS;
}

IntStackResult PopA(IntStackTwin* s, int* x)
{
	if (s->ptrA <= 0) {
		return POP_NO_DATA;
	}
	*x = s->stk[--s->ptrA];
	return SUCCESS;
}
IntStackResult PopB(IntStackTwin* s, int* x)
{
	if (s->ptrB >=s->max) {
		return POP_NO_DATA;
	}
	*x = s->stk[s->ptrB++];
	return SUCCESS;
}

IntStackResult PeekA(IntStackTwin* s, int* x)
{
	if (s->ptrA <= 0) {
		return PEEK_NO_DATA;
	}
	*x = s->stk[s->ptrA-1];
	return SUCCESS;
}
IntStackResult PeekB(IntStackTwin* s, int* x)
{
	if (s->ptrB >= s->max) {
		return PEEK_NO_DATA;
	}
	*x = s->stk[s->ptrB];
	return SUCCESS;
}

void ClearA(IntStackTwin* s)
{
	s->ptrA = 0;
}
void ClearB(IntStackTwin* s)
{
	s->ptrB = s->max;
}

int Capacity(const IntStackTwin* s)
{
	return s->max;
}
int SizeA(const IntStackTwin* s)
{
	return s->ptrA;
}
int SizeB(const IntStackTwin* s)
{
	return s->max - s->ptrB;
}

bool IsEmptyA(const IntStackTwin* s)
{
	return s->ptrA <= 0;
}
bool IsEmptyB(const IntStackTwin* s)
{
	return s->ptrB >= s->max;
}
bool IsFull(const IntStackTwin* s)
{
	return s->ptrA == s->ptrB;
}

int SearchA(const IntStackTwin* s, int x)
{
	for (int i = s->ptrA - 1; i >= 0; i--) {
		if (s->stk[i] == x) {
			return i;
		}
	}
	return SEARCH_NOT_FOUND; // -1
}
int SearchB(const IntStackTwin* s, int x)
{
	for (int i = s->ptrB; i < s->max; i++) {
		if (s->stk[i] == x) {
			return i;
		}
	}
	return SEARCH_NOT_FOUND; // -1
}
void Print(const IntStackTwin* s)
{
	for(int i = 0; i < s->max; i++) {
		if (i < s->ptrA || i>=s->ptrB ) {
			printf("%d ", s->stk[i]);
		}
		else {
			printf("- ");
		}
	}
	putchar('\n');
}

void Terminate(IntStackTwin* s)
{
	if (s->stk != nullptr) {
		free(s->stk);
		s->stk = nullptr;
	}
	s->max = 0;
	s->ptrA = 0;
	s->ptrB = 0;
}
