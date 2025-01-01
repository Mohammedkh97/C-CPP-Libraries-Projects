#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

// Strategy interface: Defines a common interface for all sorting strategies
class SortingStrategy
{
public:
    virtual ~SortingStrategy() {}                        // Virtual destructor for proper cleanup
    virtual void sort(std::vector<int> &data) const = 0; // Pure virtual method for sorting data
};

// ConcreteStrategy1: Bubble Sort implementation
class BubbleSort : public SortingStrategy
{
public:
    ~BubbleSort() override {}

    void sort(std::vector<int> &data) const override
    {
        std::cout << "Using Bubble Sort..." << std::endl;
        for (size_t i = 0; i < data.size(); ++i)
        {
            for (size_t j = 0; j < data.size() - i - 1; ++j)
            {
                if (data[j] > data[j + 1])
                {
                    std::swap(data[j], data[j + 1]);
                }
            }
        }
    }
};

// ConcreteStrategy2: Merge Sort implementation
class MergeSort : public SortingStrategy
{
public:
    ~MergeSort() override {}

    void sort(std::vector<int> &data) const override
    {
        std::cout << "Using Merge Sort..." << std::endl;
        mergeSort(data, 0, data.size() - 1);
    }

private:
    void mergeSort(std::vector<int> &data, int left, int right) const
    {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(data, left, mid);
        mergeSort(data, mid + 1, right);
        merge(data, left, mid, right);
    }

    void merge(std::vector<int> &data, int left, int mid, int right) const
    {
        std::vector<int> leftArr(data.begin() + left, data.begin() + mid + 1);
        std::vector<int> rightArr(data.begin() + mid + 1, data.begin() + right + 1);
        int i = 0, j = 0, k = left;
        while (i < leftArr.size() && j < rightArr.size())
        {
            if (leftArr[i] <= rightArr[j])
            {
                data[k++] = leftArr[i++];
            }
            else
            {
                data[k++] = rightArr[j++];
            }
        }
        while (i < leftArr.size())
        {
            data[k++] = leftArr[i++];
        }
        while (j < rightArr.size())
        {
            data[k++] = rightArr[j++];
        }
    }
};

// ConcreteStrategy3: Quick Sort implementation
class QuickSort : public SortingStrategy
{
public:
    ~QuickSort() override {}

    void sort(std::vector<int> &data) const override
    {
        std::cout << "Using Quick Sort..." << std::endl;
        quickSort(data, 0, data.size() - 1);
    }

private:
    void quickSort(std::vector<int> &data, int low, int high) const
    {
        if (low < high)
        {
            int pi = partition(data, low, high);
            quickSort(data, low, pi - 1);
            quickSort(data, pi + 1, high);
        }
    }

    int partition(std::vector<int> &data, int low, int high) const
    {
        int pivot = data[high];
        int i = low - 1;
        for (int j = low; j < high; ++j)
        {
            if (data[j] < pivot)
            {
                ++i;
                std::swap(data[i], data[j]);
            }
        }
        std::swap(data[i + 1], data[high]);
        return i + 1;
    }
};

// Context: Maintains a reference to a SortingStrategy and delegates the sorting to it
class SortContext
{
public:
    SortContext(SortingStrategy *strategy) : strategy(strategy) {}

    ~SortContext()
    {
        delete strategy; // Cleanup strategy
    }

    // Sort the given data using the current strategy
    void sortData(std::vector<int> &data) const
    {
        strategy->sort(data);
    }

private:
    SortingStrategy *strategy; // The sorting strategy
};

int main()
{
    std::vector<int> data = {9, 7, 5, 11, 12, 2, 14, 3};

    // Using Bubble Sort
    SortContext context1(new BubbleSort());
    context1.sortData(data);
    std::cout << "Sorted data: ";
    for (int num : data)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Reset the data and use Merge Sort
    data = {9, 7, 5, 11, 12, 2, 14, 3};
    SortContext context2(new MergeSort());
    context2.sortData(data);
    std::cout << "Sorted data: ";
    for (int num : data)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Reset the data and use Quick Sort
    data = {9, 7, 5, 11, 12, 2, 14, 3};
    SortContext context3(new QuickSort());
    context3.sortData(data);
    std::cout << "Sorted data: ";
    for (int num : data)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
