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
void EngineeringMain();
float vector_length(float vec[]);
void VectorMain();
void vector_unit(float Vec[], Vector* vector, int* VecCount);
void vector_projection(float Vec1[], float onto_Vec2[]);
void vector_cross_product(float vec1[], float vec2[], float result[]);
float angle_between_vectors(float vec1[], float vec2[]);
void fibo(int n);
void syntheticDivision(int PolyArray[], int numberOfcoefficients, int MainPolynomial[]);
void randomGenerator(void);
void PasswordGen(int length);
void CaesarEncrypt(char* input2, int key2);
void CaesarDecrypt(char* input, int key);
int ServerConnect();
void Prime(int n);
void VigenereEncryption(char* input);
void VigenereDecryption(char* input);
void clearInputBuffer();
void Shuffle(char Cards[][30]);
void Print(char cards[]);
void ClearInput();
void Compare(int PlayerPoints, int DealerPoints);
int Calculate(char cards[], int count);
void PrintRoyal(char c);
void AES_JournalMenu();
void handleErrors();
void derive_key_iv(const char* password, unsigned char* key, unsigned char* iv);
int encrypt(unsigned char* plaintext, int plaintext_len, unsigned char* key,
	unsigned char* iv, unsigned char* ciphertext);
int decrypt(unsigned char* ciphertext, int ciphertext_len, unsigned char* key,
	unsigned char* iv, unsigned char* plaintext);
void MatrixPrint(int** Matrix, int row, int column);
int Add_Matrix(int** Matrix1, int** Matrix2, int row1, int column1, int row2, int column2, int coefficient);
int** CreateMatrix(int row, int column);
void MatrixFill(int** Matrix, int row, int column);
void Multiplication_Matrix(int** Matrix1, int row1, int column1, int** Matrix2, int row2, int column2);
int MatrixDeterminant(int** Matrix, int row, int column);
void Matrix_Main();
void clearInputBuffer();
void Destroy(int** Matrix, int row);
void linePrint(FILE* View);
void TxtView(FILE* noteFiles);
void Note();
void StringReplace(char* string);
int WeatherMain();
size_t write_callback(void* data, size_t size, size_t nmemb, void* userp);
void MSpaint(FILE* InputWrite, char* imageName);
double ConvertSpeed(double* v, char* from, char* to);
float vector_dot_product(float vec1[], float vec2[]);
int NetworkMain(); 
void TodoList();
void todo_log_viewer(FILE* r, int doneFilter);
FILE* task_selecter(FILE* list, int Remove);
