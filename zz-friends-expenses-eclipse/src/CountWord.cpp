/*
 * CountWord.cpp
 *
 *  Created on: 20 mars 2014
 *      Author: ubuntu
 */

#include "CountWord.hpp"


CountWord::CountWord(string iText) {
	_text = iText;
}

unsigned int CountWord::count() {
    unsigned int aCount = 0;
    char *aWord = 0;
    char aDelimiters[] = " :.!\"#$%&'()*+,-/;<=>?@[]\\^_`{|}~\n\t\r";
    // Cf. http://www.cplusplus.com/reference/cctype/
    // for the list of characters

    char aText[_text.length() + 1];
    strcpy(aText, _text.c_str());

    aWord = strtok(aText, aDelimiters);
    while (aWord) {
        aCount++;
        aWord = strtok(0, aDelimiters);
    }
    return aCount;
}

vector<string> CountWord::split() {
    vector<string> aWords;
    char *aWord = 0;
    char aDelimiters[] = " :.!\"#$%&'()*+,-/;<=>?@[]\\^_`{|}~\n\t\r";
    // Cf. http://www.cplusplus.com/reference/cctype/
    // for the list of characters

    char aText[_text.length() + 1];
    strcpy(aText, _text.c_str());

    aWord = strtok(aText, aDelimiters);
    while (aWord) {
    	aWords.push_back(aWord);
        aWord = strtok(0, aDelimiters);
    }
    return aWords;
}

