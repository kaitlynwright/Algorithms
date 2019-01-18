struct Node {
		int data;
		struct Node* next;
};

struct AdjList {
		struct Node* head;
};

class Graph {
public:
	int V;
	int E;
	struct AdjList *adjList;

	Graph(int, int);

	Node* addNode(int);
	void addEdge(int, int);
	void printGraph();
};