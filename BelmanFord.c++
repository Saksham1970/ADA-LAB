#include<bits/stdc++.h>
using namespace std;

vector<int>* bellmonFord(int n , int m , int src , vector<vector<int>>& edges){

    vector<int>* distance = new vector<int>(n,INT_MAX);
    (*distance)[src] = 0;

    for(int i{} ; i<n-1 ; i++)
        for(int j{} ; j<m ; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if((*distance)[u]!=INT_MAX && (*distance)[u]+w < (*distance)[v])
                (*distance)[v] = (*distance)[u]+w;
        }

        for(int j{} ; j<m ; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            if((*distance)[u] != INT_MAX && (*distance)[u]+weight<(*distance)[v]){
                cout<<"There exists a negative cycle in this Graph";
                return new vector<int>(n,INT_MIN);
            }
        }

        return distance;

}

int main(){

    vector<vector<int>> edges = {{0,1,-1},{0,2,4},{1,2,3},{1,3,2},{1,4,2},{3,2,5},{3,1,1},{4,3,-3}};
    int n = 5 , m = 8 , src = 0;
    vector<int>* distance = bellmonFord(n,m,src,edges);

    cout<<"   Vertex \t\t\t\t\t Distance from Source vertex "<<src<<endl;

    if((*distance)[0] == INT_MIN)
        return 0;

    for(int i{} ; i<n ; i++)    
        cout<<"      "<<i<<"\t\t\t\t\t\t\t\t"<<(*distance)[i]<<endl;
    
    cout<<"===============================================================================================================\n";

    vector<vector<int>> edges1 = {{0,1,5},{1,2,6},{1,3,5},{2,4,1},{3,5,2},{4,3,-1},{5,4,-3}};
    n = 6 , m = 7 , src = 0;
    distance = bellmonFord(n,m,src,edges1);

    if((*distance)[0] == INT_MIN)
        return 0;

    cout<<"   Vertex \t\t\t\t\t Distance from Source vertex "<<src<<endl;
    
    for(int i{} ; i<n ; i++)    
        cout<<"      "<<i<<"\t\t\t\t\t\t\t\t"<<(*distance)[i]<<endl;

    return 0;

}