#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

int ping_poing()
{
    int p1[2]; // 管道1
    int p2[2]; // 管道2

    // 初始化管道
    if (pipe(p1) < 0 || pipe(p2) < 0)
    {
        printf("初始化管道失败！");
    }

    // 计时
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int begin_time = tv.tv_sec; // 单位秒

    // 传送字节数
    int exchanges = 1000000;
    const int bytesPerExchange = 1;

    if (fork() == 0) // 子进程1，ping
    {
        /* 开始ping-pong */
        char buf[bytesPerExchange];
        while (exchanges)
        {
            write(p1[1], buf, 1); // 在管道1写入
            read(p2[0], buf, 1);  // 从管道2读入
            exchanges--;
        }
        exit(0);
    }
    if (fork() == 0) // 子进程2，pong
    {
        /* 开始ping-pong */
        char buf[bytesPerExchange];
        while (exchanges)
        {
            read(p1[0], buf, 1);  // 从管道1读入
            write(p2[1], buf, 1); // 在管道2写入
            exchanges--;
        }
        exit(0);
    }
    wait(0);
    wait(0);

    // 输出计时
    gettimeofday(&tv, NULL);
    int end_time = tv.tv_sec; // 单位秒
    printf("Exchanges: %d\n", exchanges * bytesPerExchange);
    printf("Use time: %ds\n", end_time - begin_time);
    printf("Exchange rate: %d/s\n", (exchanges * bytesPerExchange) / (end_time - begin_time));
    return 0;
}

int main()
{
    ping_poing();
    return 0;
}