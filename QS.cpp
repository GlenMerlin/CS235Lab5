#include "QS.h"

using namespace std;

QS::QS(){}
QS::~QS(){}

bool QS::createArray(int capacity){
    cout << "inside the createArray function" << endl;
    if (capacity > 0){
        int valuearray[capacity];
        return true;
    }
    else{
        return false;
    }
}

bool QS::addToArray(int value){
    arraySize();
    if (addIndex < size){
        cout << "addIndex: " << addIndex << " is less than " << size << "." << endl;
        valueArray[addIndex] = value;
        addIndex++;
        return true;
    }
    else{
        return false;
    }

}

void QS::sortAll(){
    // cout << "inside the function" << endl;
}
int QS::medianOfThree(int left, int right){
    // cout << "inside the function" << endl;
    return 0;
}
int QS::partition(int left, int right, int pivotIndex){
    // cout << "inside the function" << endl;
    return 0;
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

void QS::arraySize(){
    size = sizeof(valueArray)/sizeof(valueArray[0]);
    // cout << "the size of the array is: " << size << endl;
}