import java.util.LinkedList;
import java.util.Queue;

public class BFS {
    static class Graph {
        private int V; // Number of vertices
        private LinkedList<Integer>[] adj; // Adjacency list

        Graph(int v) {
            V = v;
            adj = new LinkedList[v];
            for (int i = 0; i < v; ++i) {
                adj[i] = new LinkedList<>();
            }
        }

        void addEdge(int v, int w) {
            adj[v].add(w);
        }

        void breadthFirstSearch(int start) {
            boolean[] visited = new boolean[V];
            Queue<Integer> queue = new LinkedList<>();

            visited[start] = true;
            queue.add(start);

            while (!queue.isEmpty()) {
                start = queue.poll();
                System.out.print(start + " ");

                for (Integer neighbor : adj[start]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        queue.add(neighbor);
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        int vertices = 7; // Change this to the number of vertices in your graph
        Graph graph = new Graph(vertices);

        // Add edges to the graph
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 3);
        graph.addEdge(1, 4);
        graph.addEdge(2, 5);
        graph.addEdge(2, 6);

        System.out.println("Breadth-First Traversal (starting from vertex 0):");
        graph.breadthFirstSearch(0);
    }
}

