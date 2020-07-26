
#include "list_graph.h"
//
// Created by smart_000 on 20.02.2018.
//
CListGraph::CListGraph(size_t num){
	num_of_vertices = num;
	vertices_list.resize(num);
	vertices_list_reverse.resize(num);
}

CListGraph::CListGraph(const I_Graph *x_graph) {
	num_of_vertices = x_graph->vertices_count();
	vertices_list.resize(num_of_vertices);
	for (size_t i = 0; i < num_of_vertices; ++i) {
		x_graph->get_next_vertices(i, vertices_list[i]);
	}
	for (size_t i = 0; i < num_of_vertices; ++i) {
		x_graph->get_prev_vertices(i, vertices_list_reverse[i]);
	}
}

void CListGraph::add_vertexes(int necessary_num) {
	while (num_of_vertices < necessary_num + 1) {
		v_int new_vertex;
		++num_of_vertices;
		vertices_list.push_back(new_vertex);
		vertices_list_reverse.push_back(new_vertex);
	}
}

void CListGraph::add_edge(int from , int to) {
	int necessary_num = std::max(from, to);
	if (num_of_vertices < necessary_num + 1) {
		add_vertexes(necessary_num);
	}
	vertices_list[from].push_back(to);
	vertices_list_reverse[to].push_back(from);
}

size_t CListGraph::vertices_count() const {
	return num_of_vertices;
}

void CListGraph::get_next_vertices(int vertex, v_int &vertices) const {
	for (int vertex_it : vertices_list[vertex]) {
		vertices.push_back(vertex_it);
	}
}

void CListGraph::get_prev_vertices(int vertex, v_int &vertices) const {
	for (int vertex_it : vertices_list_reverse[vertex]) {
		vertices.push_back(vertex_it);
	}
}