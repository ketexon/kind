#pragma once

#include <string>
#include <ranges>

namespace Kind {
	using HashType = unsigned long long;

	template<typename It>
	constexpr HashType Hash(It start, It end)
	{
		// djb2
		HashType hash = 5381;

		for(It it = start; it != end; ++it) {
			auto c = *it;
			c = c > 0 ? c : -c;
			hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
		}

		return hash;
	}

	template<typename T, size_t N>
	constexpr HashType Hash(const T(&data)[N]) {
		return Hash(data, data + N - 1);
	}

	template<typename T>
	constexpr HashType Hash(const std::basic_string<T>& str) {
		return Hash(str.begin(), str.end());
	}

	template<typename T>
	constexpr HashType Hash(const std::basic_string_view<T>& str) {
		return Hash(str.begin(), str.end());
	}

	namespace literals {
		constexpr HashType operator "" _kh(const char* str, size_t len)
		{
			return Hash(str, str + len);
		}
	}

	namespace impl {
		static inline HashType NextTypeIndex(){
			static HashType index = 0;
			return index++;
		}

		template<typename T>
		HashType TypeIndexImpl(){
			static const HashType index = NextTypeIndex();
			return index;
		}
	}

	template<typename T>
	HashType TypeIndex(){
		return impl::TypeIndexImpl<std::decay_t<T>>();
	}
}