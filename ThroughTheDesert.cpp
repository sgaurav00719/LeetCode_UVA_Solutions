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
#include <fstream>

using namespace std;

#include <bits/stdc++.h>
#define rep(i,n) for(auto i=0; i<(n); i++)
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
#define mx 0

char event[55];
int val[55];
int km[55];
int n;
char can(double fuel)
{
    double init = fuel;
    int cons = 0;
    int ckm = 0;
    int leek = 0;
    int i;
    for(i=0;i<n;i++)
    {
        fuel=fuel-(km[i]-ckm)*leek-(km[i]-ckm)/100.00*cons;
        if(fuel<0)
            return 0;
        if(event[i]=='F')
            cons = val[i];
        else if(event[i]=='L')
                leek++;
        else if(event[i]=='M')
                leek = 0;
        else if(event[i]=='G'&&fuel>=0)
                fuel = init;
        ckm = km[i];
    }
    return 1;
}

int main()
{
	read("input");
    char inp[100],s1[20],s2[20];
    int c,x,a;
    double hi,lo,mid;
    n = 0;
    while(gets(inp))
    {
        x = sscanf(inp,"%d %s %s %d",&a,s1,s2,&c);
        //When last line is reached
        if(x==4&&!a&&!c)
            break;
        //When goal is reached
        if(x==2&&s1[0]=='G')
        {
            km[n]=a;
            event[n]='g';
            n++;
            hi = 10000;
            lo = 0;
            while(fabs(hi-lo)>1e-9)
            {
                mid = (hi+lo)/2;
                if(can(mid))
                    hi = mid;
                else
                    lo = mid;
            }
            printf("%.3lf\n",(hi+lo)/2);
            n = 0;
        }
        else
        {
        	//This case will handle Leak,Gas station and Mechanic cases
            if(x<=3)
            {
                km[n]=a;
                event[n]=s1[0];
                n++;
            }
            if(x==4)
            {
                km[n]=a;
                event[n]=s1[0];
                val[n]=c;
                n++;
            }
        }
    }
    return 0;
}
