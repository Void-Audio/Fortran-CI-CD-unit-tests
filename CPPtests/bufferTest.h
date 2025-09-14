#pragma once
#include <cstddef>
#include <vector>

extern "C" {
    struct VOID_Verb_t;

    // Fortran C-bindings
    void verb_process(VOID_Verb_t* v, const float* in, float* out, size_t nFrames);
    void verb_reset(VOID_Verb_t* v);
}

// C++ helper class to test the buffer using an existing verb object
class RingBufferTest {
public:
    RingBufferTest(VOID_Verb_t* existingVerb);
    
    // Push input vector through the buffer and get output
    void RunTest(const std::vector<float>& input, std::vector<float>& output);

    // Reset the buffer
    void Reset();

private:
    VOID_Verb_t* verb;
};
