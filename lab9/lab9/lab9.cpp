#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <queue>

#define MAX_SIZE 10000

void BFSD(int** G, int size_G, int v, int* DIST) {
	std::queue<int> q;
	q.push(v);

	DIST[v] = 0;

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 0; i < size_G; i++) {
			if (G[v][i] == 1 && DIST[i] == -1) {
				q.push(i);
				DIST[i] = DIST[v] + 1;
			}
		}
	}
	//printf("\n");


	/*int queue[MAX_SIZE] = { 0 };
	int front = 0, rear = 0;
	queue[rear++] = v;

	int** NUM = (int**)malloc(size_G * sizeof(int*));
	for (int i = 0; i < size_G; i++) {
		NUM[i] = (int*)calloc(size_G, sizeof(int));
	}


	while (front != rear) {
		int current_vertex = queue[front++];

		for (int i = 0; i < size_G; i++) {
			if (G[current_vertex][i] == 1 && !visited[i]) {
				queue[rear++] = i;
				visited[i] = true;

				int y = 0;
				while (NUM[current_vertex][y] != 0) {
					NUM[i][y] = NUM[current_vertex][y];
					y++;
				}

				while (NUM[i][y] != 0)
					y++;
				NUM[i][y] = current_vertex + 1;
				DIST[i] = DIST[current_vertex] + 1;
			}
		}
	}*/
	//for (int i = 0; i < size_G; i++)
	//	free(NUM[i]);
	//free(NUM);

}

void POSH(int** matrix, int size, int v, int* DIST) {
	for (int i = 0; i < size; i++) {
		DIST[i] = -1;
	}
	BFSD(matrix, size, v, DIST);
	//printf("\nDIST vector: \n");
	for (int i = 0; i < size; i++) {
		//printf("%d ", DIST[i]);
	}

}



void DFS(int** vertex, int first, int** matrix, int count, int dst) {
	vertex[1][first] = false;

	printf("vertex: %d", vertex[0][first]);
	printf(" dst: %d\n", dst);

	for (int i = 0; i < count; i++) {
		if (matrix[first][i] == 1 and vertex[1][i] == true) {
			DFS(vertex, i, matrix, count, ++dst);
		}
	}

}

void POG(int** matrix, int count, int i) {
	int** NUM = (int**)malloc(2 * sizeof(int*));
	for (int i = 0; i < 2; i++)
		NUM[i] = (int*)malloc(count * sizeof(int));

	for (int i = 0; i < count; i++) {
		NUM[0][i] = i + 1;
		NUM[1][i] = true;
	}

	int clearVertex = count;

	for (int i = 0; i < count; i++) {
		if (NUM[1][i] == false) {
			continue;
		}
		DFS(NUM, i, matrix, count, 0);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setbuf(stdout, NULL);

	int size, v = 0;
	printf("Enter a count of headers: ");
	scanf(" %d", &size);

	srand(time(NULL)); //

	int** matrix = (int**)calloc(size, sizeof(int*));
	for (int i = 0; i < size; i++) {
		matrix[i] = (int*)calloc(size, sizeof(int));
	}

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			int random = rand() % 2; //    0  1
			matrix[i][j] = random;
			matrix[j][i] = random; //
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	printf("Enter the source vertex: ");
	scanf("%d", &v);
	v--;
	if (v < 0) {
		v = 0;
	}

	int* DIST = (int*)calloc(MAX_SIZE + 1, sizeof(int));


	clock_t time_start = clock();
	POSH(matrix, size, v, DIST);
	clock_t time_end = clock();
	double diff = (time_end - time_start) / CLOCKS_PER_SEC;


	printf("\nDIST vector:\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", DIST[i]);
	}

	// 2
	printf("\n\n--TASK 2--\n\n");
	clock_t time_start2 = clock();
	POG(matrix, size, v);
	clock_t time_end2 = clock();
	double diff2 = time_end2 - time_start2;

	printf("\ntime elapsed : %fms\n", diff);
	printf("time elapsed2: %fms\n", diff2);


}




