#pragma once
// Déclaration d'un espace de noms
namespace matrice
{
	class matr
	{
	private:
		int **M;
		int col;
		int row;
	public:
		//constructor 
		matr(int L, int C);
		int &operator()(int L, int C) const;
		// Constructor de copy
		matr(const matr &autre);
		// OPerateur =
		matr operator=(const matr &matrix);
		//Addition de deux Matrices
		friend matr operator+(const matr &matrix1, const matr &matrix2);
		// Produit de deux Matrices
		friend matr operator*(const matr &matrix1, const matr &matrix2);
		//Affichage
		void affichage();
		//Puissance
		matr Puissance(int val);
		//Transposer
		
		//Deconstructor
		~matr();
	};
}