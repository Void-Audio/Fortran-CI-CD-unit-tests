#include "TestInit.hpp"

TestInit::TestInit() {
    verb = void_verb_create();
    void_verb_reset(verb); 
}

TestInit::~TestInit() {
    void_verb_destroy(verb);
}
