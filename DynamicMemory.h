#ifndef DYNAMIC_MEMORY_H
#define DYNAMIC_MEMORY_H


template<typename T1>
void NullifyPointerVector(vector<T1*> ptrStructure)
{
    for(T1* ptr : ptrStructure)
    {
        ptr = nullptr;
    }
};

template <typename T1>
void CleanPointerVector(vector<T1*> ptrStructure)
{
    for(T1* ptr : ptrStructure)
    {
        delete ptr;
        ptr = nullptr;
    }
};


#endif