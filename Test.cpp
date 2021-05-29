#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <time.h> 
#include <array>
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


    //////////////////////////////////////////////////
    //tree 0:
        BinaryTree<int> tree;
        CHECK_NOTHROW(tree.add_root(0));
        int print_ [1]={1};
        CHECK_EQ(print_[0],*tree.begin_preorder());
        CHECK_EQ(print_[0],*tree.end_preorder());
    //////////////////////////////////////////////////

    //////////////////////////////////////////////////
    //tree 0:
        BinaryTree<int> tree_0;
        CHECK_NOTHROW(tree_0.add_root(0));
        CHECK_NOTHROW(tree_0.add_left(0, 1));
        CHECK_NOTHROW(tree_0.add_right(0, 2));
        int print_0[3] = {1,0,2};
        CHECK_EQ(print_0[0],*tree_0.begin_preorder());
        CHECK_EQ(print_0[2],*tree_0.end_preorder());
        int j=0;
        for (auto i = tree_0.begin_preorder(); i != tree_0.end_preorder(); ++i)
        {   
            CHECK(print_0[j]==*i);
            j++;
        }
    //////////////////////////////////////////////////

    //////////////////////////////////////////////////
    //tree 1:
        BinaryTree<int> tree_1;
        CHECK_NOTHROW(tree_1.add_root(0));
        CHECK_NOTHROW(tree_1.add_left(0, 1));
        CHECK_NOTHROW(tree_1.add_left(1, 2));
        int print_1[3] = {2,1,0};
        CHECK_EQ(print_1[0],*tree_1.begin_preorder());
        CHECK_EQ(print_1[2],*tree_1.end_preorder());
        j = 0;
        for (auto i = tree_1.begin_preorder(); i != tree_1.end_preorder(); ++i)
        {
            CHECK_EQ(print_1[j],*i);
            j++;
        }
    //////////////////////////////////////////////////

    //////////////////////////////////////////////////
    //tree 2:
        BinaryTree<int> tree_2;
        CHECK_NOTHROW(tree_2.add_root(0));
        CHECK_NOTHROW(tree_2.add_right(0, 1));
        CHECK_NOTHROW(tree_2.add_right(0, 2));
        int print_2[3] = {0,2,1};
        CHECK_EQ(print_2[0],*tree_2.begin_preorder());
        CHECK_EQ(print_2[2],*tree_2.end_preorder());
        j = 0;
        for (auto i = tree_2.begin_preorder(); i != tree_2.end_preorder(); ++i)
        {
            CHECK_EQ(print_2[j],*i);
            j++;
        }
    //////////////////////////////////////////////////

    //////////////////////////////////////////////////
    //tree 3:
        BinaryTree<int> tree_3;
        CHECK_NOTHROW(tree_3.add_root(1));
        CHECK_NOTHROW(tree_3.add_left(1, 2));
        CHECK_NOTHROW(tree_3.add_right(1, 8));
        CHECK_NOTHROW(tree_3.add_left(2, 3));
        CHECK_NOTHROW(tree_3.add_right(2, 4));
        CHECK_NOTHROW(tree_3.add_left(3, 5));
        CHECK_NOTHROW(tree_3.add_right(3, 6));
        CHECK_NOTHROW(tree_3.add_left(3, 7));
        CHECK_NOTHROW(tree_3.add_left(8, 9));
        CHECK_NOTHROW(tree_3.add_left(9, 10));
        CHECK_NOTHROW(tree_3.add_right(9, 11));
        CHECK_NOTHROW(tree_3.add_left(11, 12));
        int print_3[12] = {5,3,6,2,4,7,10,9,12,11,8};
        CHECK_EQ(print_3[0],*tree_3.begin_preorder());
        CHECK_EQ(print_3[11],*tree_3.end_preorder());
        j=0;
        for (auto i = tree_3.begin_preorder(); i != tree_3.end_preorder(); ++i)
        {
            CHECK_EQ(print_3[j],*i);
            j++;
        }
    ////////////////////////////////////////////////

}

