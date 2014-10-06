#include <stdio.h>
#include <stdlib.h>

float *load_matrix(char *filename, int *n, int *m);
void multiplicacion( float *A, float *B , float *C, int N, int m, int n);
void transpose(float * m, int N, int m);


int main(int argc, char **argv){
  float *matrix1;
  float *matrix2; 
  float *matrix3;
  int n_row, n_cols;
  int i, j;
  int n; 
  int f; 
  float *final; 


  matrix1 = load_matrix(argv[1], &n_row, &n_cols);
  matrix2 = load_matrix(argv[1], &n_row, &n_cols);
  matrix3 = load_matrix(argv[1], &n_row, &n_cols);

  n = atoi(argv[2]); 

  
  if(n<0){
    printf("Necesita un numero mayor a cero para calcular el factorial,");
    exit(1);
  }

 

  multiplicacion(matrix1, matrix2, matrix3, n_row, n_cols, n); 

  transpose(matrix1, n_row, n_cols);
 


 
      
      printf(" %f \n" , matrix3[i*n_cols + j]);
    
   
 

 

  return 0;
}

void multiplicacion( float *A, float *B , float *C, int N, int m, int n){

  int i, j, k, p;

  for(i=0; i<N; i++){
    for(j=0; j<m; j++){
      C[i*m + j] = 0.0;
      for (p=0; p<=n;p++){
	for(k=0;k<m;k++){
	  C[i*m + j] = C[i*m + j] + (A[i*m + k] * B[k*m + j]);
	
      }
	B[i*m + j] = C[i*m + j] ;
	
      }
    }
  }   
}


}
float *load_matrix(char *filename, int *n, int *m){
  float *matrix;
  
  FILE *in;
  int n_row, n_cols;
  int i;
  int j;

  if(!(in=fopen(filename, "r"))){
    printf("Problem opening file 1 %s\n", filename);
    exit(1);
  }

  

  fscanf(in, "%d %d\n", &n_row, &n_cols);
  printf("%d %d\n", n_row, n_cols);

  matrix = malloc(n_row * n_cols * sizeof(float));
 

  for(i=0;i<n_row;i++){
    for(j=0;j<n_cols;j++){
      fscanf(in, "%f", &matrix[i*n_cols + j]);
    }
  }    
  *n = n_row;
  *m = n_cols;
  return matrix;
}

void transpose(float *A, int N, int m){
  int i;
  int j;
  int pos_ij;
  int pos_ji;

  float tmp;
  /*Prints to screen*/
  for(i=0;i<N;i++){
    for(j=i;j<m;j++){
      pos_ij = i + (N * j);
      pos_ji = j + (N * i);
      tmp = A[pos_ij];
      A[pos_ij] = A[pos_ji];
      A[pos_ji] = tmp;
    }
  }
}
