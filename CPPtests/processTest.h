#pragma once
#include "FORTRAN.h"


// C++ helper class to test the buffer 
class ProcessTest {

public:

    // Push @bufferSize input floats through process function
static void testProcess(const std::vector<float>& inBuffer, std::vector<float>& outBuffer, int bufferSize);




};
