#include <iostream>
#include <string>
#include <queue>
using namespace std;
class TicTacToeTree {
public:
    int size;
    int currentIndex = 0;
    int xWinCount = 0;
    string* boardStates;

    TicTacToeTree(int maxsize) {
        size = maxsize;
        boardStates = new string[size];
    }
    void generateBoardStates(queue<string>& gameQueue) {
        char currentPlayer;
        int round = 0;
        string newBoardState;
        gameQueue.push("---------");

        while (!gameQueue.empty()) {
            string currentBoard = gameQueue.front();
            gameQueue.pop();
            int xCount = 0, oCount = 0;
            
            for (int k = 0; k < 9; ++k) {
                if (currentBoard[k] == 'X') xCount++;
                else if (currentBoard[k] == 'O') oCount++;
            }
            cout << "Round: " << round++ << endl;
            displayBoard(currentBoard);
            if (checkWin(currentBoard, 'X')) {
                xWinCount++;
                cout << "============= X Wins: " << xWinCount << endl;
                continue;
            } else if (checkWin(currentBoard, 'O')) {
                xWinCount--;
                cout << "============= X Loses: " << xWinCount << endl;
                continue;
            }
            currentPlayer = (xCount > oCount) ? 'O' : 'X';
            for (int k = 0; k < 9; ++k) {
                if (currentBoard[k] == '-') {
                    newBoardState = currentBoard;
                    newBoardState[k] = currentPlayer;
                    boardStates[currentIndex++] = newBoardState;
                    gameQueue.push(newBoardState);
                }
            }
        }
    }
    bool checkWin(const string& board, char player) {
        for (int k = 0; k < 3; ++k) {
            if (board[k * 3] == player && board[k * 3 + 1] == player && board[k * 3 + 2] == player) return true;
            if (board[k] == player && board[k + 3] == player && board[k + 6] == player) return true;
        }
        return (board[0] == player && board[4] == player && board[8] == player) ||
               (board[2] == player && board[4] == player && board[6] == player);
    }
    void displayBoard(const string& board) {
        cout << "___" << endl;
        for (int k = 0; k < 9; ++k) {
            cout << board[k];
            if (k % 3 == 2) cout << endl;
        }
    }
    ~TicTacToeTree() {
        delete[] boardStates;
    }
};
int main() {
    queue<string> gameQueue;
    TicTacToeTree tree(600000);
    tree.generateBoardStates(gameQueue);
    return 0;
}
