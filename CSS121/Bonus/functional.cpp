#include<iostream>
#include<cfloat>
#include<cmath>
using namespace std;

struct Area {
    char Area_id[50];
    int Latitude;
    int Longitude;
    int hasGold;
};

class Board {
public:
    float distances[15];
    Area areas[15];

    Board() {
        areas[0] = {"1", 54, 97, 1};
        areas[1] = {"2", 99, 91, 0};
        areas[2] = {"3", 61, 53, 1};
        areas[3] = {"4", 43, 95, 0};
        areas[4] = {"5", 60, 10, 1};
        areas[5] = {"6", 40, 74, 0};
        areas[6] = {"7", 16, 92, 1};
        areas[7] = {"8", 8, 8, 0};
        areas[8] = {"9", 90, 37, 1};
        areas[9] = {"10", 13, 32, 0};
        areas[10] = {"11", 85, 75, 1};
        areas[11] = {"12", 98, 23, 0};
        areas[12] = {"13", 94, 74, 1};
        areas[13] = {"14", 54, 38, 0};
        areas[14] = {"15", 36, 42, 1};
    }

    float calculateDistance(int lati, int longti, int index) {
        return sqrt(pow((areas[index].Latitude - lati), 2) + pow((areas[index].Longitude - longti), 2));
    }

    void calculateAllDistances(int lati, int longti) {
        for (int i = 0; i < 15; i++) {
            distances[i] = calculateDistance(lati, longti, i);
        }
    }

    int findClosestArea() {
        float minDistance = distances[0];
        int minIndex = 0;
        for (int i = 1; i < 15; i++) {
            if (distances[i] < minDistance) {
                minDistance = distances[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    void markAreas() {
        int goldCount = 0;
        for (int i = 0; i < 3; i++) {
            int closestAreaIndex = findClosestArea();
            if (areas[closestAreaIndex].hasGold == 1) {
                goldCount++;
            }
            distances[closestAreaIndex] = FLT_MAX;
        }
        cout << "Has gold? ";
        if (goldCount >= 2) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
};

int main() {
    Board board;
    int lati, longti;
    cout << "Latitude = ";
    cin >> lati;
    cout << "Longitude = ";
    cin >> longti;
    board.calculateAllDistances(lati, longti);
    board.markAreas();
    return 0;
}
