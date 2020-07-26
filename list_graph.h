//
// Created by smart_000 on 20.02.2018.
//

#ifndef GRAPH_REALIZATIONS_1_LIST_GRAPH_H
#define GRAPH_REALIZATIONS_1_LIST_GRAPH_H

#endif //GRAPH_REALIZATIONS_1_LIST_GRAPH_H

#include "I_Graph.h"

struct CListGraph : public I_Graph {
	explicit CListGraph(size_t num);
	explicit CListGraph(const I_Graph*);

	void add_edge(int from, int to) override;
	size_t vertices_count() const  override ;

	void get_next_vertices(int vertex, v_int& vertices) const override ;
	void get_prev_vertices(int vertex, v_int& vertices) const override ;
 private:
	std::vector<v_int> vertices_list;
	std::vector<v_int> vertices_list_reverse;
	size_t num_of_vertices;
	void add_vertexes(int necessary_num);
};
