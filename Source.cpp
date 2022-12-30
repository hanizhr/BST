#include<iostream>
using namespace std;

class node {
public:
	node() { rCh = lCh = NULL; }
	int data;
	node* rCh;
	node* lCh;
};

class BST {
public:
	node* root;
	BST() { root = NULL; }
	bool insert(int , node*);
	node* search(int,node*);
	bool delet(int,node*);
	void inOrder(node*);
	node* getParent(int, node*);
	node* minkey(node*);
	int getHight(node*);
	void print(int ,node*,char);
};

void BST::print(int n,node* t,char ch) {
	//end point
	if (t == NULL) return;
	//inorder 
	//caling left child
	print(n + 1, t->lCh, '/');
	for (int i = 0; i < n; i++) {
		cout << "   ";
	}
	//caling right childe
	cout <<ch <<t->data << endl;
	print(n + 1, t->rCh, '\\');
}
	
int BST::getHight(node* t) {
	if (t == NULL)
		return 0;
	int lh = getHight(t->lCh);
	int rh = getHight(t->rCh);
	// add 1 to maximom branch
	if (lh > rh)
		return(lh + 1);
	else
		return	(rh + 1);
}

node* BST::minkey(node* t) {
	//return minmom data after node t
	t = t->rCh;
	while (t->lCh != NULL) {
		t = t->lCh;
	}
	return t;
}

node* BST::getParent(int x, node* t) {
	node* parent = NULL;
	node* curr = t;
	if (curr == NULL)
		return parent;
	while (curr != NULL && x!=curr->data) {
		if (x > curr->data) {
			parent = curr;
			curr = curr->rCh;
		}
		else {
			parent = curr;
			curr = curr->lCh;
		}
	}
	if (curr == NULL)
		return NULL;
	return parent;
}

bool BST::delet(int x, node*t) {
	node* parent = getParent(x,t);
	node* curr = search(x, t);
	if (curr == NULL)
		return false;
	//case one  for leaf
	if (curr->lCh == NULL && curr->rCh==NULL) {
		if (curr != root) {
			if (parent->lCh == curr)
				parent->lCh = NULL;
			else
				parent->rCh = NULL;
		}
		else
			root = NULL;

	}
	//case tow for node hade two chile
	else if (curr->lCh && curr->rCh) {
		node* s = minkey(curr);
		int val = s->data;
		delet(s->data, t);
		curr->data = val;
	}
	//case tree for node hade one childe
	else {
		node* chiled = (curr->lCh) ? curr->lCh : curr->rCh;
		if (curr != root) {
			if (curr == parent->lCh)
				parent->lCh = chiled;
			else
				parent->rCh = chiled;
		}
		else
			root = chiled;
	}
}

node* BST::search(int x, node*t) {
	if (t == NULL)
		return NULL;
	if (x == t->data)
		return t;
	
	if (x < t->data)
		search(x, t->lCh);
	else
		search(x, t->rCh);
}

bool BST::insert(int x ,node* t) {
	node* newNode;
	newNode = new node();
	newNode->data = x;
	//for root :
	if (root == NULL) { root = newNode; return true; }
	node* tmp = root;
	node* prv = NULL;
	while (tmp) {
		prv = tmp;
		if (x < tmp->data) tmp = tmp->lCh;
		else tmp = tmp->rCh;
	}
	
	if (prv->data > x) prv->lCh = newNode;
	else prv->rCh = newNode;
	return true;
}

void BST::inOrder(node*t) {
	if (t != NULL)
	{
		inOrder(t->lCh);
		cout << t->data << " ";
		inOrder(t->rCh);
	}
}

int main() {
	BST b;
	b.insert(20, b.root);
	b.insert(18, b.root);
	b.insert(22, b.root);
	b.insert(17, b.root);
	b.insert(19, b.root);
	b.insert(21, b.root);
	b.insert(24, b.root);
	b.insert(16, b.root);
	b.insert(25, b.root);
	b.insert(15, b.root);
	//b.inOrder(b.root);
	cout << endl;
	//cout << b.search(8, b.root);;
	//b.delet(9, b.root);
	//b.inOrder(b.root);
	//cout << endl;
	//cout << b.getHight(b.root);
//	b.print(b.getHight(b.root), b.root);
	b.print(1, b.root,'/');
	return 0;
}