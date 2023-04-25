//Author:Ryan Byrnes
//Course: Seng1120 Data Structores
//File: BSTree.hpp
//Implementation for Binary Search Tree


#include "BTNode.h"
#include <cstdlib>
#include <iostream>

// template <typename T>
// BSTree<T>::BSTree()
// {
// 	root = NULL;
// }

template <typename T>
BSTree<T>::BSTree()
{
	root = NULL;
	size = 0;
}

template <typename T>
BSTree<T>::~BSTree()
{
	removeNode(root);
}

template <typename T>
bool BSTree<T>::isEmpty() const
{
	if(root == NULL)
	{
		return true; //returns true if its empty
	}
	else
	{
		return false; //returns false if it is not
	}
}
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
int BSTree<T>::size_() const
{
     return size;
}
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void BSTree<T>::insert(T data, BTNode<T>* node)
{
	// if (root == NULL)
	// {
	// 	root = new BTNode<T>(data); CLEARLY NOT BLOODY WORKING
	// }
	// else
	// {
	// 	add(data, root);
	// }
	// size++;
	BTNode<T>* nodeT;
	//If the node data is greater than the get_data it will set
	//it to the right node
	if(data>node->get_data())
	{
       if(node->get_right() != NULL) //check to see if the right node is equal to NULL
       {
       	 //If so return the NULL
       }
       else if(node->get_right() == NULL) //check to see if the right node is equal to NU::
       {
         nodeT = new BTNode<T>(data);
         node->set_right(nodeT);
         size++;
       }
       else
       {
       	insert(data, node->get_right()); //Recursely call the insert function to insert a node with data and the right node.
       }
	
	//If the node data is less than the get)data it will set
	//it to the right node
	else
	{
      if(node->get_left() != NULL)
      {
        //Do nothing!
      }
      else if(node->get_left() == NULL)
      {
      	nodeT = new BTNode<T>(data);
      	node->set_left(nodeT);
      	size++
      }
      else
      {
      	insert(data, node->get_left());
      }
	}
}

}
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void BSTree<T>::add(T data)
{
	cout << "HELLO ARE U THERE" << endl;
   if (&data == node->get_data())
   {
   	node->set_data(data);
   }
   else if (&data > node->get_data())
   {
   	if (node->get_right() == NULL)             CLEARLY WASNT BLOODY WORKING
   	{
   		node->set_right(new BTNode<T>(data));
   	}
   	else
   	{
   		add(data, node->get_right());
   	}
   }
	//Will insert if the node is not NULL else it will add a new node
   if(root != NULL)
   {
   	insert(data, root);
   }
   else
   {
   	root = new BTNode<T>(data);
   }

}
///////////////////////////////////////////////////////////////////////////////////////
// template <typename T>
// bool BSTree<T>::remove(T& data)
// {
// 	 BTNode<T>* rootNode = root;
// 	 rootNode = remove(data, rootNode);
// }
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool BSTree<T>::remove(T data)
{
  	cout << "HELLO ARE U THERE" << endl;
 if(data == root->get_data())
 {
 	BTNode<T> tempRoot; //Will create a temp root node
 	tempRoot.set_left(root); //will set the left node to the temp
    
 	BTNode<T>* current = root->removeNodes(data, &tempRoot);
 	root = tempRoot.get_left();
 	if(current == NULL)
 	{
        return false;
 	}
 	else
 	{
 		delete current;
 		return true;
 	}
 	

 }
 else
 {
 	BTNode<T>* current = root->removeNodes(data, NULL);
 	if(current == NULL)
 	{
 		return false;
 	}
 	else
 	{
 		delete current;
 		return true;
 	}
 }
// 	// //case 1: If the node is a leaf
//  //    if(node->get_right() == NULL && node->get_left() == NULL)
//  //    {
//  //      root = NULL;
//  //    }
//  //    //Jeremy ando's github holds the key
//  //    //in his BSTree.hpp file in remove function


	// if(root == NULL)
	// {
	// 	return root;
	// }
	// else if(data < root->data)
	// {
 //      root->left = remove(data,root->left);
	// }
	// else if(data > root->data)
	// {
	// 	root->right = remove(data,root->right);
	// }
	// else //will go through the cases and delete based on the conditional statement
	// {
	// 	//This case is if it has no child
 //       if(root->left == NULL && root->right == NULL) //if it has no children :(
 //       {
 //           delete root;
 //           root = NULL;
 //           return root;
 //       }
 //       //The one child case
 //       else if (root->left == NULL) //if it has one child to the right
 //       {
 //       	BTNode<T>* tempNode = root; //store current node to a temp node
 //       	root = root->right; //move the root to the right child
 //       	delete tempNode; //delete tempnode
 //       	return root; //return the root
 //       }
 //       else if(root->right == NULL) //if the right child is null
 //       {
 //         BTNode<T>* tempNode = root; //store the current node to a temp node
 //         root = root->left; //move the root to the left child
 //         delete tempNode; //delete tempnode
 //         return root; //return the root
 //       }
 //       //The 2 children case
 //       else
 //       {
 //       	  //Im calling the findMin function and collecting the return in a pointer to a node named tempNode
 //       	  BTNode<T>* tempNode = findMin(root->right); //searches the min element in right subtree of the node we are trying to delete
 //       	  root->data = tempNode->data; //set the data in current node that im trying to delete as the min value
 //       	  root->right = remove(root->right,tempNode->data); //deleting the min value
 //       	  return root; //returns the root
 //       }
	// }
    
} 
///////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void BSTree<T>::removeNode(BTNode<T>* node)
{
	//Recursive function to remove the nodes from a binary search tree
	//Will recursively call removeNode for both left and right directions for the tree
	//This function will work with the deconstructor to remove the nodes.

		if(node->get_left() != NULL)
		{
			removeNode(node->get_left()); //Will remove the node to the left
			remove(node->get_left()->get_data()); //Will remove the data within the node
		}
		else if(node->get_right() != NULL)
		{
			removeNode(node->get_right()); //Will remove the node to the right
			remove(node->get_right()->get_data()); //Will remove the data within the node
		}
		delete root; //Makes sure to delete root for best practice
		size--; //decrease the size of the nodes

	
    // if(node != NULL)
    // {
    // 	removeNodes(node->get_left());
    // 	removeNodes(node->get_right());                  THIS FUNCTION WAS NOT REMOVING THE DATA AND JUST REMOVING THE NODE.
    // 	delete node; //make sure to delete the node as it is good practice!
    // 	size--; //decrease the size of the tree each time a node is removed.
    // }
}
			
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
BTNode<T>* BSTree<T>::findANode(BTNode<T>* node, const T& found) const
{
	if(found > node->get_data()) //data > node
	{
		return findANode(node->get_right(), found); //recursive function to move right
	}
	else if (found < node->get_data())
	{
		return findANode(node->get_left(), found); //recursive function to move left
	}
	else
	{
		return node;
	}
}
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void BSTree<T>::inOrder(BTNode<T>* node, std::ostream& out)
{
	if(node != NULL)
	{
	    inOrder(node->get_left(), out);
	    out << node->get_data() << " ";
	    inOrder(node->get_right(), out);	
	}
}

