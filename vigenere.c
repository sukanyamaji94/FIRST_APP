/*****Please include following header files*****/
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
/***********************************************/

int Mod(int a, int b)
{
	return (a % b + b) % b;
}

char* Cipher(char* input, char* key, bool encipher)
{
	int keyLen = strlen(key);
int i;
	for (i = 0; i < keyLen; ++i)
		if (!isalpha(key[i]))
			return ""; // Error

	int inputLen = strlen(input);
	char* output = (char*)malloc(inputLen + 1);
	int nonAlphaCharCount = 0;

	for (i= 0; i < inputLen; ++i)
	{
		if (isalpha(input[i]))
		{
			bool cIsUpper = isupper(input[i]);
			char offset = cIsUpper ? 'A' : 'a';
			int keyIndex = (i - nonAlphaCharCount) % keyLen;
			int k = (cIsUpper ? toupper(key[keyIndex]) : tolower(key[keyIndex])) - offset;
			k = encipher ? k : -k;
			char ch = (char)((Mod(((input[i] + k) - offset), 26)) + offset);
			output[i] = ch;
		}
		else
		{
			output[i] = input[i];
			++nonAlphaCharCount;
		}
	}

	output[inputLen] = '\0';
	return output;
}

char* Encipher(char* input, char* key)
{
	return Cipher(input, key, true);
}

char* Decipher(char* input, char* key)
{
	return Cipher(input, key, false);
}
int main(){
char* text = "honesty is the best";
char* cipherText = Encipher(text, "centre");
char* plainText = Decipher(cipherText, "centre");
printf("\n\t..............Vigenere cipher Encryption & Decryption............\n");
printf("\n\tEnter plain text:%s",plainText);
printf("\n\n\tEncrypted text is %s",cipherText);
printf("\n\n\tDecrypted text is %s\n\n",plainText);

return 0;
}
