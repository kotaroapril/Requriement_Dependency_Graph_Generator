# Requirement Dependency Generator

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
       - Key Functions:
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

## NOTES

### AI Usage ###
       - Explained string manipulation techniques for extracting requirement tags and dependencies from each line, including how to use strstr, strtok, and sscanf.
       - Helped understand how sscanf works to extract the requirement tag from the line. Gave an example.
       - Helped improve my comments in the code, made it more concised and accurately describe what certain function does.
       - Suggested to have find_reqID in dependency_map.c. I initially just have if the is_***_added, which only returns 1 or 0 if the the ID already exists in the map/list. I needed a function that returns the actual location of reqID for adding a child/parent. I added find_parentID and find_childID just in case.
