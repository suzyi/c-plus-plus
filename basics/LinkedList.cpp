#include <iostream>
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int main() {
	ListNode* tmp, * head = new ListNode(10);
	tmp = head;
	for (int i = 9; i >= 1; i--) {
		ListNode* node = new ListNode(i);
		tmp->next = node;
		tmp = node;
	}

	
	while (head != nullptr) {
		std::cout << head->val << ", ";
		head = head->next;
	}
	return 0;
}