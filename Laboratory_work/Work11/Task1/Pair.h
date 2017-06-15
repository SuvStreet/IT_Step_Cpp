#pragma once

template<typename T = int, typename U = char>
class Pair {
	T first;
	U second;
public:
	Pair(const T, const U);

	~Pair() = default;

	T getFirst() const;
	U getSecond() const;

	void make_pair(const T, const U);
};

template<typename T, typename U>
Pair<T, U>::Pair(const T a, const U b) : first(a), second(b) {}

template<typename T, typename U>
T Pair<T, U>::getFirst() const {
	return first;
}

template<typename T, typename U>
U Pair<T, U>::getSecond() const {
	return second;
}

template<typename T, typename U>
void Pair<T, U>::make_pair(const T a, const U b) {
	Pair(a, b);
}

template<>
class Pair <bool, bool>{
	bool first;
	bool second;
public:
	Pair(const bool);

	~Pair() = default;

	bool getFirst() const;
	bool getSecond() const;

	void make_pair(const bool, const bool);
};

template<typename T, typename U>
Pair<T, U>::Pair(const T a, const U b) : first(a), second(b) {}

bool Pair<bool, bool>::getFirst() const {
	return first;
}

bool Pair<bool, bool>::getSecond() const {
	return second;
}

template<typename T, typename U>
void Pair<T, U>::make_pair(const T a, const U b) {
	Pair(a, b);
}
