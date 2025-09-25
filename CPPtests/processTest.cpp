#include "processTest.h"

void ProcessTest::testProcess(const std::vector<float>& inBuffer, std::vector<float>& outBuffer, int bufferSize)
{
    for (int i = 0 ; i < bufferSize; i++)
    {
        vprocess(&inBuffer[i], &outBuffer[i]);
    }
}
