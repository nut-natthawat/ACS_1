#include <iostream>
#include <cmath>
#include <string>
using namespace std;
const int MAX_SIZE = 15;
struct DataPoint {
    int id;
    double lat;
    double lon;
    string hasYes;
    double distance;
};
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    return sqrt(pow((lat1 - lat2), 2) + pow((lon1 - lon2), 2));
}
void merge(DataPoint data[], DataPoint temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (data[i].distance <= data[j].distance) {
            temp[k++] = data[i++];
        } else {
            temp[k++] = data[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = data[i++];
    }

    while (j <= right) {
        temp[k++] = data[j++];
    }

    for (int i = left; i <= right; ++i) {
        data[i] = temp[i];
    }
}
void mergeSort(DataPoint data[], DataPoint temp[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(data, temp, left, mid);
        mergeSort(data, temp, mid + 1, right);
        merge(data, temp, left, mid, right);
    }
}
void kNN(DataPoint data[], int size, double lat, double lon) {
    for (int i = 0; i < size; ++i) {
        double distance = calculateDistance(lat, lon, data[i].lat, data[i].lon);
        data[i].distance = round(distance * 100.0) / 100.0;
    }
}
string hasYes(DataPoint data[]) {
    int count = 0;
    for (int i = 0; i < 3; ++i) {
        if (data[i].hasYes == "Yes") {
            count++;
        }
    }
    return count >= 2 ? "Yes" : "No";
}
void process(DataPoint data[], int size, double lat, double lon) {
    DataPoint temp[MAX_SIZE];
    kNN(data, size, lat, lon);
    mergeSort(data, temp, 0, size - 1);

    cout << "Top 3 closest distances: " << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "lat: " << data[i].lat << " long: " << data[i].lon << " has gold: " << data[i].hasYes << " distance: " << data[i].distance << endl;
    }
    cout << endl;

    string result = hasYes(data);
    cout << "(Yes / No) ? : " << result << endl;
}
int main() {
    DataPoint data[MAX_SIZE] = {
        {1, 54, 97, "Yes"},
        {2, 99, 91, "No"},
        {3, 61, 53, "Yes"},
        {4, 43, 95, "No"},
        {5, 60, 10, "Yes"},
        {6, 40, 74, "No"},
        {7, 16, 92, "Yes"},
        {8, 8, 8, "No"},
        {9, 90, 37, "Yes"},
        {10, 13, 32, "No"},
        {11, 85, 75, "Yes"},
        {12, 98, 23, "No"},
        {13, 94, 74, "Yes"},
        {14, 54, 38, "No"},
        {15, 36, 42, "Yes"}
    };
    double lat = 52, lon = 25;
    process(data, MAX_SIZE, lat, lon);
    return 0;
}
