//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();
            int x = V;
            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++) adj.add(i, new ArrayList<Integer>());

            int[][] edges = new int[E][2];
            for (int i = 0; i < E; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
                adj.get(edges[i][0]).add(edges[i][1]);
            }

            ArrayList<Integer> res = new Solution().topoSort(V, edges);

            if (check(adj, x, res) == true)
                System.out.println("true");
            else
                System.out.println("false");
            System.out.println("~");
        }
    }

    static boolean check(ArrayList<ArrayList<Integer>> adj, int V,
                         ArrayList<Integer> res) {

        if (V != res.size()) return false;

        int[] map = new int[V];
        for (int i = 0; i < V; i++) {
            map[res.get(i)] = i;
        }
        for (int i = 0; i < V; i++) {
            for (int v : adj.get(i)) {
                if (map[i] > map[v]) return false;
            }
        }
        return true;
    }
}

// } Driver Code Ends


class Solution {
    static ArrayList<ArrayList<Integer>> adjList;
    static ArrayList<Integer> ans;
    static boolean[] visited;
    static void dfs(int v) {
        visited[v] = true;
        for(int u: adjList.get(v)) {
            if(!visited[u]) {
                dfs(u);
            }
        }
        ans.add(v);
    }
    public static ArrayList<Integer> topoSort(int V, int[][] edges) {
        // code here
        adjList = new ArrayList<>();
        ans = new ArrayList<>();
        for(int i = 0; i < V; i++) adjList.add(new ArrayList<>());
        for(int i = 0; i < edges.length; i++) {
            int src = edges[i][0];
            int dest = edges[i][1];
            adjList.get(src).add(dest);
        }
        visited = new boolean[V];
        Arrays.fill(visited, false);
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i);
            }
        }
        
        Collections.reverse(ans);
        return ans;
    }
}