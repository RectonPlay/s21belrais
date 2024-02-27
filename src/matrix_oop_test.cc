#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

//-----------Operator_Sum-------------//
TEST(Operator_Sum, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(1, 1) = 1;
  S21Matrix b(2, 2);
  b(0, 0) = 2;
  b(1, 1) = 2;
  S21Matrix c(2, 2);
  bool value = 0;
  // Act
  c = a + b;
  // Assert
  if (c(0, 0) == 3 and c(1, 1) == 3) value = 1;
  ASSERT_EQ(value, 1);
}

TEST(Operator_Sum, test_2) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(1, 1) = 1;
  S21Matrix c(2, 2);
  bool value = 0;
  // Act
  c = a + c;
  // Assert
  if (c(0, 0) == 1 and c(1, 1) == 1) value = 1;
  ASSERT_EQ(value, 1);
}
//-----------Operator_Sub-------------//
TEST(Operator_Sub, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(1, 1) = 1;
  S21Matrix b(2, 2);
  b(0, 0) = 2;
  b(1, 1) = 2;
  S21Matrix c(2, 2);
  bool value = 0;
  // Act
  c = a - b;
  // Assert
  if (c(0, 0) == -1 and c(1, 1) == -1) value = 1;
  ASSERT_EQ(value, 1);
}
//-----------Operator_MulMatrix-------------//
TEST(Operator_MulMatrix, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(1, 1) = 3;
  S21Matrix b(2, 2);
  b(0, 0) = 2;
  b(1, 1) = 4;
  S21Matrix c(2, 2);
  bool value = 0;
  // Act
  c = a * b;
  // Assert
  if (c(0, 0) == 4 and c(1, 1) == 12) value = 1;
  ASSERT_EQ(value, 1);
}
//-----------Operator_MulNumber-------------//
TEST(Operator_MulNumber, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(1, 1) = 3;
  double b = 2;
  S21Matrix c(2, 2);
  bool value = 0;
  // Act
  c = a * b;
  // Assert
  if (c(0, 0) == 4 and c(1, 1) == 6) value = 1;
  ASSERT_EQ(value, 1);
}
//-----------Operator_EqMatrix-------------//
TEST(Operator_EqMatrix, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(1, 1) = 3;
  S21Matrix b(2, 2);
  b(0, 0) = 2;
  b(1, 1) = 4;
  bool value = 0;
  bool kra = false;
  // Act
  kra = a == b;
  // Assert
  if (kra) value = 1;
  ASSERT_EQ(value, 0);
}

TEST(Operator_EqMatrix, test_2) {
  // Arrange
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  bool value = 0;
  bool kra = false;
  // Act
  kra = a == b;
  // Assert
  if (kra) value = 1;
  ASSERT_EQ(value, 1);
}
TEST(Operator_NoEqMatrix, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(1, 1) = 3;
  S21Matrix b(2, 2);
  b(0, 0) = 2;
  b(1, 1) = 4;
  bool value = 0;
  bool kra = false;
  // Act
  kra = a != b;
  // Assert
  if (kra) value = 1;
  ASSERT_EQ(value, 1);
}
TEST(Operator_NoEqMatrix, test_2) {
  // Arrange
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  bool value = 0;
  bool kra = false;
  // Act
  kra = a != b;
  // Assert
  if (kra) value = 1;
  ASSERT_EQ(value, 0);
}

