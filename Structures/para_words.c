#include <stdio.h>

struct Wordcount {
    char *word;
    int count;
};

int isEqual(char a[], char b[]) {
    int i = 0;
    while (a[i] == b[i]) {
      if (a[i] == '\0' || b[i] == '\0')
         break;
      i++;
   }
   if (a[i] == '\0' && b[i] == '\0')
      return 1;
    return 0;
}

int main() {

    char para[500], words[100][100];
    struct Wordcount wordcounts[100];
    int noOfWords = 0, i = 0, j = 0, uniqueWords = 0;

    printf("Enter a paragraph:\n");
    gets(para);

    while (para[i] != '\0') {
        while(para[i] != ' ' && para[i] != '\0'){
            words[noOfWords][j] = para[i];
            j++;
            i++;
        }
        noOfWords++;
        if(para[i] != '\0')
            i++;
        j = 0;
    }

    for(i = 0; i < noOfWords; i++) {
        int wordRepeated = 0;
        for(j = 0; j < uniqueWords; j++) {
            if (isEqual(words[i], wordcounts[j].word)) {
                wordcounts[j].count++;
                wordRepeated = 1;
            }
        }
        if (!wordRepeated) {
            wordcounts[uniqueWords].word = words[i];
            wordcounts[uniqueWords].count = 1;
            uniqueWords++;
        }
    }

    for(i = 0; i < uniqueWords; i++) {
        printf("\n %s \n Count:%d", wordcounts[i].word, wordcounts[i].count);
    }

    return 0;
}