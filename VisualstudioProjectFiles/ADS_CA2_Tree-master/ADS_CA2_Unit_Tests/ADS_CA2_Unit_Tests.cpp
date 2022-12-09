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
			// adding in a student row with it's key
			TNode<StudentKey, Student> tree;
			StudentKey key1("WBC88XPE6LP", "Burks", "6723 EV");

			Student std1("WBC88XPE6LP", "Burks", "6723 EV");
			tree.add(key1, std1);

			Assert::IsNotNull(tree.root);
			Student s = tree.root->getData();

			string id = "WBC88XPE6LP";
			//checking if the data from the first key is in the root
			Assert::AreEqual(id, s.getuser_id());
		}


		TEST_METHOD(TestAddToEmptyTreefail)
		{
			TNode<StudentKey, Student> tree;
			StudentKey key1("WBC88XPE6LP", "Burks", "6723 EV");

			Student std1("WBC88XPE6LP", "Burks", "6723 EV");
			tree.add(key1, std1);

			Assert::IsNotNull(tree.root);
			Student s = tree.root->getData();

			string id = "fail";
			Assert::AreEqual(id, s.getuser_id());
		}



		/*
		This test ensures a node is created on the left branch
		when value is less than root.
		*/
		TEST_METHOD(TestAddToRootLeft)
		{
			// adding the first key and then a smaller key after to ensure it goes left
			TNode<StudentKey, Student> tree;
			StudentKey key1("WBC88XPE6LP", "Burks", "6723 EV");  // hash key = 1345459642473233006
			StudentKey key2("MIH77ICR6QP", "Odom", "11649");   // hash key = 930083968261580712      
			
			// key 2 < key 1 so it goes left

			Student std1("WBC88XPE6LP", "Burks", "6723 EV");
			Student std2("MIH77ICR6QP", "Odom", "11649");

			
			tree.add(key1, std1);
			tree.add(key2, std2);
			
			Student rootnode = tree.root->getData();
			Assert::IsNotNull(tree.root);
			string rootid = "WBC88XPE6LP";
			string rootleftid = "MIH77ICR6QP";
			Assert::AreEqual(rootid,rootnode.getuser_id());
			TNode<StudentKey,Student>* left = tree.root->getLeft();

			Student x = left->getData();
			
			// checking if there is a left node present
			Assert::IsNotNull(left);
			
			// checking if the left node contains the data of key2
			Assert::AreEqual(rootleftid,x.getuser_id());
			
		
			
		}

		TEST_METHOD(TestAddToRootLeftfail)
		{

			TNode<StudentKey, Student> tree;
			StudentKey key1("WBC88XPE6LP", "Burks", "6723 EV");
			StudentKey key2("RDS11RXM7WY", "Morse", "08450");


			Student std1("WBC88XPE6LP", "Burks", "6723 EV");
			Student std2("RDS11RXM7WY", "Morse", "08450");


			tree.add(key1, std1);
			tree.add(key2, std2);

			Student rootnode = tree.root->getData();
			Assert::IsNotNull(tree.root);
			
			TNode<StudentKey, Student>* left = tree.root->getLeft();

			//fails because key 2 has been added to the right instead of left this time
			Assert::IsNotNull(left);



		}
		/*
		This test ensures a node is created on the right branch
		when value is less than root.
		*/
		TEST_METHOD(TestAddToRootRight)
		{

			// doing the same as above except key2 is a greater value than the root 

			TNode<StudentKey, Student> tree;
			StudentKey key1("WBC88XPE6LP", "Burks", "6723 EV"); // hash key = 1345459642473233006
			StudentKey key2("RDS11RXM7WY", "Morse", "08450"); // hash key 13027513765601054169

			// key 2 > key 1 so it goes right

			Student std1("WBC88XPE6LP", "Burks", "6723 EV");
			Student std2("RDS11RXM7WY", "Morse", "08450");

			tree.add(key1, std1);
			tree.add(key2, std2);
			Student rootnode = tree.root->getData();
			Assert::IsNotNull(tree.root);
			string rootid = "WBC88XPE6LP";
			string rootrightid = "RDS11RXM7WY";
			Assert::AreEqual(rootid,rootnode.getuser_id());
			TNode<StudentKey, Student>* right = tree.root->getRight();
			//checking if there is a right node
			Assert::IsNotNull(right);
			Student x = right->getData();
			//checking if the right node contains the userid of key 2
			Assert::AreEqual(rootrightid,x.getuser_id());
		}


		TEST_METHOD(TestAddToRootRightfail)
		{
			TNode<StudentKey, Student> tree;
			StudentKey key1("WBC88XPE6LP", "Burks", "6723 EV");
			StudentKey key2("MIH77ICR6QP", "Odom", "11649");


			Student std1("WBC88XPE6LP", "Burks", "6723 EV");
			Student std2("MIH77ICR6QP", "Odom", "11649");


			tree.add(key1, std1);
			tree.add(key2, std2);

			
			
			TNode<StudentKey, Student>* right = tree.root->getRight();

			// fails because key 2 was added to the left instead of right, meaning no node is present on the right of the root
			Assert::IsNotNull(right);
			
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
			// testing the remove function

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
			// removing key 4 which is not place in the tree
			tree.remove(key4);
			Assert::AreEqual(3, tree.count());

			
			//checking all of the nodes to see if the remove function had an impact on removing node that wasn't there

			
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

			/*
	Test the remove function to try and remove a leaf node
	to test this we will use the following tree
	 key1
	/   \
	2    Key2
   / \   / \
   1 3 Key3  7

   */


			TNode<StudentKey, Student> tree;
			StudentKey key1("WBC88XPE6LP", "Burks", "6723 EV");
			StudentKey key2("RDS11RXM7WY", "Morse", "08450");
			StudentKey key3("FNO15QZA3TB", "Francis", "14719");
			StudentKey key4("j1", "smfg", "cd");
			StudentKey key5("fdfa", "sfsf", "casf");

			Student std1("WBC88XPE6LP", "Burks", "6723 EV");
			Student std2("RDS11RXM7WY", "Morse", "08450");
			Student std3("FNO15QZA3TB", "Francis", "14719");
			Student std4("j1", "smfg", "cd");
			Student std5("fdfa", "sfsf", "casf");
			tree.add(key1, std1);
			tree.add(key2, std2);
			tree.add(key3, std3);
			tree.add(key4, std4);
			tree.add(key5, std5);
			Assert::AreEqual(5, tree.count());
			
		    tree.remove(key3);
			//removing key 3 from the diagram above
			Assert::AreEqual(4, tree.count());
			



			
			Assert::IsNotNull(tree.root);
			
			TNode<StudentKey, Student>* right = tree.root->getRight();
			//checking if there is still a node in the position where key 3 was
			Assert::IsNull(right->getLeft());


			

			/*
		Test the remove function to try and remove a leaf node
		to test this we will use the following tree
		 key1
		/   \
		2    Key2
	   / \   / \
	   1 3 Key3  7

	   */

		

		/*
		Test the remove function to try and remove a node with one child to the right
		to test this we will use the following tree
		  4
		 / \
		 2   6
		/ \ / \
		1   5  key4
				\
				key5
		*/
		}
		TEST_METHOD(TestRemoveNodeWithOneChild)
		{
			/*
		Before deletion
		  4
		 / \
		 2   6
		/ \ / \
		1   5  key4
				\
				key5
		*/


		/*
After removing key 4
  4
 / \
 2   6
/ \ / \
1   5  key5
		
		
*/

			TNode<StudentKey, Student> tree;
			StudentKey key1("WBC88XPE6LP", "Burks", "6723 EV");
			StudentKey key2("RDS11RXM7WY", "Morse", "08450");
			StudentKey key3("FNO15QZA3TB", "Francis", "14719");
			StudentKey key4("TEE62QJX2SJ", "Mccarty", "165810");
			StudentKey key5("KMW31DFX1GN", "Newman", "4266");

			Student std1("WBC88XPE6LP", "Burks", "6723 EV");
			Student std2("RDS11RXM7WY", "Morse", "08450");
			Student std3("FNO15QZA3TB", "Francis", "14719");
			Student std4("TEE62QJX2SJ", "Mccarty", "165810");
			Student std5("KMW31DFX1GN", "Newman", "4266");
			tree.add(key1, std1);
			tree.add(key2, std2);
			tree.add(key3, std3);
			tree.add(key4, std4);
			tree.add(key5, std5);
			//removing key 4 which is the node with 1 child
			tree.remove(key4);
			Assert::IsNotNull(tree.root);
			TNode<StudentKey, Student>* right = tree.root->getRight();
			Assert::IsNull(right->getRight()->getRight());
			Student rightmostleaf = right->getRight()->getData();
			// checking if key 5 is now in the position where key 4 was previously
			string rightmostnode = "KMW31DFX1GN";
			Assert::AreEqual(rightmostleaf.getuser_id(), rightmostnode);
			

		}
		



		TEST_METHOD(TestRemoveNodeWithTwoChildrenpass)
		{
			/*
		Before deletion
		 key1
		/    \
	   key2   6
		/ \   / \
		1 Key4 5  7
		*/


		/*
		After deletion
		 key1
		/    \
	   key4   6
		/    / \
		1    5  7
		*/


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
			//removing the left node of the root
			tree.remove(key2);
			Assert::AreEqual(3, tree.count());
			Student rootnode = tree.root->getData();
			string rootid = "FNO15QZA3TB";
			Assert::AreEqual(rootnode.getuser_id(),rootid);
			TNode<StudentKey, Student>* left = tree.root->getLeft();
			Student l = left->getData();
			// checking if key 4 is now in the position of key2
			string leftid = "KDS98KUM7KI";
			Assert::AreEqual(leftid,l.getuser_id());
			Student lr = left->getLeft()->getData();
			string leftleftid = "LGF12DCE4WF";
			Assert::AreEqual(leftleftid, lr.getuser_id());
			// checking if key 4 position no longer exists because it got swapped with key2 after it got deleted
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
			TNode<StudentKey, Student> tree;

			//Insert data similiar to the diagram above
			// would have to modify add method to insert ints instead of hashkeys, difficult to place all of the students similiar to the diagram above

			StudentKey key1("FNO15QZA3TB", "Burks", "6723 EV");
			StudentKey key2("NJB82NEB7RA", "Ortega", "03854");
			StudentKey key3("LGF12DCE4WF", "Rose", "686404");
			StudentKey key4("RDS11RXM7WY", "Morse", "08450");
			StudentKey key5("FNO1QZA3TB", "urk541s", "6723 V");
			StudentKey key6("JB82NEB7RA", "Ortg84a", "0384");
			StudentKey key7("LF12DCE1514WF", "Rse", "68644");
			StudentKey key8("RDS1RXM2817WY", "More", "0450");


			Student std1("FNO15QZA3TB", "Burks", "6723 EV");
			Student std2("NJB82NEB7RA", "Ortega", "03854");
			Student std3("LGF12DCE4WF", "Rose", "686404");
			Student std4("KDS98KUM7KI", "Boone", "83147");
			Student std5("FNO15QZA3TB", "Burks", "6723 EV");
			Student std6("NJB82NEB7RA", "Ortega", "03854");
			Student std7("LGF12DCE4WF", "Rose", "686404");
			Student std8("KDS98KUM7KI", "Boone", "83147");

			tree.add(key1, std1);
			tree.add(key2, std2);
			tree.add(key3, std3);
			tree.add(key4, std4);
			tree.add(key5, std5);
			tree.add(key6, std6);
			tree.add(key7, std7);
			tree.add(key8, std8);



			// check if there is a node on the left that has multiple children
			TNode<StudentKey, Student>* left = tree.root->getLeft();
			Assert::IsNull(left->getRight()->getRight());
			Assert::IsNull(left->getRight()->getLeft());
			Assert::IsNotNull(left->getLeft()->getRight());
			Assert::IsNull(left->getLeft()->getLeft());


			//remove the node left of the root // check the count 
			// check if the lowest hashkey at the bottom of the tree on the left will replace the node left of the root
			// do this by doing Assert::AreEqual(left->getData, "***check against the user.id which should have replaced the node");



			
		}

		TEST_METHOD(SearchForKeyAfterInsertedpass)
		{
			TNode<StudentKey, Student> tree;
			StudentKey key1("OFV53LRD4EP4", "Walters", "78377");
			StudentKey key2("RDS11RXM7WY", "Morse", "08450");

			Student std1("OFV53LRD4EP4", "Walters", "78377");
			Student std2("OFV53LRD4EP4", "Walters", "78377");
			tree.add(key1, std1);
			tree.add(key2, std2);

		
			Assert::IsTrue(tree.search(key2));


			//Implement Assert that checks whether the found keys data.userid is equal to "j123415441"
			//would have to edit the search method to work in such a way



		}

		TEST_METHOD(SearchForKeyAfterInsertedfail)
		{
			TNode<StudentKey, Student> tree;
			StudentKey key1("OFV53LRD4EP4", "Walters", "78377");
			StudentKey key2("RDS11RXM7WY", "Morse", "08450");

			Student std1("OFV53LRD4EP4", "Walters", "78377");
			Student std2("RDS11RXM7WY", "Morse", "08450");
			tree.add(key1, std1);
			//tree.add(key2, std2);

		
			Assert::IsTrue(tree.search(key2));
			
			
		

		}





		TEST_METHOD(PrintTest)
		{
			TNode<StudentKey, Student> tree;
			StudentKey key1("WBC88XPE6LP", "Burks", "6723 EV");
			
			Student std1("WBC88XPE6LP", "70", "Colby");
			




			// Try to store the output as a string, printBT method would need to be modified
			/*string output;
			output = printBT(tree.root);*/
			
			// key1 value checked against what would be printed out by the printBT
			/*string printedout = "<--(1345459642473233006)";


			Assert::AreEqual(output, printedout);*/

			//if the test passes means the print function is working correctly
			// this can also be checked with the main method * Run Compiler

		}












	};



}
