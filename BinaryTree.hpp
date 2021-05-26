#pragma once
#include <iostream>
#include <list>
#include <ostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <streambuf>
#include <string>
using namespace std;
namespace ariel {
    enum Child { Right, Left };
    template <typename T> class BinaryTree {
    

    private:
    class Node {
    public:
        Node *right;
        Node *left;
        T data;
        Node(T data) : data(data), right(nullptr), left(nullptr) {}
        Node(Node const &node) {
        data = node.data;
        right = node.right;
        left = node.left;
        }
    };
    using Iterator =typename list<T>::iterator;
    list<T> itr;
    bool setWasChanged = true;
    Node *root;
    bool contains(T key);
    void moveN(T source, T destination, Node *father, Child child);
    void preorder(Node *node);
    void inorder(Node *node);
    void postorder(Node *node);
    void print2DUtil(Node *root, int space);

    public:
    BinaryTree<T>() : root(nullptr), itr() {}
    ~BinaryTree<T>() {}
    BinaryTree &add_root(T value);
    BinaryTree &add_left(T pos, T value);
    BinaryTree &add_right(T pos, T value);
    Iterator begin_preorder();
    Iterator end_preorder();
    Iterator begin_inorder();
    Iterator end_inorder();
    Iterator begin_postorder();
    Iterator end_postorder();
    Iterator begin();
    Iterator end();

    template <typename T1>
    friend ostream &operator<<(ostream &os, BinaryTree<T1> const &root);
    void print2D(Node *bnrtree);
    };

    template <typename T> bool BinaryTree<T>::contains(T key){return true;}

    template <typename T> void BinaryTree<T>::preorder(Node *node) {}

    template <typename T> void BinaryTree<T>::inorder(Node *node) {}

    template <typename T> void BinaryTree<T>::postorder(Node *node) {}

    template <typename T> BinaryTree<T> &BinaryTree<T>::add_root(T value) {return *this;}

    template <typename T> BinaryTree<T> &BinaryTree<T>::add_left(T pos, T value) {return *this;}

    template <typename T> BinaryTree<T> &BinaryTree<T>::add_right(T pos, T value) {return *this;}

    template <typename T>
    typename list<T>::iterator BinaryTree<T>::begin_preorder() {return itr.begin();}

    template <typename T> typename list<T>::iterator BinaryTree<T>::end_preorder() {return itr.end();}

    template <typename T>
    typename list<T>::iterator BinaryTree<T>::begin_inorder() {return itr.begin();}

    template <typename T> typename list<T>::iterator BinaryTree<T>::end_inorder() {return itr.end();}

    template <typename T>
    typename list<T>::iterator BinaryTree<T>::begin_postorder() {return itr.begin();}

    template <typename T>
    typename list<T>::iterator BinaryTree<T>::end_postorder(){return itr.end();}

    template <typename T> typename list<T>::iterator BinaryTree<T>::begin() {return itr.begin();}

    template <typename T> typename list<T>::iterator BinaryTree<T>::end() {return itr.end();}

    template <typename T>
    ostream &operator<<(ostream &os, BinaryTree<T> const &bnrtree) {
    return os;
    }
} // namespace ariel
