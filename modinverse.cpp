#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define dd double
const int sz=1e6+10;
const int OO=0x3f3f3f3f;
bool composite[sz+1];
vector<int>prime;
ll M=1e9+7;
ll add(ll a,ll b,ll m)
{
    return ((a%m)+(b%m))%m;
}
ll mul(ll a,ll b,ll m)
{
  return ((a%m)*(b%m))%m;
}

int extendedEuclid_recursive(int a, int b, int& x, int& y) {
    if (b==0) {
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d=extendedEuclid_recursive(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}

int extendedEuclid_iterative(int a, int b, int& x_prev, int& y_prev)
{
    x_prev=1,y_prev=0;
    int x=0,y=1;
    while (b) {
        int q=a/b;
        tie(x,x_prev)=make_tuple(x_prev-q*x,x);
        tie(y,y_prev)=make_tuple(y_prev-q*y,y);
        tie(a,b)=make_tuple(b,a%b);

    }

    return a;
}
int modinverse (int a,int m)
{
    a=a%m;
    for (int i = 1; i < m; ++i) {
        if((a*i)%m==1)
            return i;
    }
}
int x;
int modinverse_bezouts_therom (int a,int m)
{
    int x, y;
    int g = extendedEuclid_iterative(a, m, x, y);
    if (g != 1) {
        cout << "No solution!";
    }
    else {
        x = (x % m + m) % m;
        cout << x << endl;
    }
}
int modinverse_fermat (int a,int m)
{
    return modularExponentiation(a,m-2,m);
}


