#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <Windows.h> // USE THIS FOR SLEEP FUNCTON TO MAKE LOADING PROCESS  (HELP TAKEN FROM INTERNET)
using namespace std;

class Matrix
{
private:
    int **matrixArr;
    int rowSize;
    int colSize;

public:
    Matrix();         //default constructor
    Matrix(int, int); //parameterized construtor
    void setRowCol();
    int getRow();
    int getCol();
    void setRow(int);
    void setCol(int);
    void createMatrix();
    Matrix operator+(Matrix); //overload + operator for addition
    Matrix operator-(Matrix); //overload - operator for subtraction
    Matrix operator*(Matrix); //overload * operator for multiplication
    Matrix operator~();       //overload ~ operator for Transpose
    void display() const;
    void multipliedDisplay(Matrix, Matrix) const; //display output after muliplicaton
};
Matrix::Matrix() //default constructor
{
    rowSize = 0;
    colSize = 0;
    matrixArr = nullptr;
}
Matrix::Matrix(int rowSize, int colSize) //parameterized construtor
{
    this->rowSize = rowSize;
    this->colSize = colSize;

    matrixArr = new int *[rowSize];
    for (int row = 0; row < rowSize; ++row)
    {
        matrixArr[row] = new int[colSize];
    }
    for (int row = 0; row < rowSize; ++row)
    {
        for (int col = 0; col < colSize; ++col)
        {
            this->matrixArr[row][col] = rand() % 12; //intialize with random values between (0-12)
        }
    }
}
void Matrix::setRowCol()
{
    cout << "\n\tEnter rowSize : ";
    cin >> rowSize;
    cout << "\n\tEnter colSize : ";
    cin >> colSize;
    cout << endl;
}
int Matrix::getRow()
{
    return rowSize;
}
int Matrix::getCol()
{
    return colSize;
}
void Matrix::setRow(int rowSize)
{
    this->rowSize = rowSize;
}
void Matrix::setCol(int colSize)
{
    this->colSize = colSize;
}
void Matrix::createMatrix()
{
    matrixArr = new int *[rowSize];
    for (int row = 0; row < rowSize; ++row)
    {
        this->matrixArr[row] = new int[colSize];
    }
    for (int row = 0; row < rowSize; ++row)
    {
        for (int col = 0; col < colSize; ++col)
        {
            this->matrixArr[row][col] = rand() % 9;
        }
    }
}
Matrix Matrix::operator+(Matrix m)
{
    Matrix add(rowSize, colSize);
    for (int row = 0; row < rowSize; ++row)
    {
        for (int col = 0; col < colSize; ++col)
        {
            add.matrixArr[row][col] = this->matrixArr[row][col] + m.matrixArr[row][col];
        }
    }
    return add;
}
Matrix Matrix::operator-(Matrix m)
{
    Matrix sub(rowSize, colSize);
    for (int row = 0; row < rowSize; ++row)
    {
        for (int col = 0; col < colSize; ++col)
        {
            sub.matrixArr[row][col] = this->matrixArr[row][col] - m.matrixArr[row][col];
        }
    }
    return sub;
}
Matrix Matrix::operator*(Matrix m)
{
    Matrix multiply(rowSize, colSize);
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < m.colSize; col++)
        {
            multiply.matrixArr[row][col] = 0;
            for (int k = 0; k < colSize; ++k)
            {
                multiply.matrixArr[row][col] += this->matrixArr[row][k] * m.matrixArr[k][col];
            }
        }
    }
    return multiply;
}
Matrix Matrix::operator~()
{
    Matrix Transpose(colSize, rowSize);
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < colSize; col++)
        {
            Transpose.matrixArr[col][row] = this->matrixArr[row][col];
        }
    }
    return Transpose;
}
void Matrix::display() const
{
    cout << "Matrix :\n\n"
         << endl;

    for (int row = 0; row < rowSize; ++row)
    {
        for (int col = 0; col < colSize; ++col)
        {
            cout << "\t\t" << this->matrixArr[row][col] << "\t";
        }
        cout << "\n\n";
    }

    cout << "\t(" << this->rowSize << "," << this->colSize << ")"; //order of matrix
    cout << endl;
}
void Matrix::multipliedDisplay(Matrix m1, Matrix m2) const
{
    cout << "Matrix :\n\n"
         << endl;
    for (int row = 0; row < m1.rowSize; ++row)
    {
        for (int col = 0; col < m2.colSize; ++col)
        {
            cout << "\t\t" << matrixArr[row][col] << "\t";
        }
        cout << "\n\n";
    }
    cout << "\t(" << m1.rowSize << "," << m2.colSize << ")"; //order of matrix after addition
    cout << endl;
}

