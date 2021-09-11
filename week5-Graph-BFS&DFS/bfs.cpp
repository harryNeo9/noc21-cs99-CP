    #include <bits/stdc++.h>
    using namespace std;

    #define vi vector<int>
    #define ii  pair<int,int>
    #define vii vector<pair<int,int>>
    #define iii tuple<int,int,int>
    
    const int INF = 1e9;
    vector<vii> AL;  // adjoint list global declaration

    void bfs(int V, int source){
        vi p(V,-1); // parent vector
        vi dist(V,INF);  // distance vector
        dist[source] =0;

        queue<int> q;
        q.push(source);
        
        int layer =-1;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            if(dist[u] != layer){
                cout<<"\nLayer :"<<dist[u];
            }
            layer = dist[u];
            cout<<"\tvisit "<<u;

            for(auto &[v,w] : AL[u]){
                if(dist[v] == INF){
                    dist[v] = dist[u]+1;
                    p[v] =u;
                    q.push(v);
                }
            }
        }
    }

    int main(){
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int V;
        cin>>V;

       //    vector<vii> AL(V, vii()); 

        AL.assign(V, vii());                         // initialize AL
        for (int u = 0; u < V; ++u) {
            int total_neighbors; 
            cin>>total_neighbors;
            while (total_neighbors--) {
                int v, w; 
                cin>>v>>w;
                --v;     // to 0-based indexing
                AL[u].emplace_back(v, w);
            }
        }
        
        cout<<"BFS :";
        bfs(V,0);

        
        // for(int i=0; i<AL.size(); i++){
        //     cout<<"Neighbors of vertex "<<i<<" :\n";
        //      for (auto &[v, w] : AL[i]) {
        //         cout<<"\tEdge "<<i<<"-"<<v<<" (weight = "<<w<<")\n";
        //      }                   
            
        // }
       
  

    }



/*

INPUT:
6
2 2 10 5 100
3 1 10 3 7 5 8
2 2 7 4 9
3 3 9 5 20 6 5
3 1 100 2 8 4 20
1 4 5

OUTPUT:

BFS :
Layer :0	visit 0
Layer :1	visit 1	visit 4
Layer :2	visit 2	visit 3
Layer :3	visit 5

*/