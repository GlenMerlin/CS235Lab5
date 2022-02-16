#include "QS.h"

using namespace std;

QS::QS(){}
QS::~QS(){
    delete[]valueArray;
}

bool QS::createArray(int capacity){
    
    // cout << "inside the createArray function. Capacity: " << capacity << endl;
    size = capacity;
    if (capacity > 0){
        int *valueArray = new int[capacity];

        addIndex = 0;
        
        delete[]valueArray;
        return true;
    }
    else{
        return false;
    }
}

bool QS::addToArray(int value){
    // cout << "addIndex: " << addIndex << " is less than " << size << "." << endl;
    if (addIndex < size){
        valueArray[addIndex] = value;
        addIndex++;
        return true;
    }
    else{
        return false;
    }

}

void QS::sortAll(){
    medianOfThree(valueArray[0], valueArray[addIndex]);
}
int QS::medianOfThree(int left, int right){
    int middle = (left+right)/2;
    if (addIndex < 1){
        return -1;
    }
    if (left < 0 || right > size -1 || left > right || middle <= 0  || middle < left){
        return -1;
    }

    if (valueArray[left] > valueArray[middle]){
        swap(valueArray[left], valueArray[middle]);
    }

    if (valueArray[middle] > valueArray[right]){
        swap(valueArray[middle], valueArray[right]);
    }

    if (valueArray[middle] < valueArray[left]){
        swap(valueArray[middle], valueArray[left]);
    }
    return middle;
}
int QS::partition(int left, int right, int pivotIndex){
    if (addIndex < 1){
        return -1;
    }
    if (left < 0 || right < 0 || left >= size || right > size || left >= right || pivotIndex < left  || pivotIndex > right){
        return -1;
    }

    swap(valueArray[left], valueArray[pivotIndex]);
    
    int up, down;
    up = left +1;
    down = right;
    cout << "left: " << left << " right: " << right << " pivot: " << pivotIndex << endl;
    for (int i = 0; i < size; i++){
        cout << valueArray[i] << " ";
    }
    cout << endl;
    
    do{
        while(valueArray[left] > valueArray[up] && up != right){
            cout << "up: " << up << endl;
            up++;
                
        }
        while(valueArray[left] <= valueArray[down] && down != left){
            cout << "down: " << down << endl;
            down--;
        }

        if (up < down){
            swap(valueArray[up], valueArray[down]);
        }

    } while (up < down);
    
    swap(valueArray[left], valueArray[down]);
    return down;
}
string QS::getArray() const {
    string result = "";
    for (int i = 0; i < addIndex; i++){
        if (i < addIndex-1){
            // cout << valueArray[i] << ", " << endl;
            result += to_string(valueArray[i]) + ",";
        }
        else {
            // cout << "last one: " << valueArray[i] << endl;
            result += to_string(valueArray[i]) + "";
        }
    }
    return result;
}
int QS::getSize() const {
    return addIndex;
}
void QS::clear(){
    addIndex = 0;
    size = 0;
}

void swap (int x, int y){
    int temp = x;
    x = y;
    y = temp;
}