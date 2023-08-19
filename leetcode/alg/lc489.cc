// leetcode 489
// Robot Room Cleaner

// 我们正在控制一个扫地机器人来进行房间扫除，房间是m*n的，
// 一开始机器人在的位置是不明确的，同时我们不知道整个房间的情况，只能操作机器人移动
// 需要利用该机器人把整个房间扫完
// 由于我们不知道真实的坐标，所以我们考虑相对坐标和相对方向
// 一开始的坐标是 (0,0) 初始化的方向是 0 (0, 1, 2, 3)
// backtrack({x, y}, direction):
// 1. visited(x, y)
// 2. clean the room
// 3. try move to another near room
//  遍历四个相对方向来得到下一个相对坐标，如果下一个位置可以移动，移动到下一个房间backtrack(nx, ny, nd)
//  然后需要回到之前的房间
//  back():
//  1. 首先需要向右转2次，使得机器人的朝向为回去的方向
//  2. move 这样就能到原来的方向
//  3. 再次向右转2次，使得机器人完全恢复最初的状态
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void back(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    // 利用set来进行pair的去重检查
    set<pair<int, int>> visited;

    // backtrack是从 (x, y) 方向为d 开始进行回溯
    // 首先标记该位置为已访问过
    // 然后调用robot.clean来清理
    // 然后我们遍历四个方向，注意要取 % 4
    //   对于没有访问过的方向，我们继续调用回溯，由于这个机器人的移动是有状态的，所以
    //   我们还必须额外调用一次的back，返回之前的位置，在开始下一个回溯
    void backtrack(int x, int y, int d, Robot& robot) {
        visited.insert({x, y});
        robot.clean();

        for(int i=0; i<4; i++) {
            // 注意方向需要取模
            int nd = (d + i) % 4;
            int nx = x + dx[nd];
            int ny = y + dy[nd];

            if (visited.find({nx, ny}) == visited.end() &&robot.move()) {
                backtrack(nx, ny, nd, robot);
                // 这个回溯的方法比较tricky
                back(robot);
            }
            robot.turnRight();
        }
    }

    void cleanRoom(Robot& robot) {
        robot = robot;
        visited = set<pair<int, int>>();
        backtrack(0, 0, 0, robot);
    }
};