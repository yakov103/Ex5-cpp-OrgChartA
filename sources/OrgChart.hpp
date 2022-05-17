#pragma once 
#include <vector>
#include <string>
#include <iostream>
#include <map> 
#include <stack> 
#include <queue>
#include <stdexcept>

using namespace std; 

namespace ariel {
    enum iterator_type {
        LEVEL_ORDER,
        REVERSE_ORDER, 
        PRE_ORDER,
        END_LEVEL_ORDER,
        END_REVERSE_ORDER,
        END_PRE_ORDER
    };

    struct Node { 
        string name;
        vector<Node*> children;
    };

    class OrgChart {
        class Iterator{ 
            private : 
            vector<Node*> _collector ; 
            unsigned int _index;
            unsigned int _size; 
            void fill (iterator_type type, Node* node);
            public : 
            Iterator(iterator_type type, Node* node); 
            Iterator operator++();
            Iterator operator++(int);
            bool operator==(const Iterator& other);
            bool operator!=(const Iterator& other);
            string& operator*();
            string* operator->();
            
        };

        Node* _root;
        OrgChart::Iterator *testIter;
        public :
        OrgChart();
        ~OrgChart();

        
        OrgChart& operator= (const OrgChart& other);
        OrgChart& add_root(const string& name);
        OrgChart& add_sub(string parent,string child);
        bool check_parent(string parent, string child , Node *node);

        OrgChart::Iterator begin() const;
        OrgChart::Iterator end() const;
        OrgChart::Iterator begin_level_order() const;
        OrgChart::Iterator begin_reverse_order() const;
        OrgChart::Iterator begin_preorder() const;
        OrgChart::Iterator end_level_order() const;
        OrgChart::Iterator reverse_order() const ; 
        OrgChart::Iterator end_preorder() const;

        friend ostream& operator<<(ostream& os, const OrgChart& org);



    };
};