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
    cout << "Vertex Distance from start :" << endl;
    for(int i=0;i<node;i++){
        cout << "1 -> " << i + 1 << " distance is : " << -distance[i] <<endl;        //O(n)
    }
}

int main(){
    int node = 9;
    int edge = 10;
    int start = 0;
    Edge edges_long[] = {
        {0,1,-3},{0,2,-4},      //start = 0 A=1 B=2 C=3 D=4 E=5 F=6 G=7 finish=8
        {1,3,-2},{1,4,-1},
        {2,5,-2},
        {3,6,-1},
        {4,8,0},
        {5,7,-1},
        {6,8,0},
        {7,8,0}
    };
    cout << "longest path " << endl;
    bellman(node,edge,edges_long,start);
}