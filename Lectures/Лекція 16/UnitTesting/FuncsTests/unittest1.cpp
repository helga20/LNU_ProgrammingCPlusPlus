#include "stdafx.h"
#include "CppUnitTest.h"
#include "Funcs.h"
//#include "string"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FuncsTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double c = harmony(45., 55.);
			//std::string s;
			Assert::AreEqual(49.5, c, 1.e-6);
			//Assert::AreEqual(1, 1);
		}

	};
}