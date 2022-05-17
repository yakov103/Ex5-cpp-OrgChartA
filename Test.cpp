#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "OrgChart.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Good case ")
{
 
     OrgChart org;
  
        CHECK_NOTHROW(org.add_root("root"));
        CHECK_NOTHROW(org.add_sub("root", "child1"));
        CHECK_NOTHROW(org.add_sub("child1", "grandchild1"));
        CHECK_NOTHROW(org.add_sub("grandchild1", "greatgrandchild1"));
        CHECK_NOTHROW(org.add_sub("root", "child2"));
        CHECK_NOTHROW(org.add_sub("child2", "grandchild2"));
        CHECK_NOTHROW(org.add_sub("grandchild2", "greatgrandchild2"));
        CHECK_NOTHROW(org.add_sub("root", "child3"));
        CHECK_NOTHROW(org.add_sub("child3", "grandchild3"));
        CHECK_NOTHROW(org.add_sub("grandchild3", "greatgrandchild3"));
        CHECK_NOTHROW(org.add_sub("root", "child4"));
        CHECK_NOTHROW(org.add_sub("child4", "grandchild4"));
        CHECK_NOTHROW(org.add_sub("grandchild4", "greatgrandchild4"));
        string token; 
        string forchild;  


        OrgChart organization;
        CHECK_NOTHROW(organization.add_root("CEO")); // add root
        CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));          // Now the CTO is subordinate to the CEO
        CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));         // Now the CFO is subordinate to the CEO
        CHECK_NOTHROW(organization.add_sub("CEO", "COO"));        // Now the COO is subordinate to the CEO
        CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW")); // Now the VP Software is subordinate to the CTO
        CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));      // Now the VP_BI is subordinate to the COO

        cout << organization << endl; /* Prints the org chart in a reasonable format. For example:
       CEO
       |--------|--------|
       CTO      CFO      COO
       |                 |
       VP_SW             VP_BI
 */
    token.clear(); 
  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){token += *it + " " ;}
  
  CHECK (token == "CEO CTO CFO COO VP_SW VP_BI " );
  token.clear();
  for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it){token += *it + " " ;}
    CHECK (token == "VP_SW VP_BI CTO CFO COO CEO " );
    token.clear();
  for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {token += *it + " " ;}
    CHECK (token == "CEO CTO VP_SW CFO COO VP_BI " );
    token.clear();

  // demonstrate the arrow operator:
  for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
  {
    cout << it->size() << " " ;
  } 
        

        //  level order 
        // int i = 0 ; 
        // for (auto it = org.begin_level_order(); it != org.end_level_order(); it++) {
        //     if (i == 0 ){
        //         CHECK (*it == "root");
        //         i++;
        //         continue;
        //     }
        //     if (i <= 4){
        //     token = *it;
        //     forchild = "child"; 
        //     forchild += to_string(i);
        //     CHECK(token == forchild);
        //     printf("%s\n", token.c_str());
        //     i++;
        //     continue;
        //     }
        //     if (5 <= i && i < 8){
        //     token = *it;
        //     forchild = "grandchild"; 
        //     forchild += to_string(i%4);
        //     printf("%s\n", token.c_str());
        //     CHECK(token == forchild);
        //     i++; 
        //     continue;
        //     }
        //     if (9 <= i && i < 12){
        //     token = *it;
        //     forchild = "greatgrandchild";
        //     forchild += to_string(i%4+1);
        //     CHECK(token == forchild);
        //     i++; 
        //     continue;
        //     }
        

        
    }
     
    // check revese order

TEST_CASE("Bad cases"){

    OrgChart org; 
    CHECK_THROWS(org.add_sub("root", "child")); // still no root 
    CHECK_NOTHROW(org.add_root("root"));
    CHECK_NOTHROW(org.add_sub("root", "child"));
    CHECK_NOTHROW(org.add_sub("child", "grandchild"));
    CHECK_NOTHROW(org.add_sub("grandchild", "greatgrandchild"));
    CHECK_THROWS(org.add_sub("whatt", "cannot"));// no such parent
    CHECK_THROWS(org.add_sub("bishbash", "child")); // no such parent

}