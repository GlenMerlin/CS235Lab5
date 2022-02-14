#pragma once
#include "QSInterface.h"
#include <iostream>
#include <vector>

using namespace std;

class QS: public QSInterface {
    public:
    
    QS();
    
    ~QS();
    int *valueArray = new int[15];
    int addIndex = 0;
    int size;

    void sortAll() override;
    
    int medianOfThree(int left, int right) override;
    
    int partition(int left, int right, int pivotIndex) override;
    
    string getArray() const override;
    
    int getSize() const override;
    
    bool addToArray(int value) override;
    
    bool createArray(int capacity) override;
    
    void clear() override;

    void arraySize();
};