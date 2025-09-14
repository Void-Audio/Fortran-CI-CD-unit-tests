#pragma once
#include <cstddef>

extern "C" {
    struct VOID_Verb_t;
    VOID_Verb_t* void_verb_create();
    void void_verb_destroy(VOID_Verb_t* v);
    void void_verb_reset(VOID_Verb_t* v);
}

class TestInit {
public:
    TestInit();
    ~TestInit();
    VOID_Verb_t* getVerb() const { return verb; }

private:
    VOID_Verb_t* verb;
};
