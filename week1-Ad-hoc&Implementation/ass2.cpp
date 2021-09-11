    #include <bits/stdc++.h>
    using namespace std;

    #define ll  long long int
    #define vi  vector<int>
    #define vll vector<long long int>


     int divisors(int n){
        ll cnt = 0;
        for (ll i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                // If divisors are equal,
                // count only one
                if (n / i == i)
                    cnt++;
    
                else // Otherwise count both
                    cnt = cnt + 2;
                }
        }
     return cnt;
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
            ll N;
            ll count=0;
            cin>>N;
            
            for(ll i=2; i*i<=N; i++){
                // cout<<i*i<<" ";
                 if(goodnumber(i*i))
                    count++;
            }
            cout<<count<<endl;

          }

    }