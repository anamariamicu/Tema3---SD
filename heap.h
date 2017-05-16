#ifndef HEAP_H
#define HEAP_H

#include<iostream>
 
template <typename T>
class Heap
{ 
private:
    T* values;
    int dimVect;
    int capVect;
public:
    Heap(int capVect);

    ~Heap();
 
    int parent(int poz);
 
    int leftSubtree(int poz);
 
    int rightSubtree(int poz);
 
    void pushUp(int poz);
 
    void pushDown(int poz);
 
    void insert(T x);
 
    T peek();
 
    T extractMin();

    void displayVect();
};



template <typename T>
Heap<T>::Heap(int capVect)
{
    this->capVect = capVect;
    dimVect = 0;
    values = new T[capVect];
}

template <typename T>
Heap<T>::~Heap()
{
    delete[] values;
}


template <typename T>
int Heap<T>::parent(int poz)
{
    return (poz - 1) / 2;
}

template <typename T>
int Heap<T>::leftSubtree(int poz)
{
    return 2 * poz + 1;
}

template <typename T>
int Heap<T>::rightSubtree(int poz)
{
    return 2 * poz + 2;
}

template <typename T>
void Heap<T>::pushUp(int poz)
{
    int parent = this->parent(poz);
    while (poz > 0 && values[parent] > values[poz]) {
      T aux = values[poz];
      values[poz] = values[parent];
      values[parent] = aux;
      poz = parent;
      parent = this->parent(poz);
    }
}

template <typename T>
void Heap<T>::pushDown(int poz)
{
    while (1) {
      if (rightSubtree(poz) > dimVect - 1) { // nu exista right
        if (leftSubtree(poz) > dimVect - 1) { // nu exista left
          break;
        } else { // exista left
          if (values[poz] > values[leftSubtree(poz)]) {
            T aux = values[poz];
            values[poz] = values[leftSubtree(poz)];
            values[leftSubtree(poz)] = aux;
            poz = leftSubtree(poz);
          } else { // se respecta conditia de ordine crescatoare
            break;
          }
        }
      } else { // exista si left si right
          if (values[leftSubtree(poz)] < values[rightSubtree(poz)]) {
            if (values[poz] > values[leftSubtree(poz)]) { // ordine
              T aux = values[poz];
              values[poz] = values[leftSubtree(poz)];
              values[leftSubtree(poz)] = aux;
              poz = leftSubtree(poz);
            } else {
              break; // se respecta ordinea
            }
          } else {
            if (values[poz] > values[rightSubtree(poz)]) {
              T aux = values[poz];
              values[poz] = values[rightSubtree(poz)];
              values[rightSubtree(poz)] = aux;
              poz = rightSubtree(poz);
            } else {
              break; // se respecta ordinea
            }
          }
      }
    }
}


template <typename T>
void Heap<T>::insert(T x)
{
    if (dimVect == capVect) {
      capVect = capVect * 2;
      T *newValues = new T[capVect];
      std::memcpy(newValues, values, dimVect * sizeof(T));
      delete[] values;
      values = newValues;
    }
    values[dimVect] = x;
    ++dimVect;
    pushUp(dimVect - 1);
}

template <typename T>
T Heap<T>::peek()
{
    if (dimVect > 0) {
      return values[0];
    }
    return T();
}

template <typename T>
T Heap<T>::extractMin()
{
    T aux = values[0];
    values[0] = values[dimVect - 1];
    values[dimVect - 1] = aux;
    --dimVect;
    if (dimVect < capVect / 2) {
      capVect = capVect / 2;
      T *newValues = new T[capVect];
      std::memcpy(newValues, values, dimVect * sizeof(T));
      delete[] values;
      values = newValues;
    }
    pushDown(0);
    return aux;
}

template <typename T>
void Heap<T>::displayVect()
{
    for (int i = 0; i < dimVect; ++i) {
      std::cout << values[i] << " ";
    }
}

#endif // HEAP_H
