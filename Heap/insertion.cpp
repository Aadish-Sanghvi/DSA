#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }
    void insert(int val){
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
            }
            else{
                return;
            }
        }
    }
    void deletefromHeap(){
        if(size == 0){
            cout << "Nothing to delete" << endl;
            return;
        }
        //Step 1: put element into first index
        arr[1] = arr[size];

        //Step 2: remove last element
        size--;

        //Step 3: take root node to its correct pos.
        int i = 1;
        while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            // if((rightIndex < size && arr[i] < arr[rightIndex]) && (leftIndex < size && arr[i] < arr[leftIndex])){
            //     if(arr[leftIndex] < arr[rightIndex]){
            //         swap(arr[i], arr[rightIndex]);
            //         i = leftIndex;
            //     }
            // }
            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
};



int main(){
    heap h;
    h.insert(55);
    h.insert(51);
    h.insert(53);
    h.insert(50);
    h.insert(49);
    h.print();

    cout << "After deleting the greatest value from the Max heap: " << endl;
    h.deletefromHeap();
    h.print();

    return 0;
}