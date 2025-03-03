#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <fstream>
using namespace std;

//Creature Class

class Creature {

public:
    //accessor functions that return variables
    //all of them get returned as strings
    //instructions mention ID needing to be a string
    string getStrenght() const { return to_string(strength); }
    string getHealth() const { return to_string(health); }
    string getID() const { return id; }
    //(rand() % strength) + 1 for damage as stated in the instructions
    string getDamage() { return to_string((rand() % strength) + 1); }
    //mutator function to set ALL member variables
    void setCreature(int newStrenght, int newHealth, string newId) { strength = newStrenght;  health = newHealth; id = newId; }

private:
    string id = "placeholder";
    int strength = 50;
    int health = 75;
};

//print the list of creatures
void printCreatureStats(Creature list[10]);
//update the list of creatures
void updateCreatureArray(Creature list[10]);
//print the damage for all the creatures, along with other stats on a table with heading
void printCreatureFeaturesTable(Creature list[10]);

int main()
{
    
    //file reading stuff
    ifstream infile;
    infile.open("creatureNameList.dat");
    if (!infile) {
        cout << "Cannot open file" << endl;
        exit(EXIT_FAILURE);
    }

    //setting the seed of the rand() function
    srand(time(0));

    //array of creatures
    Creature creatureList[10];

    //switch statement for the menu
    
    //variable for the switch statement
    int optionChosen = 0;

    //4 options
    //1 - print the list of creatures with health id and strenght
    //2 - update the list of creatures
    //3 - print the damage for all the creatures, along with other stats on a table with heading
    //4 - exit
    
    //seperated by chunk for organization
    cout << "Notice:\n- Make sure your list of names in 'creatureNameList.dat' consists of 10 names.";
    cout << "\n ~ Any name after 10 will not be imported.";
    cout << "\n ~ Any missing name from a list of size less than 10 will be marked as 'placeholder'.";
    cout << "\n- By default, Strength is set to 50, Health is set to 75, and Name will be set to 'placeholder.";
    cout << "\n- Any change you make to 'creatureNameList.dat' while the program is running will not appear unless you Re-Assign names with option 2.";

    
    cout << "\n\nPlease type in a number corresponding to one of the listed funcions below:\n";
    
    cout << "   1: Print your list of Creatures, along with their health, and strength onto an array.\n";
    cout << "   2: Assign Names (from your input file), Strenght (randomly set between 50 and 200), and Health (Randomly set between 75 and 250).\n";
    cout << "   3: Print your list of Creatures, along with their damage, health, and strength onto an array.\n";
    cout << "   4: Exit the program.\n\n";

    while (optionChosen != 4) {
        //to ensure that it loops and wont have to be restarted after every single selection
        cout << "Input: ";
        cin >> optionChosen;

        //the switch statement itself
        switch (optionChosen) {
        case 1:
            printCreatureStats(creatureList);
            break;
        case 2:
            updateCreatureArray(creatureList);
            break;
        case 3:
            printCreatureFeaturesTable(creatureList);
            break;
        case 4:
            break;
        default:
            //this is to make sure that incase they put the wrong number, nothing, or a string, the program can properly function 

            cin.clear();
            cin.ignore(265, '\n');
            cout << "Invalid option, please input a valid option.\n";
            break;
        }

    }
   


}

//print the list of creatures
void printCreatureStats(Creature list[10]) {
    //this cout is outside of the loop so that it only prints once per funciton call
    //seperated cout statements by row for organization purposes
    cout << setfill('~') << setw(26) << right << "Array of Creatures" << setfill('~') << setw(11) << "" << endl;
    cout << setfill(' ') << setw(15) << left << "|Name" << setw(13) << left << "Health" << right << "Strenght|" << endl;
    cout << "+" << setw(36) << setfill('-') << "+" << endl;
    
    //prints each row of creature stats
    for (int i = 0; i < 10; i++) {

        cout << "|" << setfill(' ') << setw(15) << left << list[i].getID() << setw(15) << left << list[i].getHealth() << setw(5) << left << list[i].getStrenght() << "|" << endl;

    }
    
    
}
//update the list of creatures
    //set health between 75 and 250 randomly
    //set strength between 50 and 200 randomly
    //assign id
