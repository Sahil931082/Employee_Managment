#include <iostream>
#include <vector>
using namespace std;

vector<pair<string, string>> users;
string username;
string password;
string admin;

void createUser() {
    cout<<"ENTER ADMIN ADDRESS:\n";
    cin>>admin;
    if(admin=="Sahil@931"||admin=="Vanshita@931")
{    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    users.push_back(make_pair(username, password));
}else{
cout<<"ENTER CORRECT ADMIN ADDRESS\n";
}
}
bool checkuser(string username, string password)
{
    
     for (const auto& user : users) 
     {
    if(user.first==username&& user.second==password)
    {
        return true;
    }
    else{
        return false;
    }
     }

}

class Employee {
private:
    long int salary;
    long long int mobile_no;
    int age;

public:
    static int nextEmployeeId;
    int employeeId;
    string name;
    string last_name;
    Employee* next;
    Employee* prev;

    void getAge() {
        cout << age;
    }
    void getSalary() {
        cout << salary;
    }
    void setAge(int age) {
        this->age = age;
    }
    void setSalary(long int salary) {
        this->salary = salary;
    }
    void getMobile() {
        cout << mobile_no;
    }
    void setMobile(long long int mobileno) {
        mobile_no = mobileno;
    }

    Employee(string name, string last_name, long long int mobileno, int age, long int salary) {
        this->name = name;
        setSalary(salary);
        setMobile(mobileno);
        setAge(age);
        this->last_name = last_name;
        this->next = NULL;
        this->prev = NULL;
        this->employeeId = nextEmployeeId++;
    }
};

int Employee::nextEmployeeId = 1;
Employee* head = NULL;
Employee* tail = NULL;

void insert() {
    int age;
    long int salary;
    string name, lastname;
    long long int mobileno;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter last name: ";
    cin >> lastname;
    cout << "Enter mobile number: ";
    cin >> mobileno;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter salary: ";
    cin >> salary;
    Employee* newnode = new Employee(name, lastname, mobileno, age, salary);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void display() {
    Employee* temp = head;
    while (temp != NULL) {
        cout << endl << "EMPLOYEE ID: " << temp->employeeId << endl;
        cout << "NAME: " << temp->name << " " << temp->last_name << endl;
        cout << "MOBILE NO.: ";
        temp->getMobile();
        cout << endl << "AGE: ";
        temp->getAge();
        cout << endl << "SALARY: ";
        temp->getSalary();
        cout << endl;
        temp = temp->next;
    }
}

void displayId(Employee* temp) {
    cout << "EMPLOYEE ID: " << temp->employeeId << endl;
    cout << "NAME: " << temp->name << " " << temp->last_name << endl;
    cout << "MOBILE NO.: ";
    temp->getMobile();
    cout << endl << "AGE: ";
    temp->getAge();
    cout << endl << "SALARY: ";
    temp->getSalary();
}

void deleteEntry(Employee* temp) {
    if (temp == head) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else if (temp == tail) {
        tail = temp->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    cout << "DELETED ITEM" << endl;
    displayId(temp);
        Employee::nextEmployeeId--; 
    delete temp;
}

void deletion() {
    string firstname, lastname;
    cout << "Enter the first name: ";
    cin >> firstname;
    cout << "Enter last name: ";
    cin >> lastname;
    Employee* temp = head;
    while (temp != NULL) {
        if (temp->name == firstname && temp->last_name == lastname) {
            deleteEntry(temp);
            break;
        }
        temp = temp->next;
    }
}

void findEmployee() {
    bool found = false;
    string firstname, lastname;
    cout << "Enter the first name: ";
    cin >> firstname;
    cout << "Enter last name: ";
    cin >> lastname;
    Employee* temp = head;
    while (temp != NULL) {
        if (temp->name == firstname && temp->last_name == lastname) {
            displayId(temp);
            found = true;
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Employee not found." << endl;
    }
}

int main() {
    char y;
    while(true){
    cout<<"Enter 'r' to create user: \n";
        cout<<"Enter 'u' to login: \n";

    cin>>y;
    if(y=='r')
    {
        createUser();
    }
    else if(y=='u')
    {
        cout<<"Enter username : \n";
    cin>>username;
    cout<<"enter password : \n";
    cin>>password;
    if(checkuser(username,password))
    {
    char x = ' ';
    while (x != 'n') {
        cout << endl
             << "Enter 'e' to insert the node at head" << endl;
        cout << "Enter 'd' to display" << endl;
        cout << "Enter 'c' to deletion from tail" << endl;
        cout << "Enter 'f' to find employee" << endl;
        cout << "Enter 'n' to end" << endl;

        cin >> x;
        if (x == 'e') {
            insert();
        } else if (x == 'd') {
            display();
        } else if (x == 'c') {
            deletion();
        } else if (x == 'f') {
            findEmployee();
        } else {
            cout << "Wrong input, try again" << endl;
        }
    }
    }
    else{
        cout<<"user not found\n";
    }
    }
    }
    return 0;
}