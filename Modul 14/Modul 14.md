# <h1 align="center">Laporan Praktikum Modul 14 GRAPH</h1>
<p align="center">Rasya Syahri Ramadhan - 103112430189</p>

## Dasar Teori
Multi linked list merupakan varian linked list yang lebih kompleks, di mana setiap node memiliki lebih dari dua pointer untuk menghubungkan ke multiple node lain, memungkinkan struktur relasional seperti one-to-many atau many-to-many. Struktur ini sering digunakan untuk merepresentasikan hubungan data yang tidak linier sederhana, berbeda dari single atau doubly linked list.[2][4][5][8]

### Definisi
Multi linked list, juga disebut multiple linked list, adalah senarai berantai dengan multiple link atau pointer per node, memungkinkan navigasi ke beberapa arah atau kelompok node terkait. Contohnya, node pegawai dapat memiliki pointer ke multiple node anak, membentuk hubungan 1-N tanpa duplikasi data.[4][5][9]

### Komponen Node
Setiap node berisi data dan beberapa pointer (lebih dari dua), seperti ptr1, ptr2, dst., yang masing-masing menunjuk ke node berbeda dalam list terpisah tapi saling terkait. Ini memerlukan manajemen pointer kompleks untuk traversal antar list.[7][8][2]

### Jenis dan Contoh
- **Multi Linked List 1-N**: Satu node parent terhubung ke banyak child, seperti pegawai dan anak-anaknya.[9][10]
- **Multi Linked List N-M**: Multiple parent ke multiple child, mirip graf berarah.[5]
Traversal dilakukan dengan mengikuti pointer spesifik, misal dari pegawai ke daftar anak.[4]

### Operasi Dasar
- **Insertion**: Tambah node child ke pointer spesifik parent.[8]
- **Deletion**: Hapus hubungan pointer tanpa hilang data terkait.[7]
- **Traversal**: Ikuti pointer tertentu untuk akses subset data.[2]

### Kelebihan dan Kekurangan
Multi linked list fleksibel untuk data relasional seperti database sederhana atau family tree, tetapi kompleks dalam implementasi dan traversal O(n) per pointer. Overhead memori tinggi karena multiple pointer.[5][8][4]



## Guided 

### Guided 1
`graf.h`
```C++
#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED

#include <iostream>
using namespace std;

typedef char infoGraph;

struct ElmNode;
struct ElmEdge;

typedef ElmNode *adrNode;
typedef ElmEdge *adrEdge;

struct ElmNode
{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct ElmEdge
{
    adrNode node;
    adrEdge next;
};

struct Graph
{
    adrNode first;
};

// PRIMITIF GRAPH
void CreateGraph(Graph &G);
adrNode AllocateNode(infoGraph X);
adrEdge AllocateEdge(adrNode N);

void InsertNode(Graph &G, infoGraph X);
adrNode FindNode(Graph G, infoGraph X);

void ConnectNode(Graph &G, infoGraph A, infoGraph B);

void PrintInfoGraph(Graph G);

// Traversal
void ResetVisited(Graph &G);
void PrintDFS(Graph &G, adrNode N);
void PrintBFS(Graph &G, adrNode N);

#endif
```
`graf.cpp`
```C++
#include "graf.h"
#include <queue>
#include <stack>

void CreateGraph(Graph &G)
{
    G.first = NULL;
}

adrNode AllocateNode(infoGraph X)
{
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

adrEdge AllocateEdge(adrNode N)
{
    adrEdge P = new ElmEdge;
    P->node = N;
    P->next = NULL;
    return P;
}

void InsertNode(Graph &G, infoGraph X)
{
    adrNode P = AllocateNode(X);
    P->next = G.first;
    G.first = P;
}

adrNode FindNode(Graph G, infoGraph X)
{
    adrNode P = G.first;
    while (P != NULL)
    {
        if (P->info == X)
            return P;
        P = P->next;
    }
    return NULL;
}

void ConnectNode(Graph &G, infoGraph A, infoGraph B)
{
    adrNode N1 = FindNode(G, A);
    adrNode N2 = FindNode(G, B);

    if (N1 == NULL || N2 == NULL)
    {
        cout << "Node tidak ditemukan!\n";
        return;
    }

    // Buat edge dari N1 ke N2
    adrEdge E1 = AllocateEdge(N2);
    E1->next = N1->firstEdge;
    N1->firstEdge = E1;

    // Karena undirected → buat edge balik
    adrEdge E2 = AllocateEdge(N1);
    E2->next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G)
{
    adrNode P = G.first;
    while (P != NULL)
    {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL)
        {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void ResetVisited(Graph &G)
{
    adrNode P = G.first;
    while (P != NULL)
    {
        P->visited = 0;
        P = P->next;
    }
}

void PrintDFS(Graph &G, adrNode N)
{
    if (N == NULL)
        return;

    N->visited = 1;
    cout << N->info << " ";

    adrEdge E = N->firstEdge;
    while (E != NULL)
    {
        if (E->node->visited == 0)
        {
            PrintDFS(G, E->node);
        }
        E = E->next;
    }
}

void PrintBFS(Graph &G, adrNode N)
{
    if (N == NULL)
        return;

    queue<adrNode> Q;
    Q.push(N);

    while (!Q.empty())
    {
        adrNode curr = Q.front();
        Q.pop();

        if (curr->visited == 0)
        {
            curr->visited = 1;
            cout << curr->info << " ";

            adrEdge E = curr->firstEdge;
            while (E != NULL)
            {
                if (E->node->visited == 0)
                {
                    Q.push(E->node);
                }
                E = E->next;
            }
        }
    }
}
```
`main.cpp `
```C++
#include "graf.h"
#include <iostream>
using namespace std;

int main()
{
    Graph G;
    CreateGraph(G);

    // Tambah node
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');

    // Hubungkan node (graph tidak berarah)
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'C');
    ConnectNode(G, 'B', 'D');
    ConnectNode(G, 'C', 'E');

    cout << "=== Struktur Graph ===\n";
    PrintInfoGraph(G);

    cout << "\n=== DFS dari Node A ===\n";
    ResetVisited(G);
    PrintDFS(G, FindNode(G, 'A'));

    cout << "\n\n=== BFS dari Node A ===\n";
    ResetVisited(G);
    PrintBFS(G, FindNode(G, 'A'));

    cout << endl;
    return 0;
}
```
### Screenshot Output
<img width="709" height="349" alt="image" src="https://github.com/user-attachments/assets/1421f9ca-695c-4115-a826-df96ebb61ee2" />

