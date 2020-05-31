import java.util.Arrays;
import java.util.Random;

public class MergeSort {
    public static void main(String args[]) {
        int[] arr = new int[100000];
        for (int i = 0; i < arr.length; i++){
            arr[i] = i + 1;
        }
        randomize(arr);
        merge_sort(arr);
        System.out.println(Arrays.toString(arr));
    }
    private static void merge_sort(int[] arr){
        if (arr.length == 1) return;
        int[] lh = new int[arr.length/2];
        int[] rh = new int[arr.length - lh.length];
        for (int i = 0; i < arr.length/2; i++){
            lh[i] = arr[i];
        }
        for (int i = arr.length/2; i < arr.length; i++){
            rh[i-arr.length/2] = arr[i];
        }
        merge_sort(lh);
        merge_sort(rh);
        merge(arr, rh, lh);
    }
    private static void merge(int[] whole, int[] rh, int[] lh){
        int i = 0, j = 0, k = 0;
        while(i < lh.length && j < rh.length){
            if (lh[i] < rh[j]){
                whole[k] = lh[i++];
            }else whole[k] = rh[j++];
            k++;
        }
        while (i < lh.length){
            whole[k++] = lh[i++];
        }
        while (j < rh.length){
            whole[k++] = rh[j++];
        }
    }
    private static void randomize(int[] arr){
        Random r = new Random();
        for (int i = 0; i < arr.length; i++){
            int j = r.nextInt(arr.length);
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
}