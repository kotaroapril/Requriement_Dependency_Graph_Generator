MODULES PURPOSE:
SEEN_SET
 - Keeps track of which files have already been visited, so the program doesn’t process the same file more than once. Will be done recursively.

DEPENDENCY_MAP
 - Stores the relationship between a file and its dependencies. Mapping which files depend on which files.

 PARSE
 - Reads files and extract dependencies filename then add it to dependency_map and/or seen_set

SORT_DEPENDENCY
 - Sorts the map in topological order

DRAW_DIAGRAM
 - Prints out the final output which the dependency tree. Will make easier to follow which file depends on which file.


 THE PROCESS/IN MAIN:
 - Create hashmap and seen_set 
 - Ask user for root file, if input invalid or file is empty loop back to as for a filename
 - Process the file by calling parse_file function
 - Once all files have been processed, using sort_dependencies, arrange all files in topological order
 - Print our dependency tree using draw_diagram

 *Made a Flow Chart before started making the skeleton file during Lab session (5-13-25). 
*Original plan:      Use BFS with queue for trackikng which files still need to process/parse.
                     Changed to DFS with stack
                     From stack to recursion for backtracking.              
*Still figuring out topological sort and printing out diagram.

AI Usage (CoPilot and ChatGPT)
 - Which is better for traversing to make the dependency tree, DFS or BFS? 
        - DFS will be used in the program.
 - Is it better to use a stack for the program for tracking seen files or is there a way to backtrack?
        - Use of recursion for backtracking with proper topological sort algorithm. Simpler, less code.
        - With stack, more code and more complex.
        - No need for stack, will do recursively.
 - 
