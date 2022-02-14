#pragma once
#include "QSInterface.h"
#include <iostream>
#include <vector>

using namespace std;

class QS: public QSInterface {
    protected:
        int valueArray[5];
    public:
    
    QS();
    
    ~QS();
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