# define  _CRT_SECURE_NO_WARNINGS
# включить  < stdio.h >
# включить  < stdlib.h >
# include  < time.h >
# включить  < conio.h >
# включить  < locale.h >
# включить  < стек >

используя  пространство имен  std ;

typedef  struct  Node {
	int vertex;
	struct 	Node * next;
} Узел;

void  add_Node_to_beginning (Node ** head, int data) // функция добавления узла в начало
{
	Узел * tmp_node = (Узел *) malloc ( sizeof (Узел)); // создаем новый узел
	tmp_node-> вершина = данные;
	tmp_node-> next = (* голова); // присваиваем указателю tmp адрес след. узел
	(* голова) = tmp_node; // Присваиваем указателю руководитель адрес tmp
} // после выхода из функций tmp уничтожается

Node * findLastHead (Node * head) { // поиск адреса последнего элемента
	if (head == NULL ) {
		return  NULL ;
	}
	while (head-> next ) {
		head = head-> next ;
	}
	вернуть голову;
}

void  add_Node_to_end (Node * head, int data) { // функция добавления нового узла в конец
	Узел * last = findLastHead (голова); // получить указатель на последний элемент списка
	Узел * tmp_node = (Узел *) malloc ( sizeof (Узел)); // создаем новый узел
	tmp_node-> вершина = данные;
	tmp_node-> next = NULL ;
	последний-> следующий = tmp_node; // записываем в последний элемент списка указатель на новый узел
}

void  createLinkedList ( int ** a, Node ** head, int n) // создаем связный список
{
	для ( int i = 0 ; i <n; i ++)
	{
		add_Node_to_beginning (& head [i], i); // передаем адрес вершины и ее номер
		для ( int j = 0 ; j <n; j ++)
		{
			если (a [i] [j] == 1 )
			{
				add_Node_to_end (голова [i], j); // добавляем к вершине связные с ней вершины
			}
		}
	}
}


void  printLinkedList ( const Node * head) {
	printf ( " \ п " );
	while (head) {
		printf ( " % d -> " , head-> vertex + 1 );
		head = head-> next ;
	}
	printf ( " \ п " );
}

void  DFS ( int ** a, bool * hibited , int n, int v) // поиск в глубину, v - текущая вершина, n - кол-во вершин, a - массив
{
	printf ( " % d " , v + 1 );
	посетил [v] = true ; // помещаем текущюю вершину
	для ( int i = 0 ; i <n; i ++)
	{
		if (a [v] [i] == 1 && loaded [i] == false ) // проверяем семейные с ней вершины
		{
			DFS (a, посещено, n, i); // вызываем рекурсию
		}
	}

}


void  DFSlist (узел ** голова, bool * посещено, int v)
{
	printf ( " % d -> " , v + 1 );
	посетил [v] = true ;
	Узел * tmp_node = head [v]; 
	while (tmp_node) // идем по текущей вершине
	{
		если (посетил [tmp_node-> vertex ] == false )
			DFSlist (голова, посещение, tmp_node-> вершина ); // если вершина не посещена то передаем ее адрес и номер и идем дальше по ней
		tmp_node = tmp_node-> следующий ;
	}
}

void  DFS_no_rec ( int ** a, bool * visit , int n, int v) { // обход графа без рекурсии
	стек < int > стек;
	стек. нажать (v);
	а (! стек. пустой ())
	{
		если (посетил [stack. top ()] == false )
		{
			посетил [стек. top ()] = истина ;
			printf ( " % d " , стек. вершина () + 1 );
			v = стек. верх ();
			стек. pop ();
			для ( int i = n - 1 ; i> 0 ; i--)
			{
				if (a [v] [i] == 1 && посетил [i] == false )
				{
					стек. push (i);
				}
			}
		}
		еще
		{
			стек. pop ();
		}
	}
}

void  main ()
{
	setlocale (LC_ALL, « RUS » );
	srand ( время ( NULL ));
	стек < int > стек;
	int ** a, N, число; // N-кол-во вершин, num-вершина для ввода
	printf ( " Укажите размер матрицы N * N: " );
	scanf ( " % d " , & N);
	Node ** head = (Node **) malloc (N * sizeof (Node *));
	for ( int i = 0 ; i <N; i ++) {
		head [i] = NULL ;
	}

	bool * посещено = ( bool *) malloc (N * sizeof ( bool ));
	для ( int i = 0 ; i <N; i ++)
	{
		посетил [я] = ложь ;
	}

	a = ( int **) malloc (N * sizeof ( int *));
	для ( int i = 0 ; i <N; i ++)
	{
		a [i] = ( int *) malloc (N * sizeof ( int ));
	}

	для ( int i = 0 ; i <N; i ++)
	{
		а [я] [я] = 0 ;

		для ( int j = i + 1 ; j <N; j ++)
		{

			a [i] [j] = rand ()% 2 ;
			a [j] [i] = a [i] [j];


		}
	}

	printf ( " \ n Вывод матрицыности \ n  " );

	printf ( " \ п  " );
	printf ( " \ t " );

	for ( int i = 0 ; i <N; i ++) {
		printf ( " % d " , я + 1 );
	}

	for ( int i = 0 ; i <N; i ++) { // вывод матриц средствности

		printf ( " \ п " );
		printf ( " % d \ t " , я + 1 );

		for ( int j = 0 ; j <N; j ++) {
			printf ( " % d " , a [i] [j]);
		}


	}

	printf ( " \ n Введите вершину для начала обхода графа в глубину: " );
	scanf ( " % d " , & num);
	число--;


	printf ( " \ n \ n Рекурсивный проход в глубину по матрице материи: " );
	DFS (a, посещено, N, число);
	printf ( " \ п " );

	для ( int i = 0 ; i <N; i ++)
		посетил [я] = ложь ;

	createLinkedList (a, голова, N);
	printf ( " \ n Создадим список возможностей: " );
	для ( int i = 0 ; i <N; i ++)
		printLinkedList (голова [я]);

	printf ( " \ n Рекурсивный проход в глубину по списку смежности: " );
	DFSlist ( заголовок , посещение, число);
	printf ( " \ п " );

	for ( int i = 0 ; i <N; i ++) {
		посетил [я] = ложь ;
	}

	printf ( " \ n Проход в глубину по матрице матрицы без рекурсивной функции: " );
	DFS_no_rec (a, посещено, N, число);
	printf ( " \ п \ п " );
	_getch;
}
