#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
    case 4: case 6: case 9: case 11: return 30;
    case 2: return isLeapYear(year) ? 29 : 28;
    default: return 31;
    }
}

int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    if (year1 > year2 || (year1 == year2 && month1 > month2) || (year1 == year2 && month1 == month2 && day1 > day2)) {
        swap(day1, day2);
        swap(month1, month2);
        swap(year1, year2);
    }

    int days = 0;

    while (year1 < year2 || month1 < month2 || day1 < day2) {
        day1++;
        if (day1 > daysInMonth(month1, year1)) {
            day1 = 1;
            month1++;
        }
        if (month1 > 12) {
            month1 = 1;
            year1++;
        }
        days++;
    }
    return days;
}

int main() {
    int day1, month1, year1, day2, month2, year2;
    cout << "Enter first date (day month year): ";
    cin >> day1 >> month1 >> year1;
    cout << "Enter second date (day month year): ";
    cin >> day2 >> month2 >> year2;

    cout << "Difference in days: " << daysBetweenDates(day1, month1, year1, day2, month2, year2) << endl;
    return 0;
}

*/


/*double average(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

int main() {
    int arr[] = { 3, 5, 7, 10, 2 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Average: " << average(arr, size) << endl;
    return 0;
}*/


/*
void countElements(const int arr[], int size, int& positive, int& negative, int& zeros) {
    positive = negative = zeros = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) positive++;
        else if (arr[i] < 0) negative++;
        else zeros++;
    }
}

int main() {
    int arr[] = { 3, -5, 0, 7, -2, 0, 8, -1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int positive, negative, zeros;

    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    countElements(arr, size, positive, negative, zeros);

    cout << "Positive elements: " << positive << endl;
    cout << "Negative elements: " << negative << endl;
    cout << "Zero elements: " << zeros << endl;

    return 0;
}*/


/*template <typename T>
void initializeMatrix(vector<vector<T>>& matrix, int size, T value) {
    matrix.resize(size, vector<T>(size, value));
}

template <typename T>
void printMatrix(const vector<vector<T>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <typename T>
void findMinMaxDiagonal(const vector<vector<T>>& matrix, T& min, T& max) {
    int size = matrix.size();
    min = matrix[0][0];
    max = matrix[0][0];
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
}

template <typename T>
void sortRows(vector<vector<T>>& matrix) {
    for (auto& row : matrix) {
        sort(row.begin(), row.end());
    }
}

int main() {
    int size;
    cout << "Enter the size of the square matrix: ";
    cin >> size;

    vector<vector<int>> intMatrix;
    initializeMatrix(intMatrix, size, 5);
    cout << "Integer matrix initialized:" << endl;
    printMatrix(intMatrix);

    int minInt, maxInt;
    findMinMaxDiagonal(intMatrix, minInt, maxInt);
    cout << "Min on diagonal: " << minInt << ", Max on diagonal: " << maxInt << endl;

    sortRows(intMatrix);
    cout << "Sorted integer matrix by rows:" << endl;
    printMatrix(intMatrix);

    vector<vector<double>> doubleMatrix;
    initializeMatrix(doubleMatrix, size, 3.14);
    cout << "Double matrix initialized:" << endl;
    printMatrix(doubleMatrix);

    double minDouble, maxDouble;
    findMinMaxDiagonal(doubleMatrix, minDouble, maxDouble);
    cout << "Min on diagonal: " << minDouble << ", Max on diagonal: " << maxDouble << endl;

    sortRows(doubleMatrix);
    cout << "Sorted double matrix by rows:" << endl;
    printMatrix(doubleMatrix);

    vector<vector<char>> charMatrix;
    initializeMatrix(charMatrix, size, 'A');
    cout << "Character matrix initialized:" << endl;
    printMatrix(charMatrix);

    char minChar, maxChar;
    findMinMaxDiagonal(charMatrix, minChar, maxChar);
    cout << "Min on diagonal: " << minChar << ", Max on diagonal: " << maxChar << endl;

    sortRows(charMatrix);
    cout << "Sorted character matrix by rows:" << endl;
    printMatrix(charMatrix);

    return 0;
}*/





/*int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int num1, num2;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    cout << "Greatest Common Divisor: " << gcd(num1, num2) << endl;
    return 0;
}
*/

string generateNumber() {
    string number;
    while (number.length() < 4) {
        char digit = '0' + rand() % 10;
        if (number.find(digit) == string::npos) {
            number += digit;
        }
    }
    return number;
}

pair<int, int> getBullsAndCows(const string& secret, const string& guess) {
    int bulls = 0, cows = 0;
    for (int i = 0; i < 4; i++) {
        if (guess[i] == secret[i]) {
            bulls++;
        }
        else if (secret.find(guess[i]) != string::npos) {
            cows++;
        }
    }
    return { bulls, cows };
}

void playGame(const string& secret, int attempts) {
    string guess;
    cout << "Enter your guess (4 unique digits): ";
    cin >> guess;

    if (guess.length() != 4) {
        cout << "Please enter a 4-digit number with unique digits.\n";
        playGame(secret, attempts);
        return;
    }

    pair<int, int> result = getBullsAndCows(secret, guess);
    int bulls = result.first;
    int cows = result.second;

    if (bulls == 4) {
        cout << "Congratulations! You've guessed the number in " << attempts << " attempts.\n";
    }
    else {
        cout << "Bulls: " << bulls << ", Cows: " << cows << endl;
        playGame(secret, attempts + 1);
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    string secret = generateNumber();

    cout << "Welcome to Bulls and Cows! Try to guess the 4-digit number.\n";
    playGame(secret, 1);

    return 0;
}