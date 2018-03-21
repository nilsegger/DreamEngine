#pragma once
template <typename A, typename B>
struct Pair {
	A a;
	B b;
	bool operator==(const Pair& pair) {
		return (this->a == pair.a) && (this->b == pair.b);
	}
	bool operator!=(const Pair& pair) {
		return !((this->a == pair.a) && (this->b == pair.b));
	}
};