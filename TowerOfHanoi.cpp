/*
 * TowerOfHanoi.cpp
 *
 *  Created on: Feb 18, 2017
 *      Author: iNviNciBLe
 */
#include<iostream>
using namespace std;

void towers(int,char,char,char);
int count = 0;
int main(){
	int num;

	cout<<"Enter the number of disks : ";
	cin>>num;
	cout<<"The sequence of moves involved in the Tower of Hanoi are :\n";
	towers(num, 'A', 'C', 'B');
	cout << "\nTotal number of steps : " << count;
	return 0;
}

void towers(int num, char frompeg, char topeg, char auxpeg)
{
	count++;
    if (num == 1)
    {
        cout<<"\n Move disk 1 from peg "<<frompeg<<" to peg "<<topeg;
        return;
    }
    towers(num - 1, frompeg, auxpeg, topeg);
    cout<<"\n Move disk "<<num<<" from peg "<<frompeg<<" to peg "<<topeg;
    towers(num - 1, auxpeg, topeg, frompeg);
}


