#include <stdio.h>
#include "lang.h"
#include "lexer.h"
#include "parser.h"
#include "string.h"
#include "analysis.h"

extern struct cmd * root;
int yyparse();

// file_name is the name of the file to be parsed
// ret is the string to be returned
// void get_abstract_syntax_tree(char* file_name, char* ret) {
//     FILE *file = fopen(file_name, "r");
//     yyin = file;
//     yyparse();
//     get_cmd(root, ret);
// }

// void file_to_string(char* file_name, char** ret) {
//     FILE *file = fopen(file_name, "r");
//     if (file == NULL) {
//         printf("Failed to open file\n");
//         return;
//     }

//     // 获取文件大小
//     fseek(file, 0, SEEK_END);
//     long file_size = ftell(file);
//     rewind(file);

//     // 分配内存
//     *ret = (char*) malloc(sizeof(char) * (file_size + 1));
//     if (*ret == NULL) {
//         printf("Failed to allocate memory\n");
//         fclose(file);
//         return;
//     }

//     // 读取文件内容
//     size_t result = fread(*ret, 1, file_size, file);
//     if (result != file_size) {
//         printf("Reading error\n");
//         free(*ret);
//         *ret = NULL;
//     } else {
//         (*ret)[file_size] = '\0';  // 添加字符串结束符
//     }

//     fclose(file);
// }


// void get_abstract_syntax_tree(char* file_name, char* ret) {


//     char* content = NULL;
//     file_to_string(file_name, &content);
//     yyin = fmemopen(content, strlen(content), "r");

//     yyparse();
//     get_cmd(root, ret);
// }


void get_abstract_syntax_tree(const char* syntax, char* ret)
{
    yy_scan_string(syntax);
    yyparse();
    get_cmd(root, ret);
}

// void get_abstract_syntax_tree(char* file_name, char* ret)
// {
//     char* content = NULL;
//     file_to_string(file_name, &content);
//     yy_scan_string(content);
//     yyparse();
//     get_cmd(root, ret);
// }



// void get_abstract_syntax_tree1(char** syntax, char* ret) {
//     yy_scan_string(*syntax);
//     yyparse();
//     get_cmd(root, ret);
// }
