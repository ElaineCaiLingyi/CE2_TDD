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
			
			TextBuddy tb("Filename.txt");
			tb.text.push_back("cat");
			tb.text.push_back("dog");
			tb.text.push_back("monkey");
			tb.text.push_back("elephant");
			tb.text.push_back("hedgehog");

			//test case 1
			tb.sortFile();
		
		}

	};
}



/* public:
TEST_METHOD(testTotalSalary){
Payroll* p = new Payroll();
p->setSalaryManager(new SalaryManagerStub());
//test case 1
p->setEmployees(new std::string[2]{"E001", "E002"}, 2);
Assert::AreEqual(p->totalSalary(), 6400);
//test case 2
p->setEmployees(new std::string[1]{"E001"}, 1);
Assert::AreEqual(p->totalSalary(), 2300);
//more tests�
delete p;
}
};*/