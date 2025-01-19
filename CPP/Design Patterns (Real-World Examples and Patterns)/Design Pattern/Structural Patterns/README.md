### Proxy Pattern:

The **Proxy Pattern** is a structural design pattern that provides an object representing another object. It acts as an intermediary or placeholder for the real object and can control access to it. This pattern is useful when you want to control or modify the behavior of an object before or after it is accessed, while keeping the interface the same.

The Proxy Pattern allows for additional actions to be taken when accessing an object without modifying the object itself.

### Types of Proxies

1. **Virtual Proxy**: Controls access to a resource that is expensive to create or load. It only initializes the resource when it is actually needed.
2. **Remote Proxy**: Represents an object that is located on a different address space (e.g., in a different machine).
3. **Protective Proxy**: Controls access to an object based on permissions or other conditions.
4. **Cache Proxy**: Stores results of expensive operations and returns them to the client if the same request is made again, improving performance.

### Structure of the Proxy Pattern

1. **Subject**: This is an interface that defines the common operations for the RealSubject and Proxy.
2. **RealSubject**: This class implements the Subject interface and contains the actual business logic.
3. **Proxy**: This class also implements the Subject interface and controls access to the RealSubject. It can add additional behavior before or after delegating to the RealSubject.

### Benefits of the Proxy Pattern
- It allows for **lazy initialization** of resources.
- **Access control** can be enforced, ensuring only authorized clients can access the real object.
- **Caching** can be done for repeated expensive operations.
- It provides a **remote interface** for objects that exist in a different address space.

### Example - Virtual Proxy Example: Image Loading

Let’s demonstrate the **Proxy Pattern** with an example of an image loading application. In this example, a `RealImage` represents an image that takes time to load, and a `ProxyImage` acts as a placeholder. The proxy only loads the image when it's needed.

### Code Example

```cpp
#include <iostream>
#include <memory>

// Subject interface
class Image {
public:
    virtual ~Image() {}
    virtual void display() = 0;
};

// RealSubject: Represents an expensive-to-load image
class RealImage : public Image {
public:
    RealImage(const std::string& filename) : filename(filename) {
        loadImage();
    }

    void display() override {
        std::cout << "Displaying image: " << filename << std::endl;
    }

private:
    std::string filename;

    void loadImage() {
        std::cout << "Loading image: " << filename << " (expensive operation)\n";
    }
};

// Proxy: Controls access to RealImage
class ProxyImage : public Image {
public:
    ProxyImage(const std::string& filename) : filename(filename), realImage(nullptr) {}

    void display() override {
        // Only load the image when needed
        if (!realImage) {
            realImage = std::make_shared<RealImage>(filename);
        }
        realImage->display();  // Delegate the display to RealImage
    }

private:
    std::string filename;
    std::shared_ptr<RealImage> realImage; // Lazy initialization
};

int main() {
    std::cout << "Creating ProxyImage for image.jpg\n";
    ProxyImage proxyImage("image.jpg");

    std::cout << "Now displaying the image via proxy:\n";
    proxyImage.display();  // The image is loaded only when this method is called

    std::cout << "\nReusing ProxyImage to display again:\n";
    proxyImage.display();  // Image is displayed without reloading

    return 0;
}
```

### Explanation of the Example

1. **Image (Subject)**: This is the base class/interface that both `RealImage` and `ProxyImage` implement. It contains the method `display()`, which both concrete classes must implement.

2. **RealImage**: This is the actual image object that represents a real image. It contains an expensive `loadImage()` method that simulates loading the image from disk.

3. **ProxyImage**: This class represents the proxy. It contains a reference to `RealImage` and controls its initialization and access. The image is only loaded when `display()` is called for the first time. On subsequent calls, it simply delegates the task to the already-loaded `RealImage` instance.

4. **Main**: In the `main()` function, we create a `ProxyImage` and call its `display()` method. On the first call, the image is loaded, and on subsequent calls, the image is displayed without reloading, demonstrating the proxy's functionality.

### Output:

```
Creating ProxyImage for image.jpg
Now displaying the image via proxy:
Loading image: image.jpg (expensive operation)
Displaying image: image.jpg

Reusing ProxyImage to display again:
Displaying image: image.jpg
```

### Key Points:
- The **Proxy** class is responsible for managing the real object (`RealImage`) and controlling its access. It ensures that the image is loaded only when necessary.
- The **RealSubject** (`RealImage`) contains the actual business logic, which is the image loading in this case.
- The **Proxy** provides the same interface to the client as the **RealSubject**, so clients don’t need to know about the proxy.
- **Lazy Loading**: The image is not loaded until it is displayed for the first time.

### Use Cases of Proxy Pattern:
- **Virtual Proxy**: When dealing with expensive-to-load objects (like images, videos, etc.), a proxy can ensure the object is only loaded when needed.
- **Remote Proxy**: For remote communication, a proxy can represent objects that exist in different address spaces or even remote systems.
- **Protective Proxy**: In some cases, proxies are used for access control or permissions checks.
- **Cache Proxy**: For caching, proxies can store the results of expensive operations and return them directly if the same request is made again.

### Conclusion
The Proxy Pattern allows you to control the access and initialization of an object, adding additional functionality like lazy loading, access control, caching, or remote communication. It helps in improving performance, security, and efficiency without altering the interface of the underlying objects.