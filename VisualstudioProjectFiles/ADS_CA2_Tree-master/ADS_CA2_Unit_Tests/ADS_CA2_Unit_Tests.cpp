#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/BinaryTree.h"
#include "../ADS_CA2_Tree/StudentKey.h"
#include "../ADS_CA2_Tree/Student.h"
//#include "../ADS_CA2_Tree/TNode.h"
//#include "../ADS_CA2_Tree/BSTNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ADSCA2UnitTests
{
	TEST_CLASS(ADSCA2UnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}

		/*
			This test ensures a node is created at the root when
			an element is added to an empty binary tree
		*/

		TEST_METHOD(TestAddToEmptyTree)
		{
			BinaryTree<StudentKey, Student> tree;
			StudentKey key("j1234", "smith", "code123");
			Student std("j1234", "billybob", "john");
			tree.add(key, std);

			Assert::IsNotNull(tree.root);
			Student s = tree.root->getData();

			string id = "j1234";
			Assert::AreEqual(s.getuser_id(), id);
		}


		TEST_METHOD(TestAddToEmptyTreefail)
		{
			BinaryTree<StudentKey, Student> tree;
			StudentKey key("j1234", "smith", "code123");
			Student std("j1234", "billybob", "john");
			tree.add(key, std);

			Assert::IsNotNull(tree.root);
			Student s = tree.root->getData();

			string id = "j4321";
			Assert::AreEqual(s.getuser_id(), id);
		}

		/*
		This test ensures a node is created on the left branch
		when value is less than root.
		*/



		TEST_METHOD(TestAddToRootLeft)
		{
			
			BinaryTree<StudentKey, Student> tree;
			StudentKey key("j1234", "smith", "code123");
			StudentKey key2("", "momma", "code69");
			Student std("j1234", "billybob", "john", "j1234", "billybob", "john", "j1234", "billybob", "john", "j1234", "billybob", "john", "j1234", "billybob", "john");
			Student std1("jfadsf", "bisdfadb", "jofdasfan", "j1dfasdfa4", "billafsdfa", "jfasdf", "j1234", "billybob", "john", "j1234", "billybob", "john", "j1234", "billybob", "john");
			tree.add(key, std);
			tree.add(key2, std1);
			Student s = tree.root->getData();
			Assert::IsNotNull(tree.root);
			string id = "j4321";
			Assert::AreEqual(s.getuser_id(), id);
			


			//Assert::IsNotNull(left);
			//Assert::AreEqual(1, left->getItem());







			//left = tree.root->getLeft();
			///////////////////////



			//Assert::AreEqual(2, tree.root->getData());

			//Assert::IsNotNull(left);
			//Assert::AreEqual(1, left->getItem());








			/*BinaryTree<StudentKey, Student > tree;
			StudentKey key("R7284", "robinson", "code575");
			tree.add(0);
			tree.add(3);
			tree.add(8);
			BSTNode <string>* left = tree.root->getLeft();
			Assert::IsNotNull(tree.root);
			 BSTNode <string>* left = tree.root->getLeft();
			Assert::IsNotNull(left);
			Assert::AreEqual(left->add(key, data), left->getItem(0));
			Assert::AreEqual(left->add(key, data), left->getItem(3));
			Assert::AreEqual(left->add(key, data), left->getItem(8));*/
		}
		/*
		This test ensures a node is created on the right branch
		when value is less than root.
		*/
		TEST_METHOD(TestAddToRootRight)
		{
			/*BinaryTree<StudentKey, Student > tree;
			StudentKey key("R6734", "marco", "code117");
			tree.add(0);
			tree.add(3);
			tree.add(8);
			BSTNode <string>* right = tree.root->getRight();
			Assert::IsNotNull(tree.root);
			BSTNode <string>* right = tree.root->getRight();
			Assert::IsNotNull(right);
			Assert::AreEqual(right->add(key, data), right->getItem(0));
			Assert::AreEqual(right->add(key, data), right->getItem(3));
			Assert::AreEqual(right->add(key, data), right->getItem(8));*/
		}

		/*
		Test the count function for empty tree
		*/

		TEST_METHOD(TestCountOnEmpty)
		{
			/*BinaryTree<string> tree;
			Assert::AreEqual(nullptr, tree.count(nullptr));*/
		}
		/*
		Test the count function for full tree
		to test this we will use the following tree
		   4
		  / \
		 2   6
		/ \ / \
		1 3 5  7
		*/

		TEST_METHOD(TestCountOnFullTree)
		{
			/*BinaryTree<int> tree;
			StudentKey key("R1114", "jaskson", "code234" );
			BSTNode <string>* right = tree.root->getRight();
			BSTNode <string>* left = tree.root->getLeft();
			Assert::AreEqual( , tree.count());*/
		}

		/*
		Test the remove function to try and remove an item not found
		to test this we will use the following tree
		   4
		  / \
		 2   6
		/ \ / \
		1 3 5  7
		*/

		TEST_METHOD(TestRemoveItemNotPresent)
		{
			/*BinaryTree<string> tree;
			tree.add(0);
			tree.add(1);
			tree.add(2);
			tree.add(3);
			tree.add(4);
			tree.add(5);
			tree.add(6);
			tree.add(7);
			tree.add(8);
			tree.add(9);
			tree.add(10);
			tree.add(11);
			tree.add(12);
			tree.add(13);
			tree.add(14);
			Assert::AreEqual(14, tree.count());
			Assert::IsNotNull(tree.root);
			Assert::IsNotNull(left);
			Assert::IsNotNull(right);
			tree.remove(8);
			Assert::AreEqual(0, tree.root->getItem());
			Assert::AreEqual(1, tree.root->getLeft()->getItem());
			Assert::AreEqual(2, tree.root->getRight()->getItem());
			Assert::AreEqual(3, tree.root->getLeft()->getItem());
			Assert::AreEqual(4, tree.root->getRight()->getItem());
			Assert::AreEqual(5, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			Assert::AreEqual(7, tree.root->getLeft()->getItem());
			BSTNode<string>* left = tree.root->getLeft();
			BSTNode<string>* right = tree.root->getRight();
			Assert::AreEqual(8, left->getLeft()->getItem());
			Assert::AreEqual(9, right->getRight()->getItem());
			Assert::AreEqual(10, left->getLeft()->getItem());
			Assert::AreEqual(11, right->getRight()->getItem());
			Assert::AreEqual(12, left->getLeft()->getItem());
			Assert::AreEqual(13, right->getRight()->getItem());
			Assert::AreEqual(14, left->getLeft()->getItem());*/
		}

		/*
		Test the remove function to try and remove a leaf node
		to test this we will use the following tree
		 4
		/ \
		2   6
	   / \ / \
	   1 3 5  7
		*/

		TEST_METHOD(TestRemoveLeafNode)
		{
			/*BinaryTree<int> tree;
			tree.add(0);
			tree.add(1);
			tree.add(2);
			tree.add(3);
			tree.add(4);
			tree.add(5);
			tree.add(6);
			tree.add(7);
			tree.add(8);
			tree.add(9);
			tree.add(10);
			tree.add(11);
			tree.add(12);
			tree.add(13);
			tree.add(14);
			Assert::AreEqual(7, tree.count());
			Assert::IsNotNull(tree.root);
			Assert::IsNotNull(left);
			Assert::IsNotNull(right);
			tree.remove(14);
			Assert::AreEqual(0, tree.root->getItem());
			Assert::AreEqual(1, tree.root->getLeft()->getItem());
			Assert::AreEqual(2, tree.root->getRight()->getItem());
			Assert::AreEqual(3, tree.root->getLeft()->getItem());
			Assert::AreEqual(4, tree.root->getRight()->getItem());
			Assert::AreEqual(5, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			Assert::AreEqual(7, tree.root->getLeft()->getItem());
			BSTNode<int>* left = tree.root->getLeft();
			BSTNode<int>* right = tree.root->getRight();
			Assert::AreEqual(8, left->getLeft()->getItem());
			Assert::AreEqual(9, right->getRight()->getItem());
			Assert::AreEqual(10, left->getLeft()->getItem());
			Assert::AreEqual(11, right->getRight()->getItem());
			Assert::AreEqual(12, left->getLeft()->getItem());
			Assert::AreEqual(13, right->getRight()->getItem());
			Assert::IsNull(right->getLeft());
			Assert::AreEqual(13, right->getRight()->getItem());*/
		}

		/*
		Test the remove function to try and remove a node with one child to the right
		to test this we will use the following tree
		  4
		 / \
		 2   6
		/ \ / \
		1   5  7
				\
				 8
		*/

		TEST_METHOD(TestRemoveNodeWithOneChild)
		{
			/*BinaryTree<int> tree;
			tree.add(4);
			tree.add(2);
			tree.add(6);
			tree.add(1);
			tree.add(5);
			tree.add(7);
			tree.add(8);
			Assert::AreEqual(7, tree.count());
			tree.remove(7);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(2, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			BSTNode<int>* left = tree.root->getLeft();
			BSTNode<int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(8, right->getRight()->getItem());*/
		}
		/*
		Test the remove function to try and remove a leaf node
		to test this we will use the following tree
		 4
		/ \
		2   6
		/ \ / \
		1 3 5  7
		*/

		TEST_METHOD(TestRemoveNodeWithTwoChildren)
		{
			/*BinaryTree<int> tree;
			tree.add(4);
			tree.add(2);
			tree.add(6);
			tree.add(1);
			tree.add(3);
			tree.add(5);
			tree.add(7);
			Assert::AreEqual(7, tree.count());
			tree.remove(2);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(3, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			BSTNode<int>* left = tree.root->getLeft();
			BSTNode<int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::IsNull(left->getRight());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(7, right->getRight()->getItem());*/
		}

		/*
		Test the remove function to try and a node with multiple children
		to test this we will use the following tree:

				   8
				/    \
			   /      \
			  /        \
			 4          12
			/ \        /   \
		   2   6      10   14
		  / \ / \    / \  / \
		 1  3 5  7  9  11 13 15

				  8
				/    \
			   /      \
			  /        \
			 4          12
			/ \        /   \
		   2   6      10   14
		  / \ / \    / \    \
		 1  3 5  7  9  11    15

		 When we remove a node in the middle of the tree, the algorithm
		 should move the next lowest item up to the place of the removed node.
		 In this case 13 will be moved up to the place of 12
		*/

		TEST_METHOD(TestRemoveNodeWithMultipleChildren)
		{
			/*BinaryTree<int> tree;
			tree.add(8);
			tree.add(4);
			tree.add(12);
			tree.add(2);
			tree.add(6);
			tree.add(1);
			tree.add(3);
			tree.add(5);
			tree.add(7);
			tree.add(10);
			tree.add(14);
			tree.add(9);
			tree.add(11);
			tree.add(13);
			tree.add(15);
			Assert::AreEqual(15, tree.count());

			Assert::IsNotNull(tree.root->getRight()->getRight()->getLeft());
			Assert::AreEqual(13, tree.root->getRight()->getRight()->getLeft()->getItem());
			tree.remove(12);
			Assert::AreEqual(14, tree.count());
			Assert::AreEqual(13, tree.root->getRight()->getItem());
			Assert::IsNull(tree.root->getRight()->getRight()->getLeft());*/
		}


















	};



}
