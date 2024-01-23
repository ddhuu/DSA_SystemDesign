# Graph Algorithm && Application
## 01. Connected Graph
You are givem a directed graph as input. The task is check if the graph is connected or not.
## 02. Detect cycle in the undirected graph
Given a undirected graph, write an algorithm to find out whether graph contains cycle or not in Time Complexity O(Vertex + Edge) and Space Complexity O(Vertex).
## 03. Find Path 
Given a 2d matrix, find a path from the top left corner to bottom right corner. Assume there exists at least one path, and you only need to find one valid path. You can move up, right, down, left at any position with extra Space Complexity O(m + n).
## 04. Topological Sorting
The topological sort algorithm takes a directed graph and returns an array of the nodes where each node appears before all the nodes it points to.
## 05. Number of island
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands in Time Complexity O(Vertices + Edges).
## 06. Dijkstra algorithm
Design and implement Dijkstra's algorithm which allows us to find the shortest path between any two vertices of a graph in Time Complexity O(E+V*log(V))
## 07. Verifying an Alien Dictionary using Topological Algorithm
You receive a list of non-empty words from the dictionary, where words are sort
ed lexicographically by the rules of this new language used by aliens. Write Algorithm to Derive the order of letters in this in Time Complexity O(edges +vertices).
```java
import java.util.*;

class Solution {
    public String alienOrder(String[] words) {
        Map<Character, Set<Character>> graph = new HashMap<>();
        int[] inDegree = new int[26];
        buildGraph(words, graph, inDegree);

        StringBuilder sb = new StringBuilder();
        Queue<Character> q = new LinkedList<>();
        for (char c : graph.keySet()) {
            if (inDegree[c - 'a'] == 0) {
                q.add(c);
                sb.append(c);
            }
        }

        while (!q.isEmpty()) {
            char c = q.poll();
            for (char next : graph.get(c)) {
                inDegree[next - 'a']--;
                if (inDegree[next - 'a'] == 0) {
                    q.add(next);
                    sb.append(next);
                }
            }
        }

        return sb.length() == graph.size() ? sb.toString() : "";
    }

    private void buildGraph(String[] words, Map<Character, Set<Character>> graph, int[] inDegree) {
        for (String word : words) {
            for (char c : word.toCharArray()) {
                graph.putIfAbsent(c, new HashSet<>());
            }
        }

        for (int i = 1; i < words.length; i++) {
            String first = words[i - 1];
            String second = words[i];
            int len = Math.min(first.length(), second.length());
            for (int j = 0; j < len; j++) {
                char out = first.charAt(j);
                char in = second.charAt(j);
                if (out != in) {
                    if (!graph.get(out).contains(in)) {
                        graph.get(out).add(in);
                        inDegree[in - 'a']++;
                    }
                    break;
                }
            }
        }
    }
}
```
## 08. All Paths
 Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.
## 09. Breadth first search algorithm to solve Rotten Orange Problem
A matrix of mxn where each cell in the matrix have Fresh,Rotten and Empty Cell. Write algorithm to find minimum time required so that all the oranges become rotten in Time Complexity O(mxn) and Space Complexity O(mxn).