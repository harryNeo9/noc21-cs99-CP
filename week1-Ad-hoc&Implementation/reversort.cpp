
    #include <bits/stdc++.h>
    using namespace std;

    #define ll  long long int
    #define vi  vector<int>
    #define vll vector<long long int>

    int reversort(vi &L){
        int cost=0;

        for(int i=0; i<L.size()-1; i++){

            int m = *min_element(L.begin()+i, L.end());

            auto x = find(L.begin(),L.end(),m);

            reverse(L.begin()+i, x+1);

            int j = distance(L.begin(),x);

            cost+= j-i+1;
        }

        return cost;
    }

    int main(){
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int T;
        cin>>T;
          for(int c=1; c< T+1; c++){
            int  N;
            cin>>N;
            
            vi L;
            for(int i=0; i<N;i++){
                int num;
                cin>>num;
                L.push_back(num);
            }

            
            cout<<"Case #"<<c<<": "<< reversort(L)<<endl;


          }

    }