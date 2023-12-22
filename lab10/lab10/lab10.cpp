#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <queue>
#include <clocale>

#define MAX_NODES 400

// Функция для генерации случайной матрицы смежности
void generateRandomGraph(int graph[MAX_NODES][MAX_NODES], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                graph[i][j] = 0; // Нет петель
            }
            else {
                int random_value = rand() % n; // Генерируем 0 или 1
                graph[i][j] = random_value;
                graph[j][i] = random_value; // Граф неориентированный
            }
        }
    }
}

// Функция для поиска расстояний в графе с использованием BFS
int bfs(int graph[MAX_NODES][MAX_NODES], int n, int startNode) {
    bool visited[MAX_NODES] = { false };
    int distances[MAX_NODES] = { 0 };
    std::queue<int> q;



    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        for (int i = 0; i < n; i++) {
            if (graph[currentNode][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
                distances[i] = distances[currentNode] + graph[startNode][i];
            }
        }
    }

    // Выводим расстояния от startNode до всех остальных узлов
    for (int i = 0; i < n; i++) {
        //printf("\nРасстояние от ребра %d до ребра %d: %d\n", startNode+1, i+1, distances[i]);
    }



    int max = 0;
    for (int i = 0; i < n; i++) {
        if (distances[i] > max) {
            max = distances[i];
        }

    }

    return max;
    /*for (int i = 0;i < n;i++) {
        if (distances[i] == min) {
            min = distances[i];
        }


    }

    printf("\nРадиус равен: %d\nДиаметр равен: %d\n", min, max);


    int midlle[MAX_NODES] = { 0 };
    int perf[MAX_NODES] = { 0 };


    printf("\nПодмножество центральных вершин: ");

    for (int i = 0;i < n;i++) {
        if (distances[i] == min) {
            printf("%d ", i+1);
        }
    }


    printf("\nПодмножество перефирийнных вершин: ");


    for (int i = 0;i < n;i++) {
        if (distances[i] == max) {
            printf("%d ", i+1);
        }
    }*/

}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL)); // Инициализируем генератор случайных чисел

    int n; // Количество узлов в графе
    printf("Введите количество ребер в графе: ");
    scanf("%d", &n);

    int graph[MAX_NODES][MAX_NODES] = { 0 };

    generateRandomGraph(graph, n);

    // Выводим матрицу смежности
    printf("Матрица смежности графа:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    int startNode;
    printf("Введите начальный узел для поиска расстояний: ");
    scanf("%d", &startNode);
    startNode = startNode - 1;

    //int x = bfs(graph, n, 0);
    int min = 100;
    int max = 0;

    for (int i = 0; i < n; i++) {
        int x = bfs(graph, n, i);
        printf("Эксцентриситет %d вершины: %d\n", i + 1, x);
        if (x < min) {
            min = x;
        }
        if (x > max) {
            max = x;
        }

    }

    printf("\nРадиус: %d\nДиаметр графа: %d\n", max, min);

    printf("\nПодмножество центральных вершин: ");

    for (int i = 0; i < n; i++) {
        int x = bfs(graph, n, i);
        if (x == min) {
            printf("%d ", i + 1);
        }
    }

    printf("\nПодмножество перефирийнных вершин: ");

    for (int i = 0; i < n; i++) {
        int x = bfs(graph, n, i);
        if (x == max) {
            printf("%d ", i + 1);
        }

    }

    return 0;
}