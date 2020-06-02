#include <iostream>
#include <queue>
#include <stack>
#include <time.h>

using namespace std;

void easy()
{
    //Создать стек, добавить в него данные о месте проживания(улица, дом, квартира). Вывести стек на экран. Посчитать кол-во квартир, которые находятся на улице "Дерибасовская";

    //создаем стек;
    stack <string> Numbers;

    struct home
    {
        char street[56];
        string house;
        string flat;
    };

    const int N = 2;
    int count = 0;

    home number[N];

    //вводим значения, добавляем их в стек;
    for (int i = 0; i < N; i++)
    {
        cout << "Место проживания номер " << i + 1 << endl;
        cout << "Улица: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(number[i].street, 56);
        Numbers.push(number[i].street);

        //если улица корректна условию - прибавляем к переменной единицу;
        if (Numbers.top() == "Deribasovskaya")
            count++;
        cout << endl;

        cout << "Номер дома: ";
        cin >> number[i].house;
        Numbers.push(number[i].house);
        cout << endl;

        cout << "Номер квартиры: ";
        cin >> number[i].flat;
        Numbers.push(number[i].flat);
        cout << endl;
    }

    //просматриваем значения стека;
    cout << "Данные стека: ";

    do
    {
        cout << Numbers.top() << " ";
        Numbers.pop();
    } while (!Numbers.empty());

    cout << endl << "Кол-во квартир на улице Дерибасовская: " << count << endl << endl;
}

void medium()
{
    //Создать очередь из строковых значений. Вывести ее на экран, после чего удалить старый и добавить новый элемент. Снова вывести очередь на экран;

    queue <string> Words;

    //добавляем в очередь элементы;
    Words.push("one");
    Words.push("two");
    Words.push("three");
    Words.push("four");
    Words.push("five");
    Words.push("six");
    Words.push("seven");

    string arr[7], arr1[10];

    //выводим элементы очереди;
    cout << "Элементы очереди: ";
    for (int i = 0; i < 7; i++)
    {
        cout << Words.front() << " ";
        arr[i] = Words.front();
        Words.pop();
    }

    for (int i = 0; i < 7; i++)
    {
        Words.push(arr[i]);
    }

    cout << endl;

    //удаляем элемент и добавляем новый;
    Words.pop();
    Words.push("eight");

    cout << "Очередь после изменений: ";
    for (int i = 0; i < 7; i++)
    {
        cout << Words.front() << " ";
        Words.pop();
    }

    cout << endl << endl;
}

void hard()
{
    //Дана строка скобок. Выяснить, является ли данная строка правильной(кол-во закрывающих и открывающих скобок совпадает). Добавить и считать из стека открывающие скобки;
    //Вывести все скобки на экран;

    stack <char> Stack;
    const int size = 8;
    char arr[size] = { ')','}','[','[',']','(','{',']' };
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0;

    //добавляем открывающие скобки в стек, считаем кол-во скобок каждого вида;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == '(')
        {
            Stack.push(arr[i]);
            count1++;
        }
        if (arr[i] == '{')
        {
            Stack.push(arr[i]);
            count2++;
        }
        if (arr[i] == '[')
        {
            Stack.push(arr[i]);
            count3++;
        }
        if (arr[i] == ')')
        {
            count4++;
        }
        if (arr[i] == '}')
        {
            count5++;
        }
        if (arr[i] == ']')
        {
            count6++;
        }
    }

    cout << "Открывающие скобки: ";

    //выводим стек и соотв. закрывающие скобки;
    do
    {
        cout << Stack.top() << " ";
        Stack.pop();
    } while (!Stack.empty());

    cout << endl;

    cout << "Закрывающие скобки: ";

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}')
        {
            cout << arr[i] << " ";
        }
    }

    cout << endl;

    //если кол-во скобок каждого вида совпадает - строка правильная;
    if (count1 == count4 && count2 == count5 && count3 == count6)
    {
        cout << "Строка правильная";
    }
    else
    {
        cout << "Строка не правильная";
    }

    cout << endl << endl;
};


int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "RU");

    int a;
    int count = 0;

    do
    {
        cout << "Введите номер задания(easy - 1, medium - 2, hard - 3): ";

        cin >> a;

        cout << endl;

        if (a == 1)
        {
            easy();
            count++;
        }

        if (a == 2)
        {
            medium();
            count++;
        }

        if (a == 3)
        {
            hard();
            count++;
        }

    } while (count == 0);

    int b;

    do
    {
        count = 0;

        cout << "Продолжить ввод? Да - 1, Нет - 2: ";

        cin >> b;

        cout << endl;

        if (b == 1)
        {
            count++;
            main();
        }

        if (b == 2)
        {
            cout << "Вы решили не продолжать";
            count++;
            break;
        }

    } while (count == 0);
}