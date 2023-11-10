#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
	while (currentChar == BLANK || currentChar == '\n') {
		ADV();
	}
}

void STARTWITHBLANK()
{
    START();
    IgnoreBlanks();

    int i=0;
    while((currentChar != MARK)){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
    // if(i > NMax){
    //     currentWord.Length = NMax;
    // }

}

void STARTSENTENCE() {
	START();
	if (currentChar == MARK) {
		EndWord = true;
	}
	else {
		EndWord = false;
		CopySentence();
	}
}

void STARTWORD() {
	START();
	IgnoreBlanks();
	if (currentChar == MARK) {
		EndWord = true;
	}
	else {
		EndWord = false;
		CopyWord();
	}
}

void ADVWORD() {
	IgnoreBlanks();
	if (currentChar == MARK) {
		EndWord = true;
	}
	else {
		CopyWord();
		IgnoreBlanks();
	}
}

void CopyWord() {
	int i = 0;
	while (currentChar != MARK && i < NMax && currentChar!= BLANK) {
		currentWord.TabWord[i] = currentChar;
		i++;
		ADV();
	}

	currentWord.Length = i;
}

void CopySentence() {
	int i = 0;
	while (currentChar != MARK && i < NMax) {
		if (currentChar == '\n') {
			ADV();
			continue;
		}
		currentWord.TabWord[i] = currentChar;
		i++;
		ADV();
	}

	currentWord.Length = i;
}
