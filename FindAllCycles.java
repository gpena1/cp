import java.util.*;

class FindAllCycles{
    private static ArrayList<String> findCycles(int start, int end, boolean[] visited, String path){
        if (visited[start] && start != end) return new ArrayList<>();
        if (visited[start] && start == end){
            ArrayList<String> ar = new ArrayList<>();
            ar.add(path);
            return ar;
        }
        ArrayList<String> ar = new ArrayList<>();
        visited[start] = true;
        for (int i : map.get(start)){
            ar.addAll(findCycles(i, end, visited, path + i + " "));
        }
        visited[start] = false;
        return ar;
    }
    private static ArrayList<String> findCycles(int vertices){
        ArrayList<String> ar = new ArrayList<>();
        for (int i = 0; i < vertices; i++){
            ar.addAll(findCycles(i, i, new boolean[vertices], i + " "));
        }
        return ar;
    }
    private static HashMap<Integer, ArrayList<Integer>> map = new HashMap<>();
    public static void main(String[] args) {
        for (int i = 0; i < 4; i++){
            map.put(i, new ArrayList<>());
        }
        map.get(0).add(1);
        map.get(0).add(2);
        map.get(1).add(2);
        map.get(2).add(3);
        map.get(2).add(0);
        map.get(3).add(3);
        System.out.println(findCycles(4));
    }
}