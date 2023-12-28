import random
import queue
import matplotlib.pyplot as plt


def titulniyList():
    print("\n Министерство науки и высшего образования Российской Федерации")
    print(" Пензенский государственный университет")
    print(" Кафедра «Вычислительная кафедра»\n")
    print(" КУРСОВОЙ ПРОЕКТ")
    print(" по дисциплине:\n ЛОГИКА И ОСНОВЫ АЛГОРИТМИЗАЦИИ В ИНЖЕНЕРНЫХ ЗАДАЧАХ")
    print(" тема проекта:\n Алгоритм поиска кратчайшего пути в лабиринте\n\n")
    print(" Выполнил:\n студент группы 22ВВВ2\n Сергунов М.Р. \n\n")
    print(" Принял:\n Акифьев И.В.\n\n Пенза 2023\n")


def generate_random_maze(rows, cols):
    density = 0.3  # Пример значения плотности, можно настроить по вашему усмотрению
    maze = [[random.choice([0, 1]) for _ in range(cols)] for _ in range(rows)]

    for _ in range(rows * cols // 2):
        row = random.randint(0, rows - 1)
        col = random.randint(0, cols - 1)
        maze[row][col] = 0

    maze[0][0] = 0  # Start point
    maze[rows - 1][cols - 1] = 0  # End point
    return maze


def print_matrix(matrix):
    for row in matrix:
        print(" ".join(map(str, row)))


def write_to_file(matrix, result, path, filename):
    if not filename.endswith('.txt'):
        filename += '.txt'

    with open(filename, "w") as file:
        # Записываем матрицу в файл
        file.write("Матрица:\n")
        for row in matrix:
            file.write(" ".join(map(str, row)) + "\n")

        # Записываем результат поиска кратчайшего пути, или "No path found", если результат равен -1
        if result != -1:
            file.write("\nДлина кратчайшего пути:" + str(result))
            file.write("\nКратчайший путь:" + " -> ".join(map(str, path)))
        else:
            file.write("\nПуть не найден")


def read_from_file(filename):
    with open(filename, "r") as file:
        matrix = []
        for line in file:
            if line.strip() == "Матрица:":
                break
        for line in file:
            if not line.strip():
                break
            matrix.append(list(map(int, line.strip().split())))
    return matrix


def create_matrix_from_input():
    while True:
        try:
            rows = int(input("Введите количество строк: "))
            cols = int(input("Введите количество столбцов: "))
            if rows <= 0 or cols <= 0:
                raise ValueError("Строки и столбцы должны быть целыми положительными числами.")
            break  # Если пользователь ввел корректные значения, выходим из цикла
        except ValueError as e:
            print(f"Error: {e}")

    matrix = []
    for _ in range(rows):
        while True:
            try:
                row = list(map(int, input("Введите строку (целые числа, разделенные пробелом): ").split()))
                if len(row) != cols or any(val not in {0, 1} for val in row):
                    raise ValueError(f"Недопустимая строка. Она должна содержать целые числа {cols} (0 или 1).")
                break  # Если пользователь ввел корректную строку, выходим из цикла
            except ValueError as e:
                print(f"Ошибка: {e}")
        matrix.append(row)
    return matrix


def shortest_path(matrix):
    rows, cols = len(matrix), len(matrix[0])
    directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

    q = queue.Queue()
    q.put((0, 0, 0, [(0, 0)]))  # (row, col, distance, path)
    visited = set()

    while not q.empty():
        row, col, dist, path = q.get()

        if (row, col) == (rows - 1, cols - 1):
            return dist+1, path

        for dr, dc in directions:
            nr, nc = row + dr, col + dc
            if 0 <= nr < rows and 0 <= nc < cols and matrix[nr][nc] == 0 and (nr, nc) not in visited:
                q.put((nr, nc, dist + 1, path + [(nr, nc)]))
                visited.add((nr, nc))

    return -1, []  # No path found


def plot_path(matrix, path):
    rows, cols = len(matrix), len(matrix[0])
    path_matrix = [[0] * cols for _ in range(rows)]

    for node in path:
        path_matrix[node[0]][node[1]] = 1

    plt.imshow(path_matrix, cmap='Blues', interpolation='nearest')
    plt.title('Кратчайший путь')
    plt.show()


if __name__ == "__main__":
    titulniyList()
    while True:
        try:
            print("1. Генерировать случайную матрицу")
            print("2. Считывание матрицы из файла")
            print("3. Создать матрицу из входных данных")
            print("4. Выход")

            choice = int(input("Выберите из (1/2/3/4): "))
            if choice == 4:
                break

            if choice not in {1, 2, 3}:
                raise ValueError("Неверный выбор. Пожалуйста, введите 1, 2, 3 или 4.")

            if choice == 1:
                while True:
                    try:
                        rows = int(input("Введите количество строк: "))
                        cols = int(input("Введите количество столбцов: "))
                        if rows <= 0 or cols <= 0:
                            raise ValueError("Строки и столбцы должны быть целыми положительными числами.")
                        break  # Если пользователь ввел корректные значения, выходим из цикла
                    except ValueError as e:
                        print(f"Error: {e}")
                maze = generate_random_maze(rows, cols)
            elif choice == 2:
                filename = input("Введите название файла: ")
                maze = read_from_file(filename)
            elif choice == 3:
                maze = create_matrix_from_input()

            print("\nМатрица:")
            print_matrix(maze)

            result, path = shortest_path(maze)

            if result != -1:
                print("\nДлина кратчайшего пути:", result)
                print("\nКратчайший путь:", path)
                plot_path(maze, path)
            else:
                print("\nПуть не найден.")

            while True:
                write_choice = input("Вы хотите записать матрицу в файл? (y/n): ")
                if write_choice.lower() in {'y', 'n'}:
                    break
                else:
                    print("Некорректный выбор. Пожалуйста, введите 'y' or 'n'.")

            if write_choice.lower() == 'y':
                filename = input("Введите имя файла: ")
                write_to_file(maze, result, path, filename)
        except ValueError as e:
            print(f"Ошибка: {e}")
