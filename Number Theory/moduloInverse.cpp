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

struct Triplet{
	int x;
	int y;
	int gcd;

	void computeLdeSoln(int a,int b){
		if(b == 0) {
			// a is the gcd
			x = 1;
			y = 0;
			gcd = a;
			return;
		}
		computeLdeSoln(b,a%b);
		int _x = x, _y = y;
		x = _y; 
		y = _x - _y * (a/b);
	}
};

int moduloInverse(int a,int m){
	Triplet t;
	t.computeLdeSoln(a,m);

	if(t.gcd != 1) return -1; // no solution

	return (t.x % m + m)%m;
}

