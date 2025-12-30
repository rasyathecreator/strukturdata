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