# **Observer Design Pattern - Notification System**

## **Overview**

This project demonstrates the Observer Design Pattern through a stock trading application. 
The Observer Pattern is used to decouple the stock price management logic from the notification system, enabling users (observers) to be dynamically 
notified about changes in stock prices without modifying the core logic.

## **Features**

- **Dynamic Observer Registration and Removal:** Users can register and deregister to receive notifications.
- **Notification System:** All registered users are notified when there is a change in stock prices.
- **Scalability:** The system can easily be extended by adding more observers or modifying the subject logic without affecting the rest of the system.

## **Design Pattern Used**

- **Observer Pattern:** The StockManager (Subject) maintains a list of observers (Users) and notifies them of any price changes.

## **Code Structure**

- **StockManager (Concrete Subject):**
  - Maintains a list of observers.
  - Notifies them whenever the stock price changes.
  - Allows adding and removing observers.
  
- **User (Concrete Observer):**
  - Receives updates about stock price changes.
  - Displays the stock price change notification to the user.

## **Classes and Responsibilities**

1. **Observer Interface (`Observer.hpp`):**
   - Defines the `update()` method, which all observers must implement to receive notifications.
   
2. **Subject Interface (`Subject.hpp`):**
   - Defines the methods for registering, removing, and notifying observers.
   
3. **StockManager (`StockManager.hpp` / `StockManager.cpp`):**
   - Implements the `Subject` interface.
   - Notifies all registered observers whenever the stock price changes.
   
4. **User (`User.hpp` / `User.cpp`):**
   - Implements the `Observer` interface.
   - Receives notifications and handles the updates.

## **Clean Code Practices**

- **Separation of Concerns:** The stock price logic and notification system are decoupled, ensuring clear responsibilities for each class.
- **Encapsulation:** Private members are encapsulated within classes, and only necessary methods are exposed.
- **Interfaces/Abstract Classes:** Used to define clear contracts between subjects and observers, improving code extensibility.
- **Descriptive Method Names:** Method names such as `registerObserver()`, `removeObserver()`, and `notifyObservers()` are used to describe their actions clearly.

## **Real-World Use Cases**
- **Stock Price Alerts:** This pattern can be applied to notify multiple subscribers when stock prices change.
- **Weather Systems:** Multiple devices (observers) can be notified when the weather changes.
- **Sensor Data Monitoring:** Systems that monitor sensors and notify users about critical data changes.
