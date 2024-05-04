/*this program illustrates how a string can be processed
as an array of individual characters.  It reads a string and counts the number
of voweles in the string.  It then usesteh toupper function to uppercase each
letter in the stirng*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
using namespace std;

int main()
{
   char ch;
   int vowelCount = 0;
   string sentence;

   cout << "Enter a sentence: ";
   getline(cin, sentence);

   //notice that string.lengh() determines the number of chars in the string
   for(int pos = 0; pos < sentence.length(); pos ++)
   {
      //make the character in the string uppercase to process vowel switch below
      ch = toupper(sentence[pos]);
      //if the char is a vowel increment vowelcount
      switch(ch)
      {
         case 'A':
         case 'E':
         case 'I':
         case 'O':
         case 'U': vowelCount++;
      }
   }
   cout << "There are " << vowelCount << " vowels in the sentence." << endl;
   system("PAUSE");
   return 0;
}
