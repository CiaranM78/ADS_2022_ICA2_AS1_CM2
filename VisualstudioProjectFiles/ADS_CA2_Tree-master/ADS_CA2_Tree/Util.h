#pragma once

//#include "BinaryTree.h"

/*
recursive function to display a binary tree
*/
template <typename T, typename V>
void printBT(const std::string& prefix, TNode<T, V>* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "<--" : ">--");

		// print the value of the node
		std::cout <<"(" << node->getKey().hash() << ")" << node->getData()->getuser_id() << std::endl;

		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? "|   " : "    "), node->getLeft(), true);
		printBT(prefix + (isLeft ? "|   " : "    "), node->getRight(), false);
	}
}
/*
Display function to print the tree
*/
template <class T, class V>
void printBT(TNode<T, V>* node)
{
	printBT("", node, true);
}




/*
Recursive Function to add each element when balancing a binary tree
*/





