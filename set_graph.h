#ifndef GRAPH_REALIZATIONS_1_SET_GRAPH_H
#define GRAPH_REALIZATIONS_1_SET_GRAPH_H

#endif //GRAPH_REALIZATIONS_1_SET_GRAPH_H

#include "i_graph.h"
#include <set>
typedef std::set<int> s_int;

struct CSetGraph : public I_Graph {
	explicit CSetGraph(size_t num);
	explicit CSetGraph(const I_Graph *);

	void add_edge(int from, int to) override;
	size_t vertices_count() const override;

	void get_next_vertices(int vertex, v_int &vertices) const override;
	void get_prev_vertices(int vertex, v_int &vertices) const override;
 private:
	std::vector<s_int> vertices_sets;
	std::vector<s_int> vertices_sets_reverse;
	size_t num_of_vertices;
	void add_vertexes(int necessary_num);
};