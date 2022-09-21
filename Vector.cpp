// Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

void Options();

//Fill Functions
vector<vector<int>> FillRandomly(int width, int height);
vector<vector<int>> FillZeroes(int width, int height);
vector<vector<int>> FillCin(int width, int height);

//Show Function
void ShowNumber(vector<vector<int>> ar, int width, int height);

//Sum Function
int SumOfElements(vector<vector<int>> ar, int width, int height);

//Min and Max Functions
int MinElement(vector<vector<int>> ar, int width, int height);
int MaxElement(vector<vector<int>> ar, int width, int height);

//Average Functions
double MeanOfElements(vector<vector<int>> ar, int width, int height);
double AverageValue(vector<vector<int>> ar, int width, int height);

int main()
{
    // 1)
    Options();

    vector<vector<int>> numbers;
    int width = 4;
    int height = 4;

    // 2)
    numbers = FillRandomly(width, height);
    ShowNumber(numbers, width, height);

    // 3)
    numbers = FillZeroes(width, height);
    ShowNumber(numbers, width, height);

    // 4)
    numbers = FillCin(width, height);
    ShowNumber(numbers, width, height);

    // 5)
    int sum = SumOfElements(numbers, width, height);
    cout << "Sum = " << sum << endl;

    // 6)
    int min = MinElement(numbers, width, height);
    cout << "Min = " << min << endl;

    // 7)
    int max = MaxElement(numbers, width, height);
    cout << "Max = " << max << endl;

    // 8)
    double mean = MeanOfElements(numbers, width, height);
    double average = AverageValue(numbers, width, height);
    cout << "Mean = " << mean << endl << "Average from list = " << average << endl;
}

void Options() {
    srand((unsigned int)time(0));
}

vector<vector<int>> FillRandomly(int width, int height) {
    vector<vector<int>> ar;
    for (int y = 0; y < height; y++) {
        vector<int> row;
        for (int x = 0; x < width; x++) {
            row.push_back(rand() % 100);
        }
        ar.push_back(row);
    }
    return ar;
}

vector<vector<int>> FillZeroes(int width, int height) {
    vector<vector<int>> ar;
    for (int y = 0; y < height; y++) {
        vector<int> row;
        for (int x = 0; x < width; x++) {
            row.push_back(0);
        }
        ar.push_back(row);
    }
    return ar;
}

vector<vector<int>> FillCin(int width, int height) {
    vector<vector<int>> ar;
    for (int y = 0; y < height; y++) {
        vector<int> row;
        for (int x = 0; x < width; x++) {
            int val;
            cin >> val;
            row.push_back(val);
        }
        ar.push_back(row);
    }
    return ar;
}

void ShowNumber(vector<vector<int>> ar, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cout << ar[y][x] << "\t";
        }
        cout << endl;
    }
}

int SumOfElements(vector<vector<int>> ar, int width, int height) {
    int sum = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            sum += ar[y][x];
        }
    }
    return sum;
}

int MinElement(vector<vector<int>> ar, int width, int height) {
    int min = ar[0][0];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (min > ar[y][x]) {
                min = ar[y][x];
            }
        }
    }
    return min;
}

int MaxElement(vector<vector<int>> ar, int width, int height) {
    int max = ar[0][0];
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (max < ar[y][x]) {
                max = ar[y][x];
            }
        }
    }
    return max;
}

double MeanOfElements(vector<vector<int>> ar, int width, int height) {
    double mean = (double)SumOfElements(ar, width, height) / (width * height);
    return mean;
}

double AverageValue(vector<vector<int>> ar, int width, int height) {
    double average = (double)((MaxElement(ar, width, height) + MinElement(ar, width, height))) / 2;
    return average;
}