int main()
{
    srand(time(0));
    Matrix m1(3, 3); //this is for automatic operations also added for customs inputs later in the code
    Matrix m2(3, 3);
    Matrix m3;

    int ch;
    char choice;

    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t   LOADING ";
    char x = 219; // this is Ascii value equal to "ALT KEY"
    for (int i = 0; i < 40; i++)
    {

        cout << x;
        Sleep(100); //suspends the execution of the program for a specified period of time
    }
    cout << " COMPLETED 100 % " << endl;

    cout
        << "\n\t\t\t==============WELOME To Matrix Arithmatic Calculator==============" << endl;
    cout << endl;
    while (true)
    {

        cout << "\n\n\t***\tPRESS 1: For Addtion of Matrices" << endl;
        cout << "\n\t***\tPRESS 2: For Subraction of Matrices " << endl;
        cout << "\n\t***\tPRESS 3: For Multiplication of  Matrices " << endl;
        cout << "\n\t***\tPRESS 4: For Transpose of Matrix " << endl;
        cout << "\n\t***\tPRESS 5: For Exit" << endl;
        cin >>
            ch;
        switch (ch)
        {
        case 1:
            system("cls");

            cout << "\n|||**Welcome to Matrix Additon**|||" << endl;
            cout << "\n\n\tDo you want to  use your custom inputs (Y/n) or (N/n for automatic operation)" << endl;
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                cout << "\n\n***For First Matrix " << endl;
                m1.setRowCol();
                m1.createMatrix();
                m1.display();
                cout
                    << "\n***For Second Matrix" << endl;
                m2.setRowCol();
                m2.createMatrix();
                m2.display();
                if (m1.getRow() == m2.getRow() && m1.getCol() == m2.getCol())
                {
                    m3 = m1 + m2;
                    cout << "\nAddtion of ";
                    m3.display();
                }
                else
                {
                    cout << "\t!!!!UNABLE TO ADD!!!!" << endl;
                    cout << "\nFirst Matrix is (" << m1.getRow() << "," << m1.getCol() << ") and Second Matrix is (" << m2.getRow() << "," << m2.getCol() << ") i.e. the order of these matrices is not equal " << endl;
                }
            }
            else if (choice == 'n' || choice == 'N')
            {
                m1.display();
                m2.display();
                cout << "\n-----------------------------------------------------------" << endl;
                m3 = m1 + m2;
                cout << "\nAddtion of ";
                m3.display();
            }

            break;
        case 2:
            system("cls");

            cout << "\n|||**Welcome to Matrix Subtration**|||" << endl;
            cout << "\n\n\tDo you want to  use your custom inputs (Y/n) or (N/n for automatic operation)" << endl;
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                cout << "\n\n***For First Matrix " << endl;
                m1.setRowCol();
                m1.createMatrix();
                m1.display();
                cout
                    << "\n***For Second Matrix" << endl;
                m2.setRowCol();
                m2.createMatrix();
                m2.display();
                if (m1.getRow() == m2.getRow() && m1.getCol() == m2.getCol())
                {
                    m3 = m1 - m2;
                    cout << "\nSubtraction of ";
                    m3.display();
                }
                else
                {
                    cout << "\t!!!!UNABLE TO SUBTRACT!!!!" << endl;
                    cout << "\nFirst Matrix is (" << m1.getRow() << "," << m1.getCol() << ") and Second Matrix is (" << m2.getRow() << "," << m2.getCol() << ") i.e. the order of these matrices is not equal " << endl;
                }
            }
            else if (choice == 'n' || choice == 'N')
            {
                m1.display();
                m2.display();
                cout << "\n-----------------------------------------------------------" << endl;
                m3 = m1 - m2;
                cout << "\nSubtraction of ";
                m3.display();
            }

            break;

        case 3:
            system("cls");

            cout << "\n|||**Welcome to Matrix Multiplication**|||" << endl;
            cout << "\n\n\tDo you want to  use your custom inputs (Y/n) or (N/n for automatic operation)" << endl;
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                cout << "\n\n***For First Matrix " << endl;
                m1.setRowCol();
                m1.createMatrix();
                m1.display();
                cout
                    << "\n***For Second Matrix" << endl;
                m2.setRowCol();
                m2.createMatrix();
                m2.display();

                if (m1.getCol() == m2.getRow())
                {
                    m3 = m1 * m2;
                    cout << "Multiplication of ";
                    m3.multipliedDisplay(m1, m2);
                }
                else
                {

                    cout << "\t!!!!UNABLE TO MULTIPLY!!!!" << endl;
                    cout << "\nFirst Matrix is (" << m1.getRow() << "," << m1.getCol() << ") and Second Matrix is (" << m2.getRow() << "," << m2.getCol() << ") i.e. the order of these matrices is not equal (" << m1.getCol() << "," << m2.getRow() << ")" << endl;
                }
            }
            else if (choice == 'n' || choice == 'N')
            {
                m1.display();
                m2.display();
                cout << "\n-----------------------------------------------------------" << endl;
                m3 = m1 * m2;
                cout << "\nMultiplication of ";
                m3.multipliedDisplay(m1, m2);
            }

            break;
        case 4:
            system("cls");

            cout << "\n|||**Welcome to Matrix Transpose**|||" << endl;
            cout << "\n\n\tDo you want to  use your custom inputs (Y/n) or (N/n for automatic operation)" << endl;
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                m1.setRowCol();
                m1.createMatrix();
                cout << "\n Before transposing ";
                m1.display();
                m2 = ~m1;
                cout << "\n After transposing ";
                m2.display();
                break;
            }
            else if (choice == 'n' || choice == 'Y')
            {

                cout << "\n Before transposing ";
                m1.display();
                cout << "\n-----------------------------------------------------------" << endl;
                m2 = ~m1;
                cout << "\n After transposing ";
                m2.display();
                break;
            }
        case 5:
            exit(0);

        default:

            cout << "Ivalid Entry....." << endl;
            break;
        }
    }
    return 0;
}