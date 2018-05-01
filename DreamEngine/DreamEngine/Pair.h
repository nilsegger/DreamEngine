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

template <typename A, typename B, typename C>
struct Trio {
	A a;
	B b;
	C c;
	bool operator==(const Pair& pair) {
		return (this->a == pair.a) && (this->b == pair.b) && (this->c == pair.c);
	}
	bool operator!=(const Pair& pair) {
		return !((this->a == pair.a) && (this->b == pair.b) && (this->c == pair.c));
	}
};