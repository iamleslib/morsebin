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