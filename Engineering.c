#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include <windows.h>
#include <stdio.h>

typedef struct {
    float vector[3];
} Components;
typedef struct {
    float vector[3];
    float position[3];
} EngVector;
void EngineeringMain() {
    Components Position;
    Components Force;
    Components Unit;
    Components P1, P2;
    int choice = 0;
    while (1) {
        printf("Please enter -1 to quit\n");
        printf("**************************\n");
        printf("Engineering options\n");
        printf("1. MomentCalculatorOnAxis\n2. Multipiple_Force_Vectors_With_Axis_Moment_Calculator\n");
        printf("**************************\n");
        scanf("%d", &choice);
        if (choice == 1) {
            float crossResult[3] = { 0,0,0 };
            float length = 0;
            char unitChoice = ' ';
            printf("Please enter the position vector (e.g 2 3 2): ");
            scanf("%f %f %f", &Position.vector[0], &Position.vector[1], &Position.vector[2]);
            printf("Please enter the Force Vector (Fx Fy Fz): ");
            scanf("%f %f %f", &Force.vector[0], &Force.vector[1], &Force.vector[2]);
            printf("Do you have Vector of the axis? [y|n]: ");
            scanf(" %c", &unitChoice);
            if (unitChoice == 'n') {
                printf("Please enter two Points P1 and P2 on the chosen axis\n");
                printf("P1 (i, j, k): ");
                scanf("%f %f %f", &P1.vector[0], &P1.vector[1], &P1.vector[2]);
                printf("P2 (i, j, k): ");
                scanf("%f %f %f", &P2.vector[0], &P2.vector[1], &P2.vector[2]);
                Unit.vector[0] = P2.vector[0] - P1.vector[0];
                Unit.vector[1] = P2.vector[1] - P1.vector[1];
                Unit.vector[2] = P2.vector[2] - P1.vector[2];
                Sleep(200);
                printf("The formula for finding the moment across an axis is M = (r x F) dot lambda\n");
                Sleep(600);
                printf("This is where r is the position vector relative from the force of action, F is a force vector, and lambda is the unit vector of the axis\n\n");
                length = vector_length(Unit.vector);
                for (int i = 0; i < 3; i++) {
                    Unit.vector[i] /= length;
                }
                vector_cross_product(Position.vector, Force.vector, crossResult);
                float final = vector_dot_product(crossResult, Unit.vector);
                Sleep(400);
                printf("The moment is %f N dot m\n", final);
                Sleep(700);
                printf("Please note a positive value means it runs counter-clockwise along the axis\n");
            }
            else if (unitChoice == 'y') {
                printf("Great please enter axis vector in the same format (i j k): ");
                scanf("%f %f %f", &Unit.vector[0], &Unit.vector[1], &Unit.vector[2]);
                Sleep(200);
                printf("The formula for finding the moment across an axis is M = (r x F) dot lambda\n\n");
                Sleep(700);
                printf("This is where r is the position vector relative from the force of action, F is a force vector, and lambda is the unit vector of the axis\n\n");
                length = vector_length(Unit.vector);
                for (int i = 0; i < 3; i++) {
                    Unit.vector[i] /= length;
                }
                vector_cross_product(Position.vector, Force.vector, crossResult);
                float final = vector_dot_product(crossResult, Unit.vector);
                printf("The moment is %f N dot m\n", final);
                Sleep(500);
                printf("Please note a positive value means it runs counter-clockwise along the axis\n");
            }
            else {
                printf("Invalid input, please try again.\n");
            }
        }
        else if (choice == 2) {
            EngVector engVec[12];
            int VecCount = 0;
            float tempMoment[3] = { 0.0f, 0.0f, 0.0f };
            float Moment[3] = { 0.0f, 0.0f, 0.0f };
            float axisVector[3] = { 0.0f, 0.0f, 0.0f };
            printf("Please enter how many Force Vectors there are going to be (max 12): ");
            scanf("%d", &VecCount);
            printf("Please note that the position vector is tricky remember the reference points, not just coordinates\n\n");
            for (int i = 0; i < VecCount; i++) {
                printf("%d. Please enter the force components (Fx Fy Fz): ", i + 1);
                scanf("%f %f %f", &engVec[i].vector[0], &engVec[i].vector[1], &engVec[i].vector[2]);
                printf("Now please enter the corresponding position vector (rx ry rz): ");
                scanf("%f %f %f", &engVec[i].position[0], &engVec[i].position[1], &engVec[i].position[2]);
            }
            for (int i = 0; i < VecCount; i++) {
                tempMoment[0] = 0.0f;
                tempMoment[1] = 0.0f;
                tempMoment[2] = 0.0f;
                vector_cross_product(engVec[i].position, engVec[i].vector, tempMoment);
                for (int j = 0; j < 3; j++) {
                    Moment[j] += tempMoment[j];
                }
            }
            printf("The resultant moment is: %f %f %f\n", Moment[0], Moment[1], Moment[2]);
            char axis = ' ';
            printf("Did you want this around an axis? [y|n]: ");
            scanf(" %c", &axis);
            if (axis == 'y') {
                float length = 0.0f;
                float dotValue = 0.0f;
                printf("Alright, please enter the axis vector (i j k): ");
                scanf("%f %f %f", &axisVector[0], &axisVector[1], &axisVector[2]);
                length = vector_length(axisVector);
                for (int i = 0; i < 3; i++) {
                    axisVector[i] /= length;
                }
                dotValue = vector_dot_product(Moment, axisVector);
                printf("The moment across that axis is: %f N . m\n", dotValue);
                Sleep(100);
                printf("Note that a positive value indicates counter-clockwise across that axis\n");
            }
            else if (axis == 'n') {
                char newChoice = ' ';
                float newLength = 0.0f;
                printf("The formula for Moment is r X F, where r is the position vector and F is the force vector\n");
                printf("Would you like the magnitude of the Moment? [y|n]: ");
                scanf(" %c", &newChoice);
                if (newChoice == 'y') {
                    newLength = vector_length(Moment);
                    printf("The magnitude of the moment is: %f\n", newLength);
                }
                else {
                    printf("Okay, done.\n");
                }
            }
        }
        else if (choice == 0) {
            system("cls");
        }
        else if (choice == -1) {
            printf("Exiting...\n");
            Sleep(100);
            break;
        }
        else {
            printf("Invalid menu choice.\n");
        }
    }
}
