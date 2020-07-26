#include "set_graph.h"

CSetGraph::CSetGraph(size_t num) {
	num_of_vertices = num;
	vertices_sets.resize(num_of_vertices);
	vertices_sets_reverse.resize(num_of_vertices);
}

CSetGraph::CSetGraph(const I_Graph *x_graph) {
	num_of_vertices = x_graph->vertices_count();
	vertices_sets.resize(num_of_vertices);
	vertices_sets_reverse.resize(num_of_vertices);
	v_int next_vertices;
	v_int prev_vertices;
	for (size_t i = 0; i < num_of_vertices; ++i) {
		next_vertices.clear();
		prev_vertices.clear();
		x_graph->get_next_vertices(i,next_vertices);
		x_graph->get_prev_vertices(i,prev_vertices);
		for(int vertex : next_vertices){
			vertices_sets[i].insert(vertex);
		}
		for(int vertex : prev_vertices){
			vertices_sets_reverse[i].insert(vertex);
		}
	}
}

size_t CSetGraph::vertices_count() const {
	return num_of_vertices;
}

void CSetGraph::add_vertexes(int necessary_num) {
	while (num_of_vertices < necessary_num + 1) {
		s_int new_vertex;
		++num_of_vertices;
		vertices_sets.push_back(new_vertex);
		vertices_sets_reverse.push_back(new_vertex);
	}
}
void CSetGraph::add_edge(int from, int to) {
	int necessary_num = std::max(from, to);
	if (num_of_vertices < necessary_num + 1) {
		add_vertexes(necessary_num);
	}
	vertices_sets[from].insert(to);
	vertices_sets_reverse[to].insert(from);
}

void CSetGraph::get_next_vertices(int vertex, v_int &vertices) const {
	for(int i : vertices_sets[vertex]){
		vertices.push_back(i);
	}
}

void CSetGraph::get_prev_vertices(int vertex, v_int &vertices) const {
	for(int i : vertices_sets_reverse[vertex]){
		vertices.push_back(i);
	}
}