//-----------Funk_EqMatrix-------------//
TEST(Funk_EqMatrix, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(1, 1) = 3;
  S21Matrix b(2, 2);
  b(0, 0) = 2;
  b(1, 1) = 4;
  bool kra = false;
  // Act
  kra = a.EqMatrix(b);
  // Assert
  ASSERT_EQ(kra, 0);
}
TEST(Funk_EqMatrix, test_2) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(0, 1) = 1;
  a(1, 0) = 1;
  a(1, 1) = 3;
  S21Matrix b(2, 2);
  b(0, 0) = 2;
  b(0, 1) = 1;
  b(1, 0) = 1;
  b(1, 1) = 3;
  bool kra = false;
  // Act
  kra = a.EqMatrix(b);
  // Assert
  ASSERT_EQ(kra, 1);
}
//-----------Operator_ravn-------------//
TEST(Operator_ravn, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;
  S21Matrix b(2, 2);
  bool value = 0;
  // Act
  b = a;
  // Assert
  if (a(0, 0) == b(0, 0) and a(0, 1) == b(0, 1) and a(1, 0) == b(1, 0) and
      a(1, 1) == b(1, 1))
    value = 1;
  ASSERT_EQ(value, 1);
}
//-----------Operator_+=-------------//
TEST(Operator_pre_ravn_sum, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(1, 1) = 4;
  S21Matrix b(2, 2);
  b(0, 0) = 3;
  b(1, 1) = 4;
  bool value = 0;
  // Act
  a += b;
  // Assert
  if (a(0, 0) == 5 and a(1, 1) == 8) value = 1;
  ASSERT_EQ(value, 1);
}
//-----------Operator_-=-------------//
TEST(Operator_pre_ravn_sub, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(1, 1) = 4;
  S21Matrix b(2, 2);
  b(0, 0) = 3;
  b(1, 1) = 4;
  bool value = 0;
  // Act
  a -= b;
  // Assert
  if (a(0, 0) == -1 and a(1, 1) == 0) value = 1;
  ASSERT_EQ(value, 1);
}
//-----------Operator_*=_1-------------//
TEST(Operator_pre_mulMatrix, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(1, 1) = 4;
  S21Matrix b(2, 2);
  b(0, 0) = 3;
  b(1, 1) = 4;
  bool value = 0;
  // Act
  a *= b;
  // Assert
  if (a(0, 0) == 6 and a(1, 1) == 16) value = 1;
  ASSERT_EQ(value, 1);
}
//-----------Operator_*=_2-------------//
TEST(Operator_pre_mulNumber, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(1, 1) = 4;
  double b = 3;
  bool value = 0;
  // Act
  a *= b;
  // Assert
  if (a(0, 0) == 6 and a(1, 1) == 12) value = 1;
  ASSERT_EQ(value, 1);
}
//-----------Funk_SumMatrix-------------//
TEST(Funk_SumMatrix, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(1, 1) = 4;
  S21Matrix b(2, 2);
  b(0, 0) = 1;
  b(1, 1) = 1;
  bool value = 0;
  // Act
  a.SumMatrix(b);
  // Assert
  if (a(0, 0) == 3 and a(1, 1) == 5) value = 1;
  ASSERT_EQ(value, 1);
}
//-----------Funk_SubMatrix-------------//
TEST(Funk_SubMatrix, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(1, 1) = 4;
  S21Matrix b(2, 2);
  b(0, 0) = 1;
  b(1, 1) = 1;
  bool value = 0;
  // Act
  a.SubMatrix(b);
  // Assert
  if (a(0, 0) == 1 and a(1, 1) == 3) value = 1;
  ASSERT_EQ(value, 1);
}
//-----------Funk_MulNumber-------------//
TEST(Funk_MulNumber, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(1, 1) = 4;
  double b = 2;
  bool value = 0;
  // Act
  a.MulNumber(b);
  // Assert
  if (a(0, 0) == 4 and a(1, 1) == 8) value = 1;
  ASSERT_EQ(value, 1);
}
//-----------Funk_MulMatrix-------------//
TEST(Funk_MulMatrix, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 2;
  a(1, 1) = 4;
  S21Matrix b(2, 2);
  b(0, 0) = 3;
  b(1, 1) = 4;
  bool value = 0;
  // Act
  a.MulMatrix(b);
  // Assert
  if (a(0, 0) == 6 and a(1, 1) == 16) value = 1;
  ASSERT_EQ(value, 1);
}
//-----------Funk_Determinant-------------//
TEST(Funk_Determinant, test_1) {
  // Arrange
  S21Matrix a(3, 3);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(0, 2) = 13;
  a(1, 0) = 4;
  a(1, 1) = 5;
  a(1, 2) = 6;
  a(2, 0) = 7;
  a(2, 1) = 8;
  a(2, 2) = 15;
  double resul;
  // Act
  resul = a.Determinant();
  // Assert
  ASSERT_EQ(resul, -48);
}
TEST(Funk_Determinant, test_2) {
  // Arrange
  S21Matrix a(1, 1);
  a(0, 0) = 1;
  double resul;
  // Act
  resul = a.Determinant();
  // Assert
  ASSERT_EQ(resul, 1);
}
TEST(Funk_Determinant, test_3) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;
  double resul;
  // Act
  resul = a.Determinant();
  // Assert
  ASSERT_EQ(resul, -2);
}
//-----------Funk_InverseMatrix-------------//
TEST(Funk_InverseMatrix, test_1) {
  // Arrange
  S21Matrix a(3, 3);
  a(0, 0) = 2;
  a(0, 1) = 5;
  a(0, 2) = 7;
  a(1, 0) = 6;
  a(1, 1) = 3;
  a(1, 2) = 4;
  a(2, 0) = 5;
  a(2, 1) = -2;
  a(2, 2) = -3;
  S21Matrix resul(3, 3);
  // Act
  resul = a.InverseMatrix();
  int value = 0;
  if (resul(0, 0) == 1 and resul(0, 1) == -1 and resul(0, 2) == 1 and
      resul(1, 0) == -38 and resul(1, 1) == 41 and resul(1, 2) == -34 and
      resul(2, 0) == 27 and resul(2, 1) == -29 and resul(2, 2) == 24)
    value = 1;
  // Assert
  ASSERT_EQ(value, 1);
}
//-----------constructors_()-------------//
TEST(constructors_def, test_1) {
  // Arrange
  S21Matrix a;
  bool value = false;
  // Act
  // Assert
  if (a.GetRows() == 0 and a.GetCols() == 0) value = 1;
  ASSERT_EQ(value, 1);
}
//-----------constructors_(row, col)-------------//
TEST(constructors_input_row_and_col, test_1) {
  // Arrange
  S21Matrix a(4, 7);
  bool value = false;
  // Act
  // Assert
  if (a.GetRows() == 4 and a.GetCols() == 7) value = 1;
  ASSERT_EQ(value, 1);
}
//-----------constructors_copy-------------//
TEST(constructors_copy, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;
  bool value = false;
  // Act
  S21Matrix b(a);
  // Assert
  if (a.GetRows() == b.GetRows() and a.GetCols() == b.GetCols()) value = 1;
  ASSERT_EQ(value, 1);
}
TEST(constructors_copy, test_2) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;
  bool value = false;
  // Act
  S21Matrix b(a);
  // Assert
  if (a(0, 0) == b(0, 0) and a(0, 1) == b(0, 1) and a(1, 0) == b(1, 0) and
      a(1, 1) == b(1, 1))
    value = 1;
  ASSERT_EQ(value, 1);
}
//-----------constructors_cut-------------//
TEST(constructors_cut, test_1) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;
  bool value = false;
  S21Matrix temp_a(a);
  // Act
  S21Matrix b(std::move(a));
  // Assert
  if (b.GetRows() == 2 and b.GetCols() == 2) value = 1;
  ASSERT_EQ(value, 1);
}
TEST(constructors_cut, test_2) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;
  bool value = false;
  S21Matrix temp_a(a);
  // Act
  S21Matrix b(std::move(a));
  // Assert
  if (a.GetRows() == 0 and a.GetCols() == 0) value = 1;
  ASSERT_EQ(value, 1);
}
TEST(constructors_cut, test_3) {
  // Arrange
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;
  bool value = false;
  S21Matrix temp_a(a);
  // Act
  S21Matrix b(std::move(a));
  // Assert
  if (b(0, 0) == 1 and b(0, 1) == 2 and b(1, 0) == 3 and b(1, 1) == 4)
    value = 1;
  ASSERT_EQ(value, 1);
}
//-----------getter_and_setter_part-------------//
TEST(setter, test_1_matrix_stong) {
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  bool value = false;
  a.SetRows(3);
  if (a.GetCols() == 2 and a.GetRows() == 3) value = true;
  ASSERT_EQ(value, 1);
}
TEST(setter, test_2) {
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  bool value = false;
  a.SetRows(1);
  if (a.GetCols() == 2 and a.GetRows() == 1) value = true;
  ASSERT_EQ(value, 1);
}
TEST(setter, test_3) {
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  bool value = false;
  a.SetRows(3);
  if (a(2, 1) == 0 and a(2, 1) == 0) value = true;
  ASSERT_EQ(value, 1);
}
TEST(setter, test_4) {
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  bool value = false;
  a.SetCols(1);
  if (a.GetCols() == 1 and a.GetRows() == 2) value = true;
  ASSERT_EQ(value, 1);
}
TEST(setter, test_5) {
  S21Matrix a(2, 2);
  a(0, 0) = 1;
  a(0, 1) = 2;
  bool value = false;
  a.SetCols(3);
  if (a.GetCols() == 3 and a.GetRows() == 2) value = true;
  ASSERT_EQ(value, 1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}