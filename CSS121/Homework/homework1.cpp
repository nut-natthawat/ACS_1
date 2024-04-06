#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct mbti
{
    string name,type;
    char type1,type2,type3,type4;
    double Ne,Ni,Te,Ti,Se,Si,Fe,Fi,distance;
    mbti* next;
    mbti* prev;
};
class KNN{
    private:
        mbti* head;
        mbti* tail;
        int size=0,mindistance = 999999;
    public:
        KNN(){
            head = nullptr;
            tail = nullptr;
        }
    void insert(string name,double Ne,double Ni,double Te,double Ti,double Se,double Si,double Fe,double Fi,char type1,char type2,char type3,char type4){
        mbti* newinfo = new mbti;
        newinfo -> name = name;
        newinfo -> Ne = Ne;
        newinfo -> Ni = Ni;
        newinfo -> Te = Te;
        newinfo -> Ti = Ti;
        newinfo -> Se = Se;
        newinfo -> Si = Si;
        newinfo -> Fe = Fe;
        newinfo -> Fi = Fi;
        newinfo -> type1 = type1;
        newinfo -> type2 = type2;
        newinfo -> type3 = type3;
        newinfo -> type4 = type4;
        newinfo -> distance = 0;
        newinfo -> next = nullptr;
        newinfo -> prev = nullptr;
        if(head == nullptr){
            head = newinfo;
            tail = newinfo;
        }
        else{
            tail -> next = newinfo;
            newinfo -> prev = tail;
            tail = newinfo;
        }
    }
    double caldistance(double ne,double Ne,double ni,double Ni,double te,double Te,double ti,double Ti,double se,double Se,double si,double Si,double fe,double Fe,double fi,double Fi,){
        double distance = sqrt(pow(ne-Ne,2)+pow(ni-Ni,2)+pow(te-Te,2)+pow(ti-Ti,2)+pow(se-Se,2)+pow(si-Si,2)+pow(fe-Fe,2)+pow(fi-Fi,2));
        return distance;
    }
    void knn(double ne,double ni,double te,double ti,double se,double si,double fe,double fi){
        mbti* fence = head;
        while(fence != nullptr){
            head -> distance = caldistance(ne,head -> Ne,ni,head -> Ni,te,head -> Te,ti,head -> Ti,se,head->Se,si,head -> Si,fe,head -> Fe,fi,head -> Fi);
            fence = fence -> next;
            /*if(head -> next -> distance <= mindistance && size <= 3){
                mindistance = head -> next -> distance;
                size++;
            }*/
        }
    }
};
int main(){
    KNN info;
    double ne,ni,te,ti,se,si,fe,fi;
    string name;
    char a,b,c,d;
    cout << "Enter your name" << endl;
    cin >> name;
    cout << "Enter Ne Ni Te Ti Se Si Fe Fi" << endl;
    cin >> ne >> ni >> te >> ti >> se >> si >> fe >> fi;
    cout << "Enter type" << endl;
    cin >> a >> b >> c >> d;
    info.knn(ne,ni,te,ti,se,si,fe,fi);
    

}
