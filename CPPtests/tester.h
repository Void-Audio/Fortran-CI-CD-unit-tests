#pragma once
#include <vector>
#include <cstddef>
#include <stdexcept>
#include <cmath>

extern "C" {

    struct VOID_Verb_t;

    float void_rb_peek_index(VOID_Verb_t* v, size_t idx);
    size_t void_rb_get_write_index(VOID_Verb_t* v);
}

class BufferTester {
    
public:

    BufferTester(VOID_Verb_t* verbPtr, size_t bufSize);
    void TestProcessBlock(const std::vector<float>& input);

private:
    VOID_Verb_t* verb;
    size_t size;
    std::vector<float> snapshot;
};
