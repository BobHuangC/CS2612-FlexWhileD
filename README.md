<div id="top"></div>

<!-- ABOUT THE PROJECT -->
# Flex specified for WhileDeref

Using Flex, this project designs a lexical rule containing a regular expression and WhileDeref program, performs lexical analysis, syntax analysis and syntax tree output for the lexical rule, and generates NFA and DFA from the regular expression.

The preprocessors are placed in the folder PreProcess;
The programs for lexical analysis and syntax analysis of the lexical rule are in the folder LangAnalysis;
The programs for generating NFA and DFA are in the folder NFADFA.

In addition, the folder examples contains 6 test examples. The first one `examples/input_file.l` is the most representative one, which includes many extreme cases you might want to test.

## Installation

   Clone the repo
   ```sh
   git clone https://github.com/BobHuangC/PL_project.git
   ```

   
<p align="right">(<a href="#top">back to top</a>)</p> 

## Test

<!-- input module usage:    
```sh
./input examples/input_file.l
```

Test the LanguageAnalyzer usage:    
```sh
cd LangAnalysis
make
./LAtest2
``` -->


GeneralAnalyzer usage:    
```sh
make
./bin/flexWhileD examples/input_file.l
```

Then the output will be in the file "examples/input_file.l-result.txt".

<p align="right">(<a href="#top">back to top</a>)</p>


The requirements for the input file are listed in the `doc/InputRequirements.md` file.

## Contact

Please feel free to open an issue or contact us personally if you have questions, need help, or need explanations. Write to one of the following email addresses, and maybe put one other in the cc:

huang2003bo@sjtu.edu.cn

railgun18@sjtu.edu.cn

<p align="right">(<a href="#top">back to top</a>)</p>


