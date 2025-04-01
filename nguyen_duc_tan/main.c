#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int value;
	struct node_t* previous_node;
}node_t;

typedef struct
{
	node_t* last_node;
	int len;
}linked_list_t;



/*3. Add: thêm một node vào cuối linked_list
  - Input: 
   * linked_list_t* - địa chỉ đối tượng linked list. Cái mà chúng ta sẽ add node vào đó
   * int - giá trị của node được add vào
  - Output: void */
void AddNodetoLinkedlist(linked_list_t* ll, int val)
{
	node_t* node = malloc(sizeof(node_t));
	node->value = val;
	if (ll->len > 0) {
		node->previous_node = ll->last_node;
	}
	else
	{
		node->previous_node = 0;
	}
	ll->last_node = node;
	ll->len++;
}

/* 9. GetValueIndex: lấy giá trị của node ở vị trí index
  - Input: 
   * linked_list_t*: địa của của linked list cái mà chúng ta sẽ đi đọc giá trị của node ở vị trí index
   * int index: vị trí của node chúng ta muốn đọc
  - Ouput: int: giá trị của node mà chúng ta đọc được*/
int GetValueIndex(linked_list_t* ll, int index)
{
	node_t* node_temp = ll->last_node;
	for (int i = ll->len - 1; i > index; i--)
	{
		node_temp = node_temp->previous_node;
	}
	return node_temp->value;
}

/*1. Create: tạo ra đối tượng linked list
  - input: linked_list_t* - địa chỉ đối tượng linked_list được tạo
  - output: void*/
void Create(linked_list_t* ll) {
	ll->last_node = NULL;
	ll->len = 0;
}
/*2. GetLen: lấy số lượng node trong linked lisst
  - input: linked_list_t* địa chỉ đối tượng linked_list cần GetLen
  - Output: int*/
int GetLen(linked_list_t* ll) {
	return ll->len;
}

/*4. Insert: chèn node vào lined list ở vị trí index
  - input: 
   * linked_list_t* địa của đối tượng linked lisst, mà ta sẽ insert đối tượng vào
   * int value: giá trị của node.
   * int index: vị trí node được insert vào.
  - Output: void
  - Gợi ý: giống như add chúng ta cũng cần cấp phát động, và chúng ta cần update lại previous_node của node trước nó
*/
void Insert(linked_list_t* ll, int val, int index)
{
	node_t* node = malloc(sizeof(node_t));
	node->value = val;
	node_t* node_temp = ll->last_node;
	for (int i = ll->len - 1; i > index; i--)
	{
		node_temp = node_temp->previous_node;
	}
	node->previous_node = node_temp->previous_node;
	node_temp->previous_node = node;
	ll->len++;
}

/*5. Remove: xoá một node ở vị trí cuối cùng trong linked list
  - input: linked_list_t* địa chỉ của đối tượng linked list, mà ta muốn xoá node ở trong nos
  - output: void
  - gợi ý: giải phóng vùng nhớ (sử dụng hàm free) của node cuối cùng.*/
void Remove(linked_list_t* ll)
{
	node_t* node_temp = ll->last_node;
	ll->last_node = node_temp->previous_node;
	free(node_temp);
	ll->len--;
}

/*6. RemoveIndex: xoá một node ở vị trí index
  - Input: 
   * linked_list_t*: địa chỉ của linked_líst, mà ta muốn xoá node trong nos
   * int index: vị trí của node muốn xoá*/
void RemoveIndex(linked_list_t* ll, int index) {
	node_t* node_temp = ll->last_node;
	for (int i = ll->len - 1; i > index; i--)
	{
		node_temp = node_temp->previous_node;
	}
	node_t* node_temp2 = node_temp->previous_node;
	node_temp->previous_node = node_temp2->previous_node;
	free(node_temp2);
	ll->len--;
}

/*7. Search: tìm kiếm vị trí của node theo giá trị
  - Input: 
   * linked_list_t*: địa chỉ của linked líst mà chúng ta cần tìm kiếm
   * int value: giá trị của node mà chúng ta muốn tìm kiếm
   - Ouput: int: vị trí của node được tìm thấy, -1 nếu không tìm thấy bất kỳ node vào có giá trị value.*/
int Search(linked_list_t* ll, int val) {
	node_t* node_temp = ll->last_node;
	for (int i = ll->len - 1; i >= 0; i--)
	{
		if (node_temp->value == val)
		{
			return i;
		}
		node_temp = node_temp->previous_node;
	}
	return -1;
}

/*8. GetValue: lấy giá trị của node ở vị trí cuối cùng
  - Input: 
   * linked_list_t*: địa chỉ của linked list cái mà chúng ta sẽ đi đọc node trong đó.
  - Ouput: int: giá trị của node*/
int GetValue(linked_list_t* ll) {
	return ll->last_node->value;
}

/*10. DeleteAll: xoá tất cả node trong linked lisst
  - Input: linked_list_t*: địa chỉ của linked list cái mà chúng ta muốn xoá hết tất cả node của nos
  - Output: void */
void DeleteAll(linked_list_t* ll){
	node_t* node_temp = ll->last_node;
	while (ll->len > 0)
	{
		node_temp = ll->last_node;
		ll->last_node = node_temp->previous_node;
		free(node_temp);
		ll->len--;
	}
}

void main() {
	linked_list_t ll = { 0 };
	AddNodetoLinkedlist(&ll, 1);
	AddNodetoLinkedlist(&ll, 2);
	AddNodetoLinkedlist(&ll, 3);
	AddNodetoLinkedlist(&ll, 4);
	AddNodetoLinkedlist(&ll, 5);

	int x = GetValueIndex(&ll, 3);
	Insert(&ll, 6, 2);
	int y = GetLen(&ll);
	Remove(&ll);
	int z = GetLen(&ll);
	RemoveIndex(&ll, 2);
	int t = GetLen(&ll);
	int k = Search(&ll, 3);
	int m = GetValue(&ll);
	DeleteAll(&ll);
}