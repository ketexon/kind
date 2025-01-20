# KInd

Ketexon's little hashing library

## Usage

```c++
#include <kind/Kind.hpp>

// for _kh literal
using namespace Kind::literals;

int main(){
	constexpr auto hash1 = "String"_kh;
	constexpr auto hash2 = Kind::Hash("String");
}
```