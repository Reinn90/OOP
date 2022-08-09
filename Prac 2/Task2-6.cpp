#include <iostream>

void swap(int& f, int& s)
{
    int t = f;
    f = s;
    s = t;
}

void sort(int& first, int& second, int& third)
{
    while(first > second || second > third)
    {
        if (first > third)
        {
            swap(first, third);
        }

        if (second > third)
        {
            swap(second, third);
        }

        if (first > second)
        {
            swap(first, second);
        }
    }
}

int main()
{
    int f;
    int s;
    int t;

    std::cout << "Enter 3 numbers: ";
    std::cin >> f >> s >> t;

    sort(f, s, t);

    std::cout << "first: " << f << " second: " << s << " third: " << t << std::endl;

    return 0;
}