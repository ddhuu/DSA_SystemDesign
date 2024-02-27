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
 ```java
 class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        path.add(0);
        dfs(graph, 0, path, result);
        return result;
    }

    private void dfs(int[][] graph, int node, List<Integer> path, List<List<Integer>> result) {
        if (node == graph.length - 1) {
            result.add(new ArrayList<>(path));
            return;
        }

        for (int nextNode : graph[node]) {
            path.add(nextNode);
            dfs(graph, nextNode, path, result);
            path.remove(path.size() - 1);
        }
    }
}

 ```
## 09. Breadth first search algorithm to solve Rotten Orange Problem
A matrix of mxn where each cell in the matrix have Fresh,Rotten and Empty Cell. Write algorithm to find minimum time required so that all the oranges become rotten in Time Complexity O(mxn) and Space Complexity O(mxn).
```java

class Solution {
    public int orangesRotting(int[][] grid) {
        class Cell {
            int x, y, time;
            Cell(int x, int y, int time) {
                this.x = x;
                this.y = y;
                this.time = time;
            }
        }

        Queue<Cell> queue = new LinkedList<>();
        int freshOranges = 0;

        // Add the position of all rotten oranges to queue
        // count the number of fresh oranges
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 2) {
                    queue.add(new Cell(i, j, 0));
                } else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        // if no fresh oranges, return 0
        if (freshOranges == 0) {
            return 0;
        }

        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int timeElapsed = 0;

        // process the rotten oranges
        while (!queue.isEmpty()) {
            Cell current = queue.poll();
            timeElapsed = current.time;
            for (int[] direction : directions) {
                int nextX = current.x + direction[0];
                int nextY = current.y + direction[1];
                if (nextX >= 0 && nextX < grid.length && nextY >= 0 && nextY < grid[0].length && grid[nextX][nextY] == 1) {
                    grid[nextX][nextY] = 2;
                    queue.add(new Cell(nextX, nextY, current.time + 1));
                    freshOranges--;
                }
            }
        }

        // if any fresh oranges left, return -1
        if (freshOranges > 0) {
            return -1;
        }

        return timeElapsed;
    }
}
```
## 10. Understanding Queue based approach to Jumping Number problem
A number is called as a Jumping Number if all adjacent digits in it differ by 1. The difference between ‘9’ and ‘0’ is not considered as 1. Given a positive number x, print all Jumping Numbers smaller than or equal to x in Time Complexity O(Jumping_Numer) Asked in : Morgan Stanley, OLA, NetApp
```java
import java.util.*;

class Main {
    public static void printJumpingNumbers(int x) {
        // All single digit numbers are jumping numbers
        for (int i = 0; i <= 9 && i <= x; i++) {
            bfs(x, i);
        }
    }

    public static void bfs(int x, int num) {
        // Create a queue and enqueue 'num'
        Queue<Integer> q = new LinkedList<>();
        q.add(num);

        while (!q.isEmpty()) {
            num = q.peek();
            q.poll();

            if (num <= x) {
                System.out.print(num + " ");
                int last_digit = num % 10;

                // If last digit is 0, append next digit only
                if (last_digit == 0) {
                    q.add((num * 10) + (last_digit + 1));
                }

                // If last digit is 9, append previous digit only
                else if (last_digit == 9) {
                    q.add((num * 10) + (last_digit - 1));
                }

                // If last digit is neighter 0 nor 9, append both previous and next digits
                else {
                    q.add((num * 10) + (last_digit - 1));
                    q.add((num * 10) + (last_digit + 1));
                }
            }
        }
    }

    public static void main(String args[]) {
        int x = 50;
        printJumpingNumbers(x);
    }
}
```

