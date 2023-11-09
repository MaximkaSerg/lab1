#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int DFS(int first, int** matrix, int count, int* NUM)
{
    NUM[first] = true;
    printf("%d ", first);

    for (int i = 0; i < count; i++)
    {
        if (matrix[first][i] == 1 and NUM[i] == false)
        {
            DFS(i, matrix, count, NUM);
        }
    }
    return 0;
}

int main()
{
    int count = 0;
    printf("Enter count of vertices: ");
    scanf("%d", &count);

    srand(time(NULL));

    int** matrix = (int**)malloc(count * sizeof(int*));
    for (int i = 0; i < count; i++)
    {
        matrix[i] = (int*)malloc(count * sizeof(int));
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            matrix[j][i] = 0;
        }
    }

    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            int random = rand() % 2;
            matrix[i][j] = random;
            matrix[j][i] = random;
        }
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");

    int* NUM = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < count; i++)
    {
        NUM[i] = false;
    }

    int i = 0;
    printf("Enter vertex number from which would you prefer to start: ");
    scanf("%d", &i);

    DFS(i, matrix, count, NUM);
}