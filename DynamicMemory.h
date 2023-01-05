#ifndef DYNAMIC_MEMORY_H
#define DYNAMIC_MEMORY_H


template<typename T1>
void NullifyPointerVector(vector<T1*> vectorOfPtrs)
{
    for(T1* ptr : vectorOfPtrs
)
    {
        ptr = nullptr;
    }
}

template <typename T1>
void CleanPointerVector(vector<T1*> vectorOfPtrs)
{
    for(T1* ptr : vectorOfPtrs)
    {
        delete ptr;
        ptr = nullptr;
    }
}

template <typename T1>
void DeepCopyPointerVector(vector<T1*> ptrsToCopy, vector<T1*> targetVector)
{

    CleanPointerVector(targetVector);

    targetVector.clear();

    for(T1* ptr : ptrsToCopy)
    {
        targetVector.push_back(new T1(*ptr));
    }
}

template <typename T1>
void CleanDynamicArray(T1* array, int arraySize)
{
    if(array != nullptr)
    {
        delete [] array;
        array = nullptr;
    }

}

template <typename T1>
void DeepCopyDynamicArray(T1* arrayToCopy, T1* targetArray, int arraySize)
{

    if(arrayToCopy != nullptr)
    {
        CleanDynamicArray(targetArray, arraySize);

        targetArray = new T1[arraySize];

        for(int i = 0; i < arraySize; i++)
        {
            targetArray[i] = arrayToCopy[i];
        }
    }

};


#endif