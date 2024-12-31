#include <iostream>
// #include <string>

// // Strategy interface: Defines a common interface for all compression strategies
// class CompressionStrategy
// {
// public:
//     virtual ~CompressionStrategy() {}                         // Virtual destructor for proper cleanup
//     virtual void compress(const std::string &data) const = 0; // Pure virtual method for compression implementation
// };

// // ConcreteStrategyA: A specific implementation of the CompressionStrategy interface
// class RLECompression : public CompressionStrategy
// {
// public:
//     ~RLECompression() override {} // Destructor

//     void compress(const std::string &data) const override
//     {
//         // Simple Run-Length Encoding (RLE) compression
//         std::cout << "Compressing using Run-Length Encoding: ";
//         int n = data.size();
//         for (int i = 0; i < n; i++)
//         {
//             int count = 1;
//             while (i < n - 1 && data[i] == data[i + 1])
//             {
//                 count++;
//                 i++;
//             }
//             std::cout << data[i] << count;
//         }
//         std::cout << std::endl;
//     }
// };

// // ConcreteStrategyB: Another specific implementation of the CompressionStrategy interface
// class HuffmanCompression : public CompressionStrategy
// {
// public:
//     ~HuffmanCompression() override {} // Destructor

//     void compress(const std::string &data) const override
//     {
//         // Simulated Huffman compression (simplified for the sake of the example)
//         std::cout << "Compressing using Huffman Coding: ";
//         // Simulate Huffman compression logic (in real case, a Huffman tree would be used)
//         std::cout << "Huffman compressed data: " << data << std::endl;
//     }
// };

// // Context: Maintains a reference to a CompressionStrategy and invokes its method
// class CompressionContext
// {
// public:
//     // Constructor initializes with a specific strategy
//     CompressionContext(CompressionStrategy *strategy) : strategy(strategy) {}

//     // Destructor to ensure the strategy is deleted to avoid memory leaks
//     ~CompressionContext()
//     {
//         delete strategy; // Clean up the strategy object to avoid memory leak
//     }

//     // Method to execute the current strategy
//     void compressData(const std::string &data) const
//     {
//         strategy->compress(data); // Delegates the call to the strategy's method
//     }

// private:
//     CompressionStrategy *strategy; // A pointer to the current strategy
// };

// int main()
// {
//     // Create a Context with RLECompression and execute its method
//     CompressionContext context(new RLECompression());
//     context.compressData("aaabbbccccc");

//     // Switch to a different strategy at runtime
//     context = CompressionContext(new HuffmanCompression()); // Switch to HuffmanCompression strategy
//     context.compressData("aaabbbccccc");

//     return 0;
// }

