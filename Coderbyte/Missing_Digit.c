#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MissingDigit(char *str) {
    char left[50], right[50], result_str[50], op;
    int num1, num2, result, missing_digit = -1;

    // 解析等式
    if (sscanf(str, "%s %c %s = %s", left, &op, right, result_str) != 4) {
        printf("Error\n");
        return;
    }

    // 確定哪個數字包含 'x'
    char *missing_part = NULL;
    if (strchr(left, 'x')) missing_part = left;
    else if (strchr(right, 'x')) missing_part = right;
    else if (strchr(result_str, 'x')) missing_part = result_str;

    // 遍歷 0-9 測試 x
    for (int digit = 0; digit <= 9; digit++) {
        char temp[50];
        strcpy(temp, missing_part);

        // 替換 x 為當前測試數字
        for (int i = 0; temp[i]; i++) {
            if (temp[i] == 'x') {
                temp[i] = '0' + digit;
            }
        }

        // 轉換數字，根據 x 出現的地方更新對應變數
        if (missing_part == left) num1 = atoi(temp);
        else num1 = atoi(left);

        if (missing_part == right) num2 = atoi(temp);
        else num2 = atoi(right);

        if (missing_part == result_str) result = atoi(temp);
        else result = atoi(result_str);

        // 檢查等式是否成立
        int valid = 0;
        switch (op) {
            case '+': valid = (num1 + num2 == result); break;
            case '-': valid = (num1 - num2 == result); break;
            case '*': valid = (num1 * num2 == result); break;
            case '/': if (num2 != 0) valid = (num1 / num2 == result); break;
        }

        if (valid) {
            missing_digit = digit;
            break;  // 找到正確答案後立即結束迴圈
        }
    }

    // 輸出結果
    printf("%d\n", missing_digit);
}

// keep this function call here
int main(void) { 
   
  MissingDigit(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}