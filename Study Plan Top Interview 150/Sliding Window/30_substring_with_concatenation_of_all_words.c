int compare(const void* a, const void* b) {
    const char* a_str = *(const char**)a;
    const char* b_str = *(const char**)b;

    return strcmp(a_str, b_str);
}

int valid_word(char* the_word, char** words, int wordsSize) {
    int found_word = 0;
    for (int i = 0; i < wordsSize; i++) {
        int comparison = strcmp(words[i], the_word);
        if (comparison == 0) {
            return 1;
        } else if (comparison > 0)
            break;
    }
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int length_of_s = strlen(s);
    int length_per_word = strlen(words[0]);
    int minimum_length = length_per_word * wordsSize;

    int* return_val = malloc(sizeof(int) * length_of_s);

    *returnSize = 0;

    if (length_of_s < length_per_word * wordsSize)
        return return_val;

    char** current_substring = malloc(sizeof(char*) * wordsSize);

    for (int i = 0; i < wordsSize; i++) {
        current_substring[i] = malloc(sizeof(int) * (length_per_word + 1));
        current_substring[i][length_per_word] = '\0';
    }

    qsort(words, wordsSize, sizeof(char*), compare);

    char* first_word = malloc(sizeof(char) * (length_per_word + 1));
    char* first_word_tmp = malloc(sizeof(char) * (length_per_word + 1));
    first_word[length_per_word] = '\0', first_word_tmp[length_per_word] = '\0';
    first_word[0] = '\0', first_word_tmp[0] = '\0';

    char* last_word = malloc(sizeof(char) * (length_per_word + 1));
    char* last_word_tmp = malloc(sizeof(char) * (length_per_word + 1));
    last_word[length_per_word] = '\0', last_word_tmp[length_per_word] = '\0';
    last_word[0] = '\0', last_word_tmp[0] = '\0';
    
    int added_words = 0;
    int start_idx = 0;
    int end_idx = minimum_length;

    while (length_of_s - start_idx >= minimum_length) {

        strncpy(first_word, s + start_idx, length_per_word);
        strncpy(last_word, s + (end_idx - length_per_word), length_per_word);

        // Can just repeat previous if words being processed unchanged

        int same_word = strcmp(first_word, first_word_tmp)==0 && strcmp(last_word, last_word_tmp) == 0;

        if (!same_word) {

            if (valid_word(first_word, words, wordsSize) &&
                valid_word(last_word, words, wordsSize)) {

                // Both starting and ending point contain valid words.

                for (int i = 0; i < wordsSize; i++) {
                    strncpy(current_substring[i],
                            (s + start_idx) + (i * length_per_word),
                            length_per_word);
                }

                qsort(current_substring, wordsSize, sizeof(char*), compare);

                int different = 0;
                for (int i = 0; i < wordsSize; i++) {
                    if (strcmp(words[i], current_substring[i]) != 0) {
                        different = 1;
                        break;
                    }
                }

                if (!different) {
                    return_val[(*returnSize)] = start_idx;
                    (*returnSize)++;
                }
            }
        }
        else
        {
            // Repeat previous
            if((*returnSize)>0 && return_val[(*returnSize)-1] == start_idx-1)
            {
                return_val[(*returnSize)] = start_idx;
                (*returnSize)++;
            }
        }

        strncpy(first_word_tmp, first_word, length_per_word);
        strncpy(last_word_tmp, last_word, length_per_word);
        
        start_idx++;
        end_idx++;
    }

    free(first_word);
    free(first_word_tmp);

    free(last_word);
    free(last_word_tmp);

    for (int i = 0; i < wordsSize; i++) {
        free(current_substring[i]);
    }

    free(current_substring);

    return return_val;
}