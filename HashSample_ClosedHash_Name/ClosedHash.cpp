//==========================================================
//	クローズドハッシュ
//==========================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // strcmp()
#include "Member.h"
#include "ClosedHash.h"

// 関数プロトタイプ
static int hash(const char *key, int size);
static int rehash(int key, int size);
static void setBucket(Bucket *n, const Member* x, Status stat);


ClosedHashResult Initialize(ClosedHash* h, int size)
{
	h->table = (Bucket*)calloc(size, sizeof(Bucket));
	if (h->table == nullptr) {
		h->size = 0;
		return INITIALIZE_FAIL;
	}
	h->size = size;
	for (int i = 0; i < size; i++) {
		h->table[i].stat = Empty;
	}
	return SUCCESS;
}

Bucket* Search(const ClosedHash* h, const Member* x)
{
	int key = hash(x->name, h->size);
	Bucket* p = &h->table[key];
	for (int i = 0; p->stat != Empty && i < h->size; i++) {
		if (p->stat == Occupied && strcmp(p->data.name, x->name) == 0) {
			return p;
		}
		key = rehash(key, h->size);
		p = &h->table[key];
	}
	return nullptr;
}

ClosedHashResult Add(ClosedHash* h, const Member* x)
{
	int key = hash(x->name, h->size);
	Bucket* p = &h->table[key];

	if (Search(h, x) != nullptr) {
		return ADD_ALREADY_EXIST;
	}
	for (int i = 0; i < h->size; i++) {
		if (p->stat == Empty || p->stat == Deleted) {
			setBucket(p, x, Occupied);
			return SUCCESS;
		}
		key = rehash(key, h->size);
		p = &h->table[key];
	}
	return ADD_NO_SPACE;
}

ClosedHashResult Remove(ClosedHash* h, const Member* x)
{
	Bucket* p = Search(h, x);
	if (p == nullptr) {
		return REMOVE_NOT_FOUND;
	}
	p->stat = Deleted;
	return SUCCESS;
}

void Dump(const ClosedHash* h)
{
	for (int i = 0; i < h->size; i++) {
		printf("%02d:", i);
		Bucket* p = &h->table[i];
		switch (p->stat) {
		case Occupied:
			printf("%d(%s)\n", p->data.no, p->data.name);
			break;
		case Empty:
			printf("-- 未登録 -- \n");
			break;
		case Deleted:
			printf("-- 削除済 --\n");
			break;
		}
	}
}

void Clear(ClosedHash* h)
{
	for (int i = 0; i < h->size; i++) {
		h->table[i].stat = Empty;
	}
}

void Terminate(ClosedHash* h)
{
	Clear(h);
	free(h->table);
	h->size = 0;
	h->table = nullptr;
}

static int hash(const char *key, int size) 
{
	unsigned int value=0;
	while (*key != '\0') {
		int c = *key++;
		value = (value << 5) + value + c;
	}
	// 負値%sizeは負値になってまずい
	return value % size;
}
static int rehash(int key, int size)
{
	return (key + 1) % size;
}
static void setBucket(Bucket* n, const Member* x, Status stat)
{
	n->data = *x;
	n->stat = stat;
}