Ketiga file ini bekerja sama untuk mengimplementasikan dan mensimulasikan struktur data graf tidak berarah (undirected graph). graf.h berfungsi sebagai header yang mendefinisikan kerangka dasar program, mencakup struktur data ElmNode untuk menyimpan simpul dan ElmEdge untuk menyimpan hubungan antar simpul, serta mendeklarasikan prototipe fungsi utama seperti pembuatan graf, penyisipan simpul, dan metode penelusuran.

Logika dari setiap fungsi tersebut diimplementasikan dalam graf.cpp, yang mengatur bagaimana simpul dialokasikan secara dinamis, bagaimana sisi (edge) menghubungkan dua simpul secara timbal balik, serta menyediakan logika penelusuran mendalam menggunakan DFS (Depth First Search) secara rekursif dan penelusuran melebar menggunakan BFS (Breadth First Search) dengan bantuan antrean (queue). Akhirnya, main.cpp berperan sebagai titik masuk program yang mengintegrasikan seluruh komponen tersebut; di dalamnya, sebuah graf dibuat dengan lima simpul (A hingga E), dihubungkan membentuk struktur tertentu, dan ditampilkan hasilnya ke layar untuk memverifikasi bahwa struktur graf dan algoritma penelusuran berjalan dengan benar.

### Full code screenshot
`graf.h`
<img width="1646" height="958" alt="image" src="https://github.com/user-attachments/assets/64c12777-b189-4712-bb6f-a92e67e258e7" />
`graf.cpp`
<img width="1854" height="966" alt="image" src="https://github.com/user-attachments/assets/2705936f-83c3-4cb2-a60f-25bad04a6540" />
`main.cpp`
<img width="1145" height="886" alt="image" src="https://github.com/user-attachments/assets/1acd1260-bc9b-41e1-bbd1-090fd30a65fa" />


## Unguided 
### Buatlah ADT Graph tidak berarah file “graph.h”. Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.
`graph.h`
```C++
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
using namespace std;

typedef char info_graph;

struct elm_node;
struct elm_edge;

typedef elm_node* adr_node;
typedef elm_edge* adr_edge;

struct elm_node
{
	info_graph info;
	int visited;
	adr_edge first_edge;
	adr_node next;
};

struct elm_edge
{
	adr_node node;
	adr_edge next;
};

struct graph
{
	adr_node first;
};

/* primitive graph */
void create_graph(graph &g);
adr_node allocate_node(info_graph x);
adr_edge allocate_edge(adr_node n);

void insert_node(graph &g, info_graph x);
adr_node find_node(graph g, info_graph x);
void connect_node(graph &g, info_graph a, info_graph b);

void print_info_graph(graph g);

/* traversal */
void reset_visited(graph &g);
void print_dfs(graph &g, adr_node start);
void print_bfs(graph &g, adr_node start);

#endif
```

