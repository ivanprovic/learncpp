#include <iostream>
#include <string>
using namespace std;

//creates a class with logic gate
//that returns label and boolean val
class LogicGate {
    public:
        LogicGate(string n) {
            label = n;
        }
        string getLabel(){
            return label;
        }
        bool getOutput(){
            output = performGateLogic();
            return output;
        }
        virtual bool performGateLogic(){
            cout << "ERROR! performGateLogic BASE" << '\n';
            return false; 
        }

        virtual void setNextPin(bool source) {
            cout << "ERROR! setNextPin BASE" << '\n';
        }
    private:
        string label;
        bool output;
};

//class that allows the gates to have two inputs
class BinaryGate: public LogicGate {
    public:
        BinaryGate(string n) : LogicGate(n) {
            pinATaken = false;
            pinBTaken = false;
        }
        bool getPinA() {
            if (pinATaken == false) {
                cout << "Enter Pin A input for gate " << getLabel() << ": ";
                cin >> pinA;
                pinATaken = true;
            }
            return pinA;
        }
        bool getPinB() {
            if (pinBTaken == false) {
                cout << "Enter Pin B input for gate " << getLabel() << ": ";
                cin >> pinB;
                pinBTaken = true;
            }
            return pinB;
        }
        virtual void setNextPin(bool source) {
            if (pinATaken == false) {
                pinA = source; 
                this->pinATaken = true;
            }
            else if (pinBTaken == false) {
                pinB = source;
                this->pinBTaken = true;
            }
        }
    private:
        bool pinA, pinATaken, pinB, pinBTaken;
};

//allows the creation of a logic gate with one input
class UnaryGate : public LogicGate {
    public:
        UnaryGate(string n) : LogicGate(n) {
            pinTaken = false;
        }
        bool getPin() {
            if (pinTaken == false) {
                cout << "Enter Pin input for gate " << getLabel() << ": ";
                cin >> pin;
                pinTaken = true;
            }
            return pin;
        }
        virtual void setNextPin(bool source) {
            if (pinTaken == false) {
                pin = source;
                pinTaken = true;
            }
            else {
                return;
            }
        }

    private:
        bool pin, pinTaken;
};

int main()
{
    return 0;
}
