#include <zollstock/constants/units/length.hpp>
#include <zollstock/tests/header_info.hpp>

#include <catch2/catch_all.hpp>


TEST_CASE("length-unit-constants-header", "[headers][length-units]")
{

    STATIC_REQUIRE(includes_length_unit_constants());

}