void updateCreatureArray(Creature list[10]) {
    //so that the infile can be put as a variable in a function
    string tempID;

    //re-opens and re-reads the file, allowing changes to be made to the name, 
    //and fixing a bug where after running the function once, the names vanished from the list
    ifstream infile;
    infile.open("creatureNameList.dat");
    if (!infile) {
        cout << "Cannot open file" << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 10; i++) {
        
        
        infile >> tempID;
        
        if (tempID == "") {

            tempID = "placeholder";

        }

        //setCreature(strength, health, ID)
        list[i].setCreature((rand() % 176) + 75, (rand() % 151) + 50, tempID);

    }
    

}
//print the damage for all the creatures, along with other stats on a table with heading
//essentially is the printCreatureStats function but with damage included
void printCreatureFeaturesTable(Creature list[10]) {
    //this cout is outside of the loop so that it only prints once per funciton call
    //seperated cout statements by row for organization purposes
    cout << setfill('~') << setw(34) << right << "Array of Creatures" << setfill('~') << setw(18) << "" << endl;
    cout << setfill(' ') << setw(15) << left << "|Damage" << setw(15) << left << "Name" << setw(13) << left << "Health" << right << "Strenght|" << endl;
    cout << "+" << setw(51) << setfill('-') << "+" << endl;

    for (int i = 0; i < 10; i++) {

        cout << "|" << setfill(' ') << setw(14) << left << list[i].getDamage() << setw(16) << left << list[i].getID() << setw(15) << left << list[i].getHealth() << setw(5) << left << list[i].getStrenght() << "|" << endl;

    }

}

/*
- Creature class
    - creature class manages one creature only

    - member variables to store
        - strength (a measure of how physically strong a character is)
        - health (determines the maximum amount of damage that a character or object can take; sometimes referred to as hit points )
        - id
        - always initialize member variables at the time of definition
    
    - mutator function to
        - write setCreature function to set all member variables
    
    - accessor functions to return
        - health
        - strength
        - id
        - damage (all creatures inflict damage, which is a random number up to their strength damage = (rand( ) % strength) + 1;
    
    - accessor function to return a creature object as a string ( to_String()), for example, " Centaur      10      87"
*/
/*
 - main()
    - an array of creatures
    - a menu  with the following options
        - print  the array of creatures (id,  health, and strength) as a table with headings
        - update the array of creatures by setting health, strength, and id
            - set health between 75 and 250 randomly
            - set strength between 50 and 200 randomly
            - assign id -  create a file with creature names and use it to set ids
        - print damage for all creatures along with their ids, health, and strength as a table with headings
        - exit
*/
/*
    - no dynamic memory allocation
    - no vectors
    - use const where appropriate
    - main() should be well-modularized
    - use enum and switch to implement the menu; generally speaking, enum class is preferred but for now enum should suffice for now
    - printing creature list in a table format with headings, right align numeral values; use to_String() member function to print individual creature
*/



