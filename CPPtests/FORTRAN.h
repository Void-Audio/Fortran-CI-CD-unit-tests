#pragma once
#include <cstddef>
#include <vector>

extern "C" {

    void ringpush(float* value);
         
    void ringpopall(std::vector<float>& outBuffer, size_t nFrames);

}
