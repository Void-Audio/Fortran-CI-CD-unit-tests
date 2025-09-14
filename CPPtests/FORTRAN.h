#pragma once
#include <cstddef>

extern "C" {
    struct VOID_Verb_t;

    VOID_Verb_t* VVerberb_create();
    void VVerb_final(VOID_Verb_t* v);

    void VVerb_reset(VOID_Verb_t* v);

    void VVerb_process(VOID_Verb_t* v, const float* in, float* out, size_t nFrames);

    float VVerb_peek_ring(VOID_Verb_t* v);          
    void VVerb_peek_ring_full(VOID_Verb_t* v, float* outBuffer, size_t nFrames);
}
