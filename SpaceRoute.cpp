#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T& data;
    Node* next;
    Node* prev;

    Node(T& d) : data(d), next(nullptr), prev(nullptr) {}
    void print() { cout << data << " "; }
};

class CelestialNode {
private:
    string name;
    double distance_from_earth;
    string mission_log;

public:
    CelestialNode(const string& n, double d, const string& log);
    const string& getName() const;
    double getDistance() const;
    const string& getMissionLog() const;
    void print() const { cout << name << " (" << distance_from_earth << " AU) - " << mission_log << endl; }
};

template <typename T>
class SpaceRoute {
private:
    Node<T>* head;
    Node<T>* tail;
    int routeLength;

public:
    SpaceRoute();  // Constructor
    ~SpaceRoute(); // Destructor

    void addWaypointAtBeginning(T& data) {
        Node<T>* newWayPoint = new Node<T>(data);
        newWayPoint->next = head;
        head = newWayPoint;
        routeLength++;
    }

    void addWaypointAtEnd(T& data) {
        Node<T>* newWayPoint = new Node<T>(data);
        newWayPoint->prev = tail;
        tail = newWayPoint;
        routeLength++;
    };
    void addWaypointAtIndex(int index, T& data) {
        if (index == 0) {
            addWaypointAtBeginning(data);
        } else if (index == routeLength) {
            addWaypointAtEnd(data);
        } else {
            Node<T>* newWayPoint = new Node<T>(data);
            Node<T>* afterWayPoint = getWaypoint(index);
            Node<T>* priorWayPoint = afterWayPoint->prev;

            newWayPoint->next = afterWayPoint;
            newWayPoint->prev = priorWayPoint;
            priorWayPoint->next = newWayPoint;
            afterWayPoint->prev = newWayPoint;
            routeLength++;
        }

    };

    void removeWaypointAtBeginning() {
        Node<T>* temp = head;
        head = temp->next;
        delete temp;
        routeLength--;
    }

    void removeWaypointAtEnd() {
        Node<T>* temp = tail;
        tail = temp->prev;
        delete temp;
        routeLength--;
    }

    void removeWaypointAtIndex(int index) {
        if (index == 0) {
            removeWaypointAtBeginning();
        } else if (index == routeLength) {
            removeWaypointAtEnd();
        } else {
            Node<T>* targetedWayPoint = getWaypoint(index);
            Node<T>* priorWayPoint = targetedWayPoint->prev;
            Node<T>* afterWayPoint = targetedWayPoint->next;

            priorWayPoint->next = afterWayPoint;
            afterWayPoint->prev = priorWayPoint;

            delete targetedWayPoint;
            routeLength--;
        }
    };

    void traverseForward() {
        Node<T>* temp = head;
        while (temp->next != NULL) {
            cout << temp << endl;
            temp = temp->next;
        }
    }

    void traverseBackward() {
        Node<T>* temp = tail;
        while (temp->prev != NULL) {
            cout << temp << endl;
            temp = temp->prev;
        }
    }

    Node<T>* getWaypoint(int index) {
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    };


    void setWaypoint(int index, T& data) {
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = data;
    };

    void print(){
        Node<T>* current = head;
        while (current) {
            current->print();
            current = current->next;
        }
        cout << endl;
    }

};

