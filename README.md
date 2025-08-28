#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <windows.h>
#include <math.h>
void VectorMain() {
	char VecChoice[32] = {0};
	Vector vector[32];
	int VecCount = 0;
	char tempNameVec[16];
	printf("How many vectors do you have?: ");
	scanf("%d", &VecCount);
	for (int i = 0; i < VecCount; i++) {
		printf("Enter Vector name: ");
		scanf("%s", vector[i].name);
		printf("Now enter the x component: ");
		scanf("%f", &vector[i].components[0]);
		printf("Now enter the y component: ");
		scanf("%f", &vector[i].components[1]);
		printf("Now enter the z component: ");
		scanf("%f", &vector[i].components[2]);
	}
	while (1) {
		printf("\nVec menu please enter you choice\nBack,Dot, Cross, Angle, Proj, UnitVector\n\n> ");
		scanf("%s", VecChoice);
		int indexLoop1 = 0;
		int indexLoop2 = 0;
		if (strcmp(VecChoice, "Cross") == 0)	{
			float result[3];
			char CrossVec1[16];
			char CrossVec2[16];
			printf("\nEnter the first Vector's name: ");
			scanf("%s", CrossVec1);
			indexLoop1 = find_vector(vector, VecCount, CrossVec1);
			if (indexLoop1== -1) {
				printf("That was invalid");
				break;
			}
			printf("Enter the second Vector's name: ");
			scanf("%s", CrossVec2);
			indexLoop2 = find_vector(vector, VecCount, CrossVec2);
			if (indexLoop2 == -1) {
				printf("That was invalid");
				break;
			}
			vector_cross_product(vector[indexLoop1].components, vector[indexLoop2].components, result);
			printf("*** CROSS PRODUCT RESULT***\n");
			for (int i = 0; i < 3; i++) {
				Sleep(200);
				printf("(%.3f)\n", result[i]);
			}
		}
		else if (strcmp(VecChoice, "UnitVector") == 0) {
			char VecName[16];
			int index = 0;
			printf("Please enter the name of the Vector you wish to finds it's unit vector");
			scanf("%s", VecName);
			index = find_vector(vector,VecCount,VecName);
			if (index == -1) {
				printf("That Vector is invalid");
				break;
			}
			vector_unit(vector[index].components, vector, &VecCount);
		}
		else if (strcmp(VecChoice, "Length") == 0) {
			int index = 0;
			char vecLength[16];
			float sum = 0.0;
			printf("Please enter the vector you wish to to find the length of: ");
			scanf("%s", vecLength);
			index = find_vector(vector,VecCount,vecLength);
			if (index == -1) {
				printf("Invalid name");
				break;
			}
			sum = vector_length(vector[index].components);
			printf("The length of %s is: %f", vecLength, sum);
		}
		else if (strcmp(VecChoice, "Angle") == 0) {
			float angleValue = 0.0;
			char Angle1[16];
			char Angle2[16];
			int index1 = 0;
			int index2 = 0;
			printf("\nEnter the first Vector's name: ");
			scanf("%s", Angle1);
			index1 = find_vector(vector, VecCount, Angle1);
			if (index1 == -1) {
				printf("That was invalid\n");
				break;
			}
			printf("Enter the second Vector's name: ");
			scanf("%s", Angle2);
			index2 = find_vector(vector, VecCount, Angle2);
			if (index2 == -1) {
				printf("That was invalid\n");
				break;
			}
			angleValue = angle_between_vectors(vector[index1].components,vector[index2].components);
			printf("*** Angle Result ***");
			Sleep(500);
			printf("%.3f radians\n", angleValue);
		}
		else if (strcmp(VecChoice, "Dot") == 0) {
			float final = 0;
			char Vec1[16];
			char Vec2[16];
			int index1 = 0;
			int index2 = 0;
			printf("Please enter the first vector: ");
			scanf("%s", Vec1);
			index1 = find_vector(vector, VecCount, Vec1);
			if (index1 == -1) {
				printf("Invalid Vector");
				break;
			}
			printf("Please enter the second vector: ");
			scanf("%s", Vec2);
			index2 = find_vector(vector, VecCount, Vec2);
			if (index2 == -1) {
				printf("Invalid Vector");
				break;
			}
			final = vector_dot_product(vector[index1].components, vector[index2].components);
			printf("Debug: %f\n", final);
			fflush(stdout);
			printf("The dot product of %s and %s is: %.3f\n", Vec1, Vec2, final);
		}
		else if (strcmp(VecChoice, "Back") == 0) {
			break;
		}
		else {
			printf("Invalid Input");
		}
	}
}
void vector_projection(float Vec1[], float onto_Vec2[]) {
	printf("\n*** PROJECTION RESULT ***\n");
	float projVec[3];
	float DotProduct = 0.0;
	float mag = 0.0;
	float scalar = 0.0;
	for (int i = 0; i < 3; i++) { // Calculates Dot product by using the vector array and cycling through. This is a . b
		DotProduct += Vec1[i] * onto_Vec2[i];
	}
	for (int i = 0; i < 3; i++) {   // Calculates the maginiatude by summing it this is the lower half of a .b / |b|^2 
		mag += onto_Vec2[i] * onto_Vec2[i]; // now since it is sqaured the square root is cancelled out so no square root
	}
	scalar = DotProduct / mag;

	printf("The projection is\n");
	for (int i = 0; i < 3; i++) {
		projVec[i] = scalar * onto_Vec2[i];
		printf("(%.3f)\n", projVec[i]);
	}
}
int find_vector(Vector *vector,int vecNumber, char* name) {
	for (int i = 0; i < vecNumber; i++) {
		if (strcmp(vector[i].name, name) == 0) { // positive that vector was found
			return i;
		}
	}
	return -1;
}
float vector_length(float vec[]) {
	float sum = 0.0;
	for (int i = 0; i < 3; i++) {
		sum += vec[i] * vec[i];
	}
	sum = (float)sqrt(sum);
	return sum;
}
void vector_cross_product(float vec1[], float vec2[], float result[]) {
	result[0] = vec1[1] * vec2[2] - vec1[2] * vec2[1]; // x component of cross product
	result[1] = vec1[2] * vec2[0] - vec1[0] * vec2[2]; // y component
	result[2] = vec1[0] * vec2[1] - vec1[1] * vec2[0];  // z component
}
float vector_dot_product(float vec1[], float vec2[]) {
	float sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += vec1[i] * vec2[i];
	}
	return sum;
}
float angle_between_vectors(float vec1[], float vec2[]) {
	float x = 0;
	float theta = 0;
	float dot = 0;
	float lengthA = 0;
	float lengthB = 0;
	float SumA = 0;
	float SumB = 0;
	for (int i = 0; i < 3; i++) {
		dot += vec1[i] * vec2[i];
	}
	for (int i = 0; i < 3; i++) {
		SumA += vec1[i] * vec1[i];
		SumB += vec2[i] * vec2[i];
	}
	lengthA = sqrt(SumA);
	lengthB = sqrt(SumB);
	theta = dot / (lengthA * lengthB);
	x = (float)acos(theta);
	return x;
}
void vector_unit(float Vec[], Vector *vector, int* VecCount) {
	float VecCopy[3];
	float length = 0;
	char choice = ' ';
	char UnitName[16];
	length = vector_length(Vec);
	printf("Please note that the unit vector is found by dividing the orignal vector by its length");
	for (int i = 0; i < 3; i++) {
		VecCopy[i] = Vec[i];
		VecCopy[i] = VecCopy[i] * (1/length);
	}
	printf("The unit vector is\n***Unit Vector ***");
	for (int i = 0; i < 3; i++) {
		Sleep(300);
		printf("(%.3f)\n", VecCopy[i]);
	}
	printf("You wish to use this vector again?[y|n]: ");
	scanf(" %c", &choice);
	if (choice == 'y') {
		printf("Returning unit vector give it a name: ");
		scanf("%s", UnitName);
		strcpy(vector[*VecCount].name,UnitName); // finds the correct index to copy the name and componets to. which is a new array
		for (int i = 0; i < 3; i++) {
			vector[*VecCount].components[i] = VecCopy[i];
		}	
		(*VecCount)++;
		Sleep(400);
		printf("Vector sucessfuly returned");
	}
	else {
		printf("Thats okay");
	}

}
