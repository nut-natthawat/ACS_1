#include <iostream>
using namespace std;
template <class Elem> class Link {
    Elem element;
    Link *next;
    Link *prev;
    Link(const Elem& e, Link* prev = NULL,Link* next = NULL)
        {element = e; prev = prevp; next = nextp;}
    Link(Link* prev =NULL, Link* nxtp = NULL)
        { prev = prevp; next = nextp;}
};
template <class Elem> class LList {
    bool LList<Elem>::insert(const Elem& item) {
        fence->next = new Link<Elem>(item, fence, fence->next);
        if (fence->next->next != NULL)
            fence->next->next->prev = fence->next;
        if (tail == fence) // Appending new Elem
            tail = fence->next; // so set tail
            rightcnt++; // Added to right
        return true;
    }
    bool LList<Elem>::remove(Elem& it) {
        if (fence->next == NULL) return false;
            it = fence->next->element;
    Link<Elem>* ltemp = fence->next;
        if (ltemp->next != NULL)
            ltemp->next->prev = fence;
        else tail = fence; // Reset tail
            fence->next = ltemp->next; // Remove
            delete ltemp; // Reclaim space
            rightcnt--; // Removed from right
        return true;
    }
};