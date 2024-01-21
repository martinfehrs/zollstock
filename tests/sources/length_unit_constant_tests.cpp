#include <catch2/catch_all.hpp>
#include <zollstock/length_unit_constants.hpp>
#include <zollstock/unit_algorithms.hpp>
#include <zollstock/tests/test_helpers.hpp>


using namespace zollstock;


TEST_CASE("length-unit-constants", "[length][unit][constants]")
{

    ZOLLSTOCK_TESTS_TEST_SI_BASE_UNIT_CONSTANTS(meter, m)


}
