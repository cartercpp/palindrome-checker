#include "palindrome.hpp"

int main()
{
	static_assert(is_palindrome_v<"racecar">, "x");
	static_assert(!is_palindrome_v<"carter">, "x");
}
