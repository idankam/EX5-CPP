//
// Created by Eitan Kats on 17/05/2022.
//

#include "doctest.h"
#include "sources/OrgChart.hpp"
#include "iostream"
#include <sstream>

using namespace ariel;

TEST_CASE ("Basic Orgchart functionality check") {
            CHECK_NOTHROW(OrgChart
                                  chart);
    OrgChart charti;
            CHECK_NOTHROW(charti.add_root("Kendrick"));
            CHECK_NOTHROW(
            charti.add_sub("Kendrick", "Yeled")
                    .add_sub("Yeled", "Shalom")
                    .add_sub("Kendrick", "Lodrick"));
            CHECK_NOTHROW(charti.add_root("rak python"));

    OrgChart chartizard;

            SUBCASE("adding sub when node doesn't exist") {
                CHECK_THROWS(chartizard.add_sub("testy", "testy2"));
    }

            SUBCASE("creating regular iterator when there is no head") {
        auto iterStart = chartizard.begin();
                CHECK(iterStart == chartizard.end());

    }
            SUBCASE("creating reverse order with no head") {
        auto iterStart = chartizard.begin_reverse_order();
                CHECK(iterStart == chartizard.end_reverse_order());
    }

            SUBCASE("creating pre order with no head") {
        auto iterStart = chartizard.begin_preorder();
                CHECK(iterStart == chartizard.end_preorder());
    }
}

TEST_CASE ("Basic Iterator tests") {
    OrgChart chart;
            CHECK_NOTHROW(chart.add_root("test"));

            SUBCASE("basic iterator creation") {

        auto iterStart = chart.begin();
                CHECK_NOTHROW(*iterStart);
                CHECK_NOTHROW(iterStart++);
                CHECK(iterStart == chart.end());
    }

            SUBCASE("level_order Iterator creation") {
        auto iterStart = chart.begin_level_order();
                CHECK_NOTHROW(*iterStart);
                CHECK_NOTHROW(++iterStart);
                CHECK(iterStart == chart.end_level_order());
    }
            SUBCASE("Preorder Iterator creation") {
        auto iterStart = chart.begin_preorder();
                CHECK_NOTHROW(*iterStart);
                CHECK_NOTHROW(++iterStart);
                CHECK(iterStart == chart.end_preorder());
    }

            SUBCASE("reverse order Iterator creation") {
        auto iterStart = chart.begin_reverse_order();
                CHECK_NOTHROW(*iterStart);
                CHECK_NOTHROW(++iterStart);
                CHECK(iterStart == chart.end_reverse_order());
    }

}

TEST_CASE ("complex iterator tests") {
    OrgChart chartush;
    chartush.add_root("1");
    chartush.add_sub("1", "2")
            .add_sub("1", "6")
            .add_sub("1", "7")
            .add_sub("2", "3")
            .add_sub("2", "5")
            .add_sub("3", "4");
            SUBCASE("pre order") {
        std::string ans = "1234567";
        std::stringstream buffer;
        for (auto element = chartush.begin_preorder(); element != chartush.end_preorder(); ++element) {
            buffer << (*element);
        }
                CHECK(buffer.str() == ans);
    }

            SUBCASE("level order") {
        std::string ans = "1267354";
        std::stringstream buffer;
        for (auto element = chartush.begin_level_order(); element != chartush.end_level_order(); ++element) {
            buffer << (*element);
        }
                CHECK(buffer.str() == ans);
    }

            SUBCASE("reverse order") {
        std::string ans = "4352671";
        std::stringstream buffer;
        for (auto element = chartush.begin_reverse_order(); element != chartush.end_reverse_order(); ++element) {
            buffer << (*element);
        }
                CHECK(buffer.str() == ans);
    }

}