#include <iostream>
#include <vector>
using namespace std;

struct Row {
    int A;
    int B;
    int C;
};

void insertionsort(std::vector<Row>& arr, int n, char column) {
    for (int i = 1; i < n; i++) {
        Row key = arr[i];
        int j = i - 1;
        switch (column) {
            case 'A':
                for (; j >= 0 && arr[j].A > key.A; j--) {
                    arr[j + 1] = arr[j];
                }
                arr[j + 1] = key;
                break;
            case 'B':
                for (; j >= 0 && arr[j].B > key.B; j--) {
                    arr[j + 1] = arr[j];
                }
                arr[j + 1] = key;
                break;
            case 'C':
                for (; j >= 0 && arr[j].C > key.C; j--) {
                    arr[j + 1] = arr[j];
                }
                arr[j + 1] = key;
                break;
            default:
                break;
        }
    }
}

int main() {
    int n = 15;
    std::vector<Row> data = {
        {1, 1, 4},
        {3, 1, 1},
        {4, 4, 4},
        {2, 4, 4},
        {3, 5, 3},
        {4, 3, 3},
        {1, 3, 3},
        {2, 4, 3},
        {3, 3, 5},
        {1, 5, 3},
        {1, 1, 4},
        {4, 1, 1},
        {5, 2, 3},
        {3, 5, 2}
    };
    char column;
    cout << "Input column to sort (A, B, C): ";
    cin >> column;
    insertionsort(data, n, column);
    for (const Row& row : data) {
        cout << row.A << " " << row.B << " " << row.C << endl;
    }
}
