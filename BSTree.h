//Author:Ryan Byrnes Assignment 3 c3326903
//Course: Seng1120 Data Structores
//File: BSTree.h

#include "BTNode.h"

#include <cstdlib>

#include <iostream>

template < typename T >

  class BSTree {
    public:
      //constructor
      BSTree() {
        root = NULL;
        size = 0;
      }

      //destructor
      ~BSTree() {
      	
        removeNodes(root);
    
      }
    ///////////////////////////////////////////////////////////////////////////////////////
    //Precondition: none
    //Postcondition: will return true if the root is NULL and false is it isnt

    //stastics Query Functions
    bool isEmpty() const {
      if (root == NULL) {
        return true; //returns true if its empty
      } else {
        return false; //returns false if it is not
      }
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    //Precondition: node has data
    //Postcondition: will return the size
    int size_() const {
      return size;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    //Mutator functions
    //Precondition:none
    //Postcondition:Will insert data into the node
    BTNode<T>* add(const T& data, BTNode <T>* node)
    {

      if(data < node->get_data()) //if the data in the node is less than the data
      {
        if(node->get_left()) //if the left of the node
        {
          node->set_left(add(data,node->get_left())); //set the left of the node to recursively call add(node->getLeft)
        }
        else
        {
          node->set_left(new BTNode<T>(data,node, NULL, NULL)); //else will create a new node and increase the size
          size++;
        }
      }
      if(data > node->get_data()) //if the data in the node is more than the data
      {
        if(node->get_right()) //get the right of the node
        {
          node->set_right(add(data,node->get_right())); //will set the left of the node to recursively call add(node->getRight)
        }
        else
        {
          node->set_right(new BTNode<T>(data,node, NULL, NULL)); //else will create a new node and increase the size of the tree
          size++;
        }
      }
      return node; //return the node
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    //Precondition:none
    //Postcondition:Will call the insert function if the root is not null else is will create a new node as root
    void add(const T& data) {
      if(root==NULL)
      {
        root = new BTNode<T>(data, NULL, NULL, NULL); //if the root is null, create a new node and increase the size
        size++;
        return;
      }
      else
      {
        add(data,root);
      }

    }
    ///////////////////////////////////////////////////////////////////////////////////////
     //Precondition:none
    //Postcondition:Will remove a given node if the root is not equal to 0.
    bool remove(T& data) {
    	if(root == 0)
    	{
    		return false; //will return false is root = 0 //if the root is 0 return false
    	}
    	else
    	{
    		return removeRecursive(root, data); //Recursively call the remove function to remove
    	}
    }
    ///////////////////////////////////////////////////////////////////////////////////////
     //Precondition:the remove() function was called
    //Postcondition:The recursive function for removing the node
    bool removeRecursive(BTNode<T>* current_node, T& data) 
    {
       if(current_node == NULL) //Checks to see if the current node is NULL and nothing to remove
       {
       	return false;
       }

       int relation = compare(data, current_node->get_data()); // set a new relation to compare the data

       //If you need to keep searching to the right
       if(relation > 0) //if the relation data is greater than 0
       {
       	removeRecursive(current_node->get_right(),data); //recursively call the removeRecursive() function to remove the right
       }
       else if(relation <0)//if the relation data is less than 0
       {
       	removeRecursive(current_node->get_left(), data);//recursively call the removeRecursive() function to remove the right
       }
       else
       {
       	//Case 1. Leaf
       	if(current_node->is_leaf()) //If the node is a leaf
       	{
       		//The root case!
       		if(compare(root->get_data(), data) == 0) //if the compare function returns 0 
       		{
       			root = NULL;
       		}
       		else
       		{
       			if(current_node->is_right_child()) //if the current node is right child
       			{
       				current_node->get_parent()->set_right(NULL);  //will set the current to parent and right to NULL
       			}
       			else
       			{
       				current_node->get_parent()->set_left(NULL); //will set the current to parent and left to NULL
       			}
       		}
       		//release from memory because this is important!
       		delete current_node; //delete the current node
       		size--; //decrease the size
       	}

       	//Case 2 - one child
       	else if(current_node->has_one_child()) //if the current node has one child
       	{
       		if(compare(root->get_data(), data) == 0) //if the compare function comes back with 0 for the root data and data
       		{
       			if(current_node->get_right() != NULL) //if the current right node != NULL
       			{
       				current_node->get_right()->set_parent(NULL); 
       				root = current_node->get_right(); //Will set root to the current right node
       			}
       			else
       			{
       				current_node->get_left()->set_parent(NULL); //will
       				root = current_node->get_left();
       			}
       		}
       		//       []
       		//       /\
       		//      /  \
       		//     []   ()
       		//If you are removing a node with a right child
       		else if(current_node->get_right() != NULL) //will 
       		{
       			current_node->get_right()->set_parent(current_node->get_parent()); //will set current get right node to parent and get the parent data
       			if(current_node->is_right_child()) //if the current node is a right child
       			{
       				current_node->get_parent()->set_right(current_node->get_right()); //will get the parent of the current node, set it to right.
       			}
       			else
       			{
       				current_node->get_parent()->set_left(current_node->get_right());//Will get the parent of the current node, set it to the left
       			}
       		}
       		//       []
       		//       /\
       		//      /  \
       		//     ()   []
       		//If you are removing a node with a right child
       		else //If you are removing a left child
       		{
              current_node->get_left()->set_parent(current_node->get_parent()); //Removing a right child
              if(current_node->is_right_child()) //if the current node is a right child
              {
              	current_node->get_parent()->set_right(current_node->get_left()); //we want to set the current's parent to set right, current get Left
              }
              else
              {
              	current_node->get_parent()->set_left(current_node->get_left()); //else set the left
              }
       		}
       		//release memory
       		delete current_node; //delete the current node for memory management
       		size--; //decrease the size

       	}

       	//Case 3 - Two children
       	else
       	{
       		BTNode<T>* temp_node = findMinimum(current_node->get_right()); //will create a new node by finding the minimum
       		T* temp_item = new T (temp_node->get_data()); //will create a temp node and set that with the current data

       		removeRecursive(current_node->get_right(),temp_node->get_data()); //will resurively call the remove function to remove the right of the current node and set the temp
       		current_node->set_data(*temp_item); //will set the data of the current node to the temp data
       		

       	}
       return true;
       }
       return false;
       }

    
    ///////////////////////////////////////////////////////////////////////////////////////
    //Postcondition:two objects are passed in
    //Postcondition:Will compare the data and return a number depending on the condition 
    int compare(const T& a, const T& b) const {
      if (a < b) {
        return -1;
      } else if (a == b) {
        return 0;
      } else {
        return 1;
      }
    }
    //inventory management
    //Postcondition:binary tree has data
    //Postcondition:Will recursive call the calculate parts function to calc the parts of the BSTree
    int calculateParts() {
      if (root == NULL) {
        return 0;
      } else {
        return (calculatePartsRecursive(root));
      }
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    //Postcondition:binary tree has data
    //Postcondition:Will recursive call the calculate inventory function to calc the inventory of the BSTree
    int calculateInventory() {
      return (calculateInventoryRecursive(root));
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    //o stream functions
    //Postcondition:binary tree has data
    //Postcondition:Will print out the binary tree in order
    void inOrder(BTNode < T > * node, std::ostream & out) {
      if (node != NULL) { //if node is NOT null
        inOrder(node -> get_left(), out); //recursively call the inOrder function and traverse left, print out
        out << node -> get_data() << " ";
        inOrder(node -> get_right(), out);//recursively call the inOrder function and traverse right, print out
      }
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    //Postcondition:binary tree has data
    //Postcondition:Will print out the binary tree in order
    void printInOrder() {
      inOrder(root);
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    //Postcondition:binary tree has data
    //Postcondition:Will print out the binary tree in order
    void outputHelper(std::ostream & out) {
      inOrder(root, out);
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    //Postcondition:binary tree has data
    //Postcondition:Will recursively remove all the nodes in the BSTree
    void removeNodes(BTNode <T>* node) {
        //get left data
        // if left data != NULL
        //removeNodes left
        //do same for right
      if(node==NULL)
      {
        return;
      }
      removeNodes(node -> get_left()); //recursively call to remove nodes from the left
      removeNodes(node -> get_right());//recursively call to remove nodes from the right

      delete node;
      size--;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    //private variables
    private:
    BTNode <T> * root;
    int size;
    ///////////////////////////////////////////////////////////////////////////////////////
    //private functions
    //Postcondition:binary tree has data
    //Postcondition:Will find the minimum value of the BSTree
    BTNode <T> * findMinimum(BTNode<T>* current_node) const {
      //Recursive function to find the minimum root
      //As shown in the lecture
      if (current_node -> get_left() == NULL) { //if the current node's left is NULL
        return current_node; //will return the root
      } else {
        return findMinimum(current_node->get_left()); //Recursive function
      }
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    //Postcondition:binary tree has data
    //Postcondition:Will find the Maximum value of the BSTree
    BTNode <T> * findMaximum(BTNode <T> * root) const {
      //Recursive function to find the maximum root
      //As shown in the lecture
      if (root -> get_right() == NULL) {
        return root; //will return the root
      } else {
        return findMaximum(root -> get_right()); //recursive function
      }
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    //Postcondition:binary tree has data
    //Postcondition:Will recursively call the calcParts function to calc the BSTree parts
    int calculatePartsRecursive(BTNode < T > * node) {
      int count = 0; //set count to 0
      if (node != NULL) { //if the node is not NULL
        count += 1; //count + 1
        if (node -> get_right() != NULL) { //if the right of the node is NOT null
          count += calculatePartsRecursive(node->get_right()); //increase count
        } else if (node -> get_left() != NULL) { //if the left of the node is NOT null
          count += calculatePartsRecursive(node->get_left()); //increase count
        }
      }
      return count;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    //Postcondition:binary tree has data
    //Postcondition:Will recursively call the calcInventory function to calc the BSTree inventory
    int calculateInventoryRecursive(BTNode < T > * node) {
      int count = 0; //set count the 0
      if (node == NULL) { //if the node is NULL
        return 0; //return 0
      } else {
        count = count + calculateInventoryRecursive(node -> get_left()); //recursively call the function for the left of the node and add it to count
        count = count + node -> get_data().get_quantity(); //get the data and quantity and add it to the count
        count = count + calculateInventoryRecursive(node -> get_right());//recursively call the function for the right of the node and add it to count
      }

      return count;
    }
    ///////////////////////////////////////////////////////////////////////////////////////
    //Postcondition:binary tree has data
    //Postcondition:Will find the node your looking after
    BTNode <T>* findANode(BTNode < T > * node,
      const T & found) const {
      if (found > node -> get_data()) //data > node
      {
        return findANode(node -> get_right(), found); //recursive function to move right
      } else if (found < node -> get_data()) {
        return findANode(node -> get_left(), found); //recursive function to move left
      } else {
        return node;
      }
    }
   

  };
  //Overload the o stream opoerator <<
template < typename T >
  std::ostream & operator << (std::ostream & out, BSTree < T > & tree) {
    tree.outputHelper(out);
    return out;
  }

