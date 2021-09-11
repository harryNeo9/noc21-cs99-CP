/*   Week 1: Programming Assignment 2
Swayam likes prime numbers a lot. He calls a number `good` if the number of divisors 
(including 1 and the number itself) of this number is an odd prime.
Help him find the number of `good` numbers in the range from 1 to N 
(both end points inclusive).
    
Input
    The first line of each test case contains an integer T denoting the number of test cases. The description of T test cases follows.
    The only line of each test case contains an integer N.
Output
    For each test case, output an integer in a new line, corresponding to the answer of the problem.

Constraints
    1 ≤ T ≤ 100
    1 ≤ N ≤ 10^12
    
*/
    #include <bits/stdc++.h>
    using namespace std;

    #define ll  long long int
    #define vi  vector<int>
    #define vll vector<long long int>

    const ll maxn = 1e12+1;

    int divisors(int n){
        const int maxn = 100;
        int divisor_count[maxn] {0};
        for(int i=1; i<maxn; i++){
            for(int j=i; j<maxn; j+=i){
                divisor_count[j]+=i;
            }
        }
        int d = divisor_count[n];
        return d;
    }

    bool isoddprime(ll nd){
        bool flag=1;
        if(nd<=2)
            return false;
        else{
            for(ll i=2; i<=ceil(sqrt(nd)); i++){
                if(nd%i == 0)
                    flag=0;
            }
        }
        return flag;
    }

    bool goodnumber(ll n){
        ll nd = divisors(n); //return the number of divisors of n

        if(isoddprime(nd)) // checks if no. of divisors is odd prime
            return true;
        else
            return false;

    }

    int main(){
        
 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int T;
        cin>>T;
          while(T--){
            ll N,count=0;
            cin>>N;
            
            for(ll i=1; i<=N; i++){
                if(goodnumber(i))
                    count++;
            }

            cout<<count<<endl;
            divisors(N);
            

          }

    }