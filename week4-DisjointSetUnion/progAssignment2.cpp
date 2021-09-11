    #include <bits/stdc++.h>
    using namespace std;

    #define ll  long long int
    #define vi  vector<int>
    #define vll vector<long long int>
    #define vpi vector<pair<int,int>>

    class UnionFind{
        public:
            vi p, weight, rank, setWeightSum, setSize;
            int numSets;
        
            UnionFind(int N){

                p.assign(N,0);

                for(int i=0; i<N; i++)
                    p[i]=i;
                
                weight.assign(N,0);

                setWeightSum.assign(N,0);
                
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

            void deleteUnionSet(int i, int j){

            }
    };


    int main(){
        
 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n,m,q;
        cin>>n>>m>>q;
        
        UnionFind UF(n+1);
        vpi edges(m+1);  // vector of pair for storing edges

        for(int i=1; i<=n; i++ ){  // n weights follows
            int w;
            cin>>w;
            UF.weight[i]=w;
        }

        for(int i=1; i<=m; i++){  // m edges follows
            int from,to;
            UF.UnionSet(from,to);  // connecting the two egdes
            cin>>from>>to;
            edges.push_back(make_pair(from,to));
        }

        // q queries follows
        while(q--){
            int op;  // operation 1 or 2
            cin>>op;

            if(op == 1){
                int i;
                cin>>i;
                
                // delete ith edge
                UF.deleteUnionSet(edges[i].first, edges[i].second);

            }else{
                int i,x;
                cin>>i>>x;
                // change weight at index i to x
                UF.weight[i] = x;
            }

            // Output Q lines, with one integer in each line. 
            //The i-th line should contain an integer corresponding 
            //to the maximum weight among all the connected components, after i updates.

            auto it = max_element(UF.setWeightSum.begin(), UF.setWeightSum.end());
            cout<<*it<<endl;
        }


    }