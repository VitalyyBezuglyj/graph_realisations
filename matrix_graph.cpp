#include "matrix_graph.h"

CMatrixGraph::CMatrixGraph(size_t num) {
	num_of_vertices = num;
	vertices_matrix.resize(num_of_vertices);
	for (size_t i = 0; i < num_of_vertices; ++i) {
		vertices_matrix[i].resize(num_of_vertices, 0);
	}
}

CMatrixGraph::CMatrixGraph(const I_Graph *x_graph) {
	num_of_vertices = x_graph->vertices_count();
	vertices_matrix.resize(num_of_vertices);
	for (size_t i = 0; i < num_of_vertices; ++i) {
		v_int next_vertices;
		vertices_matrix[i].resize(num_of_vertices, 0);
		x_graph->get_next_vertices(i, next_vertices);
		for (int vertex : next_vertices) {
			vertices_matrix[i][vertex] = 1;
		}
	}
}

size_t CMatrixGraph::vertices_count() const {
	return num_of_vertices;
}

void CMatrixGraph::add_vertexes(int necessary_num) {
	while (num_of_vertices < necessary_num + 1) {
		v_int new_vertex;
		new_vertex.resize(num_of_vertices, 0);
		++num_of_vertices;
		vertices_matrix.push_back(new_vertex);
		for (size_t i = 0; i < num_of_vertices; ++i){
			vertices_matrix[i].push_back(0);
		}
	}
}

void CMatrixGraph::add_edge(int from, int to) {
	int necessary_num = std::max(from, to);
	if (num_of_vertices < necessary_num + 1) {
		add_vertexes(necessary_num);
	}
	vertices_matrix[from][to] = 1;
}

void CMatrixGraph::get_next_vertices(int vertex, v_int &vertices) const {
	for(size_t i = 0; i < num_of_vertices; ++i){
		int vertex_loc = vertices_matrix[vertex][i];
		if(vertex_loc > 0){
			vertices.push_back(i);
		}
	}
}

void CMatrixGraph::get_prev_vertices(int vertex, v_int &vertices) const {
	for(size_t i = 0; i < num_of_vertices; ++i){
		int vertex_loc = vertices_matrix[i][vertex];
		if(vertex_loc > 0){
			vertices.push_back(i);
		}
	}
}