rsa v1.1 readme file

This is the readme file for the rsa project, version 1.1.
The project homepage can be found at
 
http://code.google.com/p/rsa/ 

WHAT IS rsa?

rsa is a computer program that implements the RSA algorithm. It is entirely 
written in standard C++ (the 1998 version), using only the standard libraries. 
There are a lot of implementations of RSA out there, and some are even 
open-source and very popular (OpenSSL). The goal for rsa is to be complete and 
easy to understand. 'Complete' means that the entire functionality of the RSA 
algorithm (including encryption, decryption, key generation and digital 
signature) should be implemented. rsa is licensed under the GPLv3 software 
license <http://www.gnu.org/licenses/>. 

WHAT IS THE RSA ALGORITHM?

The RSA algorithm is a cryptography algorithm used to encrypt and decrypt 
information (messages, files etc.) or for digital signing. You can find out more
about the RSA algorithm on these websites: 

http://en.wikipedia.org/wiki/RSA
http://www.di-mgt.com.au/rsa_alg.html

PROJECT STATUS

Currently, the project has only one member. If you are interested to work on 
rsa, contact me.
 
Project features in the current version: 
  - RSA encryption (string and file)
  - RSA decryption (string and file)
  - RSA key generation
  - Command line interface for key and prime generation and benchmarking
  - Automated source code testing
  - Automated key and prime generation benchmarking with result visualization

Still to be done:
  - Implement digital signatures
  - Optimize the BigInt class (the digits should be stored as 32 or 64-bit 
  numbers, depending on the platform)
  - Generate more secure keys (there are a number of known vulnerabilities that 
  can be avoided when generating RSA keys)
  - Implement some more multiplication algorithms and the logic that should 
  choose the best at run-time, depending on the size of the operands 
  (candidates: 1. Toom-Cook 2. Schonhage-Strassen 3. Furer)
  - Improve source code readability (some parts are messy, like BigInt::divide)
  - Make visual front-ends in many different environments

PROJECT CONTENTS

/docs - Home to the documentation. (see DOCUMENTATION) 
  - readme.txt - This file. 
  - rsa.pdf - A paper on the project and RSA in general. 
/source - The source code can be found here. (see SOURCE CODE)
  - RSA.h, RSA.cpp - The RSA class. 
  - PrimeGenerator.h, PrimeGenerator.cpp - The PrimeGenerator class. 
  - KeyPair.h, KeyPair.cpp - The KeyPair class. 
  - Key.h, Key.cpp - The Key class.  
  - BigInt.h, BigInt.cpp - The BigInt class.
  - test.h, test.cpp - Test functions. 
  - main.cpp - The main program. 
/test - Contains files used for testing and benchmarking. (see TESTING AND 
BENCHMARKING)
  - message.txt - A sample message. 
  - message.big.txt - A sample message, 2kB. 
  - timekeys.sh - A linux shell script for key generation benchmarking. 
  - timekeys.sci - Scilab code for key generation benchmark 
  result visualization. 
  - timeprimes.sh - A linux shell script for prime generation benchmarking. 
  - timeprimes.sci - Scilab code for prime generation benchmark 
  result visualization.  

DOCUMENTATION

The best source of documentation is the source code itself. It is mostly well 
documented. There is a 40-page paper on the project and the theory behind 
the RSA algorithm in the /docs folder, called rsa.pdf, but it's currently only
available in Bosnian language (if you are interested in reading it contact me 
and I will hopefully find some time to translate it to English). Also, there is 
a short presentation coming soon.

SOURCE CODE

The source code is organized in 13 files: 5 classes, testing functions and the 
main program. 

Classes:
  - RSA - Provides static methods for RSA encryption, decryption and key 
  generation.
  - PrimeGenerator - Provides static methods for random or prime number 
  generation. Used by the RSA class for key generation and by main for 
  benchmarking.
  - KeyPair - Stores a RSA public/private key pair. Used by RSA for key 
  generation and by every object that wants to use RSA services as a key 
  container.
  - Key - Stores a single public or private RSA key. Used by RSA for key 
  generation and by KeyPair for key storage.
  - BigInt - A data structure for storing arbitrary size integers and for 
  arithmetic operations using those integers. Used by Key for key exponent and 
  key modulus storage. 

Testing functions are used to test all the classes.

The main program is a command line interface. It parses the input arguments 
and acts according to them.

Detailed information can be found in source code comments.

TESTING AND BENCHMARKING

Testing and benchmarking functions rely on a few files located in the /test 
folder. 

The testing function test::TestFileEncryptionDecryption uses message.txt as an 
example message to encrypt. The result is saved as cyphertext.txt and then 
decrypted as new_message.txt. message.big.txt is a sample message, but a bit 
bigger one. 

There are two benchmarks implemented: prime generation and key generation 
benchmarks. They rely on scilab (an open-source scientific software package 
for numerical computation), and can only be ran on POSIX systems. 
The benchmarks can be run by running the timeprimes.sh or timekeys.sh shell 
scripts, without parameters or with two parameters representing a range of 
numbers. The numbers from that range are used for input in the main program, 
and represent prime number length or key length, depending on the benchmark 
selected. The scripts call the main program one time for each number in the 
given range, measuring the time needed for the program to successfully finish 
the task. The results of each run are stored in an intermediate file called 
timeprimes.dat or timekeys.dat, and the individual primes or keys are stored in 
primes.dat or keys.dat. Then a scilab script, called timeprimes.sci or 
timekeys.sci is called, to plot a graph and export it to timeprimes.gif or 
timekeys.gif.

CONTACT

Author: Nedim Srndic (my email address can be found on the project homepage)
13th of September, 2008
