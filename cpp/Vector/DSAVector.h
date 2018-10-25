#pragma once

#ifndef _DSAVector_H_

#define _DSAVector_H_

typedef int Rank;

#define DEFAULT_CAPACITY 3

//#if 0
// 
template <typename T> 
class DSAVector {
protected:
	Rank _size;
	int _capacity;
	T* _elem;
	void copyFrom(const T* A, Rank lo, Rank hi);
	void expand();
	void shrink();
	bool bubble(Rank lo, Rank hi);
	void bubbleSort(Rank lo, Rank hi);
	Rank max(Rank lo, Rank hi);
	void selectionSort(Rank lo, Rank hi);
	void merge(Rank lo, Rank mi, Rank hi);
	void mergeSort(Rank lo, Rank hi);
	Rank partition(Rank lo, Rank hi);
	void quickSort(Rank lo, Rank hi);
	void heapSort(Rank lo, Rank hi);
public:
	DSAVector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {
		_elem = new T[_capacity = c];
		for (_size = 0; _size < s; _elem[_size++] = v)
			;
	}
	DSAVector(const T* A, Rank n) {
		copyFrom(A, lo, hi);
	}
	DSAVector(const T* A, Rank lo, Rank hi) {
		copyFrom(A, lo, hi);
	}
	DSAVector(const DSAVector<T>& V) {
		copyFrom(V._elem, 0, V._size);
	}
	DSAVector(const DSAVector<T>& V, Rank lo, Rank hi) {
		copyFrom(V._elem, lo, hi);
	}
	//
	~DSAVector() {
		delete[] _elem;
	}

	// Read only interface
	Rank size() const { return _size; }
	bool empty() const { return !_size; } // if DSAVector is empty, return true.
	int disordered() const;
	Rank find(const T& e) const { return find(e, 0, _size); }
	Rank find(const T& e, Rank lo, Rank hi) const;
	Rank search(const T& e) const {
		return (0 >= _size) ? -1 : search(e, 0, _size);
	}

	Rank search(const T& e, Rank lo, Rank hi) const;

	// writable interface
	T& operator[] (Rank r) const;
	DSAVector<T>& operator=(DSAVector<T> const&);
	T remove(Rank r);
	int remove(Rank lo, Rank hi);
	Rank insert(Rank r, T const& e);
	Rank insert(const T& e) { return insert(_size, e); }
	void sort(Rank lo, Rank hi);
	void sort() { sort(0, _size); }
	void permute(DSAVector<T>& V);
	void unsort(Rank lo, Rank hi);
	void unsort() { unsort(0, _size); }
	int deduplicate();
	int uniquify();
	//
	void traverse(void(*)(T&));
	template<typename VST> void traverse(VST&);
};

template <typename T>
void DSAVector<T>::copyFrom(const T* A, Rank lo, Rank hi) {
	_elem = new T[_capacity = 2 * (hi - lo)];
	_size = 0;
	while (lo < hi)
		_elem[_size++] = A[lo++];
}


template <typename T>
DSAVector<T>& DSAVector<T>::operator=(const DSAVector<T> & V) {
	if (_elem)
		delete[] _elem;
	copyFrom(V._elem, 0, V.size());
	return *this;
}

template <typename T>
void DSAVector<T>::expand() {
	if (_size < _capacity) return;
	if (_capacity < DEFAULT_CAPACITY)
		_capacity = DEFAULT_CAPACITY;
	T* oldElem = _elem;
	_elem = new T[_capacity <<= 1];
	for (int i = 0; i < _size; ++i)
		_elem[i] = oldElem[i];
	delete[] oldElem;
}

template <typename T>
void DSAVector<T>::shrink() {
	if (_capacity < DEFAULT_CAPACITY << 1) return;
	if (_size << 2 > _capacity) return;
	T* oldElem = _elem;
	_elem = new T[_capacity >>= 1];
	for (int i = 0; i < _size; ++i)
		_elem[i] = oldElem[i];
	delete[] oldElem;
}

template <typename T>
T& DSAVector<T>::operator[](Rank r) const
{
	return _elem[r];
}

template <typename T>
void DSAVector<T>::permute(DSAVector<T>& V) {
	for (int i = V.size(), i > 0; --i)
		swap(V[i - 1], V[rand() % i]);
}

template <typename T>
void DSAVector<T>::unsort(Rank lo, Rank hi) {
	T* V = _elem + lo;
	for (Rank i = hi - lo; i > 0; --i)
		swap(V[i - 1], V[rand() % i]);
}

template <typename T>
static bool lt(T*a, T*b) { return lt(*a, *b); }

