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


bool isPrime(int n) {
	if(n == 1) return false;

	for(int i=2;i*i<=n;i++){
		if(n%i == 0) 
			return false;
	}
	return true;
}


