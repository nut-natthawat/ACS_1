#include <iostream>
#include <queue>

using namespace std;

// โครงสร้างข้อมูลที่ใช้เก็บ state ของบอร์ดเกม
struct State {
    char board[3][3]; // บอร์ดเกมขนาด 3x3
    State* parent; // ชี้ไปที่ state ก่อนหน้า (สำหรับสร้าง uptree)

    State(char b[3][3], State* p = nullptr) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = b[i][j];
        parent = p;
    }
};

// ฟังก์ชันแสดงบอร์ดเกม
void printBoard(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
}

// ฟังก์ชันตรวจสอบว่าผู้เล่นคนใดคนหนึ่งชนะหรือไม่
bool checkWin(const char board[3][3], char player) {
    // ตรวจสอบแถว
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
    }
    // ตรวจสอบคอลัมน์
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    // ตรวจสอบแนวทแยงมุม
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

    return false;
}

// ฟังก์ชันตรวจสอบว่าบอร์ดเกมเต็มหรือยัง
bool isBoardFull(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

// ฟังก์ชันสร้างลูกจาก state ปัจจุบัน
queue<State*> generateNextStates(State* currentState, char player) {
    queue<State*> nextStates;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (currentState->board[i][j] == ' ') {
                char newBoard[3][3];
                for (int x = 0; x < 3; ++x)
                    for (int y = 0; y < 3; ++y)
                        newBoard[x][y] = currentState->board[x][y];
                newBoard[i][j] = player;
                nextStates.push(new State(newBoard, currentState));
            }
        }
    }
    return nextStates;
}

int main() {
    // สร้างบอร์ดเกมเริ่มต้น (empty)
    char initialBoard[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    State* initialState = new State(initialBoard);

    // สร้าง queue เพื่อเก็บ state ต่างๆ
    queue<State*> stateQueue;
    stateQueue.push(initialState);

    // ตัวนับจำนวน state
    int stateCount = 1; // เริ่มต้นที่ 1 เนื่องจาก initialState ถือว่าเป็น state แรก

    // ตัวอย่างการสำรวจ state ต่างๆ
    char currentPlayer = 'X'; // เริ่มต้นด้วยผู้เล่น X

    while (!stateQueue.empty()) {
        State* currentState = stateQueue.front();
        stateQueue.pop();

        cout << "Current Board State:" << endl;
        printBoard(currentState->board);
        cout << endl;

        // ตรวจสอบว่ามีผู้เล่นชนะหรือไม่
        if (checkWin(currentState->board, 'X')) {
            cout << "Player X wins. End of this path." << endl;
            continue;
        }
        if (checkWin(currentState->board, 'O')) {
            cout << "Player O wins. End of this path." << endl;
            continue;
        }

        // ตรวจสอบว่าบอร์ดเต็มหรือยัง
        if (isBoardFull(currentState->board)) {
            cout << "Board is full. End of this path." << endl;
            continue;
        }

        // สร้างลูกจาก state ปัจจุบัน
        queue<State*> nextStates = generateNextStates(currentState, currentPlayer);
        while (!nextStates.empty()) {
            stateQueue.push(nextStates.front());
            nextStates.pop();
            stateCount++; // เพิ่มตัวนับเมื่อสร้าง state ใหม่
        }

        // สลับผู้เล่น
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    cout << "Total number of states: " << stateCount << endl;

    // ทำความสะอาดหน่วยความจำ
    while (!stateQueue.empty()) {
        delete stateQueue.front();
        stateQueue.pop();
    }
    delete initialState;

    return 0;
}
