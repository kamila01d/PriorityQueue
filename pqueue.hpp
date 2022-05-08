#include <iostream>
#include <vector>

template <typename T>
struct element{
    T value;
    int priority;
    element() : value(T()), priority() {} // konstruktor domyslny
    element(const T& value, int priority) : value(value), priority(priority) {}
};
template <typename T>
class PQueue{
private:

    std::vector<element<T>> heap;
    int size = 0;

public:
    PQueue(){}
    int parent(int i) {
        return (i - 1) / 2;
    }

    void swap(element<T> *pElement, element<T> *cElement) {
        element<T> tmp = *pElement;
        *pElement = *cElement;
        *cElement = tmp;
    }

    void enqueue(T value, int priority) {

        element<T> elem(value, priority);
        heap.push_back(elem);
        size = size+1;

        int i = size - 1;

        while (i != 0 && heap[parent(i)].priority < heap[i].priority) {

            swap(&heap[parent(i)], &heap[i]);
            i = parent(i);
        }

    }

    T front(){
        if(size == 0)
            throw std::logic_error("Priority Queue is empty!");
        else {
            return heap[0].value;
        }
    }
    T dequeue() {
        if(size == 0)
            throw std::logic_error("Priority Queue is empty!");
        else {
            T maxItem = heap[0].value;
            element<T> element = heap[size - 1];

            heap[0] = element;
            heap.pop_back();
            size = size - 1;

            heapBuilder(0);
            return maxItem;
        }
    }
    void heapBuilder(int i){

        int left_child = 2*i + 1;;
        int right_child = 2*i + 2;
        int largest = i;

        if (left_child <= size && heap[left_child].priority > heap[largest].priority)
            largest = left_child;

        if (right_child <= size && heap[right_child].priority > heap[largest].priority)
            largest = right_child;

        if (largest != i) {
            swap(&heap[i],&heap[largest]);
            heapBuilder(largest);
        }

    }


    int Size(){
        return size;
    }


};
