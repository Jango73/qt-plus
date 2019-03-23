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
 * 				main.cpp
 * 
 * A sample program used to demonstrate the functionality of the library. 
 * 
 * Author: Nedim Srndic
 * Release date: 14th of March 2008
 * 
 * ****************************************************************************
 */

#include <cstdlib>	//srand()
#include <iostream>	//cout
#include <ctime>	//time()
#include <cstring>	//strcmp()
#include "test.h"	//testing functions
#include "RSA.h"	//GenerateKeyPair()
#include "PrimeGenerator.h"	//Generate()

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char *argv[])
{
	//randomize the random number generator
	std::srand(time(NULL));
	
	if (argc > 1)	//arguments present
	{
		void parseParams(int argc, char *argv[]);
		parseParams(argc, argv);
		return EXIT_SUCCESS;
	}
	else	//no arguments
	{
		void printUsage();
		printUsage();
		return EXIT_SUCCESS;
	}
}

void printUsage()
{
	cout <<  
	"Usage: rsa [OPTION] [ARGUMENT]" << endl << 
	"rsa is a command-line frontend to rsalib. rsalib provides RSA encryption,"
	" decryption and digital signature." << endl << 
	endl << 
	"Available options: " << endl <<
	endl << 
	"    genkey LENGTH [N]" << endl << 
	"Generate and print a RSA key. The generated key is LENGTH " 
	"digits long and is generated in N iterations (default N = 3 is fine). "
	"LENGTH and N must be positive decimal integers." << endl << 
	endl <<
	"    genprime LENGTH [N]" << endl << 
	"Generate and print a prime number. The generated prime is LENGTH " 
	"digits long and is generated in N iterations (default N = 3 is fine). "
	"LENGTH and N must be positive decimal integers." << endl << 
	endl << 
	"    test" << endl << 
	"Run preconfigured tests (development version only)." << endl << 
	endl << 
	"Exit status is 0 if OK, otherwise not 0." << endl;
}

void exitError(const char *message = "\0")
{
	cout << message << endl;
	printUsage();
	std::exit(EXIT_FAILURE);
}

void missingArgumentError(const char *argName)
{
	cout << "Missing argument: '" << argName << "'." << endl;
	exitError();
}

void test()
{
	try
	{
		TestBigIntFunctions();
		TestBigIntOperators();
		FactorialBenchmark();
		RandomBigIntTest(1);
		RandomBigIntDivisionTest(1);
		TestPrimeGenerator(1, 10);
		TestKeyGeneration(1, 8);
		TestEncryptionDecryption(1, 8);
		TestFileEncryptionDecryption(1, 8);
	}
	catch (const char errorMessage[])
	{
		exitError(errorMessage);
	}
	catch (...)
	{
		exitError("Unknown error.");
	}
}

void genkey(unsigned long int digits, unsigned long int iterations = 0)
{
	try
	{
		if (iterations != 0)
			cout << RSA::GenerateKeyPair(digits, iterations) << endl;
		else
			cout << RSA::GenerateKeyPair(digits) << endl;
	}
	catch (const char errorMessage[])
	{
		exitError(errorMessage);
	}
	catch (...)
	{
		exitError("Unknown error.");
	}
}

void genprime(unsigned long int digits, unsigned long int iterations = 0)
{
	try
	{
		if (iterations != 0)
			cout << PrimeGenerator::Generate(digits, iterations) << endl;
		else
			cout << PrimeGenerator::Generate(digits) << endl;
	}
	catch (const char errorMessage[])
	{
		exitError(errorMessage);
	}
	catch (...)
	{
		exitError("Unknown error.");
	}
}

void parseParams(int argc, char *argv[])
{
	if (strcmp(argv[1], "genkey") == 0)	//generate and print a RSA key
	{
		long int digits = 0;
		if (argc > 2)
		{
			digits = std::atol(argv[2]);
			if (digits == 0)
				exitError("'LENGTH' must be a positive integer.");
		}
		else
			missingArgumentError("LENGTH");
		if (argc > 3)
		{
			long int iterations = std::atol(argv[3]);
			if (iterations <= 0)
				exitError("'N' must be a positive integer.");
			
			genkey(digits, iterations);
		}
		else
			genkey(digits);
	}
	else if (strcmp(argv[1], "genprime") == 0)
	{
		long int digits = 0;
		if (argc > 2)
		{
			digits = std::atol(argv[2]);
			if (digits == 0)
				exitError("'LENGTH' must be a positive integer.");
		}
		else
			missingArgumentError("LENGTH");
		if (argc > 3)
		{
			long int iterations = std::atol(argv[3]);
			if (iterations <= 0)
				exitError("'N' must be a positive integer.");

			genprime(digits, iterations);
		}
		else
			genprime(digits);
	}
	else if (strcmp(argv[1], "test") == 0)	//run all the tests
		test();
	else
		exitError("Unrecognized option.");
}
