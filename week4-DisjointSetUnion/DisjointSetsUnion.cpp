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

        int n,m;
        cin>>n>>m;

        UnionFind UF(n+1);

        while(m--){
            string s;
            cin>>s;

            int x,y;
            cin>>x>>y;

            if(s == "union")
                UF.UnionSet(x,y);
            else{
                if(UF.isSameSet(x,y))
                    cout<<"YES"<<endl;
                else
                {
                    cout<<"NO"<<endl;
                }
                
            }

        }

    }