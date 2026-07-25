#include <stdio.h>
// 无向图
// 邻接矩阵实现图的dfs和bfs遍历

// 6*6矩阵
int matrix [6][6]={
//  a b c d e f
    0,1,1,0,1,0, //a
    1,0,0,0,1,0, //b
    1,0,0,0,0,1, //c
    0,0,0,0,1,1, //d
    1,1,0,1,0,0, //e
    0,0,1,1,0,0, //f
};


char letter[6] = {'a', 'b', 'c', 'd', 'e', 'f'}; // 对应矩阵的字母abcdef

int judge_dfs[6] = {0}; // 判断字母是否遍历过，未遍历为0，遍历过为1；
int judge_bfs[6] = {0}; //同上


void DFS(int current)
{
    if (judge_dfs[current] == 0)//未遍历就打印
    {
        judge_dfs[current]=1;//遍历过标记为1
        printf("%c,", letter[current]);
    }

    for (int i = 0; i < 6; i++)
    {

        if (matrix[current][i] == 1&&judge_dfs[i]==0)//1代表相连&&judge判断链接点是否遍历过
        {
            DFS(i);
        }
    }
}


//bfs,设置一个队列，先入队，然后他的邻居也入队，然后再操作队里的下一个


void BFS(int current)
{
    int queue_bfs[6]={0};
    int head=0;
    int tail=0;

    queue_bfs[tail++]=current;//保存下标，不存字母
    judge_bfs[current]=1;

    while (head<tail)
    {
        printf("%c,",letter[queue_bfs[head++]]);//打印出队字母
       for (int i = 0; i < 6; i++)
       {
            if (matrix[queue_bfs[head-1]][i]==1&&judge_bfs[i]==0)//因为前面head++所以head-1才是当前节点
            {
                judge_bfs[i]=1;
                queue_bfs[tail++]=i;//i对应着字母编号
            }
       }
   }
}


int main(int argc, char const *argv[])
{
    printf("DFS:");
    //输零从a开始，输1从b开始。。。。
    DFS(1);

    printf("\n");
    printf("BFS:");
    //输零从a开始，输1从b开始。。。。
    BFS(1);
    return 0;
}




