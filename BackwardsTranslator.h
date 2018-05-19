#ifndef BACKWARDS_TRANSLATOR_H
#define BACKWARDS_TRANSLATOR_H

// Backwards Translator reverses the order of every character in your message

#include <algorithm>

#include "Translator.h"

class BackwardsTranslator : public Translator {
public:
    std::string getLanguage() { return "Backwards"; }
    std::string translate(std::string& message) { std::reverse(message.begin(), message.end()); return message; }
    std::string untranslate(std::string& message) { return translate(message); }
};

#endif