TEST_CASE("Inorder Test") {


    //////////////////////////////////////////////////
    //tree 0:
        BinaryTree<int> tree;
        CHECK_NOTHROW(tree.add_root(0));
        int print_[1] = {1};
        CHECK_EQ(print_[0],*tree.begin_inorder());
        CHECK_EQ(print_[0],*tree.end_inorder());
    //////////////////////////////////////////////////

    //////////////////////////////////////////////////
    //tree 0:
        BinaryTree<int> tree_0;
        CHECK_NOTHROW(tree_0.add_root(0));
        CHECK_NOTHROW(tree_0.add_left(0, 1));
        CHECK_NOTHROW(tree_0.add_right(0, 2));
        int print_0[3] = {1,0,2};
        CHECK_EQ(print_0[0],*tree_0.begin_inorder());
        CHECK_EQ(print_0[2],*tree_0.end_inorder());
        int j=0;
        for (auto i = tree_0.begin_inorder(); i != tree_0.end_inorder(); ++i)
        {
            CHECK_EQ(print_0[j],*i);
            j++;
        }
    //////////////////////////////////////////////////

    //////////////////////////////////////////////////
    //tree 1:
        BinaryTree<int> tree_1;
        CHECK_NOTHROW(tree_1.add_root(0));
        CHECK_NOTHROW(tree_1.add_left(0, 1));
        CHECK_NOTHROW(tree_1.add_left(1, 2));
        int print_1[3] = {2,1,0};
        CHECK_EQ(print_1[0],*tree_1.begin_inorder());
        CHECK_EQ(print_1[2],*tree_1.end_inorder());
        j = 0;
        for (auto i = tree_1.begin_inorder(); i != tree_1.end_inorder(); ++i)
        {
            CHECK_EQ(print_1[j],*i);
            j++;
        }
    //////////////////////////////////////////////////

    //////////////////////////////////////////////////
    //tree 2:
        BinaryTree<int> tree_2;
        CHECK_NOTHROW(tree_2.add_root(0));
        CHECK_NOTHROW(tree_2.add_right(0, 1));
        CHECK_NOTHROW(tree_2.add_right(0, 2));
        int print_2[3] = {0,2,1};
        CHECK_EQ(print_2[0],*tree_2.begin_inorder());
        CHECK_EQ(print_2[2],*tree_2.end_inorder());
        j = 0;
        for (auto i = tree_2.begin_inorder(); i != tree_2.end_inorder(); ++i)
        {
            CHECK_EQ(print_2[j],*i);
            j++;
        }
    //////////////////////////////////////////////////

    //////////////////////////////////////////////////
    //tree 3:
        BinaryTree<int> tree_3;
        CHECK_NOTHROW(tree_3.add_root(1));
        CHECK_NOTHROW(tree_3.add_left(1, 2));
        CHECK_NOTHROW(tree_3.add_right(1, 8));
        CHECK_NOTHROW(tree_3.add_left(2, 3));
        CHECK_NOTHROW(tree_3.add_right(2, 4));
        CHECK_NOTHROW(tree_3.add_left(3, 5));
        CHECK_NOTHROW(tree_3.add_right(3, 6));
        CHECK_NOTHROW(tree_3.add_left(3, 7));
        CHECK_NOTHROW(tree_3.add_left(8, 9));
        CHECK_NOTHROW(tree_3.add_left(9, 10));
        CHECK_NOTHROW(tree_3.add_right(9, 11));
        CHECK_NOTHROW(tree_3.add_left(11, 12));
        int print_3[12] = {5,3,6,2,4,7,10,9,12,11,8};
        CHECK_EQ(print_3[0],*tree_3.begin_inorder());
        CHECK_EQ(print_3[11],*tree_3.end_inorder());
        j=0;
        for (auto i = tree_3.begin_inorder(); i != tree_3.end_inorder(); ++i)
        {
            CHECK_EQ(print_3[j],*i);
            j++;
        }
    //////////////////////////////////////////////////

}

