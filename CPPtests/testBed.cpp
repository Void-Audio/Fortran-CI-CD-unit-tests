/*
 *  Unit Tests built to demonstrate the initial CI/CD pipeline 
 *  with fortran integration into iPlug2OOS build
 */
#include "processTest.h"
#include "rbTest.h"
#include <random>
#include <iostream>


int main() 
{
    int numBuffers     = 5;
    int bufferSize     = 512;
    int flattenedBuffers = numBuffers * bufferSize;


    // Build 5, size = 512 buffers to load into the ring

    std::vector<std::vector<float>> inBuffers(numBuffers, std::vector<float>(bufferSize));
    std::vector<std::vector<float>> outBuffers(numBuffers, std::vector<float>(bufferSize));

    float  flatOutBuffer[bufferSize];


    std::random_device rd;
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<float> dist(-1.0f, 1.0f);

    for (int b = 0; b < numBuffers; ++b) {
        for (int i = 0; i < bufferSize; ++i) {
            inBuffers[b][i] = dist(gen);
        }
    }
    for (int b = 0; b < numBuffers; ++b) {
        ProcessTest::testProcess(inBuffers[b],  outBuffers[b], bufferSize);
    }

    float result  = 0.0f;

    for (int b = 0; b < numBuffers; ++b) {
        for (int i = 0; i < bufferSize; ++i) {
            result += std::pow(inBuffers[b][i] - outBuffers[b][i],2); // simple L2 norm 
        }
    }


    
    std::cout << result << "\n";


    if (!(result < 1e-5))
    {
        std::cout << "result bad ( .neq. 0 ) \n";
        return 1;
    }

    return 0;
}