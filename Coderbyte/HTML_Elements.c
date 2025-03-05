#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定義 HTML 標籤堆疊
typedef struct {
    char tags[100][10]; // 最多 100 個標籤，每個標籤長度最多 10
    int top;
} Stack;

// 初始化堆疊
void initStack(Stack *s) {
    s->top = -1;
}

// 推入堆疊
void push(Stack *s, char *tag) {
    if (s->top < 99) {
        strcpy(s->tags[++(s->top)], tag);
    }
}

// 彈出堆疊
char *pop(Stack *s) {
    if (s->top >= 0) {
        return s->tags[(s->top)--];
    }
    return NULL;
}

// 取得堆疊頂部元素
char *top(Stack *s) {
    if (s->top >= 0) {
        return s->tags[s->top];
    }
    return NULL;
}

// HTML 標籤檢查函數
void HTMLElements(char *str) {
    Stack stack;
    initStack(&stack);
    
    char tag[10], wrong_tag[10] = "";
    int i = 0, len = strlen(str);
    
    while (i < len) {
        if (str[i] == '<') {
            int j = i + 1, k = 0;
            char closing = 0;

            // 判斷是否為閉合標籤 </tag>
            if (str[j] == '/') {
                closing = 1;
                j++;
            }

            // 讀取標籤名稱
            while (str[j] != '>' && k < 9) {
                tag[k++] = str[j++];
            }
            tag[k] = '\0';  // 標籤字串結束
            i = j; // 移動索引到 `>`

            if (!closing) { // 開啟標籤
                push(&stack, tag);
            } else { // 閉合標籤
                char *topTag = pop(&stack);
                if (topTag == NULL || strcmp(topTag, tag) != 0) {
                    // **錯誤情況：閉合標籤與堆疊頂部標籤不匹配**
                    strcpy(wrong_tag, (topTag == NULL) ? tag : topTag);
                    break;
                }
            }
        }
        i++;
    }

    // **如果堆疊還有未關閉的標籤，則回傳第一個未關閉標籤**
    if (wrong_tag[0] == '\0' && stack.top >= 0) {
        strcpy(wrong_tag, stack.tags[0]);
    }

    // 輸出結果
    if (wrong_tag[0] == '\0') {
        printf("true\n");
    } else {
        printf("%s\n", wrong_tag);
    }
}