#ifndef GRAPH_REALIZATIONS_1_ARC_GRAPH_H
#define GRAPH_REALIZATIONS_1_ARC_GRAPH_H

#endif //GRAPH_REALIZATIONS_1_ARC_GRAPH_H

#include "i_graph.h"

struct CArcGraph : public I_Graph {
	explicit CArcGraph(size_t num);
	explicit CArcGraph(const I_Graph *);

	void add_edge(int from, int to) override;
	size_t vertices_count() const override;

	void get_next_vertices(int vertex, v_int &vertices) const override;
	void get_prev_vertices(int vertex, v_int &vertices) const override;
 private:
	v_int to_vertices_list;
	v_int from_vertices_list;
	size_t num_of_vertices;
};