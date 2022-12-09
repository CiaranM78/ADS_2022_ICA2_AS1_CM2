#pragma once
#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/BinaryTree.h"
#include "../ADS_CA2_Tree/StudentKey.h"
#include "../ADS_CA2_Tree/Student.h"
//#include "../ADS_CA2_Tree/TNode.h"
//#include "../ADS_CA2_Tree/BSTNode.h"
#include "../ADS_CA2_Tree/Util.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ADSCA2UnitTests
{
	TEST_CLASS(ADSCA2UnitTests)
	{
	public:
		/*
			This test ensures a node is created at the root when
			an element is added to an empty binary tree
		*/




		TEST_METHOD(TestAddToEmptyTree)
		{
			TNode<StudentKey, Student> tree;
			StudentKey key1("j1234", "smith", "code123");
			Student std1("j1234", "billybob", "john");
			tree.add(key1, std1);

			Assert::IsNotNull(tree.root);
			Student s = tree.root->getData();

			string id = "j1234";
			Assert::AreEqual(s.getuser_id(), id);
		}


		TEST_METHOD(TestAddToEmptyTreefail)
		{
			TNode<StudentKey, Student> tree;
			StudentKey key1("j1234", "smith", "code123");
			Student std1("j1234", "billybob", "john");
			tree.add(key1, std1);

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
			
			TNode<StudentKey, Student> tree;
			StudentKey key1("j1234", "smith", "code123");
			StudentKey key2("4321jf", "momma", "code69");
			StudentKey key4("j123g", "smitfg", "cod");
			Student std1("j1234", "billybob", "john");
			Student std2("jfadsf", "bisdfadb", "jofdasfan");
			Student std3("jfadadsfaf", "bisdfdsfdfasdfadfdb", "jofdasfan");
			tree.add(key1, std1);
			tree.add(key2, std2);
			//tree.add(key4, std3);
			Student rootnode = tree.root->getData();
			Assert::IsNotNull(tree.root);
			string id1 = "j1234";
			string id2 = "jfadsf";
			Assert::AreEqual(rootnode.getuser_id(), id1);
			TNode<StudentKey,Student>* left = tree.root->getLeft();

			Student x = left->getData();
			
			
			Assert::IsNotNull(left);
			TNode<StudentKey, Student>* right = tree.root->getRight();
			//Assert::IsNotNull(right);
			
			Assert::AreEqual(x.getuser_id(), id2);
			
		
			//Assert::AreEqual(key2, left->getData());
			
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
			TNode<StudentKey, Student> tree;
			StudentKey key1("j1234", "smith", "code123");
			StudentKey key2("j123g", "smitfg", "cod");
			Student std1("j1234", "billybob", "john");
			Student std2("jfadadsfaf", "bisdfdsfdfasdfadfdb", "jofdasfan");
			tree.add(key1, std1);
			tree.add(key2, std2);
			Student rootnode = tree.root->getData();
			Assert::IsNotNull(tree.root);
			string id1 = "j1234";
			string id2 = "jfadadsfaf";
			Assert::AreEqual(rootnode.getuser_id(), id1);
			TNode<StudentKey, Student>* right = tree.root->getRight();
			Assert::IsNotNull(right);
			Student x = right->getData();
			Assert::AreEqual(x.getuser_id(), id2);
		}

		/*
		Test the count function for empty tree
		*/

		TEST_METHOD(TestCountOnEmpty)
		{
			TNode<StudentKey, Student> tree;
			Assert::AreEqual(0, tree.count());
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
			TNode<StudentKey, Student> tree;
			StudentKey key1("j1234", "smith", "code123");
			StudentKey key2("4321jf", "momma", "code69");
			StudentKey key3("j123g", "smitfg", "cod");
			Student std1("j1234", "billybob", "john");
			Student std2("jfadsf", "bisdfadb", "jofdasfan");
			Student std3("jfadadsfaf", "bisdfdsfdfasdfadfdb", "jofdasfan");
			tree.add(key1, std1);
			tree.add(key2, std2);
			tree.add(key3, std3);


			Assert::AreEqual(3, tree.count());

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
			//might be issues with this
			// key4 not getting deleted properly

			TNode<StudentKey, Student> tree;
			StudentKey key1("j1234", "smith", "code123");
			StudentKey key2("4321jf", "momma", "code69");
			StudentKey key3("j123g", "smitfg", "cod");
			StudentKey key4("faskdfa", "sfdasf", "cfdasf");
			Student std1("j1234", "billybob", "john");
			Student std2("jfadsf", "bisdfadb", "jofdasfan");
			Student std3("jfadadsfaf22222", "bisdfdsfdfasdfadfdb", "jofdasfan");
			Student std4("jfadadsfaf6", "bisdfdsfdfasdfadfdb", "jofdasfan");
			tree.add(key1, std1);
			tree.add(key2, std2);
			tree.add(key3, std3);
			Assert::AreEqual(3, tree.count());
			tree.remove(key4);
			Assert::AreEqual(3, tree.count());

			

			//testing if root doesn't get deleted had issues with this
			Student rootnode = tree.root->getData();
			Assert::IsNotNull(tree.root);
			string id1 = "j1234";
			Assert::AreEqual(rootnode.getuser_id(), id1);
			//test check data in the right node
			string idRight = "jfadadsfaf22222";
			TNode<StudentKey, Student>* right = tree.root->getRight();
			Student r = right->getData();
			Assert::AreEqual(r.getuser_id(), idRight);
			//test check data in the left node
			string idLeft = "jfadsf";
			TNode<StudentKey, Student>* left = tree.root->getLeft();
			Student l = left->getData();
			Assert::AreEqual(l.getuser_id(), idLeft);
			




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
			TNode<StudentKey, Student> tree;
			StudentKey key1("WBC88XPE6LP", "Burks", "6723 EV");
			StudentKey key2("RDS11RXM7WY", "Morse", "08450");
			StudentKey key5("FNO15QZA3TB", "Francis", "14719");
			StudentKey key3("j1", "smfg", "cd");
			StudentKey key4("fdfa", "sfsf", "casf");
			Student std1("j1234", "billybob", "john");
			Student std2("jfadsf", "bisdfadb", "jofdasfan");
			Student std3("jfad", "bisdfdsfdfb", "jon");
			Student std4("jfadaf6", "bisdfdsadfdb", "joan");
			Student std5("FNO15QZA3TB", "bisdfdssdfadfdb", "sfan");
			tree.add(key1, std1);
			tree.add(key2, std2);
			tree.add(key3, std3);
			tree.add(key4, std4);
			tree.add(key5, std5);
			Assert::AreEqual(5, tree.count());
		    tree.remove(key5);
			Assert::AreEqual(4, tree.count());
			/*Assert::AreEqual(4, tree.count());
			tree.remove(key4);
			Assert::AreEqual(3, tree.count());*/



			//testing if root doesn't get deleted had issues with this
			//Student rootnode = tree.root->getData();
			Assert::IsNotNull(tree.root);
			//string id1 = "j1234";
			//Assert::AreEqual(rootnode.getuser_id(), id1);
			////test check data in the right node
			//string idRight = "jfadadsfaf22222";
			TNode<StudentKey, Student>* right = tree.root->getRight();
			Assert::IsNull(right->getLeft());


			//Student r = right->getLeft()->getData();
			//string rightleftleafid = "FNO15QZA3TB5";
		    //Assert::AreEqual(r.getuser_id(), rightleftleafid);



			//Assert::AreEqual(r.getuser_id(), idRight);
			////test check data in the left node
			//string idLeft = "jfadsf";
			//TNode<StudentKey, Student>* left = tree.root->getLeft();
			//Student l = left->getData();
			//Assert::AreEqual(l.getuser_id(), idLeft);

			/*
		Test the remove function to try and remove a leaf node
		to test this we will use the following tree
		 key1
		/   \
		2    Key2
	   / \   / \
	   1 3 Key3  7



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
		}
		TEST_METHOD(TestRemoveNodeWithOneChild)
		{
			TNode<StudentKey, Student> tree;
			StudentKey key1("WBC88XPE6LP", "Burks", "6723 EV");
			StudentKey key2("RDS11RXM7WY", "Morse", "08450");
			StudentKey key5("FNO15QZA3TB", "Francis", "14719");
			StudentKey key6("TEE62QJX2SJ", "Mccarty", "165810");
			StudentKey key7("KMW31DFX1GN", "Newman", "4266");
			Student std1("j1234", "billybob", "john");
			Student std2("jfadsf", "bisdfadb", "jofdasfan");
			Student std5("FNO15QZA3TB", "bisdfdssdfadfdb", "sfan");
			Student std6("TEE62QJX2SJ", "bisdfdssdfadfdb", "sfan");
			Student std7("KMW31DFX1GN", "bisdfdssdfadfdb", "sfan");
			tree.add(key1, std1);
			tree.add(key2, std2);
			tree.add(key5, std5);
			tree.add(key6, std6);
			tree.add(key7, std7);
			tree.remove(key6);
			Assert::IsNotNull(tree.root);
			TNode<StudentKey, Student>* right = tree.root->getRight();
			Assert::IsNull(right->getRight()->getRight());
			Student rightmostleaf = right->getRight()->getData();
			string rightmostnode = "KMW31DFX1GN";
			Assert::AreEqual(rightmostleaf.getuser_id(), rightmostnode);
			

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
			TNode<StudentKey, Student> tree;
			

			StudentKey key1("FNO15QZA3TB", "Burks", "6723 EV");
			StudentKey key2("NJB82NEB7RA", "Ortega", "03854");
			StudentKey key3("LGF12DCE4WF", "Rose", "686404");
			StudentKey key4("RDS11RXM7WY", "Morse", "08450");
			

			Student std1("FNO15QZA3TB", "Burks", "6723 EV");
			Student std2("NJB82NEB7RA", "Ortega", "03854");
			Student std3("LGF12DCE4WF", "Rose", "686404");
			Student std4("KDS98KUM7KI", "Boone", "83147");
			





			tree.add(key1, std1);
			tree.add(key2, std2);
			tree.add(key3, std3);
			tree.add(key4, std4);
			Assert::AreEqual(4, tree.count());
			tree.remove(key2);
			Assert::AreEqual(3, tree.count());
			Student rootnode = tree.root->getData();
			string rootid = "FNO15QZA3TB";
			Assert::AreEqual(rootnode.getuser_id(),rootid);
			TNode<StudentKey, Student>* left = tree.root->getLeft();
			Student l = left->getData();
			string leftid = "KDS98KUM7KI";
			Assert::AreEqual(leftid,l.getuser_id());
			Student ll = left->getLeft()->getData();
			string leftleftid = "LGF12DCE4WF";
			Assert::AreEqual(leftleftid, ll.getuser_id());
			Assert::IsNull(left->getRight());
			
			
		}


		TEST_METHOD(TestRemoveNodeWithTwoChildrenfail)
		{
			TNode<StudentKey, Student> tree;


			StudentKey key1("FNO15QZA3TB", "Burks", "6723 EV");
			StudentKey key2("NJB82NEB7RA", "Ortega", "03854");
			StudentKey key3("LGF12DCE4WF", "Rose", "686404");
			StudentKey key4("RDS11RXM7WY", "Morse", "08450");


			Student std1("FNO15QZA3TB", "Burks", "6723 EV");
			Student std2("NJB82NEB7RA", "Ortega", "03854");
			Student std3("LGF12DCE4WF", "Rose", "686404");
			Student std4("KDS98KUM7KI", "Boone", "83147");






			tree.add(key1, std1);
			tree.add(key2, std2);
			tree.add(key3, std3);
			tree.add(key4, std4);
			Assert::AreEqual(4, tree.count());
			//tree.remove(key2);
			Assert::AreEqual(4, tree.count());
			Student rootnode = tree.root->getData();
			string rootid = "FNO15QZA3TB";
			Assert::AreEqual(rootnode.getuser_id(), rootid);
			TNode<StudentKey, Student>* left = tree.root->getLeft();
			Student l = left->getData();
			string leftid = "NJB82NEB7RA";
			Assert::AreEqual(leftid, l.getuser_id());
			Student ll = left->getLeft()->getData();
			string leftleftid = "LGF12DCE4WF";
			Assert::AreEqual(leftleftid, ll.getuser_id());
			Assert::IsNull(left->getRight());


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

		TEST_METHOD(SearchForKeyAfterInsertedpass)
		{
			TNode<StudentKey, Student> tree;
			StudentKey key1("j1234", "smith", "code123");
			StudentKey key2("j114", "sm5", "code143");
			Student std1("j1234", "billybob", "john");
			Student std2("j123415441", "bill151", "jo1515612");
			tree.add(key1, std1);
			tree.add(key2, std2);

		
			Assert::IsTrue(tree.search(key2));
		}

		TEST_METHOD(SearchForKeyAfterInsertedfail)
		{
			TNode<StudentKey, Student> tree;
			StudentKey key1("j1234", "smith", "code123");
			StudentKey key2("j114", "sm5", "code143");
			Student std1("j1234", "billybob", "john");
			Student std2("j123415441", "bill151", "jo1515612");
			tree.add(key1, std1);
			//tree.add(key2, std2);

		
			Assert::IsTrue(tree.search(key2));
			

		}














	};



}
