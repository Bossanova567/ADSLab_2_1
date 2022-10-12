#include "Heap.h"

int *A = NULL;

int main(){
    int choice;
    cout << "Menu" << endl;
    cout << "1. Create an array." << endl;
    cout << "2. Build a non-increasing pyramid." << endl;
    cout << "3. Build a non-decreasing pyramid." << endl;
    cout << "4. Sort the array in ascending order." << endl;
    cout << "5. Sort the array in descending order." << endl;
    cout << "6. Show the pyramid." << endl;
    cout << "0. Quit." << endl;
    label1:
    cout << endl;
    cout << "Your choice:";
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Do NOT type letters or words. Try again" << endl;
        goto label1;
    }
    if (choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6) {
        switch (choice) {
            case 0:
                return 0;
            case 1:
                int n; // n - кількість елементів масиву
            label2:
                cout << "Enter the length of an array:";
                cin >> n;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Do NOT type letters or words. Try again" << endl;
                    goto label2;
                }
                if (n <= 1) {
                    cout << "The length of array can't be " << n << endl;
                    goto label2;
                }
                else {
                    A = new int[n];
                    for (int i = 0; i < n; i++) {
                        cout << "Enter the data: " << endl;
                        cin >> A[i];
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(100, '\n');
                            cout << "Do NOT type letters or words. Try again" << endl;
                            goto label2;
                        }
                    }
                    Show(A, n);
                }
                break;
            case 2:
                if (A != NULL) {
                    BuildMaxHeap(A, n);
                    Show(A, n);
                }
                else
                    cout << "You didn't create an array" << endl;
                break;

            case 3:
                if (A != NULL) {
                    BuildMinHeap(A, n);
                    Show(A, n);
                }
                else
                    cout << "You didn't create an array" << endl;
                break;
            case 4:
                if (A != NULL) {
                    HeapSort(A, n, 1);
                    Show(A, n);
                }
                else
                    cout << "You didn't create an array" << endl;
            break;
            case 5:
                if (A != NULL) {
                    HeapSort(A, n, 2);
                    Show(A, n);
                }
                else
                    cout << "You didn't create an array" << endl;
            break;
            case 6:
                if (A != NULL) {
                    Show(A, n);
                }
                else
                    cout << "You didn't create an array" << endl;
            break;
                }
        goto label1;
        }
    else {
        cout << "You haven't chosen any of the available options. Please, try again." << endl;
        goto label1;
    }
}
