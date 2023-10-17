#include<iostream>
#include "matrice.h"
using namespace matrice;
using namespace std;

matrice::matr::matr(int L, int C)
{

    
    //*** allocation      ***//
    M = new int *[L];
    for (int i = 0; i < L; i++)
        M[i] = new int[C];
    //*** initialisation ***//
    for(int i=0;i<L;i++)
      for (int j = 0; j < C; j++)
          M[i][j] = rand() % 10;
    this->row = L;
    this->col = C;
}

matrice::matr::~matr()
{
    cout << "Au revoir !!";
}

matrice::matr::matr(const matr &aut)
{
    M = new int *[aut.row];
    for (int i = 0; i < aut.row; i++)
        M[i] = new int[aut.col];
    //* initialisation *//
    for (int i = 0; i < aut.row; i++)
        for (int j = 0; j < aut.col; j++)
            M[i][j] = aut.M[i][j];
    this->row = aut.row;
    this->col = aut.col;
}

matrice::matr matrice::matr::operator=(const matrice::matr &aut)
{
    M = new int *[aut.row];
    for (int i = 0; i < aut.row; i++)
        M[i] = new int[aut.col];
    //* initialisation *//
    for (int i = 0; i < aut.row; i++)
        for (int j = 0; j < aut.col; j++)
            M[i][j] = aut.M[i][j];
    this->row = aut.row;
    this->col = aut.col;
    return *this;
}

// Définition de l'opérateur () pour accéder aux éléments de la matrice

int &matrice::matr::operator()(int L, int C) const
{
    return this->M[L][C];
}

void matrice::matr::affichage()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << M[i][j];
            cout << "\t";
        }
        cout << "\n";
    }
    cout << "\n";

}

matrice::matr matrice::operator+(const matrice::matr &matrix1, const matr &matrix2)
{
    if (matrix1.row != matrix2.row || matrix1.col != matrix2.col)
        throw runtime_error("Les matrices ont des dimensions différentes.");
    matrice::matr result(matrix1.row, matrix1.col);
    for (int i = 0; i < matrix1.row; ++i)
    {
        for (int j = 0; j < matrix1.col; ++j)
            result(i, j) = matrix1(i, j) + matrix2(i, j);
    }
    return result;
}

matrice::matr matrice::operator*(const matrice::matr &matrix1, const matr &matrix2)
{
    if ( matrix1.col != matrix2.row)
        throw runtime_error("Les matrices ne peuvent pas être multipliées car les dimensions ne sont pas compatibles.");
    matrice::matr result(matrix1.row, matrix2.col);
    for (int i = 0; i < matrix1.row; ++i)
    {
        for (int j = 0; j < matrix2.col; ++j)
        {
            result(i, j) = 0;
            for (int k = 0; k < matrix1.col; ++k)
            {
                result(i, j) += matrix1(i, k) * matrix2(k, j);
            }
        }       
    }
    return result;
}
// ************** Puissance ***********//
matrice::matr matrice::matr::Puissance(int val)
{
    matr tmp(3,3);
    for(int i=1;i<val;i++)
    tmp = *this * tmp;
    return tmp;
}
int main()
{
    matr M(3,3);
    matr M1(3, 3);
    matr M2(M1);
    M2 = M;
   M2= M2.Puissance(2);
    //M(1,2)=9;
    cout << "M :" << endl;
    M.affichage();
    cout << "M1 :" << endl;
    M1.affichage();
    cout << "M2 :" << endl;
    M2.affichage();
    cout << M(1, 2)<<endl;
   matr add = M1 + M2;
   matr produit = M1 * M2;
   cout << "Somme de deux matrices M1 + M2" << endl;
   add.affichage();
   cout << "Produit de deux matrices M1 * M2" << endl;
   produit.affichage();
}

