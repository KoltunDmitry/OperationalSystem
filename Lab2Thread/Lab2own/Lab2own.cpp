#include "stdafx.h"
#include <windows.h>
#include <iostream>
using namespace std;

struct MulMatrixOnVector {
	int **arr;
	int *vector;
	int *result;
	int size;
	MulMatrixOnVector(int n) {
		size = n;
		arr = new int*[n];
		for (int i = 0; i < n; i++) {
			arr[i] = new int[n];
		}
		result = new int[n];
		vector = new int[n];
		for (int i = 0; i < n; i++)
		{
			result[i] = 0;
		}
	}
	void inputMatrixAndVector() {
		std::cout << "input " << size * size << " elements of matrix\n";
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				std::cin >> arr[i][j];
			}
		}
		std::cout << "input " << size << " elements of vector\n";
		for (int i = 0; i < size; i++) {
			std::cin >> vector[i];
		}
	}
	void outputResult() {
		std::cout << "Multiplication matrix on vector:\n";
		for (int i = 0; i < size; i++) {
			std::cout << "result "<< i << result[i] << "\n";
		}
	}
	~MulMatrixOnVector() {
		delete[]result;
		delete[]vector;
		for (int i = 0; i < size; i++) {
			delete[]arr[i];
		}
		delete[]arr;

	}
};
int inputSizeOfMatrix() {
	int n = 0;
	std::cout << "input size of matrix and vector\n";
	std::cin >> n;
	return n;
}
MulMatrixOnVector mulMatrixOnVector(inputSizeOfMatrix());
DWORD WINAPI mul(LPVOID iNum) {
	int iteration = (int)iNum;
	for (int i = 0; i < mulMatrixOnVector.size; i++) {
		mulMatrixOnVector.result[iteration] += mulMatrixOnVector.arr[iteration][i] * mulMatrixOnVector.vector[i];
		Sleep(7);
	}
	cout << "result " << iteration << " " << mulMatrixOnVector.result[iteration] << "\n";
	return 0;
}
int main()
{	int n = mulMatrixOnVector.size;
	mulMatrixOnVector.inputMatrixAndVector();
	HANDLE *hThread = new HANDLE[n];
	DWORD *IDThread = new DWORD[n];
	for (int i = 0; i < n; i++) {
		hThread[i] = CreateThread(NULL, 0, mul, (void*)i, 0, &IDThread[i]);
		if (hThread[i] == NULL) {
			return GetLastError();
		}
	}
	WaitForMultipleObjects(n, hThread,true,INFINITE);

	for (int i = 0; i < n; i++) {
		CloseHandle(hThread[i]);
	}
	delete[]hThread;
	delete[]IDThread;
	//mulMatrixOnVector.outputResult();
	system("pause");
	return 0;
}

