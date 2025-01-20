#include <ktest/KTest.hpp>
#include <kind/Kind.hpp>

TEST_CASE("Simple test", SimpleTest) {
    using namespace Kind::literals;
    constexpr auto x = Kind::Hash("Hello, World!");
    constexpr auto y = "Hello, World!"_kh;

    static_assert(x == y, "Hashes should be equal and compile time");

    std::string str = "Hello, World!";
    const auto strHash = Kind::Hash(str);
    test.AssertEq(strHash, x, "Hashes should be equal at runtime");
}