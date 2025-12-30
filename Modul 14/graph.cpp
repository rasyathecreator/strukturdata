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