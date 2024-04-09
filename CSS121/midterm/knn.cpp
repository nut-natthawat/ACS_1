#include <iostream>
#include <cmath>
using namespace std;

struct area
{
    char areaID[50];
    int Latitude;
    int Longtitude;
    int HasGold;
};

void knn(area* data,int A,int B){
    float lowdistance[3] = {9999,9999,9999};
    float distance[50];
    int minindex[3],Y=0,N=0;
    for(int i=0;i<15;i++){
        distance[i] = sqrt(pow(data[i].Latitude - A,2)+ pow(data[i].Longtitude - B,2));
        if(distance[i] < lowdistance[0] || distance[i] < lowdistance[1] || distance[i] < lowdistance[2]){
            if(distance[i] <= lowdistance[0]){
                lowdistance[2] = lowdistance[1];
                lowdistance[1] = lowdistance[0];
                lowdistance[0] = distance[i];
                minindex[0] = i;
            }
            else if (distance[i] <= lowdistance[1]) {
                lowdistance[2] = lowdistance[1];
                lowdistance[1] = distance[i];
                minindex[1] = i;
            } else {
                lowdistance[2] = distance[i];
                minindex[2] = i;
            }
        } 
    }
    cout << "me tong or not?" << endl;
    if(data[minindex[0]].HasGold == 1){
        Y++;
    }else {
        N++;
    }
    if(data[minindex[1]].HasGold == 1){
        Y++;
    }
    else{
        N++;
    }
    if(data[minindex[2]].HasGold == 1){
        Y++;
    }else {
        N++;
    }
    if(Y > N){
        cout << "Yes jer Gold" << endl;
    }
    else{
        cout << "No jer Gold" << endl;
    }
    cout << "nearest 3 position :" << data[minindex[0]].areaID << "," << data[minindex[1]].areaID << "," << data[minindex[2]].areaID << endl;
}
int main(){
    area areaID[50];
    int A,B;
    cout << "input latitude :";
    cin >> A;
    cout << "Input longtitude :";
    cin >> B;
    areaID[0] = {"1",54,97,1};
    areaID[1] = {"2",99,91,0};
    areaID[2] = {"3",61,53,1};
    areaID[3] = {"4",43,95,0};
    areaID[4] = {"5",60,10,1};
    areaID[5] = {"6",40,74,0};
    areaID[6] = {"7",16,92,1};
    areaID[7] = {"8",8,8,0};
    areaID[8] = {"9",90,37,1};
    areaID[9] = {"10",13,32,0};
    areaID[10] = {"11",85,75,1};
    areaID[11] = {"12",98,23,0};
    areaID[12] = {"13",94,74,1};
    areaID[13] = {"14",54,38,0};
    areaID[14] = {"15",36,42,1};
    knn(areaID,A,B);

}

