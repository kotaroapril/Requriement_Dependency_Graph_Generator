## Assignement #4 - Requirement Dependency Generator (Implementation process)

## Module Purpose

### dependency_map ###
       - Implements the data structure and functions for storing and managing the requirement dependencies using linked lists
       - Each requirement, with unique reqID, is stored as a node, with linked lists for its parent/s and children.
       - Key Functions:
              `create_map_dependency()` - Allocates and initializes an empty map.
              `find_reqID()` – Searches for a requirement node by its ID.
              `add_reqID()` – Adds a new requirement node to the map.
              `add_parent()` – Adds a parent relationship to a requirement.
              `add_child()` – Adds a child relationship to a requirement.
              `is_map_dependency_empty()` – Checks if the map is empty.
              `free_map_dependency()` – Frees all memory used by the map and its nodes.
              `print_map_dependency()` – Prints the contents of the map for debugging.

### parse ###
       - Reads the input file, extracts requirement tags and dependencies, and adds them in the dependency map
       - Key Functions:
              `parse_file()` – Parses the input file, finds requirement tags, and stores them and their dependencies to the map.
              `is_req_tag()` – Checks if a string matches the requirement tag format.

### io ###
       - Handles file input and output operations, such as prompting for the input file name and creating the report file.
       - Key Functions:
              `user_input()` – Prompts the user for the input file name and validates it.
              `create_output_file()` – Opens the output report file for writing.

### draw_diagram ###
       - Formats and writes the final dependency graph to the output file.
       - Prints the first three lines of the input file and all requirement relationships in the required format.
       - Key Functions:
              `draw_diagram()` – Writes the formatted dependency graph to the output file.

### main ###
       - Coordinates the overall program flow: gets user input, parses the file, generates the report, and frees resources.
       - Key Functions: -
              `main()` – Entry point; calls io, parsing and report generation, and frees resources.

## How to build
       - Open a terminal in the project root and run:
              make
       - This will create `rdgg-57045714.exe` in the root folder.

## How to run
       - Simply run the program `rdgg-57045714.exe` and enter the file name when prompted.

## OUTPUT
       - The program generates a report file named `rdgg-report-57045714.md` in the root folder.
       - The report contains the first three lines of the input file and the requirement dependency graph in the required format.

--

## NOTES

**AI Usage**
       - Explained string manipulation techniques for extracting requirement tags and dependencies from each line, including how to use strstr, strtok, and sscanf.
       - Helped understand how sscanf works to extract the requirement tag from the line. Gave an example.
       - Helped improve my comments in the code, made it more concised and accurately describe what certain function does.
       - Suggested to have find_reqID in dependency_map.c. I initially just have if the is_***_added, which only returns 1 or 0 if the the ID already exists in the map/list. I needed a function that returns the actual location of reqID for adding a child/parent. I added find_parentID and find_childID just in case.

** Changes after HW3 **
        - Deleted seen_set and sort_dependencies: In my mind we were to draw the dependency tree of each modules and will be scanning all source/header files.
       - Added io module for user input.
---

## Assignment #3 - Stub process 

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
 - parse_file will extract all req_ID and its dependencies
 - Once all req_ID's have been processed, using sort_dependencies, arrange all req_ID in topological order
 - Print our dependency tree using draw_diagram

 *Made a Flow Chart before started making the skeleton file during Lab session (5-13-25). 
*Original plan:      Use BFS with queue for trackikng which req_ID's still need to process.
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
