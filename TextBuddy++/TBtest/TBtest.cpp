#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TBtest {

	TEST_CLASS(TBtest) {
	
	public:
		
		TEST_METHOD(ConstructorTest) {
				
			TextBuddy tb("filename.txt");
			string expected="filename.txt";
			Assert::AreEqual(expected, tb._filename); 
			Assert::IsTrue (tb._numberoflines==0);
		}

		TEST_METHOD(ClearTest) {

			TextBuddy tb ("clear.txt");
			tb.text.push_back("meow"); 
			tb.text.push_back("woof"); 
			tb.clearAll();
			string expected= "all content deleted from clear.txt\n";
			Assert::AreEqual(expected,tb.MESSAGE_ALL_CLEARED());
			Assert::IsTrue(tb._numberoflines==0);
		}

		TEST_METHOD(SortTest) {
			
			//assuming that the user inputs are all in lower cases
			TextBuddy tb("Filename.txt");
			tb.text.push_back("cat");
			tb.text.push_back("dog");
			tb.text.push_back("monkey");
			tb.text.push_back("elephant");
			tb.text.push_back("hedgehog");
			tb.text.push_back("monkeyy");
			
			//mannually rearranged
			string expected0="cat";
			string expected1="dog";
			string expected2="elephant";
			string expected3="hedgehog";
			string expected4="monkey";
			string expected5="monkeyy";

			//test case 1
			tb.sortFile();
			Assert::AreEqual(expected0,tb.text[0]);
			Assert::AreEqual(expected1,tb.text[1]);
			Assert::AreEqual(expected2,tb.text[2]);
			Assert::AreEqual(expected3,tb.text[3]);
			Assert::AreEqual(expected4,tb.text[4]);

			//test case 2
			string expected="All lines are sorted alphabetically";
			Assert::AreEqual(expected, tb.MESSAGE_ALL_SORTED);

			//test case 3
			Assert::AreEqual(expected5,tb.text[5]);
		
		}

		TEST_METHOD(SearchTest) {
		
			//assuming that the user inputs are all in lower cases
			TextBuddy tb("Filename.txt");
			tb.text.push_back("cat wanna eat fish");
			tb.text.push_back("monkey climbs over the tree");
			tb.text.push_back("dog barks happily");

			//test case 1 -> same word appears in only one sentence
			int size=tb.text.size();
			Assert::AreEqual(3,size); 
			string expected1="1. dog barks happily\n";
			Assert::AreEqual(expected1, tb.searchFile("barks"));

			//test case 2 -> same word appears in multiple sentences
			tb.text.push_back("cat cat");
			tb.text.push_back("kittycat");
			string expected2="1. cat wanna eat fish\n2. cat cat\n3. kittycat\n";
			Assert::AreEqual(expected2, tb.searchFile("cat"));

			//test case 3 -> the word does not exit in the file
			string expected3="The word cannot be found\n";
			Assert::AreEqual(expected3, tb.searchFile("sunshine"));

			//test case 4 -> findind a word in an empty file
			tb.clearAll();
			string expected4="The word cannot be found\n";
			Assert::AreEqual(expected4, tb.searchFile("cat"));

		}

	};
}