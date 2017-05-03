/*
 * invertedtriangle.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: iNviNciBLe
 */




#include <iostream>
using namespace std;
int main()
{
    int i,j,rows;
    cout<<"Enter the number of rows: ";
    cin>>rows;
    for(i=rows;i>=1;--i)
    {
        for(j=1;j<=i;++j)
        {
           cout<<"* ";
        }
        cout<<"\n";
    }
    return 0;
}
