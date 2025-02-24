#include <stdio.h>
#include <string.h>

int main()
{
    FILE *inputFile = fopen("student.txt", "r");    // 打开输入文件
    FILE *outputFile = fopen("csStudent.txt", "w"); // 打开输出文件

    if (inputFile != NULL && outputFile != NULL)
    {
        char line[256];
        while (fgets(line, sizeof(line), inputFile))
        {
            // 解析行数据
            char name[64], id[64], dept[64], age[64];
            char *token;

            token = strtok(line, ":");
            strcpy(name, token);

            token = strtok(NULL, ":");
            strcpy(id, token);

            token = strtok(NULL, ":");
            strcpy(dept, token);

            token = strtok(NULL, ":");
            strcpy(age, token);

            // 判断dept是否为"cs"，如果是则写入输出文件
            if (strcmp(dept, "cs") == 0)
            {
                fprintf(outputFile, "%s:%s:%s\n", name, id, age);
            }
        }

        // 关闭文件
        fclose(inputFile);
        fclose(outputFile);

        printf("信息提取完成！\n");
    }
    else
    {
        printf("无法打开文件！\n");
    }

    return 0;
}
