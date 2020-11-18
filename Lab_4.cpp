#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>
#include <stack>

using namespace std;

typedef struct Node { 
	int vertex; 
	struct	Node *next; 
} Node;

void add_Node_to_beginning(Node **head, int data) //функция добавления узла в начало
{
	Node* tmp_node = (Node*)malloc(sizeof(Node)); // создаем новый узел
	tmp_node->vertex = data; 
	tmp_node->next = (*head); //присваиваем указателю tmp адрес след. узла
	(*head) = tmp_node; //Присваиваем указателю head адрес tmp
} //после выхода из функции tmp уничтожается

Node* findLastHead(Node* head) { //поиск адреса последнего элемента
	if (head == NULL) {
		return NULL;
	}
	while (head->next) {
		head = head->next;
	}
	return head;
}

void add_Node_to_end(Node* head, int data) { //функция добавления нового узла в конец
	Node* last = findLastHead(head); //получаем указатель на последний элемент списка
	Node* tmp_node = (Node*)malloc(sizeof(Node)); // создаем новый узел
	tmp_node->vertex = data; 
	tmp_node->next = NULL; 
	last->next = tmp_node; //записываем в последний элемент списка указатель на новый узел
}

void createLinkedList(int** a, Node** head, int n) //создаем связный список
{
	for (int i = 0; i < n; i++)
	{
		add_Node_to_beginning(&head[i], i); //передаем адрес вершины и ее номер 
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1)
			{
				add_Node_to_end(head[i], j); //добавляем к вершине связные с ней вершины
			}
		}
	}
}


void printLinkedList(const Node* head) {
	printf("\n");
	while (head) {
		printf("%d -->", head->vertex+1);
		head = head->next;
	}
	printf("\n");
}

void DFS(int** a, bool* visited, int n, int v) //поиск в глубину, v - текущая вершина, n - кол-во вершин, a - массив
{
	printf("%d ", v +1);
	visited[v] = true; //помещаем текущюю вершину
	for (int i = 0; i < n; i++)
	{
		if (a[v][i] == 1 && visited[i] == false) //проверяем смежные с ней вершины
		{
			DFS(a, visited, n, i); //вызываем рекурсию
		}
	}

}


void DFSlist(Node** head, bool* visited, int v)
{
	printf("%d-->", v + 1);
	visited[v] = true;
	Node* tmp_node = head[v]; 
	while (tmp_node) //идем по текущей вершине
	{
		if (visited[tmp_node->vertex] == false)
			DFSlist(head, visited, tmp_node->vertex); //если вершина не посещена то передаем ее адрес и номер и идем дальше по ней
		tmp_node = tmp_node->next;
	}
}

void DFS_no_rec(int** a, bool* visited, int n, int v){ //обход графа без рекурсии
	stack <int> stack;
	stack.push(v);
	while (!stack.empty())
	{
		if (visited[stack.top()] == false)
		{
			visited[stack.top()] = true;
			printf("%d ", stack.top() + 1);
			v = stack.top();
			stack.pop();
			for (int i = n - 1; i > 0; i--)
			{
				if (a[v][i] == 1 && visited[i] == false)
				{
					stack.push(i);
				}
			}
		}
		else
		{
			stack.pop();
		}
	}
}

void main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	stack <int> stack;
	int** a, N, num; //N-кол-во вершин, num-вершина для ввода
	printf("Укажите размер матрицы N*N: ");
	scanf("%d", &N);
	Node** head = (Node**)malloc(N * sizeof(Node*));
	for (int i = 0; i < N; i++) {
		head[i] = NULL;
	}

	bool* visited = (bool*)malloc(N * sizeof(bool));
	for (int i = 0; i < N; i++)
	{
		visited[i] = false;
	}

	a = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		a[i] = (int*)malloc(N * sizeof(int));
	}

	for (int i = 0; i < N; i++) 
	{
		a[i][i] = 0;

		for (int j = i + 1; j < N; j++)
		{

			a[i][j] = rand() % 2;
			a[j][i] = a[i][j];


		}
	}

	printf("\n Вывод матрицы смежности\n ");

	printf("\n ");
	printf("\t");

	for (int i = 0; i < N; i++) {
		printf("%d", i+1);
	}

	for (int i = 0; i < N; i++) { // вывод матриц смежности

		printf("\n");
		printf("%d\t", i+1);

		for (int j = 0; j < N; j++) {
			printf("%d", a[i][j]);
		}


	}

	printf("\nВведите вершину для начала обхода графа в глубину : ");
	scanf("%d", &num);
	num--;


	printf("\n\nРекурсивный проход в глубину по матрице смежности : ");
	DFS(a, visited, N, num);
	printf("\n");

	for (int i = 0; i < N; i++)
		visited[i] = false;

	createLinkedList(a, head, N);
	printf("\nСоздадим список смежности: ");
	for (int i = 0; i < N; i++)
		printLinkedList(head[i]);

	printf("\nРекурсивный проход в глубину по списку смежности : ");
	DFSlist(head, visited, num);
	printf("\n");

	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}

	printf("\nПроход в глубину по матрице смежности без рекурсивной функции: ");
	DFS_no_rec(a, visited, N, num);
	printf("\n\n");
	_getch;
}
