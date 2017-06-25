#include<iostream>
#include<cmath>

template<typename T, typename U>
T* solve(const T t, const U u)
{
	T answer[2];
	if (t == 0)
	{
		answer[0] = 0;
		return answer;
	}

	answer[0] = 1;
	answer[1] = ((u * -1) / t);
	return answer;

}

template<typename T, typename U, typename X>
T* solve(const T t, const U u, const X x)
{
	T answer[3];
	auto d = (u*u) - 4 * t * x;
	if (d < 0)
	{
		answer[0] = 0;
		return answer;
	}
	if (d == 0)
	{
		answer[0] = 1;
		answer[1] = (-u / (2 * t));
		return answer;
	}

	answer[0] = 2;
	answer[1] = (-u + sqrt(d)) / (2 * t);
	answer[2] = (-u - sqrt(d)) / (2 * t);
	return answer;
}

int main()
{
	auto *arr2 = solve(0, 5);

	if (arr2[0] == 0)
		std::cout << "Test 1: OK!\n";
	else
		std::cout << "Test 1: Error!\n";

	arr2 = solve(5, 5);

	if (arr2[1] == -1)
		std::cout << "Test 2: OK!\n";
	else
		std::cout << "Test 2: Error!\n";


	auto *arr3 = solve(3, -5, 23);
	if (arr3[0] == 0)
		std::cout << "Test 3: OK!\n";
	else
		std::cout << "Test 3: Error!\n";

	arr3 = solve(1, -4, 4);
	if (arr3[0] == 1 && arr3[1] == 2)
		std::cout << "Test 4: OK!\n";
	else
		std::cout << "Test 4: Error!\n";

	arr3 = solve(1, 2, -48);
	if (arr3[0] == 2 && (arr3[1] == 6 || arr3[1] == -8) && (arr3[2] == 6 || arr3[2] == -8))
		std::cout << "Test 5: OK!\n";
	else
		std::cout << "Test 5: Error!\n";

	return 0;
}
