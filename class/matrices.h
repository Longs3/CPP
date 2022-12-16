#ifndef MATRICES_H
#define MATRICES_H
#include<bits/stdc++.h>
using namespace std;



int __len(float x);
bool __isPrime(int x);
int __indexOf(vector<int> arr, int value);
vector<int> __allPrime(int num);

class Matrices {
private:
    int rows, cols, factor = 1;
    vector<vector<float>> matrix;
public:
    // This constructor takes 3 args. The first one is for the number of row. Second the the number of column. And the third one is the value for all the rows and column of the entire matrix.
    Matrices(int rows, int cols, float value = 0) { vector<float> temp;for (int i = 0;i < cols;i++) temp.push_back(value); for (int j = 0;j < rows;j++) matrix.push_back(temp);this->cols = cols;this->rows = rows; }
    // This constructor take 2 args. The first one is for the number of row to be created. The second one is an array or vector type to be inserted for each row.
    Matrices(int rows, vector<float> arr) { for (int i = 0;i < rows;i++) matrix.push_back(arr); }
    // This constructor take a two deminsional array and create an matrix automatically
    Matrices(vector<vector<float>> arr) { int rows = arr.size(), cols = 0;for (int i = 0;i < rows;i++)(cols <= arr[i].size()) ? cols = arr[i].size() : cols += 0;vector<float> temp;for (int i = 0;i < rows;i++) { for (int j = 0;j < cols;j++) temp.push_back((arr[i][j]) ? arr[i][j] : 0);matrix.push_back(temp);temp.clear(); }this->rows = rows;this->cols = cols; }

    // Take 3 args for the matrix location one is for the specific row and col and the value to be inserted.
    void replace(int row, int col, float value) { matrix[row][col] = value; }


    void addRow(int x = 1) { this->rows += x;vector<float> temp; for (int i = 0;i < this->cols; i++) temp.push_back(0);for (int i = 0;i < x;i++) matrix.push_back(temp); }
    void addRow(float value, int x = 1) { this->rows += x;vector<float> temp;for (int i = 0;i < this->cols;i++)temp.push_back(value);for (int i = 0;i < x;i++)matrix.push_back(temp); }
    void addRow(vector<float> value, int x = 1) { this->rows += x;vector<float> temp;if (value.size() < this->cols) for (int i = value.size();i < cols;i++) value.push_back(value[value.size() - 1]);for (int i = 0;i < this->cols;i++)temp.push_back(value[i]);for (int i = 0;i < x;i++)matrix.push_back(temp); }
    void addRow(vector<vector<float>> arr) { int rows = arr.size(), cols = 1;vector<float> temp; for (int i = 0;i < rows;i++) addRow(arr[i]);this->rows += rows; }

    void addCol(int x = 1) { for (int i = 0;i < this->rows;i++) matrix[i].push_back(0); }
    void addCol(float value, int x = 1) { for (int j = 0;j < x;j++) for (int i = 0;i < rows;i++) matrix[i].push_back(value); this->cols += x; }
    void addCol(vector<float> value, int x = 1) { int ctr = value.size();for (int j = 0;j < x;j++)for (int i = 0;i < this->rows;i++) { if (ctr == 0) for (int k = 0;k < cols - ctr;k++) matrix[i].push_back(0);matrix[i].push_back(value[i]);ctr--; } }

    void factoring(int value) { factor = value;for (int i = 0;i < rows;i++) for (int j = 0;j < this->cols;j++) replace(i, j, valueAt(i, j) / factor); }

    int getCol() const { return this->cols; }
    int getRow() const { return this->rows; }

    float valueAt(int row, int col) const { return matrix[row][col]; }
    bool __checkInt() {
        int temp;
        for (int i = 0;i < rows;i++) {
            for (int j = 0;j < cols;j++) {
                temp = (int)valueAt(i, j);
                if (temp != valueAt(i, j)) return false;
            }
        }
        return true;
    }
    friend ostream& operator<<(ostream& os, const Matrices& matrix) {
        os << (char)201 << "  ";
        for (int i = 0;i < matrix.cols;i++)
            os << "       ";
        os << (char)187 << endl;
        for (int j = 0;j < matrix.rows;j++) {
            os << (char)186;
            for (int i = 0;i < matrix.cols;i++) {
                float value = matrix.matrix[j][i];
                int count = __len(value);(value < 0) ? os << " -" : os << "  ";
                if (value < 10000 && value >= 1000) os << " ";
                (count == 0) ? os << setprecision(1) << abs(value) : os << fixed << setprecision(count - 1) << abs(value);
            }os << "  " << (char)186; (matrix.rows/2==j && matrix.factor !=1)? os << '(' << matrix.factor << ')' << endl:os << endl;
        }os << (char)200 << "  ";for (int i = 0;i < matrix.cols;i++) cout << "       "; os << (char)188 << endl;return os;
    }

    friend Matrices operator+(Matrices&, float&);
    friend Matrices operator+(Matrices&, vector<vector<float>>&);
    friend Matrices operator+(Matrices&, Matrices&);

    friend Matrices operator-(Matrices&, float&);
    friend Matrices operator-(Matrices&, vector<vector<float>>&);
    friend Matrices operator-(Matrices&, Matrices&);

    friend void operator*(float&, Matrices&);
    friend void operator*(Matrices&, float&);

    friend void operator+=(Matrices&, float&);
    friend void operator+=(Matrices&, vector<float>&);
    friend void operator+=(Matrices, vector<vector<float>>&);
    friend void operator+=(Matrices&, Matrices&);

