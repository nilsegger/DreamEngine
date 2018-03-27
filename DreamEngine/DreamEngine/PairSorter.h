#pragma once


#include <vector>
#include "Pair.h"

template <typename A, typename B>
class PairSorter {
public:
	void add(Pair<A, B> pair);
	B get(A key);
private:
	std::vector<Pair<A, B>> pairs;
};

template<typename A, typename B>
inline void PairSorter<A, B>::add(Pair<A, B> pair)
{
	pairs.push_back(pair);
}

template<typename A, typename B>
inline B PairSorter<A, B>::get(A key)
{
	for (int i = 0; i < int(pairs.size()); i++) {
		if (pairs[i].a == key) return pairs[i].b;
	}

	return B();
}
