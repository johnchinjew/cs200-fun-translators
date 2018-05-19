#ifndef COPYCAT_TRANSLATOR_H
#define COPYCAT_TRANSLATOR_H

// Copycat Translator simply repeats your exact message back to you

#include "Translator.h"

class CopycatTranslator : public Translator {
public:
    std::string getLanguage() { return "Copycat"; }
    std::string translate(std::string& message) { return message; }
    std::string untranslate(std::string& message) { return message; }
};

#endif
