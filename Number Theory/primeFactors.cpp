
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
#define fr(k,a,b) for(ll k=a;k<b;k++)
#define rfr(k,a,b) for(ll k=a;k>=b;k--)
#define raf(k,container) for(auto &k : container)


// Time complexity -> O(sqrt(N))
// Only use this for the prime factorisation of a single number. Not suitable when queries are given
map<int,int> primeFactorsWithPowers(int n) {
	map<int,int> pf;

	for(int i=2;i*i<=n;i++) {
		while(n % i == 0){
			pf[i]++;
			n /= i;
		}
	}
	if(n > 1) pf[n]++;

	return pf;
}


// Time Complexity -> O(N log(logN) + Q*logN)
// Suitable when queries are given
const int N = 2e5;
int spf[N+1]; // this array stores the smallest prime factor of every number

void createSPF(int n = N) {
	for(int i=1;i<=n;i++) {
		spf[i] = i;
	}

	// time complexity of this loop is O(n * log(log n))
	for(int i=2;i*i<=n;i++){
		if(spf[i] == i) {
			for(int j=i*i;j<=n;j+=i){
				if(spf[j] == j)
					spf[j] = i;
			}
		}
	}
}
createSPF(N);

map<int,int> primeFactorsWithPowers(int n) {
	map<int,int> pf;

	// time complexity of this loop is O(log n)
	while(n != 1) {
		pf[spf[n]]++;
		n = n / spf[n];
	}

	return pf;
}



