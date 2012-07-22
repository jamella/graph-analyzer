/*
 * Filename	: Graph.h
 * Author	: Kuba Sejdak
 * Created on	: 20-06-2012
 */

#ifndef GRAPH_H_
#define GRAPH_H_

/* standard headers */
#include <iterator>
#include <vector>
using namespace std;

/* libemu headers */
extern "C" {
	#include <emu/emu_graph.h>
	#include <emu/emu_hashtable.h>
	#include <emu/emu_queue.h>
}

/* project headers */
#include <core/Dot.h>
#include <core/InstructionSplitter.h>

typedef vector<emu_vertex *> loop_vec;
typedef vector<loop_vec *> loop_container;

class Graph {
public:
	Graph();
	Graph(struct emu_graph *g, struct emu_hashtable *h);
	virtual ~Graph();

	emu_graph *getEmuGraph();
	emu_hashtable *getEmuHashtable();

	/* iterator */
	class graph_iterator : public std::iterator<forward_iterator_tag, emu_vertex> {
	public:
		graph_iterator();
		graph_iterator(Graph *g, emu_vertex *v);
		graph_iterator(const graph_iterator &it);

		graph_iterator &operator++();
		graph_iterator &operator--();
		bool operator==(const graph_iterator &r);
		bool operator!=(const graph_iterator &r);
		emu_vertex &operator*();
		emu_vertex *operator->();

	private:
		emu_vertex *outVertex;
		Graph *outGraph;
		friend class Graph;
	}; /* iterator */

	graph_iterator begin();
	graph_iterator end();

	loop_container *detectLoop(graph_iterator from_it);

private:
	void clearVertColor(emu_vertex *from);

	struct emu_graph *graph;
	struct emu_hashtable *hashtable;
};

#endif /* GRAPH_H_ */
