#include <iostream>
#include <vector>
using namespace std;

struct Row {
    int A;
    int B;
    int C;
};

void insertionsort(std::vector<Row>& arr, int n, char column) {
    for (size_t i = 1; i < n; ++i) {
        Row key = arr[i];
        size_t j = i;
        switch (column) {
            case 'A':
                while (j > 0 && arr[j - 1].A > key.A) {
                    arr[j] = arr[j - 1];
                    --j;
                }
                break;
            case 'B':
                while (j > 0 && arr[j - 1].B > key.B) {
                    arr[j] = arr[j - 1];
                    --j;
                }
                break;
            case 'C':
                while (j > 0 && arr[j - 1].C > key.C) {
                    arr[j] = arr[j - 1];
                    --j;
                }
                break;
            default:
                break;
        }
        arr[j] = key;
    }
}

int main() {
    int n = 14;
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

    cout << "Enter the column to sort (A, B, C): ";
    cin >> column;

    insertionsort(data, n, column);

    for (const Row& row : data) {
        std::cout << row.A << " " << row.B << " " << row.C << endl;
    }

    return 0;
}
