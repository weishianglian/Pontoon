# Pontoon

## Introduction
The card game: Pontoon is played between a bank and a player with a deck of cards composed of the 4 suits and 13 faces. According to the rule of this game and the requirements from the specification, I created the 8 classes based on object-oriented design programming, representing the essential components of this game as follows:
* Card: This class represents the face and value of a playing card.
  * SuitCard: It's a derived class of Card for implementing polymorphism and represents the suit of a playing card.
* Deck: This class contains a vector loading 52 playing cards and the relational operations.
* Hand: It's a base class representing the playing cards held on the Bank and the Player in the game. Moreover, it is an abstract class and has a virtual function called "deal" needed to override.
  * Bank: It's is a derived class of Hand and implements the virtual function "deal" for dealing action in the game.
  * Player: It's is a derived class of Bank and overrides the function of printing the playing cards held on the hand.
* Log: This class contains all necessary functions to record the results of each game into a text file.
* Game: Game is a class containing the flow and logic of the Pontoon and is the main element combining the above classes.

## Implementation
### The algorithm of shuffling the playing cards:
At first, I used the STL Library function called "shuffle", which is from the head file "algorithm" and rearranges the elements in the range randomly, to do the action of shuffling. However, I found an algorithm to implement shuffling without using STL Library. This algorithm is Fisher- Yates shuffle[1] generating a random permutation of a finite sequence. It will explain how the shuffling actually works as following:
1. Select the last item from the sequence.
2. Pick another item preceding the selected item (include itself) randomly.
3. Swap the contents of two selected items.
4. Select the new item before the previously selected item.
5. Repeat the step 2 to 4 up to the first item.

### The function of swapping:
Furthermore, I created a function called "swapRef" for swapping the positions by their reference between two items in the sequence, and it uses the template to provide the feature of parameterised types which means it can work for any type in specifically sequentially containers such as array or vector.

### The function of swapping:
Furthermore, I created a function called "swapRef" for swapping the positions by their reference between two items in the sequence, and it uses the template to provide the feature of parameterised types which means it can work for any type in specifically sequentially containers such as array or vector.

### The use of inheritance and polymorphism:
I practised the inheritance in two parts of my programs which are Card and Hand, and their derived class are SuitCard, and Bank and Player. Card defines the face and the value of a playing card and SuitCard defines the suit of a playing card. Further, SuitCard overrides the function called "printCard" from only showing the face to showing the face with the suit by a vector contains the pointer of Card class. Moreover, Hand handles all basic functional operations but remains an abstract function waiting for implementation, called "deal", to its derived class Bank. Bank practices "deal" by getting the top of a card from a deck and putting it into the hand. Further, Player just rewrite the function called "printHand" for displaying the information about the cards on the hand.

### The handling of exception:
I handled the exception in the program of Log due to the risk of handling IO exceptions. So I use the keyword: "try" and "catch" to dealing any failure from exporting contents based on using STL Library "ostream". In the block of "catch" code, I used error output: "cerr" to show the failure message.

### The handling of exception:
I handled the exception in the program of Log due to the risk of handling IO exceptions. So I use the keyword: "try" and "catch" to dealing any failure from exporting contents based on using STL Library "ostream". In the block of "catch" code, I used error output: "cerr" to show the failure message.

## Pontoon UML Class Diagram
![Pontoon UML Class Diagram](images/PontoonUML.png)


## Programming Compile and Environment
* The source files:
  * Card.h
  * Card.cpp
  * SuitCard.h
  * SuitCard.cpp
  * Deck.h
  * Deck.cpp
  * Hand.h
  * Hand.cpp
  * Bank.h
  * Bank.cpp
  * Player.h
  * Player.cpp
  * Game.h
  * Game.cpp
  * Log.h
  * Log.cpp
  * PlayGame.cpp

* The executable file:
  * ./PlayGame

* How to configure my programs:
  * They can be compiled by typing command "make" at the same folder on the terminal, and the command will use the makefile to configure my programs.
  * There is another way to compile my programs by entering command following:
    * g++ -std=c++14 -o PlayGame Card.cpp SuitCard.cpp Deck.cpp Hand.cpp Bank.cpp Player.cpp Log.cpp Game.cpp PlayGame.cpp

* How to run my programs:
  * When the programs are compiled, it has an executable file called "PlayGame" and you can run the program by the following command: "./PlayGame".

* The programming environment I used to create and build the program:
  * The editor of C++:
    * Sublime Text 3
  * The compiling command:
    * g++ -std=c++14 -o PlayGame Card.cpp SuitCard.cpp Deck.cpp Hand.cpp Bank.cpp Player.cpp Log.cpp Game.cpp PlayGame.cpp

  * The development enviroment:
```
                 -/+:.          
                :++++.          OS: 64bit Mac OS X 10.12.6
               /+++/.           
       .:-::- .+/:-``.::-       Kernel: x86_64 Darwin 16.7.0
    .:/++++++/::::/++++++/:`    
  .:///////////////////////:`   Shell: zsh 5.4.2
  ////////////////////////`     
 -+++++++++++++++++++++++`      CPU: Intel Core i5-4278U @ 2.60GHz
 /++++++++++++++++++++++/       
 /sssssssssssssssssssssss.      GPU: Intel Iris
 :ssssssssssssssssssssssss-     
  osssssssssssssssssssssssso/`  RAM: 8192MiB
  `syyyyyyyyyyyyyyyyyyyyyyyy+`  
   `ossssssssssssssssssssss/
     :ooooooooooooooooooo+.
      `:+oo+/:-..-:/+o+/-
```

* The C++ compiler and version you used:
  * The information by executing the command "g++ --version":
    * Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
    * Apple LLVM version 9.0.0 (clang-900.0.39.2)
    * Target: x86_64-apple-darwin16.7.0
    * Thread model: posix
    * InstalledDir: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin


