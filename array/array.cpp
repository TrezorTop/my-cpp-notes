#include <iostream>

void printArray(const int* arr, const int size) {
  std::cout << "printArray" << std::endl;
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << '\t';
  }
  std::cout << std::endl << std::endl;
}

void fillArray(int* const arr, const int size) {
  for (int i = 0; i < size; ++i) {
    arr[i] = rand() % 20;
  }
}

void push(int*& arr, int& size, const int value, const int index) {
  int* newArr = new int[++size];

  for (int i = 0, j = 0; i < size; ++i) {
    if (i == index) {
      newArr[i] = value;
      continue;
    }

    newArr[i] = arr[j];
    ++j;
  }

  delete[] arr;
  arr = newArr;
}

void pushBack(int*& arr, int& size, const int value) {
  int* newArr = new int[size + 1];

  for (int i = 0; i < size; ++i) {
    newArr[i] = arr[i];
  }

  newArr[size++] = value;

  delete[] arr;
  arr = newArr;
}

void pushStart(int*& arr, int& size, const int value) {
  int* newArr = new int[size + 1];

  newArr[0] = value;

  for (int i = 0; i < size; ++i) {
    newArr[i + 1] = arr[i];
  }

  size++;

  delete[] arr;
  arr = newArr;
}

void pop(int*& arr, int& size, const int index) {
  int* newArr = new int[--size];

  for (int i = 0, j = 0; i < size; ++i, ++j) {
    if (i == index) {
      ++j;
    }

    newArr[i] = arr[j];
  }

  delete[] arr;
  arr = newArr;
}

void popBack(int*& arr, int& size) {
  int* newArr = new int[--size];

  for (int i = 0; i < size; ++i) {
    newArr[i] = arr[i];
  }

  delete[] arr;
  arr = newArr;
}

void popStart(int*& arr, int& size) {
  int* newArr = new int[--size];

  for (int i = 0; i < size; ++i) {
    newArr[i] = arr[i + 1];
  }

  delete[] arr;
  arr = newArr;
}
