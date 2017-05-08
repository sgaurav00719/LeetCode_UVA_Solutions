/*
 * arbitrag.cpp
 *
 *  Created on: May 7, 2017
 *      Author: iNviNciBLe
 */
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
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <fstream>

using namespace std;

#include <bits/stdc++.h>
#define rep(i,n) for(size_t i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define rite(x) freopen(x,"w",stdout);
#define read(x) freopen(x,"r",stdin);
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define clr clear()
#define inf (1<<30)
#define ins insert
#define xx first
#define yy second
#define eps 1e-9
typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int, int> mii;
typedef map<st, int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;


/*
 * import java.util.Scanner;

public class Solution2
{

    int[] arbitrage(String[] inputs){

        float capital=100000.0f;
        float t =0.0f;
        int len = inputs.length;
        int[] output = new int[len];

        for(int i=0; i<len; i++){
            String[] parts = inputs[i].split(" ");
            float[] temp = new float[3];
            t = capital;
            for(int j=0; j<3;j++){
                t /=  Float.parseFloat(parts[j]);
            }

            output[i] = t<capital?0:(int)(t - capital);

        }

        return output;
    }

    public static void main(String[] args) {

        // get the number of lines
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] inputs = new String[n];
        for (int i = 0; i < n; i++) {
            String s = sc.next();
            inputs[i] = s;
        }

        Solution2 s = new Solution2();
        System.out.print(s.arbitrage(inputs));
    }

}*/


vector<int> arbitrage(vector<string>& inputs){
	double capital=100000.0;
	double t = 0.0;
	int len = inputs.size();
	vector<int> output;
	for(int i=0; i<len; i++){
		istringstream iss(inputs[i]);
		vector<string> parts;
		string s;
		while ( getline( iss, s, ' ' ) ) {
			parts.push_back(s);
		}
		t = capital;
		for(int j=0; j<3;j++){
			t /=  stod(parts[j]);
		}
		output.push_back(t<capital?0:(int)(t - capital));
	}
	return output;
}

int main(){
	read("test");
	string N;
	getline(cin,N);
	vector<string> in;
	for(int i = stoi(N); i > 0; i--){
		string line;
		getline(cin,line);
		in.push_back(line);
	}
	vector<int> res = arbitrage(in);
	for(auto i : res) cout << i << endl;
	return 0;
}



