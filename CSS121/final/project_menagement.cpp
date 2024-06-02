#include <iostream>
#include <vector>
using namespace std;
const int INF = 9999999;
struct Edge
{
    int node , destination , weight;
};
void bellman(int node,int edge,Edge edges[],int start){
    int distance[100];
    for(int i=0;i<node;i++){ //ทำให้ distance ทุกค่าเป็น inf     O(n)
        distance[i] = INF;
    }
    distance[start] = 0; //เริ่มที่จุด 1
    for(int i=0;i<node-1;i++){
        for(int j=0;j<edge;j++){            //O(n^2)
            int u = edges[j].node; 
            int v = edges[j].destination;
            int weight = edges[j].weight;
            if(distance[u] + weight <= distance[v]){
                distance[v] = distance[u] + weight;
            }
        }
    }
    //print
    cout << "Vertex Distance from vertex 1 :" << endl;
    for(int i=0;i<node;i++){
        cout << "1 -> " << i + 1 << " distance is : " << distance[i] <<endl;        //O(n)
    }
}

int main(){
    int node = 9;
    int edge = 14;
    int start = 0;
    Edge edges_short[] = {
        {0,1,3},{0,2,4},{0,3,6},
        {1,4,9},{1,5,1},
        {2,5,4},{2,3,3},
        {3,5,5},{3,6,4},
        {4,7,3},
        {5,7,6},{5,8,3},
        {6,8,6},
        {7,8,9}
    };
    Edge edges_long[] = {
        {0,1,-3},{0,2,-4},{0,3,-6},
        {1,4,-9},{1,5,-1},
        {2,5,-4},{2,3,-3},
        {3,5,-5},{3,6,-4},
        {4,7,-3},
        {5,7,-6},{5,8,-3},
        {6,8,-6},
        {7,8,-9}
    };
    cout << "shortest path " << endl;
    bellman(node,edge,edges_short,start);
    cout << "longest path " << endl;
    bellman(node,edge,edges_long,start);
}