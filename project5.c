#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ConvertStringToUppercase(char *pText);
void AnalyzeText(const char *pText);
void PrintStringInMorseCode(const char *pText);
void PrintAsciiCharCodeInBinary(char ch);
void PrintStringInAsciiBinary(const char *pText);

const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char digits[] = "0123456789";

int main() 
{
    char pText [300];

    printf("Please enter a message: \n");
    gets(pText);

    ConvertStringToUppercase(pText);
    printf("Your message in uppercase is: \n");
    printf("%s", pText);
    AnalyzeText(pText);
    PrintStringInMorseCode(pText);
    PrintStringInAsciiBinary(pText);

} //End main function

void ConvertStringToUppercase(char *pText)
{
    if ((pText == NULL) || (strlen(pText) == 0)) {
        return;
    }
    else {
        for(int i = 0; i < strlen(pText); i++) {
            if (islower(pText[i])) {
                pText[i] = toupper(pText[i]);
            }
        }
    }
}

void AnalyzeText(const char *pText)
{
    int spaceCount = 0; //count of spaces in string
    int letterCounts[26] = {0}; //count of each letter
    int digitCount[10] = {0};   //count of individual numeric character
    int otherCount = 0;     //count of other characters which are non of the above

    if(pText == NULL) {
        printf("Error: ");
        return;
    }

    for(int i = 0; i < strlen(pText); i++) {
        if(isalpha(pText[i])) {
            //figure out what letter it is and increment the count 
            for(int index = 0; index < 26; index++) {
                if(alphabet[index] == pText[i]) {
                    letterCounts[index]++;
                }
            }
        }
        else if(isdigit(pText[i])) {
            //figure out what digit it is and increment the corresponding count
            for(int index = 0; index < 10; index++) {
                if(digits[index] == pText[i]) {
                    digitCount[index]++;
                }
            }
        }
        else if(isspace(pText[i])) {
            spaceCount++;
        }
        else {
            otherCount++;
        }
    }
    printf("\n\nText Analysis:\n--------------------\n");
    if(spaceCount > 0) {
        printf("Number of spaces:             %i \n", spaceCount);
    }
    if(otherCount > 0) {
        printf("Number of special characters: %i \n", otherCount);
    }
    printf("Letter Usage:\n");
    for(int j = 0; j < (sizeof(letterCounts)/sizeof(letterCounts[0])); j++) {
        if(letterCounts[j] > 0) {
            printf("%c    %i\n", alphabet[j], letterCounts[j]);
        }
    }
    printf("Digit Usage:\n");
    for(int j = 0; j < (sizeof(digitCount)/sizeof(digitCount[0])); j++) {
        if(digitCount[j] > 0) {
            printf("%c    %i\n", digits[j], digitCount[j]);
        }
    }
    printf("\n");
}

void PrintStringInMorseCode(const char *pText)
{
    //This function coverts the user input message into Morse code
    const char *morseLetters[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                            ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                            "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."}; 
    const char *morseDigits[] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...",
                            "---..", "----."};
    if(pText == NULL) {
        printf("Error");
        return;
    }
    printf("\nYoure message in Morse code is:\n");
    for(int i = 0; i < strlen(pText); i++) {
        if(isalpha(pText[i])) {
            //figure out what letter it is and increment the count 
            for(int index = 0; index < 26; index++) {
                if(alphabet[index] == pText[i]) {
                    printf("%s ", morseLetters[index]);
                }
            }
        }
        else if(isdigit(pText[i])) {
            //figure out what digit it is and increment the corresponding count
            for(int index = 0; index < 10; index++) {
                if(digits[index] == pText[i]) {
                     printf("%s ", morseDigits[index]);
                }
            }
        }
        else if(isspace(pText[i])) {
            printf("  ");
        }
    }
    printf("\n\n");
}

// Instructor-supplied function which prints the seven-digit binary equivalent
// of the ASCII value of a specified character.
void PrintAsciiCharCodeInBinary(char ch)
{
	char outputTemplate[] = "0000000";
	unsigned digits = strlen(outputTemplate);

	for (int index = digits - 1; index >= 0; index--)
	{
		if (ch % 2)			// Get the remainder, to see if we have a 1 bit.
		{
			outputTemplate[index] = '1';		// Set the output for this bit to 1.
		}

		ch /= 2;			// Prepare for next digit.
	}

	printf("%s ", outputTemplate);		// display the sequence of binary digits.
}
// End of instructor-supplied function.

void PrintStringInAsciiBinary(const char *pText)
{
    //This function converts the user input message into ASCII binary
    if(pText == NULL) {
        printf("Error");
        return;
    }
    printf("Your message in binary is:\n");
    for(int i = 0; i < strlen(pText); i++) {
        PrintAsciiCharCodeInBinary(pText[i]);
    }
    printf("\n");   
}