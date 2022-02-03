#include <AlgorithmTest.hpp>
#include <RadixHeap.hpp>

int main(int argc, char** argv) {
    auto config = std::make_tuple<bool, std::string, std::string, std::string>((std::string(argv[5]) == "-oss"), argv[2], argv[4], argv[6]);
    AlgorithmTest::testAlgorithm(config, RadixHeap(), "radixheap");
    return 0;
}