    friend void operator-=(Matrices&, float&);
    friend void operator-=(Matrices&, vector<float>&);
    friend void operator-=(Matrices, vector<vector<float>>&);
    friend void operator-=(Matrices&, Matrices&);

};
// operator +
Matrices operator+(Matrices& obj, float& value) { int row = obj.getRow(), col = obj.getCol();Matrices temp(row, col);for (int i = 0;i < row;i++)for (int j = 0;j < col;j++)temp.replace(i, j, obj.valueAt(i, j) + value);return temp; }
Matrices operator+(Matrices& obj, vector<vector<float>>& arr) { Matrices temp(obj.getRow(), obj.getCol());if (arr.size() != obj.getRow()) return obj;int row = obj.getRow(), col = 0;for (int i = 0;i < row;i++)if (arr[i].size() == obj.getCol()) { col = 1;break; }if (col)for (int i = 0;i < obj.getRow();i++)for (int j = 0;j < obj.getCol();j++)temp.replace(i, j, obj.valueAt(i, j) + arr[i][j]);return temp; }
Matrices operator+(Matrices& o1, Matrices& o2) { int row = o1.getRow(), col = o1.getCol();Matrices temp(row, col);if (col != o2.getCol() || row != o2.getRow()) return temp;for (int i = 0;i < row;i++)for (int j = 0;j < col;j++)temp.replace(i, j, o1.valueAt(i, j) + o2.valueAt(i, j)); }
// end of operator +
// operator -
Matrices operator-(Matrices& obj, float& value) { int row = obj.getRow(), col = obj.getCol();Matrices temp(row, col);for (int i = 0;i < row;i++)for (int j = 0;j < col;j++)temp.replace(i, j, obj.valueAt(i, j) - value);return temp; }
Matrices operator-(Matrices& obj, vector<vector<float>>& arr) { Matrices temp(obj.getRow(), obj.getCol());if (arr.size() != obj.getRow()) return obj;int row = obj.getRow(), col = 0;for (int i = 0;i < row;i++)if (arr[i].size() == obj.getCol()) { col = 1;break; }if (col)for (int i = 0;i < obj.getRow();i++)for (int j = 0;j < obj.getCol();j++)temp.replace(i, j, obj.valueAt(i, j) - arr[i][j]);return temp; }
Matrices operator-(Matrices& o1, Matrices& o2) { int row = o1.getRow(), col = o1.getCol();Matrices temp(row, col);if (col != o2.getCol() || row != o2.getRow()) return temp;for (int i = 0;i < row;i++)for (int j = 0;j < col;j++)temp.replace(i, j, o1.valueAt(i, j) - o2.valueAt(i, j));return temp; }
// end of operator -
void operator*(float& value, Matrices& matrix) { for (int i = 0;i < matrix.getRow();i++) for (int j = 0;j < matrix.getCol();j++) matrix.replace(i, j, matrix.valueAt(i, j) * value); }
void operator*(Matrices& matrix, float& value) { for (int i = 0;i < matrix.getRow();i++) for (int j = 0;j, matrix.getCol();j++) matrix.replace(i, j, matrix.valueAt(i, j) * value); }
// operator +=
void operator+=(Matrices& obj, float& value) { for (int i = 0;i < obj.getRow();i++)for (int j = 0;j < obj.getCol();j++)obj.replace(i, j, obj.valueAt(i, j) + value); }
void operator+=(Matrices& obj, vector<vector<float>>& arr) { if (arr.size() != obj.getRow()) return;int row = obj.getRow(), col = 0; for (int i = 0;i < row;i++)if (arr[i].size() == obj.getCol()) { col = 1;break; }if (col)for (int i = 0;i < obj.getRow();i++)for (int j = 0;j < obj.getCol();j++)obj.replace(i, j, obj.valueAt(i, j) + arr[i][j]); }
void operator+=(Matrices& o1, Matrices& o2) { int row = o1.getRow(), col = o1.getCol();if (col != o2.getCol() || row != o2.getRow()) return;for (int i = 0;i < row;i++)for (int j = 0;j < col;j++)o1.replace(i, j, o1.valueAt(i, j) + o2.valueAt(i, j)); }
// end of operator +=
// operator -=
void operator-=(Matrices& obj, float& value) { for (int i = 0;i < obj.getRow();i++)for (int j = 0;j < obj.getCol();j++)obj.replace(i, j, obj.valueAt(i, j) - value); }
void operator-=(Matrices& obj, vector<vector<float>>& arr) { if (arr.size() != obj.getRow()) return;int row = obj.getRow(), col = 0;for (int i = 0;i < row;i++)if (arr[i].size() == obj.getCol()) { col = 1;break; }if (col)for (int i = 0;i < obj.getRow();i++)for (int j = 0;j < obj.getCol();j++)obj.replace(i, j, obj.valueAt(i, j) - arr[i][j]); }
void operator-=(Matrices& o1, Matrices& o2) { int row = o1.getRow(), col = o1.getCol();if (col != o2.getCol() || row != o2.getRow()) return;for (int i = 0;i < row;i++)for (int j = 0;j < col;j++)o1.replace(i, j, o1.valueAt(i, j) - o2.valueAt(i, j)); }
// end of operator -=
int __len(float x) { int temp = abs((int)x); if (temp >= 100000) return 0;int ctr = 4;for (;;) { if (temp <= 9) return ctr;ctr--;temp /= 10; }if (ctr > 4) return 0;return ctr; }
int __indexOf(vector<int> arr, int value) { int ctr = 0; for (auto& i : arr) { if (i == value) return ctr;ctr++; } return -1; }
#endif
