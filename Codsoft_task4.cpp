#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure to store task details
struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

// Function to add a task to the list
void AddTask(vector<Task>& taskList, const string& description) {
    Task newTask(description);
    taskList.push_back(newTask);
    cout << "Task added: " << description << endl;
}

// Function to view tasks with their status
void ViewTasks(const vector<Task>& taskList) {
    cout << "Task List:" << endl;
    for (size_t i = 0; i < taskList.size(); i++) {
        cout << "[" << (i + 1) << "] ";
        if (taskList[i].completed) {
            cout << "[Completed] ";
        } else {
            cout << "[Pending]   ";
        }
        cout << taskList[i].description << endl;
    }
}

// Function to mark a task as completed
void MarkTaskCompleted(vector<Task>& taskList, size_t index) {
    if (index >= 1 && index <= taskList.size()) {
        taskList[index - 1].completed = true;
        cout << "Task marked as completed: " << taskList[index - 1].description << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Function to remove a task from the list
void RemoveTask(vector<Task>& taskList, size_t index) {
    if (index >= 1 && index <= taskList.size()) {
        cout << "Task removed: " << taskList[index - 1].description << endl;
        taskList.erase(taskList.begin() + (index - 1));
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> taskList;
    char choice;

    do {
        cout << "===== To-Do List Manager =====" << endl;
        cout << "Options:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                {
                    string taskDescription;
                    cout << "Enter task description: ";
                    cin.ignore(); // Ignore newline character
                    getline(cin, taskDescription);
                    AddTask(taskList, taskDescription);
                }
                break;
            case '2':
                ViewTasks(taskList);
                break;
            case '3':
                {
                    size_t taskIndex;
                    cout << "Enter the task number to mark as completed: ";
                    cin >> taskIndex;
                    MarkTaskCompleted(taskList, taskIndex);
                }
                break;
            case '4':
                {
                    size_t taskIndex;
                    cout << "Enter the task number to remove: ";
                    cin >> taskIndex;
                    RemoveTask(taskList, taskIndex);
                }
                break;
            case '5':
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != '5');

    return 0;
}
