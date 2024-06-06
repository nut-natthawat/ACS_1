#include <iostream>
using namespace std;

struct Row {
    int A;
    int B;
    int C;
};

void insertionsort(Row arr[], int n, char primary, char secondary, char tertiary) {
    for (int i = 1; i < n; ++i) {
        Row key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            bool shouldSwap = false;
            if (primary == 'A') {
                if (arr[j].A > key.A ||
                   (arr[j].A == key.A && arr[j].B > key.B) ||
                   (arr[j].A == key.A && arr[j].B == key.B && arr[j].C > key.C)) {
                    shouldSwap = true;
                }
            } else if (primary == 'B') {
                if (arr[j].B > key.B ||
                   (arr[j].B == key.B && arr[j].C > key.C) ||
                   (arr[j].B == key.B && arr[j].C == key.C && arr[j].A > key.A)) {
                    shouldSwap = true;
                }
            } else if (primary == 'C') {
                if (arr[j].C > key.C ||
                   (arr[j].C == key.C && arr[j].A > key.A) ||
                   (arr[j].C == key.C && arr[j].A == key.A && arr[j].B > key.B)) {
                    shouldSwap = true;
                }
            }
            if (!shouldSwap) break;
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    const int n = 14;
    Row data[n] = {
        {1, 1, 4}, {3, 1, 1}, {4, 4, 4}, {2, 4, 4}, {3, 5, 3}, {4, 3, 3},
        {1, 3, 3}, {2, 4, 3}, {3, 3, 5}, {1, 5, 3}, {1, 1, 4}, {4, 1, 1},
        {5, 2, 3}, {3, 5, 2}
    };

    char primary, secondary, tertiary;
    cout << "Input primary column to sort (A,B,C): ";
    cin >> primary;
    cout << "Input secondary column to sort (A,B,C): ";
    cin >> secondary;
    cout << "Input tertiary column to sort (A,B,C): ";
    cin >> tertiary;

    insertionsort(data, n, primary, secondary, tertiary);

    for (int i = 0; i < n; ++i) {
        cout << data[i].A << " " << data[i].B << " " << data[i].C << endl;
    }

    return 0;
}
