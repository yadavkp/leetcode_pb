class Solution {
    int n;
    vector<int> par, size;

    int find_par(int u) {
        if (par[u] == u) return u;
        return par[u] = find_par(par[u]);
    }

    void union_y_size(int u, int v) {
        int pu = find_par(u);
        int pv = find_par(v);

        if (pu != pv) {
            if (size[pu] < size[pv]) swap(pu, pv);
            par[pv] = pu;
            size[pu] += size[pv];
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // If not enough cables, impossible
        if (connections.size() < n - 1) return -1;

        this->n = n;
        par.assign(n, 0);
        size.assign(n, 1);

        for (int i = 0; i < n; i++) par[i] = i;

        // Union all connections
        for (auto &vec : connections) {
            int u = vec[0], v = vec[1];
            union_y_size(u, v);
        }

        // Count components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find_par(i) == i) components++;
        }

        // Minimum operations = components - 1
        return components - 1;
    }
};
