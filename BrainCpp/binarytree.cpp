#include <iostream>

using namespace std;

class treeNode
{
	friend class tree;
private:
	int value;
	treeNode *left, *right;
	treeNode(int val) : value(val), left(NULL), right(NULL) {}		// 생성자
};

class tree
{
private:
	void recursiveInsert(treeNode *&, int);
	void recursiveRemove(treeNode *&, int);
	void preorderRecursivePrint(treeNode*);
	void postorderRecursivePrint(treeNode*);
	void inorderRecursivePrint(treeNode*);

public:
	treeNode *root;
	tree() : root(NULL) {}		// 생성자
	void insert(int);
	void remove(int);
	void preorderPrint();
	void postorderPrint();
	void inorderPrint();
};

void tree::recursiveInsert(treeNode * &node, int val)
{
	if(node == NULL)
		node = new treeNode(val);			// 탐색하고 있는 노드가 NULL이면 새로 만든다(삽입)
	else if (val > node -> value)
		recursiveInsert(node->right, val);	// 삽입할 값이 노드의 값보다 크면 오른쪽 Chilld를 탐색
	else if (val < node -> value)
		recursiveInsert(node->left, val);	// 삽입할 값이 노드의 값보다 작으면 왼쪽 Child를 탐색
}