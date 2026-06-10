#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

void drawHuman(int mistakes)
{
    cout << "\n";

    switch (mistakes)
    {
    case 0:
        cout << " +---+\n";
        cout << " |   |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "=======\n";
        break;

    case 1:
        cout << " +---+\n";
        cout << " |   |\n";
        cout << " O   |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "=======\n";
        break;

    case 2:
        cout << " +---+\n";
        cout << " |   |\n";
        cout << " O   |\n";
        cout << " |   |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "=======\n";
        break;

    case 3:
        cout << " +---+\n";
        cout << " |   |\n";
        cout << " O   |\n";
        cout << "/|   |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "=======\n";
        break;

    case 4:
        cout << " +---+\n";
        cout << " |   |\n";
        cout << " O   |\n";
        cout << "/|\\  |\n";
        cout << "     |\n";
        cout << "     |\n";
        cout << "=======\n";
        break;

    case 5:
        cout << " +---+\n";
        cout << " |   |\n";
        cout << " O   |\n";
        cout << "/|\\  |\n";
        cout << "/    |\n";
        cout << "     |\n";
        cout << "=======\n";
        break;

    default:
        cout << " +---+\n";
        cout << " |   |\n";
        cout << " O   |\n";
        cout << "/|\\  |\n";
        cout << "/ \\  |\n";
        cout << "     |\n";
        cout << "=======\n";
        break;
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
        drawHuman(mistakes);

        cout << "\nСлово: ";
        for (int i = 0; i < len; i++)
            cout << hidden[i] << " ";

        cout << "\n\nВикористані літери: " << used << endl;

        char letter;
        cout << "\nВведіть літеру: ";
        cin >> letter;

        bool alreadyUsed = false;

        for (int i = 0; used[i] != '\0'; i++)
        {
            if (used[i] == letter)
            {
                alreadyUsed = true;
                break;
            }
        }

        if (alreadyUsed)
        {
            cout << "\nЦя літера вже використовувалась\n";
            continue;
        }

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
            cout << "\nНеправильно\n";
        }
        else
        {
            cout << "\nПравильно\n";
        }

        if (strcmp(hidden, secretWord) == 0)
        {
            cout << "\n Вітаю, ти виграв\n";
            cout << "Загадане слово: " << secretWord << endl;
            break;
        }
    }

    drawHuman(6);

    cout << "\nТи програв\n";
    cout << "Загадане слово було: " << secretWord << endl;
}