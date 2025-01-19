#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

// Observer Interface: All observers must implement this interface
class Observer
{
public:
    virtual ~Observer() {}
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

// Subject Interface: The subject must implement this interface
class Subject
{
public:
    virtual ~Subject() {}
    virtual void addObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void removeObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void notifyObservers() = 0;
};

// Concrete Subject: Weather Station
class WeatherStation : public Subject
{
public:
    void setWeatherData(float temp, float hum, float press)
    {
        temperature = temp;
        humidity = hum;
        pressure = press;
        notifyObservers();
    }

    void addObserver(std::shared_ptr<Observer> observer) override
    {
        observers.push_back(observer);
    }

    void removeObserver(std::shared_ptr<Observer> observer) override
    {
        // Remove observer using std::find
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end())
        {
            observers.erase(it); // Remove the found observer
        }
    }

    void notifyObservers() override
    {
        for (auto &observer : observers)
        {
            observer->update(temperature, humidity, pressure);
        }
    }

private:
    float temperature = 0.0f;
    float humidity = 0.0f;
    float pressure = 0.0f;
    std::vector<std::shared_ptr<Observer>> observers;
};

// Concrete Observers: Displays that observe the WeatherStation
class PhoneDisplay : public Observer
{
public:
    void update(float temperature, float humidity, float pressure) override
    {
        std::cout << "Phone Display - Temperature: " << temperature << "C, Humidity: " << humidity << "%, Pressure: " << pressure << " hPa" << std::endl;
    }
};

class DesktopDisplay : public Observer
{
public:
    void update(float temperature, float humidity, float pressure) override
    {
        std::cout << "Desktop Display - Temperature: " << temperature << "C, Humidity: " << humidity << "%, Pressure: " << pressure << " hPa" << std::endl;
    }
};

int main()
{
    // Create the WeatherStation (subject)
    WeatherStation weatherStation;

    // Create the displays (observers)
    std::shared_ptr<PhoneDisplay> phoneDisplay = std::make_shared<PhoneDisplay>();
    std::shared_ptr<DesktopDisplay> desktopDisplay = std::make_shared<DesktopDisplay>();

    // Add observers to the WeatherStation
    weatherStation.addObserver(phoneDisplay);
    weatherStation.addObserver(desktopDisplay);

    // Change weather data (this will notify all observers)
    weatherStation.setWeatherData(25.0f, 60.0f, 1013.0f);
    weatherStation.setWeatherData(22.0f, 65.0f, 1012.0f);

    // Remove an observer
    weatherStation.removeObserver(phoneDisplay);

    // Change weather data (this will notify the remaining observers)
    weatherStation.setWeatherData(20.0f, 70.0f, 1011.0f);

    return 0;
}
