#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

static const int INF = INT_MAX;

struct edge
{
	unsigned left;
	unsigned right;

	int weight;

	edge() {;}
	edge(unsigned _left, unsigned _right, int _weight) : left(_left), right(_right), weight(_weight) {;}
};

std::pair<bool, std::vector<int>> FordBellman(std::vector<edge> Graph, unsigned vert, unsigned N, unsigned M)
{
	std::vector<int> dist(N, INF);
	dist[vert] = 0;

	bool changed = true;
	unsigned i;
	for (i = 0; changed && i < N; i++)
	{
		changed = false;
		for (unsigned j = 0; j < M; j++)
			if (dist[Graph[j].left] < INF)
				if (dist[Graph[j].right] > dist[Graph[j].left] + Graph[j].weight)
				{
					dist[Graph[j].right] = dist[Graph[j].left] + Graph[j].weight;
					changed = true;
				}
	}

	if (i == N)
		return {false, dist};
	else
		return {true, dist};
}