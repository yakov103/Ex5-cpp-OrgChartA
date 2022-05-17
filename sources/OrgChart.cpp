#include "OrgChart.hpp"

namespace ariel {  


    /* OrgChart Implementation */ 

    /*
    *constractor 
    */
    OrgChart::OrgChart() {
        _root = nullptr;
        testIter = nullptr;
    }
    /*  
    * destructor 
    */

    OrgChart::~OrgChart() {
        delete _root;
    }


    OrgChart& OrgChart::operator= (const OrgChart& other) {
        if (this != &other) {
            delete _root;
            _root = other._root;
        }
        return *this;
    }

    /* 
    * add root , if the root is not null just change the name 
    * else create a new root 
    */
    OrgChart& OrgChart::add_root(const string& name) {
        if (_root != nullptr) {
            _root->name = name;
            return *this;
        }
        _root = new Node;
        _root->name = name;
        return *this;
    }

    bool OrgChart::check_parent(string parent, string child, Node *node)
    {
        if (node->name.compare(parent) == 0)
        {
            Node *new_sub = new Node;
            new_sub->name = child;
            node->children.push_back(new_sub);
            return true;
        }
        for (unsigned int i = 0; i < node->children.size(); i++)
        {
            //printf("%s\n", node->children[i]->name.c_str());
            if (check_parent(parent, child, node->children.at(i)))
            {
                return true;
            }
        }

        return false;
    }



    OrgChart& OrgChart::add_sub(string parent, string child) {
        if (_root == nullptr) {
            throw "no root";
        }
        if (!check_parent(parent, child, _root))
        {
            throw std::invalid_argument("parent not found");
        }
        return *this; 
    }



    OrgChart::Iterator OrgChart::begin_level_order() const {
        return OrgChart::Iterator(LEVEL_ORDER, _root);
    }
    OrgChart::Iterator OrgChart::begin_reverse_order() const {
        
        return Iterator(REVERSE_ORDER, _root);
    }
    OrgChart::Iterator OrgChart::begin_preorder() const {
        return Iterator(PRE_ORDER, _root);
    }
    OrgChart::Iterator OrgChart::end_level_order() const {
        return Iterator(LEVEL_ORDER, _root);
    }
    OrgChart::Iterator OrgChart::reverse_order() const {
        return Iterator(REVERSE_ORDER, nullptr);
    }
    OrgChart::Iterator OrgChart::end_preorder() const {
        return Iterator(PRE_ORDER, nullptr);
    }

    OrgChart::Iterator OrgChart::begin() const {
        return begin_level_order();
    }
    OrgChart::Iterator OrgChart::end() const {
        return end_level_order();
    }

    ostream& operator<<(ostream& os, const OrgChart& org) {
        int i = 0 ;
        for (auto it = org.begin(); it != org.end() && i < 7 ; ++it) {
            os << *it << " ";
            i++; 
        }
        return os;
    }





    /* implementation of the iterator */


    OrgChart::Iterator::Iterator(iterator_type type, Node* node) {
        // int flag = 0 ; 
        // if (type == END_LEVEL_ORDER){ 
        //     flag = 1; 
        //     type = LEVEL_ORDER;
        // }
        // this->_size = 0 ;
        // this->_index = 0; 
        // _collector.clear(); 
        _index = 0;  
        _collector.push_back(node);
        fill(type, node);
        _collector.push_back(nullptr); 
    
        } 
    

    OrgChart::Iterator OrgChart::Iterator::operator++() {
        this->_index++;
        printf("\n%d in the ++++ \n", _index);
        return *this;
    }
    

    OrgChart::Iterator OrgChart::Iterator::operator++(int) {
        Iterator temp = *this;
        ++_index;
        return temp;
    }

    bool OrgChart::Iterator::operator==(const Iterator& other) {
        return _collector.at(_index) == other._collector.at(_index);
    }

    bool OrgChart::Iterator::operator!=(const Iterator& other) {
        return _collector.at(_index) != other._collector.at(_index);
    }

    string & OrgChart::Iterator::operator*() {
        return _collector.at(_index)->name;
    }

    string* OrgChart::Iterator::operator->() {
        return &_collector.at(_index)->name;
    }


    void OrgChart::Iterator::fill(iterator_type type, Node* node) {
        unsigned int i = 0 ; // index for loops . 
        if (node == nullptr || node->children.size() == 0) {
            return;
        }
        if (type == LEVEL_ORDER) {
            
            for (i = 0 ; i < node->children.size() ; i++) {
                _collector.push_back(node->children.at(i));
            } 
            for (i = 0 ; i < node->children.size() ; i++) {
                fill(type, node->children.at(i));
            }
            // printf("\n");
            // for (auto it = _collector.begin() ; it != _collector.end() ; ++it) {
            //   printf("%s  ", (*it)->name.c_str());
            // }
            // printf("\n");
        }
        else if (type == REVERSE_ORDER) {
        }
        else if (type == PRE_ORDER) {
        }
    }







}