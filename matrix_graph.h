
#ifndef GRAPH_REALIZATIONS_1_MATRIX_GRAPH_H
#define GRAPH_REALIZATIONS_1_MATRIX_GRAPH_H

#endif //GRAPH_REALIZATIONS_1_MATRIX_GRAPH_H

#include "i_graph.h"

struct CMatrixGraph : public I_Graph {
	explicit CMatrixGraph(size_t num);
	explicit CMatrixGraph(const I_Graph*);

	void add_edge(int from, int to) override;
	size_t vertices_count() const  override ;

	void get_next_vertices(int vertex, v_int& vertices) const override ;
	void get_prev_vertices(int vertex, v_int& vertices) const override ;
 private:
	std::vector<v_int> vertices_matrix;
	size_t num_of_vertices;
	void add_vertexes(int necessary_num);
};