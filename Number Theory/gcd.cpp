#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7,inf = 1e18;

#define pb push_back
#define fr(a,b) for(int i=a;i<b;i++)

int gcd(int a,int b){
	if(b == 0) return a;

	return gcd(b,a%b);
}

