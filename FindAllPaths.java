import java.util.*;

class FindAllPaths{
    private static ArrayList<String> paths(int start, int end, boolean[] visited, String path){
        if (start == end){
            ArrayList<String> paths = new ArrayList<>();
            paths.add(path);
            return paths;
        }
        ArrayList<String> paths = new ArrayList<>();
        visited[start] = true;
        for (int i : map.get(start)){
            if (!visited[i]){
                paths.addAll(paths(i, end, visited, path + i + " "));
            }
        }
        visited[start] = false;
        return paths;
    }
    private static HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
    public static void main(String[] args) {
        for (int i = 0; i < 4; i++){
            map.put(i, new ArrayList<>());
        }
        map.get(0).add(2);
        map.get(0).add(3);
        map.get(0).add(1);
        map.get(1).add(3);
        map.get(2).add(1);
        map.get(2).add(0);
        System.out.println(paths(2, 1, new boolean[4], "2 "));
    }
}