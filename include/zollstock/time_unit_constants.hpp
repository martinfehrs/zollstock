#ifndef __ZOLLSTOCK_TIME_UNIT_CONSTANTS_HPP__
#define __ZOLLSTOCK_TIME_UNIT_CONSTANTS_HPP__


#include <zollstock/unit_concept.hpp>
#include <zollstock/si_prefixes.hpp>
#include <zollstock/definition_helpers.hpp>


namespace zollstock::inline units::inline constants
{

    ZOLLSTOCK_DEFINE_BASE_SI_UNIT_CONSTANTS(dimensions::T, s)

    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(dimensions::T, min,         60.0L)
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(dimensions::T, h  ,      3'600.0L)
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(dimensions::T, d  ,     86'400.0L)
    ZOLLSTOCK_DEFINE_BASE_UNIT_CONSTANT(dimensions::T, a  , 31'536'000.0L)

}


#endif //__ZOLLSTOCK_TIME_UNIT_CONSTANTS_HPP__
