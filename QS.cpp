#include "QS.h"

using namespace std;

QS::QS(){}
QS::~QS(){
    clear();
}

bool QS::createArray(int capacity){
    
    if (valueArray != NULL){
        clear();
    }
    size = capacity;    
    valueArray = new int[capacity];
    addIndex = 0;
    return true;
}

bool QS::addToArray(int value){
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
    if (addIndex <= 1){
        return;
    }
    quickSort(0, addIndex-1);
}

void QS::quickSort(int low, int high){
    if (high - low < 1){
        return;
    }
    if (high - low < 3){
        medianOfThree(low, high);
        return;
    }
    int pivot = medianOfThree(low, high);
    if (pivot < 0){
        return;
    }
    pivot = partition(low, high, pivot);
    if (pivot < 0){
        return;
    }
    quickSort(low, pivot-1);
    quickSort(pivot+1, high);
}

int QS::medianOfThree(int left, int right){
    int middle = (left+right)/2;
    if (addIndex < 1){
        return -1;
    }
    if (left < 0 || right > addIndex -1 || left > right || middle < 0  || middle < left || left == right){
        return -1;
    }

    if (valueArray[left] > valueArray[middle]){
        swap(valueArray[left], valueArray[middle]);
    }

    if (valueArray[middle] > valueArray[right]){
        swap(valueArray[middle], valueArray[right]);
    }

    if (valueArray[left] > valueArray[middle]){
        swap(valueArray[left], valueArray[middle]);
    }
    return middle;
}

int QS::partition(int left, int right, int pivotIndex){
    if (addIndex < 1){
        return -1;
    }
    if (left < 0 || right < 0 || left >= size || right >= size || left >= right || pivotIndex < left  || pivotIndex > right){
        return -1;
    }

    swap(valueArray[left], valueArray[pivotIndex]);
    
    int up, down;
    up = left +1;
    down = right;
    
    do{
        while(valueArray[up] <= valueArray[left] && up < right){
            cout << "up: " << up << endl;
            up++;
                
        }
        while(valueArray[down] > valueArray[left] && down != left){
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
    if (addIndex < 1){
        return "";
    }
    string result = "";
    for (int i = 0; i < addIndex; i++){
        if (i < addIndex-1){
            result += to_string(valueArray[i]) + ",";
        }
        else {
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
    delete[]valueArray;
    valueArray = NULL;
}

void swap (int x, int y){
    int temp = x;
    x = y;
    y = temp;
}