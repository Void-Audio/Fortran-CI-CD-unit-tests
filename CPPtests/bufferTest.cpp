#include "ringBufferTest.h"
#include <iostream>

RingBufferTest::RingBufferTest(VOID_Verb_t* existingVerb)
    : verb(existingVerb)
{
    if (!verb) {
        std::cerr << "Warning: RingBufferTest initialized with null verb pointer!\n";
    }
}

void RingBufferTest::RunTest(const std::vector<float>& input, std::vector<float>& output) {
    if (!verb) {
        std::cerr << "Verb not initialized!\n";
        return;
    }

    size_t nFrames = input.size();
    output.resize(nFrames);
    verb_process(verb, input.data(), output.data(), nFrames);
}

void RingBufferTest::Reset() {
    if (verb) {
        verb_reset(verb);
    }
}
