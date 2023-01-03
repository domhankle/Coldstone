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
};

template <typename T1>
void CleanPointerVector(vector<T1*> vectorOfPtrs)
{
    for(T1* ptr : vectorOfPtrs
)
    {
        delete ptr;
        ptr = nullptr;
    }
};

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
void NullifyPointerArray(T1* arrayOfPtrs)
{
    for(T1* ptr : arrayOfPtrs)
    {
        ptr = nullptr;
    }
}

template <typename T1>
void CleanPointerArray(T1* arrayOfPtrs)
{
    for(T1* ptr : arrayOfPtrs)
    {
        delete ptr;
        ptr = nullptr;
    }
}


#endif