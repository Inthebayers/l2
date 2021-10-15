#pragma once
#include <iostream>
#include "nodedata.h"
class BinTree { // you add class/method comments and assumptions/implementation 
    
private:
    struct Node {
        NodeData* data; // pointer to data object 
        Node* left; // left subtree pointer 
        Node* right; // right subtree pointer 
    };
    Node* root; // root of the tree 
    // utility functions 
    void inorderHelper(...) const; // recursive helper for operator<< 
    void sidewaysHelper(Node*, int) const;
    bool retrieveHelper(const NodeData&,
        NodeData*&, Node*) const; // *
    void destroyForDestructor(Node*);

public:
    BinTree(); // constructor *
    BinTree(const BinTree&); // copy constructor 
    ~BinTree(); // destructor, calls makeEmpty() 
    bool isEmpty() const; // true if tree is empty, otherwise false *
    void makeEmpty(); // make the tree empty so isEmpty returns true 
    BinTree& operator=(const BinTree&);
    bool operator==(const BinTree&) const;
    bool operator!=(const BinTree&) const;
    bool insert(NodeData*); // *
    bool retrieve(const NodeData&, NodeData*&) const; // * 
    void displaySideways() const; // displays the tree sideways
    // can create search to determine of object already exists in tree, *
    Node* search();



};