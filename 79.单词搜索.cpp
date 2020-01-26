/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start

#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool DFS(vector<vector<char>> &board, vector<vector<int>> &visit, int x, int y, string s)
    {
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        if (!s.size())
            return true;

        visit[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newX = dx[i] + x;
            int newY = dy[i] + y;

            if (newX < 0 || newX >= visit.size() || newY < 0 || newY >= visit[newX].size())
            {
                continue;
            }
            if (visit[newX][newY] == 0 && board[newX][newY] == s[0])
            {
                return DFS(board, visit, newX, newY, s.substr(1));
            }
        }
        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        // 构建一个
        vector<vector<int>> visit;
        for (size_t i = 0; i < board.size(); i++)
        {
            vector<int> item;
            for (size_t j = 0; j < board[i].size(); i++)
            {
                item.push_back(0);
            }
            visit.push_back(item);
        }

        for (unsigned int i = 0; i < board.size(); i++)
            for (unsigned int j = 0; j < board[0].size(); j++)

                if (word[0] == board[i][j])
                {
                    if (DFS(board, visit, i, j, word.substr(1)))
                        return true;
                }

        return false;
    }
};
// @lc code=end
