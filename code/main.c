#include <stdio.h>

#include <stdlib.h>

#include<ctype.h>

#include <locale.h>

#include <string.h>

#define MAX_LINE_LENGTH 256
#define NUM_LANGUAGES 7
#define ALPHABET_SIZE 26

typedef struct {
  char letter;
  int count;
}
LetterFreq;

typedef struct {
  char language[MAX_LINE_LENGTH];
  char filename[MAX_LINE_LENGTH];
  char signature[ALPHABET_SIZE];
}
Language;

void frequency(int( * array)[ALPHABET_SIZE], char ch, int i) {
  int checking_ascii = (int) ch;
  if (ch >= 'a' && ch <= 'z') {
    ch = ch - 32; // convert lowercase to uppercase
  }
  if (ch >= 'A' && ch <= 'Z') {
    array[i][ch - 'A']++;
  }
}

int levenshtein(char * s1, char * s2) {
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  int matrix[len1 + 1][len2 + 1];
  for (int i = 0; i <= len1; i++) {
    matrix[i][0] = i;
  }
  for (int j = 0; j <= len2; j++) {
    matrix[0][j] = j;
  }
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
      matrix[i][j] = fmin(fmin(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1), matrix[i - 1][j - 1] + cost);
    }
  }
  return matrix[len1][len2];
}

// Comparison function for sorting LetterFreq array in descending order based on count
int cmpfunc(const void * a,
  const void * b) {
  const LetterFreq * fa = (const LetterFreq * ) a;
  const LetterFreq * fb = (const LetterFreq * ) b;
  return (fb -> count - fa -> count);
}

int main() {
  setlocale(LC_ALL, "en_US.UTF-8");
  FILE * fp;
  char line[MAX_LINE_LENGTH];
  Language languages[NUM_LANGUAGES];

  // Open the input file
  fp = fopen("input.txt", "r");
  if (fp == NULL) {
    printf("Error opening input file\n");
    return 1;
  }

  // Read each line of the file and store the data in a Language struct
  int i = 0;
  while (fgets(line, MAX_LINE_LENGTH, fp)) {
    sscanf(line, "%s %s", languages[i].language, languages[i].filename);
    i++;
  }

  // Process each file
  int counts[NUM_LANGUAGES][ALPHABET_SIZE] = {
    0
  };

  for (i = 0; i < NUM_LANGUAGES; i++) {

    // Open the file
    FILE * file = fopen(languages[i].filename, "r");
    if (file == NULL) {
      printf("Error opening file %s\n", languages[i].filename);
      return 1;
    }

    // Reset count array
    memset(counts[i], 0, sizeof(int) * ALPHABET_SIZE);

    // Count letter frequencies
    char ch;
    while ((ch = fgetc(file)) != EOF) {

      frequency(counts, ch, i);
    }
    LetterFreq freqs[ALPHABET_SIZE];
    // Sort letter frequencies in descending order
    for (int j = 0; j < ALPHABET_SIZE; j++) {
      freqs[j].letter = 'A' + j;
      freqs[j].count = counts[i][j];
    }
    qsort(freqs, ALPHABET_SIZE, sizeof(LetterFreq), cmpfunc);

    // Print letter frequencies in descending order
    for (int j = 0; j < ALPHABET_SIZE; j++) {
      languages[i].signature[j] = freqs[j].letter;
    }

    fclose(file);
  }
  fclose(fp);
  int option = -1;
  while (option != 0) {
    printf("Which Language\n");
    printf("Select from the following stages of output to display:\n");
    printf("1. Letter frequency counts\n");
    printf("2. Letter frequency order\n");
    printf("3. Get user input and display frequency counts\n");
    printf("4. Get user input, display frequency counts, and display language\n");
    printf("0. Exit the program\n");
    scanf("%d", & option);
    getchar(); // clear newline character from input buffer

    // process user input based on option
    switch (option) {
    case 1: {
      // display letter frequency counts for each language
      for (i = 0; i < NUM_LANGUAGES; i++) {
        printf("%s\n", languages[i].language);
        for (int j = 0; j < ALPHABET_SIZE; j++) {
          printf("%c %d\n", 'A' + j, counts[i][j]);
        }
      }
      break;
    }
    case 2: {
      // display letter frequency order for each language
      for (i = 0; i < NUM_LANGUAGES; i++) {
        printf("%s: ", languages[i].language);
        for (int j = 0; j < ALPHABET_SIZE; j++) {
          printf("%c", languages[i].signature[j]);
        }
        printf("\n");
      }
      break;
    }
    case 3: {
      // get user input and display letter frequency counts
      int personalcounts[1][ALPHABET_SIZE] = {
        0
      };
      char inputText[MAX_LINE_LENGTH];
      printf("Enter some text: ");
      fgets(inputText, MAX_LINE_LENGTH, stdin);
      for (int i = 0; inputText[i] != '\0'; i++) {
        frequency(personalcounts, (char) inputText[i], 0);
      }
      for (int j = 0; j < ALPHABET_SIZE; j++) {
        printf("%c %d\n", 'A' + j, personalcounts[0][j]);
      }
      break;
    }
    case 4: {
      // get user input, display letter frequency counts, and display language
      char inputText[MAX_LINE_LENGTH];
      int personalcounts[1][ALPHABET_SIZE] = {
        0
      };
      printf("Enter some text: ");
      fgets(inputText, MAX_LINE_LENGTH, stdin);
      for (int i = 0; inputText[i] != '\0'; i++) {
        frequency(personalcounts, (char) inputText[i], 0);
      }
      int minDistance = MAX_LINE_LENGTH;
      int closestLanguageIndex = -1;
      Language myLanguage;
      LetterFreq freqs[ALPHABET_SIZE];
      // Sort letter frequencies in descending order
      for (int j = 0; j < ALPHABET_SIZE; j++) {
        freqs[j].letter = 'A' + j;
        freqs[j].count = personalcounts[i][j];
      }
      qsort(freqs, ALPHABET_SIZE, sizeof(LetterFreq), cmpfunc);

      // Print letter frequencies in descending order
      for (int j = 0; j < ALPHABET_SIZE; j++) {
        myLanguage.signature[j] = freqs[j].letter;
      }
      for (i = 0; i < NUM_LANGUAGES; i++) {
        int distance = levenshtein(myLanguage.signature, languages[i].signature);
        if (distance < minDistance) {
          minDistance = distance;
          closestLanguageIndex = i;
        }
      }
      for (int j = 0; j < ALPHABET_SIZE; j++) {
        printf("%c %d\n", 'A' + j, personalcounts[0][j]);
      }
       printf("Closest language match: %s\n", languages[closestLanguageIndex].language);
      break;
    }
    case 0: {
      // exit the program
      printf("Exiting program...\n");
      break;
    }
    default: {
      // invalid input
      printf("Invalid option. Please select a valid option.\n");
      break;
    }
    }
  }
  return 0;
}
