#include <iostream>
using namespace std;

class Shape{
    private:
        int Width;
        int Height;
    public:
        void setWidth(int w){
            Width = w;
        }
        void setHeight(int h){
            Height = h;
        }
};
class Rectangle :public Shape{
    public:
        void setWidth(int w){
            if(w < 0){
                Shape::setHeight(0);
            }
            else{
                Shape::setHeight(w);
            }
        }
        void setHeight(int h){
            if(h < 0){
                Shape::setHeight(0);
            }
            else{
                Shape::setHeight(h);
            }
        }

};
int main(){
    Rectangle myRect;
    myRect.setWidth(-5);
    myRect.setHeight(10);
    cout << myRect.Width;
}