#include <exception>
#include <iostream>
#include <string>

using std::cout, std::string;

template <typename T>
class List {
  public:
    List();

    ~List();

    T& operator[](int index);

    void insert(T data, int index);

    void push_front(T data);

    void pop_front();

    void push_back(T data);

    void pop_back();

    void remove_at(int index);

    void clear();

    int getSize() {
      return this->size;
    }

  private:
    class Node {
      public:
        T data;
        Node* nextNodePointer;

        explicit Node(T data = T(), Node* nextNodePointer = nullptr) {
          this->data = data;
          this->nextNodePointer = nextNodePointer;
        }
    };

    int size;
    Node* head;

    Node* getNode(int index) {
      if (index < 0 || index >= this->size) throw std::out_of_range("Given index is out of bounds");

      Node* targetNode = this->head;

      for (int i = 0; i < index; i++) {
        targetNode = targetNode->nextNodePointer;
      }

      return targetNode;
    }
};

template <typename T>
List<T>::List() {
  this->size = 0;
  this->head = nullptr;
}

template <typename T>
List<T>::~List() {
  this->clear();
}

template <typename T>
T& List<T>::operator[](int index) {
  return this->getNode(index)->data;
}

template <typename T>
void List<T>::insert(T data, int index) {
  if (index == 0) return this->push_front(data);
  if (index == this->size) return this->push_back(data);

  Node* previous = this->getNode(index - 1);

  previous->nextNodePointer = new Node(data, previous->nextNodePointer);
  this->size++;
}

template <typename T>
void List<T>::push_front(T data) {
  this->head = new Node(data, this->head);
  this->size++;
}

template <typename T>
void List<T>::pop_front() {
  if (this->head == nullptr) throw std::out_of_range("List is empty");

  Node* nodeToDelete = this->head;

  this->head = nodeToDelete->nextNodePointer;

  delete nodeToDelete;
  this->size--;
}

template <typename T>
void List<T>::push_back(T data) {
  if (this->head == nullptr) {
    this->head = new Node(data);
    this->size++;
    return;
  }

  Node* lastNode = getNode(this->size - 1);

  lastNode->nextNodePointer = new Node(data);
  this->size++;
}

template <typename T>
void List<T>::pop_back() {
  if (this->head == nullptr) throw std::out_of_range("List is empty");

  Node* previous = this->getNode(size - 2);

  delete previous->nextNodePointer;
  previous->nextNodePointer = nullptr;
  this->size--;
}

template <typename T>
void List<T>::clear() {
  while (this->size) {
    this->pop_front();
  }
}

template <typename T>
void List<T>::remove_at(int index) {
  if (index == 0) {
    pop_front();
    return;
  }
  if (index == this->size - 1) {
    pop_back();
    return;
  }

  Node* previous = getNode(index - 1);
  Node* nodeToDelete;

  nodeToDelete = previous->nextNodePointer;
  previous->nextNodePointer = nodeToDelete->nextNodePointer;

  delete nodeToDelete;
  this->size--;
}

int main() {
  List<int> list;

  list.push_back(1);
  list.push_back(2);
  list.push_back(3);

  for (int i = 0, size = list.getSize(); i < size; i++) {
    cout << list[i] << '\n';
  }

  return 0;
}