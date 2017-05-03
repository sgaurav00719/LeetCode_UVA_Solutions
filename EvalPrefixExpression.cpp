/*
 * EvalPrefixExpression.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: iNviNciBLe
 */




#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

struct bad_operator : public std::logic_error {
    bad_operator(char ch)  :
        std::logic_error(std::string("Bad operator: ") + ch)
    {}
};

int apply(char op, int a, int b) {
    switch (op) {
       case '+': return a + b;
       case '-': return a - b;
       case '/': return a / b;
       case '*': return a * b;
       default: throw bad_operator(op);
    }
}
//Pass by reference
int expression(char *&input) {
    char op = *input++;

    if (isdigit(op))
       return op - '0';

    int a = expression(input);
    int b = expression(input);
    return apply(op, a, b);
}


int main() {
    char *input="+45";
    std::cout << expression(input);
    return 0;
}
