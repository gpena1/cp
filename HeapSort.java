package com;
import java.util.Random;
public class HeapSort {
    public static void main(String args[]) {
        int[] arr = new int[100001];
        int[] arr2 = new int[100000];
        arr[0] = -1;
        for (int i = 0; i < arr2.length; i++){
            arr2[i] = i+1;
        }
        randomize(arr2, arr2.length);
        System.arraycopy(arr2, 0, arr, 1, arr.length - 1);
        int[] output = heap_sort(arr);
        for (int i : output){
            System.out.print(i + " ");
        }
    }
    private static void build_heap(int[] str){
        for (int i = 1; i < str.length; i++){
            insert(str, i);
        }
    }
    private static int[] heap_sort(int[] str){
        int[] chars = new int[str.length-1];
        build_heap(str);
        int size = chars.length;
        while(size > 0){
            chars[size-1] = str[1];
            str[1] = str[size];
            str[size] = 0;
            adjustHeap(str, size--, 1);
        }
        return chars;
    }
    private static void insert(int[] array, int idx){
        if (array[idx/2] < array[idx] && idx != 1){
            int temp = array[idx];
            array[idx] = array[idx/2];
            array[idx/2] = temp;
            insert(array, idx/2);
        }
    }
    private static void adjustHeap(int[] heap, int heapSize, int idx){
        // tests if the node is a leaf node
        if ((idx * 2 > heapSize && idx * 2 + 1 > heapSize) || (heap[idx * 2] == 0 && heap[idx * 2 + 1] == 0)) return;
        // following if chain tests whether just 1 child is null AND the other nonnull child is greater than the parent
        if (heap[idx*2] == 0 && heap[idx*2] != 0 && heap[idx] < heap[idx*2+1]){
            int temp = heap[idx];
            heap[idx] = heap[idx*2+1];
            heap[idx*2+1]=temp;
            adjustHeap(heap, heapSize - 1, idx * 2 + 1);
        }else if (heap[idx*2+1] != 0 && heap[idx*2] == 0 && heap[idx] < heap[idx*2]){
            int temp = heap[idx];
            heap[idx] = heap[idx*2];
            heap[idx*2] = temp;
            adjustHeap(heap, heapSize - 1, idx * 2);
        }else
        // At this point, we now know the node has 2 children
        if (heap[idx] < heap[idx*2] || heap[idx] < heap[idx*2+1]){
            int maxidx;
            if (heap[idx*2] > heap[idx*2 + 1]) maxidx = idx*2;
            else maxidx = idx*2+1;
            int temp = heap[idx];
            heap[idx] = heap[maxidx];
            heap[maxidx] = temp;
            adjustHeap(heap, heapSize - 1, maxidx);
        }
    }
    // Credit to geeksforgeeks for randomize()
    static void randomize( int arr[], int n)
    {
        // Creating a object for Random class
        Random r = new Random();

        // Start from the last element and swap one by one. We don't
        // need to run for the first element that's why i > 0
        for (int i = n-1; i > 0; i--) {

            // Pick a random index from 0 to i
            int j = r.nextInt(i+1);

            // Swap arr[i] with the element at random index
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        // Prints the random array
    }
}