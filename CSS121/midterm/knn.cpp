#include <iostream>
#include <cmath>
using namespace std;

struct area
{
    int Latitude;
    int Longtitude;
    string HasGold;
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
    if(data[minindex[0]].HasGold == "Yes"){
        Y++;
    }else {
        N++;
    }
    if(data[minindex[1]].HasGold == "Yes"){
        Y++;
    }
    else{
        N++;
    }
    if(data[minindex[2]].HasGold == "Yes"){
        Y++;
    }else {
        N++;
    }
    if(Y > N){
        cout << "Yes jer Gold";
    }
    else{
        cout << "No jer Gold";
    }
}
int main(){
    area areaID[50];
    int A,B;
    cout << "input latitude :";
    cin >> A;
    cout << "Input longtitude :";
    cin >> B;
    areaID[0] = {54,97,"Yes"};
    areaID[1] = {99,91,"No"};
    areaID[2] = {61,53,"Yes"};
    areaID[3] = {43,95,"No"};
    areaID[4] = {60,10,"Yes"};
    areaID[5] = {40,74,"No"};
    areaID[6] = {16,92,"Yes"};
    areaID[7] = {8,8,"No"};
    areaID[8] = {90,37,"Yes"};
    areaID[9] = {13,32,"No"};
    areaID[10] = {85,75,"Yes"};
    areaID[11] = {98,23,"No"};
    areaID[12] = {94,74,"Yes"};
    areaID[13] = {54,38,"No"};
    areaID[14] = {36,42,"Yes"};
    knn(areaID,A,B);

}

