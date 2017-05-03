/*
 * test_lambda.cpp
 *
 *  Created on: Jan 1, 2017
 *      Author: iNviNciBLe
 */

 //Program to test the C++ lambda syntax and initializer lists
 #include <iostream>
 #include <vector>

 using namespace std;

 int main()
 {
   // Test lambda
   cout << [](int m, int n) { return m + n;} (2,4) << endl;

   // Test initializer lists and range based for loop
   vector<int> V;
   V = {1,2,3,4};

   cout << "V =" << endl;
   for(auto e : V) {
     cout << e << endl;
   }

   return 0;
 }




