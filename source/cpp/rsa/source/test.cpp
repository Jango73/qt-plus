/* ****************************************************************************
 *
 * Copyright 2013 Nedim Srndic
 * 
 * This file is part of rsa - the RSA implementation in C++.
 *
 * rsa is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * rsa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with rsa.  If not, see <http://www.gnu.org/licenses/>.
 *
 * 				test.cpp
 * 
 * Author: Nedim Srndic
 * Release date: 14th of March 2008
 * 
 * A collection of test code, used to test the functionality of other classes.
 * 
 * ****************************************************************************
 */

#include "test.h"
#include "BigInt.h"	//BigInt
#include "PrimeGenerator.h"	//Generate()
#include "Key.h"	//Key
#include "KeyPair.h"	//KeyPair
#include "RSA.h"	//GenerateKeyPair()
#include <iostream>	//cout, cin
#include <ctime>	//clock...
#include <cstdlib>
#include <string>	//BigInt::operator std::string() const
#include <climits>	// ULONG_MAX

using std::cout;
using std::endl;

bool doPause = false;

void pauseScreen()
{
	if (!doPause)
		return;
	cout << endl << "Insert any character to continue." << endl;
	char a;
	std::cin >> a;
}

void pauseScreenOnError()
{
	cout << endl << "ERROR!!!\nInsert any character to continue." << endl;
	char a;
	std::cin >> a;
}

void testVerbose(const BigInt &a, const BigInt &b)
{
	cout << " = " << a;
	if (a != b)
	{
		cout << ", NOT " << b << "\t\tTEST FAIL!" << endl;
		pauseScreenOnError();
	}
	else
		cout << "\t\tTEST OK!" << endl;
}

template <typename T>
void testVerbose(T a, T b)
{
	cout << " = " << a;
	if (a != b)
	{
	cout << ", NOT " << b << "\t\tTEST FAIL!" << endl;
		pauseScreenOnError();
	}
	else
		cout << "\t\tTEST OK!" << endl;
}

void test(const BigInt &a, const BigInt &b)
{
	if (a != b)
	{
		cout << "\t\tTEST FAIL!" << endl;
		pauseScreenOnError();
	}
	else
		cout << "\t\tTEST OK!" << endl;
}

template <typename T>
void test(T a, T b)
{
	if (a != b)
	{
		cout << "\t\tTEST FAIL!" << endl;
		pauseScreenOnError();
	}
	else
		cout << "\t\tTEST OK!" << endl;
}

BigInt factorial(unsigned long int n)
{
	BigInt fact(1);
	for (unsigned long int i(1); i <= n; i++)
		fact = fact * i;
		
	return fact;
}

void factorialTimeTest(unsigned long int n, const char *factorialOfN)
{
	std::clock_t startTime(std::clock()), finishTime;
	BigInt a(factorial(n));
	finishTime = std::clock();
	double time((double(finishTime) - double(startTime)) / CLOCKS_PER_SEC);
	cout << "factorial(" << n << ") = " << a << endl 
		<< "Time: " << time << "s" << endl;
	test(a, factorialOfN);
}

