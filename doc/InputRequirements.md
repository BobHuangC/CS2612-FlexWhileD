# InputRequirements

The input of this program should be a .l file, below is some requirements for the input file.

## Requirements

1. The .l file should only contain the second part of the .l file, which is the rules part.

2. For each rule, the syntax part (which explains the rule to process the regular expression) should starts with a  "{" and ends with a"}".

3. For each rule, if the regular expression contains a "{" or a "}", it should be escaped by a "\".

4. For each rule, the length of the syntax should be less than 1000 characters.

5. The syntax shouldn't be empty.