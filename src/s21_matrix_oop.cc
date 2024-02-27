#include "s21_matrix_oop.h"

#include <cmath>
#include <iostream>

//--------test_for_del-----------//

int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }
void S21Matrix::SetRows(int rows) {
  if (rows < 0) throw std::invalid_argument("number matrix invalid");
  if (rows != rows_) {
    S21Matrix temp(rows, cols_);
    int min_row = std::min(rows_, rows);
    for (int i = 0; i < min_row; i++) {
      std::copy(matrix_[i], matrix_[i] + cols_, temp.matrix_[i]);
    }
    *this = std::move(temp);
  }
}
void S21Matrix::SetCols(int cols) {
  if (cols < 0) throw std::invalid_argument("number matrix invalid");
  if (cols != cols_) {
    S21Matrix temp(rows_, cols);
    int min_cols = std::min(cols_, cols);
    for (int i = 0; i < cols_; i++) {
      std::copy(matrix_[i], matrix_[i] + min_cols, temp.matrix_[i]);
    }
    *this = std::move(temp);
  }
}
//----------------constructors--------------------//
S21Matrix::S21Matrix() {}
S21Matrix::S21Matrix(int rows, int cols) {
  rows_ = rows;
  cols_ = cols;
  CreateMatrix();
}
S21Matrix::S21Matrix(const S21Matrix& other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  CreateMatrix();
  *this = other;
}
S21Matrix::S21Matrix(S21Matrix&& other) noexcept {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = std::move(other.matrix_);
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}
S21Matrix::~S21Matrix() {
  this->FreeingMem();
  matrix_ = nullptr;
}
//----------------my_creaters--------------------//
void S21Matrix::FreeingMem() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      if (matrix_[i]) delete[] matrix_[i];
    }
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
  }
}
void S21Matrix::CreateMatrix() {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::invalid_argument("number matrix invalid");
  }
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
    }
  }
}
bool S21Matrix::RavenAndNoRaven(const S21Matrix& other, bool type) const {
  bool flag_no = true;
  if (cols_ != other.cols_ || rows_ != other.rows_) {
    flag_no = false;
  }
  for (int i = 0; i < rows_ && flag_no && matrix_ && other.matrix_; i++) {
    for (int j = 0; j < cols_ && matrix_[i] && other.matrix_[i]; j++) {
      if (matrix_[i][j] != other.matrix_[i][j]) {
        flag_no = false;
      }
    }
  }
  if (!type) flag_no = !flag_no;
  return flag_no;
}

S21Matrix S21Matrix::PlusOrMinus(const S21Matrix& other, bool type) {
  S21Matrix return_matrix(this->rows_, this->cols_);
  int pre = 1;
  if (type) pre = -1;
  if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {
    throw std::invalid_argument("various matrix sizes");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      return_matrix.matrix_[i][j] = matrix_[i][j] + (pre * other.matrix_[i][j]);
    }
  }
  return return_matrix;
}

//-------Операции над матрицами--------//
bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  return RavenAndNoRaven(other, true);
}
void S21Matrix::SumMatrix(const S21Matrix& other) { *this = *this + other; }
void S21Matrix::SubMatrix(const S21Matrix& other) { *this = *this - other; }
void S21Matrix::MulNumber(const double num) { *this = *this * num; }
void S21Matrix::MulMatrix(const S21Matrix& other) { *this = *this * other; }

S21Matrix S21Matrix::Transpose() {
  S21Matrix temp(this->rows_, this->cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      temp(i, j) = this->matrix_[j][i];
    }
  }
  return temp;
}

