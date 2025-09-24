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

    float result1  = 0.0f;

    for (int b = 0; b < numBuffers; ++b) {
        for (int i = 0; i < bufferSize; ++i) {
            result1 += std::pow(inBuffers[b][i] - outBuffers[b][i],2); // simple L2 norm 
        }
    }

    float result2  = 0.0f;

    //RBTest::testRB(flatOutBuffer, numBuffers*bufferSize);

    RBTest::testRB(flatOutBuffer, 512);

    // // for (int b = 0; b < numBuffers; ++b) {
    //     for (int i = 0; i < bufferSize; ++i) {
    //         // result2 += std::pow(inBuffers[b][i] - flatOutBuffer[b*bufferSize + i],2); // simple L2 norm 
    //         result2 += std::pow(inBuffers[0][i] - flatOutBuffer[i],2); // simple L2 norm 
    //     }
    // // }
    
    std::cout << "result1, result2: " << result1 << ", " << result2 << "\n";


    if (!(result1 < 1e-5) && (result2 < 1e-6)) 
    {
        std::cout << "res1 bad\n";
        return 1;
    }
    else if ((result1 < 1e-5) && !(result2 < 1e-6))
    {
        std::cout << "res2 bad\n";
        return 2;
    } else if (!(result1 < 1e-5) && !(result2 < 1e-6))
    {
        std::cout << "Both are bad\n";
    }
    std::cout << "all passed";
    return 0;
}