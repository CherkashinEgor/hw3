#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
  void print();
private:
  /// Add whatever helper functions and data members you need below
  int m;
  PComparator c;
  std::vector<T> data;
  void heapify(int i);
  void swap(int pos_1, int pos_2);
  void make_heap();
  int find_child(int i);
  void trickleup(int i);
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c){
  this->m = m;
  this->c = c;
};

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){};


template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
  return data.empty();
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::swap(int pos_1, int pos_2){
  T temp = data[pos_1];
  data[pos_1] = data[pos_2];
  data[pos_2] = temp;
}

//returns first child of the node
template <typename T, typename PComparator>
int Heap<T, PComparator>::find_child(int i){
  return i * m;
}

//called heapify because it used to be for a binary implementation
//switched it to k-ary late at night so this is more like trickleDown
template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify(int i){
  int kid = find_child(i); 
  if(kid >= data.size()){
    return;
  }

  int priority_child = kid;
  //compare kid to other children
  for(int j = 1; j <= m; j++){
    if(kid+j >= data.size()) continue;
    if(c(data[kid+j], data[priority_child])){
      priority_child = kid + j;
    }
  }
  
  //swap if c
  if(c(data[priority_child], data[i])){
    swap(priority_child, i);
    heapify(priority_child);
  }
  
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::trickleup(int i){
  if(i == 0 ) return;
  int parent = (i - 2) / (m);
  if(c(data[i], data[parent])){
    swap(i, parent);
    trickleup(parent);
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::print()
{
    std::cout << "Array representation of Heap is:\n";
    int size = data.size();
    for (int i = 0; i < size; ++i)
        std::cout << data[i] << " ";
    std::cout << "\n";
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::make_heap(){
  int arr_len = data.size();
  int start = (arr_len / 2) - 1;

  for(int i = start; i >= 0; i--){
    heapify(i);
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Underflow Error"); 

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return data.at(0);

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Underflow Error");

  }

  data.erase(data.begin());
  make_heap();

}


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T &item){
  data.push_back(item);
  trickleup(data.size()-1);
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return data.size();
}

#endif

