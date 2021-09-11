    #include <bits/stdc++.h>
    using namespace std;

    #define ll  long long int
    #define vi  vector<int>
    #define vll vector<long long int>


    int main(){
        
 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int T;
        cin>>T;
          while(T--){
            int  N,X;
            cin>>N>>X;

            int maxslice=0;
            for(int i=X; i>0; i--){
                if(maxslice<N%i)
                    maxslice=N%i;
            }
            cout<<maxslice<<endl;

          }

    }