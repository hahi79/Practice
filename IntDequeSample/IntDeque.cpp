//=========================================================
//	Intデック
//==========================================================
#define _CRT_SECURE_NO_WARNINGS
#include "IntDeque.h"
#include <stdio.h> // printf().sprintf()
#include <stdlib.h> // calloc(),free()
#include <string.h> // strcpy()


IntDequeResult Initialize(IntDeque* q, int max)
{
	q->num = q->front = q->rear = 0;
	q->que = (int*)calloc(max, sizeof(int));
	if (q->que == nullptr) {
		q->max = 0;
		return INITIALIZE_FAIL;
	}
	q->max = max;
	return SUCCESS;
}

IntDequeResult EnqueFront(IntDeque* q, int x)
{
	if (q->num >= q->max) {
		return ENQUE_NO_SPACE;
	}
	else {
		q->num++;
		q->front--;
		if (q->front < 0) {
			q->front = q->max - 1;
		}
		q->que[q->front] = x;
		return SUCCESS;
	}
}
IntDequeResult EnqueRear(IntDeque* q, int x)
{
	if (q->num >= q->max) {
		return ENQUE_NO_SPACE;
	}
	else {
		q->num++;
		q->que[q->rear] = x;
		q->rear++;
		if (q->rear == q->max) {
			q->rear = 0;
		}
		return SUCCESS;
	}
}
IntDequeResult DequeFront(IntDeque* q, int* x)
{
	if (q->num <= 0) {
		return	DEQUE_NO_DATA;
	}
	else {
		q->num--;
		*x = q->que[q->front];
		q->front++;
		if (q->front == q->max) {
			q->front = 0;
		}
		return SUCCESS;
	}
}
IntDequeResult DequeRear(IntDeque* q, int* x)
{
	if (q->num <= 0) {
		return	DEQUE_NO_DATA;
	}
	else {
		q->num--;
		q->rear--;
		if (q->rear < 0) {
			q->rear = q->max - 1;
		}
		*x = q->que[q->rear];
		return SUCCESS;
	}
}
IntDequeResult PeekFront(const IntDeque* q, int* x)
{
	if (q->num <= 0) {
		return	PEEK_NO_DATA;
	}
	else {
		*x = q->que[q->front];
		return SUCCESS;
	}
}
IntDequeResult PeekRear(const IntDeque* q, int* x)
{
	if (q->num <= 0) {
		return	PEEK_NO_DATA;
	}
	else {
		int idx = q->rear - 1;
		if (idx < 0) {
			idx = q->max - 1;
		}
		*x = q->que[idx];
		return SUCCESS;
	}
}
void Clear(IntDeque* q)
{
	q->num = q->front = q->rear = 0;
}
int Capacity(const IntDeque* q)
{
	return q->max;
}
int Size(const IntDeque* q)
{
	return q->num;
}
bool IsEmpty(const IntDeque* q)
{
	return q->num <= 0;
}
bool IsFull(const IntDeque* q)
{
	return q->num == q->max;
}
int Search(const IntDeque* q, int x)
{
	for (int i = 0; i < q->num; i++) {
		int idx = (q->front + i) % q->max;
		if (q->que[idx] == x) {
			return i;
		}
	}
	return SEARCH_NOT_FOUND;  // -1
}
void Print(const IntDeque* q)
{
	// Front, Rearマークの表示
	for (int i = 0; i < q->max; i++) {
		const char* mark = "";
		if (i == q->front) {
			mark = (i != q->rear) ? "F" : "FR";
		}
		else if (i == q->rear) {
			mark = "R";
		}
		printf("%3s", mark);
	}
	putchar('\n');
	// データの表示
	const int BUFF_SIZE = 32;
	char buff[BUFF_SIZE];
	for (int i = 0; i < q->max; i++) {
		strcpy(buff, "--");
		if (IsEmpty(q) == false) {
			bool isData = false;
			if (q->front < q->rear) {
				isData = (q->front <= i && i < q->rear);
			}
			else if (q->rear < q->front) {
				isData = (i < q->rear || q->front <= i);
			}
			else { // q->rear==q->front
				isData = true;
			}
			if (isData) {
				sprintf(buff, "%2d", q->que[i]);
			}
		}
		printf("%3s", buff);
	}
	putchar('\n');
}
void Terminate(IntDeque* q)
{
	if (q->que != nullptr) {
		free(q->que);
		q->que = nullptr;
	}
	q->max = q->num = q->front = q->rear = 0;
}
