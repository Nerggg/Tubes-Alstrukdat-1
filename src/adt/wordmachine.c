#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
	while (currentChar == BLANK) {
		ADV();
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
