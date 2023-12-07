#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    FILE *input_file = fopen("input_file.l", "r");
    FILE *regex_output = fopen("regex.txt", "w");
    FILE *process_output = fopen("process.txt", "w");

    if (input_file == NULL || regex_output == NULL || process_output == NULL) {
        perror("Error opening files");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    int in_regex_section = 0;
    int in_braces = 0;

    while (fgets(line, sizeof(line), input_file) != NULL) {
        if (strstr(line, "%%") != NULL) {
            if (!in_regex_section) {
                in_regex_section = 1;
                continue;
            } else {
                in_regex_section = 0;
                continue;
            }
        }

        if (in_regex_section) {
            if (!in_braces) {
                if (strstr(line, "{") != NULL) {
                    in_braces = 1;
                    continue;
                } else {
                    // 提取正则表达式部分并保存到 regex.txt
                    fputs(line, regex_output);
                }
            } else {
                if (strstr(line, "}") != NULL) {
                    in_braces = 0;
                    continue;
                } else {
                    // 提取处理语句部分并保存到 process.txt
                    fputs(line, process_output);
                }
            }
        }
    }

    fclose(input_file);
    fclose(regex_output);
    fclose(process_output);

    printf("Extraction completed successfully!\n");

    return EXIT_SUCCESS;
}
