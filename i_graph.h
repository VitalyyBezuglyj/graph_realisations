
#ifndef GRAPH_REALIZATIONS_1_I_GRAPH_H
#define GRAPH_REALIZATIONS_1_I_GRAPH_H

#endif //GRAPH_REALIZATIONS_1_I_GRAPH_H

#include <iostream>
#include <vector>

typedef std::vector<int> v_int;

struct I_Graph {
	virtual ~I_Graph() {}

	// Добавление ребра от from к to.
	virtual void add_edge(int from, int to) = 0;
	virtual void add_vertex(int from, int to) = 0;
	virtual void rm_edge(int from, int to) = 0;
	virtual void rm_vertex(int from, int to) = 0;
	virtual int find_vertex

	virtual size_t vertices_count() const  = 0;

	virtual void get_next_vertices(int vertex, v_int& vertices) const = 0;
	virtual void get_prev_vertices(int vertex, v_int& vertices) const = 0;
};
