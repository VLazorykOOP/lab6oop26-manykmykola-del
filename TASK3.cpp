#include <iostream>
#include <string>
using namespace std;
class Signal {
protected:
    string signalType;
public:
    Signal(string type = "Analog") {
        signalType = type;
        cout << "Constructor Signal" << endl;
    }
    Signal(const Signal& other) {
        signalType = other.signalType;
        cout << "Copy Constructor Signal" << endl;
    }
    virtual ~Signal() {
        cout << "Destructor Signal" << endl;
    }
    friend ostream& operator<<(ostream& out,
                               const Signal& s) {
        out << "Signal type: "
            << s.signalType;
        return out;
    }
    friend istream& operator>>(istream& in,
                               Signal& s) {
        cout << "Enter signal type: ";
        in >> s.signalType;
        return in;
    }
};
class ProcessResult {
protected:
    double result;
public:
    ProcessResult(double r = 0) {
        result = r;
        cout << "Constructor ProcessResult" << endl;
    }
    ProcessResult(const ProcessResult& other) {
        result = other.result;
        cout << "Copy Constructor ProcessResult" << endl;
    }
    virtual ~ProcessResult() {
        cout << "Destructor ProcessResult" << endl;
    }

    friend ostream& operator<<(ostream& out,
                               const ProcessResult& p) {
        out << "Processing result: "
            << p.result;
        return out;
    }
    friend istream& operator>>(istream& in,
                               ProcessResult& p) {
        cout << "Enter result: ";
        in >> p.result;
        return in;
    }
};
class ResultSignal :
    public Signal,
    public ProcessResult {

private:
    string description;
public:
    ResultSignal(string type = "Digital",
                 double r = 0,
                 string desc = "Filtered")
        : Signal(type),
          ProcessResult(r) {
        description = desc;
        cout << "Constructor ResultSignal" << endl;
    }
    ResultSignal(const ResultSignal& other)
        : Signal(other),
          ProcessResult(other) {
        description = other.description;
        cout << "Copy Constructor ResultSignal" << endl;
    }

    virtual ~ResultSignal() {
        cout << "Destructor ResultSignal" << endl;
    }
    friend ostream& operator<<(ostream& out,
                               const ResultSignal& rs) {
        out << "Signal type: "
            << rs.signalType << endl;
        out << "Result: "
            << rs.result << endl;
        out << "Description: "
            << rs.description << endl;
        return out;
    }
    friend istream& operator>>(istream& in,
                               ResultSignal& rs) {
        cout << "Enter signal type: ";
        in >> rs.signalType;
        cout << "Enter result: ";
        in >> rs.result;
        cout << "Enter description: ";
        in >> rs.description;
        return in;
    }
};
int main() {
    ResultSignal obj1(
        "Digital",
        98.7,
        "Amplified"
    );
    cout << endl;
    cout << "Object data:" << endl;
    cout << obj1 << endl;
    ResultSignal obj2 = obj1;
    cout << endl;
    cout << "Copied object:" << endl;
    cout << obj2 << endl;
    return 0;
}
