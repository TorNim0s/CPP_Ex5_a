#pragma once

#include <iostream>
#include <vector>
#include <string>

namespace ariel{
    struct Node{
        std::string name;
        std::vector<Node> childrens;
    };
}