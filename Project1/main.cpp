#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

void drawHangman(int mistakes)
{
    cout << "\n";

    if (mistakes == 0)
    {
        cout << " +---+\n";
        cout << " |   |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "=======\n";
    }
    else if (mistakes == 1)
    {
        cout << " +---+\n";
        cout << " |   |\n";
        cout << " O   |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "=======\n";
    }
    else if (mistakes == 2)
    {
        cout << " +---+\n";
        cout << " |   |\n";
        cout << " O   |\n";
        cout << " |   |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "=======\n";
    }
    else if (mistakes == 3)
    {
        cout << " +---+\n";
        cout << " |   |\n";
        cout << " O   |\n";
        cout << "/|   |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "=======\n";
    }
    else if (mistakes == 4)
    {
        cout << " +---+\n";
        cout << " |   |\n";
        cout << " O   |\n";
        cout << "/|\\  |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "=======\n";
    }
    else if (mistakes == 5)
    {
        cout << " +---+\n";
        cout << " |   |\n";
        cout << " O   |\n";
        cout << "/|\\  |\n";
        cout << "/    |\n";
        cout << "     |\n";
        cout << "=======\n";
    }
    else
    {
        cout << " +---+\n";
        cout << " |   |\n";
        cout << " O   |\n";
        cout << "/|\\  |\n";
        cout << "/ \\  |\n";
        cout << "     |\n";
        cout << "=======\n";
    }
}

int main()
{
    system("chcp 65001 > nul");

    const char* words[] =
    {
        "kozak",
        "borscht",
        "viburnum",
        "sun",
        "willow",
        "tryzub",
        "bread",
        "stork"
    };

    int wordCount = 8;

    const char* secretWord = words[rand() % wordCount];

    int len = strlen(secretWord);

    char hidden[50];

    for (int i = 0; i < len; i++)
        hidden[i] = '_';

    hidden[len] = '\0';

    char used[100] = "";
    int mistakes = 0;

    cout << "================================\n";
    cout << "        ГРА ШИБЕНИЦЯ\n";
    cout << "================================\n";
    cout << "Пиши англійсикі літри\n";
    cout << "Приклад слова яке може бути: kozak\n";

    while (mistakes < 6)
    {
        drawHangman(mistakes);

        cout << "\nСлово: ";
        for (int i = 0; i < len; i++)
            cout << hidden[i] << " ";

        cout << "\n\nВикористані літери: " << used << endl;

        char letter;
        cout << "\nВведіть літеру: ";
        cin >> letter;

        bool found = false;

        for (int i = 0; i < len; i++)
        {
            if (secretWord[i] == letter)
            {
                hidden[i] = letter;
                found = true;
            }
        }

        int size = strlen(used);
        used[size] = letter;
        used[size + 1] = ' ';
        used[size + 2] = '\0';

        if (!found)
        {
            mistakes++;
            cout << "\nНеправильно!\n";
        }
        else
        {
            cout << "\nПравильно!\n";
        }

        if (strcmp(hidden, secretWord) == 0)
        {
            cout << "\n Вітаємо! Ви перемогли!\n";
            cout << "Загадане слово: " << secretWord << endl;
        }
    }

    drawHangman(6);

    cout << "\nВи програли!\n";
    cout << "Загадане слово було: " << secretWord << endl;
}