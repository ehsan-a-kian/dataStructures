#include<iostream>
#include <list>
using namespace std;

class Graph
{
	int V;    // 
	list<int> *adj;    // 
	void DFSUtil(int v, bool visited[]);  // 
public:
	Graph(int V);   // سازنده
	void addEdge(int v, int w);   // تابعی برای افزودن یال به گراف
	void DFS();    // چاپ گراف پیمایش اول عمق شده ی کامل
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // افزودن راس w به گراف
}

void Graph::DFSUtil(int v, bool visited[])
{
	// علامت گذاری گره فعلی به عنوان بازدید کرده و چاپ آن
	visited[v] = true;
	cout << v << " ";

	// تکرار برای همه رئوس مجاور به این راس
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	if (!visited[*i])
		DFSUtil(*i, visited);
}

// تابع برای انجام پیمایش اول عمق که از آن در DFSUtil() بصورت بازگشتی استفاده میشود
void Graph::DFS()
{
	// علامت گذاری همه به رئوس به عنوان بازدید نکرده
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// فراخوانی تابع کمکی بازگشتی برای چاپ پیمایش DFS
	// شروع از از همه رئوس یکی یکی
	for (int i = 0; i < V; i++)
	if (visited[i] == false)
		DFSUtil(i, visited);
}

int main()
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal (starting from vertex 0) \n";
	g.DFS();

	return 0;
} 
