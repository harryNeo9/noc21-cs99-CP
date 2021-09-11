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

        int N;
        cin>>N;

  
       AL.assign(N+1, vii());    
       vi w(N+1,0);   
       vi p(N+1,0);    
       for(int i=1; i<=N; i++){
           int weight;
           cin>>weight;
           w[i] = weight;
       }  

       for(auto x: w)
            cout<<x<<" ";
    cout<<endl;

       for(int i=1; i<=N; i++){
         int parent_i;
         cin>>parent_i;
         cout<<parent_i<<" ";
         p[i] = parent_i;
       
            // AL[i].emplace_back(p, 0);
            // AL[p].emplace_back(i, 0);
       }

    //    for(int i=1; i<=N; i++){
    //        int parent_i = p[i];
    //          AL[i].emplace_back(parent_i, 0);
    //         AL[parent_i].emplace_back(i, 0);
    //    }
       
        // cout<<"BFS :";
        // bfs(V,0);

        
        // for(int i=1; i<=AL.size(); i++){
        //     cout<<"Neighbors of vertex "<<i<<" :\n";
        //      for (auto &[v, w] : AL[i]) {
        //          cout<<"Hello\n";
        //         cout<<"\tEdge "<<i<<"-"<<v<<" (weight = "<<w<<")\n";
        //      }                   
            
        // }
       
  

    }



/*


INPUT :

13 16
0 1
1 2
2 3   
0 4 
1 5 
2 6
3 7 
5 6
4 8
8 9
5 10 
6 11 
7 12 
9 10 
10 11
11 12

OUTPUT:

BFS :
Layer :0	visit 0
Layer :1	visit 1	visit 4
Layer :2	visit 2	visit 5	visit 8
Layer :3	visit 3	visit 6	visit 10	visit 9
Layer :4	visit 7	visit 11
Layer :5	visit 12


Neighbors of vertex 0 :
	Edge 0-1 (weight = 0)
	Edge 0-4 (weight = 0)
Neighbors of vertex 1 :
	Edge 1-0 (weight = 0)
	Edge 1-2 (weight = 0)
	Edge 1-5 (weight = 0)
Neighbors of vertex 2 :
	Edge 2-1 (weight = 0)
	Edge 2-3 (weight = 0)
	Edge 2-6 (weight = 0)
Neighbors of vertex 3 :
	Edge 3-2 (weight = 0)
	Edge 3-7 (weight = 0)
Neighbors of vertex 4 :
	Edge 4-0 (weight = 0)
	Edge 4-8 (weight = 0)
Neighbors of vertex 5 :
	Edge 5-1 (weight = 0)
	Edge 5-6 (weight = 0)
	Edge 5-10 (weight = 0)
Neighbors of vertex 6 :
	Edge 6-2 (weight = 0)
	Edge 6-5 (weight = 0)
	Edge 6-11 (weight = 0)
Neighbors of vertex 7 :
	Edge 7-3 (weight = 0)
	Edge 7-12 (weight = 0)
Neighbors of vertex 8 :
	Edge 8-4 (weight = 0)
	Edge 8-9 (weight = 0)
Neighbors of vertex 9 :
	Edge 9-8 (weight = 0)
	Edge 9-10 (weight = 0)
Neighbors of vertex 10 :
	Edge 10-5 (weight = 0)
	Edge 10-9 (weight = 0)
	Edge 10-11 (weight = 0)
Neighbors of vertex 11 :
	Edge 11-6 (weight = 0)
	Edge 11-10 (weight = 0)
	Edge 11-12 (weight = 0)
Neighbors of vertex 12 :
	Edge 12-7 (weight = 0)
	Edge 12-11 (weight = 0)


*/