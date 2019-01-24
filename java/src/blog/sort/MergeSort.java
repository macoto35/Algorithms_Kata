package blog.sort;

public class MergeSort {

    public void topDown (int[] b, int[] a, int st, int ed) {
        if (ed - st < 2)
            return;

        int mid = (st + ed) / 2;

        this.topDown(a, b, st, mid);
        this.topDown(a, b, mid, ed);

        this.topDownMerge(b, a, st, mid, ed);
    }

    private void topDownMerge (int[] a, int[] b, int st, int mid, int ed) {
        int i = st;
        int j = mid;

        for (int k = st; k < ed; k++) {
            if (i < mid && (j >= ed || a[i] <= a[j]))
                b[k] = a[i++];
            else
                b[k] = a[j++];
        }
    }

    public void bottomUp (int[] b, int[] a, int n) {
        // width: 1, 2, 4, 8...
        for (int width = 1; width < n; width *= 2) {
            for (int i = 0; i < n; i = i + 2 * width) {
                this.bottomUpMerge(b, a, i, i + width, i + 2 * width);
            }
            this.copyArray(b, a, n);
        }
    }

    private void bottomUpMerge (int[] b, int[] a, int st, int mid, int ed) {
        int i = st;
        int j = mid;

        for (int k = st; k < ed; k++) {
            if (i < mid && (j >= ed || a[i] <= a[j]))
                b[k] = a[i++];
            else
                b[k] = a[j++];
        }
    }

    private void copyArray(int[] b, int[] a, int n) {
        for (int i = 0; i < n; i++)
            a[i] = b[i];
    }

    public int[] topDownList(int[] a, int st, int ed) {
        if (st == ed) {
            int[] result = { a[st] };
            return result;
        }

        int mid = (st + ed) / 2;

        int[] left = this.topDownList(a, st, mid);
        int[] right = this.topDownList(a, mid + 1, ed);

        return topDownMerge(left, right);
    }

    public int[] topDownMerge(int[] left, int[] right) {
        int n = 2 * left.length;
        int[] result = new int[n];

        int i = 0, j = 0;

        for (int k = 0; k < n; k++) {
            if ( i < left.length && (j >= right.length || left[i] < right[j]) )
                result[k] = left[i++];
            else
                result[k] = right[j++];
        }

        return result;
    }
}
