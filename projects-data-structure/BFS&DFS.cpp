// BFS :适用最短问题
// 使用队列保存未被检测的结点。结点按照宽度优先的次序被访问和进出队列。
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 100;
bool vst[maxn][maxn];                       // 访问标记
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0}; // 方向向量

struct State // BFS 队列中的状态数据结构
{
    int x, y;         // 坐标位置
    int Step_Counter; // 搜索步数统计器
};

State a[maxn];

bool CheckState(State s) // 约束条件检验
{
    if (!vst[s.x][s.y] && ...) // 满足条件
        return 1;
    else // 约束条件冲突
        return 0;
}

void bfs(State st)
{
    queue<State> q;      // BFS 队列
    State now, next;     // 定义2 个状态，当前和下一个
    st.Step_Counter = 0; // 计数器清零
    q.push(st);          // 入队
    vst[st.x][st.y] = 1; // 访问标记
    while (!q.empty())
    {
        now = q.front(); // 取队首元素进行扩展
        if (now == G)    // 出现目标态，此时为Step_Counter 的最小值，可以退出即可
        {
            ...... // 做相关处理
                return;
        }
        for (int i = 0; i < 4; i++)
        {
            next.x = now.x + dir[i][0]; // 按照规则生成 下一个状态
            next.y = now.y + dir[i][1];
            next.Step_Counter = now.Step_Counter + 1; // 计数器加1
            if (CheckState(next))                     // 如果状态满足约束条件则入队
            {
                q.push(next);
                vst[next.x][next.y] = 1; //访问标记
            }
        }
        q.pop(); // 队首元素出队
    }
     return;
}

int main()
{
    ......
    return 0;
}
 
 
// DFS :适用全部解问题
// 该DFS 框架以2D 坐标范围为例，来体现DFS 算法的实现思想。
// 使用[栈]保存未被检测的结点，结点按照深度优先的次序被访问并依次被压入栈中，并以相反的次序出栈进行新的检测。
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int maxn = 100;
bool vst[maxn][maxn];                       // 访问标记
int map[maxn][maxn];                        // 坐标范围
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0}; // 方向向量，(x,y)周围的四个方向

bool CheckEdge(int x, int y) // 边界条件和约束条件的判断
{
    if (!vst[x][y] && ...) // 满足条件
        return 1;
    else // 与约束条件冲突
        return 0;
}

void dfs(int x, int y)
{
    vst[x][y] = 1;      // 标记该节点被访问过
    if (map[x][y] == G) // 出现目标态G
    {
        ...... // 做相应处理
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (CheckEdge(x + dir[i][0], y + dir[i][1])) // 按照规则生成下一个节点
            dfs(x + dir[i][0], y + dir[i][1]);
    }
    return; // 没有下层搜索节点，回溯
}
int main()
{
    ...... 
    return 0;
}