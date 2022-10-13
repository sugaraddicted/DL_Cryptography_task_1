#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;
long module; /* модуль  */



void remainder() {                                                                 /* 2. розв’язування рівняння виду  a mod m = x */
    cout << "Enter number : " << endl;
    long a;
    cin >> a;
    cout << "Enter mod : " << endl;
    cin >> module;
    long result = a % module;
    cout << "Result : " << endl;
    cout << result << endl;
}




void bin_pow() {                                                                   /* 3. розв’язування рівняння виду a^b mod m = x  */
    cout << "Enter number 'a' : " << endl;
    int a;
    cin >> a;
    cout << "Enter number 'b' : " << endl;
    int b;
    cin >> b;
    cout << "Enter module : " << endl;
    cin >> module;

    long res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= module;
        }
        a *= (a % module);
        a %= module;
        b >>= 1;
    }
    long result = res % module;
    cout << "Result : " << endl;
    cout << result << endl;
}



int rand_beetwen(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    return static_cast<int>(rand() * fraction * ((max - min) + 1) + min);
}
void gen_rand_prime_num()                                                             /* 5. генерація простого числа у діапазоні від A до B. */

{
    int count;
    cout << "Enter number A : " << endl;
    int a;
    cin >> a;
    cout << "Enter number B : " << endl;
    int b;
    cin >> b;


    long* arr = new long[b + 1];
    std::list<long> numbers;

    for (int i = a; i < b + 1; i++)
        arr[i] = i;

    for (int p = 2; p < b + 1; p++)
    {
        if (arr[p] != 0)
        {
            if (arr[p] > a && arr[p] < b) {

                numbers.push_back(arr[p]);
            }
            for (int j = p * p; j < b + 1; j += p)
                arr[j] = 0;
        }
    }
    int size = numbers.size();
    long* arr1 = new long[size];
    for (int i = 0; i < size; i++)
    {
        arr1[i] = numbers.front();
        numbers.pop_front();
    }

    cout << "Result : " << endl;
    cout << arr1[rand_beetwen(0, size - 1)] << endl;


}


int main() {
    cout << "Welcome to the menu! Please choose an option:" << endl;
    cout << "1. Solve a mod m = x " << endl;
    cout << "2. Solve a^b mod m = x " << endl;
    cout << "3. Generate prime number in range from A to B " << endl;
    cout << "Enter number of option : " << endl;
    int n;
    cin >> n;
    if (n >= 1 && n <= 4)
    {

        switch (n) {
        case 1:
            remainder();
            break;
        case 2:
            bin_pow();
            break;
        case 3:
            gen_rand_prime_num();
            break;
        }

    }

}