///////////////////////////////////////////////////////////////////////////////////////
// template <typename T>
// void BSTree<T>::printInOrder()
// {
// 	inOrder(root);
// }
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
void BSTree<T>::outputHelper(std::ostream& out)
{
	inOrder(root, out);
}
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
std::ostream& operator << (std::ostream& out, BSTree<T>& tree)
{
	tree.outputHelper(out);
	return out;
}
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
int BSTree<T>::calculatePartsRecursive(BTNode<T>* node)
{
	int count;
	if(node == NULL)
	{
		return 0;
	}
	else
	{
		count = count + 1;
		if(node->get_right() !=NULL)
		{
			count = count + calculatePartsRecursive(node->get_right());
		}
		else if(node->get_left() != NULL)
		{
			count = count + calculatePartsRecursive(node->get_right());
		}
	}
     if(root != NULL)
     {
     	return (calculatePartsRecursive(this->root)); 
     }
	//return count;
}
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
int BSTree<T>::calculateParts()
{
	return (calculatePartsRecursive(this->root));
}
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
int BSTree<T>::calculateInventoryRecursive(BTNode<T>* node)
{
	int count = 0;
	if(node==NULL)
	{
		return 0;
	}
	else
	{
		count = count + calculateInventoryRecursive(node->get_left());
		count = count + node->get_data().get_quantity();
		count = count + calculateInventoryRecursive(node->get_right());
	}

   return count;
}
template <typename T>
int BSTree<T>::calculateInventory()
{
	return (calculateInventoryRecursive(this->root));
}
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
BTNode<T>* BSTree<T>::findMinimum(BTNode<T>* root) const
{
	//Recursive function to find the minimum root
	//As shown in the lecture
	if(root->get_left() == NULL)
	{
		return root; //will return the root
	}
	else
	{
		return findMinimum(root->get_left()); //Recursive function
	}
}
///////////////////////////////////////////////////////////////////////////////////////
template <typename T>
BTNode<T>* BSTree<T>::findMaximum(BTNode<T>* root) const
{
	//Recursive function to find the maximum root
	//As shown in the lecture
	if(root->get_right() == NULL)
	{
		return root; //will return the root
	}
	else
	{
		return findMaximum(root->get_right()); //recursive function
	}
}
///////////////////////////////////////////////////////////////////////////////////////
