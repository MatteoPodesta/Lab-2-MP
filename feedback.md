* inline functions do not adhere to the best practices -10
* missing Creature::toString() -5
* const; if it is not 1 or 0 make it const; in case of ASCII values, use chars, e.g., temp>’a’  -5
* excessive use of printf/cout/cin/ file stream/stringstream and/or endl and/or << >>; applies to all output, not just menu-5
```
//e.g.
cout << "\n\nMenu:\n”
“1. Encrypt\n”
“2. Decrypt\n”
“3. Quit\n"<<endl;
```
* << not needed between strings
* put ‘\n’ is at the end of the previous whenever possible  
* Should print a couple of blank lines before the menu to separate from the lines of text above it
* no need for the “.” at the end of menu options; it is just clutter but no useful info to a user* no need for the “.” at the end of menu options; it is just clutter but no useful info to a user
 	* input>>name>>id>gpal;* 
* text entries should be left aligned, and numerical entries should be right aligned with the same number of decimal places -2
* #102 cin.ignore(…); what will happen if a use enters +1  more chars than you specified? -2
* file name(s) and/or file/folder structure/capitalization do not comply with posted instructions; -2
* readability, comments; do not state the obvious, remove outdated code; comments supposed to help and not create unnecessary clutter; "Code never lies, comments sometimes do." - Ron Jeffries”; what is the purpose of the comments as this(ese) one(s);  -2
```
//Creature Class
class Creature
```
* #59-70 ; ??? -2
* #182-226 ???

