#pragma once

#include <utility>
#include <cstddef>

template <std::size_t Capacity>
struct fixed_string
{
	constexpr fixed_string(
		const char(&str)[Capacity]
	) : m_size(Capacity)
	{
		for (std::size_t i = 0; i < Capacity; ++i)
		{
			m_str[i] = str[i];
			if (str[i] == '\0')
			{
				m_size = i;
				break;
			}
		}
	}

	constexpr char operator[](std::size_t i) const
	{
		return m_str[i];
	}

	char m_str[Capacity];
	std::size_t m_size;
};

template <fixed_string String>
constexpr bool is_palindrome_v = []<std::size_t... Is>(
	[[maybe_unused]] std::index_sequence<Is...>
) {
	return ((String[Is]
		== String[String.m_size - 1 - Is])
		&& ...);
}(std::make_index_sequence<String.m_size / 2>{});
