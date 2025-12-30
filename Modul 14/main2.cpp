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