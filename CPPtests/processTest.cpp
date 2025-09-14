#include "TestProcess.h"

void TestProcess::ProcessBuffer(const float* input, float* output, size_t nFrames) {
    void_verb_process(verb, input, output, nFrames);
}
