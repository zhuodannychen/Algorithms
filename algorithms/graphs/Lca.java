import java.nio.Buffer;
import java.util.*;
import java.io.*;

public class Lca {
    /*
    euler_tour: stores the order the nodes are visited
    adj: adjacency list
    first: marks the first occurrence of every node in the euler tour such that euler[first[i]] = i
    depth: the depth of each node from the root
    segtree: segment tree, stores the lowest level node-id at given intervals.
    
    The running code assumes the input nodes as Strings, so I converted them to integers.
     */
    public static HashMap<String, Integer> index;
    public static ArrayList<Integer> euler_tour;
    public static ArrayList<Integer>[] adj;
    public static int[] first, depth, segtree;
    public static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new FileReader("breedflip.in"));
        // BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(bf.readLine());
        int nodes = Integer.parseInt(st.nextToken());
        int queries = Integer.parseInt(st.nextToken());

        index = new HashMap<>();
        euler_tour = new ArrayList<>();
        first = new int[nodes];
        depth = new int[nodes];
        visited = new boolean[nodes];
        adj = new ArrayList[nodes];
        for (int i = 0; i < nodes; i++) {
            adj[i] = new ArrayList<>();
        }

        String[][] edgeList = new String[nodes - 1][2];
        Set<String> cities = new HashSet<>();

        for (int i = 0; i < nodes - 1; i++) {
            st = new StringTokenizer(bf.readLine());
            String city1 = st.nextToken();
            String city2 = st.nextToken();
            st.nextToken(); // route
            cities.add(city1);
            cities.add(city2);
            edgeList[i][0] = city1;
            edgeList[i][1] = city2;
        }
        int idx = 0;
        for (String city : cities)
            index.put(city, idx++);
        for (int i = 0; i < nodes - 1; i++) {
            int a = index.get(edgeList[i][0]);
            int b = index.get(edgeList[i][1]);
            adj[a].add(b);
            adj[b].add(a);
        }

        dfs(0, 0);
        segtree = new int[euler_tour.size() << 2];
        build(1, 0, euler_tour.size() - 1);
        // out.println(index);
        // out.println(euler_tour);
        // out.println(Arrays.toString(segtree));
        // out.println(Arrays.toString(first));
        // out.println(Arrays.toString(depth));

        while (queries-- > 0) {
            String[] inp = bf.readLine().split(" ");
            int u = index.get(inp[0]); int v = index.get(inp[1]);
            // System.out.println(lca(u, v) + " " + depth[lca(u, v)]);
            int dist = depth[lca(u, v)];
            int total_dist = depth[u] - dist + depth[v] - dist;
            out.println(total_dist);
        }
        out.flush();
    }

    public static void dfs(int current, int height) {
        visited[current] = true;
        first[current] = euler_tour.size();
        depth[current] = height;
        euler_tour.add(current);
        for (int node : adj[current]) {
            if (!visited[node]) {
                dfs(node, height + 1);
                euler_tour.add(current);
            }
        }
    }

    public static void build(int node, int begin, int end) {
        if (begin == end) {
            segtree[node] = euler_tour.get(begin);
        } else {
            int mid = (begin + end) / 2;
            build(node << 1, begin, mid);
            build(node << 1 | 1, mid + 1, end);
            int l = segtree[node << 1]; int r = segtree[node << 1 | 1];
            segtree[node] = depth[l] < depth[r] ? l : r;
        }
    }

    public static int query(int node, int begin, int end, int L, int R) {
        if (begin > R || end < L)
            return -1;
        if (begin >= L && end <= R)
            return segtree[node];

        int mid = (begin + end) / 2;
        int left = query(node << 1, begin, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, end, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return depth[left] < depth[right] ? left : right;
    }

    public static int lca(int u, int v) {
        if (first[u] > first[v]) {
            int temp = u;
            u = v;
            v = temp;
        }
        return query(1, 0, euler_tour.size() - 1, first[u], first[v]);
    }
}
