#define _CRT_SECURE_NO_WARNINGS
#define M 4
#define N 5
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int zadanie1() {
    printf("\n/*Задание1*/");
    int temp, n = 10, i = 0;

    int a[10] = { 0,1,2,3,4,5,6,7,8,9 };

    int max1 = a[0];
    int min1 = a[0];
    for (int i = 0; i < 10; ++i) {
        if (a[i] > max1) {
            max1 = a[i];
        }
        if (a[i] < min1) {
            min1 = a[i];
        }

    }
    printf("%d", max1 - min1);
    return 0;
}
int zadanie2() {
    printf("\n/*Задание2*/");
    srand(time(NULL));
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand() % 101;
        printf("%d", arr[i]);
    }
    return 0;
}
int zadanie3() {
    printf("\n/*Задание3*/");
    int razm, * mass, c = 0;
    printf(" \nВведите размер массива: ");
    scanf("%d", &razm);
    srand(time(NULL));
    mass = malloc(razm * sizeof(int));
    printf(" \nСгенерированный массив: ");
    for (c = 0; c < razm; ++c) {
        mass[c] = rand() % 100;
        printf("%d", mass[c]);
    }
    free(mass);
    return 0;
}
int zadanie4() {
    printf("\n/Задание4*/");
    srand(time(NULL));
    int el;
    int matrix[M][N];
    for (int i =0; i<M;++i){
        int st = 0;
        for (int c = 0; c < N; ++c) {
            el = rand() % 100; 
            matrix[i][c] = el;
            st += el;
        }
        printf("\n%d", st,"\n");
    }
    return 0;
}
int zadanie5() {
        setvbuf(stdin, NULL, _IONBF, 0);
        setvbuf(stdout, NULL, _IONBF, 0);

        struct student {
            char famil[20];
            char name[20], facult[20];
            int Nomzach;
        } stud[3];

        // Ввод данных о студентах
        for (int i = 0; i < 3; i++){
            printf("\nВведите фамилию студента %d:", i + 1);
            scanf("%s", stud[i].famil);

            printf("\nВведите имя студента %d:", i + 1);
            scanf("%s", stud[i].name);

            printf("\nВведите название факультета студента %d:", i + 1);
            scanf("%s", stud[i].facult);

            printf("\nВведите номер зачётной книжки студента %d:", i + 1);
            scanf("%d", &stud[i].Nomzach);
        }

        // Поиск структуры с заданными параметрами
        char searchFamil[20];
        char searchName[20];
        int searchNomzach;

        printf("\nВведите фамилию для поиска:");
        scanf("%s", searchFamil);

        printf("\nВведите имя для поиска:");
        scanf("%s", searchName);

        printf("\nВведите номер зачётной книжки для поиска:");
        scanf("%d", &searchNomzach);

        int found = 0; // Флаг для обозначения, было ли найдено совпадение

        for (int i = 0; i < 3; i++)
        {
            if (strcmp(stud[i].famil, searchFamil) == 0 &&
                strcmp(stud[i].name, searchName) == 0 &&
                stud[i].Nomzach == searchNomzach)
            {
                printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d\n",
                    stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);


                found = 1; // Устанавливаем флаг, что нашли совпадение
                break;    // Выходим из цикла, так как совпадение найдено
            }
        }

        if (!found){
            printf("\nСтудент с заданными параметрами не найден.");
        }

        return 0;
}
int main(void) {   
    setlocale(0,"rus");
    zadanie1();
    zadanie2();
    zadanie3();
    zadanie4();
    zadanie5();
}








