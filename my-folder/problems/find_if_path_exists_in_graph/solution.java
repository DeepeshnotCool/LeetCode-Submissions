class Solution {
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        //make adjacency list
        List<List<Integer>> adj = new ArrayList<>();
        for(int i=0; i<n; i++){
            adj.add(new ArrayList<>());
        }
        for(int i=0; i<edges.length; i++)
        {
            adj.get(edges[i][0]).add(edges[i][1]);
            adj.get(edges[i][1]).add(edges[i][0]);
        }
        int vis[] = new int[n];
        Queue<Integer> q = new LinkedList<>();
        q.offer(source);
        vis[source] =1;

        while(!q.isEmpty())
        {
           int node = q.poll();

           if(node==destination)
             return true;
           for(int it: adj.get(node))
           {
               if(vis[it] ==0)
                {
                    vis[it] =1;
                    q.offer(it);
                }
           }
        }
      return false;
    }
}