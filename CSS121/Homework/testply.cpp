#include <iostream>
using namespace std;
struct term
{
    int coeff,expo;
    term* next;
};
class poly{
    private:
        poly* head;
    public:
        poly(){
            head = nullptr;
        }
    void insert(int coeff,int expo){
        poly* newnode = new poly;
    }  
};