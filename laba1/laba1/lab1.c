#define _CRT_SECURE_NO_WARNINGS
#define M 4
#define N 5
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
        printf("\n%d", st, "\n");
    }
    return 0;
}
int zadanie5() {
        setvbuf(stdin, NULL, _IONBF, 0);
        setvbuf(stdout, NULL, _IONBF, 0);
        int i;
        struct student
        {
            char famil[20];
            char name[20], facult[20];
            int Nomzach;
        } stud[3];

        for (i = 0; i < 3; i++)
        {
            printf("Введите фамилию студента\n"); scanf("%20s", stud[i].famil);
        }
        for (i = 0; i < 3; i++)
        {
            printf("Введите имя студента %s\n", stud[i].famil); scanf("%20s", stud[i].name);
        }
        for (i = 0; i < 3; i++)
        {
            printf("Введите название факультета студента %s %s\n", stud[i].famil, stud[i].name); scanf("%20s", stud[i].facult);
        }
        for (i = 0; i < 3; i++)
        {
            printf("Введите номер зачётной книжки студента %s %s\n", stud[i].famil, stud[i].name); scanf("%d", &stud[i].Nomzach);
        }

        for (i = 0; i < 3; i++)
        {
            printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n", stud[i].famil, stud[i].name,
                stud[i].facult, stud[i].Nomzach);
        }
        char sname[20], fname[20], numb[20], faq[20];
        printf("\nВведите фамилии: ");
        scanf("%s", &sname);
        printf("\nВведите имя: ");
        scanf("%s", &fname);
        printf("\nВведите факультет: ");
        scanf("%s", &faq);
        printf("\nВведите номер зачетной: ");
        scanf("%s", &numb);

        for (i = 0; i < 3; i++) {
            if (strcmp(sname, stud[i].famil) == 0) {
                printf("Cтудент %s %s обучается на факультете %s, номер зачётной книжки %d \n", stud[i].famil, stud[i].name,
                    stud[i].facult, stud[i].Nomzach);
}
int main(void) {   
    setlocale(0,"rus");
    /*zadanie1();
    zadanie2();
    zadanie3();
    zadanie4();*/
    zadanie5();
}








