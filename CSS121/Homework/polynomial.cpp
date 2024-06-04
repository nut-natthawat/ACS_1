#include <iostream>
#include <unordered_map>
using namespace std;
struct Node {
    int coef; 
    int exp; 
    Node* next;
};
void insert(Node** head, int coef, int exp) {
    Node* newNode = new Node;
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    Node* cur = *head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = newNode;
}

Node* addPolynomials(Node* a, Node* b) {
    Node* res = nullptr;
    unordered_map<int, int> terms;

    while (a != nullptr) {
        terms[a->exp] += a->coef;
        a = a->next;
    }

    while (b != nullptr) {
        terms[b->exp] += b->coef;
        b = b->next;
    }

    for (auto it = terms.begin(); it != terms.end(); ++it) {
        insert(&res, it->second, it->first);
    }

    return res;
}

Node* multiplyPolynomials(Node* a, Node* b) {
    Node* res = nullptr;
    unordered_map<int, int> terms; 

    Node* curA = a;
    while (curA != nullptr) {
        Node* curB = b;
        while (curB != nullptr) {
            int coef = curA->coef * curB->coef;
            int exp = curA->exp + curB->exp;
            terms[exp] += coef;
            curB = curB->next;
        }
        curA = curA->next;
    }

    for (auto it = terms.begin(); it != terms.end(); ++it) {
        insert(&res, it->second, it->first);
    }

    return res;
}

void printPolynomial(Node* poly) {
    while (poly != nullptr) {
        cout << poly->coef << "x^" << poly->exp;
        poly = poly->next;
        if (poly != nullptr) {
            cout << " + ";
        }
    }
    cout << endl;
}

int main() {
    Node* a = nullptr;
    insert(&a, 2, 5); 
    insert(&a, 4, 3); 
    insert(&a, 3, 2); 
    insert(&a, 5, 0); 

    Node* b = nullptr;
    insert(&b, 2, 5);
    insert(&b, 4, 3); 
    insert(&b, 3, 2); 
    insert(&b, 5, 0); 

    Node* sum = addPolynomials(a, b); 
    Node* prod = multiplyPolynomials(a, b); 

    cout << "a: ";
    printPolynomial(a); 

    cout << "b: ";
    printPolynomial(b); 

    cout << "a + b: ";
    printPolynomial(sum);

    cout << "a * b: ";
    printPolynomial(prod); 

    return 0;
}
