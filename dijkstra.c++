#include<bits/stdc++.h>
using namespace std;
#define MAX_VALUE 10'000'000

// directed acyclic graph(DAG)
// vertices are form [0 , V-1]

//pair<path,shortestdistance>                            vector<<u , v , weight>> 
int dijkstra(int source , int end , vector<vector<int>>& edges , int V , vector<int>& path){

    // preparing an adjacency list  pair< w , v >
    vector< vector< pair<int,int> > > adj(V);

    for(auto edge : edges)
        adj[edge[0]].push_back({edge[2],edge[1]});
                    
                //  pair< w , u >
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > minheap;
    vector<int> distance(V , MAX_VALUE);
    vector<int> parent(V , -1);
    
    distance[source] = 0;
    minheap.push({0,source});

    while(!minheap.empty()){

        int w = minheap.top().first;
        int u = minheap.top().second;
        minheap.pop();

        if(w <= distance[u])
            for(auto edge : adj[u])
                if(distance[edge.first] > distance[u] + edge.second)
                    distance[edge.first] = distance[u] + edge.second ,
                    parent[edge.first] = u,
                    minheap.push({distance[edge.first],edge.first}) ;


    }
    
    // to detect the path we will take help of the parent array and move in opposite order
    int next = end;
    
    while(next != -1)
        path.push_back(next) , next = parent[next];
    
    reverse(path.begin(),path.end());
    
    return distance[end];
}

int main(){

    int V=4 , source=0 , end=3;
    vector<int> path;
    vector<vector<int>> edges = { {0,1,1} , {0,2,4} , {1,2,2} , {1,3,6} , {2,3,3} };
    int ans = dijkstra( source , end , edges , V , path);
    if(ans < MAX_VALUE){
        cout<<"Path is : ";
        for(auto i : path)
            cout<<i<<"->";
        cout<<endl;
        cout<<"Path distance from "<<source<<" to "<<end<<" is: "<<ans;
    }
    else
        cout<<"There exist no path from "<<source<<" to "<<end;
    
}


