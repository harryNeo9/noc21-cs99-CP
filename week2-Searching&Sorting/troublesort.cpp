    #include <bits/stdc++.h>
    using namespace std;

    #define ll  long long int
    #define vi  vector<int>
    #define vll vector<long long int>

    vi troublesort(vi &L){
        int n = L.size();
        vi odd, even, arr(n,0);
        for(int i=0; i<n; i++){
            if(i%2==0)
                even.push_back(L[i]);
            else
                odd.push_back(L[i]);
        }

        sort(even.begin(),even.end());
       
        sort(odd.begin(),odd.end());

        vi outputarr;

        for(int i=0; i<n; i++){
            if(i%2 ==0){
                outputarr.push_back(even[0]);
                even.erase(even.begin());
            }else{
                outputarr.push_back(odd[0]);
                odd.erase(odd.begin());
            }
        }
        return outputarr;
       
    }

    int main(){
        
 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int T;
        cin>>T;
         for(int c=1; c<=T; c++){
            int  N=0;
            cin>>N;
            
            vi L;
            for(int i=0; i<N;i++){
                int num;
                cin>>num;
                L.push_back(num);
            }

           L = troublesort(L);
            bool flag=true;
            int pos=0;
            for (int i = 0; i < N-1; i++)
            {
               if(L[i]>L[i+1]){
                   flag=false;
                   pos=i;
                   break;
               }
            }
           if(flag){
               cout<<"Case #"<<c<<": OK"<<"\n";
           }else{
               cout<<"Case #"<<c<<": "<<pos<<"\n";
           }


          }

    }