`graph.cpp`
```C++
#include "graph.h"
#include <queue>
#include <stack>

void create_graph(graph &g)
{
	g.first = NULL;
}

adr_node allocate_node(info_graph x)
{
	adr_node p = new elm_node;
	p->info = x;
	p->visited = 0;
	p->first_edge = NULL;
	p->next = NULL;
	return p;
}

adr_edge allocate_edge(adr_node n)
{
	adr_edge p = new elm_edge;
	p->node = n;
	p->next = NULL;
	return p;
}

void insert_node(graph &g, info_graph x)
{
	adr_node p = allocate_node(x);
	p->next = g.first;
	g.first = p;
}

adr_node find_node(graph g, info_graph x)
{
	adr_node p = g.first;
	while (p != NULL)
	{
		if (p->info == x)
			return p;
		p = p->next;
	}
	return NULL;
}

void connect_node(graph &g, info_graph a, info_graph b)
{
	adr_node n1 = find_node(g, a);
	adr_node n2 = find_node(g, b);

	if (n1 == NULL || n2 == NULL)
		return;

	adr_edge e1 = allocate_edge(n2);
	e1->next = n1->first_edge;
	n1->first_edge = e1;

	adr_edge e2 = allocate_edge(n1);
	e2->next = n2->first_edge;
	n2->first_edge = e2;
}

void print_info_graph(graph g)
{
	adr_node p = g.first;
	while (p != NULL)
	{
		cout << p->info << " -> ";
		adr_edge e = p->first_edge;
		while (e != NULL)
		{
			cout << e->node->info << " ";
			e = e->next;
		}
		cout << endl;
		p = p->next;
	}
}

void reset_visited(graph &g)
{
	adr_node p = g.first;
	while (p != NULL)
	{
		p->visited = 0;
		p = p->next;
	}
}

void print_dfs(graph &g, adr_node start)
{
	if (start == NULL)
		return;

	start->visited = 1;
	cout << start->info << " ";

	adr_edge e = start->first_edge;
	while (e != NULL)
	{
		if (e->node->visited == 0)
		{
			print_dfs(g, e->node);
		}
		e = e->next;
	}
}

void print_bfs(graph &g, adr_node start)
{
	if (start == NULL)
		return;

	queue<adr_node> q;
	q.push(start);

	while (!q.empty())
	{
		adr_node x = q.front();
		q.pop();

		if (x->visited == 0)
		{
			x->visited = 1;
			cout << x->info << " ";

			adr_edge e = x->first_edge;
			while (e != NULL)
			{
				if (e->node->visited == 0)
				{
					q.push(e->node);
				}
				e = e->next;
			}
		}
	}
}
```
`main.cpp`
```C++
#include "graph.h"
#include <iostream>
using namespace std;

int main()
{
	graph g;
	create_graph(g);

	insert_node(g, 'A');
	insert_node(g, 'B');
	insert_node(g, 'C');
	insert_node(g, 'D');
	insert_node(g, 'E');
	insert_node(g, 'F');
	insert_node(g, 'G');
	insert_node(g, 'H');

	connect_node(g, 'A', 'B');
	connect_node(g, 'A', 'C');

	connect_node(g, 'B', 'D');
	connect_node(g, 'B', 'E');

	connect_node(g, 'C', 'F');
	connect_node(g, 'C', 'G');

	connect_node(g, 'D', 'H');
	connect_node(g, 'E', 'H');
	connect_node(g, 'F', 'H');
	connect_node(g, 'G', 'H');

	cout << "struktur graph\n";
	print_info_graph(g);

	cout << "\ndfs dari node a\n";
	reset_visited(g);
	print_dfs(g, find_node(g, 'A'));

	cout << "\n\nbfs dari node a\n";
	reset_visited(g);
	print_bfs(g, find_node(g, 'A'));

	cout << endl;
	return 0;
}
```
#### Output:
<img width="919" height="407" alt="image" src="https://github.com/user-attachments/assets/4afa9607-811e-491f-96b6-a66c254182e0" />

Ketiga file program di atas membentuk satu kesatuan implementasi struktur data Graph (Graf) menggunakan metode Adjacency List dalam bahasa pemrograman C++. File graph.h berfungsi sebagai header file yang mendefinisikan kerangka struktur data, mencakup struct elm_node untuk merepresentasikan simpul, elm_edge untuk merepresentasikan hubungan antar simpul, serta deklarasi fungsi-fungsi primitif. Logika dari fungsi-fungsi tersebut kemudian diimplementasikan dalam file graph.cpp, yang mengatur mekanisme pengalokasian memori untuk simpul dan sisi, penyambungan dua simpul secara timbal balik (undirected graph), serta algoritma penelusuran graf menggunakan metode DFS (Depth First Search) secara rekursif dan BFS (Breadth First Search) menggunakan bantuan struktur data queue. Terakhir, file main.cpp berperan sebagai program utama yang mengintegrasikan seluruh komponen tersebut dengan cara membuat objek graf, memasukkan delapan simpul (A hingga H), membangun relasi antar simpul, serta menampilkan hasil penelusuran graf tersebut ke layar pengguna.
