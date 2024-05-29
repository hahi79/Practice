//=========================================================
//	IntスタックTwin
//==========================================================
#ifndef __IntStackTwin
#define __IntStackTwin

typedef struct {
	int max;   // スタックの容量
	int ptrA;  // スタックのポインターA(0,1,2,...)
	int ptrB;  // スタックのポインターB(max,max-1,max-2...)
	int* stk;  // スタック本体
} IntStackTwin;

typedef enum {
	SUCCESS=0,
	INITIALIZE_FAIL=1,
	PUSH_NO_SPACE=2,
	POP_NO_DATA=3,
	PEEK_NO_DATA=4,
} IntStackResult;

#define SEARCH_NOT_FOUND (-1)

// スタックの初期化
IntStackResult Initialize(IntStackTwin* s, int max);
// スタックへデータをプッシュ
IntStackResult PushA(IntStackTwin* s, int x);
IntStackResult PushB(IntStackTwin* s, int x);
// スタックからデータをポッブ
IntStackResult PopA(IntStackTwin* s, int* x);
IntStackResult PopB(IntStackTwin* s, int* x);
// スタックからデータをピーク
IntStackResult PeekA(IntStackTwin* s, int* x);
IntStackResult PeekB(IntStackTwin* s, int* x);
// スタックを空にする
void ClearA(IntStackTwin* s);
void ClearB(IntStackTwin* s);
// スタックの容量を取得
int Capacity(const IntStackTwin* s);
// スタックのデータ数を取得
int SizeA(const IntStackTwin* s);
int SizeB(const IntStackTwin* s);
// スタックは空か?
bool IsEmptyA(const IntStackTwin* s);
bool IsEmptyB(const IntStackTwin* s);
// スタックは満杯か?
bool IsFull(const IntStackTwin* s);
// スタックから検索
int SearchA(const IntStackTwin* s, int x);
int SearchB(const IntStackTwin* s, int x);
// 全データの表示
void Print(const IntStackTwin* s);
// スタックの後始末
void Terminate(IntStackTwin* s);

#endif // __intStackTwin
