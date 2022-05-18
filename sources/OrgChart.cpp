#include "OrgChart.hpp"

using namespace std;

namespace ariel{
    OrgChart::OrgChart(){}

    OrgChart& OrgChart::add_root(const std::string name){
        // Node temp;
        // temp.name = name;
        // if(this->root != NULL){
        //     temp.childrens.push_back(this->root);
        // }
        // this->root = temp;

        return *this;
        
    }
    OrgChart& OrgChart::add_sub(const std::string first, const std::string second){
        // add second to first. second son of first
        return *this;
    }

    string* OrgChart::begin_level_order(){
        return &this->root.name;
    }
    string* OrgChart::end_level_order(){
        return &this->root.name;
    }

    string* OrgChart::begin_reverse_order(){
        return &this->root.name;
    }
    string* OrgChart::end_reverse_order(){
        return &this->root.name;
    }
    string* OrgChart::reverse_order(){
        return &this->root.name;
    }

    string* OrgChart::begin_preorder(){
        return &this->root.name;
    }
    string* OrgChart::end_preorder(){
        return &this->root.name;
    }

}