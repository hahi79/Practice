//=========================================================
//	Intデック
//==========================================================
#ifndef __IntDeque
#define __IntDeque

typedef struct {
	int max;  // キューの容量
	int num;  // 現在のデータ数
	int front; // 先頭要素のカーソル
	int rear;  // 末尾要素のカーソル
	int* que;  // キュー本体
} IntDeque;

typedef enum {
	SUCCESS=0,
	INITIALIZE_FAIL=1,
	ENQUE_NO_SPACE=2,
	DEQUE_NO_DATA=3,
	PEEK_NO_DATA=4,
} IntDequeResult;

#define SEARCH_NOT_FOUND (-1)

// キューの初期化
IntDequeResult Initialize(IntDeque* q, int max);
// キューフロントにデータをエンキューする
IntDequeResult EnqueFront(IntDeque* q, int x);
// キューリアにデータをエンキューする
IntDequeResult EnqueRear(IntDeque* q, int x);
// キューフロントからデータをデキューする
IntDequeResult DequeFront(IntDeque* q, int* x);
// キューリアからデータをデキューする
IntDequeResult DequeRear(IntDeque* q, int* x);
// キューフロントからデータをピークする
IntDequeResult PeekFront(const IntDeque* q, int* x);
// キューリアからデータをピークする
IntDequeResult PeekRear(const IntDeque* q, int* x);
// 全データを削除
void Clear(IntDeque* q);
// キューの容量
int Capacity(const IntDeque* q);
// キュー上のデータ数
int Size(const IntDeque* q);
// キューは空か?
bool IsEmpty(const IntDeque* q);
// キューは満杯か?
bool IsFull(const IntDeque* q);
// キューからデータを探索する
int Search(const IntDeque* q, int x);
// 全データの表示
void Print(const IntDeque* q);
// キューの後始末
void Terminate(IntDeque* q);



#endif // __IntDeque
