#include <iostream>
#include <queue>
#include <stack>
#include <time.h>

using namespace std;

void easy()
{
    //������� ����, �������� � ���� ������ � ����� ����������(�����, ���, ��������). ������� ���� �� �����. ��������� ���-�� �������, ������� ��������� �� ����� "�������������";

    //������� ����;
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

    //������ ��������, ��������� �� � ����;
    for (int i = 0; i < N; i++)
    {
        cout << "����� ���������� ����� " << i + 1 << endl;
        cout << "�����: ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(number[i].street, 56);
        Numbers.push(number[i].street);

        //���� ����� ��������� ������� - ���������� � ���������� �������;
        if (Numbers.top() == "Deribasovskaya")
            count++;
        cout << endl;

        cout << "����� ����: ";
        cin >> number[i].house;
        Numbers.push(number[i].house);
        cout << endl;

        cout << "����� ��������: ";
        cin >> number[i].flat;
        Numbers.push(number[i].flat);
        cout << endl;
    }

    //������������� �������� �����;
    cout << "������ �����: ";

    do
    {
        cout << Numbers.top() << " ";
        Numbers.pop();
    } while (!Numbers.empty());

    cout << endl << "���-�� ������� �� ����� �������������: " << count << endl << endl;
}

void medium()
{
    //������� ������� �� ��������� ��������. ������� �� �� �����, ����� ���� ������� ������ � �������� ����� �������. ����� ������� ������� �� �����;

    queue <string> Words;

    //��������� � ������� ��������;
    Words.push("one");
    Words.push("two");
    Words.push("three");
    Words.push("four");
    Words.push("five");
    Words.push("six");
    Words.push("seven");

    string arr[7], arr1[10];

    //������� �������� �������;
    cout << "�������� �������: ";
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

    //������� ������� � ��������� �����;
    Words.pop();
    Words.push("eight");

    cout << "������� ����� ���������: ";
    for (int i = 0; i < 7; i++)
    {
        cout << Words.front() << " ";
        Words.pop();
    }

    cout << endl << endl;
}

void hard()
{
    //���� ������ ������. ��������, �������� �� ������ ������ ����������(���-�� ����������� � ����������� ������ ���������). �������� � ������� �� ����� ����������� ������;
    //������� ��� ������ �� �����;

    stack <char> Stack;
    const int size = 8;
    char arr[size] = { ')','}','[','[',']','(','{',']' };
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0;

    //��������� ����������� ������ � ����, ������� ���-�� ������ ������� ����;
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

    cout << "����������� ������: ";

    //������� ���� � �����. ����������� ������;
    do
    {
        cout << Stack.top() << " ";
        Stack.pop();
    } while (!Stack.empty());

    cout << endl;

    cout << "����������� ������: ";

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == ')' || arr[i] == ']' || arr[i] == '}')
        {
            cout << arr[i] << " ";
        }
    }

    cout << endl;

    //���� ���-�� ������ ������� ���� ��������� - ������ ����������;
    if (count1 == count4 && count2 == count5 && count3 == count6)
    {
        cout << "������ ����������";
    }
    else
    {
        cout << "������ �� ����������";
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
        cout << "������� ����� �������(easy - 1, medium - 2, hard - 3): ";

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

        cout << "���������� ����? �� - 1, ��� - 2: ";

        cin >> b;

        cout << endl;

        if (b == 1)
        {
            count++;
            main();
        }

        if (b == 2)
        {
            cout << "�� ������ �� ����������";
            count++;
            break;
        }

    } while (count == 0);
}