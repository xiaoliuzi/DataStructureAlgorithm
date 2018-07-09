#include "intBTnode.h"
#include <iostream>
#include <queue>

using namespace std;

void preorderTraverse(intBTnode* p) {
	if (p != NULL) {
		cout << p->data << " ";
		preorderTraverse(p->lChild);
		preorderTraverse(p->rChild);
	}
}

void inorderTraverse(intBTnode* p) {
	if (p != NULL) {
		inorderTraverse(p->lChild);
		cout << p->data << " ";
		inorderTraverse(p->rChild);
	}
}

void postTraverse(intBTnode* p) {
	if (p != NULL) {
		postTraverse(p->lChild);
		postTraverse(p->rChild);
		cout << p->data << " ";
	}
}

// level traverse order
void levelorderTraverse(intBTnode* p) {
	queue<intBTnode*> Q;
	if (p != NULL) {
		Q.push(p);
	}
	while (!Q.empty()) {
		// print the first element of queue
		cout << Q.front()->data << " ";
		// if the left child  of the front exists, then enqueue
		if (Q.front()->lChild != NULL) {
			Q.push(Q.front()->lChild);
		}
		// the same as the right child
		if (Q.front()->rChild != NULL) {
			Q.push(Q.front()->rChild);
		}
		// delete the first element of the queue
		Q.pop();
	}
}

