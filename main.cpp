#include <iostream>
/*#include "list_graph.h"*/
#include "arc_graph.h"

using namespace std;

void show_my_graph(I_Graph &my_graph) {
	int num_of_vertices = my_graph.vertices_count();
	cout << num_of_vertices << endl;
	for (int i = 0; i < num_of_vertices; ++i) {
		cout << "vertex : " << i << endl;
		cout << "next : " << endl;
		v_int vertices;
		my_graph.get_next_vertices(i, vertices);
		for (int v : vertices) {
			cout << v << " ";
		}
		cout << endl;
		vertices.clear();
		cout << "prev : " << endl;
		my_graph.get_prev_vertices(i, vertices);
		for (int v : vertices) {
			cout << v << " ";
		}
		cout << endl;
		cout << endl;
	}
}

int main() {
	size_t size = 0;
	CArcGraph my_graph(size);

	my_graph.add_edge(1, 4);
	my_graph.add_edge(2, 3);
	my_graph.add_edge(1, 2);
	my_graph.add_edge(4, 3);
	my_graph.add_edge(3, 5);
	my_graph.add_edge(6, 5);
	my_graph.add_edge(0, 5);
	I_Graph *my_graph_ptr = &my_graph;
	CArcGraph my_new_graph(my_graph_ptr);
	cout << "my_graph : " << endl;
	show_my_graph(my_graph);
	cout << "my_new_graph : " << endl;
	show_my_graph(my_new_graph);
	return 0;
}