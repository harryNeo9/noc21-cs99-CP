    #include <bits/stdc++.h>
    using namespace std;

    #define ll  long long int
    #define vi  vector<int>
    #define vll vector<long long int>

    class UnionFind{
        private:
            vi p, rank, setSize;
            int numSets;
        public:
            UnionFind(int N){

                p.assign(N,0);

                for(int i=0; i<N; i++)
                    p[i]=i;
                
                rank.assign(N,0);

                setSize.assign(N,0);

                numSets=N;
            }

            int findSet(int i){
                if(p[i] == i)
                    return i;
                else
                    return p[i]=findSet(p[i]);
            }

            bool isSameSet(int x, int y){
                return findSet(x) == findSet(y);
            }

            void UnionSet(int i, int j){
                if(isSameSet(i,j))
                    return;
                int x = findSet(i);
                int y=findSet(j);

                if(rank[x] > rank[y])
                    swap(x,y);
                
                p[x]=y;
            
                if(rank[x] == rank[y])
                    rank[y]++;
                
                setSize[y]+=setSize[x];
                numSets--;
            }
    };


    int main(){
        
 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n,t;
        cin>>n>>t;

        UnionFind UF(n);  // 0 to n-1

        while(t--){
           int type, x,y;
           cin>>type>>x>>y;
           
           if(type == 1){
                if(UF.isSameSet(x,y))
                    cout<<"1"<<endl;
                else
                {
                    cout<<"0"<<endl;
                }
           }else{
               UF.UnionSet(x,y);
           }
        }

    }