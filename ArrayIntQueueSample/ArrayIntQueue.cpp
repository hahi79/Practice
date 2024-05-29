//=========================================================
//	配列Intキュー
//==========================================================
#include "ArrayIntQueue.h"
#include <stdio.h> // printf()
#include <stdlib.h> // calloc(),free()


IntQueueResult Initialize(ArrayIntQueue* q, int max)
{
	q->num =  0;
	q->que = (int*)calloc(max, sizeof(int));
	if (q->que == nullptr) {
		q->max = 0;
		return INITIALIZE_FAIL;
	}
	q->max = max;
	return SUCCESS;
}

IntQueueResult Enque(ArrayIntQueue* q, int x)
{
	if (q->num >= q->max) {
		return ENQUE_NO_SPACE;
	}
	else {
		q->que[q->num] = x;
		q->num++;
		return SUCCESS;
	}
}
IntQueueResult Deque(ArrayIntQueue* q, int* x)
{
	if (q->num <= 0) {
		return	DEQUE_NO_DATA;
	}
	else {
		*x = q->que[0];
		for (int i = 0; i < q->num - 1; i++) {
			q->que[i] = q->que[i + 1];
		}
		q->num--;
		return SUCCESS;
	}
}
IntQueueResult Peek(const ArrayIntQueue* q, int* x)
{
	if (q->num <= 0) {
		return	PEEK_NO_DATA;
	}
	else {
		*x = q->que[0];
		return SUCCESS;
	}
}
void Clear(ArrayIntQueue* q)
{
	q->num = 0;
}
int Capacity(const ArrayIntQueue* q)
{
	return q->max;
}
int Size(const ArrayIntQueue* q)
{
	return q->num;
}
bool IsEmpty(const ArrayIntQueue* q)
{
	return q->num <= 0;
}
bool IsFull(const ArrayIntQueue* q)
{
	return q->num == q->max;
}
int Search(const ArrayIntQueue* q,int x)
{
	for (int i = 0; i < q->num; i++) {
		if (q->que[i] == x) {
			return i;
		}
	}
	return SEARCH_NOT_FOUND; // -1
}
void Print(const ArrayIntQueue* q)
{
	for (int i = 0; i < q->num; i++) {
		printf("%d ", q->que[i]);
	}
	putchar('\n');
}
void Terminate(ArrayIntQueue* q)
{
	if (q->que != nullptr) {
		free(q->que);
		q->que = nullptr;
	}
	q->max = q->num = 0;
}
