//
// Created by Fidelia Nawar on 1/30/20.
//
#include <iostream>
#include "Allocator.h"
#include "BestFit.h"
#include "WorstFit.h"
#include "FirstFit.h"

using std::cout;
using std::endl;
using std::string;
using std::exception;

Allocator::Allocator(const std::string &n) {
    allocatorName = n;
    cout << "Constructing Allocator Object: " << allocatorName << endl;
}

void* Allocator::operator new(size_t val) {
    cout << "Global new operator.  Allocating " << val << " bytes." << endl;
    //return malloc(val);
    void *storage = malloc(val);
    if(NULL == storage) {
        throw "allocation fail : no free memory";
    }
    cout << "size = " << val << ", address returned is = " << storage << endl;
    return storage;
}

void* Allocator::operator new[](size_t val){
    cout << "Global new[] operator.  Allocating " << val << " bytes." << endl;
    void *p;
    p =  malloc(val);
    if(!p)
    {
        throw "allocation fail : no free memory";
    }
    return p;
}

void Allocator::operator delete(void* ptr, size_t val) noexcept {
    cout << "Global delete operator. Deallocating..." << endl;
    if(ptr){
        free(ptr);
    }
}
void Allocator::operator delete[](void* ptr, size_t val) noexcept {
    cout << "Global delete[] operator. Deallocating..." << endl;
    if(ptr){
        free(ptr);
    }
}

