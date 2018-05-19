#ifndef OLD_ENGLISH_TRANSLATOR_H
#define OLD_ENGLISH_TRANSLATOR_H

// Old English translator replaces certain words in your message with common Old English phrases

#include "Translator.h"

class OldEnglishTranslator : public Translator {
public:
    OldEnglishTranslator();
    std::string getLanguage() { return "Old English Translator"; }
    std::string translate(std::string& message);
    std::string untranslate(std::string& message);
private:
    std::unordered_map<std::string, std::string> translateLegend = {
        { "hello", "salutations" },
        { "sir", "my-lord" },
        { "madam", "young-lady" },
        { "boy" , "lad" },
        { "girl" , "ladee" },
        { "you", "thou" },
        { "your", "thy" },
        { "are", "art" },
        { "the", "ye" },
        { "there", "yonder" },
        { "old", "olde" },
        { "young", "gerd" },
        { "day", "morn" },
        { "night", "twilight" },
        { "meat", "mutton" },
    };
    std::unordered_map<std::string, std::string> untranslateLegend;
    std::vector<std::string> prefixes = {
        "Oi!",
        "Mate!",
        "Top of the mornin!",
        "Eh,",
    };
};

OldEnglishTranslator::OldEnglishTranslator() {
    for (std::pair<std::string, std::string> entry : translateLegend) {
        untranslateLegend.insert({entry.second, entry.first});
    }
    for (auto p : prefixes) {
        untranslateLegend.insert({p, ""});
    }
}

std::string OldEnglishTranslator::translate(std::string& message) {
    return prefixes.at(rand() % prefixes.size()) + " " + findAndReplaceWords(message, translateLegend);
}

std::string OldEnglishTranslator::untranslate(std::string& message) {
    std::string output = findAndReplaceWords(message, untranslateLegend);
    return output.substr(1, output.size());
}

#endif
