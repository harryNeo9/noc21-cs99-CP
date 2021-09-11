    #include <bits/stdc++.h>
    using namespace std;

    #define ii  pair<int,int>
    #define vii vector<pair<int,int>>
    #define iii tuple<int,int,int>


    int main(){
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int V;
        cin>>V;

       vector<vii> AL(V, vii());                      // initialize AL
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
        
     
        
        for(int i=0; i<AL.size(); i++){
            cout<<"Neighbors of vertex "<<i<<" :\n";
             for (auto &[v, w] : AL[i]) {
                cout<<"\tEdge "<<i<<"-"<<v<<" (weight = "<<w<<")\n";
             }                   
            
        }
       
  

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

Neighbors of vertex 0 :
	Edge 0-1 (weight = 10)
	Edge 0-4 (weight = 100)
Neighbors of vertex 1 :
	Edge 1-0 (weight = 10)
	Edge 1-2 (weight = 7)
	Edge 1-4 (weight = 8)
Neighbors of vertex 2 :
	Edge 2-1 (weight = 7)
	Edge 2-3 (weight = 9)
Neighbors of vertex 3 :
	Edge 3-2 (weight = 9)
	Edge 3-4 (weight = 20)
	Edge 3-5 (weight = 5)
Neighbors of vertex 4 :
	Edge 4-0 (weight = 100)
	Edge 4-1 (weight = 8)
	Edge 4-3 (weight = 20)
Neighbors of vertex 5 :
	Edge 5-3 (weight = 5)


*/