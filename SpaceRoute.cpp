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

public:
    SpaceRoute();  // Constructor
    ~SpaceRoute(); // Destructor

    void addWaypointAtBeginning(T& data) {
        Node<T>* newWayPoint = new Node<T>(data);
        newWayPoint->next = head;
        head = newWayPoint;
    }

    void addWaypointAtEnd(T& data) {
        Node<T>* newWayPoint = new Node<T>(data);
        newWayPoint->prev = tail;
        tail = newWayPoint;
    };
    void addWaypointAtIndex(int index, T& data);

    void removeWaypointAtBeginning() {
        Node<T>* temp = head;
        head = temp->next;
        delete temp;
    }

    void removeWaypointAtEnd() {
        Node<T>* temp = tail;
        tail = temp->prev;
        delete temp;
    }

    void removeWaypointAtIndex(int index);

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

    Node<T>* getWaypoint(int index);
    void setWaypoint(int index, T& data);
    void print(){

            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }

};

