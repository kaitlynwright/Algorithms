#include "Graph.cpp"

using namespace std;

int isEdge(Graph *graph, int i ,int j) {
	//determines if there is an edge between two nodes in graph
	Node *node = graph->adjList[i].head;
	while(node) {
		if (node->data == j) { return 1; }
		node = node->next;
	}
	return 0;
}

void Paths(Graph *graph) {
	int i, j;
	int v = graph->V;
	int *numPath = new int[v];
	int *shortPath = new int[v];
	int *longPath = new int[v];

	numPath[1] = 1;										//initializes path to source node as 1
	shortPath[1] = 0;
	longPath[1] = 0;
	for (i = 2; i <= v; ++i) {
		numPath[i] = 0;									//initializes paths values to 0
		shortPath[i] = std::numeric_limits<int>::max();	//initializes shortest path values to max
		longPath[i] = 0;								//initializes longest path values to 0
	}

	for(i = 1; i <= v - 1; ++i) {						//traverses each node in topological order, besides last 
		for (j = i + 1; j <= v; ++j) {					//traverses adjacent nodes
			if (isEdge(graph, i, j)) {					//continues if there is an edge between node and adjacent node
				//distinct paths
				numPath[j] = numPath[i] + numPath[j];
			
				//shortest path
				shortPath[j] = min(shortPath[j], shortPath[i] + 1);
			
				//longest path
				longPath[j] = max(longPath[j], longPath[i] + 1); 
			}
		}
	}

	cout << "Shortest path: " << shortPath[v] << "\n";
	cout << "Longest path: " << longPath[v] << "\n";
	cout << "Number of paths: " << numPath[v] << "\n\n";
	return;
}

int main() {
	int i, j, c, n, m, x ,y;

	cin >> c;							//number of graphs

	for (i=1; i <= c; i++) {
		 cin >> n;						//number of nodes
		 cin >> m;						//number of edges
		 Graph *graph = new Graph(n, m);

		 for (j=1; j <= m; j++) {
		 	cin >> x >> y;				//read edges
		 	graph->addEdge(x, y);
		 }

		cout << "Graph number: " << i << "\n";
		Paths(graph);
	}
	return 0;
}