# Language Detector Program in C
This program detects the language of a given input text. Currently, the program can detect the following languages:

- English
- French
- German
- Finnish
- Portuguese
- Spanish
- Hungarian
- Italian

The program works by analyzing the letter frequency counts of the input text and comparing them to the letter frequency counts of each language's corresponding text. The language with the closest match is determined to be the language of the input text.

# Usage
1. Clone the repository or download the source code.
2. Compile the program using a C compiler of your choice.
3. Create an input file named input.txt and save it in the same directory as the compiled program. This file should contain the text to be analyzed.
4. Run the program and follow the prompts to select the desired output.

# Sample run:

    Select from the following stages of output to display:
    1. Letter frequency counts
    2. Letter frequency order
    3. Get user input and display frequency counts
    4. Get user input, display frequency counts, and display language
    0. Exit the program
    Your choice --> 4
    Letter Frequency Counts:
    Engl Finn Fren Germ Hung Ital Port Span
    A: 6018 9416 6544 5068 7541 8935 9939 10052
    B: 1464 448 1081 2060 1746 1221 1173 1387
    C: 2144 636 3028 3126 1014 3865 2855 3222
    D: 3331 1013 2698 4592 2265 2945 3687 3815
    E: 9270 7187 12782 14779 8280 9364 10551 10861
    F: 1701 297 1101 1464 932 1099 1039 653
    G: 1333 187 772 2503 2975 1423 983 936
    H: 5244 2384 1004 4775 1687 1485 1413 1263
    I: 4653 8022 5583 7062 2961 8128 4179 3964
    J: 38 1331 538 148 1049 5 216 429
    K: 691 3952 28 1080 3551 51 19 18
    L: 3294 4648 4240 3089 4658 4814 2082 3985
    M: 2481 3526 3269 2861 3812 2790 4415 3021
    N: 4987 7958 5958 9026 4725 5966 4455 5704
    O: 6054 4219 5315 2208 3529 8668 8898 7605
    P: 1000 1331 2297 466 448 2060 1862 1842
    Q: 121 78 907 84 77 548 954 883
    R: 4518 1784 5986 5955 2802 5357 5328 5706
    S: 4943 5425 6898 5852 4538 4863 6774 6468
    T: 7055 7620 6025 5477 5632 5373 3729 3932
    U: 2590 4226 5373 3327 963 3081 3840 3591
    V: 657 1784 1566 661 1297 1287 1351 893
    W: 1926 120 78 1797 138 141 68 61
    X: 112 45 328 89 49 42 260 91
    Y: 1637 1403 247 169 1998 216 65 891
    Z: 15 3 343 939 2742 490 314 301
    Letter frequency order:
    Engl Finn Fren Germ Hung Ital Port Span
    E A E E E E E E
    T I S N A A A A
    O N A I T O O O
    A T T R N I S S
    H E R S L N R R
    N S N T S T N N
    S L I A M R M L
    I U U H K S I I
    R O O D O L U T
    D K L U G C T D
    L M M C I U D U
    U H C L R D C C
    M R D M Z M L M
    C V P G D P P P
    W Y V O Y H H B
    F J F B B G V H
    Y P B W H V B G
    B D H F V B F V
    G C Q K J F G Y
    P B G Z C Q Q Q
    K F J V U Z Z F
    V G Z P F Y X J
    Q W X Y P W J Z
    X Q Y J W K W X
    J X W X Q X Y W
    Z Z K Q X J K K
    Copy and paste a paragraph of text to be analyzed, followed by ^z (PC) or ^d (Mac) on a blank
    line:
    Ma per arrivare a un agreement bisogna essere in due. E dato che il governo intende resistere
    sui numeri della manovra, è
    necessario offrire garanzie all’Europa e ai mercati. Perciò sono stati stabiliti due capisaldi: uno
    tecnico, l’altro più
    politico. La riduzione strutturale del debito viene fissato come un «obiettivo strategico», non
    a caso sottolineato da Di
    Maio dopo il vertice. La linea dell’esecutivo è che per far ripartire l’Italia sia necessario
    «cambiare approccio» con una
    manovra espansiva «dopo anni di cure rigoriste senza risultati», ma s
    A:51 B:5 C:20 D:15 E:55 F:4 G:6 H:2 I:54 J:0 K:0 L:22 M:10 N:29 O:39 P:13 Q:0 R:37 S:28 T:31
    U:15 V:9 W:0 X:0 Y:0 Z:3
    Letter frequency order:
    Engl Finn Fren Germ Hung Ital Port Span User
    E A E E E E E E E
    T I S N A A A A I
    O N A I T O O O A
    A T T R N I S S O
    H E R S L N R R R
    N S N T S T N N T
    S L I A M R M L N
    I U U H K S I I S
    R O O D O L U T L
    D K L U G C T D C
    L M M C I U D U D
    U H C L R D C C U
    M R D M Z M L M P
    C V P G D P P P M
    W Y V O Y H H B V
    F J F B B G V H G
    Y P B W H V B G B
    B D H F V B F V F
    G C Q K J F G Y Z
    P B G Z C Q Q Q H
    K F J V U Z Z F J
    V G Z P F Y X J K
    Q W X Y P W J Z Q
    X Q Y J W K W X W
    J X W X Q X Y W X
    Z Z K Q X J K K Y
    Language is Italian

In the sample run above, the user chose option 4 to display the frequency counts and language of the input text. The program analyzed the input text and determined that it is in Italian. The letter frequency counts and order for each language were also displayed for comparison.

# To use this language detector program, follow these steps:

1. Clone the repository to your local machine using the command 

    git clone https://github.com/AhsanRao/Language-Detector-in-C

2. Compile the program using a C compiler such as GCC.
3. Ensure that the input files (English Macbeth-English.txt, French Macbeth-French.txt, German Macbeth-German.txt, Finnish Macbeth-Finnish.txt, Portugese Prosas-Portugese.txt, Spanish shakespeare-Spanish.txt, Hungarian Álomvilág-Hungarian.txt, and Italian DivineComedy-Italian.txt) are in the same directory as the executable file.
4. Run the program and follow the prompts to select an option and enter input text to analyze.

**Note** that this program currently only detects the languages listed above and can be updated by editing the input files. Also, the program assumes that the input text contains only lowercase letters and spaces. If uppercase letters or other characters are present, the program may not work correctly.

I hope you find this language detector program useful. If you have any questions or feedback, please don't hesitate to contact me.





