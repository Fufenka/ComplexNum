#include "pch.h"
#include "CppUnitTest.h"
#include "/VS projects/ΰσσσ/ΰσσσ/ComplexNum.h"
#include "/VS projects/ΰσσσ/ΰσσσ/ComplexNum.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(ComplexNumTest)
	{
	public:
		
		TEST_METHOD(TestgetRealPart)
		{
			ComplexNum z1(4, -7);
			double real = z1.getRealPart();
			Assert::AreEqual(4.0, real);
		}

		TEST_METHOD(TestMethodGetImaginary)
		{
			ComplexNum z1(4, -7);
			double imaginary = z1.getImaginaryPart();
			Assert::AreEqual(-7.0, imaginary);
		}

		TEST_METHOD(TestMethodSet)
		{
			ComplexNum z(4, -7);
			z.setRealPart(6);
			z.setImaginaryPart(9);
			Assert::AreEqual(6.0, z.getRealPart());
			Assert::AreEqual(9.0, z.getImaginaryPart());
		}
		TEST_METHOD(TestMethodModule)
		{
			ComplexNum z1(4, -3);
			double module = z1.module();
			Assert::AreEqual(5.0, module);
		}
		
		TEST_METHOD(TestMethodOperators)
		{
			ComplexNum z1(4, -3), z2(4, -3), z3(1, 5);
			double num = 5.0;
			Assert::IsTrue(z1 == z2);
			Assert::IsFalse(z1 == z3);
			Assert::IsTrue(z1 == num);
			Assert::IsFalse(z3 == num);

			ComplexNum sum = z1 + z2, ans1(8, -6);
			Assert::AreEqual(8.0, sum.getRealPart());
			Assert::AreEqual(-6.0, sum.getImaginaryPart());

			ComplexNum subtraction = z1 - z3, ans2(3, -8);
			Assert::AreEqual(3.0, subtraction.getRealPart());
			Assert::AreEqual(-8.0, subtraction.getImaginaryPart());

			ComplexNum multiplication = z1 * z3, ans3(19, 17);
			Assert::AreEqual(19.0, multiplication.getRealPart());
			Assert::AreEqual(17.0, multiplication.getImaginaryPart());

			ComplexNum division = z1 / z2, ans4(1, 0);
			Assert::AreEqual(1.0, division.getRealPart());
			Assert::AreEqual(0.0, division.getImaginaryPart());
		}

		TEST_METHOD(TestMethodPow)
		{
			ComplexNum z1(3, 4);
			ComplexNum answer = z1.pow1(3);
			Assert::AreEqual(-117.0, round(answer.getRealPart() * 100.0) / 100.0);
			Assert::AreEqual(44.0, round(answer.getImaginaryPart() * 100.0) / 100.0);

		}

	};
}
