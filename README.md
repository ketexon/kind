# KInd

Ketexon's little hashing library

## Usage

```c++
#include <kind/Kind.hpp>

// for _kh literal
using namespace Kind::literals;

struct MyStruct {};
struct MyStruct2 {};

int main(){
	constexpr auto hash1 = "String"_kh;
	constexpr auto hash2 = Kind::Hash("String");
	// hash1 == hash2

	const auto id1 = Kind::TypeIndex<MyStruct>();
	const auto id2 = Kind::TypeIndex<const MyStruct&>();
	const auto id3 = Kind::TypeIndex<MyStruct2>();
	// id1 == id2
	// id1 != id3
}
```