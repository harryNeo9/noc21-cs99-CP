    #include <bits/stdc++.h>
    using namespace std;

    #define ll  long long int
    #define vi  vector<int>
    #define vll vector<long long int>

    int  C,D,L;

    // x - number of cats riding dogs
    // x <= min(cats, dogs*4)
    // legs = (cats+dogs -x)*4
    
    bool solvesubtask(){
        if(L%4 != 0)
            return false;
        
        long long x = C+D;
        x -= L/4;
        return x>=0 && x<= min(C, D*4);
    }

    int main(){
        
 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int T;
        cin>>T;
          while(T--){
            
            cin>>C>>D>>L;

            bool status = solvesubtask();
            
            puts(status ? "yes" : "no");
           


          }

    }