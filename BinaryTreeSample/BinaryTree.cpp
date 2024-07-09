//==========================================================
//	２分探索木
//==========================================================
#include "BinaryTree.h"
#include <stdio.h>   // printf(),puts()
#include <stdlib.h>  // calloc(),free()

// 関数プロトタイプ
static BinNode* allocBinNode(void);
static void setBinNode(BinNode* node, const Member *x, const BinNode* left, const BinNode* right);
static void dumpMem(const void* _adrs, int dumpSize, const char* title);

// 探索
BinNode* Search(BinNode* p, const Member* x)
{
	if (p == nullptr) {
		return nullptr;
	}
	int cond = MemberNoCmp(x, &p->data);
	if (cond == 0) {
		return p;
	}
	else if (cond < 0) {
		return Search(p->left, x);
	}
	else { // cond>0
		return Search(p->right, x);
	}
}
// ノードの挿入
BinNode* Add(BinNode* p, const Member* x)
{
	if (p == nullptr) {
		p = allocBinNode();
		setBinNode(p, x, nullptr, nullptr);
		return p;
	}
	int cond = MemberNoCmp(x, &p->data);
	if (cond == 0) {
		printf("【エラー】%dは既に登録されています\n", x->no);
	}
	else if (cond < 0) {
		p->left = Add(p->left, x);
	}
	else {
		p->right = Add(p->right, x);
	}
	return p;
}
// ノードの削除
bool Remove(BinNode** root, const Member* x)
{
	BinNode* next, * temp;
	BinNode** left;
	BinNode** p = root;

	while (true) {
		int cond;
		if (*p == nullptr) {
			printf("【エラー】%dは登録されていません\n", x->no);
			return false;
		}
		cond = MemberNoCmp(x, &(*p)->data);
		if (cond == 0) {
			break;
		}
		else if (cond < 0) {
			p = &(*p)->left;
		}
		else {
			p = &(*p)->right;
		}
	}
	if ((*p)->left == nullptr) {
		next = (*p)->right;
	}
	else {
		left = &(*p)->left;
		while ((*left)->right == nullptr) {
			left = &(*left)->right;
		}
		next = *left;
		*left = (*left)->left;
		next->left = (*p)->left;
		next->right = (*p)->right;
	}
	temp = *p;
	*p = next;
	free(temp);

	return true;
}
// 全ノードの表示
void PrintTree(const BinNode* p)
{
	if (p != nullptr) {
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}
// 全ノードの削除
void FreeTree(BinNode* p)
{
	if (p != nullptr) {
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}

// ノードを動的に確保
static BinNode* allocBinNode(void)
{
	BinNode* node = (BinNode*)calloc(1, sizeof(BinNode));
	if (node == nullptr) {
		printf("calloc失敗");
		exit(1);
	}
	return node;
}
// ノードのメンバー設定
static void setBinNode(BinNode* node, const Member* x, const BinNode* left, const BinNode* right)
{
	node->data = *x;
	node->left = (BinNode*)left;
	node->right = (BinNode*)right;
}

void DumpTree(BinNode* p,int level)
{
	if (p != nullptr) {
		char name[32];
		snprintf(name, sizeof(name), "binNode(%d)", level);
		dumpMem(p, sizeof(BinNode), name);
		DumpTree(p->left, level + 1);
		DumpTree(p->right, level + 1);
	}
}

static void dumpMem(const void* _adrs, int dumpSize, const char* title)
{
	const int lineSize = 16;
	printf("--%s--\n", title);
	const unsigned char* adrs = (const unsigned char*)_adrs;

	const unsigned char* end = &adrs[dumpSize];
	while (adrs < end) {
		printf("%p:", adrs);
		for (int i = 0; i < lineSize; i++) {
			if (&adrs[i] < end) {
				printf(" %02x", adrs[i]);
			}
			else {
				printf("   ");
			}
		}
		printf(" : ");
		for (int i = 0; i < lineSize; i++) {
			if (&adrs[i] < end) {
				int c = (adrs[i] >= 0x20) ? adrs[i] : '.';
				printf("%c", c);
			}
			else {
				printf(" ");
			}
		}
		putchar('\n');
		adrs += lineSize;
	}
	putchar('\n');
	putchar('\n');
	putchar('\n');
}

// ツリー状態をプリント
static void getMaxLevel(BinNode* p, int level, int* maxLevel);
static void setNodeList(BinNode* p, BinNode*** nodeListPtr, int level, int setNodeLevel,int maxLevel);
static void printSpace(int n);
static int powerOf2(int n);
void PrintTreeState(BinNode* p)
{
	int maxLevel = 0;
	getMaxLevel(p, 0, &maxLevel);
	int listSize = powerOf2(maxLevel + 1) - 1;
	BinNode** nodeList = (BinNode**)calloc(listSize, sizeof(BinNode*));
	BinNode** nodeListPtr = nodeList;
	//          0       
	//        ／ ＼           
	//       1     2      =>  nodeList[] へ格納(nullptrも格納)
	//     ／ ＼  ／ ＼
	//    3    4  5    6
	//
	for (int  lv = 0; lv <= maxLevel; lv++) {
		setNodeList(p, &nodeListPtr, 0, lv, maxLevel);
	}

	int height = maxLevel + 1;
	
	int idx = 0;
	int level_w = 1;
	for (int level = 0; level < height; level++) {
		printSpace(powerOf2(height - level) - 2);
		for (int j = 0; j < level_w; j++) {
			BinNode* x = nodeList[idx++];
			if (x != nullptr) {
				printf("%2d", x->data.no);
			}
			else {
				printf("  ");
			}
			if (idx >= listSize) goto exit;
			printSpace(powerOf2(height - level + 1) - 2);
		}
		putchar('\n');
		printSpace(powerOf2(height - level) - 3);
		for (int k = 0; k < level_w; k++) {
			int child = 2 * k + idx;
			const char* branch;
			branch= (child < listSize && nodeList[child] != nullptr)?"／":"　";
			printf(branch);
			child++;
			branch = (child < listSize && nodeList[child] != nullptr) ? "＼" : "　";
			printf(branch);
			printSpace(powerOf2(height - level + 1) - 4);
		}
		putchar('\n');
		level_w *= 2;
	}
exit:
	putchar('\n');

	free(nodeList);
}
// nodeList[]に登録
static void setNodeList(BinNode* p,BinNode*** nodeListPtr,int level,int setNodeLevel,int maxLevel)
{
	if (level > maxLevel) {
		return;
	}
	if (level == setNodeLevel) {
		BinNode** np = (*nodeListPtr)++;
		*np = p;
	}
	if (p != nullptr) {
		setNodeList(p->left, nodeListPtr,level + 1, setNodeLevel,maxLevel);
		setNodeList(p->right, nodeListPtr,level + 1, setNodeLevel, maxLevel);
	}
	else {
		setNodeList(nullptr, nodeListPtr, level + 1, setNodeLevel, maxLevel);
		setNodeList(nullptr, nodeListPtr, level + 1, setNodeLevel, maxLevel);
	}
}
// 最大レベルを得る
static void getMaxLevel(BinNode* p,int level,int *maxLevel)
{
	if (p != nullptr) {
		if (*maxLevel < level) {
			*maxLevel = level;
		}
		getMaxLevel(p->left, level + 1, maxLevel);
		getMaxLevel(p->right, level + 1, maxLevel);
	}
}
// n個の空白表示
static void printSpace(int n)
{
	for (int i = 0; i < n; i++) {
		printf(" ");
	}
}
// 2のn乗を得る
static int powerOf2(int n)
{
	int power = 1;
	while (n > 0) {
		power *= 2;
		n--;
	}
	return power;
}