void TestBigIntFunctions()
{
	/*CONSTRUCTOR, DESTRUCTOR, ASSIGNMENT AND STREAM OUTPUT OPERATOR TEST*/

	cout << "  CONSTRUCTOR, DESTRUCTOR, ASSIGNMENT AND STREAM OUTPUT" <<
	" OPERATOR TEST   " << endl << endl;

	//test zero param constructor
    BigInt myNumberA;
    cout << "myNumberA = " << myNumberA << endl;
    test(myNumberA, "0");
    
    //test const char* constructor
    BigInt myNumberB = "00000290823984273072361";
	cout << "myNumberB = " << myNumberB << endl;
	test(myNumberB, "290823984273072361");
	BigInt myNumberB1 = "290823984273072361257203975203975203952093520984121286128681286186200880243234234234162356876909986221564574980882162898021200892208721076218021087612698981290809216790921";
	cout << "myNumberB1 = " << myNumberB1 << endl;
	test(myNumberB1, "290823984273072361257203975203975203952093520984121286128681286186200880243234234234162356876909986221564574980882162898021200892208721076218021087612698981290809216790921");
	myNumberB1 = "-000005";
	test(myNumberB1, "-5");
	//test const char* constructor with invalid characters
	//BigInt myNumberC = "2308238902230823a"; throws "Error 02: Input string contains characters other than digits.";
	//test const char* constructor with an empty string
	//BigInt myNumberC = "";	//throws "Error 01: Input string empty.";
	
	//test unsigned long int constructor
	BigInt myNumberE = 8840;
	cout << "myNumberE = " << myNumberE << endl;
	test(myNumberE, 8840);
	BigInt myNumberZ = (unsigned long int) 0;
	cout << "myNumberZ = " << myNumberZ << endl;
	test(myNumberZ, (unsigned long int) 0);
	BigInt myNumberE1 = 384094351;
	cout << "myNumberE1 = " << myNumberE1 << endl;
	test(myNumberE1, 384094351);
	
	//test std::string constructor 
	std::string strNum("123456");
	BigInt newBI(strNum);
	test(newBI, "123456");
	//test std::string constructor with invalid characters
//	strNum = "23082334378652458902230823a";
	BigInt newBI2(strNum); //throws "Error 02: Input string contains characters other than digits.";
	//test const char* constructor with an empty string
	strNum.clear();
//	BigInt newBI3(strNum);	//throws "Error 01: Input string empty.";
	
	//test copy constructor
	BigInt myNumberF(myNumberA);
	cout << "myNumberF = " << myNumberF << endl;
	test(myNumberF, myNumberA);
	BigInt myNumberG(myNumberB1);
	cout << "myNumberG = " << myNumberG << endl;
	test(myNumberG, myNumberB1);
	BigInt myNumberG1(myNumberB1);
	cout << "myNumberG1 = " << myNumberG1 << endl;
	test(myNumberG1, myNumberB1);
	
	//test the BigInt::operator std::string() const
	strNum = myNumberG1;
	test(strNum, myNumberG1);
	
	//test overloaded assignment operator with right number bigger
	myNumberA = myNumberB;
	cout << "myNumberA = " << myNumberA << endl;
	test(myNumberA, myNumberB);
	//test overloaded assignment operator with right number negative
	myNumberA = myNumberB1;
	cout << "myNumberA = " << myNumberA << endl;
	test(myNumberA, myNumberB1);
	//test overloaded assignment operator with right number smaller
	myNumberA = myNumberE;
	cout << "myNumberA = " << myNumberA << endl;
	test(myNumberA, myNumberE);
	//test overloaded assignment operator with right number same size
	myNumberA = myNumberE;
	cout << "myNumberA = " << myNumberA << endl;
	test(myNumberA, myNumberE);
	//test overloaded assignment operator with self assignment
	myNumberA = myNumberA;
	cout << "myNumberA = " << myNumberA << endl;
	test(myNumberA, myNumberA);
	//test overloaded assignment operator with right number bigger
	myNumberA = "09837450923475203962509347568969876986";
	cout << "myNumberA = " << myNumberA << endl;
	test(myNumberA, "09837450923475203962509347568969876986");
	//test overloaded assignment operator with right number smaller
	myNumberA = "1";
	cout << "myNumberA = " << myNumberA << endl;
	test(myNumberA, 1);
	//test overloaded assignment operator with right number same size
	myNumberA = "1";
	cout << "myNumberA = " << myNumberA << endl;
	test(myNumberA, 1);
	
	//test the EqualsZero member function
	test(myNumberA.EqualsZero(), false);
	myNumberA = BigIntZero;
	test(myNumberA.EqualsZero(), true);
	myNumberA = "0";
	test(myNumberA.EqualsZero(), true);
	myNumberA = BigIntOne - BigIntOne;
	test(myNumberA.EqualsZero(), true);
	myNumberA = BigIntZero - BigIntOne;
	test(myNumberA.EqualsZero(), false);
	
	//test GetDigit(), SetDigit()
	myNumberA = "145";
	if (myNumberA.GetDigit(0) == 5 && myNumberA.GetDigit(1) == 4 
			&& myNumberA.GetDigit(2) == 1)
		cout << "GetDigit() test passed" << endl;
	else
		pauseScreenOnError();
//	if (myNumberA.GetDigit(3) == 0)	//throws "Error BIGINT14: Index out of range.";
//		cout << "GetDigit() test failed" << endl; 
	myNumberA.SetDigit(1, 8);
	test(myNumberA, 185L);
//	myNumberA.SetDigit(33, 2);	//throws "Error BIGINT15: Index out of range.";
//	myNumberA.SetDigit(1, 99);	//throws "Error BIGINT16: Digit value out of range.";
	
	
	//test GetPower(int), SetPower(int), GetPower(BigInt), SetPower(BigInt)
	BigInt a(2), b(3);
	cout << a.GetPower(10);
	test(a.GetPower(10), 1024);
	a = 2;
	cout << a.GetPower(63) << endl;
	test(a.GetPower(63), "9223372036854775808");
	cout << a.GetPower(64) << endl;
	test(a.GetPower(64), "18446744073709551616");
	cout << a.GetPower(71) << endl;
	test(a.GetPower(71), "2361183241434822606848");
	test(a.GetPower(0), "1");
	a = "10";
	a.SetPower(6);
	cout << a << endl;
	test(a, "1000000");
	a = 10;
	cout << (a.GetPower("200")) << endl;
	test(a.GetPower("200"), "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
	a.SetPower(b);
	cout << a << endl;
	test(a, "1000");
	
	//test SetPowerMod(), GetPowerMod()
	a = 3;
	b = 3;
	cout << a.GetPowerMod(b, 5) << endl;
	test(a.GetPowerMod(b, 5), 2);
	a.SetPowerMod(b, 5);
	cout << a << endl;
	test(a, 2);
	a = "22";
	test(a.GetPowerMod("6", "37"), "27");
	
	//test ToString()
	a = "10000000000";
	cout << a.ToString() << endl;
	cout << a.ToString(true) << endl;
	a = -a;
	cout << a.ToString() << endl;
	
	//test Length()
	cout << a.Length() << endl;
	test(a.Length(), 11);
	
	//test Abs()
	a = "10";
	cout << "a.Abs() = " << a.Abs() << endl;
	test(a.Abs(), a);
	cout << "(-a).Abs() = " << (-a).Abs() << endl;
	test((-a).Abs(), a);
}

void TestBigIntOperators()
{
	/*				COMPARISION OPERATOR TEST				*/

	cout << endl << endl << "		COMPARISION OPERATOR TEST" <<
	endl << endl;

    cout << "\tOPERATORS <, <=, >, >=, ==\n\n";
    
    BigInt t1(3), t2(static_cast<unsigned long int>(0)), t3("-3");
    
    for (; t1 >= t3; t1 = t1 - BigIntOne)
    {
    	cout << t1 << " < " << t2 << " = " << (t1 < t2) << endl;
    	cout << t1 << " <= " << t2 << " = " << (t1 <= t2) << endl;
    	cout << t1 << " > " << t2 << " = " << (t1 > t2) << endl;
    	cout << t1 << " >= " << t2 << " = " << (t1 >= t2) << endl;
    	cout << t1 << " == " << t2 << " = " << (t1 == t2) << endl; 
    }
	
	/*				ARITHMETIC OPERATOR TEST				*/

	cout << endl << endl << "		ARITHMETIC OPERATOR TEST	" <<
	endl << endl;

	cout << "\tUNARY OPERATOR +\n\n";
	{
		BigInt num1 = 99, num2 = "-1";
		test(+num1, 99);
		test(+num2, "-1");
	}
	
    cout << "\tBINARY OPERATOR +\n\n";

	{
		BigInt num1 = 99, num2 = 1, num3;
		cout << "num1 = " << num1 << "\nnum2 = " << num2
		<< "\nnum3 = " << num3 << endl;
		cout << "num1 + num2 = " << (num1 + num2) << endl;
		test(num1 + num2, 100);
		cout << "num2 + num1 = " << (num2 + num1) << endl;
		test(num2 + num1, 100);
		num3 = num1 + num2;
		cout << "num3 = num1 + num2\nnum3 = " << num3 << endl;
		test(num3, num1 + num2);
		num1 = "9834752937520397520395610694519";
		cout << "num1 = " << num1 << endl;
		num2 = "56475638475928374692873450237450";
		cout << "num2 = " << num2 << endl;
		num3 = num1 + num2;
		cout << "num3 = num1 + num2\nnum3 = " << num3 << endl;
		test(num3, "66310391413448772213269060931969");
		cout << "num1 + num1 = " << (num1 + num1) << endl;
		test(num1 + num1, "19669505875040795040791221389038");
		
		num1 = "-5"; num2 = "-3";
		cout << "num1 = " << num1 << endl;
		cout << "num2 = " << num2 << endl;
		cout << "num1 + num2 = " << (num1 + num2) << endl;
		test(num1 + num2, "-8");
		cout << "num2 + num1 = " << (num2 + num1) << endl;
		test(num2 + num1, "-8");
		num2 = "3";
		cout << "num1 = " << num1 << endl;
		cout << "num2 = " << num2 << endl;
		cout << "num1 + num2 = " << (num1 + num2) << endl;
		test(num1 + num2, "-2");
		cout << "num2 + num1 = " << (num2 + num1) << endl;
		test(num2 + num1, "-2");
		num1 = "5";
		cout << "num1 = " << num1 << endl;
		cout << "num2 = " << num2 << endl;
		cout << "num1 + num2 = " << (num1 + num2) << endl;
		test(num1 + num2, "8");
		cout << "num2 + num1 = " << (num2 + num1) << endl;
		test(num2 + num1, "8");
		num2 = "-3";
		cout << "num1 = " << num1 << endl;
		cout << "num2 = " << num2 << endl;
		cout << "num1 + num2 = " << (num1 + num2) << endl;
		test(num1 + num2, "2");
		cout << "num2 + num1 = " << (num2 + num1) << endl;
		test(num2 + num1, "2");
	}

	cout << "\n\n\tBINARY OPERATOR -\n\n";
	
	{
	    BigInt n1 = "1", n2 = "10";
	    //test overloaded - operator with equal operands
	    n1 = "10";
	    cout << "n1 = " << n1 << "\nn2 = " << n2 << endl;
	    cout << "n1 - n2 = " << (n1 - n2) << endl;
	    test(n1 - n2, static_cast<unsigned long int>(0));
	    //test overloaded - operator with first operand bigger
	    n1 = "11";
	    cout << "n1 = " << n1 << "\nn2 = " << n2 << endl;
	    cout << "n1 - n2 = " << (n1 - n2) << endl;
	    test(n1 - n2, 1);
	    //test overloaded - operator with first operand bigger
	    n1 = "12";
	    cout << "n1 = " << n1 << "\nn2 = " << n2 << endl;
	    cout << "n1 - n2 = " << (n1 - n2) << endl;
	    test(n1 - n2, 2);
	    //test overloaded - operator with first operand bigger
	    n1 = "13";
	    cout << "n1 = " << n1 << "\nn2 = " << n2 << endl;
	    cout << "n1 - n2 = " << (n1 - n2) << endl;
	    test(n1 - n2, 3);
	    //test overloaded - operator with first operand bigger
	    n1 = "100";
	    cout << "n1 = " << n1 << "\nn2 = " << n2 << endl;
	    cout << "n1 - n2 = " << (n1 - n2) << endl;
	    test(n1 - n2, 90);
	    //test overloaded - operator with first operand bigger
	    n1 = "1010";
	    n2 = "99";
	    cout << "n1 = " << n1 << "\nn2 = " << n2 << endl;
	    cout << "n1 - n2 = " << (n1 - n2) << endl;
	    test(n1 - n2, "911");
	    //test overloaded - operator with first operand bigger
	    n1 = "66310391413448772213269060931969";
	    n2 = "56475638475928374692873450237450";
	    cout << "n1 = " << n1 << "\nn2 = " << n2 << endl;
	    cout << "n1 - n2 = " << (n1 - n2) << endl;
	    test(n1 - n2, "9834752937520397520395610694519");
	    //test overloaded - operator with first operand bigger
	    n1 = "100";
	    n2 = "99";
	    cout << "n1 = " << n1 << "\nn2 = " << n2 << endl;
	    cout << "n1 - n2 = " << (n1 - n2) << endl;
	    test(n1 - n2, "1");
	    
	    n1 = "-5"; n2 = "-3";
	    cout << "n1 = " << n1 << "\nn2 = " << n2 << endl;
	    cout << "n1 - n2 = " << (n1 - n2) << endl;
	    test(n1 - n2, "-2");
	    cout << "n2 - n1 = " << (n2 - n1) << endl;
	    test(n2 - n1, "2");
	    n1 = "-5"; n2 = "3";
	    cout << "n1 = " << n1 << "\nn2 = " << n2 << endl;
	    cout << "n1 - n2 = " << (n1 - n2) << endl;
	    test(n1 - n2, "-8");
	    cout << "n2 - n1 = " << (n2 - n1) << endl;
	    test(n2 - n1, "8");
	    n1 = "5"; n2 = "3";
	    cout << "n1 = " << n1 << "\nn2 = " << n2 << endl;
	    cout << "n1 - n2 = " << (n1 - n2) << endl;
	    test(n1 - n2, "2");
	    cout << "n2 - n1 = " << (n2 - n1) << endl;
	    test(n2 - n1, "-2");
	    n1 = "5"; n2 = "-3";
	    cout << "n1 = " << n1 << "\nn2 = " << n2 << endl;
	    cout << "n1 - n2 = " << (n1 - n2) << endl;
	    test(n1 - n2, "8");
	    cout << "n2 - n1 = " << (n2 - n1) << endl;
	    test(n2 - n1, "-8");
	}

	cout << "\n\n\tOPERATOR ++\n\n";

	{
		BigInt num;
		num++;
		test(num, 1);
		num = "-1";
		test(++num, "0");
	} 
	
	cout << "\n\n\tOPERATOR --\n\n";
	
	{
		BigInt num(5);
		num--;
		test(num, 4);
		num = "0";
		test(--num, "-1");
	}
	
	cout << "\n\n\tOPERATOR +=\n\n";
	
	{
		BigInt num1 = "9834752937520397520395610694519";
		BigInt num2 = "56475638475928374692873450237450";
		test((num1 += num2), "66310391413448772213269060931969");
		num1 = "9834752937520397520395610694519";
		test(num2 = (num1 += num1), "19669505875040795040791221389038");
		num1 = "3"; num2 = "-5";
		test((num1 += num2), "-2");
	}
	
	cout << "\n\n\tOPERATOR -=\n\n";
	
	{
		BigInt n1 = "66310391413448772213269060931969";
	    BigInt n2 = "56475638475928374692873450237450";
	    test((n1 -= n2), "9834752937520397520395610694519");
	    n1 = "100"; n2 = "99";
	    test(n2 = (n1 -= n2), "1");
	    n1 = "-3"; n2 = "-4";
	    test((n1 -= n2), "1");
	}
	
	cout << "\n\n\tOPERATOR *\n\n";

	{
		BigInt a(10), b(20);
		test(a * b, 200);
		BigInt e(9900), f(9900);
		test(e * f, 9900 * 9900);
		e = 8448448;
		test(e * f, "83639635200");
		a = "20";
		b = "121645100408832000";
		test(a * b, "2432902008176640000");
		test(b * a, "2432902008176640000");
		a = "44444";
		b = "99999";
		test(a * b, "4444355556");
		a = "0";
		test(a * b, "0");
		
		a = "10"; b = "20";
		test(a * b, "200");
		test(b * a, "200");
		a = "10"; b = "-20";
		test(a * b, "-200");
		test(b * a, "-200");
		a = "-10"; b = "20";
		test(a * b, "-200");
		test(b * a, "-200");
		a = "-10"; b = "-20";
		test(a * b, "200");
		test(b * a, "200");
	}
	
	cout << "\n\n\tOPERATOR *=\n\n";

	{
		BigInt a(10), b(20);
		test(a *= b, 200);
		BigInt e(9900), f("-9900");
		test(e *= f, "-98010000");
		e = 8448448;
		f = -f;
		test(e *= f, "83639635200");
		a = "20";
		b = "121645100408832000";
		test(a *= b, "2432902008176640000");
		a = "20";
		test(b *= a, "2432902008176640000");
		a = "44444";
		b = "99999";
		test(a *= b, "4444355556");
		a = "0";
		test(a *= b, "0");
	}
	
	cout << "\n\n\tOPERATOR /\n\n";

	{
		BigInt a(10), b("0");
//		test(a / b, "0");	//throws "Error 12: Attempt to divide by zero."
		a = "0";
		b = "121645100408832000";
		test(a / b, "0");
		a = "232323";
		test(a / b, "0");
		b = "232323";
		test(a / b, "1");
		a = "9";
		b = 3;
		test(a / b, "3");
		
		a = "-10"; b = "-3";
		test(a / b, 3);
		b = "3";
		test(a / b, "-3");
		a = 10;
		test(a / b, 3);
		b = "-3";
		test(a / b, "-3");
	}
	
	cout << "\n\n\tOPERATOR /=\n\n";

	{
		//test overloaded /= operator 
		pauseScreen();
		
		BigInt a(10), b("0");
//		test(a /= b, "0");	//throws "Error 12: Attempt to divide by zero."
		a = "0";
		b = "121645100408832000";
		test(a /= b, "0");
		a = "232323";
		test(a /= b, "0");
		a = "232323";
		b = "-232323";
		test(a /= b, "-1");
		a = "9";
		b = 3;
		test(a /= b, "3");
	}
	
	cout << "\n\n\tOPERATOR %\n\n";

	{
		BigInt a(10), b("0");
//		test(a % b, "0");	//throws "Error 12: Attempt to divide by zero."
		a = "0";
		b = "121645100408832000";
		test(a % b, "0");
		a = "232323";
		test(a % b, "232323");
		b = "232323";
		test(a % b, "0");
		a = "9";
		b = 3;
		test(a % b, "0");
		a = "10";
		test(a % b, "1");
		a = "11";
		test(a % b, "2");
		
		a = "-10"; b = "-3";
		test(a % b, "-1");
		b = "3";
		test(a % b, "-1");
		a = 10;
		test(a % b, 1);
		b = "-3";
		test(a % b, "1");
	}
	
	cout << "\n\n\tOPERATOR %=\n\n";

	{
		//test overloaded % operator 
		pauseScreen();
		
		BigInt a(10), b("0");
//		test(a %= b, "0");	//throws "Error 12: Attempt to divide by zero."
		a = "0";
		b = "121645100408832000";
		test(a %= b, "0");
		a = "232323";
		test(a %= b, "232323");
		b = "232323";
		test(a %= b, "0");
		a = "-9";
		b = 3;
		test(a %= b, "0");
		a = "10";
		test(a %= b, "1");
		a = "11";
		test(a %= b, "2");
	}
}

/*				FACTORIAL COMPUTATION BENCHMARK			*/

void FactorialBenchmark()
{
	cout << "\n\n\tFACTORIAL BENCHMARK\n\n";
	
	factorialTimeTest(19, "121645100408832000");
	factorialTimeTest(20, "2432902008176640000");
	factorialTimeTest(67, "36471110918188685288249859096605464427167635314049524593701628500267962436943872000000000000000");
	factorialTimeTest(100, "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000");
	factorialTimeTest(300, "306057512216440636035370461297268629388588804173576999416776741259476533176716867465515291422477573349939147888701726368864263907759003154226842927906974559841225476930271954604008012215776252176854255965356903506788725264321896264299365204576448830388909753943489625436053225980776521270822437639449120128678675368305712293681943649956460498166450227716500185176546469340112226034729724066333258583506870150169794168850353752137554910289126407157154830282284937952636580145235233156936482233436799254594095276820608062232812387383880817049600000000000000000000000000000000000000000000000000000000000000000000000000");
//	factorialTimeTest(1000,"402387260077093773543702433923003985719374864210714632543799910429938512398629020592044208486969404800479988610197196058631666872994808558901323829669944590997424504087073759918823627727188732519779505950995276120874975462497043601418278094646496291056393887437886487337119181045825783647849977012476632889835955735432513185323958463075557409114262417474349347553428646576611667797396668820291207379143853719588249808126867838374559731746136085379534524221586593201928090878297308431392844403281231558611036976801357304216168747609675871348312025478589320767169132448426236131412508780208000261683151027341827977704784635868170164365024153691398281264810213092761244896359928705114964975419909342221566832572080821333186116811553615836546984046708975602900950537616475847728421889679646244945160765353408198901385442487984959953319101723355556602139450399736280750137837615307127761926849034352625200015888535147331611702103968175921510907788019393178114194545257223865541461062892187960223838971476088506276862967146674697562911234082439208160153780889893964518263243671616762179168909779911903754031274622289988005195444414282012187361745992642956581746628302955570299024324153181617210465832036786906117260158783520751516284225540265170483304226143974286933061690897968482590125458327168226458066526769958652682272807075781391858178889652208164348344825993266043367660176999612831860788386150279465955131156552036093988180612138558600301435694527224206344631797460594682573103790084024432438465657245014402821885252470935190620929023136493273497565513958720559654228749774011413346962715422845862377387538230483865688976461927383814900140767310446640259899490222221765904339901886018566526485061799702356193897017860040811889729918311021171229845901641921068884387121855646124960798722908519296819372388642614839657382291123125024186649353143970137428531926649875337218940694281434118520158014123344828015051399694290153483077644569099073152433278288269864602789864321139083506217095002597389863554277196742822248757586765752344220207573630569498825087968928162753848863396909959826280956121450994871701244516461260379029309120889086942028510640182154399457156805941872748998094254742173582401063677404595741785160829230135358081840096996372524230560855903700624271243416909004153690105933983835777939410970027753472000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
}

/*				RANDOM TEST GENERATOR					*/

unsigned long int myRand(unsigned long int max = RAND_MAX)
{
	return static_cast<unsigned long int>(rand() % max);
}

/*				TEST CODES:
 * 0; a.GetPower(int n);
 * 1; a < b
 * 2; a <= b
 * 3; a > b
 * 4; a >= b
 * 5; a == b
 * 6; a != b
 * 7; a + b
 * 8; ++a
 * 9; a++
 * 10; a += b
 * 11; a - b
 * 12; --a
 * 13; a--
 * 14; a -= b
 * 15; a * b
 * 16; a *= b
 * 17; a / b
 * 18; a /= b
 */
void RandomBigIntTest(unsigned long int testCount)
{
	cout << "\n\n\tRANDOM TEST\n\n";
	cout << "Preparing to do " << testCount << " tests." << endl << endl;
	BigInt a, b;
	unsigned long int m(0), n(0);
	for (unsigned long int i(1); i <= testCount; i++)
	{
		cout << "\nTEST " << i << " =======================================\n";
		switch (rand() % 19)
		{
			case 1:
				m = myRand();	n = myRand();
				a = m;	b = n;
				cout << "a = " << a << endl << "b = " << b << endl;
				cout << "TESTING a < b";
				testVerbose(a < b, m < n);
				break;
			case 2:
				m = myRand();	n = myRand();
				a = m;	b = n;
				cout << "a = " << a << endl << "b = " << b << endl;
				cout << "TESTING a <= b";
				testVerbose(a <= b, m <= n);
				break;
			case 3:
				m = myRand();	n = myRand();
				a = m;	b = n;
				cout << "a = " << a << endl << "b = " << b << endl;
				cout << "TESTING a > b";
				testVerbose(a > b, m > n);
				break;
			case 4:
				m = myRand();	n = myRand();
				a = m;	b = n;
				cout << "a = " << a << endl << "b = " << b << endl;
				cout << "TESTING a >= b";
				testVerbose(a >= b, m >= n);
				break;
			case 5:
				m = myRand();	n = myRand();
				a = m;	b = n;
				cout << "a = " << a << endl << "b = " << b << endl;
				cout << "TESTING a == b";
				testVerbose(a == b, m == n);
				break;
			case 6:
				m = myRand();	n = myRand();
				a = m;	b = n;
				cout << "a = " << a << endl << "b = " << b << endl;
				cout << "TESTING a != b";
				testVerbose(a != b, m != n);
				break;
			case 7:
				m = myRand();	n = myRand(RAND_MAX - n);
				a = m;	b = n;
				cout << "a = " << a << endl << "b = " << b << endl;
				cout << "TESTING a + b";
				testVerbose(a + b, m + n);
				break;
			case 8:
				m = myRand();
				a = m;
				cout << "a = " << a << endl;
				cout << "TESTING ++a";
				testVerbose(++a, ++m);
				break;
			case 9:
				m = myRand();
				a = m;
				cout << "a = " << a << endl;
				cout << "TESTING a++";
				testVerbose(a++, m++);
				testVerbose(a, m);
				break;
			case 10:
				m = myRand();	n = myRand(RAND_MAX - n);
				a = m;	b = n;
				cout << "a = " << a << endl << "b = " << b << endl;
				cout << "TESTING a += b";
				testVerbose(a += b, m += n);
				break;
			case 11:
				m = myRand();	n = myRand(m);

				a = m;	b = n;
				cout << "a = " << a << endl << "b = " << b << endl;
				cout << "TESTING a - b";
				testVerbose(a - b, m - n);
				break;
			case 12:
				m = myRand();
				a = m;
				cout << "a = " << a << endl;
				cout << "TESTING --a";
				testVerbose(--a, --m);
				break;
			case 13:
				m = myRand();
				a = m;
				cout << "a = " << a << endl;
				cout << "TESTING a--";
				testVerbose(a--, m--);
				testVerbose(a, m);
				break;
			case 14:
				m = myRand();	n = myRand(m);
				a = m;	b = n;
				cout << "a = " << a << endl << "b = " << b << endl;
				cout << "TESTING a -= b";
				testVerbose(a -= b, m -= n);
				break;
			case 15:
				m = myRand(ULONG_MAX / 2000);	n = myRand(ULONG_MAX / m);
				a = m;	b = n;
				cout << "a = " << a << endl << "b = " << b << endl;
				cout << "TESTING a * b";
				testVerbose(a * b, m * n);
				break;
			case 16:
				m = myRand(ULONG_MAX / 2000);	n = myRand(ULONG_MAX / m);
				a = m;	b = n;
				cout << "a = " << a << endl << "b = " << b << endl;
				cout << "TESTING a *= b";
				testVerbose(a *= b, m *= n);
				break;
			case 17:
				m = myRand();	n = myRand(m);
				a = m;	b = n;
				cout << "a = " << a << endl << "b = " << b << endl;
				cout << "TESTING a / b";
				testVerbose(a / b, m / n);
				break;
			case 18:
				m = myRand();	n = myRand(m);
				a = m;	b = n;
				cout << "a = " << a << endl << "b = " << b << endl;
				cout << "TESTING a /= b";
				testVerbose(a /= b, m /= n);
				break;
			case 0:
				m = myRand(10);	n = myRand(9);
				a = m;
				cout << "a = " << a << endl << "n = " << n << endl;
				cout << "TESTING a.Power(n)";
				double temp(pow((double) m, (double) n));
				unsigned long int power;
				if (temp - floor(temp) < ceil(temp) - temp)
					power = static_cast<unsigned long int>(floor(temp));
				else
					power = static_cast<unsigned long int>(ceil(temp));
				testVerbose(a.GetPower(n), power);
				break;
		}
	}
	cout << "\nRandom test finished!" << endl;
}

/*				RANDOM DIVISION TEST GENERATOR			*/
void RandomBigIntDivisionTest(unsigned long int testCount)
{
	cout << "\n\n\tRANDOM DIVISION TEST\n\n";
	cout << "Preparing to do " << testCount << " tests." << endl << endl;
	
	for (unsigned long int i(1); i <= testCount; i++)
	{
		cout << "Test " << i << endl;
		BigInt a(myRand()), b(myRand()), c(myRand()), d(myRand());
		a *= c * d;
		cout << "a = " << a << endl << "b = " << b << endl;
		cout << "a * b = " << a * b << endl;
		cout << "a * b / a = ";
		testVerbose(a * b / a, b);
		cout << endl << "a * b / b = ";
		testVerbose(a * b / b, a);
		cout << endl;
	}
	cout << "\nRandom division test finished!" << endl;
}

/*				PRIME GENERATOR TEST					*/
void TestPrimeGenerator(unsigned long int testCount, 
						unsigned long int digitCount, 
						unsigned long int iterationCount)
{
	cout << "\n\n\tPRIME GENERATOR TEST\n\n";
	cout << "Preparing to do " << testCount << " tests.\nDigits: " 
	<< digitCount << "\nIterations: " << iterationCount << endl << endl;
	
	for (unsigned long int i = 1; i <= testCount; i++)
		cout << i << ". " << PrimeGenerator::Generate(	digitCount, 
														iterationCount) 
				<< endl << endl;
	
	cout << "\nPrime generator test finished!" << endl;
}

/*				KEY GENERATOR TEST						*/
void TestKeyGeneration(	unsigned long int testCount, 
						unsigned long int keyLength)
{
	cout << "\n\n\tKEY GENERATION TEST\n\n";
	cout << "Preparing to do " << testCount << " tests.\nKeylength: " 
	<< keyLength << endl << endl;
	
	for (unsigned long int i = 1; i <= testCount; i++)
	{
		cout << i << ". " << endl;
		KeyPair newKeyPair(RSA::GenerateKeyPair(keyLength));
		std::string message("aha");
		std::string cypherText = RSA::Encrypt(	message, 
												newKeyPair.GetPublicKey());
		std::string newMessage = RSA::Decrypt(	cypherText, 
												newKeyPair.GetPrivateKey());
		cout << newKeyPair << endl;
		test(message, newMessage);
	}
	
	cout << "\nKey generation test finished!" << endl;
}

/*				ENCRYPTION/DECRYPTION TEST				*/
void TestEncryptionDecryption(	unsigned long int testCount, 
								unsigned long int keyLength)
{
	cout << "\n\n\tENCRYPTION/DECRYPTION TEST\n\n";
	cout << "Preparing to do " << testCount << " tests.\nKeylength: " 
	<< keyLength << endl;
	
	KeyPair newKeyPair(RSA::GenerateKeyPair(keyLength));
	std::string message("Ja ti on ona ono mi vi oni one ona. \n\t\0egnb50hue");
	cout << "\n" << newKeyPair << "\n\ndone!" << endl
			<< "Encrypting the message: \"" << message << "\"... \n";
	for (unsigned long int i = 1; i <= testCount; i++)
	{
		cout << i << ".\nEncrypting the message... ";
		
		std::string cypherText = RSA::Encrypt(	message, 
												newKeyPair.GetPublicKey());
		cout << "done!\nDecrypting the message... ";
		std::string newMessage = RSA::Decrypt(	cypherText, 
												newKeyPair.GetPrivateKey());
		cout << "done!\n" << endl;
		test(message, newMessage);
	}
	
	cout << "\nEncryption/decryption test finished!" << endl;
}

/*				FILE ENCRYPTION/DECRYPTION TEST			*/
void TestFileEncryptionDecryption(	unsigned long int testCount, 
									unsigned long int keyLength)
{
	cout << "\n\n\tFILE ENCRYPTION/DECRYPTION TEST\n\n";
	cout << "Preparing to do " << testCount << " tests.\nKeylength: " 
	<< keyLength << endl << endl;
	
	cout << "Generating keypair... ";
	KeyPair newKeyPair(RSA::GenerateKeyPair(keyLength));
	cout << "\n\n" << newKeyPair << "\n\ndone!" << endl; 
	char messageFile[] = "test/message.txt";
	char cypherFile[] = "test/cyphertext.txt";
	char destFile[]	= "test/new_message.txt";
	cout << "Encrypting the file: \"" << messageFile << "\"... \n";
	for (unsigned long int i = 1; i <= testCount; i++)
	{
		cout << i << ".\nEncrypting the file... ";
		
		RSA::Encrypt(messageFile, cypherFile, newKeyPair.GetPublicKey());
		cout << "done!\nDecrypting the file... ";
		RSA::Decrypt(cypherFile, destFile, newKeyPair.GetPrivateKey());
		cout << "done!\n" << endl;
		test(system("diff test/message.txt "
				"test/new_message.txt"), 0);
	}
	
	cout << "\nFile encryption/decryption test finished!" << endl;
}
