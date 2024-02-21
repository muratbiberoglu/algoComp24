#include <bits/stdc++.h>
using namespace std;

// 1 unit of moves for rook, bishop and knight
vector<pair<int, int>> rookMoves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int, int>> bishopMoves = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
vector<pair<int, int>> knightMoves = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

// Check if the given position is inside the board
bool isInside(int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void dfs(vector<vector<char>> &board, vector<vector<int>> &dist, vector<pair<int, int>> &positions, vector<pair<int, int>> &moves) {
    // creating queue with position and previous move
    // if previous move is same as current move, then the rook or bishops distance won't increase
    queue<pair<pair<pair<int, int>, pair<int, int>>, int>> q;

    for (auto pos : positions) {
        q.push({{pos, make_pair(0, 0)}, 0});
        dist[pos.first][pos.second] = 0;
    }

    while (!q.empty()) {
        pair<int, int> pos = q.front().first.first;
        pair<int, int> prevMove = q.front().first.second;
        int curDist = q.front().second;
        q.pop();

        for (auto move : moves) {
            int x = pos.first + move.first;
            int y = pos.second + move.second;

            if (!(isInside(x, y, board.size()) && board[x][y] != 'P')) continue;
            // int prevDist = dist[pos.first][pos.second];
            // This line is to imitate the rook or bishop's limitless movement in one direction at on move
            int nextDist = curDist;
            if (prevMove != move) {
                nextDist++;
            }
            if (dist[x][y] >= nextDist) {
                dist[x][y] = min(dist[x][y], nextDist);
                q.push({{{x, y}, {move}}, nextDist});
            }
        }
    }
}

// dfs for knight
// We onlt need to check if the knight can reach the target cell
// If the knight can reach the target cell, then we can check if it can reach the target cell with less moves than the rook and bishop
// If it can, then the knight can reach the target cell

void knightDfs(vector<vector<char>> &board, vector<vector<int>> &dist, pair<int, int> &target, pair<int, int> &knightPos, vector<pair<int, int>> &moves, vector<vector<int>> &combinedBoard) {
    queue<pair<int, int>> q;

    q.push(knightPos);
    dist[knightPos.first][knightPos.second] = 0;

    while (!q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();

        for (auto move : moves) {
            int x = pos.first + move.first;
            int y = pos.second + move.second;

            // inside the board, not visited, not a pawn and rook and bishop can reach the cell with less or equal moves than the knight
            if (isInside(x, y, board.size()) && board[x][y] != 'P' && combinedBoard[x][y] > (dist[pos.first][pos.second] + 1)) {
                int prevDist = dist[pos.first][pos.second] + 1;

                if (dist[x][y] > prevDist) {
                    dist[x][y] = prevDist;
                    q.push({x, y});
                }
            }
        }
    }
}

void printTable(vector<vector<int>> &table) {
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++) {
            if (table[i][j] == INT_MAX / 2)
                cout << "-"
                     << " ";
            else
                cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, r, c;
        cin >> n >> r >> c;
        r--;
        c--;

        vector<vector<char>> board(n, vector<char>(n, '_'));

        vector<pair<int, int>> rookPos;
        vector<pair<int, int>> bishopPos;
        pair<int, int> knightPos;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char ch;
                cin >> ch;
                board[i][j] = ch;
                if (ch == 'R') {
                    rookPos.push_back({i, j});
                }
                if (ch == 'B') {
                    bishopPos.push_back({i, j});
                }
                if (ch == 'K') {
                    knightPos = {i, j};
                }
            }
        }

        // Check if knight can move to the given position
        // Quick check if it's possible to reach the target cell
        if (board[r][c] == 'K') {
            cout << "YES" << endl;
            continue;
        }
        if (board[r][c] == 'P') {
            cout << "NO" << endl;
            continue;
        }

        vector<vector<int>> rookBoard(n, vector<int>(n, INT_MAX / 2));
        vector<vector<int>> bishopBoard(n, vector<int>(n, INT_MAX / 2));
        vector<vector<int>> knightBoard(n, vector<int>(n, INT_MAX / 2));

        dfs(board, rookBoard, rookPos, rookMoves);
        dfs(board, bishopBoard, bishopPos, bishopMoves);

        // printTable(rookBoard);
        // printTable(bishopBoard);

        // combine the dfs for rook and bishops distance into rookBoard
        // get the minimum distance for each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rookBoard[i][j] = min(rookBoard[i][j], bishopBoard[i][j]);
            }
        }

        pair<int, int> target = {r, c};
        knightDfs(board, knightBoard, target, knightPos, knightMoves, rookBoard);

        if (knightBoard[r][c] != INT_MAX / 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        // Dfs for rook and bishop
        // rookBoard[i][j] = x means that the rook can reach the cell (i,j) with x moves
        // bishopBoard[i][j] = x means that the bishop can reach the cell (i,j) with x moves

        // after that dfs for knight
        // but knight can only reach the target cell if and only if it can reach that cell with less moves than the rook and bishop
        // at the end of the dfs, if knightBoard[r][c] < rookBoard[r][c] and knightBoard[r][c] < bishopBoard[r][c], then the knight can reach the target cell
        // otherwise, it can't reach the target cell
    }
}

/**
 * Theory:
 * If for all all the "reaching cells" such that the knight must pass through to reach the target cell,
 * If Rooks and Bishops can reach those "reaching cells" with at least x moves and knight can reach those cells with at least y moves,
 * if x <= y, then the knight can't reach the target cell.
 *
 * Because in order to knight to reach the target cell, it must pass through the "reaching cells" and if the knight can't reach those cells without being captured, then it can't reach the target cell.
 */

// Check if the knight can reach the target cell