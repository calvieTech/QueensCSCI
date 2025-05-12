public class A4SortCT{
    public static void mergeSort(int[] a, int l, int h) {
        if (l >= h) return;
        int mid = (h + l) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        merge(a, l, mid, h);
    }

    public static void merge(int[] a, int low, int mid, int high) {
        int l = low, m = mid+1, h = high;
        int[] arr = new int[a.length];

        for(int j = 0; j <= high; ++j) {
            arr[j] = a[j];
        }

        for (int i = low; i <= high; ++i) {
            if(i > m) a[i] = arr[m++];
            else if (m > h) a[i] = arr[l++];
            else if (arr[i] < arr[m]) a[i] = arr[l++];
            else a[i] = arr[m++];
        }
    }

    public static void main(String[] args){
        int[] a = {3,2,7,5,1,6,4,8,9};
        System.out.println("mergeSort a: ");
        long time, nextTime;
        time = System.nanoTime();
        mergeSort(a, 0, a.length - 1);
        nextTime = System.nanoTime();
        System.out.println("\tTime used: " + (nextTime - time) + " nseconds");
        for (int i = 0; i < a.length; i++) System.out.print(a[i] + ",");
        System.out.println();
    }

}
