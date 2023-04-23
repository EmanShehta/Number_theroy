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
int binaryExponentiation(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n%2==1){result=result*x;}
        x=x*x;
        n=n/2;
    }
    return result;
}
int modularExponentiation(int x,int n,int m)
{
    int result=1;
    while(n>0)
    {
        if(n%2==1){result=(result*x)%m;}
        x=(x*x)%m;
        n=n/2;
    }
    return result;
}
ll modularExponentiation_lastmodified(ll x,ll n,ll m)
{
    ll result=1;
    while(n>0)
    {
        if(n%2==1){result=mul(result,x,m);}
        x=mul(x,x,m);
        n=n/2;
    }
    return result;
}
void factorization(int n){

    for (int i=1;i*i<=n;i++)
    {
        if (n%i==0)
        {
            cout<<i<<" ";
            if (i*i!=n)
            {
                cout<<n/i;
            }
            cout<<endl;
        }
    }
}
void prime_factorization(int n){
    vector<int>v;

    for (int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            n/=i;
            v.push_back(i);
            cout<<n<<" ";
        }
    }
    if (n!=1)
    {
        v.push_back(n);
    }
    for (int i=0;i<v.size();i++)
    {
       // cout<<v[i]<<" ";
    }
}
ll gcd(ll a,ll b)
{
    while(b!=0)
    {
        ll a2=a;
        a=b;
        b=a2%b;
    }
    return a;
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}

void sieve()
{
    composite[0]=composite[1]=1;
    for (int i=2;i*i<=sz;i++)
    {
        if (!composite[i])
        {
            for (int j=i*i;j<=sz;j+=i)
            {
                composite[j]=1;
            }
        }
    }
}
void linear_sieve()
{
    composite[0]=composite[1]=1;
    for (int i=2; i<=sz; ++i)
    {
        if (!composite[i])
        {
            prime.push_back(i);
        }
        for (int j=0; j<(int)prime.size()&&i*prime[j]<=sz; ++j)
        {
            composite[i * prime[j]] = 1;
            if (i%prime[j]==0) break;

        }
    }
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
   // extendedEuclid_iterative(a,m);
    return (x%m+m)%m;
}
int modinverse_fermat (int a,int m)
{
    return modularExponentiation(a,m-2,m);
}


