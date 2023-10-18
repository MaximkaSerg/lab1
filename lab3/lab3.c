#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct node {
	char inf[256];  // �������� ����������
	struct node* next; // ������ �� ��������� �������
} node;

struct node* head = NULL, * last = NULL, * f = NULL; // ��������� �� ������ � ��������� �������� ������
int dlinna = 0;

// ������� ���������� ��������, ��������� ������
void spstore(void), review(void), del(char* name);

char find_el[256];
struct node* find(char* name); // ������� ���������� ��������
struct node* get_struct(void); // ������� �������� ��������

struct node* get_struct(void) {
	struct node* p = NULL;
	char s[256];

	if ((p = calloc(1, sizeof(struct node))) == NULL) {
		printf("������ ��� ������������� ������\n");
		exit(1);
	}

	printf("������� �������� �������: \n");   // ������ ������
	scanf("%s", s);
	if (*s == 0) {
		printf("������ �� ���� �����������\n");
		return NULL;
	}
	strcpy(p->inf, s);

	p->next = NULL;

	return p;		// ���������� ��������� �� ��������� �������
}

/* ���������������� ���������� � ������ �������� (� �����)*/
void spstore(void) {
	struct node* p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL) { // ���� ������ ���, �� ������������� ������ ������
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) { // ������ ��� ����, �� ��������� � �����
		last->next = p;
		last = p;
	}
	return;
}

void spstore2(void) {
	struct node* p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL) { // ���� ������ ���, �� ������������� ������ ������
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) { // ������ ��� ����, �� ��������� � ������
		p->next = head;
		head = p;
	}
	return;
}

/* �������� ����������� ������. */
void review(void) {
	struct node* struc = head;
	if (head == NULL) {
		printf("������ ����\n");
	}
	while (struc) {
		printf("��� - %s, \n", struc->inf);
		struc = struc->next;
	}
	return;
}

/* ����� �������� �� �����������. */
struct node* find(char* name) {
	struct node* struc = head;
	if (head == NULL) {
		printf("������ ����\n");
	}
	while (struc) {
		if (strcmp(name, struc->inf) == 0) {
			return struc;
		}
		struc = struc->next;
	}
	printf("������� �� ������\n");
	return NULL;
}

/* �������� �������� �� �����������. */
void del(char* name) {
	struct node* struc = head; // ���������, ���������� �� ������ ���������� �� ������ ������
	struct node* prev = NULL; // ��������� �� �������������� ���������� �������
	int flag = 0;      // ��������� ���������� ���������� �������� � ������

	if (head == NULL) { // ���� ������ ������ ����� NULL, �� ������ ����
		printf("������ ����\n");
		return;
	}

	if (strcmp(name, struc->inf) == 0) { // ���� ��������� ������� - ������
		flag = 1;
		head = struc->next; // ������������� ������ �� ��������� �������
		free(struc);  // ������� ������ �������
		struc = head; // ������������� ��������� ��� ����������� ������
	}
	else {
		prev = struc;
		struc = struc->next;
	}

	while (struc) { // ������ �� ������ � ����� ���������� ��������
		if (strcmp(name, struc->inf) == 0) { // ���� �����, ��
			flag = 1;         // ���������� ���������
			if (struc->next) { // ���� ��������� ������� �� ��������� � ������
				prev->next = struc->next; // ������ ���������
				free(struc); // �������  �������
				struc = prev->next; // ������������� ��������� ��� ����������� ������
			}
			else { // ���� ��������� ������� ��������� � ������
				prev->next = NULL; // �������� ��������� ��������������� ��������
				free(struc); // �������  �������
				return;
			}
		}
		else { // ���� �� �����, ��
			prev = struc; // ������������� ��������� ��� ����������� ������
			struc = struc->next;
		}
	}

	if (flag == 0) { // ���� ���� = 0, ������ ������ ������� �� ������
		printf("������� �� ������\n");
		return;
	}

}

/*
 *   3333
 *       3
 *       3
 *   3333
 *       3
 *       3
 *   3333
 */

typedef struct PQobj {
	node* inf;  // �������� ����������
	int prior;
} PQobj;

void qp() {
	printf("��������� �������:\n");
	int i2 = 15;

	int q_size = 0;
	PQobj* q = NULL;

	for (int i = 1; i <= i2; i++) {
		printf("�������� ��������: 1 - ��������, 2 - ��������, 3 - ������� (%d/%d)\n", i, i2);

		int act = 0;
		scanf("%d", &act);

		if (act == 1) {
			q_size++;
			q = realloc(q, sizeof(PQobj) * q_size);

			node* inf = get_struct();
			int prior = 0;
			printf("������� ���������:\n");
			scanf("%d", &prior);

			q[q_size - 1].inf = inf;
			q[q_size - 1].prior = prior;

			for (int i3 = 0; i3 < q_size; i3++) {
				for (int i4 = 0; i4 < q_size; i4++) {
					if (i3 == i4)
						continue;
					PQobj n1 = q[i3];
					PQobj n2 = q[i4];

					if (n1.prior > n2.prior) {
						q[i3] = n2;
						q[i4] = n1;
					}
				}
			}
		}
		else if (act == 2) {
			for (int i3 = 0; i3 < q_size; i3++) {
				PQobj n1 = q[i3];
				printf("%s -- ��������� %d\n", n1.inf->inf, n1.prior);
			}
		}
		else if (act == 3) {
			if (!q_size) {
				printf("������ �������\n");
				continue;
			}
			free(q[0].inf);
			q_size--;
			memmove(&q[0], &q[1], sizeof(PQobj) * q_size);
			q = realloc(q, sizeof(PQobj) * q_size);
		}
		else {
			printf("��� ������ ��������\n");
		}

	}

	for (int i = 0; i < q_size; i++) {
		free(q[i].inf);
	}
	free(q);
}

void q() {
	printf("�������:\n");
	int i2 = 15;
	for (int i = 1; i <= i2; i++) {
		printf("�������� ��������: 1 - ��������, 2 - ��������, 3 - ������� (%d/%d)\n", i, i2);

		int act = 0;
		scanf("%d", &act);

		if (act == 1) {
			spstore();
		}
		else if (act == 2) {
			review();
		}
		else if (act == 3) {
			if (head) {
				printf("������: %s\n", head->inf);
				del(head->inf);
			}
			else {
				printf("������ �������\n");
			}
		}
		else {
			printf("��� ������ ��������\n");
		}
	}
	printf("\n");
}

void stack() {
	printf("����:\n");
	int i2 = 15;
	for (int i = 1; i <= i2; i++) {
		printf("�������� ��������: 1 - ��������, 2 - ��������, 3 - ������� (%d/%d)\n", i, i2);

		int act = 0;
		scanf("%d", &act);

		if (act == 1) {
			spstore2();
		}
		else if (act == 2) {
			review();
		}
		else if (act == 3) {
			if (head) {
				printf("������: %s\n", head->inf);
				del(head->inf);
			}
			else {
				printf("������ �������\n");
			}
		}
		else {
			printf("��� ������ ��������\n");
		}
	}
	printf("\n");
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setbuf(stdout, NULL);

	qp();
	q();
	stack();

}
