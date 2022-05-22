/**
 * Demo file for the exercise on iterators
 *
 * @author Tal Zichlinsky
 * @since 2022-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "OrgChart.hpp"
using namespace ariel;

int main() {
    OrgChart org;
    OrgChart org_empty;
    OrgChart org_double_names;
    /* create normal tree */
    org.add_root("adi");
    org.add_root("shir");
    org.add_sub("shir", "tal");
    org.add_sub("shir", "sapir");
    org.add_sub("sapir", "dan");
    org.add_sub("dan", "ziv");
    org.add_sub("tal", "avi");
    org.add_sub("tal", "yossi");
    org.add_sub("shir", "ido");
    org.add_sub("ziv", "shaked");
    org.add_sub("ziv", "ofer");

  cout << "----------------------------" << endl;
        cout << org << endl; 
        cout << "----------------------------" << endl;
        /*check reverse level order with normal tree*/
        std::vector<std::string> v = {"shaked", "ofer", "ziv", "avi", "yossi", "dan", "tal", "sapir", "ido", "shir"};
        size_t i = 0;
        for(auto it = org.begin_reverse_order(); it != org.reverse_order(); ++it){
            cout << *it << "  ";
        }
        cout << endl;


//   OrgChart organization;
//   organization.add_root("CEO")
//       .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
//       .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
//       .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
//       .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
//       .add_sub("COO", "VP_BI");      // Now the VP_BI is subordinate to the COO

//    cout << organization << endl; /* Prints the org chart in a reasonable format. For example:
// //        CEO
// //        |--------|--------|
// //        CTO      CFO      COO
// //        |                 |
// //        VP_SW             VP_BI
// //  */

//   for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//   {
//     cout << (*it) << " " ;
//   } // prints: CEO CTO CFO COO VP_Smake
  
//   for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
//   {
//     cout << (*it) << " " ;
//   }
//    // prints: VP_SW VP_BI CTO CFO COO CEO
//   for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
//     cout << (*it) << " " ;
//   }  // prints: CEO CTO VP_SW CFO COO VP_BI

//   for (auto element : organization)
//   { // this should work like level order
//     cout << element << " " ;
//   } // prints: CEO CTO CFO COO VP_SW VP_BI

//   // demonstrate the arrow operator:
//   for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
//   {
//     cout << it->size() << " " ;
//   } // prints: 3 3 3 3 5 5

  
}