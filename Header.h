#include <time.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#define GEN_SIZE 89
typedef struct {
	char* name;
	float components[3];
}Vector;
float vector_length(float vec[]);
void VectorMain();
void vector_unit(float Vec[], Vector* vector, int* VecCount);
void vector_projection(float Vec1[], float onto_Vec2[]);
void vector_cross_product(float vec1[], float vec2[], float result[]);
float angle_between_vectors(float vec1[], float vec2[]);


