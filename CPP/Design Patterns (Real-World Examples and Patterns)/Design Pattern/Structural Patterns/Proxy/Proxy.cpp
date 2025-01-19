#include <iostream>
#include <memory>

// Subject interface
class Image
{
public:
    virtual ~Image() {}
    virtual void display() = 0;
};

// RealSubject: Represents an expensive-to-load image
class RealImage : public Image
{
public:
    RealImage(const std::string &filename) : filename(filename)
    {
        loadImage();
    }

    void display() override
    {
        std::cout << "Displaying image: " << filename << std::endl;
    }

private:
    std::string filename;

    void loadImage()
    {
        std::cout << "Loading image: " << filename << " (expensive operation)\n";
    }
};

// Proxy: Controls access to RealImage
class ProxyImage : public Image
{
public:
    ProxyImage(const std::string &filename) : filename(filename), realImage(nullptr) {}

    void display() override
    {
        // Only load the image when needed
        if (!realImage)
        {
            realImage = std::make_shared<RealImage>(filename);
        }
        realImage->display(); // Delegate the display to RealImage
    }

private:
    std::string filename;
    std::shared_ptr<RealImage> realImage; // Lazy initialization
};

int main()
{
    std::cout << "Creating ProxyImage for image.jpg\n";
    ProxyImage proxyImage("image.jpg");

    std::cout << "Now displaying the image via proxy:\n";
    proxyImage.display(); // The image is loaded only when this method is called

    std::cout << "\nReusing ProxyImage to display again:\n";
    proxyImage.display(); // Image is displayed without reloading

    return 0;
}
