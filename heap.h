#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

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

private:
  /// Add whatever helper functions and data members you need below

	void heapify_up(size_t index); //for inserting element
	void heapify_down(size_t index); //for removing element
  std::vector<T> data;
	int m;
	PComparator compare; // determinen heap order
	



};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c):m(m), compare(c){}


template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const{
	
	return data.empty();
}


template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
	
	return data.size();

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
    throw std::underflow_error("empty Heap");

  }
  
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];


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
    throw std::underflow_error("empty Heap");

  }

  //swap first and last element -> remove the last
  std::swap(data.front(), data.back());
  data.pop_back();
  if(!empty()){

   heapify_down(0); //restore order
		
  }

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item){

	data.push_back(item); //add item to the last
	heapify_up(data.size() -1); //maintain order

  
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify_up(size_t index){
	
  if(index==0){ //if no parent
    return;
  }
  size_t parent_index = (index-1)/m;

  if(compare(data[index],data[parent_index])){ //if child has higher priority than parent, swap
    std:: swap(data[index], data[parent_index]);
    heapify_up(parent_index);
    }


}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify_down(size_t index){

 

  if(index>=data.size()){
    return;
  }
  size_t first_chld = m* index+1;
  size_t smallest_chld = first_chld;

  if(smallest_chld>=data.size()){
    return;
  }
  for(size_t i=0; i<= static_cast<size_t>(m); i++){ //search for m children and find smallest
    size_t child = first_chld + i;

    if(child<data.size()&&compare(data[child], data[smallest_chld])){
      smallest_chld = child; 
    }
  }

  if(compare(data[smallest_chld], data[index])){ 
    std::swap(data[index], data[smallest_chld]);//if found, swap
    heapify_down(smallest_chld); //recursively
  }
}


#endif