/*
Test run 1 - Empty CreatureNameList:
Notice:
- Make sure your list of names in 'creatureNameList.dat' consists of 10 names.
 ~ Any name after 10 will not be imported.
 ~ Any missing name from a list of size less than 10 will be marked as 'placeholder'.
- By default, Strength is set to 50, Health is set to 75, and Name will be set to 'placeholder.
- Any change you make to 'creatureNameList.dat' while the program is running will not appear unless you Re-Assign names with option 2.

Please type in a number corresponding to one of the listed funcions below:
   1: Print your list of Creatures, along with their health, and strength onto an array.
   2: Assign Names (from your input file), Strenght (randomly set between 50 and 200), and Health (Randomly set between 75 and 250).
   3: Print your list of Creatures, along with their damage, health, and strength onto an array.
   4: Exit the program.

Input: 1
~~~~~~~~Array of Creatures~~~~~~~~~~~
|Name          Health       Strenght|
+-----------------------------------+
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
Input: 3
~~~~~~~~~~~~~~~~Array of Creatures~~~~~~~~~~~~~~~~~~
|Damage        Name           Health       Strenght|
+--------------------------------------------------+
|40            placeholder     75             50   |
|38            placeholder     75             50   |
|21            placeholder     75             50   |
|37            placeholder     75             50   |
|29            placeholder     75             50   |
|6             placeholder     75             50   |
|26            placeholder     75             50   |
|19            placeholder     75             50   |
|20            placeholder     75             50   |
|16            placeholder     75             50   |
Input: 2
Input: 1
~~~~~~~~Array of Creatures~~~~~~~~~~~
|Name          Health       Strenght|
+-----------------------------------+
|placeholder    173            112  |
|placeholder    106            155  |
|placeholder    99             240  |
|placeholder    162            158  |
|placeholder    127            143  |
|placeholder    147            195  |
|placeholder    51             169  |
|placeholder    173            120  |
|placeholder    135            92   |
|placeholder    152            172  |
Input: 3
~~~~~~~~~~~~~~~~Array of Creatures~~~~~~~~~~~~~~~~~~
|Damage        Name           Health       Strenght|
+--------------------------------------------------+
|25            placeholder     173            112  |
|90            placeholder     106            155  |
|138           placeholder     99             240  |
|97            placeholder     162            158  |
|36            placeholder     127            143  |
|187           placeholder     147            195  |
|56            placeholder     51             169  |
|86            placeholder     173            120  |
|3             placeholder     135            92   |
|131           placeholder     152            172  |
Input: 4

C:\Users\Matteo\source\repos\Creature Class S25\x64\Debug\Creature Class S25.exe (process 21968) exited with code 0.
Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------

Test Run 2 - Incomplete (less than 10 names) CreatureNameList(tom sam tom frank):
Notice:
- Make sure your list of names in 'creatureNameList.dat' consists of 10 names.
 ~ Any name after 10 will not be imported.
 ~ Any missing name from a list of size less than 10 will be marked as 'placeholder'.
- By default, Strength is set to 50, Health is set to 75, and Name will be set to 'placeholder.
- Any change you make to 'creatureNameList.dat' while the program is running will not appear unless you Re-Assign names with option 2.

Please type in a number corresponding to one of the listed funcions below:
   1: Print your list of Creatures, along with their health, and strength onto an array.
   2: Assign Names (from your input file), Strenght (randomly set between 50 and 200), and Health (Randomly set between 75 and 250).
   3: Print your list of Creatures, along with their damage, health, and strength onto an array.
   4: Exit the program.

Input: 1
~~~~~~~~Array of Creatures~~~~~~~~~~~
|Name          Health       Strenght|
+-----------------------------------+
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
Input: 2
Input: 1
~~~~~~~~Array of Creatures~~~~~~~~~~~
|Name          Health       Strenght|
+-----------------------------------+
|tom            113            169  |
|sam            152            122  |
|tom            99             196  |
|frank          151            190  |
|frank          136            110  |
|frank          58             161  |
|frank          189            232  |
|frank          101            108  |
|frank          176            123  |
|frank          198            156  |
Input: 3
~~~~~~~~~~~~~~~~Array of Creatures~~~~~~~~~~~~~~~~~~
|Damage        Name           Health       Strenght|
+--------------------------------------------------+
|38            tom             113            169  |
|103           sam             152            122  |
|159           tom             99             196  |
|136           frank           151            190  |
|107           frank           136            110  |
|87            frank           58             161  |
|111           frank           189            232  |
|55            frank           101            108  |
|61            frank           176            123  |
|98            frank           198            156  |
Input: 4

C:\Users\Matteo\source\repos\Creature Class S25\x64\Debug\Creature Class S25.exe (process 9368) exited with code 0.
Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------

Test Run 3 - overflowing (greater than 10 names) CreatureNameList(tom sam tom frank poppy gosh ricky track eden tok ranch delly):
Notice:
- Make sure your list of names in 'creatureNameList.dat' consists of 10 names.
 ~ Any name after 10 will not be imported.
 ~ Any missing name from a list of size less than 10 will be marked as 'placeholder'.
- By default, Strength is set to 50, Health is set to 75, and Name will be set to 'placeholder.
- Any change you make to 'creatureNameList.dat' while the program is running will not appear unless you Re-Assign names with option 2.

Please type in a number corresponding to one of the listed funcions below:
   1: Print your list of Creatures, along with their health, and strength onto an array.
   2: Assign Names (from your input file), Strenght (randomly set between 50 and 200), and Health (Randomly set between 75 and 250).
   3: Print your list of Creatures, along with their damage, health, and strength onto an array.
   4: Exit the program.

Input: 1
~~~~~~~~Array of Creatures~~~~~~~~~~~
|Name          Health       Strenght|
+-----------------------------------+
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
Input: 2
Input: 1
~~~~~~~~Array of Creatures~~~~~~~~~~~
|Name          Health       Strenght|
+-----------------------------------+
|tom            118            167  |
|sam            61             202  |
|tom            68             236  |
|frank          74             226  |
|poppy          200            224  |
|gosh           198            77   |
|ricky          98             147  |
|track          188            144  |
|eden           196            142  |
|tok            140            147  |
Input: 3
~~~~~~~~~~~~~~~~Array of Creatures~~~~~~~~~~~~~~~~~~
|Damage        Name           Health       Strenght|
+--------------------------------------------------+
|146           tom             118            167  |
|185           sam             61             202  |
|5             tom             68             236  |
|141           frank           74             226  |
|65            poppy           200            224  |
|24            gosh            198            77   |
|17            ricky           98             147  |
|134           track           188            144  |
|17            eden            196            142  |
|6             tok             140            147  |
Input: 4

C:\Users\Matteo\source\repos\Creature Class S25\x64\Debug\Creature Class S25.exe (process 18560) exited with code 0.
Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------

Test Run 4 - CreatureNameList with ecactly 10 names (tom frank poppy gosh ricky track eden tok ranch delly):
Notice:
- Make sure your list of names in 'creatureNameList.dat' consists of 10 names.
 ~ Any name after 10 will not be imported.
 ~ Any missing name from a list of size less than 10 will be marked as 'placeholder'.
- By default, Strength is set to 50, Health is set to 75, and Name will be set to 'placeholder.
- Any change you make to 'creatureNameList.dat' while the program is running will not appear unless you Re-Assign names with option 2.

Please type in a number corresponding to one of the listed funcions below:
   1: Print your list of Creatures, along with their health, and strength onto an array.
   2: Assign Names (from your input file), Strenght (randomly set between 50 and 200), and Health (Randomly set between 75 and 250).
   3: Print your list of Creatures, along with their damage, health, and strength onto an array.
   4: Exit the program.

Input: 2
Input: 3
~~~~~~~~~~~~~~~~Array of Creatures~~~~~~~~~~~~~~~~~~
|Damage        Name           Health       Strenght|
+--------------------------------------------------+
|101           tom             100            174  |
|31            frank           105            78   |
|63            poppy           167            246  |
|58            gosh            105            97   |
|126           ricky           51             190  |
|150           track           166            213  |
|36            eden            117            173  |
|32            tok             161            174  |
|136           ranch           190            145  |
|94            delly           103            217  |
Input: 1
~~~~~~~~Array of Creatures~~~~~~~~~~~
|Name          Health       Strenght|
+-----------------------------------+
|tom            100            174  |
|frank          105            78   |
|poppy          167            246  |
|gosh           105            97   |
|ricky          51             190  |
|track          166            213  |
|eden           117            173  |
|tok            161            174  |
|ranch          190            145  |
|delly          103            217  |
Input: 4

C:\Users\Matteo\source\repos\Creature Class S25\x64\Debug\Creature Class S25.exe (process 20416) exited with code 0.
Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------

Test Run 5 - CreatureNameList with ecactly 10 names, but numbers for some names (tom frank poppy 100 ricky track 759 tok ranch 10):
Notice:
- Make sure your list of names in 'creatureNameList.dat' consists of 10 names.
 ~ Any name after 10 will not be imported.
 ~ Any missing name from a list of size less than 10 will be marked as 'placeholder'.
- By default, Strength is set to 50, Health is set to 75, and Name will be set to 'placeholder.
- Any change you make to 'creatureNameList.dat' while the program is running will not appear unless you Re-Assign names with option 2.

Please type in a number corresponding to one of the listed funcions below:
   1: Print your list of Creatures, along with their health, and strength onto an array.
   2: Assign Names (from your input file), Strenght (randomly set between 50 and 200), and Health (Randomly set between 75 and 250).
   3: Print your list of Creatures, along with their damage, health, and strength onto an array.
   4: Exit the program.

Input: 1
~~~~~~~~Array of Creatures~~~~~~~~~~~
|Name          Health       Strenght|
+-----------------------------------+
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
Input: 2
Input: 3
~~~~~~~~~~~~~~~~Array of Creatures~~~~~~~~~~~~~~~~~~
|Damage        Name           Health       Strenght|
+--------------------------------------------------+
|44            tom             147            206  |
|31            frank           155            85   |
|61            poppy           134            86   |
|24            100             173            126  |
|21            ricky           188            171  |
|114           track           195            174  |
|37            759             166            102  |
|148           tok             174            246  |
|14            ranch           174            108  |
|111           10              137            205  |
Input: 1
~~~~~~~~Array of Creatures~~~~~~~~~~~
|Name          Health       Strenght|
+-----------------------------------+
|tom            147            206  |
|frank          155            85   |
|poppy          134            86   |
|100            173            126  |
|ricky          188            171  |
|track          195            174  |
|759            166            102  |
|tok            174            246  |
|ranch          174            108  |
|10             137            205  |
Input: 4

C:\Users\Matteo\source\repos\Creature Class S25\x64\Debug\Creature Class S25.exe (process 18236) exited with code 0.
Press any key to close this window . . .
--------------------------------------------------------------------------------------------------------------------

Test Run 6 - CreatureNameList with ecactly 10 names, but numbers for some names, and the list is altered mid code (tom frank poppy 100 ricky track 759 tok ranch 10) -> (sam frank poppy peter 40 track 759 tok pincer 10):
Notice:
- Make sure your list of names in 'creatureNameList.dat' consists of 10 names.
 ~ Any name after 10 will not be imported.
 ~ Any missing name from a list of size less than 10 will be marked as 'placeholder'.
- By default, Strength is set to 50, Health is set to 75, and Name will be set to 'placeholder.
- Any change you make to 'creatureNameList.dat' while the program is running will not appear unless you Re-Assign names with option 2.

Please type in a number corresponding to one of the listed funcions below:
   1: Print your list of Creatures, along with their health, and strength onto an array.
   2: Assign Names (from your input file), Strenght (randomly set between 50 and 200), and Health (Randomly set between 75 and 250).
   3: Print your list of Creatures, along with their damage, health, and strength onto an array.
   4: Exit the program.

Input: 1
~~~~~~~~Array of Creatures~~~~~~~~~~~
|Name          Health       Strenght|
+-----------------------------------+
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
|placeholder    75             50   |
Input: 2
Input: 3
~~~~~~~~~~~~~~~~Array of Creatures~~~~~~~~~~~~~~~~~~
|Damage        Name           Health       Strenght|
+--------------------------------------------------+
|135           tom             113            183  |
|138           frank           121            156  |
|79            poppy           152            206  |
|185           100             196            202  |
|94            ricky           80             221  |
|74            track           147            90   |
|105           759             177            213  |
|55            tok             176            97   |
|9             ranch           169            128  |
|128           10              158            140  |
Input: 1
~~~~~~~~Array of Creatures~~~~~~~~~~~
|Name          Health       Strenght|
+-----------------------------------+
|tom            113            183  |
|frank          121            156  |
|poppy          152            206  |
|100            196            202  |
|ricky          80             221  |
|track          147            90   |
|759            177            213  |
|tok            176            97   |
|ranch          169            128  |
|10             158            140  |
Input: 3
~~~~~~~~~~~~~~~~Array of Creatures~~~~~~~~~~~~~~~~~~
|Damage        Name           Health       Strenght|
+--------------------------------------------------+
|25            tom             113            183  |
|33            frank           121            156  |
|5             poppy           152            206  |
|118           100             196            202  |
|143           ricky           80             221  |
|4             track           147            90   |
|109           759             177            213  |
|84            tok             176            97   |
|11            ranch           169            128  |
|36            10              158            140  |
Input: 2
Input: 1
~~~~~~~~Array of Creatures~~~~~~~~~~~
|Name          Health       Strenght|
+-----------------------------------+
|tom            171            119  |
|frank          185            190  |
|poppy          166            142  |
|100            80             94   |
|ricky          185            197  |
|track          129            103  |
|759            127            117  |
|tok            80             235  |
|ranch          186            121  |
|10             148            155  |
Input: 2
//alter happens here (above i forgot to update the list before i did input 2 (updateCreatureArray) again)
Input: 1
~~~~~~~~Array of Creatures~~~~~~~~~~~
|Name          Health       Strenght|
+-----------------------------------+
|sam            106            199  |
|frank          58             122  |
|poppy          61             147  |
|peter          108            84   |
|40             76             145  |
|track          152            79   |
|759            56             202  |
|tok            125            97   |
|pincer         65             144  |
|10             114            98   |
Input: 4

C:\Users\Matteo\source\repos\Creature Class S25\x64\Debug\Creature Class S25.exe (process 15688) exited with code 0.
Press any key to close this window . . .
*/

