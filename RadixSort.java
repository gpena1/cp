import java.util.Arrays;
public class RadixSort {
    public static void main(String args[]) {
        int[] arr = new int[100000];
        for (int i = 0; i < arr.length; i++){
            arr[i] = 100000-i;
        }
        arr = radix_sort(arr);
	System.out.println(Arrays.toString(arr));
    }
    private static int[] counting_sort(int[] arr2, int exp){
        int[] arr = new int[arr2.length];
        for (int i = 0; i < arr.length; i++){
            arr[i] = (arr2[i]/exp)%10;
        }
        int[] index = new int[10];
        for (int i : arr){
            index[i]++;
        }
        for (int i = 0; i < index.length-1; i++){
            index[i+1] = index[i] + index[i+1];
        }
        int[] places = new int[arr.length];
        for (int i = arr2.length-1; i >= 0; i--){
            places[index[arr[i]] - 1] = arr2[i];
            index[arr[i]]--;
        }
        return places;
    }
    private static int[] radix_sort(int[] arr){
        int max = -2147483648;
        for (int i : arr){
            if (i > max){
                max = i;
            }
        }
        for (int exp = 1; max/exp > 0; exp *= 10){
            arr = counting_sort(arr, exp);
        }
        return arr;
    }
}