S21Matrix S21Matrix::CalcComplements() {
  if (cols_ != rows_) {
    throw std::invalid_argument("matrix is not square");
  }
  S21Matrix return_matrix(this->cols_, this->rows_);
  S21Matrix minor(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      Minors(this, &minor, i, j);
      double res = minor.Determinant();
      return_matrix.matrix_[i][j] = pow(-1, i + j) * res;
    }
  }
  return return_matrix;
}
double S21Matrix::Determinant() {
  double result = 0;
  int model_z = 1;
  if (cols_ != rows_) {
    throw std::invalid_argument("matrix is not square");
  }
  if (cols_ == 1 && rows_ == 1) {
    result += matrix_[0][0];
  } else if (cols_ == 2 && rows_ == 2) {
    result += (matrix_[0][0] * matrix_[1][1]) - (matrix_[0][1] * matrix_[1][0]);
  } else {
    S21Matrix minor(rows_ - 1, cols_ - 1);
    for (int j = 0; j < cols_; j++, model_z *= -1) {
      Minors(this, &minor, 0, j);
      result += model_z * matrix_[0][j] * minor.Determinant();
    }
  }

  return result;
}
void S21Matrix::Minors(S21Matrix* main_matrix, S21Matrix* minor, int rows,
                       int cols) {
  int flag_minor = 0;
  for (int i = 0; i < main_matrix->rows_; i++) {
    for (int j = 0; j < main_matrix->cols_; j++) {
      flag_minor = 0;
      if (i != rows) {
        flag_minor = 1;
      }
      if (j == cols) {
        flag_minor = 0;
      }
      if (flag_minor == 1) {
        int ii = i;  // нужен для минора, смещаем rows
        int jj = j;  // нужен для минора, смещает cols
        // фактический данная комбинация условий срезает как ход ладьи в
        // шахматах. ii и jj, нужны для заполнения матрицы минора, ниже мы
        // двигаем индексы.
        if (i > rows) ii--;
        if (jj > cols) jj--;
        minor->matrix_[ii][jj] = main_matrix->matrix_[i][j];
      }
    }
  }
}
S21Matrix S21Matrix::InverseMatrix() {
  double opred = this->Determinant();
  S21Matrix return_matrix(rows_, cols_);
  if (opred == 0) {
    throw std::invalid_argument("matrix determinant is 0");
  }
  S21Matrix minor(rows_ - 1, cols_ - 1);
  S21Matrix transpon_matr(rows_, cols_);
  minor = this->CalcComplements();
  transpon_matr = minor.Transpose();
  return_matrix = transpon_matr * (1 / opred);
  return return_matrix;
}
//------операторы---------//
S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix return_matrix(this->rows_, this->cols_);
  return_matrix = PlusOrMinus(other, false);
  return return_matrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix return_matrix(this->rows_, this->cols_);
  return_matrix = PlusOrMinus(other, true);
  return return_matrix;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix return_matrix(this->rows_, other.cols_);
  if (this->cols_ != other.rows_) {
    throw "various matrix sizes";
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        return_matrix.matrix_[i][j] =
            return_matrix.matrix_[i][j] + (matrix_[i][k] * other.matrix_[k][j]);
      }
    }
  }
  return return_matrix;
}
S21Matrix S21Matrix::operator*(const double& other) {
  S21Matrix return_matrix(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int k = 0; k < cols_; k++) {
      return_matrix.matrix_[i][k] = this->matrix_[i][k] * other;
    }
  }
  return return_matrix;
}
bool S21Matrix::operator==(const S21Matrix& other) {
  return RavenAndNoRaven(other, true);
}
//сделал случайно, думал раз есть ==, значит будет и !=. Решил оставить, ибо
//отдельную фукцию выделил и все дела
bool S21Matrix::operator!=(const S21Matrix& other) {
  return RavenAndNoRaven(other, false);
}
S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this->matrix_ != nullptr) this->FreeingMem();
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  CreateMatrix();
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (this->matrix_ != nullptr) this->FreeingMem();
  if (this != &other) {
    cols_ = other.cols_;
    rows_ = other.rows_;
    matrix_ = std::move(other.matrix_);
    other.cols_ = 0;
    other.rows_ = 0;
    other.matrix_ = nullptr;
  }
  return *this;
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}
S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}
S21Matrix S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}
S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}
double& S21Matrix::operator()(int i, int j) {
  if ((rows_ <= i || cols_ <= j) || (i < 0 or j < 0)) {
    throw std::out_of_range("index outside matrix");
  }
  return matrix_[i][j];
}
