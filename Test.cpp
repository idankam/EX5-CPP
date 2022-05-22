#include "doctest.h"
#include "sources/OrgChart.hpp"
#include <iostream>
#include <sstream>

using namespace std;
using namespace ariel;

TEST_CASE("Basic chart check")
{
        CHECK_NOTHROW(OrgChart chart1);
        OrgChart chart2;
        CHECK_NOTHROW(chart2.add_root("11"));
        CHECK_NOTHROW(
            chart2.add_sub("11", "22")
                .add_sub("22", "33")
                .add_sub("11", "44"));
        CHECK_NOTHROW(chart2.add_root("55"));

        OrgChart chart3;

        SUBCASE("add sub obj when node is not found")
        {
                CHECK_THROWS(chart3.add_sub("11", "22"));
        }

        SUBCASE("iterator when there is no head")
        {
                auto start = chart3.begin();
                CHECK(start == chart3.end());

                auto start2 = chart3.begin_reverse_order();
                CHECK(start2 == chart3.end_reverse_order());

                auto start3 = chart3.begin_preorder();
                CHECK(start3 == chart3.end_preorder());
        }
}

TEST_CASE("Basic Iterator check")
{
        OrgChart chart;
        CHECK_NOTHROW(chart.add_root("11"));

        SUBCASE("iterator creation")
        {

                auto start = chart.begin();
                auto end = chart.end();
                CHECK_NOTHROW(*start);
                CHECK_NOTHROW(start++);
                CHECK(start == end);

                auto start2 = chart.begin_level_order();
                auto end2 = chart.end_level_order();
                CHECK_NOTHROW(*start2);
                CHECK_NOTHROW(++start2);
                CHECK(start2 == end2);

                auto start3 = chart.begin_preorder();
                auto end3 = chart.end_preorder();
                CHECK_NOTHROW(*start3);
                CHECK_NOTHROW(++start3);
                CHECK(start3 == end3);

                auto start4 = chart.begin_reverse_order();
                auto end4 = chart.end_reverse_order();
                CHECK_NOTHROW(*start4);
                CHECK_NOTHROW(++start4);
                CHECK(start4 == end4);
        }
}

TEST_CASE("not basix iterator check")
{
        OrgChart chart;
        chart.add_root("11");
        chart.add_sub("11", "22")
            .add_sub("11", "66")
            .add_sub("11", "77")
            .add_sub("22", "33")
            .add_sub("22", "55")
            .add_sub("33", "44");

        SUBCASE("Level")
        {
                string result = "11 22 66 77 33 55 44 ";
                stringstream streamBuf;
                for (auto obj = chart.begin_level_order(); obj != chart.end_level_order(); ++obj)
                {
                        streamBuf << (*obj);
                }
                CHECK(streamBuf.str() == result);
        }
        
        SUBCASE("PreOrder")
        {
                string result = "11 22 33 44 55 66 77 ";
                stringstream streamBuf;
                for (auto obj = chart.begin_preorder(); obj != chart.end_preorder(); ++obj)
                {
                        streamBuf << (*obj);
                }
                CHECK(streamBuf.str() == result);
        }

        SUBCASE("Reverse")
        {
                string result = "44 33 55 22 66 77 11 ";
                stringstream streamBuf;
                for (auto obj = chart.begin_reverse_order(); obj != chart.end_reverse_order(); ++obj)
                {
                        streamBuf << (*obj);
                }
                CHECK(streamBuf.str() == result);
        }
}