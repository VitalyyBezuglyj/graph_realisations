#include "arc_graph.h"

CArcGraph::CArcGraph(size_t num) {
	num_of_vertices = num;
	to_vertices_list.clear();
	from_vertices_list.clear();
}

CArcGraph::CArcGraph(const I_Graph *x_graph) {
	num_of_vertices = x_graph->vertices_count();
	v_int vertices;
	for (int vertex = 0; vertex < num_of_vertices; ++vertex){
		vertices.clear();
		x_graph->get_next_vertices(vertex,vertices);
		for(int v : vertices){
			to_vertices_list.push_back(v);
			from_vertices_list.push_back(vertex);
		}
	}
}

size_t CArcGraph::vertices_count() const {
	return num_of_vertices;
}

void CArcGraph::add_edge(int from, int to) {
	size_t necessary_num = std::max(from, to);
	if (num_of_vertices < necessary_num + 1) {
		num_of_vertices = necessary_num + 1;
	}
	to_vertices_list.push_back(to);
	from_vertices_list.push_back(from);
}

void CArcGraph::get_next_vertices(int vertex, v_int &vertices) const {
	int counter = 0;
	for(int v : from_vertices_list){
		if(v==vertex){
			vertices.push_back(to_vertices_list[counter]);
		}
		++counter;
	}
}

void CArcGraph::get_prev_vertices(int vertex, v_int &vertices) const {
	int counter = 0;
	for(int v : to_vertices_list){
		if(v==vertex){
			vertices.push_back(from_vertices_list[counter]);
		}
		++counter;
	}
}