from argparse import ArgumentParser
from os.path import isfile
from sys import exit
import re

parser = ArgumentParser()
parser.add_argument("-n", "--name", dest="filename", help="generated file name")
args = parser.parse_args()


header_filename = args.filename + ".h"
cpp_filename = args.filename + ".cpp"
test_filename = args.filename + "Test.cpp"

if isfile(header_filename):
  exit("File exists: {}".format(header_filename))

if isfile(cpp_filename):
  exit("File exists: {}".format(cpp_filename))

if isfile(test_filename):
  exit("File exists: {}".format(test_filename))

with open(header_filename, 'w') as f:
  template = '''#ifndef LEETCODE_{0}_H
#define LEETCODE_{0}_H
#endif //LEETCODE_{0}_H'''.format(args.filename.upper())
  f.write(template)


with open(cpp_filename, 'w') as f:
  template = '#include "{}"\n'.format(header_filename)
  f.write(template)

with open(test_filename, 'w') as f:
  testname = ' '.join(re.findall('[A-Z][^A-Z]*', args.filename))
  template = '''#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "{0}"
TEST_CASE("Test {1}") {{
  REQUIRE();
}}'''.format(header_filename, testname)
  f.write(template)
  

with open("CMakeLists.txt", 'a') as f:
  testname = ' '.join(re.findall('[A-Z][^A-Z]*', args.filename))
  template = '''
# test {0}.
add_executable({1}Test {1}Test.cpp
        {1}.cpp)
target_link_libraries({1}Test Catch2::Catch2)
catch_discover_tests({1}Test)
'''.format(testname, args.filename)
  f.write(template)

