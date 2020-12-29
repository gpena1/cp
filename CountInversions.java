import java.util.Arrays;

public class CountInversions {
    private static int inversions=0;
    public static void main(String[] args) {
        int[] bruh = new int[]{32,174,38,110,52,173,172,41,28,95,158,151,129,45,3,54,59,61,195,186,99,83,9,157,189,193,71,103,155,197,167,17,192,101,21,149,13,86,170,12,96,147,146,2,88,93,107,137,11,47,108,142,72,124,37,42,190,168,143,33,161,150,89,55,132,74,187,201,175,194,104,18,102,49,191,24,77,171,164,6,139,165,79,115,8,76,127,98,40,20,39,123,128,188,63,57,91,90,156,87,16,118,120,60,51,136,58,5,169,105,43,29,7,75,141,162,34,35,31,166,159,50,182,67,48,23,46,1,180,111,94,14,145,44,154,181,26,4,122,184,69,30,68,126,125,80,183,134,133,82,119,56,25,84,85,19,179,116,73,196,66,144,65,113,200,109,121,27,92,160,53,100,97,78,185,114,199,130,131,135,163,106,176,81,22,70,198,117,140,178,138,148,64,152,10,15,177,153,36,62,112};
        mergeSort(bruh);
        System.out.println(Arrays.toString(bruh));
        System.out.println("Number of inversions: " + inversions);
    }
    private static void mergeSort(int[] arr){
        if (arr.length == 1) return;
        int[] left = Arrays.copyOfRange(arr, 0, arr.length/2);
        int[] right = Arrays.copyOfRange(arr, arr.length/2, arr.length);
        mergeSort(left);
        mergeSort(right);
        merge(arr, left, right);
    }
    private static void merge(int[] whole, int[] left, int[] right){
        int i = 0, j = 0, k = 0;
        int mid = left.length;
        while(i < left.length && j < right.length){
            if (left[i] > right[j]){
                inversions += (mid-i);
                whole[k++] = right[j++];
            }else{
                whole[k++] = left[i++];
            }
        }
        while(i < left.length){
            whole[k++] = left[i++];
        }
        while(j < right.length){
            whole[k++] = right[j++];
        }
    }
}
