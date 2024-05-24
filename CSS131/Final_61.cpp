#include <iostream>
#include <string>
using namespace std;

class Animal{
    protected:
        string name;
    public:
        void speak(){
            cout << "The animal speak." << endl;
        }
};
class Dog :public Animal{
    public:
        void speak(){
            cout << "The dog braks." << endl;
        }
};
int main(){
    Dog mydog;
    mydog.speak();
}