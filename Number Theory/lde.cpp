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

// to find solutions for equations of the form ax + by = gcd(a,b)

// returns gcd(a,b)
// int gcd(int a,int b,int &x,int &y) {
// 	if(b == 0) {
// 		// a is the gcd
// 		x = 1;
// 		y = 0;
// 		return a;
// 	}

// 	int x1,y1;
// 	int g = gcd(b,a%b,x1,y1);
// 	x = y1;
// 	y = x1 - y1 * (a/b);

// 	return g;
// }

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

// to find solution for equations of the form ax + by = c
// here c = k * gcd(a,b)
pair<int,int> findIntegralSoln(int a,int b,int c) {
	Triplet t;
	t.computeLdeSoln(a,b);
	int x = t.x, y = t.y, g = t.gcd;

	return {x * c/g , y * c/g};
}

// if we have one solution to the equation ax + by = c (x0,y0) all the other solns can be calculated as 

//             x = x0 + k * b / g
//             y = y0 - k * a / g
// k ∈ I