#include <iostream>
using namespace std;

const int INF = 999999;
const int V = 5;

void floyd(int graph[V][V]){
    int distance[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){           //ใส่ค่า distance         O(n^2)
            distance[i][j] = graph[i][j];
        }
    }
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(distance[i][k]!=INF&&distance[k][j]!=INF&&distance[i][j] > distance[i][k]+distance[k][j]){       //O(n^3)
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
    //print matrix
    cout << "distance between ever pair" << endl << "   1 2 3 4 5" << endl;
    for(int i=0;i<V;i++){
        cout << i+1 << "| ";
        for(int j=0;j<V;j++){                   //O(n^2)
            if(distance[i][j] == INF){
                cout << "INF";
            }
            else{
                cout << distance[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    int graph[V][V] = {
        {0, 3, 4, INF,INF},  
        {3, 0, 3, 1,6}, 
        {4, 3, 0, 6,5},
        {INF, 1, 7, 0,3},
        {INF, 6, 5, 3, 0}
    };
    floyd(graph);
}