TEST_CASE("Postorder Test") {


    //////////////////////////////////////////////////
    //tree 0:
        BinaryTree<int> tree;
        CHECK_NOTHROW(tree.add_root(0));
        int print_[1] = {1};
        CHECK_EQ(print_[0],*tree.begin_postorder());
        CHECK_EQ(print_[0],*tree.end_postorder());
    //////////////////////////////////////////////////

    //////////////////////////////////////////////////
    //tree 0:
        BinaryTree<int> tree_0;
        CHECK_NOTHROW(tree_0.add_root(0));
        CHECK_NOTHROW(tree_0.add_left(0, 1));
        CHECK_NOTHROW(tree_0.add_right(0, 2));
        int print_0[3] = {1,0,2};
        CHECK_EQ(print_0[0],*tree_0.begin_postorder());
        CHECK_EQ(print_0[2],*tree_0.end_postorder());
        int j=0;
        for (auto i = tree_0.begin_postorder(); i != tree_0.end_postorder(); ++i)
        {
            CHECK_EQ(print_0[j],*i);
            j++;
        }
    //////////////////////////////////////////////////

    //////////////////////////////////////////////////
    //tree 1:
        BinaryTree<int> tree_1;
        CHECK_NOTHROW(tree_1.add_root(0));
        CHECK_NOTHROW(tree_1.add_left(0, 1));
        CHECK_NOTHROW(tree_1.add_left(1, 2));
        int print_1[3] = {2,1,0};
        CHECK_EQ(print_1[0],*tree_1.begin_postorder());
        CHECK_EQ(print_1[2],*tree_1.end_postorder());
        j = 0;
        for (auto i = tree_1.begin_postorder(); i != tree_1.end_postorder(); ++i)
        {
            CHECK_EQ(print_1[j],*i);
            j++;
        }
    //////////////////////////////////////////////////

    //////////////////////////////////////////////////
    //tree 2:
        BinaryTree<int> tree_2;
        CHECK_NOTHROW(tree_2.add_root(0));
        CHECK_NOTHROW(tree_2.add_right(0, 1));
        CHECK_NOTHROW(tree_2.add_right(0, 2));
        int print_2[3] = {0,2,1};
        CHECK_EQ(print_2[0],*tree_2.begin_postorder());
        CHECK_EQ(print_2[2],*tree_2.end_postorder());
        j = 0;
        for (auto i = tree_2.begin_postorder(); i != tree_2.end_postorder(); ++i)
        {
            CHECK_EQ(print_2[j],*i);
            j++;
        }
    //////////////////////////////////////////////////

    //////////////////////////////////////////////////
    //tree 3:
        BinaryTree<int> tree_3;
        CHECK_NOTHROW(tree_0.add_root(1));
        CHECK_NOTHROW(tree_0.add_left(1, 2));
        CHECK_NOTHROW(tree_0.add_right(1, 8));
        CHECK_NOTHROW(tree_0.add_left(2, 3));
        CHECK_NOTHROW(tree_0.add_right(2, 4));
        CHECK_NOTHROW(tree_0.add_left(3, 5));
        CHECK_NOTHROW(tree_0.add_right(3, 6));
        CHECK_NOTHROW(tree_0.add_left(3, 7));
        CHECK_NOTHROW(tree_0.add_left(8, 9));
        CHECK_NOTHROW(tree_0.add_left(9, 10));
        CHECK_NOTHROW(tree_0.add_right(9, 11));
        CHECK_NOTHROW(tree_0.add_left(11, 12));
        int print_3[12] = {5,3,6,2,4,7,10,9,12,11,8};
        CHECK_EQ(print_3[0],*tree_3.begin_postorder());
        CHECK_EQ(print_3[11],*tree_3.end_postorder());
        j=0;
        for (auto i = tree_0.begin_postorder(); i != tree_0.end_postorder(); ++i)
        {
            CHECK_EQ(print_3[j],*i);
            j++;
        }
    //////////////////////////////////////////////////

}