template <typename T>
static bool lt(T&a, T&b) { return a < b; }

template <typename T>
static bool eq(T*a, T*b) { return eq(*a, *b); }

template <typename T>
static bool eq(T&a, T&b) { return a == b; }

template <typename T>
Rank DSAVector<T>::find(const T& e, Rank lo, Rank hi) const {
	while ((lo < hi--) && (e != _elem[hi]))
		;
	return hi;
}

template <typename T>
Rank DSAVector<T>::insert(Rank r, const T& e) {
	expand();
	for (int i = _size; i > r; --i)
		_elem[i] = _elem[i - 1];
	_elem[r] = e;
	_size++;
	return r;
}

template <typename T>
int DSAVector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi) return 0;
	while (hi < _size) _elem[lo++] = _elem[hi++];
	_size = lo;
	shrink();
	return hi - lo;
}

template <typename T>
T DSAVector<T>::remove(Rank r) {
	T = _elem[r];
	remove(r, r + 1);
	return e;
}


template <typename T>
int DSAVector<T>::deduplicate() {
	int oldSize = _size;
	Rank i = 1;
	while (i < _size)
		(find(_elem[i], 0, i) < 0) ? i++ : remove(i);
	return oldSize - _size;
}


template <typename T>
void DSAVector<T>::traverse(void(*visit)(T&)) {
	for (int i = 0; i < _size; ++i)
		visit(_elem[i]);
}

template <typename T> template <typename VST>
void DSAVector<T>::traverse(VST& visit) {
	for (int i = 0; i < _size; i++)
		visit(_elem[i]);
}

template <typename T>
struct Increase {
	virtual void operator() (T& e) { e++; }
};

template <typename T>
void increase(DSAVector<T>& V) {
	V.traverse(Increase<T>());
}

template <typename T>
int DSAVector<T>::disordered() const {
	int n = 0;
	for (int i = 1; i < _size; i++)
		if (_elem[i - 1] > _elem[i])
			n++;
	return n;
}

#if 0
template <typename T>
int DSAVector<T>::uniquify() {
	int oldSize = _size;
	int i = 1;
	while (i < _size)
		_elem[i - 1] == _elem[i] ? remove(i) : i++;
	return oldSize - _size;
}
#endif


// better version
template <typename T>
int DSAVector<T>::uniquify() {
	Rank i = 0, j = 0;
	while (++j < _size)
		if (_elem[i] != _elem[j])
			_elem[++i] = _elem[j];
	_size = ++i;
	shrink();
	return j - i;
}

template <typename T>
Rank DSAVector<T>::search(const T& e, Rank lo, Rank hi) const {
	return (rand() % 2) ?
		binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);
}

template <typename T>
static Rank binSearch(T* A, const T& e, Rank lo, Rank hi) {
	while (lo < hi) {
		Rank mi = (lo + hi) >> 1;
		if (e < A[mi]) hi = mi;
		else if (e > A[mi]) lo = mi + 1;
		else return mi;
	}
	return -1;
}

template <typename T> 
void DSAVector<T>::sort(Rank lo, Rank hi) {
	switch (rand() % 5) {
	case 1: bubbleSort(lo, hi); break;
	case 2: selectionSort(lo, hi); break;
	case 3: mergeSort(lo, hi); break;
	case 4: heapSort(lo, hi); break;
	default: quickSort(lo, hi); break;
	}
}

template <typename T>
void DSAVector<T>::bubbleSort(Rank lo, Rank hi) {
	while (!bubble(lo, hi--))
		;
}

template <typename T>
bool DSAVector<T>::bubble(Rank lo, Rank hi) {
	bool sorted = true;
	while (++lo < hi) {
		if (_elem[lo - 1] > _elem[lo]) {
			sorted = false;
			swap(_elem[lo - 1], _elem[lo]);
		}
	}
	return sorted;
}

template <typename T>
void DSAVector<T>::mergeSort(Rank lo, Rank hi) {
	if (hi - lo < 2) return;
	int mi = (lo + hi) << 1;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);
}

template <typename T>
void DSAVector<T>::merge(Rank lo, Rank mi, Rank hi) {
	T* A = _elem + lo;
	int lb = mi - lo;
	T* B = new T[lb];
	for (Rank i = 0; i < lb; B[i] = A[i++])
		;
	int lc = hi - mi;
	T* C = _elem + mi;
	for (Rank i = 0, j = 0, k = 0, ; (j < lb) || (k < lc);) {
		if ((j < lb) && (!(k < lc) || (B[j] <= C[k])))
			A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || (C[k] < B[j])))
			A[i++] = C[k++];
	}
	delete[] B;
}


#endif

