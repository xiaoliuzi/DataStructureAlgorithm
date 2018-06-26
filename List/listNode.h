#pragma once
#ifndef _LISTNODE_H_

#define _LISTNODE_H_

typedef int Rank;
#define ListNodePosi(T) ListNode<T>*

template <typename T> struct ListNode {
public:
	T data;
	ListNodePosi(T) pred;
	ListNodePosi(T) succ;

	ListNode() {}
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
		: data(e), pred(p), succ(s) {}
	ListNodePosi(T) insertAsPred(T const& e);
	ListNodePosi(T) insertAsSucc(T const& e);
};

#endif