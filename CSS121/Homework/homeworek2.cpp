#include <iostream>
using namespace std;
struct polynomialequation
{
    int poly,expo;
    polynomialequation* next;
};
class polynomial{   
    private:
        polynomial* head;
    public:
        polynomial(){
            head = NULL;
        }
    void insert(int coefficient, int exponent) {
        polynomialequation* new_node = new polynomialequation;
        new_node->poly = coefficient;
        new_node->expo = exponent;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            polynomialequation* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
        }
    }
    void add(int )
};