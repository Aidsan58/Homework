# Instructions:
1. Unzip
1. cd into "Smart Dictionary & Spell Checker"
3. run this code: g++ src/main.cpp src/trie.cpp src/hashTable.cpp src/heap.cpp -o program.exe
4. program.exe can be run like any executable

# Description:
The hash set that I used is standard library C++. I used a set instead of a map because I only need to save one value per item. I implemented a left-child right-sibling trie for the trie data structure. The heap is straightforward, and it sorts the suggestions from the function trie when the user runs the SUGGEST command. NOTE: user commands are case sensitive.