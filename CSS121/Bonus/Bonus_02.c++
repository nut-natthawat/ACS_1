#include <iostream>
#include <string>
using namespace std;
struct player
    {
        string name;
        int score;
        player* next;
        player* prev;
    };
class Scoreborad{
    private:
        player* head;
        player* tail;
        int size;
    public:
        Scoreborad(){
            head = NULL;
            tail = NULL;
            size = 0;
        }
    void insertscore(string name ,int score){
        player* newplayer = new player;
        newplayer->name = name;
        newplayer->score = score;
        newplayer->prev = NULL;
        newplayer->next = NULL;
        if(head == NULL){
            head = newplayer;
            tail = newplayer;
        }
        else{
            player* current = head;
            while (current != NULL && current->score >= score) {
                current = current->next;
            }
            if (current == head) {
                newplayer->next = head;
                head->prev = newplayer;
                head = newplayer;
            } else if (current == NULL) {
                tail->next = newplayer;
                newplayer->prev = tail;
                tail = newplayer;
            } else {
                newplayer->next = current;
                newplayer->prev = current->prev;
                current->prev->next = newplayer;
                current->prev = newplayer;
            }
        }
        if(size >= 4){
            removelast();
        }
        else{
            size++;
        }
    }
    private:
        void removelast(){
            if (tail != nullptr) {
            player* temp = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
        }
        }
    public:
    void display() {
        player* current = head;
        while (current != NULL) {
            cout << current->name << ":" << current->score << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main(){
    Scoreborad borad;
    string name;
    int score;
    for(int i=1;i<=4;i++){
        cout << "Enter name" << endl;
        cin >> name >> score;
        borad.insertscore(name,score);
    }
    cout << "Scoreborad" << endl;
    borad.display();
    cout << "Insert player" << endl;
    cin >> name >> score;
    borad.insertscore(name,score);
    cout << "\n" << name << "Got new score = " << score << endl;
    cout << "\n" << "Scoredborad" << endl;
    borad.display();
}
