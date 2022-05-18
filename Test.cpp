#include "doctest.h"
#include <iostream>
#include <string>
#include <vector>

#include "OrgChart.hpp"

using namespace std;
using namespace ariel;

TEST_CASE("Good Tests"){
    OrgChart org;
    CHECK_NOTHROW(org.add_root("CEO"));

    CHECK_NOTHROW(org.add_sub("CEO", "VP_Tech"));
    CHECK_NOTHROW(org.add_sub("CEO", "VP_Design"));
    CHECK_NOTHROW(org.add_sub("CEO", "VP_Sales"));

    CHECK_NOTHROW(org.add_sub("VP_Tech", "Manager_Xbox"));
    CHECK_NOTHROW(org.add_sub("VP_Design", "Manager_UI_UX"));
    CHECK_NOTHROW(org.add_sub("VP_Sales", "Manager_Finance"));
    CHECK_NOTHROW(org.add_sub("VP_Sales", "Manager_Houses"));  

    string check;
    // organization order
    for (auto it = org.begin_level_order(); it != org.end_level_order(); ++it)
    {
        check += " " +(*it);
    }
    CHECK(check == " CEO VP_Tech VP_Design VP_Sales Manager_Xbox Manager_UI_UX Manager_Finance Manager_Houses");

    check = "";
    // should be the same as above
    for (auto element : org)
    { // this should work like level order
        check += " " + element;
    }
    CHECK(check == " CEO VP_Tech VP_Design VP_Sales Manager_Xbox Manager_UI_UX Manager_Finance Manager_Houses");

    check = "";
    // reverse order
    for (auto it=org.begin_preorder(); it!=org.end_preorder(); ++it) {
        check += " " +(*it);
    }
    CHECK(check == " Manager_Houses Manager_Finance Manager_UI_UX Manager_Xbox VP_Sales VP_Design VP_Tech CEO");


    check = "";
    // organization preorder 
    for (auto it=org.begin_preorder(); it!=org.end_preorder(); ++it) {
        check += " " + (*it);
    } 
    CHECK(check == " CEO VP_Tech Manager_Xbox VP_Design Manager_UI_UX VP_Sales Manager_Finance Manager_Houses");
}

TEST_CASE("BAD Cases"){
    OrgChart org;
    CHECK_NOTHROW(org.add_root("CEO"));

    CHECK_NOTHROW(org.add_sub("CEO", "VP_Tech"));
    CHECK_NOTHROW(org.add_sub("CEO", "VP_Design"));
    CHECK_NOTHROW(org.add_sub("CEO", "VP_Sales"));

    CHECK_NOTHROW(org.add_sub("VP_Tech", "Manager_Xbox"));
    CHECK_NOTHROW(org.add_sub("VP_Design", "Manager_UI_UX"));
    CHECK_NOTHROW(org.add_sub("VP_Sales", "Manager_Finance"));
    CHECK_NOTHROW(org.add_sub("VP_Sales", "Manager_Houses"));  

    CHECK_THROWS(org.add_sub("CEO", "VP_Law"));
    CHECK_THROWS(org.add_sub("VP_LAW", "CEO"));
    CHECK_THROWS(org.add_sub("ss","bb"));
}