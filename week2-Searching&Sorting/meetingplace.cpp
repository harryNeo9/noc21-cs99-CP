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
            int  N;
            cin>>N;
            
            vi L;
            for(int i=0; i<N;i++){
                int num;
                cin>>num;
                L.push_back(num);
            }

            for (int i = 0; i < N; i++)
            {
                cout<<L[i]<<" ";
            }
            cout<<endl;


          }

    }