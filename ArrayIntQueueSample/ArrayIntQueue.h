//=========================================================
//	配列Intキュー
//==========================================================
#ifndef __IntQueue
#define __IntQueue

typedef struct {
	int max;  // キューの容量
	int num;  // 現在のデータ数
	int* que;  // キュー本体
} ArrayIntQueue;

typedef enum {
	SUCCESS=0,
	INITIALIZE_FAIL=1,
	ENQUE_NO_SPACE=2,
	DEQUE_NO_DATA=3,
	PEEK_NO_DATA=4,
} IntQueueResult;

#define SEARCH_NOT_FOUND (-1)

// キューの初期化
IntQueueResult Initialize(ArrayIntQueue* q, int max);
// キューにデータをエンキューする
IntQueueResult Enque(ArrayIntQueue* q, int x);
// キューからデータをデキューする
IntQueueResult Deque(ArrayIntQueue* q, int* x);
// キューからデータをピークする
IntQueueResult Peek(const ArrayIntQueue* q, int* x);
// 全データを削除
void Clear(ArrayIntQueue* q);
// キューの容量
int Capacity(const ArrayIntQueue* q);
// キュー上のデータ数
int Size(const ArrayIntQueue* q);
// キューは空か?
bool IsEmpty(const ArrayIntQueue* q);
// キューは満杯か?
bool IsFull(const ArrayIntQueue* q);
// キューからデータを探索する
int Search(const ArrayIntQueue* q, int x);
// 全データの表示
void Print(const ArrayIntQueue* q);
// キューの後始末
void Terminate(ArrayIntQueue* q);



#endif // __IntQueue
