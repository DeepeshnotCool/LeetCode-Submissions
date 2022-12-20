class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        int [] vis = new int[rooms.size()];
        Queue<Integer> q = new LinkedList<>();

        for(int i=0; i<rooms.get(0).size(); i++){
            q.offer(rooms.get(0).get(i));
            vis[rooms.get(0).get(i)] =1;
        }
        vis[0] =1;
        while(!q.isEmpty())
        {
            int node = q.poll();
            for(int it : rooms.get(node))
            {
                if(vis[it] !=1)
                {
                    vis[it] =1;
                    q.offer(it);
                }
            }
        }
        System.out.println(Arrays.toString(vis));
        for(int i=0; i<vis.length; i++)
        {
            if(vis[i]==0)
              return false;
        }  
       return true; 
    }
}