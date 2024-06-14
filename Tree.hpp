#ifndef _TREE_HPP_
#define _TREE_HPP_

#include <random>
#include <vector>
#include <utility>
using std :: vector;
using std :: uniform_int_distribution;
using std :: default_random_engine;
using std :: pair;
class treeBase {
private:
	vector<vector<int> > E;
	vector<pair<int, int> > edges;
protected:
	int sz;
public:
	treeBase(int sz_) {
		E = vector<vector<int> >(sz_, vector<int>(0));
		sz = sz_;
	}
	void addEdge(int u, int v) {
		E[u].push_back(v);
		E[v].push_back(u);
		edges.push_back({u, v});
	}
	vector<pair<int, int> > getEdges() {
		return edges;
	}
	vector<vector<int> > getEdge() {
		return E;
	}
	virtual void construct() = 0;
};

class chain : public treeBase {
public:
	chain(int sz_):treeBase(sz_) {}
	void construct() {
		for (int i = 0; i < sz - 1; i++) {
			addEdge(i, i + 1);
		}
	}
};

class flower : public treeBase {
public:
	flower(int sz_):treeBase(sz_) {}
	void construct() {
		for (int i = 1; i < sz; i++) {
			addEdge(0, i);
		}
	}
};

template <typename tree1, int size1, typename tree2>
class mix : public treeBase {
public:
	mix(int sz_):treeBase(sz_) {}
	void construct() {
		int sz1 = size1;
		tree1 tr1(sz1);
		tr1.construct();
		for (auto i:tr1.getEdges()) {
			addEdge(i.first, i.second);
		}
		int sz2 = sz - sz1 + 1;
		tree2 tr2(sz2);
		tr2.construct();
		vector<vector<int> > e = tr2.getEdge();
		for (auto i:e[0]) {
			addEdge(0, i + sz1 - 1);
		}
		for (int i = 1; i < sz2; i++) {
			for (auto j:e[i]) {
				if (i >= j) continue;
				addEdge(i + sz1 - 1, j + sz1 - 1);
			}
		}
	}
};

class randomTree : public treeBase {
public:
	randomTree(int sz_):treeBase(sz_) {}
	void construct() {
		default_random_engine e;
		for (int i = 1; i < sz; i++) {
			uniform_int_distribution<int> d(0, i - 1);
			int fa = d(e);
			addEdge(fa, i);
		}
	}
};

#endif