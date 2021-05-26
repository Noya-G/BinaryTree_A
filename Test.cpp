#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <time.h> 
using namespace std;

#include "BinaryTree.hpp"
using namespace ariel;
#define SEED_1 10 //you can redifne the seeds.
#define SEED_2 10
#define SEED_3 10

//genarator random string
string random_string(int seed1, int seed2)
{
    int string_size=rand()%3;
    string str;
    for (int i = 0; i < string_size; i++)
    {
        str+=(char)((rand()%93) +1);
    }
    
    return str;
}


TEST_CASE("Basic Test initilizing the Tree") {
    
    //basic tree of ints:
    BinaryTree<int> tree_a;
    CHECK_NOTHROW(tree_a.add_root(1));
    CHECK_NOTHROW(tree_a.add_left(1, 9));
    CHECK_NOTHROW(tree_a.add_left(9, 4));
    CHECK_NOTHROW(tree_a.add_right(9, 5));
    CHECK_NOTHROW(tree_a.add_right(1, 3));
    CHECK_NOTHROW(tree_a.add_left(1, 2));
    
    //tree of ints:
    srand(SEED_1);
    BinaryTree<int> tree_b;
    for (int i = 0; i < 9; i++)
    {
        int child1 = rand()%100;
        int child2 = rand()%100;
        CHECK_THROWS(tree_b.add_left(child1,child2));
        CHECK_THROWS(tree_b.add_right(child1,child2));
    }
    
    
    int father1 = rand()%100;
    int father2 = father1;
    tree_b.add_root(father1);
    for (int i = 0; i < 5; i++)
    {
        int child1 = rand()%100;
        int child2 = rand()%100;
        CHECK_NOTHROW(tree_b.add_left(father1,child1));
        CHECK_NOTHROW(tree_b.add_right(father2,child2));
        father1 = child1;
        father2 = child2;
    }
    
    //tree of strings:
    BinaryTree<string> tree_c;
    srand(SEED_1);
    
    for (int i = 0; i < 5; i++)
    {
        string random_string1 = random_string(SEED_2,SEED_3);
        string random_string2 = random_string(SEED_2,SEED_3);
        CHECK_THROWS(tree_c.add_left(random_string2,random_string2));
        CHECK_THROWS(tree_c.add_right(random_string1,random_string2));
    }

    string father1_s = random_string(SEED_2,SEED_3);
    string father2_s = random_string(SEED_2,SEED_3);
        
    for (int i = 0; i < 10; i++)
    {
        string child1 = random_string(SEED_2,SEED_3);
        string child2 = random_string(SEED_2,SEED_3);
        CHECK_NOTHROW(tree_c.add_left(father1_s,child1));
        CHECK_NOTHROW(tree_c.add_right(father2_s,child2));
        father1_s = random_string(SEED_2,SEED_3);
        father2_s = random_string(SEED_2,SEED_3);
    }
}



 TEST_CASE("Preorder Test") {
 
     }

TEST_CASE("root Test + iterator -begin()") {

}

