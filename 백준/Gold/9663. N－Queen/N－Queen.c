#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#pragma warning(disable : 4996)

int N_Queen(int n, int line, int** arr);
int make_zone(int n, int i, int j, int** arr);
void diSet0(int** arr, int n);

int count = 0;

int main(void)
{
    int N;
    scanf("%d", &N);
    int** chess = (int**)malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++)
    {
        chess[i] = (int*)malloc(sizeof(int) * N);
    }
    diSet0(chess, N);

    /*code*/
    N_Queen(N, 0, chess);
    printf("%d\n", count);

    for (int i = 0; i < N; i++)
    {
        free(chess[i]);
    }
    free(chess);
}

int N_Queen(int n, int line, int** arr)
{
    if (line >= n)
    {
        count++;
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        //역으로 그 자리의 퀸 공격 방향에 퀸이 없으면 되는거 아님?
        if (make_zone(n, line, i, arr))
        {
            arr[line][i] = 1;
            // 다음 라인으로
            N_Queen(n, line + 1, arr);
            arr[line][i] = 0;
        }
        /*근데 어떻게 다시 돌아올래? -> 백트래킹 핵심*/
        //이 부분을 stack로 해결할 수 있는 알고리즘 필요
    }
    return 0;
}

void diSet0(int** arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }
}

///////////////////////////////////////////////////////////////////

int make_zone(int n, int i, int j, int** arr)
{
    for (int k = 0; k < n; k++)
    {
        if (arr[i][k] == 1)
            return 0;
        if (arr[k][j] == 1)
            return 0;
        if (i + k < n && j + k < n && arr[i + k][j + k] == 1)
            return 0;
        if (i + k < n && j - k >= 0 && arr[i + k][j - k] == 1)
            return 0;
        if (i - k >= 0 && j + k < n && arr[i - k][j + k] == 1)
            return 0;
        if (i - k >= 0 && j - k >= 0 && arr[i - k][j - k] == 1)
            return 0;
    }
    return 1;
}

// tip
// n%2 == 1			같은패턴 1/4 블록 개수 = (n/2)(n/2+1)	*4	+1(하나 따로 계산)
// n%2 == 0			같은패턴 1/4 블록 개수 = (n/2)^2			*4
// 사실상 8등분도 가능하긴 한데
// 블록개수 필요한가? 필요없을수도
