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
 * 				test.h
 * 
 * Author: Nedim Srndic
 * Release date: 14th of March 2008
 * 
 * Header file containing declarations of test functions.  
 * 
 * ****************************************************************************
 */
 
#ifndef TEST_H_
#define TEST_H_

void pauseScreen();

/*CONSTRUCTOR, DESTRUCTOR, ASSIGNMENT AND STREAM OUTPUT OPERATOR TEST*/
void TestBigIntFunctions();
/*				ARITHMETIC AND COMPARISON OPERATOR TEST	*/
void TestBigIntOperators();
/*				FACTORIAL COMPUTATION BENCHMARK			*/
void FactorialBenchmark();
/*				RANDOM TEST GENERATOR					*/
void RandomBigIntTest(unsigned long int testCount);
/*				RANDOM DIVISION TEST GENERATOR			*/
void RandomBigIntDivisionTest(unsigned long int testCount);
/*				PRIME GENERATOR TEST					*/
void TestPrimeGenerator(unsigned long int testCount, 
						unsigned long int digitCount = 10, 
						unsigned long int iterationCount = 3);
/*				KEY GENERATOR TEST						*/
void TestKeyGeneration(	unsigned long int testCount, 
						unsigned long int keyLength = 20);
/*				ENCRYPTION/DECRYPTION TEST				*/
void TestEncryptionDecryption(	unsigned long int testCount, 
								unsigned long int keyLength = 6);
/*				FILE ENCRYPTION/DECRYPTION TEST			*/
void TestFileEncryptionDecryption(	unsigned long int testCount, 
									unsigned long int keyLength = 12);

#endif /*TEST_H_*/
