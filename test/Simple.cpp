#include <ktest/KTest.hpp>
#include <kind/Kind.hpp>

TEST_CASE("Simple hash test", SimpleHashTest) {
    using namespace Kind::literals;
    constexpr auto x = Kind::Hash("Hello, World!");
    constexpr auto y = "Hello, World!"_kh;
    constexpr auto z = "Hello, World"_kh;

    static_assert(x == y, "Hashes should be equal and compile time");
    static_assert(x != z, "Hashes should be different");

    std::string str = "Hello, World!";
    const auto strHash = Kind::Hash(str);
    test.AssertEq(strHash, x, "Hashes should be equal at runtime");
}

struct MyStruct {};
struct MyStruct2 {};

TEST_CASE("Simple TypeIndex Test", SimpleTypeIndexTest) {
    const auto x = Kind::TypeIndex<MyStruct>();
    const auto y = Kind::TypeIndex<const MyStruct>();
    const auto z = Kind::TypeIndex<const MyStruct&>();
    const auto w = Kind::TypeIndex<MyStruct2>();

    test.AssertEq(x, y, "TypeIndex should be equal regardless of const");
    test.AssertEq(y, z, "TypeIndex should be equal regardless of reference");
    test.AssertNeq(x, w, "TypeIndex should be different for different types");
}