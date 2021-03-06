    #include <bits/stdc++.h>
    using namespace std;

    #define ll  long long int
    #define vi  vector<int>
    #define vll vector<long long int>


    int power(int x, unsigned int y, int p)
    {
        int res = 1;      // Initialize result
        x = x % p;  // Update x if it is more than or
                    // equal to p
        while (y > 0)
        {
            // If y is odd, multiply x with result
            if (y & 1)
                res = (res*x) % p;
    
            // y must be even now
            y = y>>1; // y = y/2
            x = (x*x) % p;
        }
        return res;
    }


    bool miillerTest(int d, int n)
    {
        // Pick a random number in [2..n-2]
        // Corner cases make sure that n > 4
        int a = 2 + rand() % (n - 4);
    
        // Compute a^d % n
        int x = power(a, d, n);
    
        if (x == 1  || x == n-1)
        return true;
    
        // Keep squaring x while one of the following doesn't
        // happen
        // (i)   d does not reach n-1
        // (ii)  (x^2) % n is not 1
        // (iii) (x^2) % n is not n-1
        while (d != n-1)
        {
            x = (x * x) % n;
            d *= 2;
    
            if (x == 1)      return false;
            if (x == n-1)    return true;
        }
    
        // Return composite
        return false;
    }


    bool isPrime(int n, int k)
        {
        // Corner cases
        if (n <= 1 || n == 4)  return false;
        if (n <= 3) return true;
    
        // Find r such that n = 2^d * r + 1 for some r >= 1
        int d = n - 1;
        while (d % 2 == 0)
            d /= 2;
    
        // Iterate given nber of 'k' times
        for (int i = 0; i < k; i++)
            if (!miillerTest(d, n))
                return false;
    
        return true;
    }


     int divisors(int n){
        int cnt = 0;
        for (int i = 1; i <= sqrt(n); i++) {
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


    int main(){
        
 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int T;
        cin>>T;
          while(T--){
            ll N;
            int count=0,nd=0;
            cin>>N;
            
            for(int i=1; i*i<=N; i++){
                // cout<<i*i<<" ";
                nd = divisors(i*i);
                if(isPrime(nd, 4))
                    count++;
                   
            }
            cout<<count<<endl;

          }
          

    }