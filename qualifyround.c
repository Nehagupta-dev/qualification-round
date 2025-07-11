#include <stdio.h>
#include <stdlib.h>
int prime(int num){
    if (num <= 1)      
       return 0;
    if (num == 2)       
      return 1;
    if (num % 2 == 0) 
      return 0;      
    for (int i = 3;i * i <= num; i += 2)
        if (num % i == 0) return 0;
    return 1;
}
long long zigzag_sum(int **mat, int n) {
    long long sum = 0;
    for (int d = 0; d < 2 * n - 1; ++d) {
        int row_start = d < n ? 0 : d - n + 1;
        int row_end = d < n ? d : n - 1;
        if (d & 1)                      
            for (int i =  row_start; i <= row_end; ++i) {
                int val = *(*(mat + i) + (d - i));
                sum += prime(val) ? -val : val;
            }
        else                           
            for (int i = row_end; i >=  row_start; --i) {
                int val = *(*(mat + i) + (d - i));
                sum += prime(val) ? -val : val;
            }
    }
    return sum;
}
int main() {
    int n; 
    if (scanf("%d", &n) != 1 || n < 2)
      return 0;
    int **m = malloc(n * sizeof *m);
    for (int i = 0; i < n; ++i) {
        m[i] = malloc(n * sizeof **m);
        if (!m[i]) {
            while (i--) free(m[i]);
            free(m);
            return 1;
        }    
        for (int j = 0; j < n; ++j) 
           scanf("%d", &m[i][j]);
    }
    printf("%lld\n", zigzag_sum(m, n));
    for (int i = 0; i < n; ++i){
       free(m[i]); 
    }
    free(m);
}