#include <iostream> 
struct ListNode { 
int val; 
ListNode *next; 
ListNode(int x) : val(x), next(nullptr) {} 
}; 
class Solution { 
public: 
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { 
// Create a dummy node to simplify the merging process 
ListNode dummy(0); 
ListNode* current = &dummy; 
// Traverse both lists and append the smaller node to the merged list 
while (list1 != nullptr && list2 != nullptr) { 
if (list1->val < list2->val) { 
   
                current->next = list1; 
                list1 = list1->next; 
            } else { 
                current->next = list2; 
                list2 = list2->next; 
            } 
            current = current->next; 
        } 
 
        // If there are remaining nodes in either list, append them 
        if (list1 != nullptr) { 
            current->next = list1; 
        } else { 
            current->next = list2; 
        } 
 
        // The merged list is next to the dummy node 
        return dummy.next; 
    } 
}; 
 
// Helper function to create a linked list from user input 
ListNode* createLinkedList() { 
    ListNode* head = nullptr; 
    ListNode* tail = nullptr; 
    int value; 
 
    std::cout << "Enter values for the linked list (enter -1 to stop):" << std::endl; 
    while (true) { 
        std::cin >> value; 
        if (value == -1) break; // Stop input when -1 is entered 
 
        ListNode* newNode = new ListNode(value); 
        if (head == nullptr) { 
            head = newNode; // First node 
            tail = head; 
        } else { 
            tail->next = newNode; // Append to the end 
            tail = tail->next; 
        } 
    } 
 
    return head; 
}  
// Helper function to print the linked list 
void printLinkedList(ListNode* head) { 
ListNode* current = head; 
while (current != nullptr) { 
std::cout << current->val << " -> "; 
current = current->next; 
} 
std::cout << "nullptr" << std::endl; 
} 
int main() { 
Solution solution; 
// Create two sorted linked lists from user input 
std::cout << "Creating first sorted linked list:" << std::endl; 
ListNode* list1 = createLinkedList(); 
std::cout << "Creating second sorted linked list:" << std::endl; 
ListNode* list2 = createLinkedList(); 
// Merge the lists 
ListNode* mergedList = solution.mergeTwoLists(list1, list2); 
// Print the merged list 
std::cout << "Merged linked list:" << std::endl; 
printLinkedList(mergedList); 
// Clean up memory (not shown here for brevity) 
return 0; 
}