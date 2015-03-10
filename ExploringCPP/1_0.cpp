/// Sort the standard input alphabetically.
/// Read lines of text, sort them, and print the results to the standard output.
/// If the command line names a file, read from that file. Otherwise, read from
/// the standard input. The entire input is stored in memory, so don't try
/// this with input files that exceed available RAM.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <gtest\gtest.h>


TEST(L1_0, read_cin)
{
   // Part 1. Read the entire input into text. If the command line names a file,
   // read that file. Otherwise, read the standard input.
   std::vector<std::string> text; ///< Store the lines of text here
   text.push_back("abc");
   text.push_back("abd");
   text.push_back("bccc");
   text.push_back("abe");
   text.push_back("111");
   // Part 2. Sort the text.
   std::sort(text.begin(), text.end());
   // Part 3. Print the sorted text.
   std::copy(text.begin(), text.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}
