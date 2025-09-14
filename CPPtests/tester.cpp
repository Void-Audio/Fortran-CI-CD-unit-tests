#include "Tester.h"
#include "FORTRAN.h" 
#include <iostream>
#include <cassert>

BufferTester::BufferTester(VOID_Verb_t* verbPtr, size_t bufSize)
    : verb(verbPtr), size(bufSize), snapshot(bufSize, 0.0f)
{
}

void BufferTester::TestProcessBlock(const std::vector<float>& input) {
    std::vector<float> output(input.size(), 0.0f);

    extern "C" void void_verb_process(VOID_Verb_t* v, const float* in, float* out, size_t nFrames);
    void_verb_process(verb, input.data(), output.data(), input.size());

    for (size_t i = 0; i < size; ++i)
        snapshot[i] = void_rb_peek_index(verb, i);

    for (size_t i = 0; i < size; ++i) {
        if (std::isnan(snapshot[i])) {
            throw std::runtime_error("NaN detected in ring buffer at index " + std::to_string(i));
        }
    }

    size_t writeIdx = void_rb_get_write_index(verb);
    for (size_t i = 0; i < input.size(); ++i) {
        size_t idx = (writeIdx + size - input.size() + i) % size;
        if (std::abs(snapshot[idx] - input[i]) > 1e-6f) {
            std::cerr << "Mismatch at buffer[" << idx << "]: expected "
                      << input[i] << ", found " << snapshot[idx] << "\n";
        }
    }

    std::cout << "First 5 samples in buffer snapshot: ";
    for (size_t i = 0; i < 5 && i < size; ++i)
        std::cout << snapshot[i] << " ";
    std::cout << "\n";
}
