
#include <gtest/gtest.h>
#include <iostream>
using namespace std;

TEST(L8_0, Field_Width  )
{

    std::cout << " N N^2 N^3\n";
    for (int i{1}; i != 10; ++i)
    {
        std::cout << std::setw(2) << i
              << std::setw(6) << i*i
              << std::setw(7) << i*i*i
              << '\n';
    }
    for (int i{1}; i != 10; ++i)
    {
        std::cout << std::setw(6) << i
              << std::setw(6) << i*i
              << std::setw(6) << i*i*i
              << '\n';
    }

}

TEST(L8_0, Fill_Char)
{
  int day{14};
  int month{3};
  int year{2006};
  int dollars{42};
  int cents{7};
  // Print date in USA order. Later in the book, you will learn how to
  // handle internationalization.
  cout << "Date: " << setfill('0') << setw(2) << month
                            << '/' << setw(2) << day
                            << '/' << setw(2) << year << '\n';
  cout << "Pay to the order of: CASH\n";
  cout << "The amount of $" << setfill('*') << setw(8) << dollars << '.'
                            << setfill('0') << setw(2) << cents << '\n';

}

TEST(L8_0, Alignment)
{
  cout << '|' << setfill('*') << setw(6) <<  1234 << '|' << '\n';
  cout << '|' << left <<         setw(6) <<  1234 << '|' << '\n';
  cout << '|' <<                 setw(6) << -1234 << '|' << '\n';
  cout << '|' << right <<        setw(6) << -1234 << '|' << '\n';

  cout << setfill('0') << setw(6) << 42 << '\n';
  cout << left         << setw(6) << 42 << '\n';
  cout << 42 << '\n';
  cout << setfill('-') << setw(4) << -42 << '\n';

}

TEST(L8_0, Alternative_Syntax)
{
  cout.fill('0');
  cout.width(6);
  cout << 42 << '\n';
  cout.setf(ios_base::left, ios_base::adjustfield);
  cout.width(6);
  cout << 42 << '\n';
  cout << 42 << '\n';
  cout.fill('-');
  cout.width(4);
  cout << -42 << '\n';
}

TEST(L8_0, Multiplication_Table)
{
  int const low{1}; ///< Minimum value for the table
  int const high{10}; ///< Maximum value for the table
  int const colwidth{4}; ///< Fixed width for all columns

  // All numbers must be right-aligned.
  cout << right;
  // First print the header.
  cout << setw(colwidth) << '*'
       << '|';
  for (int i{low}; i <= high; i = i + 1)
    cout << setw(colwidth) << i;
  cout << '\n';

  // Print the table rule by using the fill character.
  cout << setfill('-')
       << setw(colwidth) << ""                    // one column's worth of "-"
       << '+'                                     // the vert. & horz. intersection
       << setw((high-low+1) * colwidth) << ""     // the rest of the line
       << '\n';

  // Reset the fill character.
  cout << setfill(' ');

  // For each row¡­
  for (int row{low}; row <= high; row = row + 1)
  {
    cout << setw(colwidth) << row << '|';
    // Print all the columns.
    for (int col{low}; col <= high; col = col + 1)
      cout << setw(colwidth) << row * col;
    cout << '\n';
  }

}
