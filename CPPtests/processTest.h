#pragma once
#include <cstddef>
#include "FORTRAN.h"  

class TestProcess {
public:
    explicit TestProcess(VOID_Verb_t* v) : verb(v) {}

    void ProcessBuffer(const float* input, float* output, size_t nFrames);

    VOID_Verb_t* getVerbPointer() const { return verb; }

private:
    VOID_Verb_t* verb;
};
