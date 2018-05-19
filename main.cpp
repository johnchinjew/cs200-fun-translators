// Course:COMSC-200-5001
// By: John Chin-Jew, Jagminder Shergill

#include <iostream>
#include <string>

#include "Translator.h"
#include "CopycatTranslator.h"
#include "JumblerTranslator.h"
#include "BackwardsTranslator.h"
#include "PirateTranslator.h"
#include "SpoonerismTranslator.h"
#include "OldEnglishTranslator.h"

void printTranslatorOutput(Translator*, std::string&, bool);
int getNumberChoice();

int main() {
    srand(time(0));

    // Translator choices
    const size_t TR_COPYCAT = 1;
    const size_t TR_JUMBLER = 2;
    const size_t TR_BACKWARDS = 3;
    const size_t TR_PIRATE = 4;
    const size_t TR_PIG_LATIN = 5;
    const size_t TR_OLD_ENGLISH = 6;
    const size_t TR_QUIT = 7;

    // Action choices
    const size_t ACTION_TRANSLATE = 1;
    const size_t ACTION_UNTRANSLATE = 2;
    const size_t ACTION_PICK_DIFFERENT_LANGUAGE = 3;
    const size_t ACTION_QUIT = 4;

    // Pick translator
    while(true) {
        int translatorChoice = 0;
        std::cout << "\nPick a translator:\n";
        std::cout << "1. Copycat\n";
        std::cout << "2. Jumbler\n";
        std::cout << "3. Backwards\n";
        std::cout << "4. Pirate\n";
        std::cout << "5. Spoonerism\n";
        std::cout << "6. Old English\n";
        std::cout << "7. Quit\n";

        // Check for valid user input
        while (translatorChoice < TR_COPYCAT || translatorChoice > TR_QUIT) {
            translatorChoice = getNumberChoice();
        }

        // Quit program
        if (translatorChoice == TR_QUIT) {
            return 0;
        }

        // Translate or untranslate
        while(true) {
            int actionChoice = 0;
            std::cout << "\nPick an option:\n";
            std::cout << "1. Translate a message\n";
            std::cout << "2. Untranslate a message\n";
            std::cout << "3. Pick a different translator\n";
            std::cout << "4. Quit\n";

            // Check for valid user input
            while (actionChoice < ACTION_TRANSLATE || actionChoice > ACTION_QUIT) {
                actionChoice = getNumberChoice();
            }

            // Pick a different translator
            if (actionChoice == ACTION_PICK_DIFFERENT_LANGUAGE) {
                break;
            }

            // Quit program
            if (actionChoice == ACTION_QUIT) {
                return 0;
            }

            // Get user input message
            std::string message;
            std::cout << "\nEnter message: ";
            getline(std::cin, message);

            // Output new message, specifying translator and translate/untranslate
            bool isUntranslate = actionChoice - 1;
            Translator* t;
            if (translatorChoice == TR_COPYCAT) {
                t = new CopycatTranslator;
            } else if (translatorChoice == TR_JUMBLER) {
                t = new JumblerTranslator;
            } else if (translatorChoice == TR_BACKWARDS) {
                t = new BackwardsTranslator;
            } else if (translatorChoice == TR_PIRATE) {
                t = new PirateTranslator;
            } else if (translatorChoice == TR_PIG_LATIN) {
                t = new SpoonerismTranslator;
            } else if (translatorChoice == TR_OLD_ENGLISH) {
                t = new OldEnglishTranslator;
            } else {
                t = new Translator;
            }
            printTranslatorOutput(t, message, isUntranslate);
        }
    }
}

// Prints translation/untranslation (specifying the language) given a translator and a message
void printTranslatorOutput(Translator* t, std::string& message, bool isUntranslate) {
    std::string output = isUntranslate ? t->untranslate(message) : t->translate(message);
    std::cout << t->getLanguage() << " says: \"" << output << "\"" << std::endl;
}

// Gets numeric value from user
int getNumberChoice() {
    std::cout << "#: ";
    std::string in;
    getline(std::cin, in);
    return in[0] - '0';
}
