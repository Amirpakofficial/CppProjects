#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isComplete;

    Task(string desc) {
        description = desc;
        isComplete = false;
    }
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void removeTask(int taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            cout << "Invalid task number!" << endl;
            return;
        }
        cout << "Task removed: " << tasks[taskIndex - 1].description << endl;
        tasks.erase(tasks.begin() + taskIndex - 1);
    }

    void markTaskComplete(int taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            cout << "Invalid task number!" << endl;
            return;
        }
        tasks[taskIndex - 1].isComplete = true;
        cout << "Task marked complete: " << tasks[taskIndex - 1].description << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks to show!" << endl;
            return;
        }
        cout << "\nYour Todo List:" << endl;
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].isComplete) {
                cout << " [Completed]";
            }
            cout << endl;
        }
    }
};

int main() {
    TodoList todoList;
    int choice;
    string description;
    int taskIndex;

    do {
        cout << "\nTodo List Menu:" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. Remove a task" << endl;
        cout << "3. Mark a task as complete" << endl;
        cout << "4. View all tasks" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // to handle newline character after number input

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, description);
                todoList.addTask(description);
                break;
            case 2:
                cout << "Enter task number to remove: ";
                cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            case 3:
                cout << "Enter task number to mark as complete: ";
                cin >> taskIndex;
                todoList.markTaskComplete(taskIndex);
                break;
            case 4:
                todoList.viewTasks();
                break;
            case 5:
                cout << "Exiting Todo List Application." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

