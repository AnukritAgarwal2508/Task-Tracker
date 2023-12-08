#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;
    string priority;

    Task(const string& desc, const string& prio = "Low") : description(desc), completed(false), priority(prio) {}
};

class TaskTracker {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description, const string& priority = "Low") {
        tasks.push_back(Task(description, priority));
    }

    void markTaskAsCompleted(int index) {
        if (isValidIndex(index)) {
            tasks[index].completed = true;
        } else {
            cout << "Invalid task index.\n";
        }
    }

    void editTask(int index, const string& newDescription, const string& newPriority) {
        if (isValidIndex(index)) {
            tasks[index].description = newDescription;
            tasks[index].priority = newPriority;
        } else {
            cout << "Invalid task index.\n";
        }
    }

    void displayTasks(bool showCompleted = true) const {
        cout << "Task List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            if (showCompleted || !tasks[i].completed) {
                cout << "[" << i + 1 << "] ";
                if (tasks[i].completed) {
                    cout << "[Completed] ";
                }
                cout << "[" << tasks[i].priority << "] ";
                cout << tasks[i].description << endl;
            }
        }
    }

private:
    bool isValidIndex(int index) const {
        return index >= 0 && static_cast<size_t>(index) < tasks.size();
    }
};

int main() {
    TaskTracker taskTracker;
    int choice;
    string input;
    int taskIndex;
    string newDescription;
    string newPriority;

    do {
        cout << "\nTask Tracker Menu\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. Edit Task\n";
        cout << "4. Display Tasks\n";
        cout << "5. Display Completed Tasks\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, input);
                cout << "Enter task priority: ";
                cin >> newPriority;
                taskTracker.addTask(input, newPriority);
                break;

            case 2:
                cout << "Enter the task index to mark as completed: ";
                cin >> taskIndex;
                taskTracker.markTaskAsCompleted(taskIndex - 1);
                break;

            case 3:
                cout << "Enter the task index to edit: ";
                cin >> taskIndex;
                cout << "Enter the new task description: ";
                cin.ignore();
                getline(cin, newDescription);
                cout << "Enter the new task priority: ";
                cin >> newPriority;
                taskTracker.editTask(taskIndex - 1, newDescription, newPriority);
                break;

            case 4:
                taskTracker.displayTasks(true);
                break;

            case 5:
                taskTracker.displayTasks(true);
                break;

            case 6:
                cout << "Exiting the task tracker.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 7);

    return 0;
}
