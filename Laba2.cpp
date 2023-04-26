#include <iostream>
#include <vector>
using namespace std;

class Vector {
private:
    int n;
    vector<double> v;
public:
    Vector(int size) {
        n = size;
        v.resize(n);
    }
    void input() {
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
    }
    void print() {
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    Vector operator+ (const Vector& other) const {
        Vector res(n);
        for (int i = 0; i < n; i++) {
            res.v[i] = v[i] + other.v[i];
        }
        return res;
    }
    Vector operator- (const Vector& other) const {
        Vector res(n);
        for (int i = 0; i < n; i++) {
            res.v[i] = v[i] - other.v[i];
        }
        return res;
    }
    double operator* (const Vector& other) const {
        double res = 0;
        for (int i = 0; i < n; i++) {
            res += v[i] * other.v[i];
        }
        return res;
    }
    Vector operator* (double scalar) const {
        Vector res(n);
        for (int i = 0; i < n; i++) {
            res.v[i] = v[i] * scalar;
        }
        return res;
    }
    Vector operator/ (double scalar) const {
        Vector res(n);
        for (int i = 0; i < n; i++) {
            res.v[i] = v[i] / scalar;
        }
        return res;
    }
};

int main() {
    int n;
    double scalar;

    cout << "Enter the size of the vectors: ";
    cin >> n;
    Vector a(n), b(n);

    cout << "Enter the values for the first vector:\n";
    a.input();
    cout << "Enter the values for the second vector:\n";
    b.input();

    cout << "Enter the value for the scalar:\n";
    cin >> scalar;

    Vector c = a + b;
    Vector d = a - b;
    double mul_vectors = a * b;
    
    Vector e = a * scalar;
    Vector f = b / scalar;
    Vector g = b * scalar;
    Vector j = a / scalar;

    cout << "Sum of vectors: ";
    c.print();

    cout << "Difference of vectors: ";
    d.print();

    cout << "Vectors multiplication: " << mul_vectors << endl;

    cout << "Vector first multiplied by scalar " << scalar << ": ";
    e.print();
    cout << "Vector first divided by scalar " << scalar << ": ";
    j.print();

    cout << "Vector second multiplied by scalar " << scalar << ": ";
    g.print();
    cout << "Vector second divided by scalar " << scalar << ": ";
    f.print();

    return 0;
}