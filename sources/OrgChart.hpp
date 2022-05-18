#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Node.hpp"

namespace ariel{
    class OrgChart{
        private:
            Node root;

        public:
            OrgChart();
            OrgChart &add_root(std::string name);
            OrgChart &add_sub(std::string first, std::string second);

            std::string* begin_level_order();
            std::string* end_level_order();

            std::string* begin_reverse_order();
            std::string* end_reverse_order();
            std::string* reverse_order();

            std::string* begin_preorder();
            std::string* end_preorder();

            friend std::ostream &operator<<(std::ostream &out, OrgChart &root){
                out << "test";
                return out;
            }

            std::string* begin(){
                return &this->root.name;
            }
            std::string* end(){
                return &this->root.name;
            }

    };
}