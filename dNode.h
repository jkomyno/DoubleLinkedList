#pragma once

// incomplete declaration of dList
template <class T>
class dList;

template <class T>
class dNode {
	friend class dList<T>;
private:
	// node class fields
	T info;
	dNode *prev, *next;

	dNode(const T& a, dNode* b = nullptr, dNode* c = nullptr) :
		info(a),
		prev(b),
		next(c)
	{}
public:
	~dNode() {
		if (next != nullptr) {
			delete next;
		}
	}
};
