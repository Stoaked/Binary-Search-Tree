//Author:Ryan Byrnes Assignment 3 c3326903
//Course: Seng1120 Data Structores
//File: BTNode.h

#ifndef RYAN_NODE_H
#define RYAN_NODE_H

#include <cstdlib>
#include <iostream>

using namespace std;

template <typename T>
class BTNode
{
public:
	 //Precondition: none
    //Postcondition: Will construct the BTNodes with NULL data
	BTNode()
	{
		parent = NULL;
		left = NULL;
		right = NULL;
	}
    //Precondition: none
    //Postcondition: Will construct the BTNodes with appropriate data
	BTNode(const T& initialData, BTNode* initialParent, BTNode* initialLeft, BTNode* initialRight)
	{
		data = initialData;
		parent = initialParent;
		left = initialLeft;
		right = initialRight;
	}
    //Precondition: none
    //Postcondition: Will destruct the BTNodes
	~BTNode()
	{
		left = NULL;
		right = NULL;
		parent = NULL;
	}

    //mutators
     //Precondition: none
    //Postcondition: will set the data
	void set_data(const T& newData)        { data = newData; } //this will set the data of the node
	 //Precondition: none
    //Postcondition: will set the parent
    void set_parent(BTNode<T>* newParent)   { parent = newParent; }
     //Precondition: none
    //Postcondition: will set the left node
    void set_left(BTNode<T>* newLeft)        { left = newLeft; }
    //Precondition: none
    //Postcondition: will set the right node
    void set_right(BTNode<T>* newRight)      { right = newRight; }
     

    //Will return true if the node is a leaf of the tree or has one child/right child
     //Precondition: none
    //Postcondition: will return if the node is a leaf
    bool is_leaf() const            {return (left == NULL) && (right == NULL);}
     //Precondition: none
    //Postcondition: will return if the node has one child
    bool has_one_child() const      {return ((left == NULL) && (right != NULL)) || ((left != NULL) && (right == NULL)); }
    //Precondition: none
    //Postcondition: will return if the node is a right child
    bool is_right_child() const     {return data > parent->get_data();}
    

    //Query
    //Precondition: none
    //Postcondition: will return the minimum node
    T findMin()                {return left->findMin();}
    //Precondition: none
    //Postcondition: will return the data in the node
    T& get_data()              { return data; }
     //Precondition: none
    //Postcondition: will return the parent of the node
    BTNode* get_parent()       { return parent; }
     //Precondition: none
    //Postcondition: will return the right of the node
    BTNode* get_right()         { return right; }
    //Precondition: none
    //Postcondition: will return the left of the node
    BTNode* get_left()          { return left; }

//Private members variables
private:
	T data;
	BTNode* left;
	BTNode* right;
	BTNode* parent;
};

#endif