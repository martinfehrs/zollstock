#include <catch2/catch_all.hpp>
#include <zollstock/scalar.hpp>

#include <climits>


namespace zs = zollstock;

using namespace zs::units;


TEST_CASE("scalar aliases", "[scalar]")
{
    STATIC_REQUIRE(std::same_as<zs::short_int_t    <>, zs::scalar<_1, short int     >>);
    STATIC_REQUIRE(std::same_as<zs::short_t        <>, zs::scalar<_1, short int     >>);
    STATIC_REQUIRE(std::same_as<zs::int_t          <>, zs::scalar<_1, int           >>);
    STATIC_REQUIRE(std::same_as<zs::long_int_t     <>, zs::scalar<_1, long int      >>);
    STATIC_REQUIRE(std::same_as<zs::long_t         <>, zs::scalar<_1, long int      >>);
    STATIC_REQUIRE(std::same_as<zs::long_long_int_t<>, zs::scalar<_1, long  long int>>);
    STATIC_REQUIRE(std::same_as<zs::long_long_t    <>, zs::scalar<_1, long  long int>>);
    STATIC_REQUIRE(std::same_as<zs::float_t        <>, zs::scalar<_1, float         >>);
    STATIC_REQUIRE(std::same_as<zs::double_t       <>, zs::scalar<_1, double        >>);
    STATIC_REQUIRE(std::same_as<zs::long_double_t  <>, zs::scalar<_1, long double   >>);
}

TEST_CASE("scalar type requirements", "[scalar]")
{
    STATIC_REQUIRE(std::regular<zs::int_t<>>);
    STATIC_REQUIRE(std::same_as<typename zs::int_t<>::value_type, int>);
    STATIC_REQUIRE(std::same_as<typename zs::int_t<>::unit_type , one>);
    STATIC_REQUIRE(zs::int_t<>::unit() == _1);
}

TEST_CASE("scalar construction", "[scalar]")
{
    STATIC_REQUIRE(zs::int_t<>{}.value() == 0);
    STATIC_REQUIRE(zs::int_t<>{ 1 }.value() == 1);
}

TEST_CASE("scalar value access", "[scalar]")
{
    STATIC_REQUIRE(zs::int_t<>{ 1 }.value() == 1);
    STATIC_REQUIRE((const zs::int_t<>){ 1 }.value() == 1);
    STATIC_REQUIRE(zs::int_t<>{ 1 }.cvalue() == 1);
}

TEST_CASE("scalar value assignment", "[scalar]")
{
    zs::int_t<> s{ 0 };

    s.value() = 1;

    REQUIRE(s.value() == 1);
}

TEST_CASE("scalar negation", "[scalar]")
{
    STATIC_REQUIRE((-zs::int_t<>{ 1 }).value() == -1);
}

TEST_CASE("scalar comparison", "[scalar]")
{
    STATIC_REQUIRE(zs::int_t<>{ 1 } == zs::int_t<>{ 1 });
    STATIC_REQUIRE(zs::int_t<>{ 0 } != zs::int_t<>{ 1 });
    STATIC_REQUIRE(zs::int_t<>{ 0 } <  zs::int_t<>{ 1 });
    STATIC_REQUIRE(zs::int_t<>{ 1 } >  zs::int_t<>{ 0 });
    STATIC_REQUIRE(zs::int_t<>{ 0 } <= zs::int_t<>{ 1 });
    STATIC_REQUIRE(zs::int_t<>{ 1 } <= zs::int_t<>{ 1 });
    STATIC_REQUIRE(zs::int_t<>{ 1 } >= zs::int_t<>{ 0 });
    STATIC_REQUIRE(zs::int_t<>{ 1 } >= zs::int_t<>{ 1 });

    STATIC_REQUIRE_FALSE(zs::int_t<>{ 1 } == zs::int_t<>{ 0 });
    STATIC_REQUIRE_FALSE(zs::int_t<>{ 1 } != zs::int_t<>{ 1 });
    STATIC_REQUIRE_FALSE(zs::int_t<>{ 1 } <  zs::int_t<>{ 0 });
    STATIC_REQUIRE_FALSE(zs::int_t<>{ 1 } <  zs::int_t<>{ 1 });
    STATIC_REQUIRE_FALSE(zs::int_t<>{ 0 } >  zs::int_t<>{ 1 });
    STATIC_REQUIRE_FALSE(zs::int_t<>{ 1 } >  zs::int_t<>{ 1 });
    STATIC_REQUIRE_FALSE(zs::int_t<>{ 1 } <= zs::int_t<>{ 0 });
    STATIC_REQUIRE_FALSE(zs::int_t<>{ 0 } >= zs::int_t<>{ 1 });

    STATIC_REQUIRE(zs::int_t<>{ -1 } != zs::unsigned_t<>{ UINT_MAX });
    STATIC_REQUIRE(zs::int_t<>{ -1 } < zs::unsigned_t<>{ 1 });
    STATIC_REQUIRE(zs::unsigned_t<>{ 1 } > zs::int_t<>{ -1 });

    STATIC_REQUIRE_FALSE(zs::int_t<>{ -1 } == zs::unsigned_t<>{ UINT_MAX });
}
