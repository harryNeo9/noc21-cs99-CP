    #include <bits/stdc++.h>
    using namespace std;

    #define ll  long long int
    #define vi  vector<int>
    #define vll vector<long long int>

    class WarDisjointSet{
        private:
            vi p, frnds, enemy, f_rank, e_rank ,setSize;
            int numSets;
        public:
           WarDisjointSet(int N){

                frnds.assign(N,0);
                     for(int i=0; i<N; i++)
                        frnds[i]=i;
                enemy.assign(N,0);
                     for(int i=0; i<N; i++)
                        enemy[i]=i;
                
                f_rank.assign(N,0);
                e_rank.assign(N,0);

                // setSize.assign(N,0);

                // numSets=N;
            }

            int findSetFrnds(int i){
                if(frnds[i] == i)
                    return i;
                else
                    return frnds[i]=findSetFrnds(frnds[i]);
            }

            int findSetEnemy(int i){
                if(enemy[i] == i)
                    return i;
                else
                    return enemy[i]=findSetEnemy(enemy[i]);
            }

            bool areFriends(int x, int y){
                return findSetFrnds(x) == findSetFrnds(y);
            }

             bool areEnemies(int x, int y){
                return findSetEnemy(x) == findSetEnemy(y);
            }

            void setFriends(int i, int j){
                if(areFriends(i,j))
                    return;
                int x = findSetFrnds(i);
                int y=findSetFrnds(j);

                if(f_rank[x] > f_rank[y])
                    swap(x,y);
                
                frnds[x]=y;
            
                if(f_rank[x] == f_rank[y])
                    f_rank[y]++;
                
                // setSize[y]+=setSize[x];
                // numSets--;
            }

            void setEnemies(int i, int j){
                if(areEnemies(i,j))
                    return;
                int x = findSetEnemy(i);
                int y=findSetEnemy(j);

                if(e_rank[x] > e_rank[y])
                    swap(x,y);
                
                enemy[x]=y;
            
                if(e_rank[x] == e_rank[y])
                    e_rank[y]++;
                
                // setSize[y]+=setSize[x];
                // numSets--;
            }
    };


    int main(){
        
 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin>>n;

        WarDisjointSet WDS(n);

        int c,x,y;
        while(cin>>c){
            cin>>x>>y;
            
            if(c == 1){
                WDS.setFriends(x,y);
            }else if(c == 2){
                WDS.setEnemies(x,y);
            }else if(c == 3){
                if(WDS.areFriends(x,y))
                    cout<<1<<endl;
                else
                    cout<<0<<endl;

            }else{
                if(WDS.areEnemies(x,y))
                    cout<<1<<endl;
                else
                    cout<<0<<endl;
            }
        }
        

    }