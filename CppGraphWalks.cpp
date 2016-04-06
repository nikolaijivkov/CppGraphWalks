// CppGraphWalks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
using uint = unsigned int;

template<int n>
void BFS(uint v, uint A[][n]) {
	bool used[n]{};
	queue<uint> que;
	uint top;

	que.push(v); used[v] = true;
	while (!que.empty()) {
		top = que.front(); que.pop();
		printf("%c ", Vertices[top]);
		for (int i = 0; i < n; ++i)
			if (A[top][i] && !used[i]) {
				que.push(i); used[i] = true;
			}
	}

}


template<int n>
void DFS(uint v, uint A[][n]) {
	bool used[n]{}, hit;
	stack<uint> stk;
	uint top;

	stk.push(v); used[v] = true;
	printf("%c ", Vertices[v]);


	while (!stk.empty()) {
		top = stk.top();
		hit = false;
		for (int i = 0; i < n; ++i) {
			if (A[top][i] && !used[i]) {
				stk.push(i); used[i] = true; hit = true;
				printf("%c ", Vertices[i]);
				break;
			}
		}
		if (!hit) stk.pop();
	}
}

template<int n>
void rDFS(uint v, uint A[][n]) {
	static bool used[n]{};

	printf("%c ", Vertices[v]); used[v] = true;
	for (int i = 0; i < n; ++i)
		if (A[v][i] && !used[i])
			rDFS(i, A);
}


const uint N = 8;
char Vertices[N]{ 'A','B','C','D','E','F','G','H' };
int main() {


	uint AjacencyMatrix[N][N] = {
		{ 0,1,0,1,0,0,1,0 },
		{ 1,0,0,0,1,1,0,0 },
		{ 0,0,0,0,0,1,0,1 },
		{ 1,0,0,0,0,0,0,0 },
		{ 0,1,0,0,0,0,1,0 },
		{ 0,1,1,0,0,0,0,0 },
		{ 1,0,0,0,1,0,0,0 },
		{ 0,0,1,0,0,0,0,0 },
	};


	uint v = 0;


	printf("Graph Walk - BFS, starting from vertex %c: \n", Vertices[v]);
	BFS(v, AjacencyMatrix);

	printf("\nGraph Walk - DFS, starting from vertex %c: \n", Vertices[v]);
	DFS(v, AjacencyMatrix);

	printf("\nGraph Walk - rDFS, starting from vertex %c: \n", Vertices[v]);
	rDFS(v, AjacencyMatrix);


	getchar();
	return 0;
}