#include <cstdio>
#include <cstdlib>
#include <ctime>


float** get_random_matrix(const int N);
void print_matrix(float** A, const int N);
float get_determinant(float** A, const int N, const int start);
void clean_matrix(float** A, const int N);



int main(void) {


    /* *********************************************************************
     * Initialize
     * *********************************************************************/

    int N;

    printf("\n\n==================================================================================\n");
    printf("Determinant of A calculator\n");
    printf(" - Size of A : [N,N]\n");
    printf(" - enter N: ");
    scanf("%d", &N);




    /* *********************************************************************
     * Making a random matrix A[N,N]
     * *********************************************************************/
    
    printf("\n\n==================================================================================\n");
    printf("Making a random matrix A[N,N] ...\n");
    float** A = get_random_matrix(N);
    print_matrix(A, N);




    /* *********************************************************************
     * Calculate determinant of A
     * *********************************************************************/
        
    printf("\n\n==================================================================================\n");
    printf("Calculate determinant of A ...\n");
    float determinant = get_determinant(A, N, 0);
    printf(" - Determinant of A: %d\n", (int)determinant);


    /* *********************************************************************
     * Finalized
     * *********************************************************************/
    
    clean_matrix(A, N);


    return 0;

}


float** get_random_matrix(const int N) {

    float** A = new float*[N];
    for (int i=0; i<N; i++) 
        A[i] = new float[N];

    srand(time(NULL));
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            A[i][j] = (rand()%21 - 10);
        }
    }

    return A;
}

void print_matrix(float** A, const int N) {
    printf("\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf(" %3d", (int)A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool check_exist(float** A, const int N, const int start) {

    if (A[start][start] != 0) {
        return true;
    }

    for (int i=start+1; i<N; i++) {
        if (A[i][start] != 0) {
            for (int j=start; j<N; j++) {
                A[start][j] = A[i][j];
                return true;
            }
        }
    }

    return false;

}

void remove_first_column(float** A, const int N, const int start) {

    for (int i=start+1; i<N; i++) {
        float ratio = A[i][start]/A[start][start];
        for (int j=start; j<N; j++) {
            A[i][j] -= (ratio*A[start][j]);
        }
    }

}

float get_determinant(float** A, const int N, const int start) {

    if ((N-start) == 2) {
        return A[start][start]*A[start+1][start+1] - A[start][start+1]*A[start+1][start];
    }

    if (check_exist(A, N, start) == false) {
        return 0;
    }


    remove_first_column(A, N, start);
    return A[start][start]*get_determinant(A, N, start+1);
}

void clean_matrix(float** A, const int N) {
    for (int i=0; i<N; i++) {
        delete [] A[i];
    }
    delete [] A;
}