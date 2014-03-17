/*
 * O Radix sort é um algoritmo de ordenação rápido e estável
 * que pode ser usado para ordenar itens que estão identificados por chaves únicas.
 * Cada chave pode ser uma cadeia de caracteres (ordem lexicografia) ou número.
 */
// Radix Sort
    /*
     * Radix Sort
     */
        void radixSort(int v[],int start, int end, unsigned int mask) {
          if (start>=end+1) return;
          if (!mask) return;

          int left, right,tmp;

          for(left=start, right=end;;) {
                while ( left<=right && !( v[left]  & mask) ) left++ ;
                while ( left<=right &&  ( v[right] & mask) ) right--;

                if (left>=right) {
                  radixSort(v, start, left-1, mask>>1);
                  radixSort(v, left, end, mask>>1);
                  return;
                } else {
                  v[left]^=v[right];;
                  v[right]^=v[left];
                  v[left]^=v[right];
                }
            }
        }